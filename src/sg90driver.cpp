#include "sg90driver.h"

/*----------------------------------------------------------------------
  |       SG90Driver::SG90Driver
  +---------------------------------------------------------------------*/

SG90Driver::SG90Driver(SG90settings settings){
    // initialise the settings
    sg90settings = settings;
}

/*----------------------------------------------------------------------
  |       SG90Driver::~SG90Driver
  +---------------------------------------------------------------------*/

SG90Driver::~SG90Driver(){
    stop();
}

/*----------------------------------------------------------------------
  |       SG90Driver::start
  +---------------------------------------------------------------------*/

void SG90Driver::start(){
  if (nullptr != sg90Thread) {
                // already running
                return;
        }
  if(-1 == wiringPiSetup())
  {
    return;
  }
  //pigpio library doesn't work properly, thus I use wiringPi in this class.
  //gpioSetPWMfrequency(sg90settings.sg90_GPIO, sg90settings.sg90_FREQ);
  //gpioSetPWMrange(sg90settings.sg90_GPIO, sg90settings.sg90_RANGE);
  pinMode(sg90settings.sg90_GPIO, PWM_OUTPUT);
  softPwmCreate(sg90settings.sg90_GPIO, 0, sg90settings.sg90_RANGE);
  sg90Thread = new thread(execute,this);
}

/*----------------------------------------------------------------------
  |       SG90Driver::stop
  +---------------------------------------------------------------------*/

void SG90Driver::stop(){
  running = 0;
        if (nullptr != sg90Thread) {
                sg90Thread->join();
                delete sg90Thread;
                sg90Thread = nullptr;
    }
}

/*----------------------------------------------------------------------
  |       SG90Driver::registerCallback
  +---------------------------------------------------------------------*/

void SG90Driver::registerCallback(SG90callback* cb) {
        sg90callback = cb;
}

/*----------------------------------------------------------------------
  |       SG90Driver::unRegisterCallback
  +---------------------------------------------------------------------*/

void SG90Driver::unRegisterCallback() {
        sg90callback = nullptr;
}

/*----------------------------------------------------------------------
  |       SG90Driver::run
  +---------------------------------------------------------------------*/

void SG90Driver::run(){
  while(running){
    softPwmWrite(sg90settings.sg90_GPIO, sg90settings.degree);
  }
}

/*----------------------------------------------------------------------
  |       SG90Driver::callback
  +---------------------------------------------------------------------*/

void SG90Driver::callback(int degree){
    #ifdef DEBUG
      cout << degree << endl;
    #endif
    if(nullptr != sg90callback){
        #ifdef DEBUG
        cout << degree << endl;
        #endif
        sg90callback->hasSignal(this, degree);
    }
}


/*----------------------------------------------------------------------
  |       SG90Driver::setDegree
  +---------------------------------------------------------------------*/

void SG90Driver::setDegree(int degree){
    switch(degree){

    case 0:
        this->sg90settings.degree = SG90_D0;
        break;
    case 45:
        this->sg90settings.degree = SG90_D45;
        break;
    case 90:
        this->sg90settings.degree = SG90_D90;
        break;
    case 135:
        this->sg90settings.degree = SG90_D135;
        break;
    case 180:
        this->sg90settings.degree = SG90_D180;
    default:
        this->sg90settings.degree = SG90_D0;
        break;
    }

}
