#include <cameraEventHandler.h>


/*----------------------------------------------------------------------
  |       CameraEventCallback::CameraEventCallback
  +---------------------------------------------------------------------*/

CameraEventCallback::CameraEventCallback()
{

}

/*----------------------------------------------------------------------
  |       CameraEventCallback::~CameraEventCallback
  +---------------------------------------------------------------------*/
CameraEventCallback::~CameraEventCallback()
{
    Camera.release();
    time ( &timer_end );
    secondsElapsed = difftime ( timer_end,timer_begin );
    cout << "FPS:" << numframes / secondsElapsed << endl;
}

/*----------------------------------------------------------------------
  |       CameraEventCallback::start
  +---------------------------------------------------------------------*/
void CameraEventCallback::start(){
    //initialise the camera callback
    des->subscribe(EEVENTID_CAMERA_REQ, this);
    //start a camera event
    cameraEv = new CameraEvent();
    //set the camera display frame
    Camera.set(CAP_PROP_FRAME_WIDTH, 320);
    Camera.set(CAP_PROP_FRAME_HEIGHT, 240);
    //load the objects of face recognition
    ifstream infile("/home/pi/raspi_project_16/recognizer/labels.txt");
    int a;
    string b;
    //store the objects in an array
    while (infile >> a >> b){
        labels[a] = b;
    }
    //check the camera
    if (!Camera.open()) {cerr<<"Error opening the camera"<<endl;}
    //load the classifier
    classifier.load("/home/pi/raspi_project_16/cascades/haarcascade_frontalface_alt.xml");
    recognizer->read("/home/pi/raspi_project_16/recognizer/embeddings.xml");
    namedWindow("edges", 1);
    time (&timer_begin);
    //register the event
    des->publish(cameraEv);
}

/*----------------------------------------------------------------------
  |       CameraEventCallback::stop
  +---------------------------------------------------------------------*/
void CameraEventCallback::stop(){
    //unregister the callback
    des->unsubscribe(EEVENTID_CAMERA_REQ, this);
}

/*----------------------------------------------------------------------
  |       CameraEventCallback::freeInstance
  +---------------------------------------------------------------------*/
void CameraEventCallback::freeInstance(){
    if(cameraEv != NULL){
        delete cameraEv;
        cameraEv = NULL;
    }
}

/*----------------------------------------------------------------------
  |       CameraEventCallback::callback
  +---------------------------------------------------------------------*/
bool CameraEventCallback::callback(const CEvent* ev){
   if(EEVENTID_CAMERA_REQ == ev->getEid()){
    CameraEvent* req = (CameraEvent*) ev;
    //display the camera
    Camera.grab();
    Camera.retrieve(frame);
    //set parameters for the camera
    cvtColor(frame, windowFrame, CV_BGR2GRAY);
    //face recogition
    classifier.detectMultiScale(frame, faces, 1.2, 5);
    bool flag = false;
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
            ws2811Ev->setMsg(WARNING_COLOR);
            flag = true;
        }else{
            //otherwise display the name of the objects
            putText(frame, labels[predicted], Point(faces[i].x ,faces[i].y - 5), FONT_HERSHEY_DUPLEX, 1, Scalar(0,255,0), 1);
            ws2811Ev->setMsg(ACCESSING_COLOR);
            flag = true;
        }
        //display the info
        cout << "ID: " << predicted << " | Confidence: " << confidence << endl;
    }
    imshow("edges", frame);
    numframes++;
    waitKey(30);
    //if no faces are detected
    if(flag == false){
        ws2811Ev->setMsg(RAINBOW_COLOR);
    }
    des->publish(req);
    }
   return true;
}
