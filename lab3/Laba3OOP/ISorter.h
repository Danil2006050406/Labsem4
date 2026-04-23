#pragma once
#include <vector>

class ISorter {
public:
    virtual void sort(std::vector<int>& data) = 0;
    virtual ~ISorter() = default;
};