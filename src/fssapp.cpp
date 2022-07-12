#include "fssapp.h"

using namespace std;

FssApp::FssApp()
{
    this->resize(1000, 800);
    this->move(450, 150);
    window = new MainWindow(this, &rpiCameraDriver);
    window->setParent(this);
    //connect signals
    connect(window, SIGNAL(ledSignal(int)), this, SLOT(ledSignalReceived(int)));
    connect(window, SIGNAL(motorSignal(int)), this, SLOT(degreeSignalReceived(int)));
    connect(window, SIGNAL(stripSignal(int)), this, SLOT(stripSignalReceived(int)));
    connect(window, SIGNAL(startSignal()), this, SLOT(startSignalReceived()));
    connect(window, SIGNAL(stopSignal()), this, SLOT(stopSignalReceived()));
    //register callbacks
    ledDriver.registerCallback(&ledSignalCallback);
    sg90Driver.registerCallback(&sg90SignalCallback);
    ws2811Driver.registerCallback(&ws2811SignalCallback);

    //start with GUI control
    rpiCameraDriver.start();
    sg90Driver.start();
    ws2811Driver.start();
    ssDriver.start();
    ledDriver.start();
}

FssApp::~FssApp(){

}

void FssApp::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);
    if(this->isMaximized()){
        window->move(450, 150);
    }else if(this->isMinimized()){
        window->showMinimized();
    }else {
        window->move(0,0);
    }
}

void FssApp::ledSignalReceived(int signal){
    //cout << signal << endl;
    ledDriver.callback(signal);
}

void FssApp::degreeSignalReceived(int degree){
    //cout << degree << endl;
    sg90Driver.callback(degree);
}

void FssApp::stripSignalReceived(int index){
    //cout << index << endl;
    Color color;
    switch(index){
      case 0:
        color = RAINBOW;
        break;
      case 1:
        color = PURPLE;
        break;
      case 2:
        color = YELLOW;
        break;
      case 3:
        color = PINK;
        break;
      case 4:
        color = BLUE;
        break;
      default:
        color = RAINBOW;
        break;
    }
    ws2811Driver.callback(color);
}

void FssApp::startSignalReceived(){
    ssDriver.registerCallback(&ssSignalCallback);
    rpiCameraDriver.registerCallback(&rpiSignalCallback);
}

void FssApp::stopSignalReceived(){
    ssDriver.unRegisterCallback();
    rpiCameraDriver.unRegisterCallback();
}
