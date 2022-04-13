#include "soundEventHandler.h"


SoundEventCallback::SoundEventCallback(){
    
}

SoundEventCallback::~SoundEventCallback(){
    
}

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


void SoundEventCallback::stop(){
    // unregister the callback
    des->unsubscribe(EEVENTID_SOUND_REQ, this);
}

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
            digitalWrite(stringToNum<int>(req->getMsg()), HIGH);
            //LedEvent* ledEv = new LedEvent(stringToNum<int>(req->getMsg()), "ON");
            //des->publish(ledEv);
        }else{
            digitalWrite(stringToNum<int>(req->getMsg()), LOW);
            //LedEvent* ledEv = new LedEvent(stringToNum<int>(req->getMsg()), "OFF");
            //des->publish(ledEv);
        }
        
        
        
        //SoundEvent* soundEv = new SoundEvent(req->getGPIO(), req->getMsg());
        des->publish(soundEv);
    }else{
        cout << "unsubscribed events!" << endl;
    }

    return true;
}
