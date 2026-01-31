#include <stdio.h>

//int main()
//{
//	printf("file:%s\n", __FILE__);
//	printf("line:%d\n", __LINE__);
//	printf("date:%s\n", __DATE__);
//	printf("time:%d\n", __TIME__);
//	//printf("stdc:%d\n", __STDC__); - VSÃ»¶¨Òå
//	return 0;
//}

//#define MAX(a,b) ((a)>(b) ? (a):(b))
//
//int main()
//{
//	int x = 5;
//	int y = 8;
//	int z = MAX(x++, y++);
//	printf("%d %d %d", x, y, z);
//	return 0;
//}

#define PRINT(n) printf("the value of "#n" is %d",n);
#define GENRIC_MAX(type)\
	type type##_max(type x,type y){\
		return (x > y ? x : y);\
	}

GENRIC_MAX(int) //
int main()
{
	/*int n = 10;
	PRINT(n);*/
	int a = int_max(2, 3);
	printf("%d", a);
	return 0;
}