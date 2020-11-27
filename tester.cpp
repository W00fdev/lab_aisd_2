#include <vector>
#include <exception>
#include "../alg.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using std::vector;


const int size1 = 5;
const int size2 = 10;
const int size3 = 15;

// --------------------------- Binary Search --------------------------- //


TEST(binary_search, search) {
    int e_arr[size1] = {1, 2, 3, 4, 5};

    ASSERT_EQ(BinarySearch(e_arr, 2, 0, size1), 1);
    ASSERT_EQ(BinarySearch(e_arr, 5, 0, size1), 4);
    ASSERT_EQ(BinarySearch(e_arr, 1, 0, size1), 0);

    int e_arr_2[size2] = {0, 0, 1, 2, 4, 5, 6, 7, 8, 10};
    ASSERT_EQ(BinarySearch(e_arr_2, 2, 0, size2), 3);
    ASSERT_EQ(BinarySearch(e_arr_2, 10, 0, size2), 9);
    ASSERT_EQ(BinarySearch(e_arr_2, 0, 0, size2), 0);   // checks first element.
    ASSERT_EQ(BinarySearch(e_arr_2, 5, 0, size2), 5);   // checks first element.

    // incorrect key
    ASSERT_EQ(BinarySearch(e_arr_2, -1, 0, size2), -1);
    ASSERT_EQ(BinarySearch(e_arr_2, 10001, 0, size2), -1);

    // incorrect size
    ASSERT_THROW(BinarySearch(e_arr_2, 1, size2, 0), std::logic_error);

}

// --------------------------- Quick Sort --------------------------- //


TEST(quick_sort, sort) {
    int e_arr[size1] = {5, 4, 3, 2, 1};
    int arr[size1] = {1, 2, 3, 4, 5};

    QuickSort(e_arr, size1);
    for (int i = 0; i < size1; i++)
        ASSERT_EQ(e_arr[i], arr[i]);

    int e_arr_2[size2] = {10, 5, 3, 0, 8, 6, 7, 1, 2, 0};
    int arr_2[size2] =   {0, 0, 1, 2, 3, 5, 6, 7, 8, 10};
    QuickSort(e_arr_2, size2);
    for (int i = 0; i < size2; i++)
        ASSERT_EQ(e_arr_2[i], arr_2[i]);

    int e_arr_3[size3] = {10, 5, 3, 0, 8, 15, 15, 15, 15, 15, 6, 7, 1, 2, 0};
    int arr_3[size3] =   {0, 0, 1, 2, 3, 5, 6, 7, 8, 10, 15, 15, 15, 15, 15};
    QuickSort(e_arr_3, size3);
    for (int i = 0; i < size3; i++)
        ASSERT_EQ(e_arr_3[i], arr_3[i]);

    // incorrect data
    ASSERT_THROW(QuickSort(e_arr, size1, 0), std::logic_error);
    ASSERT_THROW(QuickSort(e_arr, size2, size1), std::logic_error);
}

// --------------------------- Insertion Sort --------------------------- //

TEST(insertion_sort, sort) {
    int e_arr[size1] = {5, 4, 3, 2, 1};
    int arr[size1] = {1, 2, 3, 4, 5};

    InsertionSort(e_arr, size1);
    for (int i = 0; i < size1; i++)
        ASSERT_EQ(e_arr[i], arr[i]);

    int e_arr_2[size2] = {10, 5, 3, 0, 8, 6, 7, 1, 2, 0};
    int arr_2[size2] =   {0, 0, 1, 2, 3, 5, 6, 7, 8, 10};
    InsertionSort(e_arr_2, size2);
    for (int i = 0; i < size2; i++)
        ASSERT_EQ(e_arr_2[i], arr_2[i]);

    int e_arr_3[size3] = {10, 5, 3, 0, 8, 15, 15, 15, 15, 15, 6, 7, 1, 2, 0};
    int arr_3[size3] =   {0, 0, 1, 2, 3, 5, 6, 7, 8, 10, 15, 15, 15, 15, 15};
    InsertionSort(e_arr_3, size3);
    for (int i = 0; i < size3; i++)
        ASSERT_EQ(e_arr_3[i], arr_3[i]);

    // incorrect data
    ASSERT_THROW(InsertionSort(e_arr, -1000), std::logic_error);
}

// --------------------------- Bogo Sort --------------------------- //

TEST(bogo_sort, sort) {
    int e_arr[size1] = {5, 4, 3, 2, 1};
    int arr[size1] = {1, 2, 3, 4, 5};

    BogoSort(e_arr, size1);
    for (int i = 0; i < size1; i++)
        ASSERT_EQ(e_arr[i], arr[i]);

    int e_arr_2[size2] = {10, 5, 3, 0, 8, 6, 7, 1, 2, 0};
    int arr_2[size2] =   {0, 0, 1, 2, 3, 5, 6, 7, 8, 10};
    BogoSort(e_arr_2, size2);
    for (int i = 0; i < size2; i++)
        ASSERT_EQ(e_arr_2[i], arr_2[i]);

//    int e_arr_3[size3] = {10, 5, 3, 0, 8, 15, 15, 15, 15, 15, 6, 7, 1, 2, 0};
//    int arr_3[size3] =   {0, 0, 1, 2, 3, 5, 6, 7, 8, 10, 15, 15, 15, 15, 15};
//    BogoSort(e_arr_3, size3);
//    for (int i = 0; i < size3; i++)
//        ASSERT_EQ(e_arr_3[i], arr_3[i]);

    // incorrect data
    ASSERT_THROW(BogoSort(e_arr, -1000), std::logic_error);
}

// --------------------------- Counting Sort --------------------------- //

TEST(counting_sort, sort) {
    char e_arr[size1] = {5, 4, 3, 2, 1};
    char arr[size1] = {1, 2, 3, 4, 5};

    CountingSort(e_arr, size1);
    for (int i = 0; i < size1; i++)
        ASSERT_EQ(e_arr[i], arr[i]);

    char e_arr_2[size2] = {10, 5, 3, 0, 8, 6, 7, 1, 2, 0};
    char arr_2[size2] =   {0, 0, 1, 2, 3, 5, 6, 7, 8, 10};
    CountingSort(e_arr_2, size2);
    for (int i = 0; i < size2; i++)
        ASSERT_EQ(e_arr_2[i], arr_2[i]);

    char e_arr_3[size3] = {10, 5, 3, 0, 8, 15, 15, 15, 15, 15, 6, 7, 1, 2, 0};
    char arr_3[size3] =   {0, 0, 1, 2, 3, 5, 6, 7, 8, 10, 15, 15, 15, 15, 15};
    CountingSort(e_arr_3, size3);
    for (int i = 0; i < size3; i++)
        ASSERT_EQ(e_arr_3[i], arr_3[i]);

    // incorrect data
    ASSERT_THROW(CountingSort(e_arr, -10), std::logic_error);
}
