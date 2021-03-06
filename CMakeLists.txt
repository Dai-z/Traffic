cmake_minimum_required(VERSION 2.8.3)
project(traffic)

add_compile_options(-std=c++11)
find_package(Qt5 COMPONENTS
    Core
    Widgets
    REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

include_directories(
  include
)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/mainwindow.cpp
    src/render.cpp
    src/item_manager.cpp

    #######
    src/items/crossings.cpp
    src/items/signals.cpp
    src/items/car.cpp

    #######
    include/mainwindow.hpp
    include/render.hpp
    include/item_manager.hpp
    include/crossings.hpp
    include/signals.hpp
    include/car.hpp
)

target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Widgets)