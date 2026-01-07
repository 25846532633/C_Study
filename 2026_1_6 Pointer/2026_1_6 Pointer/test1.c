//#include <stdio.h>
////int main()
////{
////	int a = 10;
////	int* pc = &a;
////	printf("%p\n", pc);
////	printf("%d", *pc);
////	return 0;
////}
////int main()
////{
////	printf("%zd\n", sizeof(char*));
////	printf("%zd\n", sizeof(short*));
////	printf("%zd\n", sizeof(int*));
////	printf("%zd\n", sizeof(double*));
////	return 0;
////}
////int main()
////{
////	/*int n = 0x11223344;
////	int* pi = &n;
////	char* pc = (char*)&n;
////	printf("%d\n", *pi);
////	printf("%d", *pc);
////	return 0;*/
////}
////int main()
////{
////	int n = 10;
////	char* pc = (char*)&n;
////	int* pi = &n;
////	printf("%p\n", &n);
////	printf("%p\n", pc);
////	printf("%p\n", pc + 1);
////	printf("%p\n", pi);
////	printf("%p\n", pi + 1);
////	return  0;
////}
//
//////指针+ -整数
////int main()
////{
////	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
////	int* p = &arr[0];
////	int i = 0;
////	int sz = sizeof(arr) / sizeof(arr[0]);
////	for (i = 0; i < sz; i++)
////	{
////		printf("%d ", *(p + i));
////	}
////	return 0;
////}
//
////int my_strlen(char* s)
////{
////	char* p = s;
////	while (*p != '\0')
////		p++;
////	return p - s;
////}
////
////int main()
////{
////	printf("%d\n", my_strlen("abc"));
////	return 0;
////}
//
//
////指针的关系运算
//
//#include <stdio.h>
//int main()
//{
//	const int n = 10;
//	printf("%d\n", n);
//	int* p = &n;
//	*p = 100;
//	printf("%d", n);
//	return 0;
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = &arr[0];
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p++) = i;
//	}
//	//此时p已经越界了，可以把p置为		NULL		
//	p = NULL;
//	//下次使⽤的时候，判断不为NULL的时候再使⽤
//	//...
//	p = &arr[0];//重新让p获得地址
//	if (p != NULL) //判断
//	{
//		//...
//	}
//	return 0;
//}