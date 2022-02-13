#include <iostream>
#include <wiringPi.h>
using namespace std;

bool readPin(int gpio){
      if(digitalRead(gpio) == LOW){
         cout << "gpio 28 Input 1" << endl;
         return true;
      }
      else{
         cout << "gpio 28 Input 0" << endl;
         return false;
      }
}

void lightUp(int gpio){
      digitalWrite(gpio, HIGH);
      cout << "gpio 29 Ouput 1" << endl;
}

void lightOff(int gpio){
      digitalWrite(gpio, LOW);
      cout << "gpio 29 Ouput 0" << endl;
}

int main(int argc, const char* argv[]){

   int GPIO_29 = 29;
   int GPIO_28 = 28;
   wiringPiSetup();
   pinMode(GPIO_28, INPUT);
   pinMode(GPIO_29, OUTPUT);
   digitalWrite(GPIO_28, LOW);
   digitalWrite(GPIO_29, LOW);

   while(true){
      bool flag = readPin(GPIO_28);
      if(flag == true){
         lightUp(GPIO_29);
      }else{
         lightOff(GPIO_29);
      }
   }
}
