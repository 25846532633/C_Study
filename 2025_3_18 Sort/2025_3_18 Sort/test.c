#include"Sort.h"
void TestInsertSort()
{
	int a[] = { 3, 2, 6, 8, 4, 6, 0, 9, 5, 7, 1 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestBubbleSort()
{
	int a[] = { 3, 2, 6, 8, 4, 6, 0, 9, 5, 7, 1 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestShellSort()
{
	int a[] = { 3, 2, 6, 8, 4, 6, 0, 9, 5, 7, 1 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestSelectSort()
{
	//int a[] = { 3, 2, 6, 8, 4, 6, 0, 9, 5, 7, 1 };
	int a[] = { 13, 2, 6, 8, 4, 6, 0, 9, 5, 7, 1 };

	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestHeapSort()
{
	//int a[] = { 3, 2, 6, 8, 4, 6, 0, 9, 5, 7, 1 };
	int a[] = { 13, 2, 6, 8, 4, 6, 0, 9, 5, 7, 1 };

	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestQuickSort()
{
	//int a[] = { 3, 2, 6, 8, 4, 6, 0, 9, 5, 7, 1 };
	//int a[] = {6,1,2,7,9,3,4,5,10,8};
	int a[] = { 6,1,2,6,7,9,3,4,6,10,8 };
	PrintArray(a, sizeof(a) / sizeof(int));

	QuickSortNonR(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestMergeSort()
{
	//int a[] = { 3, 2, 6, 8, 4, 6, 0, 9, 5, 7, 1 };
	//int a[] = {6,1,2,7,9,3,4,5,10,8};
	int a[] = { 6,1,2,6,7,9,3,4,6,10,8 };
	PrintArray(a, sizeof(a) / sizeof(int));

	MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestCountSort()
{
	//int a[] = { 3, 2, 6, 8, 4, 6, 0, 9, 5, 7, 1 };
	//int a[] = {6,1,2,7,9,3,4,5,10,8};
	int a[] = { 6,1,2,6,7,9,3,4,6,10,8 };
	PrintArray(a, sizeof(a) / sizeof(int));

	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	/*TestInsertSort();
	TestBubbleSort();
	TestShellSort();*/
	//TestSelectSort();
	//	TestOP();
	//TestHeapSort();
	//TestQuickSort();
	//TestMergeSort();
	TestCountSort();
	return 0;
}