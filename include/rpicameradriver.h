#ifndef RPICAMERADRIVER_H
#define RPICAMERADRIVER_H



#include <iostream>
#include <algorithm>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <raspicam/raspicam_cv.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <time.h>
#include <thread>

using namespace cv;
using namespace std;
using namespace cv::face;

enum RESULT{
  SUCCEED = 1,
  FAILED = 0,
  NO_SAMPLES = -1
};

/*----------------------------------------------------------------------
  |       RPICameraSettings
  +---------------------------------------------------------------------*/

struct RPICameraSettings{
  string faceLabelPath = "/home/pi/fss_T16/recognizer/labels.txt";
  string classiferPath = "/home/pi/fss_T16/cascades/haarcascade_frontalface_alt.xml";
  string recognizerPath = "/home/pi/fss_T16/recognizer/embeddings.xml";

};

/*----------------------------------------------------------------------
  |       RPICameraCallback
  +---------------------------------------------------------------------*/

class RPICameraCallback{

public:
  virtual void hasSignal(int isRecgnized) = 0;

};

/*----------------------------------------------------------------------
  |       RPICameraCallback
  +---------------------------------------------------------------------*/

class RPIImageCallback{

public:
  virtual void hasSample(Mat image) = 0;

};

/*----------------------------------------------------------------------
  |       RPICameraDriver
  +---------------------------------------------------------------------*/

class RPICameraDriver {
public:
    RPICameraDriver(RPICameraSettings settings);
    ~RPICameraDriver();
    void registerCallback(RPICameraCallback* cb);
    void registerImageCallback(RPIImageCallback* cb);
    void unRegisterCallback();
    void start();
    void stop();
    Mat takePictures();

private:
    Mat frame;
    Mat windowFrame;
    raspicam::RaspiCam_Cv Camera;
    map<int, string> labels;
    CascadeClassifier classifier;
    Ptr<LBPHFaceRecognizer> recognizer = LBPHFaceRecognizer::create(2, 2, 7, 7, 17);
    vector<Rect> faces;
    double secondsElapsed;
    thread* rpiCameraThread = nullptr;
    RPICameraCallback* rpiCameraCallback = nullptr;
    RPIImageCallback* rpiImageCallback = nullptr;
    RPICameraSettings rpiCamerasettings;
    int running = 1;

    void run();
    static void execute(RPICameraDriver* rpiCameraDriver){
      rpiCameraDriver->run();
    }
};

#endif // RPICAMERADRIVER_H
