#include "events_def.h"


/**
 * @brief Construct a new Led Event:: Led Event object
 * 
 * @param gpio 
 */

LedEvent::LedEvent(u32 gpio, string msg){
    this->gpio_ = gpio;
    this->setEid(EEVENTID_LED_REQ);
    this->content_ = msg;
}

LedEvent::~LedEvent(){

}

void LedEvent::ledOn(){
    digitalWrite(this->gpio_, HIGH);
    //gpioWrite(this->gpio_, 1);
}

void LedEvent::ledOff(){
    digitalWrite(this->gpio_, LOW);
    //gpioWrite(this->gpio_, 1);
}


/**
 * @brief Construct a new Sound Event:: Sound Event object
 * 
 * @param gpio 
 */

SoundEvent::SoundEvent(u32 gpio, string msg){
    this->gpio_ = gpio;
    this->setEid(EEVENTID_SOUND_REQ);
    this->content_ = msg;
}

SoundEvent::~SoundEvent(){

}

bool SoundEvent::detectSound(){
    if(digitalRead(this->gpio_) == LOW){
        cout << "Sound detected!" << endl;
        return true;
    }else{
        cout << "Sound not detected!" << endl;
        return false;
    }
    //gpioWrite(this->gpio_, 1);
}

/**
 * @brief Construct a new Ws2811Event:: Ws 2811Event object
 * 
 */



Ws2811Event::Ws2811Event()
{
    this->setEid(EEVENTID_WS2811_REQ);

}

