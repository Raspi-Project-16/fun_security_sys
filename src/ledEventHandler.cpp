#include "ledEventHandler.h"

/*----------------------------------------------------------------------
  |       LedEventCallback::LedEventCallback
  +---------------------------------------------------------------------*/

LedEventCallback::LedEventCallback(){
    
}

/*----------------------------------------------------------------------
  |       LedEventCallback::~LedEventCallback
  +---------------------------------------------------------------------*/

LedEventCallback::~LedEventCallback(){
    
}

/*----------------------------------------------------------------------
  |       LedEventCallback::start
  +---------------------------------------------------------------------*/

void LedEventCallback::start(){
    // register the event
    des->subscribe(EEVENTID_LED_REQ, this);
}

/*----------------------------------------------------------------------
  |       LedEventCallback::stop
  +---------------------------------------------------------------------*/

void LedEventCallback::stop(){
    //unregister the event
    des->unsubscribe(EEVENTID_LED_REQ, this);
}

/*----------------------------------------------------------------------
  |       LedEventCallback::callback
  +---------------------------------------------------------------------*/
bool LedEventCallback::callback(const CEvent* ev){
    
    if(EEVENTID_LED_REQ == ev->getEid()){
        LedEvent* req = (LedEvent*) ev;
        // turn on the light
        if(req->getMsg() == "ON"){
            req->ledOn();
        // turn off the light
        }else{
            req->ledOff();
        }
            
    }else{
        
    }

    return true;
}
