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

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define INVALID_U32  0xFFFF
/* Global type defintions */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;     /* int == long */
typedef signed char    i8;
typedef signed short   i16;
typedef signed int     i32;     /* int == long */
typedef float          r32;
typedef double         r64;
typedef long double    r128;

typedef unsigned char  BOOL;

typedef u32            TBoolean;
typedef i32            TDevid;

#ifdef __DCC__ /* For diab compiler environment */

typedef unsigned long long u64;
typedef signed long long i64;

#endif

#ifdef __GNUC__ /* For GNU C compiler environment */
#if (0 < __GNUC__)

typedef unsigned long long u64;
typedef signed long long i64;

#endif
#endif



#ifdef __MSC__ /* For microsoft compiler environment */

typedef unsigned __int64 u64;
typedef __int64 i64;

#endif



#ifdef __TCC__ /* For texas compiler environment */

typedef unsigned long long u64;
typedef signed long long i64;

#endif



#ifdef __cplusplus
}
#endif /* __cplusplus */

#define ARRAY_SIZE(arr)       (sizeof(arr) / sizeof(arr[0]))
// defaults for cmdline options
#define TARGET_FREQ             WS2811_TARGET_FREQ
#define GPIO_PIN                21
#define DMA                     10
#define STRIP_TYPE              WS2811_STRIP_GBR		// WS2812/SK6812RGB integrated chip+leds
//#define STRIP_TYPE            SK6812_STRIP_RGBW		// SK6812RGBW (NOT SK6812RGB)

#define WIDTH                   150
#define HEIGHT                  1
#define LED_COUNT               (WIDTH * HEIGHT)
#define WARNING_COLOR           "red"
#define ACCESSING_COLOR         "green"
#define RAINBOW_COLOR           "rainbow"

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

