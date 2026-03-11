#include "Heap.h"


//int main()
//{
//	int a[] = { 4,6,2,1,5,8,2,0 };
//	HP hp;
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
//	{
//		HeapPush(&hp, a[i]);
//	}
//
//	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
//	{
//		printf("%d ", hp.a[i]);
//	}
//	printf("\n");
//	HeapPop(&hp);
//	for (int i = 0; i < hp.size; ++i)
//	{
//		printf("%d ", hp.a[i]);
//	}
//	return 0;
//}

int main()
{
	int a[] = { 4, 6, 2, 1, 5, 8, 2, 9 };

	HeapSort(a, sizeof(a)/sizeof(int));

	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}