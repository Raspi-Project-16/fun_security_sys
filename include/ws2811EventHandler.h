#ifndef WS2811_IEVENT_HANDLER_H_
#define WS2811_IEVENT_HANDLER_H_


#include "iEventHandler.h"
#include "dispatchEventService.h"
#include "events_def.h"

class Ws2811EventHandler: public EventHandler{
public:
    Ws2811EventHandler();
    ~Ws2811EventHandler();
    void start();
    void stop();
    bool handle(const CEvent* ev);
    void matrix_render();
    void matrix_raise();
    void matrix_clear();
    void matrix_bottom();
    void clear_exit();
    void shutdown();
    
private:
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
int dotspos[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
ws2811_led_t dotcolors[8] = {
    0x00200000,  // red
    0x00201000,  // orange
    0x00202000,  // yellow
    0x00002000,  // green
    0x00002020,  // lightblue
    0x00000020,  // blue
    0x00100010,  // purple
    0x00200010,  // pink
};
ws2811_led_t dotcolors_rgbw[8] = {
    0x00200000,  // red
    0x10200000,  // red + W
    0x00002000,  // green
    0x10002000,  // green + W
    0x00000020,  // blue
    0x10000020,  // blue + W
    0x00101010,  // white
    0x10101010,  // white + W
};

};


#endif