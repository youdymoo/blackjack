cmake_minimum_required(VERSION 3.7)
project(Project4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp rand.cpp card.cpp deck.cpp hand.cpp player.cpp)
add_executable(Project4 ${SOURCE_FILES})