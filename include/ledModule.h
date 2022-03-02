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
#include <unistd.h>

using namespace std;  

#define ARRAY_SIZE(arr)       (sizeof(arr) / sizeof(arr[0]))
// defaults for cmdline options
#define TARGET_FREQ             WS2811_TARGET_FREQ
#define GPIO_PIN                21
#define DMA                     10
//#define STRIP_TYPE            WS2811_STRIP_RGB		// WS2812/SK6812RGB integrated chip+leds
#define STRIP_TYPE              WS2811_STRIP_GBR		// WS2812/SK6812RGB integrated chip+leds
//#define STRIP_TYPE            SK6812_STRIP_RGBW		// SK6812RGBW (NOT SK6812RGB)

#define WIDTH                   150
#define HEIGHT                  1
#define LED_COUNT               (WIDTH * HEIGHT)

class ledModule
{
private:
int gpio = GPIO_PIN ;
int width = WIDTH;
int height = HEIGHT;
int led_count = LED_COUNT;
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
    /* data */
public:
    void matrix_render();
    void matrix_raise();
    void matrix_clear();
    void matrix_bottom();
    void clear_exit();
    void run();
    void shutdown();
    ledModule(int gpio, int width, int freq);
    ~ledModule();
};
