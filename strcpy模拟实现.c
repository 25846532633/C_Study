#include <stdio.h>

char* my_strcpy(char* dst, const char* src)
{
	char* cp = dst;
	while (*dst++ = *src++);
	return dst;
}

size_t my_strlen(const char* str)
{
	const char* eos = str;
	while (*eos++);
	return eos - str - 1;//它会把\0也算进去，所以要-1
}


int main()
{
	char str[10]= "abcdefghi";
	char str2[10];
	my_strcpy(str2, str);
	printf("%s", str2);
	return 0;
}