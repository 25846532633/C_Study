#define _CRT_SECURE_NO_WARNINGS

//int main()
//{
//	/*int arr[] = { 1,2,3,4,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	return 0;*/
//	int a = 0x11223344;
//	char* pc = (char*)&a;
//	*pc = 0;
//	printf("%x\n", a);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    unsigned long pulArray[] = { 6,7,8,9,10 };
//    unsigned long* pulPtr;
//    pulPtr = pulArray;
//    *(pulPtr + 3) += 3;
//    printf("%d,%d\n", *pulPtr, *(pulPtr + 3));
//    return 0;
//}

//const int Len = 10000;
//int main()
//{
//	char str[10000];
//	fgets(str, Len, stdin);
//	int sz = strlen(str);
//	for (int i = sz - 1; i >= 0; i--)
//	{
//		printf("%c", str[i]);
//	}
//	//printf("%s", str);
//	return 0;
//}

//int main()
//{
//	int n = 7;
//	for (int i = 0; i < n; i++)
//	{
//		int space = n - i - 1;//空格
//		int star = 2 * i + 1;
//		for (int i = 0; i < space; i++) printf(" ");
//		for (int i = 0; i < star; i++) printf("*");
//		printf("\n");
//	}
//	for (int i = n-1; i > 0; i--)
//	{
//		int space = n-i;//空格
//		int star = 2 * i - 1;
//		for (int i = 0; i < space; i++) printf(" ");
//		for (int i = 0; i < star; i++) printf("*");
//		printf("\n");
//	}
//	return 0;
//}

#include <stdio.h>

int main() {
    int a;
    printf("请输入一个数字a：");
    scanf("%d", &a);

    // 对于5项来说，直接乘以12345即可
    int sum = a * 12345;

    printf("Sn = %d\n", sum);
    return 0;
}