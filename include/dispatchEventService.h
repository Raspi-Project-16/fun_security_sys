#ifndef BRK_SERVICE_DISPATCH_EVENT_SERVICE_H_
#define BRK_SERVICE_DISPATCH_EVENT_SERVICE_H_

#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include "event.h"
#include "eventId.h"
#include "eventQueue.h"
#include "iEventHandler.h"
using namespace std;

/*----------------------------------------------------------------------
  |       DispatchEventService
  +---------------------------------------------------------------------*/

class DispatchEventService
{
public:
    // return the only instance
    static DispatchEventService* getInstance() { return &instance_;};

    virtual bool init();
    virtual bool uninit();
    virtual bool subscribe(int eid, EventCallback* handler);
    virtual bool unsubscribe(int eid, EventCallback* handler);
    virtual bool publish(CEvent* ev);
	
protected:

    DispatchEventService();
    virtual ~DispatchEventService();

protected:

    virtual bool process(const CEvent* ev);
    static void* svc(void * );
    typedef std::vector<EventCallback*> T_EventHandlers;
    typedef std::map<int, T_EventHandlers > T_EventHandlersMap;
    T_EventHandlersMap subscribers_;
    PosixQueue<CEvent> msg_queue_;
    bool svr_exit_;

private:
    pthread_t thread_hdl_;
    // static instance 
    static DispatchEventService instance_;

};

#define des DispatchEventService::getInstance()




#endif
