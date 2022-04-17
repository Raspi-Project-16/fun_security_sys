#include "sg90EventHandler.h"

/*----------------------------------------------------------------------
  |       Sg90EventCallback::Sg90EventCallback
  +---------------------------------------------------------------------*/

Sg90EventCallback::Sg90EventCallback(){
    
}

/*----------------------------------------------------------------------
  |       Sg90EventCallback::~Sg90EventCallback
  +---------------------------------------------------------------------*/

Sg90EventCallback::~Sg90EventCallback(){
    
}

/*----------------------------------------------------------------------
  |       Sg90EventCallback::start
  +---------------------------------------------------------------------*/

void Sg90EventCallback::start(){
    // register the event
    des->subscribe(EEVENTID_MOTOR_REQ, this);
    des->publish(sg90MotorEv);
}

/*----------------------------------------------------------------------
  |       Sg90EventCallback::stop
  +---------------------------------------------------------------------*/

void Sg90EventCallback::stop(){
    //unregister the event
    des->unsubscribe(EEVENTID_MOTOR_REQ, this);
}

/*----------------------------------------------------------------------
  |       Sg90EventCallback::callback
  +---------------------------------------------------------------------*/
bool Sg90EventCallback::callback(const CEvent* ev){
    
    if(EEVENTID_MOTOR_REQ == ev->getEid()){
        Sg90MotorEvent* req = (Sg90MotorEvent*) ev;
        // turn on the motor
        if(req->getMsg() == MOTOR_ON){
            req->motorOn();
        // turn off the motor
        }else{
            req->motorOff();
        }
        des->publish(req); 
    }else{
        
    }

    return true;
}
