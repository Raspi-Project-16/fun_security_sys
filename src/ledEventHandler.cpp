#include "ledEventHandler.h"
#include "dispatchEventService.h"
#include "events_def.h"
#include <stdio.h>


LedEventHandler::LedEventHandler(){
    
}

LedEventHandler::~LedEventHandler(){
    
}

void LedEventHandler::init(){
    des->subscribe(EEVENTID_LED_REQ, this);
}


void LedEventHandler::uninit(){
    des->unsubscribe(EEVENTID_LED_REQ, this);
}

bool LedEventHandler::handle(const Event* ev){
    if(EEVENTID_LED_REQ == ev->getEid()){
        LedEvent* req = (LedEvent*) ev;
        //do something here
    }else{
        
    }
}