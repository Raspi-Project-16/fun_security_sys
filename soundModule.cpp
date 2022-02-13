#include "soundModule.h"

soundModule::soundModule(int gpio){
    this->gpio = gpio;
}

bool soundModule::detectSound(){
    if(digitalRead(this->gpio) == LOW){
        return true;
        cout << "Sound detected!" << endl;
    }else{
        return false;
        cout << "Sound not detected!" << endl;
    }
}

soundModule::~soundModule(){

}