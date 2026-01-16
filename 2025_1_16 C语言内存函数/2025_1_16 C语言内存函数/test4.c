#include <stdio.h>
#include <string.h>
#include <assert.h>


int main()
{
	char buffer1[] = "DWASDLL";
	char buffer2[] = "DWASDLH";
	printf("%d\n", sizeof(buffer1));
	int n = memcmp(buffer1, buffer2, sizeof(buffer1));
	printf("%d\n", n);
	int m = memcmp(buffer1, buffer2, sizeof(buffer1)-2);
	printf("%d\n", m);
	return 0;
}