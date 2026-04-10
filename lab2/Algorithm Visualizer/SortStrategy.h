#pragma once
#include <vector>

class SortStrategy {
public:
    virtual void sort(std::vector<int>& arr) = 0;
    virtual ~SortStrategy() = default;
};