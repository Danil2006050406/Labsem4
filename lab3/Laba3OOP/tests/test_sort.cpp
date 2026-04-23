#include <gtest/gtest.h>
#include "SequentialMergeSorter.h"
#include "ParallelMergeSorter.h"
#include <random>
#include <fstream>
TEST(SortTest, BasicSorting) {
    std::vector<int> data = { 5, 3, 8, 1 };

    SequentialMergeSorter sorter;
    sorter.sort(data);

    std::vector<int> expected = { 1, 3, 5, 8 };
    EXPECT_EQ(data, expected);
}

TEST(LargeDataTest, WorksOnBigArray) {
    const int SIZE = 100000;

    std::vector<int> data(SIZE);
    std::mt19937 rng(42);

    for (int& x : data)
        x = rng();

    auto seq = data;
    auto par = data;

    SequentialMergeSorter s1;
    ParallelMergeSorter s2;

    s1.sort(seq);
    s2.sort(par);

    EXPECT_EQ(seq, par);
}

#include <chrono>

TEST(PerformanceTest, CompareSpeed) {
    const int SIZE = 200000;

    std::vector<int> data(SIZE);
    std::mt19937 rng(42);

    for (int& x : data)
        x = rng();

    auto seq = data;
    auto par = data;

    SequentialMergeSorter s1;
    ParallelMergeSorter s2;

    auto start1 = std::chrono::high_resolution_clock::now();
    s1.sort(seq);
    auto end1 = std::chrono::high_resolution_clock::now();

    auto start2 = std::chrono::high_resolution_clock::now();
    s2.sort(par);
    auto end2 = std::chrono::high_resolution_clock::now();

    auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count();
    auto t2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count();

    std::cout << "\nSequential: " << t1 << " ms\n";
    std::cout << "Parallel: " << t2 << " ms\n";

    std::ofstream file("performance.csv", std::ios::app);

    file << SIZE << ","
         << t1 << ","
         << t2 << "\n";

    file.close();

    EXPECT_EQ(seq, par);
}

TEST(SortTest, EmptyArray) {
    std::vector<int> data;

    SequentialMergeSorter sorter;
    sorter.sort(data);

    EXPECT_TRUE(data.empty());
}

TEST(SortTest, SingleElement) {
    std::vector<int> data = { 42 };

    SequentialMergeSorter sorter;
    sorter.sort(data);

    EXPECT_EQ(data[0], 42);
}

TEST(SortTest, CompareSequentialAndParallel) {
    std::vector<int> data = { 9, 4, 7, 2, 1, 5 };

    auto seq = data;
    auto par = data;

    SequentialMergeSorter s1;
    ParallelMergeSorter s2;

    s1.sort(seq);
    s2.sort(par);

    EXPECT_EQ(seq, par);
}