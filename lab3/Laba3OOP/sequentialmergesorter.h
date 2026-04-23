#pragma once
#include <vector>
#include "ISorter.h"

class SequentialMergeSorter : public ISorter {
public:
    void sort(std::vector<int>& data) override;

private:
    void mergeSort(std::vector<int>& arr, int left, int right);
    void merge(std::vector<int>& arr, int left, int mid, int right);
};