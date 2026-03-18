#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

void PrintArray(int* a, int n);
void InsertSort(int* a, int n);
void BubbleSort(int* a, int n);

// Ï£¶ûÅÅĞò
void ShellSort(int* a, int n);
//Ñ¡ÔñÅÅĞò
void SelectSort(int* a, int n);
//¶ÑÅÅĞò
void HeapSort(int* a, int n);
//¿ìËÙÅÅĞò
void QuickSort(int* a, int begin, int end);