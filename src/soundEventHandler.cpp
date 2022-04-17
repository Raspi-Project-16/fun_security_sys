#include "soundEventHandler.h"


/*----------------------------------------------------------------------
  |       SoundEventCallback::SoundEventCallback
  +---------------------------------------------------------------------*/

SoundEventCallback::SoundEventCallback(){
    
}

/*----------------------------------------------------------------------
  |       SoundEventCallback::~SoundEventCallback
  +---------------------------------------------------------------------*/
SoundEventCallback::~SoundEventCallback(){
    
}

/*----------------------------------------------------------------------
  |       SoundEventCallback::start
  +---------------------------------------------------------------------*/
void SoundEventCallback::start(){
    // register the callback
    des->subscribe(EEVENTID_SOUND_REQ, this);
    // initialse the gpio pins
    pinMode(LED_PIN, OUTPUT);
    pinMode(SOUND_PIN, INPUT);
    // initialise a sound event
    soundEv = new SoundEvent(SOUND_PIN, NumtoString(LED_PIN));
    des->publish(soundEv);
}

/*----------------------------------------------------------------------
  |       SoundEventCallback::stop
  +---------------------------------------------------------------------*/

void SoundEventCallback::stop(){
    // unregister the callback
    des->unsubscribe(EEVENTID_SOUND_REQ, this);
}

/*----------------------------------------------------------------------
  |       SoundEventCallback::callback
  +---------------------------------------------------------------------*/

bool SoundEventCallback::callback(const CEvent* ev){
    if(EEVENTID_SOUND_REQ == ev->getEid()){
        
        SoundEvent* req = (SoundEvent*) ev;
        //if the sound sensor has received an signal, start the timing
        if(req->detectSound() && this->count == 0){
            this->count = 100;
        }
        // if the timing is not done, keep the light on
        if(this->count > 0){
            this->count--;
            ledEv->setMsg(LED_ON);
            //digitalWrite(stringToNum<int>(req->getMsg()), HIGH);
            
        }else{
            //digitalWrite(stringToNum<int>(req->getMsg()), LOW);
            ledEv->setMsg(LED_OFF);
        }
        
        des->publish(req);
    }else{
        cout << "unsubscribed events!" << endl;
    }

    return true;
}
