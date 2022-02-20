#include <iostream>
#include <wiringPi.h>
using namespace std;

class soundModule{
public:
    soundModule(int gpio);
    bool detectSound();
    ~soundModule();
private:
    int gpio;
};