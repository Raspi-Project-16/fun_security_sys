#include "ws2811EventHandler.h"


/*----------------------------------------------------------------------
  |       Ws2811EventCallback::Ws2811EventCallback
  +---------------------------------------------------------------------*/

Ws2811EventCallback::Ws2811EventCallback(){
    // initialise the led matrix for the LED strip
    matrix = (ws2811_led_t *)malloc(sizeof(ws2811_led_t) * WIDTH * HEIGHT);
    // initialise the motor
    pinMode(PWM_PIN, OUTPUT);
    softPwmCreate(PWM_PIN, 0, 200);
    softPwmWrite(PWM_PIN, 5);
}

/*----------------------------------------------------------------------
  |       Ws2811EventCallback::~Ws2811EventCallback
  +---------------------------------------------------------------------*/

Ws2811EventCallback::~Ws2811EventCallback(){
    // initalise the strip
    ws2811_fini(&ledstring);
}

/*----------------------------------------------------------------------
  |       Ws2811EventCallback::start
  +---------------------------------------------------------------------*/

void Ws2811EventCallback::start(){
    // register the callback
    des->subscribe(EEVENTID_WS2811_REQ, this);
    ws2811Ev->setMsg(RAINBOW_COLOR);
    des->publish(ws2811Ev);
}

/*----------------------------------------------------------------------
  |       Ws2811EventCallback::stop
  +---------------------------------------------------------------------*/

void Ws2811EventCallback::stop(){
    // unregister the callback
    des->unsubscribe(EEVENTID_WS2811_REQ, this);
}

/*----------------------------------------------------------------------
  |       Ws2811EventCallback::callback
  +---------------------------------------------------------------------*/

bool Ws2811EventCallback::callback(const CEvent* ev){
    if(EEVENTID_WS2811_REQ == ev->getEid()){
        Ws2811Event* req = (Ws2811Event*) ev;
        //cout << "get:" << req->getMsg() << endl;
        // check the mode, if the current mode is accessing mode
        if(req->getMsg() == ACCESSING_COLOR){
            // rotate the motor 
            softPwmWrite(PWM_PIN, 15);
        }
        // check the mode, if the current mode is warning mode or the initial mode
        if(req->getMsg() == WARNING_COLOR || req->getMsg() == RAINBOW_COLOR){
            //reset the motor
            softPwmWrite(PWM_PIN, 5);
        }
        // render the color matrix
        execute(req->getMsg());
        des->publish(req);   
    }else{
        
    }

    return true;
}

/*----------------------------------------------------------------------
  |       Ws2811EventCallback::execute
  +---------------------------------------------------------------------*/

void Ws2811EventCallback::execute(string msg){
    ws2811_return_t ret;
    //initalise the LED strip
    if ((ret = ws2811_init(&ledstring)) != WS2811_SUCCESS)
    {
        cout << stderr << "ws2811_init failed:" << ws2811_get_return_t_str(ret) << endl;
        exit(1);
    }
    //set all the leds to null first
    matrix_clear();
    //change the color of each led
    matrix_bottom(msg);
    //render the matrix
    matrix_render();
    if ((ret = ws2811_render(&ledstring)) != WS2811_SUCCESS)
    {
        fprintf(stderr, "ws2811_render failed: %s\n", ws2811_get_return_t_str(ret));
        exit(1);
    }
    
}

/*----------------------------------------------------------------------
  |       Ws2811EventCallback::matrix_render
  +---------------------------------------------------------------------*/

void Ws2811EventCallback::matrix_render(){

    int x,y;

    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            ledstring.channel[0].leds[(y * WIDTH) + x] = matrix[y * WIDTH + x];
        }
    }
}

/*----------------------------------------------------------------------
  |       Ws2811EventCallback::matrix_clear
  +---------------------------------------------------------------------*/

void Ws2811EventCallback::matrix_clear(){
    int x;


    for (x = 0; x < WIDTH; x++)
    {
        matrix[x] = 0;
    }

}

/*----------------------------------------------------------------------
  |       Ws2811EventCallback::matrix_bottom
  +---------------------------------------------------------------------*/

void Ws2811EventCallback::matrix_bottom(string mode)
{
    int i;

    for (i = 0; i < (int)(ARRAY_SIZE(dotspos)); i++)
    {
        
        dotspos[i]++;
        if (dotspos[i] > (WIDTH - 1))
        {
            dotspos[i] = 0;
        }
        //set colors for different mode
        if(mode == WARNING_COLOR){
            matrix[dotspos[i] + (HEIGHT - 1) * WIDTH] = dotcolors_red[i];
        }else if(mode == ACCESSING_COLOR){
            matrix[dotspos[i] + (HEIGHT - 1) * WIDTH] = dotcolors_green[i];
        }else if(mode == RAINBOW_COLOR){
            matrix[dotspos[i] + (HEIGHT - 1) * WIDTH] = dotcolors[i];
        }
        
    }
    
}

/*----------------------------------------------------------------------
  |       Ws2811EventCallback::shutdown
  +---------------------------------------------------------------------*/

void Ws2811EventCallback::shutdown(){
    matrix_clear();
	matrix_render();
	ws2811_render(&ledstring);
}
