#ifndef ALL_EVENT_TYPE_H_
#define ALL_EVENT_TYPE_H_

#include <iostream>
#include "event.h"
#include <string>
#include "eventId.h"
#include <pigpio.h>
#include <wiringPi.h>
#include <dispatchEventService.h>
using namespace std;



class LedEvent : public CEvent{

public:
    LedEvent(u32 gpio, string msg);
    ~LedEvent();
    //virtual std::ostream& dump(std::ostream& out) const;

    //virtual bool decode();
    //virtual char* encode();

    void ledOn();
    void ledOff();

    u32 getGPIO() const {return gpio_;};
    //void setGPIO();
    string getMsg() const {return this->content_;};

private:

    u32 gpio_;

};

class SoundEvent : public CEvent{

public:
    SoundEvent(u32 gpio, string msg);
    ~SoundEvent();

    //virtual std::ostream& dump(std::ostream& out) const;

    //virtual bool decode();
    //virtual char* encode();

    bool detectSound();

    u32 getGPIO() const {return gpio_;};
    string getMsg() const {return this->content_;};
    //const u32 getGPIO();
    //void setGPIO();

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
    u32 getGPIO() const {return gpio_;};
    string getMsg() const {return this->content_;};
    Ws2811Event();
    ~Ws2811Event();

private:
    u32 gpio_;
};


#endif