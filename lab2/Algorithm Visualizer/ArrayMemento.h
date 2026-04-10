#pragma once
#include <vector>

class ArrayMemento {
private:
    std::vector<int> state;

public:
    ArrayMemento(const std::vector<int>& arr)
        : state(arr) {
    }

    std::vector<int> getState() const {
        return state;
    }
};