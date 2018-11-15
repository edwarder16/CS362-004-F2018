cmake_minimum_required(VERSION 3.10)
project(dominion C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(
        dominion.c
        dominion.h
        dominion_helpers.h
        randomtestAdventurer.c
        randomtestcard1.c
        randomtestcard2.c
        rngs.c
        rngs.h
        rt.c

)
