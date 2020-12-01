/* Куликов Дмитрий 9302. Вариант 1. */

#include <iostream>
#include <exception>
#include <functional>
#include <time.h>

#include <gtest/gtest.h>
#include "alg.h"

using namespace std;

int BinarySearch(const int *array, int key, int left, int right) {
    if (left >= right || left < 0 || right < 0) {
        throw logic_error("left and right parts are incorrect");
    } else
    if (key > array[right - 1] || key < array[left]) return -1; // There's no such element

    int middle;
    while (left != right) {
        middle = (left + right) / 2;

        if (array[left] == key) return left;  // Нахождение самого первого! элемента
        if (array[middle] == key) {
            if (middle == left + 1) return middle;
            else right = middle + 1;
        }

        if (array[middle] < key) left = middle + 1;
        else if (array[middle] > key) right = middle - 1;
    }

    if (array[left] == key) return left;

    return -1;  // There's no such element
}

void swap(int* array, int left, int right) {
    int temp = array[right];
    array[right] = array[left];
    array[left] = temp;
}

void InsertionSort(int* array, int size) {
    if (size < 0) throw logic_error("InsertionSort's size is < 0");

    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0 && array[j-1] > array[j]; j--)
            swap(array, j-1, j);
    }
}

bool isSorted(const int* array, int size) {
    for (int i = 1; i < size; i++) {
        if (array[i - 1] > array[i]) return false;
    }

    return true;
}

void BogoSort(int* array, int size) {
    if (size < 0) throw logic_error("BogoSort's size is < 0");

    srand(time(nullptr));

    while(!isSorted(array,size)) {
        for (int i = 0; i < size; i++) {
            int position = rand() % size;
            int temp = array[i];
            array[i] = array[position];
            array[position] = temp;
        }
    }
}

void QuickSort(int* array, int source_left, int source_right) {
    if (source_left > source_right || source_left < 0 || source_right < 0) throw logic_error("incorrect arguments in quicksort");

    int left = source_left, right = source_right, medium = (left + right) / 2;
    int pivot = array[medium];

    while (left <= right) {
        while (array[left] < pivot)
            left++;
        while (array[right] > pivot)
            right--;

        if (left <= right)
            swap(array, left++, right--);
    }
    if (source_left < right) QuickSort(array, source_left, right);
    if (source_right > left) QuickSort(array, left, source_right);
}

void QuickSort(int* array, int size) {
    QuickSort(array, 0, size - 1);
}

void CountingSort(char* array, char size) {
    if (size < 0) throw logic_error("CountingSort's size is < 0");

    char max = INT8_MIN;
    for (char i = 0; i < size; i++)
        if (array[i] > max) max = array[i];

    char* counting_array = new char[max + 1];
    int pos = 0;

    for (char i = 0; i < max + 1; i++) counting_array[i] = 0;
    for (char i = 0; i < size; i++) counting_array[array[i]]++;
    for (char number = 0; number < max + 1; number++) {
        for (char j = 0; j < counting_array[number]; j++) {
            array[pos] = number;
            pos++;
        }
    }

    delete[] counting_array;
}

// --------------------------- ANALYZE ------------------------------

void Analyzer() {
    srand(time(nullptr));

    // 10
    for (int CHECK = 10; CHECK < 101'000; CHECK *= 10) {
        double est_time_1 = 0.0;
        double est_time_2 = 0.0;

        for (int i = 0; i < 10; i++) {
            int *data_1 = new int[CHECK];
            int *data_2 = new int[CHECK];

            for (int i = 0; i < CHECK; i++) {
                int num = rand() % INT16_MAX;
                data_1[i] = num;
                data_2[i] = num;
            }

            clock_t start = clock();
            QuickSort(data_1,CHECK);
            clock_t end = clock();
            est_time_1 += (double) 1000 * (end - start) / CLOCKS_PER_SEC;

            if (!isSorted(data_1, CHECK)) throw logic_error("array isn't sorted!!!");

            start = clock();
            InsertionSort(data_2, CHECK);
            end = clock();
            est_time_2 += (double) 1000 * (end - start) / CLOCKS_PER_SEC;

            if (!isSorted(data_2, CHECK)) throw logic_error("array isn't sorted!!!");

            delete [] data_1;
            delete [] data_2;
        }
        est_time_1 /= (double)CHECK;
        est_time_2 /= (double)CHECK;
        cout << "Est time for " << CHECK << "\'s QuickSort: " << est_time_1 << "ms" << endl;
        cout << "Est time for  " << CHECK << "\'s InsertionSort: " << est_time_2 << "ms" << endl;
    }
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
