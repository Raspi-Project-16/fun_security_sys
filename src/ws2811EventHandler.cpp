#include "ws2811EventHandler.h"



Ws2811EventCallback::Ws2811EventCallback(){
    // initialise the led matrix for the LED strip
    matrix = (ws2811_led_t *)malloc(sizeof(ws2811_led_t) * WIDTH * HEIGHT);
    // initialise the mode for the LED strip
    previousMode = RAINBOW_COLOR;
    // initialise the motor
    pinMode(PWM_PIN, OUTPUT);
    softPwmCreate(PWM_PIN, 0, 200);
    softPwmWrite(PWM_PIN, 5);
    this-> count = 0;
}

Ws2811EventCallback::~Ws2811EventCallback(){
    // initalise the strip
    ws2811_fini(&ledstring);
}

void Ws2811EventCallback::start(){
    // register the callback
    des->subscribe(EEVENTID_WS2811_REQ, this);
    ws2811Ev->setMsg(RAINBOW_COLOR);
    des->publish(ws2811Ev);
}


void Ws2811EventCallback::stop(){
    // unregister the callback
    des->unsubscribe(EEVENTID_WS2811_REQ, this);
}

bool Ws2811EventCallback::callback(const CEvent* ev){
    if(EEVENTID_WS2811_REQ == ev->getEid()){
        Ws2811Event* req = (Ws2811Event*) ev;
        cout << "get:" << req->getMsg() << endl;
        // check the previous mode, if the current mode is not equal to the previous mode
        if(req->getMsg() != previousMode){
            // if the previous mode is rainbow mode
            if(previousMode == RAINBOW_COLOR){
                // start the clock
                begin = clock();
                // change the mode
                previousMode = req->getMsg();
                // if the current mode is accessing mode, turn on the motor
                if(req->getMsg() == ACCESSING_COLOR){
                    softPwmWrite(PWM_PIN, 25);
                }
            }
            // if the previous mode is accessing mode
            if(previousMode == ACCESSING_COLOR){
                //stop the clock
                end = clock();
                cout << begin/CLOCKS_PER_SEC << "  " << end/CLOCKS_PER_SEC << "  " << (end - begin)/CLOCKS_PER_SEC<< endl;
                // if the timing is larger than 10s
                if((end-begin)/CLOCKS_PER_SEC > 10){
                    // turn off the motor
                    softPwmWrite(PWM_PIN, 5);
                    // change the current mode
                    previousMode = req->getMsg();
                    begin = end = 0;
                    // if the current mode is warning mode, start the timing again
                    if(req->getMsg() == WARNING_COLOR){
                    begin = clock();
                    }
                }
            }
            // if the previous mode is warning mode 
            if(previousMode == WARNING_COLOR){
                //stop the timing and check the time
                end = clock();
                cout << begin/CLOCKS_PER_SEC << "  " << end/CLOCKS_PER_SEC << "  " << (end - begin)/CLOCKS_PER_SEC<< endl;
                //if the interval is larger than 10s
                if((end-begin)/CLOCKS_PER_SEC > 10){
                    //change the current mode
                    previousMode = req->getMsg();
                    begin = end = 0;
                    //if the current mode is accessing mode, start the timing again
                    if(req->getMsg() == ACCESSING_COLOR){
                    begin = clock();
                    }
                }
            }
        //if the current mode is equal to the previous mode    
        }else{ 
                //stop the timing 
                end = clock();
                cout << begin/CLOCKS_PER_SEC << "  " << end/CLOCKS_PER_SEC << "  " << (end - begin)/CLOCKS_PER_SEC<< endl;
                //if the interval is larger than 10s, set the mode back to the initial mode
                if((end-begin)/CLOCKS_PER_SEC > 10){
                    ws2811Ev->setMsg(RAINBOW_COLOR);
                    //initial mode
                    previousMode = RAINBOW_COLOR;
                    //set the motor to the initial position
                    softPwmWrite(PWM_PIN, 5);
                    begin = end = 0;
                }
        }
        cout << "execute:" << previousMode << endl;
        execute(previousMode);
        //Ws2811Event* ws2811Ev = new Ws2811Event(previousMode);
        des->publish(req);   
    }else{
        
    }

    return true;
}

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

void Ws2811EventCallback::matrix_clear(){
    int x;


    for (x = 0; x < WIDTH; x++)
    {
        matrix[x] = 0;
    }

}

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


void Ws2811EventCallback::shutdown(){
    matrix_clear();
	matrix_render();
	ws2811_render(&ledstring);
}
