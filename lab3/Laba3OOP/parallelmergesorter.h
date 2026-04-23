#pragma once
#include <vector>
#include "ISorter.h"

class ParallelMergeSorter : public ISorter {
public:
    void sort(std::vector<int>& data) override;

private:
    void mergeSort(std::vector<int>& arr, int left, int right, int depth = 0);
    void merge(std::vector<int>& arr, int left, int mid, int right);
};