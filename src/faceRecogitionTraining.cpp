#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/imgproc/types_c.h>

#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <fstream>

using namespace cv;
using namespace std;
using namespace cv::face;

int getdir (string dir, vector<string> &files)
{
    DIR *df;
    struct dirent *dirf;
    // open the input directory
    // check if there are pictures in the directory
    if((df  = opendir(dir.c_str())) == NULL) {
        cerr << errno << endl;
        return errno;
    }
    //take the file name as a factor of in the string vector
    while ((dirf = readdir(df)) != NULL) {
        if(to_string('.').compare(string(dirf->d_name)) < 0
		|| to_string('.').compare(string(dirf->d_name)) < 0) {
		files.push_back(string(dirf->d_name));
	}
    }
    closedir(df);
    return 0;
}

int main(){
  
  
  Mat picture;
  Mat frame;
  string filename = string("/home/pi/fun_security_sys/dataset");
  vector<string> dirs = vector<string>();
  getdir(filename, dirs);
  vector<Mat> Images;
  vector<int> Labels;
  namedWindow("edges", 1);
  Ptr<LBPHFaceRecognizer> recognizer = LBPHFaceRecognizer::create(2, 2, 7, 7);
  CascadeClassifier classifier;
  classifier.load("/home/pi/fun_security_sys/cascades/haarcascade_frontalface_default.xml");
  ofstream labels;
  labels.open("/home/pi/fun_security_sys/recognizer/labels.txt");

  for(unsigned int i = 0; i < dirs.size(); i++) {
	labels << i << " " << dirs[i] << endl;
	string new_path = filename + "/" + dirs[i];
        vector<string> photos = vector<string>();
        getdir(new_path, photos);
        for (unsigned int photo = 0; photo < photos.size(); photo++) {
	   string photo_path = new_path + "/" + photos[photo];
	   cout << "[INFO] Reading photo " << photo_path << endl;
           picture = imread(photo_path);
           cvtColor(picture, frame, CV_BGR2GRAY);
           vector<Rect> faces;
           classifier.detectMultiScale(frame, faces, 1.2, 5);

           for(size_t k = 0; k < faces.size(); k++) {
              Mat face = frame(faces[k]);
              Images.push_back(face);
              Labels.push_back(i);
              }
        }
  }
  labels.close();
  cout << "[INFO] Extracting embeddings" << endl;
  recognizer->train(Images, Labels);
  cout << "[INFO] Saving embeddings" << endl;
  recognizer->save("/home/pi/fun_security_sys/recognizer/embeddings.xml");

  return 0;
}
