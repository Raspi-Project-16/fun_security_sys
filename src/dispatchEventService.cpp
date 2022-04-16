#include "dispatchEventService.h"



#define MAX_ITEM_IN_EVENT_QUEUE 65536

/*----------------------------------------------------------------------
  |       DispatchEventService::DispatchEventService
  +---------------------------------------------------------------------*/

DispatchEventService::DispatchEventService() : msg_queue_( PosixQueue<CEvent>(MAX_ITEM_IN_EVENT_QUEUE) )
{
}

/*----------------------------------------------------------------------
  |       DispatchEventService::~DispatchEventService
  +---------------------------------------------------------------------*/
DispatchEventService::~DispatchEventService()
{
}

DispatchEventService DispatchEventService::instance_;

/*----------------------------------------------------------------------
  |       DispatchEventService::init
  +---------------------------------------------------------------------*/

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

/*----------------------------------------------------------------------
  |       DispatchEventService::uninit
  +---------------------------------------------------------------------*/

bool DispatchEventService::uninit(){
    //delete message queue
    svr_exit_ = true;
    pthread_join(thread_hdl_, NULL);
    return true;
}

/*----------------------------------------------------------------------
  |       DispatchEventService::subscribe
  +---------------------------------------------------------------------*/

bool DispatchEventService::subscribe(int eid, EventCallback* callback)
{
    if(NULL == callback) return false;

    T_EventHandlersMap::iterator iter = subscribers_.find(eid);
    if (iter != subscribers_.end())
    {
        T_EventHandlers::iterator hdl_iter = std::find(iter->second.begin(), iter->second.end(), callback);
        if ( hdl_iter == iter->second.end())
        {
           iter->second.push_back(callback);
        }
    }
    else
    {
        subscribers_[eid].push_back(callback);
    }

    return true;
}

/*----------------------------------------------------------------------
  |       DispatchEventService::unsubscribe
  +---------------------------------------------------------------------*/

bool DispatchEventService::unsubscribe(int eid, EventCallback* callback)
{
    if(NULL == callback) return false;

    T_EventHandlersMap::iterator iter = subscribers_.find(eid);
    if (iter != subscribers_.end())
    {
        T_EventHandlers::iterator hdl_iter = std::find(iter->second.begin(), iter->second.end(), callback);
        if ( hdl_iter != iter->second.end())
        {
           iter->second.erase(hdl_iter);
        }
    }
    return true;
}

/*----------------------------------------------------------------------
  |       DispatchEventService::publish
  +---------------------------------------------------------------------*/

bool DispatchEventService::publish(CEvent* ev)
{
    if (NULL == ev)
    {
        return false;
    }

    return msg_queue_.enqueue(ev, 0);
}

/*----------------------------------------------------------------------
  |       DispatchEventService::process
  +---------------------------------------------------------------------*/
bool DispatchEventService::process(const CEvent* ev)
{
    if (NULL == ev)
	  {
        return false;
	  }

    int eid = ev->getEid();
    if (eid == EEVENTID_UNKOWN)
    {
        cout << "DispatchMsgService : unknow event id" << eid << endl;
        return false;
    }

    T_EventHandlersMap::iterator callbacks = subscribers_.find(eid);
    if (callbacks == subscribers_.end())
    {
        cout << "DispatchMsgService : no event callback subscribed "<< eid << endl;
        return false;
    }
    
    for (T_EventHandlers::iterator iter = callbacks->second.begin();
        iter != callbacks->second.end();
        iter++)
    {
        EventCallback* callback = *iter;
        callback->callback(ev);
    }
	return true;
}

/*----------------------------------------------------------------------
  |       DispatchEventService::svc
  +---------------------------------------------------------------------*/
void* DispatchEventService::svc(void* argv)
{
    cout << "The system is running !" << endl;
    DispatchEventService* dmsvr = (DispatchEventService*)argv;
    if(argv == NULL){
        cout << "parameter of thread is invalid. \n" << endl;
        return NULL;
    }
    while(!dmsvr->svr_exit_)
    {
        CEvent* ev = NULL;

        /* wait only 1 ms to dequeue */
        if (-1 == dmsvr->msg_queue_.dequeue(ev, 1))
        {
            continue;
        }
        //std::stringstream ss;
        //ev->dump(ss);
        //cout << "dequeue an event" << "(" << ss.str().c_str() << ")" << endl;
        dmsvr->process(ev);
		//delete ev;
    }
    
	dmsvr->subscribers_.clear();
    cout << "dms quit. \n" << endl;
    return NULL;
}
