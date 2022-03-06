#include <iostream>
#include <pigpio.h>
#include "soundModule.h"
#include "lightModule.h"
#include "timeModule.h"
#include "ledModule.h"
#include <unistd.h>
#include <time.h>
#include <thread>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>                        
#include <opencv2/imgcodecs.hpp>            
#include <opencv2/highgui.hpp> 
#include "soundEventHandler.h"
#include "ledEventHandler.h"
#include "ws2811EventHandler.h"
using namespace std;
using namespace cv;



int main(int argc, char* argv[]){

    des->init();
    int GPIO_28 = 28;
    int GPIO_27 = 27;
    
    if(-1 == wiringPiSetup())
      {
          cerr<<"setup error\n";
          exit(-1);
      }
    
    pinMode(GPIO_28, INPUT);
    pinMode(GPIO_27, OUTPUT);

    LedEventHandler ledHandler;
    ledHandler.start();
    Ws2811EventHandler ws2811Handler;
    ws2811Handler.start();
    SoundEventHandler soundHandler;
    soundHandler.start(GPIO_28, GPIO_27);
    

    for(;;){
      sleep(1);
    }

//     if (gpioInitialise() < 0)
//    {
//       cout << stderr << "pigpio initialisation failed" << endl;
//       return 1;
//    }

//     int GPIO_28 = 28;
//     gpioSetMode(GPIO_28, PI_INPUT);

//     soundModule sound(GPIO_28);
//     timeModule time;
//     ledModule led(18, 150, 400000);

//     while(true){
//         if(sound.detectSound()){
//             //light.lightUp();
//             //led.shutdown();
//             led.run();
//             // time.startms(250);
//             // std::this_thread::sleep_for(std::chrono::seconds(2));
//             // time.stop();
//         }else{
//             //light.lightOff();
//         }
//     }
//     //led.shutdown();

//     return 0;
}