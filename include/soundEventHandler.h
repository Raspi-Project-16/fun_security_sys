#ifndef SOUND_IEVENT_HANDLER_H_
#define SOUND_IEVENT_HANDLER_H_


#include "iEventHandler.h"
#include "dispatchEventService.h"
#include "events_def.h"

/*----------------------------------------------------------------------
  |       SoundEventCallback
  +---------------------------------------------------------------------*/

class SoundEventCallback: public EventCallback{
public:
    SoundEventCallback();
    ~SoundEventCallback();
    void start();
    void stop();
    bool callback(const CEvent* ev);
private:
    SoundEvent* soundEv;
    int count = 0;
};


#endif
