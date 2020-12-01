#ifndef LAB_KULIKOV_2_ALG_H
#define LAB_KULIKOV_2_ALG_H

int BinarySearch(const int *array, int key, int left, int right);
void swap(int* array, int left, int right);
void InsertionSort(int* array, int size);
bool isSorted(const int* array, int size);
void BogoSort(int* array, int size);
void QuickSort(int* array, int source_left, int source_right);
void QuickSort(int* array, int size);
void CountingSort(char* array, char size);

#endif //LAB_KULIKOV_2_ALG_H
