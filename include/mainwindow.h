#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QMenu>
#include <QIcon>
#include <QSize>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QWidget>
#include <QPalette>
#include <QColor>
#include <QRadioButton>
#include <QComboBox>
#include <string>
#include <QLineEdit>
#include <QDir>
#include <QFileInfoList>
#include <QString>
#include <QMovie>
#include "rpicameradriver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class RPIImageSampleCallback : public QObject, public RPIImageCallback {

    Q_OBJECT

public:
    virtual void hasSample(Mat image){
        //cout << image << endl;
        emit imageSample(image);
    }

signals:
    void imageSample(Mat);

};

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, RPICameraDriver* camera = nullptr);
    void resizeEvent(QResizeEvent *event);
    void setup_ui();
    ~MainWindow();

private slots:
    void ledSwitchPressed();
    void motorDegreeSelected();
    void stripColorSelected(int index);
    void displayImage(Mat image);
    void startButtonPressed();
    void stopButtonPressed();
    void takePicturesPressed();
    void trainButtonPressed();

signals:
    void ledSignal(int);
    void motorSignal(int);
    void stripSignal(int);
    void startSignal();
    void stopSignal();
    void trainSignal();

private:
    RPICameraDriver* camera;
    RPIImageSampleCallback imageCallback;
    QWidget* rpi_box;
    QWidget* led_box;
    QWidget* sg90_box;
    QWidget* ws2811_box;
    QWidget* start_box;

    QLabel* rpi_camera;
    QLabel* rpi_cam_logo;
    QLabel* led_logo;
    QLabel* led_on;
    QLabel* led_off;
    QLabel* motor_logo;
    QLabel* strip_logo;
    QLabel* strip_label;

    QLineEdit* input_name;

    QMovie* loading_mov;

    QPushButton* take_pictures;
    QPushButton* do_training;
    QPushButton* do_recognition;
    QPushButton* start_button;
    QPushButton* stop_button;

    QRadioButton* led_switch;
    QRadioButton* motor_degree_0;
    QRadioButton* motor_degree_45;
    QRadioButton* motor_degree_90;
    QRadioButton* motor_degree_135;
    QRadioButton* motor_degree_180;

    QWidget* led_logo_box;
    QWidget* motor_logo_box;
    QWidget* strip_logo_box;

    QVBoxLayout* v_bl;
    QHBoxLayout* rpi_bl;
    QVBoxLayout* rpi_bl_l;
    QHBoxLayout* led_bl;
    QHBoxLayout* led_bl_r;
    QHBoxLayout* motor_bl;
    QHBoxLayout* motor_bl_r;
    QHBoxLayout* strip_bl;
    QHBoxLayout* strip_bl_r;
    QHBoxLayout* start_bl;

    QComboBox* color_options;

};
#endif // MAINWINDOW_H
