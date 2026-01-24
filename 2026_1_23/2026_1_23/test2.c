#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct st
{
	int i;
	int a[0];
}st;

int main()
{
	printf("%d", sizeof(st));
	return 0;
}