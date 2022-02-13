cmake_minimum_required(VERSION 2.8)
enable_testing()
include_directories(/usr/local/include)

link_directories(/usr/local/lib)

add_executable (fun_security_sys fun_security_sys.cpp)
TARGET_LINK_LIBRARIES(fun_security_sys cpptimer rt)
