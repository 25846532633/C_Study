#define _CRT_SECURE_NO_WARNINGS	
#include <string.h>
#include <stdio.h>
#include <assert.h>
//
////int my_strlen(const char* str)
////{
////	assert(str != NULL);
////	char* cp = str;
////	while (*str++ != '\0');
////	return str - cp - 1;
////}
////int my_strlen(const char* str)
////{
////	int count = 0;
////	assert(str);
////	while (*str)
////	{
////		str++;
////		count++;
////	}
////	return count;
////}
////int my_strlen(const char* str)
////{
////	assert(str);
////	if (!*str)
////		return 0;
////	else
////		return 1 + my_strlen(str + 1);
////}
//
//
////int main()
////{
////	const char* str1 = "abcdef";
////	const char* str2 = "bbb";
////	printf("%d %d\n", strlen(str1), strlen(str2));
////	printf("%d %d", my_strlen(str1), my_strlen(str2));
////	return 0;
////}
////char* my_strcpy(char* str, const char* src)
////{
////	assert(str && src);
////	char* ret = str;
////	while (*str++ = *src++);
////	return ret;
////}
//
////char* my_strcat(char* dest, const char* src)
////{
////	assert(dest && src);
////	char* ret = dest;
////	while (*++dest);
////	while (*dest++ = *src++);
////	return ret;
////}
////
////
////int main()
////{
////	/*char str1[] = "Sample string";
////	char str2[40];
////	char* ret = my_strcpy(str2, str1);
////	printf("%s", ret);
////	return 0;*/
////
////	char str[80];
////	strcpy(str, "ehese ");
////	printf("%s\n", str);
////	char* ret = my_strcat(str, "strings");
////	printf("%s\n", ret);
////	/*printf("%s\n", str);
////	strcat(str, "are ");
////	printf("%s\n", str);*/
////	return 0;
////}
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	int ret = 0;
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//}
//
//


//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')//str1结束 - 说明二者相同
//			return 0;
//		str1++; str2++;
//	}
//	return *str1 - *str2;//二者的ASCII码差值
//}

int my_strcmp(const char* src, const char* dst)
{
	int ret = 0;
	assert(src != NULL);
	assert(dst != NULL);
	while (!(ret = *(unsigned char*)src - *(unsigned char*)dst) & *dst)
	{
		dst++; src++;
	}
	if (ret < 0)
		return -1;
	else if (ret > 0)
		return 1;
	else
		return 0;
}


char* my_strstr(char* dest, const char* src)
{
	char* cp = dest;
	char* str1, *str2;

	while (*cp)
	{
		str1 = cp; str2 = src;
		while (*str1 && *str2 && *str1 == *str2)
		{
			*str1++; *str2++;
		}
		if (!*str2)//找到对应子串
			return cp;
		cp++;
	}
	return NULL;
}

char* my_strcat(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	while (*++dest);
	while (*dest++ = *src++);
	return ret;
}

int main()
{
	char arr1[20] = "abced";
	char arr2[] = "abcedl";
	char* test = my_strcat(arr1, arr2);
	printf("%d\n",my_strcmp(arr1, arr2));//-1
	printf("%s\n", my_strstr(arr1, "bce"));
	printf("%s\n", test);
	return 0;
}

