# Fun_Security_System
![OS: Linux](https://img.shields.io/badge/OS-Linux-e06c75?style=flat&logo=linux)
![Version: v1.0](https://img.shields.io/badge/Version-1.0-blue.svg)
![Stars](https://img.shields.io/github/stars/Raspi-Project-16/fun_security_sys.svg?style=flat&label=Star&maxAge=86400)
[![Github open issues](https://img.shields.io/github/issues-raw/Raspi-Project-16/fun_security_sys.svg)](https://github.com/Raspi-Project-16/fun_security_sys/issues)
![](https://img.shields.io/github/repo-size/Raspi-Project-16/fun_security_sys.svg)
![Contributors](https://img.shields.io/github/contributors/Raspi-Project-16/fun_security_sys.svg?style=flat&label=Contributors&maxAge=86400)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/6241f4ff80194b638973949a48af328a)](https://www.codacy.com/gh/Raspi-Project-16/fun_security_sys/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Raspi-Project-16/fun_security_sys&amp;utm_campaign=Badge_Grade)

# Contents
* [Social Media](#social-media)
* [Handware](#handware)
* [Wiring](#wiring)
* [Installation](#installation)
* [Project Wiki](#project-wiki)
* [Flow Chart](#flow-chart)
* [Report](#report)
* [Credits](#credits)
* [Directory Tree](#directory-tree)
## [Social Media](#Raspi-Project-16)
<br><a href="https://youtu.be/IglcY-m-mO4" target="blank"><img align="left" src="https://upload.wikimedia.org/wikipedia/commons/0/09/YouTube_full-color_icon_%282017%29.svg" height="40" width="40"/>
</a>
<a href="https://www.tiktok.com/@ohmygoal_bliu/video/7126262810232851717?is_from_webapp=1&sender_device=pc&web_id=7087134852688889350">
<img align="left" alt="Mitul | Twitter" width="40px" src="https://upload.wikimedia.org/wikipedia/commons/3/3f/TikTok_Icon_Black.svg" />
</a>
<br><br>

## [Handware](#Raspi-Project-16)
<br>

<img align="left" width="180px" src="https://user-images.githubusercontent.com/85005419/163680231-62acdc1f-0fc5-4af3-ae3e-f9a4044e9a38.jpg" />
<img align="left" width="180px" src="https://user-images.githubusercontent.com/85005419/163680202-d1ba3bfd-ef0a-4c41-9061-4778aeef2b6d.jpg" />
<img align="left" width="180px" src="https://user-images.githubusercontent.com/85005419/163681156-97548632-2d6e-407c-af32-65889f19ef85.jpeg" />
<img align="center" width="180px" src="https://user-images.githubusercontent.com/85005419/163680208-fa9b71e5-f120-464e-8213-f15121690aa0.jpeg" />



## [Wiring](#Raspi-Project-16)

<img width="980" alt="wiring" src="https://user-images.githubusercontent.com/85005419/163157866-35b83be7-9eb9-45b7-b3c5-c027b84ec5b0.png">

## [Installation](#Raspi-Project-16)

### 1. Download
* wiringpi
https://github.com/WiringPi/WiringPi
```py
$ git clone https://github.com/WiringPi/WiringPi.git
$ sudo ./build
```
* pigpio
https://abyz.me.uk/rpi/pigpio/download.html
```py
$ wget https://github.com/joan2937/pigpio/archive/master.zip
$ unzip master.zip
$ cd pigpio-master
$ make
$ sudo make install
```
* opencv4.x
https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html
```py
$ wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
$ wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.x.zip
$ unzip opencv.zip
$ unzip opencv_contrib.zip
$ mkdir -p build && cd build
$ cmake -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib-4.x/modules ../opencv-4.x
$ cmake --build .
$ sudo make install
```
* raspicam
https://github.com/cedricve/raspicam
```py
$ git clone https://github.com/cedricve/raspicam.git
$ cd raspicam
$ mkdir build
$ cd build
$ cmake ..
$ make
$ sudo make install
$ sudo ldconfig
```
* ws2811
https://github.com/jgarff/rpi_ws281x
```py
$ git clone https://github.com/jgarff/rpi_ws281x.git
$ mkdir build
$ cd build
$ cmake -D BUILD_SHARED=OFF -D BUILD_TEST=ON ..
$ cmake --build .
$ sudo make install
```
* fun_security_sys
```py
$ git clone https://github.com/Raspi-Project-16/fun_security_sys.git
```
### 2. Compile

```py
$ cd fun_security_sys
```
```py
$ cmake .
```
```py
$ make
```
### 3. Run

#### 3.1 Train the dataset
```py
$ cd bin
```
```py
$ sudo ./train
```
#### 3.2 Run the system
```py
$ cd bin
```
```py
$ sudo ./run
```
## [Project Wiki](#Raspi-Project-16)

Thank you for your interest in our project. We strongly encourage reading the wiki page of our project. You can find it [here](https://github.com/Raspi-Project-16/fun_security_sys/wiki).

## [Flow Chart](#Raspi-Project-16)

<img width="1677" alt="automatic_mode" src="https://user-images.githubusercontent.com/85005419/180747477-4ba45cc7-3704-4b19-b59b-e8fcc53be376.png">


## [Report](#Raspi-Project-16)
Our report can be found in [here](https://github.com/Raspi-Project-16/project_report/blob/main/RealTime_Report.pdf).
## [Credits](#Raspi-Project-16)

`fun_security_sys` is maintained by the RTEP-Project-Team16. Team members include:

* Bin Liu   https://github.com/Lucas-ohmygoal
* Shuaiqi Liu   https://github.com/LinkinEminem
* Genyuan Su   https://github.com/sugenyuan
* Yuhan Lin   https://github.com/YuhanLin12

## [Directory Tree](#Raspi-Project-16)

    |–– CMakeFiles
    |–– include
    | |–– facetraining.h
    | |–– fssapp.h
    | |—— leddriver.h
    | |–– mainwindow.h
    | |–– rpicameradriver.h
    | |–– sg90driver.h
    | |–– soundsensordriver.h
    | |–– ws2811driver.h
    |–– src
    | |–– main.cpp
    | |–– facetrining.cpp
    | |–– fssapp.cpp
    | |–– leddriver.cpp
    | |–– sg90driver.cpp
    | |–– soundsensordriver.cpp
    | |–– ws2811driver.cpp
    | |–– mainwindow.cpp
    | |–– rpicameradriver.cpp
    |–– images
    |—— fss_T16_autogen
    |—— cascades
    | |–– haarcascade_frontalcatface.xml
    | |–– haarcascade_frontalface_default.xml
    | |–– haarcascade_frontalface_alt.xml
    | |–– lbpcascade_frontalface.xml
    |—— dataset
    | |–– Lucas
    | |–– Bruce
    | |–– Benedict
    | |–– Jackie
    |—— recognizer
    | |–– embedding.xml
    | |–– labels.txt
