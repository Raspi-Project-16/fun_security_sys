#ifndef WS2811_IEVENT_HANDLER_H_
#define WS2811_IEVENT_HANDLER_H_

#include <stdio.h>
#include <iostream>
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
#include <thread> 
#include <pigpio.h>

using namespace std;

#define ARRAY_SIZE(arr)       (sizeof(arr) / sizeof(arr[0]))
#define TARGET_FREQ             WS2811_TARGET_FREQ
#define STRIP_TYPE              WS2811_STRIP_GBR

class WS2811Driver;
// LED strip color
enum Color {
    RED,
    GREEN,
    RAINBOW
};

struct WS2811settings{

    Color color = RAINBOW;

    int width = 150;
    int height = 1;

    int ws2811_GPIO = 21; //It's better to use 21
    int ws2811_DMA = 10;
    int led_count = width * height;

    ws2811_t ledstring =
    {
        .freq = TARGET_FREQ,
        .dmanum = ws2811_DMA,
        .channel =
        {
            [0] =
            {
                .gpionum = ws2811_GPIO,
                .invert = 0,
                .count = led_count,
                .strip_type = STRIP_TYPE,
                .brightness = 255,
            },
            [1] =
            {
                .gpionum = 0,
                .invert = 0,
                .count = 0,
                .brightness = 0,
            },
        },
    };

    int color_spots[24] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
    ws2811_led_t rainbow_spots[24] =
    {
        0x00200000,  // blue
        0x00200000,  // blue
        0x00200000,  // blue
        0x00202000,  // lightblue
        0x00202000,  // lightblue
        0x00202000,  // lightblue
        0x00002000,  // green
        0x00002000,  // green
        0x00002000,  // green
        0x00002020,  // yellow
        0x00002020,  // yellow
        0x00002020,  // yellow
        0x00200010,  // pink
        0x00200010,  // pink
        0x00200010,  // pink
        0x00100010,  // purple
        0x00100010,  // purple
        0x00100010,  // purple
        0x00000120,  // orange
        0x00000120,  // orange
        0x00000120,  // orange
        0x00000020,  // red
        0x00000020,  // red
        0x00000020,  // red
    };

    ws2811_led_t red_spots[24] =
    {

        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
        0x00211100,  // red
    };

    ws2811_led_t green_spots[24] =
    {
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
        0x00100010,  // green
    };

};
/*----------------------------------------------------------------------
  |       WS2811callback
  +---------------------------------------------------------------------*/
class WS2811callback{

public:
    virtual void hasSignal(WS2811Driver * ws2811Driver, Color color) = 0;
};

/*----------------------------------------------------------------------
  |       WS2811Driver
  +---------------------------------------------------------------------*/

class WS2811Driver{

    friend class RPISignalCallback;

public:
    WS2811Driver(WS2811settings settings);
    ~WS2811Driver();
    void start();
    void stop();
    void registerCallback(WS2811callback* cb);
    void unRegisterCallback();
    void matrix_render();
    void matrix_clear();
    void matrix_bottom();
    void clear_exit();
    void shutdown();
    void setColor(Color color);
    
private:
    thread* ws2811Thread = nullptr;
    WS2811callback* ws2811callback = nullptr;
    WS2811settings ws2811settings;
    ws2811_led_t *matrix = nullptr;
    int running = 1;

    void run();
    void callback(Color color);
	static void execute(WS2811Driver* ws2811Driver){
		ws2811Driver->run();
	}
    };


#endif
