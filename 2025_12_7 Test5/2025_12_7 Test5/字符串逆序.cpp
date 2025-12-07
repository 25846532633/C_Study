////#define _CRT_SECURE_NO_WARNINGS
////#include <stdio.h>
////
////void reverse_string(char str[])
////{
////    if (*str == '\0' || *(str + 1) == '\0') {
////        return;
////    }
////    char temp = *str;// 保存当前字符（最左边的字符）
////    char* end = str;// 找到字符串末尾的'\0'前一个字符（最右边的字符）
////    while (*(end + 1) != '\0') {
////        end++;
////    }
////    *str = *end;    // 把最右边的字符放到最左边
////    *end = '\0';    // 在原来最右边的位置放入'\0'，缩小问题规模
////    reverse_string(str + 1);    // 递归处理中间部分（去掉首尾字符的子串）
////    *end = temp;    // 恢复最右边的字符为原来的最左边字符
//}
//
//int My_strlen(char arr[])
//{
//    if (*arr == '\0')
//        return 0;
//    else
//        return 1 + My_strlen(arr + 1);
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int sz = sizeof(arr) / sizeof(arr[0]) - 1;
//	/*reverse_string(arr);
//    printf("%s", arr);*/
//    int len = My_strlen(arr);
//    printf("%d %d", len, sz);
//	return 0;
//}