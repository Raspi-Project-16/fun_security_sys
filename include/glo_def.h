#ifndef _GLO_DEF_H
#define _GLO_DEF_H

#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string>
#include "ws2811.h"
#include "gpio.h"
#include <string>
#include "clk.h"
#include "pwm.h"
#include "dma.h"
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdarg.h>



#define ARRAY_SIZE(arr)       (sizeof(arr) / sizeof(arr[0]))
// defaults for cmdline options
#define TARGET_FREQ             WS2811_TARGET_FREQ
#define GPIO_PIN                21
#define DMA                     10
#define STRIP_TYPE              WS2811_STRIP_GBR		// WS2812/SK6812RGB integrated chip+leds
//#define STRIP_TYPE            SK6812_STRIP_RGBW		// SK6812RGBW (NOT SK6812RGB)


#define WIDTH                   150                     // the color matrix
#define HEIGHT                  1
#define LED_COUNT               (WIDTH * HEIGHT)
#define WARNING_COLOR           "red"
#define ACCESSING_COLOR         "green"
#define RAINBOW_COLOR           "rainbow "
#define SOUND_PIN               28
#define LED_PIN                 27
#define PWM_PIN                 1

template <class Type> 
Type stringToNum(const std::string& str){ 
    std::istringstream iss(str); 
    Type num; 
    iss >> num; 
    return num;     
}

template<typename T> 
std::string NumtoString(const T& t){
    std::ostringstream oss;  
    oss<<t;             
    return oss.str();  
}



#endif /* _GLO_DEF_H */

