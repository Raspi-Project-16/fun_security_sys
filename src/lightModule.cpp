#include "lightModule.h"

lightModule::lightModule(int gpio){
    this->gpio = gpio;
}

void lightModule::lightUp(){
    digitalWrite(this->gpio, HIGH);
    cout << "Light on" << endl;
}

void lightModule::lightOff(){
    digitalWrite(this->gpio, LOW);
    cout << "Light off" << endl;
}

lightModule::~lightModule(){
    
}