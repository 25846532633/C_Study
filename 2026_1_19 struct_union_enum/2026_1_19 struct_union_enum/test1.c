//#include <stdio.h>
//
//
//struct Student 
//{
//	char name[20];
//	int age;
//	char sex[20];
//	char sno[20];
//}P1 = {"cao",18, "男","2010100"};//1.定义了变量P1
//
//struct Node
//{
//	int num;
//	struct Student s1;
//};
//
//struct
//{
//	int a;
//	char b;
//	double c;
//}x;
//
//struct
//{
//	int a;
//	char b;
//	double c;
//}*p;
//
//struct Node
//{
//	int data;
//	struct Node next;
//};
//
//int main()
//{
//	x.a = 10; x.b = 's'; x.c = 10.22;
//	printf("%d %c %lf", x.a, x.b, x.c);
//	return 0;
//}
//
////int main()
////{
////	//2.正常定义
////	struct Student P2 = { "张三",20,"男","20231012" };
////	//3.乱序初始化
////	struct Student P3 = { .age = 20,.name = "kli",.sno = "2011909",.sex = "男" };
////	//4.嵌套
////	struct Node P4 = { 100,{"张四",22,"男","20231114"} };
////
////	//打印：
////	printf("name: %s\n", P1.name);
////	printf("age : %d\n", P1.age);
////	printf("sex : %s\n", P1.sex);
////	printf("id  : %s\n", P1.sno);
////
////	return 0;
////}