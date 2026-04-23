#pragma once
#include "ISorter.h"
#include <vector>
class SortContext {
private:
    ISorter* sorter;

public:
    void setSorter(ISorter* s) {
        sorter = s;
    }

    void execute(std::vector<int>& data) {
        if (sorter)
            sorter->sort(data);
    }
};