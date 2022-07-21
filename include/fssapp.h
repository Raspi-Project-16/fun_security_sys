#ifndef FSSAPP_H
#define FSSAPP_H
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
#include "soundsensordriver.h"
#include "leddriver.h"
#include "ws2811driver.h"
#include "rpicameradriver.h"
#include "sg90driver.h"
#include "mainwindow.h"
#include "facetraining.h"
#include <string>
#include <QThread>
using namespace std;

// inherit WS2811callback to rewrite the virtual function
// received a signal to change the color
class WS2811SignalCallback : public WS2811callback{

public:
    virtual void hasSignal(WS2811Driver* ws2811Driver, Color color){
        ws2811Driver->setColor(color);
    }
};

// inherit RPICameraCallback to rewrite the virtual function
// received a signal from the result whether the face recognition was successful or not
class RPISignalCallback : public RPICameraCallback{

public:
    RPISignalCallback(WS2811Driver* ws2811Driver, SG90Driver* sg90Driver){
        this->ws2811Driver = ws2811Driver;
        this->sg90Driver = sg90Driver;
    }
    ~RPISignalCallback(){
    }
    // if the face recognition is a success, change the color of the led strip to green, rotate the motor
    // otherwise change the color to red, no rotation for the motor
    virtual void hasSignal(int isRecgnized){
        if(isRecgnized == SUCCEED){
            Color color = GREEN;
            ws2811Driver->callback(color);
            int degree = 0;
            sg90Driver->callback(degree);
        }
        if(isRecgnized == FAILED){
            Color color = RED;
            ws2811Driver->callback(color);
            int degree = 90;
            sg90Driver->callback(degree);
        }
    }
private:
    WS2811Driver* ws2811Driver = nullptr;
    SG90Driver* sg90Driver = nullptr;
};

// inherit SG90callback to rewrite the virtual function
// received a signal to rotate the motor
class SG90SignalCallback : public SG90callback{
public:
    virtual void hasSignal(SG90Driver* sg90Driver, int degree){
        sg90Driver->setDegree(degree);
    }
};

// inherit LEDcallback to rewrite the virtual function
// received a signal to turn on/off the led bulb
class LEDSignalCallback : public LEDcallback{
public:

    virtual void hasSignal(LEDdriver* ledDriver, int signal){
        ledDriver->ledSwitch(signal);
    }
};

// inherit SoundSensorCallback to rewrite the virtual function
// received a signal whether a sound is detected
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


class FssApp : public QWidget
{
    Q_OBJECT

public:
    FssApp();
    void resizeEvent(QResizeEvent *event);
    ~FssApp();

    //slots
private slots:
    void ledSignalReceived(int signal);
    void degreeSignalReceived(int degree);
    void stripSignalReceived(int index);
    void startSignalReceived();
    void stopSignalReceived();
    void trainSignalReceived();

private:
    //setters
    WS2811settings ws2811settings;
    RPICameraSettings rpiCameraSettings;
    SG90settings sg90Settings;
    SoundSensorSettings ssSettings;
    LEDsettings ledSettings;

    //drivers
    WS2811Driver ws2811Driver= WS2811Driver(ws2811settings);
    RPICameraDriver rpiCameraDriver = RPICameraDriver(rpiCameraSettings);
    SG90Driver sg90Driver = SG90Driver(sg90Settings);
    SoundSensorDriver ssDriver= SoundSensorDriver(ssSettings);
    LEDdriver ledDriver= LEDdriver(ledSettings);

    //callbacks
    RPISignalCallback rpiSignalCallback= RPISignalCallback(&ws2811Driver, &sg90Driver);
    WS2811SignalCallback ws2811SignalCallback;
    SG90SignalCallback sg90SignalCallback;
    SSSignalCallback ssSignalCallback = SSSignalCallback(&ledDriver);
    LEDSignalCallback ledSignalCallback;

    //window
    MainWindow* window;

    //face trainer
    FaceTraining * face_trainer;
};

#endif // FSSAPP_H
