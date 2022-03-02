#include "dispatchEventService.h"
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

#define MAX_ITEM_IN_EVENT_QUEUE 65536

DispatchEventService::DispatchEventService() : msg_queue_( PosixQueue<Event>(MAX_ITEM_IN_EVENT_QUEUE) )
{
}

DispatchEventService::~DispatchEventService()
{
}


bool DispatchEventService::init(){
    
    //create a thread
    int ret = pthread_create(&thread_hdl_, NULL, svc, this);
    if(ret != 0){
        cout << "Create pthread error!\n" << endl;
        return false;
    }
    svr_exit_ = false;

    return true;
}

bool DispatchEventService::uninit(){
    //delete message queue
    svr_exit_ = true;
    pthread_join(thread_hdl_, NULL);
    return true;
}

bool DispatchEventService::subscribe(u16 eid, EventHandler* handler)
{
    if(NULL == handler) return false;

    T_EventHandlersMap::iterator iter = subscribers_.find(eid);
    if (iter != subscribers_.end())
    {
        T_EventHandlers::iterator hdl_iter = std::find(iter->second.begin(), iter->second.end(), handler);
        if ( hdl_iter == iter->second.end())
        {
           iter->second.push_back(handler);
        }
    }
    else
    {
        subscribers_[eid].push_back(handler);
    }

    return true;
}

bool DispatchEventService::unsubscribe(u16 eid, EventHandler* handler)
{
    if(NULL == handler) return false;

    T_EventHandlersMap::iterator iter = subscribers_.find(eid);
    if (iter != subscribers_.end())
    {
        T_EventHandlers::iterator hdl_iter = std::find(iter->second.begin(), iter->second.end(), handler);
        if ( hdl_iter != iter->second.end())
        {
           iter->second.erase(hdl_iter);
        }
    }
    return true;
}

bool DispatchEventService::publish(Event* ev)
{
    if (NULL == ev)
    {
        return false;
    }

    return msg_queue_.enqueue(ev, 0);
}

bool DispatchEventService::process(const Event* ev)
{
    if (NULL == ev)
	  {
        return false;
	  }

    u16 eid = ev->getEid();

    if (eid == EEVENTID_UNKOWN)
    {
        cout << "DispatchMsgService : unknow evend id" << eid << endl;
        return false;
    }

    T_EventHandlersMap::iterator handlers = subscribers_.find(eid);
    if (handlers == subscribers_.end())
    {
        cout << "DispatchMsgService : no event handler subscribed"<< eid << endl;
        return false;
    }

    for (T_EventHandlers::iterator iter = handlers->second.begin();
        iter != handlers->second.end();
        iter++)
    {
        EventHandler* handler = *iter;
        handler->handle(ev);
    }

	  return true;
}

void* DispatchEventService::svc(void* argv)
{
    cout << "dmg is running \n!" << endl;
    DispatchEventService* dmsvr = (DispatchEventService*)argv;
    if(argv == NULL){
        cout << "parameter of thread is invalid. \n" << endl;
        return NULL;
    }

    while(!dmsvr->svr_exit_)
    {
        Event* ev = NULL;
        /* wait only 1 ms to dequeue */
        if (-1 == dmsvr->msg_queue_.dequeue(ev, 1))
        {
            continue;
        }
        std::stringstream ss;
        ev->dump(ss);
        cout << "dequeue an event" << "(" << ss.str().c_str() << ")" << endl;
        dmsvr->process(ev);
		delete ev;
    }

	dmsvr->subscribers_.clear();
    cout << "dms quit. \n" << endl;
    return NULL;
}