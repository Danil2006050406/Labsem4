cmake_minimum_required(VERSION 3.16)
include(FetchContent)
project(Lab3OOP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets Concurrent)

qt_standard_project_setup()

qt_add_executable(Lab3OOP
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    parallelmergesorter.cpp
    parallelmergesorter.h
    sequentialmergesorter.cpp
    sequentialmergesorter.h
    Timer.h
)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests
    tests/test_sort.cpp
    sequentialmergesorter.cpp
    parallelmergesorter.cpp
)

target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(tests
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
target_link_libraries(Lab3OOP PRIVATE Qt6::Widgets Qt6::Concurrent)