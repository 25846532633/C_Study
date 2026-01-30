#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

//int my_atoi(const char* str)
//{
//	int num = 0;
//	while (*str != '\0' && *str != '\n')
//	{
//		num = num * 10 + (*str - '0');
//		str++;
//	}
//	return num;
//}

/*
	1.要提前移除所有的空白字符：isspace(*str)
	2.可能存在正负号的情况：所以要判断是否存在符号字符
	3.当存在整数和英文字符杂交的情况时：整数后面的字符完全忽略(a1234 - 0；12a34 - 12)
*/



enum State
{
	VAILD,
	INVAILD
}Sta = INVAILD;//创造变量默认为非法
int my_atoi(const char* str)
{
	assert(str);
	if (*str == '\0') //如果是0，直接返回
	{
		return 0;
	}
	while (isspace(*str))//跳过空白字符
	{
		str++;
	}
	int flag = 1;
	if (*str == '+')//正数
	{
		flag = 1;
		str++;
	}
	else if (*str == '-')//负数
	{
		flag = -1;
		str++;
	}
	long long ret = 0;
	while (*str != '\0')
	{
		if (isdigit(*str))//是否为数字
		{
			ret = ret * 10 + flag * (*str - '0');//减去字符0，才是数字0
			if (ret > INT_MAX || ret < INT_MIN)
			{
				return 0;
			}
		}
		else
		{
			return (int)ret;//强制类型转化为int（函数的返回值是int）
		}
		str++;
	}
	if (*str == '\0')
	{
		Sta = VAILD; //正常转换完了，到末尾的 \0
	}
	return (int)ret;




}

int main()
{
	char arr[20] = "a1234";
	int ret = my_atoi(arr);
	int ret2 = atoi(arr);
	printf("%d\n", ret2);
	if (Sta == VAILD)
	{
		printf("合法转换:%d\n", ret);
	}
	else if (Sta == INVAILD)
	{
		printf("非法转换:%d\n", ret);
	}
	return 0;
}

//int main()
//{
//	int i;
//	char buffer[256];
//	printf("Enter a number: ");
//	fgets(buffer, 256, stdin);
//	i = my_atoi(buffer);
//	printf("The value entered is %d. Its double is %d.\n", i, i * 2);
//	return 0;
//	return 0;
//}