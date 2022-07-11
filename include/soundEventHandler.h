#ifndef SOUND_IEVENT_DRIVER_H_
#define SOUND_IEVENT_DRIVER_H_


#include <iostream>
#include <thread>
#include <pigpio.h>
#include <wiringPi.h>
#include <ctime>

using namespace std;

/*----------------------------------------------------------------------
  |       SoundSensorSettings
  +---------------------------------------------------------------------*/

struct SoundSensorSettings
{
  int ss_GPIO = 25;

  enum Level{
    RISING = 1,
    FALLING = 0
  };

  int INTERVAL = 20000;  //10ms
};

/*----------------------------------------------------------------------
  |       SoundSensorCallback
  +---------------------------------------------------------------------*/
  
class SoundSensorCallback
{
public:
  virtual void hasSignal(int level) = 0;
};

/*----------------------------------------------------------------------
  |       SoundSensorDriver
  +---------------------------------------------------------------------*/

class SoundSensorDriver
{
public:
  SoundSensorDriver(SoundSensorSettings settings);
  ~SoundSensorDriver();
  void start();
  void stop();
  void registerCallback(SoundSensorCallback *cb);
  void unRegisterCallback();

private:
  thread* ssThread = nullptr;
  SoundSensorCallback* ssCallback = nullptr;
  SoundSensorSettings ssSettings;
  int running = 1;

  void run();
	static void execute(SoundSensorDriver* ssDriver){
		ssDriver->run();
	}

  // gpio library doesn't work properly in this class
	//static void gpioISR(int gpio, int level, uint32_t tick, void* signal){
  //  ((SoundSensorDriver*)signal)->callback(level);
  //   cout << level << endl;
	// }

};

#endif
