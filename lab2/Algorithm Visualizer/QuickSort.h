#pragma once
#include "SortStrategy.h"

class QuickSort : public SortStrategy {
private:
    void quickSort(std::vector<int>& arr, int low, int high) {
        if (low >= high) return;

        int pivot = arr[(low + high) / 2];
        int i = low;
        int j = high;

        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;

            if (i <= j) {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        quickSort(arr, low, j);
        quickSort(arr, i, high);
    }

public:
    void sort(std::vector<int>& arr) override {
        quickSort(arr, 0, arr.size() - 1);
    }
};