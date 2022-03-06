#ifndef LED_IEVENT_HANDLER_H_
#define LED_IEVENT_HANDLER_H_

#include "iEventHandler.h"
#include "dispatchEventService.h"
#include "events_def.h"

class LedEventHandler: public EventHandler{
public:
    LedEventHandler();
    ~LedEventHandler();
    void start();
    void stop();
    bool handle(const CEvent* ev);
};

#endif