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
    int error_array[size1] = {1, 2, 3, 4, 5};

    ASSERT_EQ(BinarySearch(error_array, 2, 0, size1), 1);
    ASSERT_EQ(BinarySearch(error_array, 5, 0, size1), 4);
    ASSERT_EQ(BinarySearch(error_array, 1, 0, size1), 0);

    int error_array_2[size2] = {0, 0, 1, 2, 4, 5, 6, 7, 8, 10};
    ASSERT_EQ(BinarySearch(error_array_2, 2, 0, size2), 3);
    ASSERT_EQ(BinarySearch(error_array_2, 10, 0, size2), 9);
    ASSERT_EQ(BinarySearch(error_array_2, 0, 0, size2), 0);   // checks first element.
    ASSERT_EQ(BinarySearch(error_array_2, 5, 0, size2), 5);   // checks first element.

    // incorrect key
    ASSERT_EQ(BinarySearch(error_array_2, -1, 0, size2), -1);
    ASSERT_EQ(BinarySearch(error_array_2, 10001, 0, size2), -1);

    // incorrect size
    ASSERT_THROW(BinarySearch(error_array_2, 1, size2, 0), std::logic_error);

}

// --------------------------- Quick Sort --------------------------- //


TEST(quick_sort, sort) {
    int error_array[size1] = {5, 4, 3, 2, 1};
    int array[size1] = {1, 2, 3, 4, 5};

    QuickSort(error_array, size1);
    for (int i = 0; i < size1; i++)
        ASSERT_EQ(error_array[i], array[i]);

    int error_array_2[size2] = {10, 5, 3, 0, 8, 6, 7, 1, 2, 0};
    int array_2[size2] =   {0, 0, 1, 2, 3, 5, 6, 7, 8, 10};
    QuickSort(error_array_2, size2);
    for (int i = 0; i < size2; i++)
        ASSERT_EQ(error_array_2[i], array_2[i]);

    int error_array_3[size3] = {10, 5, 3, 0, 8, 15, 15, 15, 15, 15, 6, 7, 1, 2, 0};
    int array_3[size3] =   {0, 0, 1, 2, 3, 5, 6, 7, 8, 10, 15, 15, 15, 15, 15};
    QuickSort(error_array_3, size3);
    for (int i = 0; i < size3; i++)
        ASSERT_EQ(error_array_3[i], array_3[i]);

    // incorrect data
    ASSERT_THROW(QuickSort(error_array, size1, 0), std::logic_error);
    ASSERT_THROW(QuickSort(error_array, size2, size1), std::logic_error);
}

// --------------------------- Insertion Sort --------------------------- //

TEST(insertion_sort, sort) {
    int error_array[size1] = {5, 4, 3, 2, 1};
    int array[size1] = {1, 2, 3, 4, 5};

    InsertionSort(error_array, size1);
    for (int i = 0; i < size1; i++)
        ASSERT_EQ(error_array[i], array[i]);

    int error_array_2[size2] = {10, 5, 3, 0, 8, 6, 7, 1, 2, 0};
    int array_2[size2] =   {0, 0, 1, 2, 3, 5, 6, 7, 8, 10};
    InsertionSort(error_array_2, size2);
    for (int i = 0; i < size2; i++)
        ASSERT_EQ(error_array_2[i], array_2[i]);

    int error_array_3[size3] = {10, 5, 3, 0, 8, 15, 15, 15, 15, 15, 6, 7, 1, 2, 0};
    int array_3[size3] =   {0, 0, 1, 2, 3, 5, 6, 7, 8, 10, 15, 15, 15, 15, 15};
    InsertionSort(error_array_3, size3);
    for (int i = 0; i < size3; i++)
        ASSERT_EQ(error_array_3[i], array_3[i]);

    // incorrect data
    ASSERT_THROW(InsertionSort(error_array, -1000), std::logic_error);
}

// --------------------------- Bogo Sort --------------------------- //

TEST(bogo_sort, sort) {
    int error_array[size1] = {5, 4, 3, 2, 1};
    int array[size1] = {1, 2, 3, 4, 5};

    BogoSort(error_array, size1);
    for (int i = 0; i < size1; i++)
        ASSERT_EQ(error_array[i], array[i]);

    int error_array_2[size2] = {10, 5, 3, 0, 8, 6, 7, 1, 2, 0};
    int array_2[size2] =   {0, 0, 1, 2, 3, 5, 6, 7, 8, 10};
    BogoSort(error_array_2, size2);
    for (int i = 0; i < size2; i++)
        ASSERT_EQ(error_array_2[i], array_2[i]);

//    int error_array_3[size3] = {10, 5, 3, 0, 8, 15, 15, 15, 15, 15, 6, 7, 1, 2, 0};
//    int array_3[size3] =   {0, 0, 1, 2, 3, 5, 6, 7, 8, 10, 15, 15, 15, 15, 15};
//    BogoSort(error_array_3, size3);
//    for (int i = 0; i < size3; i++)
//        ASSERT_EQ(error_array_3[i], array_3[i]);

    // incorrect data
    ASSERT_THROW(BogoSort(error_array, -1000), std::logic_error);
}

// --------------------------- Counting Sort --------------------------- //

TEST(counting_sort, sort) {
    char error_array[size1] = {5, 4, 3, 2, 1};
    char array[size1] = {1, 2, 3, 4, 5};

    CountingSort(error_array, size1);
    for (int i = 0; i < size1; i++)
        ASSERT_EQ(error_array[i], array[i]);

    char error_array_2[size2] = {10, 5, 3, 0, 8, 6, 7, 1, 2, 0};
    char array_2[size2] =   {0, 0, 1, 2, 3, 5, 6, 7, 8, 10};
    CountingSort(error_array_2, size2);
    for (int i = 0; i < size2; i++)
        ASSERT_EQ(error_array_2[i], array_2[i]);

    char error_array_3[size3] = {10, 5, 3, 0, 8, 15, 15, 15, 15, 15, 6, 7, 1, 2, 0};
    char array_3[size3] =   {0, 0, 1, 2, 3, 5, 6, 7, 8, 10, 15, 15, 15, 15, 15};
    CountingSort(error_array_3, size3);
    for (int i = 0; i < size3; i++)
        ASSERT_EQ(error_array_3[i], array_3[i]);

    // incorrect data
    ASSERT_THROW(CountingSort(error_array, -10), std::logic_error);
}
