#include "lightModule.h"
#include <pigpio.h>

lightModule::lightModule(int gpio){
    this->gpio = gpio;
}

void lightModule::lightUp(){
    gpioWrite(this->gpio, 1);
    cout << "Light on" << endl;
}

void lightModule::lightOff(){
    gpioWrite(this->gpio, 0);
    //cout << "Light off" << endl;
}

lightModule::~lightModule(){
    
}