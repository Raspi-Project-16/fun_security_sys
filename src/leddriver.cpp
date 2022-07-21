#include "leddriver.h"


/*----------------------------------------------------------------------
  |       LEDdriver::LEDdriver
  +---------------------------------------------------------------------*/

LEDdriver::LEDdriver(LEDsettings settings){
    // initialise the settings
    ledSettings = settings;
}

/*----------------------------------------------------------------------
  |       LEDdriver::~LEDdriver
  +---------------------------------------------------------------------*/

LEDdriver::~LEDdriver(){
    stop();

}

/*----------------------------------------------------------------------
  |       LEDdriver::start
  +---------------------------------------------------------------------*/

void LEDdriver::start(){
  if (nullptr != ledThread) {
                // already running
                return;
        }
  if(wiringPiSetup () < 0)
  {
    return;
  }
  // using pigpio library would give unexpected effects to the led strip, but not the wiringPi
  // gpioSetMode(ledSettings.led_GPIO, PI_OUTPUT);

  pinMode(ledSettings.led_GPIO, OUTPUT);
}

/*----------------------------------------------------------------------
  |       LEDdriver::stop
  +---------------------------------------------------------------------*/

void LEDdriver::stop(){
        if (nullptr != ledThread) {
                ledThread->join();
                delete ledThread;
                ledThread = nullptr;
    }
}

/*----------------------------------------------------------------------
  |       LEDdriver::registerCallback
  +---------------------------------------------------------------------*/

void LEDdriver::registerCallback(LEDcallback* cb) {
        ledCallback = cb;
}

/*----------------------------------------------------------------------
  |       LEDdriver::unRegisterCallback
  +---------------------------------------------------------------------*/

void LEDdriver::unRegisterCallback() {
    ledCallback = nullptr;
}

/*----------------------------------------------------------------------
  |       LEDdriver::run
  +---------------------------------------------------------------------*/

void LEDdriver::run(){

}

/*----------------------------------------------------------------------
  |       LEDdriver::callback
  +---------------------------------------------------------------------*/

void LEDdriver::callback(int signal){
    #ifdef DEBUG
    cout << signal << endl;
    #endif

    if(nullptr != ledCallback){

        #ifdef DEBUG
        cout << signal << endl;
        #endif
    // callback signal is from other devices
        ledCallback->hasSignal(this, signal);
  }
}


/*----------------------------------------------------------------------
  |       LEDdriver::ledSwitch
  +---------------------------------------------------------------------*/

void LEDdriver::ledSwitch(int signal){

  #ifdef DEBUG
    cout << "sound detected : " << signal << endl;
  #endif

  // if the signal is LED_ON and the led bulb is not on, turn it on
  if(signal==ledSettings.LED_ON && digitalRead(ledSettings.led_GPIO) != ledSettings.LED_ON){
    digitalWrite(ledSettings.led_GPIO, signal);
  }
  if(signal==ledSettings.LED_OFF && digitalRead(ledSettings.led_GPIO) == ledSettings.LED_ON){
    digitalWrite(ledSettings.led_GPIO, signal);
  }
}
