#include "parallelmergesorter.h"
#include <thread>

void ParallelMergeSorter::sort(std::vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1, 0);
}

void ParallelMergeSorter::mergeSort(std::vector<int>& arr, int left, int right, int depth) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    if (depth < 3) {
        std::thread t1(&ParallelMergeSorter::mergeSort, this, std::ref(arr), left, mid, depth + 1);
        std::thread t2(&ParallelMergeSorter::mergeSort, this, std::ref(arr), mid + 1, right, depth + 1);

        t1.join();
        t2.join();
    } else {
        mergeSort(arr, left, mid, depth + 1);
        mergeSort(arr, mid + 1, right, depth + 1);
    }

    merge(arr, left, mid, right);
}

void ParallelMergeSorter::merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[left + k] = temp[k];
}