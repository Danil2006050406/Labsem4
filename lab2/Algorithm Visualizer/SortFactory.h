#pragma once
#include "BubbleSort.h"
#include "QuickSort.h"
#include "SortStrategy.h"
#include <string>

class SortFactory {
public:
    static SortStrategy* create(const std::string& type) {
        if (type == "bubble")
            return new BubbleSort();

        if (type == "quick")
            return new QuickSort();

        return nullptr;
    }
};