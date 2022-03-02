#ifndef NS_IEVENT_HANDLER_H_
#define NS_IEVENT_HANDLER_H_

#include "event.h"
#include "events_def.h"

class EventHandler
{
public:
    virtual bool handle(const Event* ev) = 0;
    virtual ~EventHandler() {};
    EventHandler(){};
};

#endif