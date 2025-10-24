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

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)

add_executable(runTests
    tests/tests.cpp
    src/point.cpp
    src/figure.cpp
    src/figures_array.cpp
    src/rhomb.cpp
    src/pentagon.cpp
    src/hexagon.cpp
)

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

add_test(NAME FiguresTest COMMAND runTests)
