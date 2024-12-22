cmake_minimum_required(VERSION 3.0)

project(guerra-dos-mundos)

add_executable(guerra-dos-mundos main.cpp)

install(TARGETS guerra-dos-mundos RUNTIME DESTINATION bin)
