//#define NDEBUG
//#include <stdio.h>
//#include <assert.h>
////#include <assert.h>
////int main()
////{
////	int* p = NULL;
////	//assert(p != NULL);
////	return 0;
////}
//
////int my_strlen(const char* str)
////{
////	int count = 0;
////	assert(str);
////	while (*str)
////	{
////		count++;
////		str++;
////	}
////	return count;
////}
////
////int main()
////{
////	int len = my_strlen("abc");
////	printf("%d", len);
////	return 0;
////}
//
////int main()
////{
////	int arr[10] = { 0 };
////	int sz = sizeof(arr) / sizeof(arr[0]);
////	int* p = arr;
////	for (int i = 0; i < sz; i++)
////	{
////		printf("%d ", *(p + i));
////	}
////	return 0;
////}
//
//#include <stdio.h>
////void test(int arr[])
////{
////	int sz2 = sizeof(arr) / sizeof(arr[0]);
////	printf("sz2 = %d\n", sz2);
////}
////int main()
////{
////	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
////	int sz1 = sizeof(arr) / sizeof(arr[0]);
////	printf("sz1 = %d\n", sz1);
////	test(arr);
////	return 0;
////}
//
////int main()
////{
////	int arr1[] = { 1,2,3,4,5 };
////	int arr2[] = { 2,3,4,5,6 };
////	int arr3[] = { 3,4,5,6,7 };
////	//数组名是数组首元素的地址，类型是int*的，就可以存放在parr数组中
////	int* parr[3] = { arr1, arr2, arr3 };
////	int i = 0;
////	int j = 0;
////	for (i = 0; i < 3; i++)
////	{
////		for (j = 0; j < 5; j++)
////		{
////			printf("%d ", parr[i][j]);
////		}
////		printf("\n");
////	}
////	return 0;
////}
//
////#include <stdio.h>
////int main()
////{
////	char str1[] = "hello bit.";
////	char str2[] = "hello bit.";
////	const char* str3 = "hello bit.";
////	const char* str4 = "hello bit.";
////	if (str1 == str2)
////		printf("str1 and str2 are same\n");
////	else
////		printf("str1 and str2 are not same\n");
////	if (str3 == str4)
////		printf("str3 and str4 are same\n");
////	else
////		printf("str3 and str4 are not same\n");
////	return 0;
////}
//
//
////int Add(int x, int y)
////{
////	return x + y;
////}
////
////int main()
////{
////	printf("%p", &Add);
////	return 0;
////}
//
//#include <stdio.h>
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int (*pf3)(int, int) = Add;
//	printf("%d\n", (*pf3)(2, 3));
//	printf("%d\n", pf3(3, 5));
//	return 0;
//}