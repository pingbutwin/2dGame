cmake_minimum_required(VERSION 3.27)
project(newGame)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_SHARED_LIBS FALSE)

include (FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG         10.2.1
)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(fmt)
FetchContent_MakeAvailable(SFML)

add_executable(
        NewGame betGGame.cpp
        betGamObj.cpp
        betGamObj.h
        Menu.cpp
        Menu.h
        Shop.cpp
        Shop.h
        Player.h
)

target_link_libraries(NewGame fmt)
target_link_libraries(NewGame sfml-graphics)