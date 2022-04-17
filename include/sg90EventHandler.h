#ifndef SG90_IEVENT_HANDLER_H_
#define SG90_IEVENT_HANDLER_H_

#include "iEventHandler.h"
#include "dispatchEventService.h"
#include "events_def.h"

/*----------------------------------------------------------------------
  |       Sg90EventCallback
  +---------------------------------------------------------------------*/

class Sg90EventCallback: public EventCallback{
public:
    Sg90EventCallback();
    ~Sg90EventCallback();
    void start();
    void stop();
    bool callback(const CEvent* ev);
};

#endif
