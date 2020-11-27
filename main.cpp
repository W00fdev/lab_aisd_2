/* Куликов Дмитрий 9302. Вариант 1. */

#include <iostream>
#include <exception>
#include <functional>
#include <time.h>

#include <gtest/gtest.h>
#include "alg.h"

using namespace std;

int BinarySearch(const int *arr, int key, int left, int right) {
    if (left >= right || left < 0 || right < 0) {
        throw logic_error("left and right parts are incorrect");
    } else
    if (key > arr[right - 1] || key < arr[left]) return -1; // There's no such element

    int mid;
    while (left != right) {
        mid = (left + right) / 2;

        if (arr[left] == key) return left;  // Нахождение самого первого! элемента
        if (arr[mid] == key) {
            if (mid == left + 1) return mid;
            else right = mid + 1;
        }

        if (arr[mid] < key) left = mid + 1;
        else if (arr[mid] > key) right = mid - 1;
    }

    if (arr[left] == key) return left;

    return -1;  // There's no such element
}

void swap(int* arr, int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void InsertionSort(int* arr, int size) {
    if (size < 0) throw logic_error("InsertionSort's size is < 0");

    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0 && arr[j-1] > arr[j]; j--)
            swap(arr, j-1, j);
    }
}

bool isSorted(const int* arr, int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] > arr[i]) return false;
    }

    return true;
}

void BogoSort(int* arr, int size) {
    if (size < 0) throw logic_error("BogoSort's size is < 0");

    srand(time(nullptr));

    while(!isSorted(arr,size)) {
        for (int i = 0; i < size; i++) {
            int position = rand() % size;
            int temp = arr[i];
            arr[i] = arr[position];
            arr[position] = temp;
        }
    }
}

void QuickSort(int* arr, int _l, int _r) {
    if (_l > _r || _l < 0 || _r < 0) throw logic_error("incorrect arguments in quicksort");

    int left = _l, right = _r, medium = (left + right) / 2;
    int pivot = arr[medium];

    while (left <= right) {
        while (arr[left] < pivot)
            left++;
        while (arr[right] > pivot)
            right--;

        if (left <= right)
            swap(arr, left++, right--);
    }
    if (_l < right) QuickSort(arr, _l, right);
    if (_r > left) QuickSort(arr, left, _r);
}

void QuickSort(int* arr, int size) {
    QuickSort(arr, 0, size - 1);
}

void CountingSort(char* arr, char size) {
    if (size < 0) throw logic_error("CountingSort's size is < 0");

    char max = INT8_MIN;
    for (char i = 0; i < size; i++)
        if (arr[i] > max) max = arr[i];

    char* num_arr = new char[max + 1];
    int pos = 0;

    for (char i = 0; i < max + 1; i++) num_arr[i] = 0;
    for (char i = 0; i < size; i++) num_arr[arr[i]]++;
    for (char number = 0; number < max + 1; number++) {
        for (char j = 0; j < num_arr[number]; j++) {
            arr[pos] = number;
            pos++;
        }
    }

    delete[] num_arr;
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
//    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    cout << BinarySearch(arr, 2, 0, 10) << endl;
//    cout << BinarySearch(arr, 10, 0, 10) << endl;
//    cout << BinarySearch(arr, 11, 0, 10) << endl;

//    int arr[10] = {10, 9, 8, 7, 10, 11, 15, 6, 3, 2};
//    InsertionSort(arr, 10);
//    for (int i =0; i < 10; i++) cout << arr[i] << " ";

  //  int arr[4] = {4, 3, 2, 1};
//    BogoSort(arr, 10);
//    for (int i =0; i < 10; i++) cout << arr[i] << " ";

//    char arr[10] = {10, 9, 8, 7, 10, 11, 15, 6, 10, 12};
//
//    //QuickSort(arr, 0, 9);
//    CountingSort(arr, 10);
//    for (char i =0; i < 10; i++) cout << (int)arr[i] << " ";

//    Analyzer();
//    double est = 0.0;
//    for (int j = 0; j < 10; j++) {
//        int *data_1 = new int[100'000];
//        for (int i = 0; i < 100'000; i++) {
//            int num = rand() % INT16_MAX;
//            data_1[i] = num;
//        }
//
//
//        clock_t start = clock();
//        QuickSort(data_1, 100'000);
//        clock_t end = clock();
//        est += (double) 1000*  (end - start) / CLOCKS_PER_SEC;
//        delete[] data_1;
//    }
//    est /= 10.0;
//    cout << est << endl;

    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
