#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int func(int k, int* a)
{
	int left = 0;int right = sizeof(a) - 1;
	printf("%d\n", right);
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (a[mid] > k)
		{
			right = mid - 1;
		}
		else if(a[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}


int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8 };
	int k = 0;
	scanf("%d", &k);//要查找哪个数
	int c = func(k,arr);
	printf("%d", c);
	return 0;
}