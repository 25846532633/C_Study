////#include <stdio.h>
////#include <stddef.h>
////struct S1
////{
////	char c1;
////	int i;
////	char c2;
////};
////
////struct S4
////{
////	char c1;
////	struct S1 s1;
////	double d;
////};
////
////int main()
////{
////	printf("%d\n", sizeof(struct S1));
////	printf("%d\n", sizeof(struct S4));
////	printf("%d\n", offsetof(struct S4,s1));
////	printf("%d", offsetof(struct S4, d));
////	return 0;
////}
//
//#include <stdio.h>
//#include <stddef.h>
//#pragma pack(1)//设置默认对齐数为1
//struct S
//{
//	char c1;//0
//	int i;//1~4
//	char c2;//5
//};
//#pragma pack()//取消设置的对齐数，还原为默认
//
//int main()
//{
//	//输出的结果是什么？
//	printf("%d\n", sizeof(struct S));
//	printf("%d\n", offsetof(struct S, i));
//	return 0;
//}