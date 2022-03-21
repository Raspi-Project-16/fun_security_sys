#include "soundEventHandler.h"


SoundEventHandler::SoundEventHandler(){
    
}

SoundEventHandler::~SoundEventHandler(){
    
}

void SoundEventHandler::start(u32 gpio, u32 msg){
    des->subscribe(EEVENTID_SOUND_REQ, this);
    SoundEvent* soundEv = new SoundEvent(gpio, NumtoString(msg));
    des->publish(soundEv);
}


void SoundEventHandler::stop(){
    des->unsubscribe(EEVENTID_SOUND_REQ, this);
}

bool SoundEventHandler::handle(const CEvent* ev){
    if(EEVENTID_SOUND_REQ == ev->getEid()){
        SoundEvent* req = (SoundEvent*) ev;
        //do something here
        if(req->detectSound()){
            LedEvent* ledEv = new LedEvent(stringToNum<int>(req->getMsg()), "ON");
            des->publish(ledEv);
        }else{
            LedEvent* ledEv = new LedEvent(stringToNum<int>(req->getMsg()), "OFF");
            des->publish(ledEv);
        }
        SoundEvent* soundEv = new SoundEvent(req->getGPIO(), req->getMsg());
        des->publish(soundEv);
    }else{
        cout << "unsubscribed events!" << endl;
    }

    return true;
}
