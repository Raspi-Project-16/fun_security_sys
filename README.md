# Fun_Security_System
![OS: Linux](https://img.shields.io/badge/OS-Linux-e06c75?style=flat&logo=linux)
![Version: v1.0](https://img.shields.io/badge/Version-1.0-blue.svg)
![Stars](https://img.shields.io/github/stars/Robotics-TDP-Team2/Nao-Soccer-Simulator.svg?style=flat&label=Star&maxAge=86400)
[![Github open issues](https://img.shields.io/github/issues-raw/Raspi-Project-16/fun_security_sys-opencv-ws2812.svg)](https://github.com/Raspi-Project-16/fun_security_sys-opencv-ws2812/issues)
![](https://img.shields.io/github/repo-size/Raspi-Project-16/fun_security_sys-opencv-ws2812.svg)
![Contributors](https://img.shields.io/github/contributors/Raspi-Project-16/fun_security_sys-opencv-ws2812.svg?style=flat&label=Contributors&maxAge=86400)
![C++](https://img.shields.io/badge/C++-purple.svg)
![Cmake](https://img.shields.io/badge/Cmake-orange.svg)

#### Contents
* [Synopsis](#synopsis)
* [Wiring](#phases-and-roadmap)
* [Installation](#Installation)
* [Milestones](#milestones)
* [Contribution Guidelines](#contribution-guidelines)
* [Credits](#credits)
* [Directory Tree](#directory-tree)


## [Installation](#Raspi-Project-16)

### 1. Download

```py
$ git clone https://github.com/Raspi-Project-16/fun_security_sys-opencv-ws2812.git
```
### 2. Compile

```py
$ cd raspi_project_16
```
```py
$ cmake .
```
```py
$ make
```
### 3. Run

#### 3.1 Save your photos into the dataset folder

#### 3.2 Train the dataset

```py
$ sudo ./train
```
#### 3.2 Run the program

```py
$ sudo ./run
```


## [Credits](#Raspi-Project-16)

`fun_security_sys` is maintained by the RTEP-Project-Team16. Team members include:

* Bin Liu
* Shuaiqi Liu
* Genyuan Su
* Yuhan Lin

## [Directory Tree](#Raspi-Project-16)

    |–– CMakeFiles
    |–– include
    | |–– event.h
    | |–– eventId.h
    | |—— glo_def.h
    | |–– logger.h
    | |–– events_def.h
    | |–– mysqlConnection.h
    | |–– soundEventHandler.h
    | |–– ws2811EventHandler.h
    | |–– cameraEventHandler.h
    | |–– dispatchEventService.h
    | |–– ledEventHandler.h
    | |–– iEventHandler.h
    | |–– eventQueue.h
    |–– src
    | |–– main.cpp
    | |–– event.cpp
    | |–– logger.cpp
    | |–– events_def.cpp
    | |–– mysqlConnection.cpp
    | |–– soundEventHandler.cpp
    | |–– ws2811EventHandler.cpp
    | |–– cameraEventHandler.cpp
    | |–– dispatchEventService.cpp
    | |–– ledEventHandler.cpp
    |–– bin
    |—— lib
    |—— cascades
    | |–– haarcascade_frontalcatface.xml
    | |–– haarcascade_frontalface_default.xml
    | |–– haarcascade_frontalface_alt.xml
    | |–– lbpcascade_frontalface.xml
    |—— dataset
    | |–– Lucas
    | |–– David
    | |–– Cam
    | |–– Vlada
    |—— recognizer
    | |–– embedding.xml
    | |–– labels.txt
