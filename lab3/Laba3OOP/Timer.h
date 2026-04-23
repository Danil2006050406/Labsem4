#pragma once
#include <chrono>

class Timer {
    std::chrono::high_resolution_clock::time_point startTime;

public:
    void start() {
        startTime = std::chrono::high_resolution_clock::now();
    }

    double stop() {
        auto endTime = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double, std::milli>(endTime - startTime).count();
    }
};