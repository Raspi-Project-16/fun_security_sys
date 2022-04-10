#include <cameraEventHandler.h>


CameraEventHandler::CameraEventHandler()
{

}

CameraEventHandler::~CameraEventHandler()
{
    Camera.release();
    time ( &timer_end );
    secondsElapsed = difftime ( timer_end,timer_begin );
    cout << "FPS:" << numframes / secondsElapsed << endl;
}

void CameraEventHandler::start(){
    des->subscribe(EEVENTID_CAMERA_REQ, this);
    cameraEv = new CameraEvent();
    cout << cameraEv << endl;
    Camera.set(CAP_PROP_FRAME_WIDTH, 320);
    Camera.set(CAP_PROP_FRAME_HEIGHT, 240);
    ifstream infile("/home/pi/raspi_project_16/recognizer/labels.txt");
    int a;
    string b;
    while (infile >> a >> b){
        labels[a] = b;
    }
    if (!Camera.open()) {cerr<<"Error opening the camera"<<endl;}
    classifier.load("/home/pi/raspi_project_16/cascades/haarcascade_frontalface_alt.xml");
    recognizer->read("/home/pi/raspi_project_16/recognizer/embeddings.xml");
    namedWindow("edges", 1);
    time (&timer_begin);
    des->publish(cameraEv);
}


void CameraEventHandler::stop(){
    des->unsubscribe(EEVENTID_CAMERA_REQ, this);
}

void CameraEventHandler::freeInstance(){
    if(cameraEv != NULL){
        delete cameraEv;
        cameraEv = NULL;
    }
}

bool CameraEventHandler::handle(const CEvent* ev){
   if(EEVENTID_CAMERA_REQ == ev->getEid()){
    CameraEvent* req = (CameraEvent*) ev;
    Camera.grab();
    Camera.retrieve(frame);
    cvtColor(frame, windowFrame, CV_BGR2GRAY);
    classifier.detectMultiScale(frame, faces, 1.2, 5);
    for(size_t i = 0; i < faces.size(); i++){
        rectangle(frame, faces[i], Scalar(0, 255, 0));
        Mat face = windowFrame(faces[i]);
        double confidence = 0.0;
        int predicted = recognizer->predict(face);
        recognizer->predict(face, predicted, confidence);
        if(labels.find(predicted) == labels.end() || confidence < 25){
            putText(frame, "Unknown", Point(faces[i].x ,faces[i].y - 5), FONT_HERSHEY_DUPLEX, 1, Scalar(0,255,0), 1);
            ws2811Ev->setMsg(WARNING_COLOR);
        }else{
            putText(frame, labels[predicted], Point(faces[i].x ,faces[i].y - 5), FONT_HERSHEY_DUPLEX, 1, Scalar(0,255,0), 1);
            ws2811Ev->setMsg(ACCESSING_COLOR);
        }
        //cout << "ID: " << predicted << " | Confidence: " << confidence << endl;
    }
    imshow("edges", frame);
    numframes++;
    waitKey(30);
    //cameraEv = new CameraEvent();
    // cout << cameraEv << endl;
    des->publish(cameraEv);
    }
   return true;
}
