#pragma once
#include "Command.h"
#include <vector>

class SwapCommand : public Command {
private:
    std::vector<int>& arr;
    int i, j;

public:
    SwapCommand(std::vector<int>& a, int x, int y)
        : arr(a), i(x), j(y) {
    }

    void execute() override {
        std::swap(arr[i], arr[j]);
    }

    void undo() override {
        std::swap(arr[i], arr[j]);
    }
};