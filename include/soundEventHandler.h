#ifndef SOUND_IEVENT_HANDLER_H_
#define SOUND_IEVENT_HANDLER_H_


#include "iEventHandler.h"
#include "dispatchEventService.h"
#include "events_def.h"

class SoundEventHandler: public EventHandler{
public:
    SoundEventHandler();
    ~SoundEventHandler();
    void start(u32 gpio, u32 msg);
    void stop();
    bool handle(const CEvent* ev);
private:
    SoundEvent* soundEv;
    int count = 0;
};


#endif
