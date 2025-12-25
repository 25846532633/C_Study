#include <stdio.h>

int main()
{
	char a[1000];
	//char的范围是-128~127
	int i = 0;
	//i的范围是0~4294967295
	for (i = 0; i < 1000; i++)
	{
		//当a[i] = -127之后
		//下一个a[i] = 128
		//再一直减少到0 = a[255]
		a[i] = -1 - i;
	}
	//strlen默认以'\0'结束，其本质就是0
	//所以到:127+128 = 255的时候，就停止计算大小
	printf("%d", strlen(a));
	return 0;
}	