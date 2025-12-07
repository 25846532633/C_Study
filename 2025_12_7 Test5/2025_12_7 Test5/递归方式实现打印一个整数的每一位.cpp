#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void Print(int n)
{
	if (n == 0)
		return;
	printf("%d ", n % 10);
	Print(n / 10);
	
	
}



int main()
{
	int n = 1234;
	Print(n);
	return 0;
}