cmake_minimum_required(VERSION 3.28)
project(ADS_Praktikum)

set(CMAKE_CXX_STANDARD 17)

add_executable(ADS_Praktikum main.cpp
        catch.h
        Ring.cpp
        Ring.h
        RingNode.cpp
        RingNode.h
        RingTest.cpp
)
