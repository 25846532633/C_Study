#define _CRT_SECURE_NO_WARNINGS	
#include <string.h>
#include <stdio.h>
#include <assert.h>

//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//	char* cp = str;
//	while (*str++ != '\0');
//	return str - cp - 1;
//}
//int my_strlen(const char* str)
//{
//	int count = 0;
//	assert(str);
//	while (*str)
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
//int my_strlen(const char* str)
//{
//	assert(str);
//	if (!*str)
//		return 0;
//	else
//		return 1 + my_strlen(str + 1);
//}


//int main()
//{
//	const char* str1 = "abcdef";
//	const char* str2 = "bbb";
//	printf("%d %d\n", strlen(str1), strlen(str2));
//	printf("%d %d", my_strlen(str1), my_strlen(str2));
//	return 0;
//}
//char* my_strcpy(char* str, const char* src)
//{
//	assert(str && src);
//	char* ret = str;
//	while (*str++ = *src++);
//	return ret;
//}

//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*++dest);
//	while (*dest++ = *src++);
//	return ret;
//}
//
//
//int main()
//{
//	/*char str1[] = "Sample string";
//	char str2[40];
//	char* ret = my_strcpy(str2, str1);
//	printf("%s", ret);
//	return 0;*/
//
//	char str[80];
//	strcpy(str, "ehese ");
//	printf("%s\n", str);
//	char* ret = my_strcat(str, "strings");
//	printf("%s\n", ret);
//	/*printf("%s\n", str);
//	strcat(str, "are ");
//	printf("%s\n", str);*/
//	return 0;
//}

int my_strcmp(const char* str1, const char* str2)
{
	int ret = 0;
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	return *str1 - *str2;
}


int main()
{
	char arr1[] = "abced";
	char arr2[] = "abcedl";
	printf("%d",my_strcmp(arr1, arr2));//-1
	return 0;
}