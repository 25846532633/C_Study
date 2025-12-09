#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//int main()
//{
//	char arr4[4] = "abc";
//	char arr5[3] = { 'a','b','c' };
//	printf("%d\n", sizeof(arr5));
//	printf("%d", strlen(arr5));
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int sz[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	/*for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &sz[i]);
//	}*/
//	printf("sizeof(sz) = %d\n", sizeof(sz));
//	printf("sizeof(sz[0]) = %d", sizeof(sz[0]));
//	/*for (int i = 0; i < 10; i++)
//	{
//		printf("&sz[%d] = %p\n", sz[i],&sz[i]);
//	}*/
//	return 0;
//}

#include <stdio.h>
int main()
{
	int arr[3][5] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
		}
	}
	return 0;
}