#ifndef CAMERA_IEVENT_HANDLER_H_
#define CAMERA_IEVENT_HANDLER_H_

#include "iEventHandler.h"
#include "dispatchEventService.h"
#include "events_def.h"

class CameraEventHandler: public EventHandler{
public:
    CameraEventHandler();
    ~CameraEventHandler();
    void start();
    void stop();
    bool handle(const CEvent* ev);
private:
    CameraEvent* cameraEv = new CameraEvent();
};

#endif
