#ifndef BRK_SERVICE_DISPATCH_EVENT_SERVICE_H_
#define BRK_SERVICE_DISPATCH_EVENT_SERVICE_H_

#include <map>
#include <vector>
#include "event.h"
#include "eventId.h"
#include "eventQueue.h"
#include "iEventHandler.h"

class DispatchEventService
{
public:
    static DispatchEventService* getInstance() { return &instance_;};

    virtual bool init();
    virtual bool uninit();

    virtual bool subscribe(u16 eid, EventHandler* handler);
    virtual bool unsubscribe(u16 eid, EventHandler* handler);
    virtual bool publish(Event* ev);
	
protected:

    DispatchEventService();
    virtual ~DispatchEventService();

protected:

    virtual bool process(const Event* ev);
    static void* svc(void * );
    
    typedef std::vector<EventHandler*> T_EventHandlers;
    typedef std::map<u16, T_EventHandlers > T_EventHandlersMap;
    T_EventHandlersMap subscribers_;
    PosixQueue<Event> msg_queue_;
    bool svr_exit_;

private:
    pthread_t thread_hdl_;

    static DispatchEventService instance_;

};

#define des DispatchEventService::getInstance()

#endif