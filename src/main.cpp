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


// void detectAndDisplay(Mat frame);
// String face_cascade_name, eyes_cascade_name;
// CascadeClassifier face_cascade;
// CascadeClassifier eyes_cascade;
// String window_name = "Capture - Face detection";


int main(int argc, char* argv[]){

    des->init();
    // int GPIO_28 = 28;
    // int GPIO_27 = 27;
    
    // if(-1 == wiringPiSetup())
    //   {
    //       cerr<<"setup error\n";
    //       exit(-1);
    //   }
    
    // pinMode(GPIO_28, INPUT);
    // pinMode(GPIO_27, OUTPUT);

    // LedEventHandler ledHandler;
    // ledHandler.start();
    // Ws2811EventHandler ws2811Handler;
    // ws2811Handler.start();
    // SoundEventHandler soundHandler;
    // soundHandler.start(GPIO_28, GPIO_27);
    CameraEventHandler camHandler;
    camHandler.start();

    for(;;){
      sleep(1);
    }

    return 0;

    // face_cascade_name = "haarcascade_frontalface_default.xml";
    // eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";

    // VideoCapture stream1;
    // Mat frame;

    // //Step 1) Load the cascades
    // if (!face_cascade.load(face_cascade_name))
    // {
    //     cout << "error loading face cascade" << endl;
    //     return -1;
    // }

    // if (!eyes_cascade.load(eyes_cascade_name))
    // {
    //     cout << "error loading eyes cascade" << endl;
    //     return -1;
    // }

    // //Step 2) read in video stream

    // stream1.open(0);
    // if (!stream1.isOpened())
    // {
    //     cout << "can not open camera" << endl;
    //     return -1;
    // }
    // while (stream1.read(frame))
    // {
    //     if (frame.empty())
    //     {
    //         cout << "frame is empty" << endl;
    //         break;
    //     }
    //     //Step 3) Apply the classifier to the frame
    //     detectAndDisplay(frame);
    //     if (waitKey(10) == 27)
    //     {
    //         break;
    //     }
    // }
    // return 0;
    

}
// void detectAndDisplay(Mat frame)
// {
//     std::vector<Rect> faces;
//     Mat frame_gray;
//     cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
//     equalizeHist(frame_gray, frame_gray);

//     // Detect the faces
//     face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(60, 60));

//     for (size_t i = 0; i< faces.size(); ++i)
//     {
//         Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
//         ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);

//         Mat faceROI = frame_gray(faces[i]);
//         std::vector<Rect> eyes;

//         //in each face, find eye
//         eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

//         for (size_t j = 0; j<eyes.size(); ++j)
//         {
//             Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + +eyes[j].y + eyes[j].height / 2);
//             int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
//             circle(frame, eye_center, radius, Scalar(255, 0, 0), 4, 8, 0);

//         }

//     }
//     imshow(window_name, frame);
// }