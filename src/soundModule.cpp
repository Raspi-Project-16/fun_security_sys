#include "soundModule.h"
#include <pigpio.h>

soundModule::soundModule(int gpio){
    this->gpio = gpio;
}

bool soundModule::detectSound(){
    
    if(gpioRead(this->gpio) == 0){
        cout << "Sound detected!" << endl;
        return true;
    }else{
        cout << "Sound not detected!" << endl;
        return false;
    }
}

soundModule::~soundModule(){

}