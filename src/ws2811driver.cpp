#include "ws2811driver.h"


/*----------------------------------------------------------------------
  |       WS2811Driver::WS2811Driver
  +---------------------------------------------------------------------*/

WS2811Driver::WS2811Driver(WS2811settings settings){
    // initialise the settings
    ws2811settings = settings;
    // initialise the color
    fill(ws2811settings.red_spots, ws2811settings.red_spots + 24, 0x00000020);
    fill(ws2811settings.green_spots, ws2811settings.green_spots + 24, 0x00002000);
    fill(ws2811settings.purple_spots, ws2811settings.purple_spots + 24, 0x00200010);
    fill(ws2811settings.pink_spots, ws2811settings.pink_spots + 24, 0x00100010);
    fill(ws2811settings.yellow_spots, ws2811settings.yellow_spots + 24, 0x00002020);
    fill(ws2811settings.blue_spots, ws2811settings.blue_spots + 24, 0x00200000);
    // initialise the led matrix for the LED strip
    matrix = (ws2811_led_t *)malloc(sizeof(ws2811_led_t) * ws2811settings.width * ws2811settings.height);
}

/*----------------------------------------------------------------------
  |       WS2811Driver::~WS2811Driver
  +---------------------------------------------------------------------*/

WS2811Driver::~WS2811Driver(){
  stop();
  if (nullptr != matrix) {
        free(matrix);
          matrix = nullptr;
  }
}

/*----------------------------------------------------------------------
  |       WS2811Driver::start
  +---------------------------------------------------------------------*/

void WS2811Driver::start(){
  if (nullptr != ws2811Thread) {
                // already running
                return;
        }
  ws2811Thread = new thread(execute,this);
}

/*----------------------------------------------------------------------
  |       WS2811Driver::stop
  +---------------------------------------------------------------------*/

void WS2811Driver::stop(){
  running = 0;
        if (nullptr != ws2811Thread) {
                ws2811Thread->join();
                delete ws2811Thread;
                ws2811Thread = nullptr;
  }
  matrix_clear();
  matrix_render();
  ws2811_render(&ws2811settings.ledstring);
}

/*----------------------------------------------------------------------
  |       WS2811Driver::registerCallback
  +---------------------------------------------------------------------*/

void WS2811Driver::registerCallback(WS2811callback* cb) {
        ws2811callback = cb;
}

/*----------------------------------------------------------------------
  |       WS2811Driver::unRegisterCallback
  +---------------------------------------------------------------------*/

void WS2811Driver::unRegisterCallback() {
        ws2811callback = nullptr;
}

/*----------------------------------------------------------------------
  |       WS2811Driver::run
  +---------------------------------------------------------------------*/

void WS2811Driver::run(){
    ws2811_return_t ret;
    //initalise the LED strip
    if ((ret = ws2811_init(&ws2811settings.ledstring)) != WS2811_SUCCESS)
    {
        cout << stderr << "ws2811_init failed:" << ws2811_get_return_t_str(ret) << endl;
        exit(1);
    }

    while(running){
        //set all the leds to null first
        matrix_clear();
        //change the color of each led
        matrix_bottom();
        //render the matrix
        matrix_render();
        if ((ret = ws2811_render(&ws2811settings.ledstring)) != WS2811_SUCCESS)
        {
            fprintf(stderr, "ws2811_render failed: %s\n", ws2811_get_return_t_str(ret));
            exit(1);
        }
        // usleep(1000000 / 35);
    }

}

/*----------------------------------------------------------------------
  |       WS2811Driver::callback()
  +---------------------------------------------------------------------*/


void WS2811Driver::callback(Color color){
    #ifdef DEBUG
    cout << color << endl;
    #endif
    if(nullptr != ws2811callback){
      ws2811callback->hasSignal(this, color);
    }
}

/*----------------------------------------------------------------------
  |       WS2811Driver::matrix_render
  +---------------------------------------------------------------------*/

void WS2811Driver::matrix_render(){

    int x,y;

    for (x = 0; x < ws2811settings.width; x++)
    {
        for (y = 0; y < ws2811settings.height; y++)
        {
            ws2811settings.ledstring.channel[0].leds[(y * ws2811settings.width) + x] = matrix[y * ws2811settings.width + x];
        }
    }
}

/*----------------------------------------------------------------------
  |       WS2811Driver::matrix_clear
  +---------------------------------------------------------------------*/

void WS2811Driver::matrix_clear(){

    int x;
    for (x = 0; x < ws2811settings.width; x++)
    {
        matrix[x] = 0;
    }

}

/*----------------------------------------------------------------------
  |       WS2811Driver::matrix_bottom
  +---------------------------------------------------------------------*/

void WS2811Driver::matrix_bottom()
{
    int i;

    for (i = 0; i < (int)(ARRAY_SIZE(ws2811settings.color_spots)); i++)
    {

        ws2811settings.color_spots[i]++;
        if (ws2811settings.color_spots[i] > (ws2811settings.width - 1))
        {
            ws2811settings.color_spots[i] = 0;
        }
        //set colors for different mode
        if(ws2811settings.color == RED){
            matrix[ws2811settings.color_spots[i] + (ws2811settings.height - 1) * ws2811settings.width] = ws2811settings.red_spots[i];
        }else if(ws2811settings.color == GREEN){
            matrix[ws2811settings.color_spots[i] + (ws2811settings.height - 1) * ws2811settings.width] = ws2811settings.green_spots[i];
        }else if(ws2811settings.color == RAINBOW){
            matrix[ws2811settings.color_spots[i] + (ws2811settings.height - 1) * ws2811settings.width] = ws2811settings.rainbow_spots[i];
        }else if(ws2811settings.color == PURPLE){
            matrix[ws2811settings.color_spots[i] + (ws2811settings.height - 1) * ws2811settings.width] = ws2811settings.purple_spots[i];
        }else if(ws2811settings.color == YELLOW){
            matrix[ws2811settings.color_spots[i] + (ws2811settings.height - 1) * ws2811settings.width] = ws2811settings.yellow_spots[i];
        }else if(ws2811settings.color == PINK){
            matrix[ws2811settings.color_spots[i] + (ws2811settings.height - 1) * ws2811settings.width] = ws2811settings.pink_spots[i];
        }else if(ws2811settings.color == BLUE){
            matrix[ws2811settings.color_spots[i] + (ws2811settings.height - 1) * ws2811settings.width] = ws2811settings.blue_spots[i];
        }

    }

}

/*----------------------------------------------------------------------
  |       WS2811Driver::setColor
  +---------------------------------------------------------------------*/


void WS2811Driver::setColor(Color color){
    this->ws2811settings.color = color;
}
