#include <iostream>
#include <wiringPi.h>
using namespace std;

class lightModule{
public:
    lightModule(int gpio);
    void lightUp();
    void lightOff();
    ~lightModule();
private:
    int gpio;
};