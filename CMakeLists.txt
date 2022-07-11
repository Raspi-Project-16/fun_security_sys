
cmake_minimum_required(VERSION 3.1)

project(fun_security_sys)

set(Boost_USE_STATIC_LIBS ON)
set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

find_package(OpenCV REQUIRED)
find_library(PIGPIO_LIBRARIES NAMES pigpio)
find_library(WIRINGPI_LIBRARIES NAMES wiringPi)
#find_library(CPPTIMER_LIBRARIES NAMES cpptimer)
find_library(WS2811_LIBRARIES NAMES ws2811)
#find_library(RT_LIBRARIES NAMES rt)
#find_library(GLOG_LIBRARIES NAMES glog)
find_library(RASPICAM_LIBRARIES NAMES raspicam)
find_library(RASPICAM_CV_LIBRARIES NAMES raspicam_cv)
find_library(PTHREAD_LIBRARIES NAMES pthread)
#find_package(Boost REQUIRED COMPONENTS filesystem system thread)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(/usr/local/include/raspicam)
include_directories(/usr/local/include/ws2811)
#include_directories(/usr/local/include/glog)
include_directories(/usr/local/include/opencv4)

link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(run 
    src/main.cpp 
    src/ledEventHandler.cpp
    src/soundEventHandler.cpp
    src/ws2811EventHandler.cpp
    src/cameraEventHandler.cpp
    src/sg90EventHandler.cpp
    )

#add_executable(train 
    #src/faceRecogitionTraining.cpp 
#)

target_link_libraries(run ${OpenCV_LIBRARIES})
target_link_libraries(run ${WIRINGPI_LIBRARIES})
target_link_libraries(run ${PIGPIO_LIBRARIES})
#target_link_libraries(run ${CPPTIMER_LIBRARIES})
target_link_libraries(run ${WS2811_LIBRARIES})
#target_link_libraries(run ${RT_LIBRARIES})
#target_link_libraries(run ${GLOG_LIBRARIES})
target_link_libraries(run ${PTHREAD_LIBRARIES})
#target_link_libraries(run ${Boost_LIBRARIES})
target_link_libraries(run ${RASPICAM_LIBRARIES})
target_link_libraries(run ${RASPICAM_CV_LIBRARIES})

#target_link_libraries(train ${OpenCV_LIBRARIES})
#target_link_libraries(train ${RASPICAM_LIBRARIES})
#target_link_libraries(train ${RASPICAM_CV_LIBRARIES})
#target_link_libraries(train ${Boost_LIBRARIES})
