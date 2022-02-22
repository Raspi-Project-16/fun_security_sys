
cmake_minimum_required(VERSION 3.1)

project(raspi_project_16)

find_package(OpenCV REQUIRED)
find_library(WIRINGPI_LIBRARIES NAMES wiringPi)
find_library(PIGPIO_LIBRARIES NAMES pigpio)
find_library(CPPTIMER_LIBRARIES NAMES cpptimer)
find_library(WS2811_LIBRARIES NAMES ws2811)
find_library(RT_LIBRARIES NAMES rt)

set(EXECUTABLE_OUTPUT_PATH /home/pi/raspi_project_16)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(/usr/local/include/ws2811)


add_executable(fun_security_sys src/fun_security_sys.cpp src/lightModule.cpp src/soundModule.cpp src/timeModule.cpp src/ledModule.cpp)

target_link_libraries(fun_security_sys ${OpenCV_LIBRARIES})
target_link_libraries(fun_security_sys ${WIRINGPI_LIBRARIES})
target_link_libraries(fun_security_sys ${PIGPIO_LIBRARIES})
target_link_libraries(fun_security_sys ${CPPTIMER_LIBRARIES})
target_link_libraries(fun_security_sys ${WS2811_LIBRARIES})
target_link_libraries(fun_security_sys ${RT_LIBRARIES})
