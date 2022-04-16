#ifndef ALL_EVENT_TYPE_H_
#define ALL_EVENT_TYPE_H_

#include <iostream>
#include "event.h"
#include <string>
#include "eventId.h"
#include <pigpio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <dispatchEventService.h>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/imgproc/types_c.h>
#include <raspicam/raspicam_cv.h>
#include <ctime>
#include <fstream>
#include <map>
#include <time.h>
using namespace std;
using namespace cv;
using namespace cv::face;


/*----------------------------------------------------------------------
  |       edEvent
  +---------------------------------------------------------------------*/


class LedEvent : public CEvent{

public:
    LedEvent(int gpio, string msg);
    ~LedEvent();

    void ledOn();
    void ledOff();

    int getGPIO() const {return gpio_;};

    string getMsg() const {return this->content_;};

private:

    int gpio_;

};

/*----------------------------------------------------------------------
  |       SoundEvent
  +---------------------------------------------------------------------*/

class SoundEvent : public CEvent{

public:
    SoundEvent(int gpio, string msg);
    ~SoundEvent();

    bool detectSound();

    int getGPIO() const {return gpio_;};
    string getMsg() const {return this->content_;};


private:

    int gpio_;

};

/*----------------------------------------------------------------------
  |       Ws2811Event
  +---------------------------------------------------------------------*/

class Ws2811Event : public CEvent
{

public:
    static Ws2811Event* getInstance(){ 
        return &ins;
    };
    string getMsg() const {return this->content_;};
    void setMsg(string msg);
    Ws2811Event(string msg);
    ~Ws2811Event();

private:
    static Ws2811Event ins;
};

#define ws2811Ev Ws2811Event::getInstance()


/*----------------------------------------------------------------------
  |       CameraEvent
  +---------------------------------------------------------------------*/

class CameraEvent : public CEvent
{

public:
    string getMsg() const {return this->content_;};
    ~CameraEvent();
    CameraEvent();
    
private:
    
};


#endif
