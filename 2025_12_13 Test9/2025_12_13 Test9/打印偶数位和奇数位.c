//#include <stdio.h>
//
//
//int main()
//{
//	int n = 10;
//	int count = 0;
//    printf("偶数位: ");
//    // 打印偶数位：30, 28, 26, ..., 0
//    for (int i = 30; i >= 0; i -= 2) {
//        printf("%d ", (n >> i) & 1);
//    }
//
//    printf("\n奇数位: ");
//    // 打印奇数位：31, 29, 27, ..., 1
//    for (int i = 31; i >= 1; i -= 2) {
//        printf("%d ", (n >> i) & 1);
//    }
//    printf("\n");
//	return 0;
//}