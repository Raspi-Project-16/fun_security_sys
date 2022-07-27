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
#include "sg90EventHandler.h"
using namespace std;


class WS2811SignalCallback : public WS2811callback{

public:
    virtual void hasSignal(WS2811Driver* ws2811Driver, Color color){
        ws2811Driver->setColor(color);
    }
};

class RPISignalCallback : public RPICameraCallback{

public:
    RPISignalCallback(WS2811Driver* ws2811Driver, SG90Driver* sg90Driver){
        this->ws2811Driver = ws2811Driver;
        this->sg90Driver = sg90Driver;
    }
    ~RPISignalCallback(){
    }
    virtual void hasSignal(int isRecgnized){
        if(isRecgnized == SUCCEED){
            Color color = GREEN;
            ws2811Driver->callback(color);
            Degree degree = SG90_D90;
            sg90Driver->callback(degree);
        }
        if(isRecgnized == FAILED){
            Color color = RED;
            ws2811Driver->callback(color);
            Degree degree = SG90_D0;
            sg90Driver->callback(degree);
        }
        if(isRecgnized == NO_SAMPLES){
            Color color = RAINBOW;
            ws2811Driver->callback(color);
            Degree degree = SG90_D0;
            sg90Driver->callback(degree);
        }
    }
private:
    WS2811Driver* ws2811Driver = nullptr;
    SG90Driver* sg90Driver = nullptr;
};

class SG90SignalCallback : public SG90callback{
public:
    virtual void hasSignal(SG90Driver* sg90Driver, Degree degree){
        sg90Driver->setDegree(degree);
    }
};

class LEDSignalCallback : public LEDcallback{
public:

    virtual void hasSignal(LEDdriver* ledDriver, int signal){
        ledDriver->ledSwitch(signal);
    }
};

class SSSignalCallback : public SoundSensorCallback
{
public:
    SSSignalCallback(LEDdriver* driver){
        ledDriver = driver;
    }
    ~SSSignalCallback(){
    }

    virtual void hasSignal(int signal){
        ledDriver->callback(signal);
    }
    LEDdriver* ledDriver = nullptr;
};

int main(int argc, char* argv[]){

    

    //setters
    WS2811settings ws2811settings;
    RPICameraSettings rpiCameraSettings;
    SG90settings sg90Settings;
    SoundSensorSettings ssSettings;
    LEDsettings ledSettings;
    //drivers
    WS2811Driver ws2811Driver(ws2811settings);
    RPICameraDriver rpiCameraDriver(rpiCameraSettings);
    SG90Driver sg90Driver(sg90Settings);
    SoundSensorDriver ssDriver(ssSettings);
    LEDdriver ledDriver(ledSettings);
    //callbacks
    RPISignalCallback rpiSignalCallback(&ws2811Driver, &sg90Driver);
    rpiCameraDriver.registerCallback(&rpiSignalCallback);
    WS2811SignalCallback ws2811SignalCallback;
    ws2811Driver.registerCallback(&ws2811SignalCallback);
    SG90SignalCallback sg90SignalCallback;
    sg90Driver.registerCallback(&sg90SignalCallback);
    SSSignalCallback ssSignalCallback(&ledDriver);
    ssDriver.registerCallback(&ssSignalCallback);
    LEDSignalCallback ledSignalCallback;
    ledDriver.registerCallback(&ledSignalCallback);
    //start
    rpiCameraDriver.start();
    sg90Driver.start();
    ws2811Driver.start();
    ssDriver.start();
    ledDriver.start();
    //press a key to stop
    getchar();
    //stop
    sg90Driver.stop();
    ws2811Driver.stop();
    rpiCameraDriver.stop();
    ssDriver.stop();
    ledDriver.stop();

    return 0;
}
