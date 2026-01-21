#include <stdio.h>


//union Un
//{
//	char c;
//	int i;
//};
//
//int main()
//{
//	union Un un = { 0 };
//	//printf("%d\n", sizeof(un));
//	printf("%p\n", &(un.i));
//	printf("%p\n", &(un.c));
//	printf("%p\n", &un);
//	return 0;
//}

#include <stdio.h>
union Un1
{
	char c[5];
	int i;
};
union Un2
{
	short c[7];
	int i;
};
int main()
{
	//下面输出的结果是什么？ 
	printf("%d\n", sizeof(union Un1));
	printf("%d\n", sizeof(union Un2));
	return 0;
}