cmake_minimum_required(VERSION 3.23)
project(netKursov C)

set(CMAKE_C_STANDARD 23)

add_executable(netKursov main.c libs/message/message.c libs/test/testMessage.c libs/test/testMessage.h
        libs/Hemming/hemming.c libs/Hemming/hemming.h libs/test/testHemming.c libs/test/testHemming.h libs/menu/menu.c
        libs/menu/menu.h libs/HemmingL/hemmingL.c libs/HemmingL/hemmingL.h
        libs/test/testHemmingL.c libs/test/testHemmingL.h)
