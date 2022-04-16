#ifndef CAMERA_IEVENT_HANDLER_H_
#define CAMERA_IEVENT_HANDLER_H_

#include "iEventHandler.h"
#include "dispatchEventService.h"
#include "events_def.h"

/*----------------------------------------------------------------------
  |       CameraEventCallback
  +---------------------------------------------------------------------*/

class CameraEventCallback: public EventCallback{
public:
    CameraEventCallback();
    ~CameraEventCallback();
    void start();
    void stop();
    bool callback(const CEvent* ev);
    void freeInstance();
private:
    Mat frame;
    Mat windowFrame;
    raspicam::RaspiCam_Cv Camera;
    map<int, string> labels;
    CascadeClassifier classifier;
    Ptr<LBPHFaceRecognizer> recognizer = LBPHFaceRecognizer::create(2, 2, 7, 7, 17);
    int numframes = 0;
    time_t timer_begin,timer_end;
    vector<Rect> faces;
    double secondsElapsed;
    CameraEvent* cameraEv;
};

#endif
