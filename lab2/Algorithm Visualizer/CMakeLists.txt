cmake_minimum_required(VERSION 3.16)

project(AlgorithmVisualizer)

set(CMAKE_CXX_STANDARD 17)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

add_executable(AlgorithmVisualizer
    AlgorithmVisualizer.cpp
       MainWindow.cpp
       MainWindow.h
       BarWidget.cpp
       BarWidget.h

       BubbleSort.h
       QuickSort.h
       MergeSort.h
       ArrayMemento.h
       Command.h
       SortFactory.h
       SortStrategy.h
       SortingFacade.h
       TimedSortDecorator.h

)
target_link_libraries(AlgorithmVisualizer PRIVATE Qt6::Widgets)
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(UnitTests
    test_sort.cpp
)

target_link_libraries(UnitTests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(UnitTests)