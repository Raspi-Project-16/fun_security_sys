
cmake_minimum_required(VERSION 3.1)

project(raspi_project_16)

find_package(OpenCV REQUIRED)
find_library(WIRINGPI_LIBRARIES NAMES wiringPi)
find_library(CPPTIMER_LIBRARIES NAMES cpptimer)
find_library(RT_LIBRARIES NAMES rt)

set(EXECUTABLE_OUTPUT_PATH /home/pi/raspi_project_16/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(fun_security_sys src/fun_security_sys.cpp src/lightModule.cpp src/soundModule.cpp src/timeModule.cpp)

target_link_libraries(fun_security_sys ${OpenCV_LIBRARIES})
target_link_libraries(fun_security_sys ${WIRINGPI_LIBRARIES})
target_link_libraries(fun_security_sys ${CPPTIMER_LIBRARIES})
target_link_libraries(fun_security_sys ${RT_LIBRARIES})
