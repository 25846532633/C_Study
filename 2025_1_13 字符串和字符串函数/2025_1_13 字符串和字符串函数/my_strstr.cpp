//#define _CRT_SECURE_NO_WARNINGS	
//#include <string.h>
//#include <stdio.h>
//#include <assert.h>
//
//
//char* my_strstr(const char* str1, const char* str2)
//{
//	char* cp = (char*)str1;
//	char* s1,* s2;
//
//	if (!*str2) //str2为空串
//		return ((char*)str1);
//
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = (char*)str2;
//
//		//匹配子串中
//		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')//匹配子串成功
//			return cp;
//		cp++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char str[] = "This is a sad";
//	char* pch = my_strstr(str, "a");
//	printf("%s\n", pch);//a sad
//	strncpy(pch, "happy", 5);//This is happy
//	printf("%s\n", str);
//	strncpy(pch, "happy", 4);//This is happd
//	return 0;
//}