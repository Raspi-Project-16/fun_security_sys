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



class LedEvent : public CEvent{

public:
    LedEvent(u32 gpio, string msg);
    ~LedEvent();

    void ledOn();
    void ledOff();

    u32 getGPIO() const {return gpio_;};

    string getMsg() const {return this->content_;};

private:

    u32 gpio_;

};

class SoundEvent : public CEvent{

public:
    SoundEvent(u32 gpio, string msg);
    ~SoundEvent();

    bool detectSound();

    u32 getGPIO() const {return gpio_;};
    string getMsg() const {return this->content_;};


private:

    u32 gpio_;

};

/**
 * @brief Ws2811Event
 * 
 */

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


/**
 * @brief CameraEvent
 * 
 */

class CameraEvent : public CEvent
{

public:
    string getMsg() const {return this->content_;};
    ~CameraEvent();
    CameraEvent();
    
private:
    
};


#endif
