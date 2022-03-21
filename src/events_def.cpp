#include "events_def.h"


/**
 * @brief Construct a new Led Event:: Led Event object
 * 
 * @param gpio 
 */

LedEvent::LedEvent(u32 gpio, string msg){
    this->gpio_ = gpio;
    this->setEid(EEVENTID_LED_REQ);
    this->content_ = msg;
}

LedEvent::~LedEvent(){

}

void LedEvent::ledOn(){
    digitalWrite(this->gpio_, HIGH);
    //gpioWrite(this->gpio_, 1);
}

void LedEvent::ledOff(){
    digitalWrite(this->gpio_, LOW);
    //gpioWrite(this->gpio_, 1);
}


/**
 * @brief Construct a new Sound Event:: Sound Event object
 * 
 * @param gpio 
 */

SoundEvent::SoundEvent(u32 gpio, string msg){
    this->gpio_ = gpio;
    this->setEid(EEVENTID_SOUND_REQ);
    this->content_ = msg;
}

SoundEvent::~SoundEvent(){

}

bool SoundEvent::detectSound(){
    if(digitalRead(this->gpio_) == LOW){
        cout << "Sound detected!" << endl;
        return true;
    }else{
        cout << "Sound not detected!" << endl;
        return false;
    }
    //gpioWrite(this->gpio_, 1);
}

/**
 * @brief Construct a new Ws2811Event:: Ws 2811Event object
 * 
 */



Ws2811Event::Ws2811Event()
{
    this->setEid(EEVENTID_WS2811_REQ);

}



/**
 * @brief Construct a new CameraEvent:: Ws CameraEvent object
 * 
 */
CameraEvent::CameraEvent()
{
     this->setEid(EEVENTID_CAMERA_REQ);
}

void CameraEvent::init()
{
    
    Camera.set(CAP_PROP_FRAME_WIDTH, 320);
    Camera.set(CAP_PROP_FRAME_HEIGHT, 240);
    ifstream infile("./recognizer/labels.txt");
    int a;
    string b;
    while (infile >> a >> b){
    labels[a] = b;
  }
    if (!Camera.open()) {cerr<<"Error opening the camera"<<endl;}
    classifier.load("./cascades/lbpcascade_frontalface.xml");
    recognizer->read("./recognizer/embeddings.xml");
    namedWindow("edges", 1);
    time ( &timer_begin );
}

bool CameraEvent::recognizeFaces()
{
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
        return false;
      }else{
        putText(frame, labels[predicted], Point(faces[i].x ,faces[i].y - 5), FONT_HERSHEY_DUPLEX, 1, Scalar(0,255,0), 1);
        return true;
      }
      cout << "ID: " << predicted << " | Confidence: " << confidence << endl;
    }
    imshow("edges", frame);
    numframes++;
    return true;
}


CameraEvent::~CameraEvent()
{
  Camera.release();
  time ( &timer_end );
  secondsElapsed = difftime ( timer_end,timer_begin );
  cout << "FPS:" << numframes / secondsElapsed << endl;
}
