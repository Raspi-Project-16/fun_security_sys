#include "facetraining.h"

FaceTraining::FaceTraining()
{
    getDir(fileName, dirs);
    classifier.load("/home/pi/fss_T16/cascades/haarcascade_frontalface_default.xml");
    labels.open("/home/pi/fss_T16/recognizer/labels.txt");
    cout << "[LOG_INFO] Loading classifier" << endl;
}

FaceTraining::~FaceTraining(){

}

int FaceTraining::getDir(string dir, vector<string> &files){
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

void FaceTraining::train(){

    for(unsigned int i = 0; i < dirs.size(); i++){
        labels << i << " " << dirs[i] << endl;
        string new_path = fileName + "/" + dirs[i];
        vector<string> photos = vector<string>();
        getDir(new_path, photos);
        for (unsigned int photo = 0; photo < photos.size(); photo++){
           string photo_path = new_path + "/" + photos[photo];
           cout << "[LOG_INFO] Reading photo " << photo_path << endl;
           picture = imread(photo_path);
           cvtColor(picture, frame, CV_BGR2GRAY);
           vector<Rect> faces;
           classifier.detectMultiScale(frame, faces, 1.2, 5);

           for(size_t k = 0; k < faces.size(); k++){
                Mat face = frame(faces[k]);
                Images.push_back(face);
                Labels.push_back(i);
           }
        }
     }
      labels.close();
      cout << "[LOG_INFO] Extracting embeddings" << endl;
      recognizer->train(Images, Labels);
      cout << "[LOG_INFO] Saving embeddings" << endl;
      recognizer->save("/home/pi/fss_T16/recognizer/embeddings.xml");
}
