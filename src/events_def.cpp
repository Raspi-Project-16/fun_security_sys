#include "events_def.h"


/*----------------------------------------------------------------------
  |       LedEvent::LedEvent
  +---------------------------------------------------------------------*/

LedEvent::LedEvent(int gpio, string msg){
    this->gpio_ = gpio;
    this->setEid(EEVENTID_LED_REQ);
    this->content_ = msg;
}

/*----------------------------------------------------------------------
  |       LedEvent::~LedEvent
  +---------------------------------------------------------------------*/

LedEvent::~LedEvent(){

}

/*----------------------------------------------------------------------
  |       LedEvent::ledOn
  +---------------------------------------------------------------------*/

void LedEvent::ledOn(){
    digitalWrite(this->gpio_, HIGH);
    //gpioWrite(this->gpio_, 1);
}

/*----------------------------------------------------------------------
  |       LedEvent::ledOff
  +---------------------------------------------------------------------*/

void LedEvent::ledOff(){
    digitalWrite(this->gpio_, LOW);
    //gpioWrite(this->gpio_, 1);
}


/*----------------------------------------------------------------------
  |       SoundEvent::SoundEvent
  +---------------------------------------------------------------------*/

SoundEvent::SoundEvent(int gpio, string msg){
    this->gpio_ = gpio;
    this->setEid(EEVENTID_SOUND_REQ);
    this->content_ = msg;
}

/*----------------------------------------------------------------------
  |       SoundEvent::~SoundEvent
  +---------------------------------------------------------------------*/

SoundEvent::~SoundEvent(){

}

/*----------------------------------------------------------------------
  |       SoundEvent::detectSound
  +---------------------------------------------------------------------*/

bool SoundEvent::detectSound(){
    if(digitalRead(this->gpio_) == LOW){
        //cout << "Sound detected!" << endl;
        return true;
    }else{
        //cout << "Sound not detected!" << endl;
        return false;
    }
    //gpioWrite(this->gpio_, 1);
}


/*----------------------------------------------------------------------
  |       Ws2811Event::Ws2811Event
  +---------------------------------------------------------------------*/

Ws2811Event::Ws2811Event(string msg)
{
    this->setEid(EEVENTID_WS2811_REQ);
    this->content_ = msg;

}
/*----------------------------------------------------------------------
  |       Ws2811Event::~Ws2811Event
  +---------------------------------------------------------------------*/
Ws2811Event::~Ws2811Event()
{

}
/*----------------------------------------------------------------------
  |       Ws2811Event::setMsg
  +---------------------------------------------------------------------*/
void Ws2811Event::setMsg(string msg){
    this->content_ = msg;
}

Ws2811Event Ws2811Event::ins = Ws2811Event(RAINBOW_COLOR);




/*----------------------------------------------------------------------
  |       CameraEvent::CameraEvent
  +---------------------------------------------------------------------*/
CameraEvent::CameraEvent()
{
     this->setEid(EEVENTID_CAMERA_REQ);
}

/*----------------------------------------------------------------------
  |       CameraEvent::~CameraEvent
  +---------------------------------------------------------------------*/

CameraEvent::~CameraEvent()
{

}
