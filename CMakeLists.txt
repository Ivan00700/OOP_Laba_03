cmake_minimum_required(VERSION 3.10)
project(lab3_figures)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем папку с заголовочными файлами
include_directories(include)

# Собираем исполняемый файл
add_executable(lab3
    main.cpp
    src/figure.cpp
    src/figures_array.cpp
    src/rhomb.cpp
    src/pentagon.cpp
    src/hexagon.cpp
    src/point.cpp
)
