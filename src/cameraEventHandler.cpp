#include <cameraEventHandler.h>


CameraEventHandler::CameraEventHandler()
{

}

CameraEventHandler::~CameraEventHandler()
{

}

void CameraEventHandler::start(){
    des->subscribe(EEVENTID_CAMERA_REQ, this);
    //CameraEvent* cameraEv = new CameraEvent();
    cameraEv->init();
    des->publish(cameraEv);
}


void CameraEventHandler::stop(){
    des->unsubscribe(EEVENTID_CAMERA_REQ, this);
}


bool CameraEventHandler::handle(const CEvent* ev){
   if(EEVENTID_SOUND_REQ == ev->getEid()){
       CameraEvent* req = (CameraEvent*) ev;
       req->recognizeFaces(); 
    }
    return true;

}
