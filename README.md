# fun_security_sys

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
![Stars](https://img.shields.io/github/stars/Robotics-TDP-Team2/Nao-Soccer-Simulator.svg?style=flat&label=Star&maxAge=86400)
[![Github open issues](https://img.shields.io/github/issues-raw/Robotics-TDP-Team2/Nao-Soccer-Simulator.svg)](https://github.com/Robotics-TDP-Team2/Nao-Soccer-Simulator/issues) 
![](https://img.shields.io/github/repo-size/Robotics-TDP-Team2/Nao-Soccer-Simulator.svg?label=Repo%20size&style=flat-square)&nbsp;
![Contributors](https://img.shields.io/github/contributors/Robotics-TDP-Team2/Nao-Soccer-Simulator.svg?style=flat&label=Contributors&maxAge=86400)

#### Contents
* [Synopsis](#synopsis)
* [Phases and Roadmap](#phases-and-roadmap)
* [Usage Examples](#usage-examples)
* [Milestones](#milestones)
* [Contribution Guidelines](#contribution-guidelines)
* [Credits](#credits)
* [Directory Tree](#directory-tree)

...

## [Credits](#Nao-Soccer-Simulator)

`fun_security_sys` is maintained by the RTEP-Project-Team16. Team members include:

* Bin Liu
* Shuaiqi Liu
* Genyuan Su
* Yuhan Lin

## [Directory Tree](#Nao-Soccer-Simulator)

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
