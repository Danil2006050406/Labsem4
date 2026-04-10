#pragma once
#include "SortStrategy.h"
#include <chrono>
#include <iostream>

class TimedSortDecorator : public SortStrategy {
private:
    SortStrategy* wrapped;

public:
    TimedSortDecorator(SortStrategy* strategy)
        : wrapped(strategy) {
    }

    void sort(std::vector<int>& arr) override {
        auto start = std::chrono::high_resolution_clock::now();

        wrapped->sort(arr);

        auto end = std::chrono::high_resolution_clock::now();

        std::cout << "Execution time: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
            << " ms\n";
    }
};  