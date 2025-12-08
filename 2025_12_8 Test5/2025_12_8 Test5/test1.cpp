//#include <stdio.h>
//#include <string.h>
////int main()
////{
////   /* char str[] = "hello bit";*/
////    char acX[] = "abcdefg";
////    char acY[] = { 'a','b','c','d','e','f','g' };
////    printf("%d %d\n", sizeof(acX), strlen(acX));
////    printf("%d %d\n", sizeof(acY), strlen(acY));
////    return 0;
////}
//
//
////void init(int arr[], int sz)
////{
////	for (int i = 0; i < sz;i++)
////	{
////		arr[i] = i * 2;
////	}
////}
//
//void Bubble_sort(int arr[], int sz)
//{
//	for (int i = 0; i < sz - 1; i++)
//	{
//		for (int j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//
//
//
//int main()
//{
//	int arr[10] = { 9,4,1,2,3,6,7,5,8,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//init(arr, sz);
//	Bubble_sort(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}