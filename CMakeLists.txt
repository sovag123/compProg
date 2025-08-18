cmake_minimum_required(VERSION 4.0)
project(turci)

set(CMAKE_CXX_STANDARD 20)

add_executable(turci main.cpp)
add_executable(downtime katis/downtime.cpp)
add_executable(pivot katis/pivot.cpp)
add_executable(mastermin katis/mastermind.cpp)
add_executable( gredinc katis/greedilyincreasing.cpp)
add_executable(erase katis/erase.cpp)
add_executable(dividebyhundred katis/divideby100.cpp)

add_executable(astro katis/astro.cpp)
add_executable(mastermind katis/mastermind.cpp)