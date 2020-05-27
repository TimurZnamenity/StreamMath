cmake_minimum_required(VERSION 3.5)

project(StreamMath LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)


add_executable(StreamMath
    main.cpp
    Widgets/MainWindow.cpp
    Widgets/MainWindow.hpp
    Widgets/HandleWidget.cpp
    Widgets/HandleWidget.hpp
    Widgets/ProgressBar.cpp
    Widgets/ProgressBar.hpp
    Data.cpp
    Data.hpp
    Settings.cpp
    Settings.hpp
)

target_include_directories(StreamMath PRIVATE
    Widgets
    )

target_link_libraries(StreamMath PRIVATE Qt5::Widgets)
