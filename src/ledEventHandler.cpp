#include "ledEventHandler.h"



LedEventHandler::LedEventHandler(){
    
}

LedEventHandler::~LedEventHandler(){
    
}

void LedEventHandler::start(){
    des->subscribe(EEVENTID_LED_REQ, this);
}


void LedEventHandler::stop(){
    des->unsubscribe(EEVENTID_LED_REQ, this);
}

bool LedEventHandler::handle(const CEvent* ev){
    if(EEVENTID_LED_REQ == ev->getEid()){
        LedEvent* req = (LedEvent*) ev;
        //do something here
        if(req->getMsg() == "ON"){
            req->ledOn();
        }else{
            req->ledOff();
        }
            
    }else{
        
    }

    return true;
}