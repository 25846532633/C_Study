//#include <stdio.h>
//
//void swap(int arr1[], int arr2[],int sz)
//{
//	while (sz)
//	{
//		int temp = *arr1;
//		*arr1 = *arr2;
//		*arr2 = temp;
//		arr1++;
//		arr2++;
//		sz--;
//	}
//}
//
//
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 6,7,8,9,0 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	swap(arr1, arr2,sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}