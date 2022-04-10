#include <iostream>
#include <pigpio.h>
#include "soundModule.h"
#include "lightModule.h"
#include "timeModule.h"
#include "ledModule.h"
#include <unistd.h>
#include <time.h>
#include <thread>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "soundEventHandler.h"
#include "ledEventHandler.h"
#include "ws2811EventHandler.h"
#include "cameraEventHandler.h"
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

    //LedEventHandler ledHandler;
    //ledHandler.start();
    Ws2811EventHandler ws2811Handler;
    ws2811Handler.start();
    SoundEventHandler soundHandler;
    soundHandler.start(GPIO_28, GPIO_27);
    CameraEventHandler camHandler;
    camHandler.start();

    for(;;){
      
    }

    return 0;

}
