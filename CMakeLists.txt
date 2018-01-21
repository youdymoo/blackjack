cmake_minimum_required(VERSION 3.8)
project(Project4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Project-4-Related-Files/card.cpp
        Project-4-Related-Files/card.h
        Project-4-Related-Files/deck.h
        Project-4-Related-Files/example.cpp
        Project-4-Related-Files/hand.h
        Project-4-Related-Files/player.h
        Project-4-Related-Files/rand.cpp
        Project-4-Related-Files/rand.h)

add_executable(Project4 ${SOURCE_FILES})