#ifndef FACETRAINING_H
#define FACETRAINING_H

#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <fstream>
#include <string>
#include <vector>
#include <errno.h>
#include "opencv2/imgproc.hpp"
#include <opencv2/imgproc/types_c.h>
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/face.hpp"
#include <QThread>

using namespace std;
using namespace cv;
using namespace cv::face;

class FaceTraining : public QThread
{
     Q_OBJECT
public:
    explicit FaceTraining(QObject *parent = nullptr);
    ~FaceTraining();
    int getDir(string dir, vector<string> &files);
    void train();

protected:
    void run() override{
        this->train();
        emit finishedSignal();
    };

signals:
    void finishedSignal();

private:
    Mat frame;
    Mat picture;
    string fileName = string("/home/pi/fss_T16/dataset");
    vector<string> dirs = vector<string>();
    vector<Mat> Images;
    vector<int> Labels;
    Ptr<LBPHFaceRecognizer> recognizer = LBPHFaceRecognizer::create(2, 2, 7, 7);
    CascadeClassifier classifier;
    ofstream labels;
};

#endif // FACETRAINING_H
