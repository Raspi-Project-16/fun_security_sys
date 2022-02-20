#include <iostream>
#include <wiringPi.h>
#include "soundModule.h"
#include "lightModule.h"
#include "timeModule.h"
#include <unistd.h>
#include <time.h>
#include <thread>
#include <opencv2/opencv.hpp>
using namespace std;



int main(int argc, char* argv[]){

    int GPIO_29 = 29;
    int GPIO_28 = 28;
    wiringPiSetup();
    pinMode(GPIO_28, INPUT);
    pinMode(GPIO_29, OUTPUT);
    digitalWrite(GPIO_28, LOW);
    digitalWrite(GPIO_29, LOW);

    lightModule light(GPIO_29);
    soundModule sound(GPIO_28);
    timeModule time;

    while(true){
        if(sound.detectSound()){
            light.lightUp();
            time.startms(250);
            std::this_thread::sleep_for(std::chrono::seconds(2));
            time.stop();
        }else{
            light.lightOff();
        }
    }

    return 0;
}