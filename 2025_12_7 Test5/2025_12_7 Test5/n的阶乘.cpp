//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//
//int Facn1(int n)
//{
//	if (n == 1)
//		return 1;
//	return n * Facn1(n - 1);
//}
//
//int Facn2(int n)
//{
//	int ret = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int n1 = Facn1(n);
//	int n2 = Facn2(n);
//	printf("%d %d", n1, n2);
//	return 0;
//}