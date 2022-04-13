#ifndef WS2811_IEVENT_HANDLER_H_
#define WS2811_IEVENT_HANDLER_H_


#include "iEventHandler.h"
#include "dispatchEventService.h"
#include "events_def.h"

class Ws2811EventCallback: public EventCallback{
public:
    Ws2811EventCallback();
    ~Ws2811EventCallback();
    void start();
    void stop();
    bool callback(const CEvent* ev);
    void execute(string msg);
    void matrix_render();
    void matrix_clear();
    void matrix_bottom(string mode);
    void clear_exit();
    void shutdown();
    
private:
clock_t begin,end;
string previousMode;
u32 count;
ws2811_t ledstring =
{
    .freq = TARGET_FREQ,
    .dmanum = DMA,
    .channel =
    {
        [0] =
        {
            .gpionum = GPIO_PIN,
            .invert = 0,
            .count = LED_COUNT,
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
ws2811_led_t *matrix;
int dotspos[24] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
ws2811_led_t dotcolors[24] =
{
    0x00200000,  // red
    0x00200000,  // red
    0x00200000,  // red
    0x00201000,  // orange
    0x00201000,  // orange
    0x00201000,  // orange
    0x00202000,  // yellow
    0x00202000,  // yellow
    0x00202000,  // yellow
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002020,  // lightblue
    0x00002020,  // lightblue
    0x00002020,  // lightblue
    0x00000020,  // blue
    0x00000020,  // blue
    0x00000020,  // blue
    0x00100010,  // purple
    0x00100010,  // purple
    0x00100010,  // purple
    0x00200010,  // pink
    0x00200010,  // pink
    0x00200010,  // pink
};

ws2811_led_t dotcolors_red[24] =
{
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
    0x00000020,  // red
};

ws2811_led_t dotcolors_green[24] =
{
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
    0x00002000,  // green
};

};


#endif
