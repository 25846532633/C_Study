#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isRotatedString(const char* s1, const char* s2) {
    // 检查空指针
    if (s1 == NULL || s2 == NULL) {
        return 0;
    }

    // 长度不同肯定不是旋转字符串
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    if (len1 != len2) {
        return 0;
    }

    // 特殊情况：两个空字符串
    if (len1 == 0) {
        return 1;
    }

    // 创建拼接字符串：s1 + s1
    char* doubled = (char*)malloc(2 * len1 + 1);
    if (doubled == NULL) {
        return 0; // 内存分配失败
    }

    strcpy(doubled, s1);
    strcat(doubled, s1);

    // 检查s2是否是doubled的子串
    int result = (strstr(doubled, s2) != NULL);

    free(doubled);
    return result;
}

int main() {
    // 测试用例
    char s1[] = "AABCD";
    char s2[] = "BCDAA";
    char s3[] = "ABCD";
    char s4[] = "ACBD";

    printf("s1 = %s, s2 = %s\n", s1, s2);
    printf("是否为旋转字符串: %d\n", isRotatedString(s1, s2)); // 应返回1

    printf("\ns3 = %s, s4 = %s\n", s3, s4);
    printf("是否为旋转字符串: %d\n", isRotatedString(s3, s4)); // 应返回0

    // 更多测试
    printf("\n更多测试:\n");
    printf("相同字符串: %d\n", isRotatedString("hello", "hello")); // 1
    printf("空字符串: %d\n", isRotatedString("", "")); // 1
    printf("长度不同: %d\n", isRotatedString("abc", "abcd")); // 0

    return 0;
}