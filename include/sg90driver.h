#ifndef SG90DRIVER_H
#define SG90DRIVER_H



#include <pigpio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <thread>
#include <iostream>

using namespace std;

class SG90Driver;

enum Degree
{
  SG90_D0 = 5,
  SG90_D45 = 10,
  SG90_D90 = 15,
  SG90_D135 = 20,
  SG90_D180 = 25
};

/*----------------------------------------------------------------------
  |       SG90settings
  +---------------------------------------------------------------------*/

struct SG90settings
{
  Degree degree = SG90_D0;
  int sg90_GPIO = 6;
  int sg90_RANGE = 200;
};

/*----------------------------------------------------------------------
  |       SG90callback
  +---------------------------------------------------------------------*/
class SG90callback
{
public:
  virtual void hasSignal(SG90Driver* sg90Driver, int degree) = 0;
};

/*----------------------------------------------------------------------
  |       Sg90Driver
  +---------------------------------------------------------------------*/

class SG90Driver
{

  friend class RPISignalCallback;
  friend class FssApp;

public:
  SG90Driver(SG90settings settings);
  ~SG90Driver();
  void start();
  void stop();
  void registerCallback(SG90callback *cb);
  void unRegisterCallback();
  void setDegree(int degree);

private:
  thread* sg90Thread = nullptr;
  SG90callback* sg90callback = nullptr;
  SG90settings sg90settings;
  int running = 1;

  void run();
  void callback(int degree);
        static void execute(SG90Driver* sg90Driver){
                sg90Driver->run();
        }

};

#endif // SG90DRIVER_H
