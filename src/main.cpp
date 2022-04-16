#include <iostream>
#include <pigpio.h>
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
    if(-1 == wiringPiSetup())
      {
          cerr<<"setup error\n";
          exit(-1);
      }
    

    //start the LED strip
    Ws2811EventCallback ws2811Callback;
    ws2811Callback.start();
    //star the sound sensor
    SoundEventCallback soundCallback;
    soundCallback.start();
    //start the camera
    CameraEventCallback camCallback;
    camCallback.start();

    for(;;){
      
    }

    return 0;

}
