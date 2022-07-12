#include "soundsensordriver.h"

/*----------------------------------------------------------------------
  |       SoundSensorDriver::SoundSensorDriver
  +---------------------------------------------------------------------*/

SoundSensorDriver::SoundSensorDriver(SoundSensorSettings settings){
    // initialise the settings
    ssSettings = settings;
}

/*----------------------------------------------------------------------
  |       SoundSensorDriver::~SoundSensorDriver
  +---------------------------------------------------------------------*/

SoundSensorDriver::~SoundSensorDriver(){
    stop();

}

/*----------------------------------------------------------------------
  |       SoundSensorDriver::start
  +---------------------------------------------------------------------*/

void SoundSensorDriver::start(){
  if (nullptr != ssThread) {
                // already running
                return;
        }
  if(wiringPiSetup () < 0)
  {
    return;
  }
  // gpio library doesn't work properly in my case, the LED strip wouldn not display correctly if it is used.

  // gpioSetMode(ssSettings.led_GPIO, PI_OUTPUT);
  // gpioSetMode(ssSettings.led_GPIO, PI_INPUT);
  //gpioSetISRFuncEx(ssSettings.ss_GPIO, RISING_EDGE, ssSettings.ISR_TIMEOUT, gpioISR, (void*)this);
  // gpioSetISRFuncEx(ssSettings.ss_GPIO, FALLING_EDGE, 1, gpioISR, (void*)this);
  pinMode(ssSettings.ss_GPIO, INPUT);
  ssThread = new thread(execute,this);
}

/*----------------------------------------------------------------------
  |       SoundSensorDriver::stop
  +---------------------------------------------------------------------*/

void SoundSensorDriver::stop(){
  running = 0;
        if (nullptr != ssThread) {
                ssThread->join();
                delete ssThread;
                ssThread = nullptr;
    }
}

/*----------------------------------------------------------------------
  |       SoundSensorDriver::registerCallback
  +---------------------------------------------------------------------*/

void SoundSensorDriver::registerCallback(SoundSensorCallback* cb) {
        ssCallback = cb;
}

/*----------------------------------------------------------------------
  |       SoundSensorDriver::unRegisterCallback
  +---------------------------------------------------------------------*/

void SoundSensorDriver::unRegisterCallback() {
        ssCallback = nullptr;
}

/*----------------------------------------------------------------------
  |       SoundSensorDriver::run
  +---------------------------------------------------------------------*/

void SoundSensorDriver::run(){
  bool flag = false;
  int signal = 0;
  time_t begin, end;
  while(running){
    signal = digitalRead(ssSettings.ss_GPIO);
    //cout << "sound detected : " << signal << endl;
    if(signal == ssSettings.RISING && flag == false){
      flag = true;
      begin = clock();
    }
    if(flag){
      end = clock();
      //cout << end - begin << endl;
      if(double(end - begin) / CLOCKS_PER_SEC * 1000 > ssSettings.INTERVAL)flag=false;
      signal = ssSettings.RISING;
    }else{
      signal = ssSettings.FALLING;
    }

    if(nullptr != ssCallback){
        ssCallback->hasSignal(signal);
    }
  }
}
