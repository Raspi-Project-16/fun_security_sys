# Fun_Security_System
![OS: Linux](https://img.shields.io/badge/OS-Linux-e06c75?style=flat&logo=linux)
![Version: v1.0](https://img.shields.io/badge/Version-1.0-blue.svg)
![Stars](https://img.shields.io/github/stars/Robotics-TDP-Team2/Nao-Soccer-Simulator.svg?style=flat&label=Star&maxAge=86400)
[![Github open issues](https://img.shields.io/github/issues-raw/Raspi-Project-16/fun_security_sys-opencv-ws2812.svg)](https://github.com/Raspi-Project-16/fun_security_sys-opencv-ws2812/issues)
![](https://img.shields.io/github/repo-size/Raspi-Project-16/fun_security_sys-opencv-ws2812.svg)
![Contributors](https://img.shields.io/github/contributors/Raspi-Project-16/fun_security_sys-opencv-ws2812.svg?style=flat&label=Contributors&maxAge=86400)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/6241f4ff80194b638973949a48af328a)](https://www.codacy.com/gh/Raspi-Project-16/fun_security_sys-opencv-ws2812/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Raspi-Project-16/fun_security_sys-opencv-ws2812&amp;utm_campaign=Badge_Grade)

# Contents
* [Social Media](#social_media)
* [Handware](#handware)
* [Wiring](#wiring)
* [Installation](#installation)
* [Milestones](#milestones)
* [Contribution Guidelines](#contribution-guidelines)
* [Credits](#credits)
* [Directory Tree](#directory-tree)

## [Social Media](#Raspi-Project-16)
<br><a href="https://youtu.be/hAqNX1u65mk" target="blank"><img align="left" src="https://upload.wikimedia.org/wikipedia/commons/0/09/YouTube_full-color_icon_%282017%29.svg" height="40" width="40"/>
</a>
<a href="https://www.tiktok.com/@ohmygoal_bliu/video/7087143174593858821?is_from_webapp=1&sender_device=pc&web_id=7087134852688889350">
<img align="left" alt="Mitul | Twitter" width="40px" src="https://upload.wikimedia.org/wikipedia/commons/3/3f/TikTok_Icon_Black.svg" />
</a>
<a href="https://www.instagram.com/reel/CcaM5JNl6Lc/?igshid=YmMyMTA2M2Y=">
<img align="left" alt="Mitul's LinkedIN" width= "40px"
src="https://upload.wikimedia.org/wikipedia/commons/e/e7/Instagram_logo_2016.svg" />
</a>
<a href="https://twitter.com/lucasliu2926/status/1515288695972282370?s=21&t=oh7aflXQyq7_vTI_Y5S0fw">
<img align="left" alt="Mitul | Twitter" width="40px" src="https://raw.githubusercontent.com/peterthehan/peterthehan/master/assets/twitter.svg" />
</a><br><br>

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
#### 3.3 Run the system

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
    | |–– Bruce
    | |–– Benedict
    | |–– Jackie
    |—— recognizer
    | |–– embedding.xml
    | |–– labels.txt
