cmake_minimum_required(VERSION 3.26)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameOfLife main.cpp
        Board.cpp
        Board.h
        Cell.cpp
        Cell.h
        StateObserver.cpp
        StateObserver.h
        Game.cpp
        Game.h)
