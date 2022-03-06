#include "ws2811EventHandler.h"



Ws2811EventHandler::Ws2811EventHandler(){
    matrix = (ws2811_led_t *)malloc(sizeof(ws2811_led_t) * WIDTH * HEIGHT);
}

Ws2811EventHandler::~Ws2811EventHandler(){
    ws2811_fini(&ledstring);
}

void Ws2811EventHandler::start(){
    des->subscribe(EEVENTID_WS2811_REQ, this);
    Ws2811Event* ws2811Ev = new Ws2811Event();
    des->publish(ws2811Ev);
}


void Ws2811EventHandler::stop(){
    des->unsubscribe(EEVENTID_WS2811_REQ, this);
}

bool Ws2811EventHandler::handle(const CEvent* ev){
    if(EEVENTID_WS2811_REQ == ev->getEid()){
        Ws2811Event* req = (Ws2811Event*) ev;
        
        ws2811_return_t ret;
        if ((ret = ws2811_init(&ledstring)) != WS2811_SUCCESS)
        {
            cout << stderr << "ws2811_init failed:" << ws2811_get_return_t_str(ret) << endl;
        }
        matrix_raise();
        matrix_bottom();
        matrix_render();
        if ((ret = ws2811_render(&ledstring)) != WS2811_SUCCESS)
        {
            fprintf(stderr, "ws2811_render failed: %s\n", ws2811_get_return_t_str(ret));
            return false;
        }
        usleep(1000000 / 20);
        Ws2811Event* ws2811Ev = new Ws2811Event();
        des->publish(ws2811Ev);   
    }else{
        
    }

    return true;
}

void Ws2811EventHandler::matrix_render(){

    int x,y;

    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            ledstring.channel[0].leds[(y * WIDTH) + x] = matrix[y * WIDTH + x];
        }
    }
}

void Ws2811EventHandler::matrix_raise(){
    int x, y;

    for (y = 0; y < (HEIGHT - 1); y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            // This is for the 8x8 Pimoroni Unicorn-HAT where the LEDS in subsequent
            // rows are arranged in opposite directions
            matrix[y * WIDTH + x] = matrix[(y + 1)*WIDTH + WIDTH - x - 1];
        }
    }
    
}

void Ws2811EventHandler::matrix_clear(){
    int x, y;

    for (y = 0; y < (HEIGHT ); y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            matrix[y * WIDTH + x] = 0;
        }
    }

}

void Ws2811EventHandler::matrix_bottom()
{
    int i;

    for (i = 0; i < (int)(ARRAY_SIZE(dotspos)); i++)
    {
        {
        dotspos[i]++;
        if (dotspos[i] > (WIDTH - 1))
        {
            dotspos[i] = 0;
        }

        if (ledstring.channel[0].strip_type == SK6812_STRIP_RGBW) {
            matrix[dotspos[i] + (HEIGHT - 1) * WIDTH] = dotcolors_rgbw[i];
        } else {
            matrix[dotspos[i] + (HEIGHT - 1) * WIDTH] = dotcolors[i];
        }
    }
    }
}


void Ws2811EventHandler::shutdown(){
    matrix_clear();
	matrix_render();
	ws2811_render(&ledstring);
}
