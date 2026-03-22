#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include <string.h>

void PrintArray(int* a, int n);
//≤Â»Î≈≈–Ú
void InsertSort(int* a, int n);
//√∞≈›≈≈–Ú
void BubbleSort(int* a, int n);

// œ£∂˚≈≈–Ú
void ShellSort(int* a, int n);
//—°‘Ò≈≈–Ú
void SelectSort(int* a, int n);
//∂—≈≈–Ú
void HeapSort(int* a, int n);
//øÏÀŸ≈≈–Ú
void QuickSort(int* a, int begin, int end);
void QuickSortNonR(int* a, int begin, int end);
//πÈ≤¢≈≈–Ú
void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);
//º∆ ˝≈≈–Ú
void CountSort(int* a, int n);