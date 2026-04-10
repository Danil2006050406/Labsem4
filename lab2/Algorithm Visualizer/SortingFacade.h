#pragma once
#include "SortFactory.h"
#include "TimedSortDecorator.h"

class SortingFacade {
public:
    void runSort(std::vector<int>& arr, const std::string& type) {
        SortStrategy* strategy = SortFactory::create(type);

        TimedSortDecorator timed(strategy);
        timed.sort(arr);

        delete strategy;
    }
};