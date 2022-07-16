cmake_minimum_required(VERSION 3.5)

project(fss_T16 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(OpenCV REQUIRED)
find_library(PIGPIO_LIBRARIES NAMES pigpio)
find_library(WIRINGPI_LIBRARIES NAMES wiringPi)
find_library(WS2811_LIBRARIES NAMES ws2811)
find_library(RASPICAM_LIBRARIES NAMES raspicam)
find_library(RASPICAM_CV_LIBRARIES NAMES raspicam_cv)
find_library(PTHREAD_LIBRARIES NAMES pthread)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(/usr/local/include/raspicam)
include_directories(/usr/local/include/ws2811)
include_directories(/usr/local/include/opencv4)

link_directories(${PROJECT_SOURCE_DIR}/lib)


set(PROJECT_SOURCES
        src/facetraining.cpp
        src/main.cpp
        src/mainwindow.cpp
        src/leddriver.cpp
        src/soundsensordriver.cpp
        src/ws2811driver.cpp
        src/rpicameradriver.cpp
        src/sg90driver.cpp
        src/fssapp.cpp
        include/facetraining.h
        include/leddriver.h
        include/soundsensordriver.h
        include/ws2811driver.h
        include/rpicameradriver.h
        include/sg90driver.h
        include/mainwindow.h
        include/fssapp.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(fss_T16
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(fss_T16 SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(fss_T16
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(fss_T16 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                      ${OpenCV_LIBRARIES}
                                      ${WIRINGPI_LIBRARIES}
                                      ${PIGPIO_LIBRARIES}
                                      ${WS2811_LIBRARIES}
                                      ${PTHREAD_LIBRARIES}
                                      ${RASPICAM_LIBRARIES}
                                      ${RASPICAM_CV_LIBRARIES})

