#ifndef LED_IEVENT_DRIVER_H_
#define LED_IEVENT_DRIVER_H_

#include <iostream>
#include <pigpio.h>
#include <thread>
#include <wiringPi.h>

using namespace std;

class LEDdriver;
/*----------------------------------------------------------------------
  |       LEDsettings
  +---------------------------------------------------------------------*/

struct LEDsettings
{
  enum Signal{
    LED_OFF = 0,
    LED_ON = 1,
  };
  enum Level{
    RISING = 1,
    FALLING = 0,
    EITHER = 2
  };

  Signal signal = LED_OFF;

  int led_GPIO = 27;
};

/*----------------------------------------------------------------------
  |       LEDcallback
  +---------------------------------------------------------------------*/
class LEDcallback
{
public:
  virtual void hasSignal(LEDdriver* ledDriver, int level) = 0;
};

/*----------------------------------------------------------------------
  |       LEDdriver
  +---------------------------------------------------------------------*/

class LEDdriver
{

friend class SSSignalCallback;

public:
  LEDdriver(LEDsettings settings);
  ~LEDdriver();
  void start();
  void stop();
  void registerCallback(LEDcallback *cb);
  void unRegisterCallback();
  void ledSwitch(int level);
  
  
private:
  thread* ledThread = nullptr;
  LEDcallback* ledCallback = nullptr;
  LEDsettings ledSettings;
  void run();
  void callback(int signal);
	static void execute(LEDdriver* ledDriver){
		ledDriver->run();
	}

};

#endif
