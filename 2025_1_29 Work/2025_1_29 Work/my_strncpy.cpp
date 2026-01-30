//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <assert.h>
//#include <string.h>
//char* my_strncpy(char* dst, const char* src, size_t num)
//{
//	assert(dst && src);
//	char* temp = dst;
//	if (num == 0)
//		return temp;
//	while (*src != '\0' && num > 0)
//	{
//		*dst = *src;
//		src++; dst++;
//		num--;
//	}
//	*dst = '\0';//要自己添加结束符
//	return temp;
//	
//}
//char* my_strncat(char* dest, const char* src, size_t num)
//{
//	assert(dest);
//	if (src == NULL)
//	{
//		return dest;
//	}
//	char* temp = dest;
//	// 移动到dest的结尾
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (*src != '\0' && num > 0)
//	{
//		*dest = *src;
//		dest++; src++;
//		num--;
//	}
//	*dest = '\0';
//	return temp;
//}
//int main()
//{
//	//char str1[] = "To be or not to be";
//	//char str2[40]="hello world";
//	//char str3[] = "happy";
//	//my_strncpy(str2, str1, 4);
//	////strncpy(str3, NULL, sizeof(str2));
//	//printf("%s\n", str2);
//	char str1[20];
//	char str2[20];
//	strcpy(str1, "To be ");
//	strcpy(str2, "or not to be");
//	my_strncat(str1, str2, 6);
//	puts(str1);
//
//	return 0;
//}