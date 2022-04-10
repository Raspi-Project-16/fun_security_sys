#include "ws2811EventHandler.h"



Ws2811EventHandler::Ws2811EventHandler(){
    matrix = (ws2811_led_t *)malloc(sizeof(ws2811_led_t) * WIDTH * HEIGHT);
    previousMode = RAINBOW_COLOR;
    this-> count = 0;
}

Ws2811EventHandler::~Ws2811EventHandler(){
    ws2811_fini(&ledstring);
}

void Ws2811EventHandler::start(){
    des->subscribe(EEVENTID_WS2811_REQ, this);
    ws2811Ev->setMsg(RAINBOW_COLOR);
    des->publish(ws2811Ev);
}


void Ws2811EventHandler::stop(){
    des->unsubscribe(EEVENTID_WS2811_REQ, this);
}

bool Ws2811EventHandler::handle(const CEvent* ev){
    if(EEVENTID_WS2811_REQ == ev->getEid()){
        Ws2811Event* req = (Ws2811Event*) ev;
        cout << "get:" << req->getMsg() << endl;
        
        if(req->getMsg() != previousMode){
            
            if(previousMode == RAINBOW_COLOR){
                begin = clock();
                previousMode = req->getMsg();
            }
            
            if(previousMode == ACCESSING_COLOR){
                end = clock();
                cout << begin/CLOCKS_PER_SEC << "  " << end/CLOCKS_PER_SEC << "  " << (end - begin)/CLOCKS_PER_SEC<< endl;
                if((end-begin)/CLOCKS_PER_SEC > 10){
                    previousMode = req->getMsg();
                    begin = end = 0;
                    if(req->getMsg() == WARNING_COLOR){
                    begin = clock();
                    }
                }
            }
            
            if(previousMode == WARNING_COLOR){
                end = clock();
                cout << begin/CLOCKS_PER_SEC << "  " << end/CLOCKS_PER_SEC << "  " << (end - begin)/CLOCKS_PER_SEC<< endl;
                if((end-begin)/CLOCKS_PER_SEC > 10){
                    previousMode = req->getMsg();
                    begin = end = 0;
                    if(req->getMsg() == ACCESSING_COLOR){
                    begin = clock();
                    }
                }
            }
            
        }else{ 
                end = clock();
                cout << begin/CLOCKS_PER_SEC << "  " << end/CLOCKS_PER_SEC << "  " << (end - begin)/CLOCKS_PER_SEC<< endl;
                if((end-begin)/CLOCKS_PER_SEC > 10){
                    ws2811Ev->setMsg(RAINBOW_COLOR);
                    previousMode = RAINBOW_COLOR;
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

void Ws2811EventHandler::execute(string msg){
    ws2811_return_t ret;
    if ((ret = ws2811_init(&ledstring)) != WS2811_SUCCESS)
    {
        cout << stderr << "ws2811_init failed:" << ws2811_get_return_t_str(ret) << endl;
        exit(1);
    }
    matrix_clear();
    matrix_bottom(msg);
    matrix_render();
    if ((ret = ws2811_render(&ledstring)) != WS2811_SUCCESS)
    {
        fprintf(stderr, "ws2811_render failed: %s\n", ws2811_get_return_t_str(ret));
        exit(1);
    }
    
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

void Ws2811EventHandler::matrix_clear(){
    int x;


    for (x = 0; x < WIDTH; x++)
    {
        matrix[x] = 0;
    }

}

void Ws2811EventHandler::matrix_bottom(string mode)
{
    int i;

    for (i = 0; i < (int)(ARRAY_SIZE(dotspos)); i++)
    {
        
        dotspos[i]++;
        if (dotspos[i] > (WIDTH - 1))
        {
            dotspos[i] = 0;
        }
        
        if(mode == WARNING_COLOR){
            matrix[dotspos[i] + (HEIGHT - 1) * WIDTH] = dotcolors_red[i];
        }else if(mode == ACCESSING_COLOR){
            matrix[dotspos[i] + (HEIGHT - 1) * WIDTH] = dotcolors_green[i];
        }else if(mode == RAINBOW_COLOR){
            matrix[dotspos[i] + (HEIGHT - 1) * WIDTH] = dotcolors[i];
        }
        
    }
    
}


void Ws2811EventHandler::shutdown(){
    matrix_clear();
	matrix_render();
	ws2811_render(&ledstring);
}
