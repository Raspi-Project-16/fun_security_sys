#include "ledModule.h"
#include "timeModule.h"
#include <thread>
using namespace std;
ledModule::ledModule(int gpio, int width, int freq)
{
     
    
}

void ledModule::matrix_render(){

    int x,y;

    for (x = 0; x < width; x++)
    {
        for (y = 0; y < height; y++)
        {
            ledstring.channel[0].leds[(y * width) + x] = matrix[y * width + x];
        }
    }
}

void ledModule::matrix_raise(){
    int x, y;

    for (y = 0; y < (height - 1); y++)
    {
        for (x = 0; x < width; x++)
        {
            // This is for the 8x8 Pimoroni Unicorn-HAT where the LEDS in subsequent
            // rows are arranged in opposite directions
            matrix[y * width + x] = matrix[(y + 1)*width + width - x - 1];
        }
    }
    
}

void ledModule::matrix_clear(){
    int x, y;

    for (y = 0; y < (height ); y++)
    {
        for (x = 0; x < width; x++)
        {
            matrix[y * width + x] = 0;
        }
    }

}

void ledModule::matrix_bottom()
{
    int i;

    for (i = 0; i < (int)(ARRAY_SIZE(dotspos)); i++)
    {
        {
        dotspos[i]++;
        if (dotspos[i] > (width - 1))
        {
            dotspos[i] = 0;
        }

        if (ledstring.channel[0].strip_type == SK6812_STRIP_RGBW) {
            matrix[dotspos[i] + (height - 1) * width] = dotcolors_rgbw[i];
        } else {
            matrix[dotspos[i] + (height - 1) * width] = dotcolors[i];
        }
    }
    }
}

void ledModule::run(){
    ws2811_return_t ret;
    matrix = (ws2811_led_t *)malloc(sizeof(ws2811_led_t) * width * height);
    
    if ((ret = ws2811_init(&ledstring)) != WS2811_SUCCESS)
    {
        cout << stderr << "ws2811_init failed:" << ws2811_get_return_t_str(ret) << endl;
    }
    while (1)
    {

        matrix_raise();
        matrix_bottom();
        matrix_render();
        cout << "1" << endl;

        if ((ret = ws2811_render(&ledstring)) != WS2811_SUCCESS)
        {
            fprintf(stderr, "ws2811_render failed: %s\n", ws2811_get_return_t_str(ret));
            break;
        }
        usleep(1000000 / 15);

    }
}

void ledModule::shutdown(){
    matrix_clear();
	matrix_render();
	ws2811_render(&ledstring);
}

ledModule::~ledModule()
{
    ws2811_fini(&ledstring);
}