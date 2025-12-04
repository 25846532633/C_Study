//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int cnt = 0;
//	do {
//		cnt++;
//		n /= 10;
//	} while (n);
//	printf("%d", cnt);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//		i = i + 1;
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int i = 1;
//	do
//	{
//		if (i == 5)
//			continue;
//		printf("%d", i);
//		i = i + 1;
//	} while (i <= 10);
//	return 0;
//}
#include <stdio.h>
int main()
{
	printf("hehe\n");
	goto next;
	printf("haha\n");
next:
	printf("跳过了haha的打印\n");
	return 0;
}