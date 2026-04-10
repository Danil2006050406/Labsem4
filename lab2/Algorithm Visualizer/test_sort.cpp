#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

void bubbleSort(std::vector<int>& arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        for (size_t j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

void quickSort(std::vector<int>& arr)
{
    std::sort(arr.begin(), arr.end());
}

void mergeSort(std::vector<int>& arr)
{
    std::sort(arr.begin(), arr.end());
}

TEST(BubbleSortTest, SortsCorrectly)
{
    std::vector<int> arr = {5, 2, 9, 1};
    bubbleSort(arr);

    EXPECT_EQ(arr, std::vector<int>({1, 2, 5, 9}));
}

TEST(BubbleSortTest, EmptyArray)
{
    std::vector<int> arr;
    bubbleSort(arr);

    EXPECT_TRUE(arr.empty());
}

TEST(BubbleSortTest, SingleElement)
{
    std::vector<int> arr = {7};
    bubbleSort(arr);

    EXPECT_EQ(arr, std::vector<int>({7}));
}

TEST(QuickSortTest, SortsCorrectly)
{
    std::vector<int> arr = {8, 3, 6, 1};
    quickSort(arr);

    EXPECT_EQ(arr, std::vector<int>({1, 3, 6, 8}));
}

TEST(QuickSortTest, EmptyArray)
{
    std::vector<int> arr;
    quickSort(arr);

    EXPECT_TRUE(arr.empty());
}

TEST(QuickSortTest, SingleElement)
{
    std::vector<int> arr = {10};
    quickSort(arr);

    EXPECT_EQ(arr, std::vector<int>({10}));
}

TEST(MergeSortTest, SortsCorrectly)
{
    std::vector<int> arr = {4, 7, 2, 9};
    mergeSort(arr);

    EXPECT_EQ(arr, std::vector<int>({2, 4, 7, 9}));
}

TEST(MergeSortTest, EmptyArray)
{
    std::vector<int> arr;
    mergeSort(arr);

    EXPECT_TRUE(arr.empty());
}

TEST(MergeSortTest, SingleElement)
{
    std::vector<int> arr = {1};
    mergeSort(arr);

    EXPECT_EQ(arr, std::vector<int>({1}));
}