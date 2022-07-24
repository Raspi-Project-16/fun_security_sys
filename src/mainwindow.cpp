#include "mainwindow.h"
#include <iostream>
using namespace std;


MainWindow::MainWindow(QWidget *parent, RPICameraDriver* camera)
    : QWidget(parent)
{
    this->camera = camera;
    camera->registerImageCallback(&imageCallback);
    rpi_box = new QWidget();
    led_box = new QWidget();
    sg90_box = new QWidget();
    ws2811_box = new QWidget();
    start_box = new QWidget();

    v_bl = new QVBoxLayout();
    rpi_bl = new QHBoxLayout();
    rpi_bl_l = new QVBoxLayout();

    input_name = new QLineEdit();

    take_pictures = new QPushButton();
    do_training = new QPushButton();

    loading_mov = new QMovie("/home/pi/fss_T16/images/loading.gif");
    rpi_camera = new QLabel();
    rpi_cam_logo = new QLabel();

    led_bl = new QHBoxLayout();
    led_bl_r = new QHBoxLayout();

    led_logo_box = new QWidget();
    led_switch = new QRadioButton();
    led_on = new QLabel();
    led_off = new QLabel();
    led_logo = new QLabel();

    motor_bl = new QHBoxLayout();
    motor_bl_r = new QHBoxLayout();

    motor_logo_box = new QWidget();
    motor_degree_0 = new QRadioButton();
    motor_degree_45 = new QRadioButton();
    motor_degree_90 = new QRadioButton();
    motor_degree_135 = new QRadioButton();
    motor_degree_180 = new QRadioButton();
    motor_logo = new QLabel();

    strip_logo_box = new QWidget();
    strip_logo = new QLabel();
    strip_label = new QLabel();
    strip_bl = new QHBoxLayout();
    strip_bl_r = new QHBoxLayout();
    color_options = new QComboBox();

    start_button = new QPushButton();
    stop_button = new QPushButton();
    start_bl = new QHBoxLayout();

    setup_ui();

}

MainWindow::~MainWindow()
{

}

void MainWindow::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);
    led_logo_box->resize(int(this->width() / 3), led_logo_box->height());
    led_logo->move(int(led_logo_box->width() / 2) - 110, 25);
    motor_logo_box->resize(int(this->width() / 3), motor_logo_box->height());
    motor_logo->move(int(motor_logo_box->width() / 2) - 100, 25);
    strip_logo_box->resize(int(this->width() / 3), strip_logo_box->height());
    strip_logo->move(int(strip_logo_box->width() / 2) - 110, 25);
}

void MainWindow::ledSwitchPressed(){
    int signal = led_switch->isChecked();
    emit ledSignal(signal);
}

void MainWindow::motorDegreeSelected(){
    if (motor_degree_0->isChecked()){
        emit motorSignal(0);
    }
    if (motor_degree_45->isChecked()){
        emit motorSignal(45);
    }
    if (motor_degree_90->isChecked()){
        emit motorSignal(90);
    }
    if (motor_degree_135->isChecked()){
        emit motorSignal(135);
    }
    if (motor_degree_180->isChecked()){
        emit motorSignal(180);
    }
}

void MainWindow::stripColorSelected(int index){
    emit stripSignal(index);
}

void MainWindow::displayImage(Mat image){
    QImage dst = QImage(image.data,image.cols,image.rows,image.step,QImage::Format_BGR888);
    QPixmap img = QPixmap(QPixmap::fromImage(dst));
    rpi_camera->setMaximumSize(600, 350);
    rpi_camera->setScaledContents(true);
    rpi_camera->setPixmap(img);

}

void MainWindow::startButtonPressed(){
    take_pictures->setDisabled(true);
    do_training->setDisabled(true);
    input_name->setDisabled(true);
    led_switch->setDisabled(true);
    led_on->setDisabled(true);
    led_off->setDisabled(true);
    motor_degree_0->setDisabled(true);
    motor_degree_45->setDisabled(true);
    motor_degree_90->setDisabled(true);
    motor_degree_135->setDisabled(true);
    motor_degree_180->setDisabled(true);
    color_options->setDisabled(true);
    strip_label->setDisabled(true);
    emit startSignal();
}

void MainWindow::stopButtonPressed(){
    take_pictures->setDisabled(false);
    do_training->setDisabled(false);
    input_name->setDisabled(false);
    led_switch->setDisabled(false);
    led_on->setDisabled(false);
    led_off->setDisabled(false);
    motor_degree_0->setDisabled(false);
    motor_degree_45->setDisabled(false);
    motor_degree_90->setDisabled(false);
    motor_degree_135->setDisabled(false);
    motor_degree_180->setDisabled(false);
    color_options->setDisabled(false);
    strip_label->setDisabled(false);
    emit stopSignal();
}

void MainWindow::takePicturesPressed(){
    if(input_name->text() == ""){
        input_name->setStyleSheet("border: 1px solid red;");
        input_name->setFocus();
    }else{
        input_name->setStyleSheet("border: 1px solid #b2bec5;");
        QDir dir;
        QString currentPath = QDir::currentPath();
        QString dataFile = currentPath + "/dataset/" + input_name->text();
        cout << dataFile.toStdString() << endl;
        if(!dir.exists(dataFile)){
            dir.mkdir(dataFile);
        }
        Mat frame;
        for(int i=0; i<5; i++){
            // save the image to the taget folder
            frame = camera->takePictures();
            imwrite(dataFile.toStdString() + "/bin" + "_" + to_string(i) + ".jpg",frame);
        }
    }
}

void MainWindow::trainButtonPressed(){
    emit trainSignal();
}

void MainWindow::setup_ui(){

    this->resize(1000, 800);
    this->setLayout(v_bl);

    this->setStyleSheet("\
    QPushButton\
    {\
        background: #b2bec5;\
        border-radius: 8px;\
        color: #404042;\
        width: 200px;\
        height: 40px;\
        font-size: 18px;\
        font-weight: 700;\
        border: 3px solid #B1c1c2;\
    }\
    QPushButton:hover\
    {\
        background: #67ae5b;\
        color: #ffffff;\
        font-size: 19px;\
        font-weight: 30px;\
    }\
    QPushButton:disabled\
    {\
        color: #899299\
    }\
    QPushButton#start_button\
    {\
        background: #67ae5b;\
        border-radius: 8px;\
        color: #ffffff;\
        width: 150px;\
        height: 50px;\
        font-size: 20px;\
        font-weight: 700;\
        border: 3px solid #B1c1c2;\
    }\
    QPushButton#start_button:hover\
    {\
        background: #67ae5b;\
        color: #ffffff;\
        font-size: 22px;\
        font-weight: 30px;\
    }\
    QPushButton#stop_button\
    {\
        background: #d26053;\
        border-radius: 8px;\
        color: #ffffff;\
        width: 130px;\
        height: 50px;\
        font-size: 17px;\
        font-weight: 700;\
        border: 3px solid #B1c1c2;\
    }\
    QPushButton#stop_button:hover\
    {\
        background: #d26053;\
        color: #ffffff;\
        font-size: 19px;\
        font-weight: 30px;\
    }\
    QLabel\
    {\
        color: #404042;\
        font-size: 25px;\
        font-weight: 600;\
    }\
    QLabel:disabled\
    {\
        color: #899299\
    }\
    QRadioButton\
    {\
        color: #404042;\
        font-size: 21px;\
        font-weight: 600;\
    }\
    QRadioButton:disabled\
    {\
        color: #899299\
    }\
    QLabel#camera_box\
    {\
        border-radius: 5px;\
    }\
    QWidget#rpi_box, #led_box, #sg90_box, #ws2811_box, #start_box\
    {\
        border-bottom: 2px solid #e8e9e8;\
    }\
    #led_switch::indicator:checked{\
        image: url(/home/pi/fss_T16/images/on-button.png); width: 100px; height: 80px;\
    }\
    #led_switch::indicator:unchecked{\
        image: url(/home/pi/fss_T16/images/off-button.png); width: 100px; height: 80px;\
    }\
    #0_degree::indicator:checked,#45_degree::indicator:checked,#90_degree::indicator:checked,#135_degree::indicator:checked,#180_degree::indicator:checked{\
        image: url(/home/pi/fss_T16/images/selected.png); width: 50px; height: 50px;\
    }\
    #0_degree::indicator:unchecked,#45_degree::indicator:unchecked,#90_degree::indicator:unchecked,#135_degree::indicator:unchecked,#180_degree::indicator:unchecked{\
        image: url(/home/pi/fss_T16/images/not_selected.png); width: 50px; height: 50px;\
    }\
    QComboBox\
    {\
        border-radius:5px;\
        background-color: #b5bdc4;\
        font-weight: 700;\
        font-size:20px;\
        color: #404042;\
        width: 150px;\
        height: 50px;\
        padding-left:20px;\
    }\
    QComboBox:disabled\
    {\
        color: #899299\
    }\
    QComboBox:hover\
    {\
        background-color:#b5bdc4;\
        border-radius:5px;\
    }\
    QComboBox:on\
    {\
        border-radius: 5px;\
        background-color:#b5bdc4;\
        color:#404042;\
    }\
    QComboBox QAbstractItemView\
    {\
        outline: 0px solid #67ae5b;\
        border-radius: 5px;\
        border: 1px solid #67ae5b;\
        color: #404042;\
        font: 25px;\
        font-weight: 500;\
        background-color: transparent;\
        selection-background-color: #67ae5b;\
    }\
    QComboBox QAbstractItemView::item\
    {\
        height: 50px;\
        font-size: 20px;\
        border-radius:5px;\
        background-color: #67ae5b;\
    }\
    QComboBox QAbstractItemView::item:hover\
    {\
        height: 50px;\
        border-radius:5px;\
        background: #67ae5b;\
    }\
    QComboBox QAbstractItemView::item:selected\
    {\
        color: #404042;\
        background: #67ae5b;\
        border-radius:5px;\
    }\
    QComboBox::drop-down\
    {\
        border-radius: 5px;\
        right:20px;\
        width: 30px;\
    }\
    QComboBox::down-arrow\
    {\
        right:0px;\
        width: 30px;\
        height: 30px;\
        image: url(/home/pi/fss_T16/images/down-e.png);\
    }\
    QComboBox::down-arrow:hover\
    {\
        width: 30px;\
        height: 30px;\
        image: url(/home/pi/fss_T16/images/down-arrow.png);\
    }\
    QLineEdit\
    {\
        width: 60px;\
        height: 45px;\
        color: #404042;\
        font-size: 20px;\
        font-weight: 700;\
        border-radius: 5px;\
        border: 1px solid #b2bec5;\
        padding-left: 10px;\
    }\
    ");

    v_bl->addWidget(rpi_box);
    v_bl->addWidget(led_box);
    v_bl->addWidget(sg90_box);
    v_bl->addWidget(ws2811_box);
    v_bl->addWidget(start_box);
    rpi_box->setObjectName("rpi_box");
    led_box->setObjectName("led_box");
    sg90_box->setObjectName("sg90_box");
    ws2811_box->setObjectName("ws2811_box");
    start_box->setObjectName("start_box");
    v_bl->setAlignment(Qt::AlignCenter);
    v_bl->setSpacing(2);
    v_bl->setMargin(1);
    v_bl->setStretch(0, 3);
    v_bl->setStretch(1, 1);
    v_bl->setStretch(2, 1);
    v_bl->setStretch(3, 1);
    v_bl->setStretch(4, 1);

    rpi_box->setLayout(rpi_bl);
    rpi_bl->addLayout(rpi_bl_l);
    rpi_bl->addWidget(rpi_camera);
    rpi_bl->setSpacing(10);
    rpi_bl->setStretch(0, 1);
    rpi_bl->setStretch(1,2);
    rpi_bl->setAlignment(rpi_camera, Qt::AlignCenter);

    rpi_camera->setObjectName("camera_box");
    rpi_camera->setMaximumSize(600, 350);
    rpi_camera->setScaledContents(true);
    rpi_camera->setMovie(loading_mov);
    loading_mov->setSpeed(300);
    loading_mov->start();

    rpi_bl_l->addWidget(rpi_cam_logo);
    rpi_bl_l->addSpacing(10);
    rpi_bl_l->addWidget(input_name);
    rpi_bl_l->addWidget(take_pictures);
    rpi_bl_l->addWidget(do_training);
    rpi_bl_l->setAlignment(Qt::AlignCenter);
    rpi_bl_l->setSpacing(20);
    rpi_bl_l->setAlignment(rpi_cam_logo, Qt::AlignLeft);

    rpi_cam_logo->setText("Camera:");
    rpi_cam_logo->adjustSize();
    rpi_cam_logo->setMaximumSize(60, 50);
    QPixmap cam_logo = QPixmap("/home/pi/fss_T16/images/camera-s.png");
    rpi_cam_logo->setScaledContents(true);
    rpi_cam_logo->setPixmap(cam_logo);
    input_name->setPlaceholderText("Please input your name");
    input_name->resize(60, 80);
    take_pictures->setText("Take Photos");
    take_pictures->resize(60, 80);
    take_pictures->setCursor(Qt::PointingHandCursor);
    do_training->setText("Train");
    do_training->resize(60, 80);
    do_training->setCursor(Qt::PointingHandCursor);
    qRegisterMetaType< Mat >("Mat");

    // when image data is reveied from the camera, display the image
    connect(&imageCallback, SIGNAL(imageSample(Mat)), this, SLOT(displayImage(Mat)));

    // when the take pictures button is clicked
    connect(take_pictures, SIGNAL(clicked()), this, SLOT(takePicturesPressed()));

    // when the train button is clicked
    connect(do_training, SIGNAL(clicked()), this, SLOT(trainButtonPressed()));

    led_box->setLayout(led_bl);
    led_bl->addWidget(led_logo_box);
    led_bl->addLayout(led_bl_r);
    led_bl->setSpacing(0);
    led_bl->setMargin(0);
    led_bl->setAlignment(led_bl_r, Qt::AlignLeft);
    led_bl->setStretch(0, 1);
    led_bl->setStretch(1, 2);

    led_logo->setParent(led_logo_box);
    led_logo->setMaximumSize(75, 65);
    QPixmap led_pic = QPixmap("/home/pi/fss_T16/images/bulb.png");
    led_logo->setPixmap(led_pic);
    led_logo->setScaledContents(true);

    led_bl_r->addWidget(led_off);
    led_bl_r->addWidget(led_switch);
    led_bl_r->addWidget(led_on);
    led_bl_r->setSpacing(0);
    led_bl_r->setStretch(0, 2);
    led_bl_r->setStretch(1, 1);
    led_bl_r->setStretch(2, 2);
    led_bl_r->setAlignment(Qt::AlignCenter);
    led_bl_r->setAlignment(led_off, Qt::AlignRight);
    led_bl_r->setAlignment(led_on, Qt::AlignLeft);
    led_bl_r->setAlignment(led_switch, Qt::AlignCenter);

    led_off->setText("OFF");
    led_on->setText("ON");

    led_switch->setCursor(Qt::PointingHandCursor);
    led_switch->setObjectName("led_switch");

    // when the led switch is pressed
    connect(led_switch, SIGNAL(released()), this, SLOT(ledSwitchPressed()));

    sg90_box->setLayout(motor_bl);
    motor_bl->addWidget(motor_logo_box);
    motor_bl->addLayout(motor_bl_r);
    motor_bl->setSpacing(0);
    motor_bl->setMargin(0);
    motor_bl->setStretch(0, 1);
    motor_bl->setStretch(1, 2);
    motor_bl->setAlignment(led_bl_r, Qt::AlignLeft);

    motor_logo->setParent(motor_logo_box);
    motor_logo->setMaximumSize(75, 65);
    QPixmap motor_pic = QPixmap("/home/pi/fss_T16/images/servo.png");
    motor_logo->setPixmap(motor_pic);
    motor_logo->setScaledContents(true);

    motor_bl_r->addWidget(motor_degree_0);
    motor_bl_r->addWidget(motor_degree_45);
    motor_bl_r->addWidget(motor_degree_90);
    motor_bl_r->addWidget(motor_degree_135);
    motor_bl_r->addWidget(motor_degree_180);
    motor_bl_r->setSpacing(25);
    motor_bl_r->setMargin(0);
    motor_bl_r->setAlignment(Qt::AlignCenter);

    motor_degree_0->setObjectName("0_degree");
    motor_degree_45->setObjectName("45_degree");
    motor_degree_90->setObjectName("90_degree");
    motor_degree_135->setObjectName("135_degree");
    motor_degree_180->setObjectName("180_degree");
    motor_degree_0->setCursor(Qt::PointingHandCursor);
    motor_degree_45->setCursor(Qt::PointingHandCursor);
    motor_degree_90->setCursor(Qt::PointingHandCursor);
    motor_degree_135->setCursor(Qt::PointingHandCursor);
    motor_degree_180->setCursor(Qt::PointingHandCursor);
    motor_degree_0->setText("0°");
    motor_degree_45->setText("45°");
    motor_degree_90->setText("90°");
    motor_degree_135->setText("135°");
    motor_degree_180->setText("180°");

    // when the degree buttons are selected
    connect(motor_degree_0, SIGNAL(clicked()), this, SLOT(motorDegreeSelected()), Qt::UniqueConnection);
    connect(motor_degree_45, SIGNAL(clicked()), this, SLOT(motorDegreeSelected()), Qt::UniqueConnection);
    connect(motor_degree_90, SIGNAL(clicked()), this, SLOT(motorDegreeSelected()), Qt::UniqueConnection);
    connect(motor_degree_135, SIGNAL(clicked()), this, SLOT(motorDegreeSelected()), Qt::UniqueConnection);
    connect(motor_degree_180, SIGNAL(clicked()), this, SLOT(motorDegreeSelected()), Qt::UniqueConnection);


    ws2811_box->setLayout(strip_bl);
    strip_bl->addWidget(strip_logo_box);
    strip_bl->addLayout(strip_bl_r);
    strip_bl->setSpacing(0);
    strip_bl->setMargin(0);
    strip_bl->setStretch(0, 1);
    strip_bl->setStretch(1, 2);

    strip_logo->setParent(strip_logo_box);
    strip_logo->setMaximumSize(75, 65);
    QPixmap strip_pic = QPixmap("/home/pi/fss_T16/images/rgb.png");
    strip_logo->setPixmap(strip_pic);
    strip_logo->setScaledContents(true);

    strip_bl_r->addWidget(strip_label);
    strip_bl_r->addWidget(color_options);
    strip_bl_r->addSpacing(20);
    strip_bl_r->setSpacing(20);
    strip_bl_r->setMargin(0);
    strip_bl_r->setStretch(0, 1);
    strip_bl_r->setStretch(1, 2);
    strip_bl_r->setAlignment(strip_label, Qt::AlignRight);
    strip_bl_r->setAlignment(color_options, Qt::AlignCenter);

    strip_label->setText("Color :");

    color_options->setCursor(Qt::PointingHandCursor);
    color_options->setObjectName("color_options");
    color_options->addItems({"Rainbow", "Purple", "Yellow", "Pink", "Blue"});

    // when the color of led strip is chosen
    connect(color_options, SIGNAL(currentIndexChanged(int)), this, SLOT(stripColorSelected(int)));

    start_box->setLayout(start_bl);
    start_bl->addWidget(start_button);
    start_bl->addWidget(stop_button);
    start_bl->setSpacing(30);
    start_bl->setAlignment(Qt::AlignCenter);
    start_button->setObjectName("start_button");
    start_button->setText("Start");
    start_button->setCursor(Qt::PointingHandCursor);

    // when the start button is clicked
    connect(start_button, SIGNAL(clicked()), this, SLOT(startButtonPressed()));
    stop_button->setObjectName("stop_button");
    stop_button->setText("Stop");
    stop_button->setCursor(Qt::PointingHandCursor);

    // when the stop button is clicked
    connect(stop_button, SIGNAL(clicked()), this, SLOT(stopButtonPressed()));
}

