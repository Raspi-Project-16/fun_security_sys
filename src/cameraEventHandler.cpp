#include <cameraEventHandler.h>


/*----------------------------------------------------------------------
  |       RPICameraDriver::RPICameraDriver
  +---------------------------------------------------------------------*/

RPICameraDriver::RPICameraDriver(RPICameraSettings settings)
{
    rpiCamerasettings = settings;
}

/*----------------------------------------------------------------------
  |       RPICameraDriver::~RPICameraDriver
  +---------------------------------------------------------------------*/
RPICameraDriver::~RPICameraDriver()
{
    stop();
}

/*----------------------------------------------------------------------
  |       RPICameraDriver::registerCallback
  +---------------------------------------------------------------------*/

void RPICameraDriver::registerCallback(RPICameraCallback* cb) {
	rpiCameraCallback = cb;
}

/*----------------------------------------------------------------------
  |       RPICameraDriver::unRegisterCallback
  +---------------------------------------------------------------------*/

void RPICameraDriver::unRegisterCallback() {
	rpiCameraCallback = nullptr;
}

/*----------------------------------------------------------------------
  |       RPICameraDriver::start
  +---------------------------------------------------------------------*/
void RPICameraDriver::start(){

    if (nullptr != rpiCameraThread) {
		  // already running
		  return;
	  }
    //set the camera display frame
<<<<<<< HEAD
    Camera.set(CAP_PROP_FRAME_WIDTH, 640);
    Camera.set(CAP_PROP_FRAME_HEIGHT, 480);
=======
    Camera.set(CAP_PROP_FRAME_WIDTH, 320);
    Camera.set(CAP_PROP_FRAME_HEIGHT, 240);
>>>>>>> 0f99fa498056d66c1598a3567428c9a14eeb6f7d
    //load the objects of face recognition
    ifstream infile(rpiCamerasettings.faceLabelPath);
    int a;
    string b;
    //store the objects in an array
    while (infile >> a >> b){
        labels[a] = b;
    }
    //check the camera
    if (!Camera.open()) {cerr<<"Error opening the camera"<<endl;}
    //load the classifier
    classifier.load(rpiCamerasettings.classiferPath);
    recognizer->read(rpiCamerasettings.recognizerPath);
    namedWindow("window", 1);
    rpiCameraThread = new thread(execute,this);
}

/*----------------------------------------------------------------------
  |       RPICameraDriver::stop
  +---------------------------------------------------------------------*/
void RPICameraDriver::stop(){
    running = 0;
	  if (nullptr != rpiCameraThread) {
      rpiCameraThread->join();
      delete rpiCameraThread;
		  rpiCameraThread = nullptr;
    }
}

/*----------------------------------------------------------------------
  |       RPICameraDriver::callback
  +---------------------------------------------------------------------*/
void RPICameraDriver::run(){
    
    while(running){
    int isRecgnized = NO_SAMPLES;
      //display the camera
    Camera.grab();
    Camera.retrieve(frame);
    //set parameters for the camera
    cvtColor(frame, windowFrame, COLOR_BGR2GRAY);
    //face recogition
    classifier.detectMultiScale(frame, faces, 1.2, 5);
    
    for(size_t i = 0; i < faces.size(); i++){
        //set the detection frame of face recogition
        rectangle(frame, faces[i], Scalar(0, 255, 0));
        Mat face = windowFrame(faces[i]);
        double confidence = 0.0;
        //predict the objects
        int predicted = recognizer->predict(face);
        recognizer->predict(face, predicted, confidence);
        //if the similarity is smaller than 25
        if(labels.find(predicted) == labels.end() || confidence < 25){
            //display Unknown objects
            putText(frame, "Unknown", Point(faces[i].x ,faces[i].y - 5), FONT_HERSHEY_DUPLEX, 1, Scalar(0,0,255), 1);
            isRecgnized = FAILED;
        }else{
            //otherwise display the name of the objects
            putText(frame, labels[predicted], Point(faces[i].x ,faces[i].y - 5), FONT_HERSHEY_DUPLEX, 1, Scalar(0,255,0), 1);
            isRecgnized = SUCCEED;
        }
        //display the info
        cout << "ID: " << predicted << " | Confidence: " << confidence << endl;
    }
    imshow("window", frame);
    waitKey(30);

    if(nullptr != rpiCameraCallback){
      rpiCameraCallback->hasSignal(isRecgnized);
    }

    }
    Camera.release();
    destroyAllWindows();
}
