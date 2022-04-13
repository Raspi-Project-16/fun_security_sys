#ifndef LED_IEVENT_HANDLER_H_
#define LED_IEVENT_HANDLER_H_

#include "iEventHandler.h"
#include "dispatchEventService.h"
#include "events_def.h"

class LedEventCallback: public EventCallback{
public:
    LedEventCallback();
    ~LedEventCallback();
    void start();
    void stop();
    bool callback(const CEvent* ev);
};

#endif
