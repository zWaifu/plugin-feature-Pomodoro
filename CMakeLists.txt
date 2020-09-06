cmake_minimum_required(VERSION 3.5)

project(Pomodoro LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/plugins/features/${PROJECT_NAME})

find_package(Qt5 COMPONENTS Widgets Quick LinguistTools REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_library(Pomodoro SHARED
  Pomodoro_global.h
  Pomodoro.cpp
  Pomodoro.h
  pomodoro.json
  qml.qrc
)

target_link_libraries(Pomodoro PRIVATE Qt5::Core Qt5::Quick)
target_link_libraries(Pomodoro PRIVATE zPI)


target_compile_definitions(Pomodoro PRIVATE POMODORO_LIBRARY)
