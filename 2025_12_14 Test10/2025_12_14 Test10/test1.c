#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int x = a++;
//	printf("%d", x);
//	int y = a--;
//	printf("%d", y);
//	return 0;
//}


//int main()
//{
//	int b = 0;
//	int y = --b;
//	printf("%d", y);
//	int z = ++b;
//	printf("%d", z);
//	return 0;
//}

//int main()
//{
//	
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof a);
//	printf("%d\n", sizeof(int));
//	//printf("%d\n", sizeof int);
//	int a = 10;
//	int b = 0, c = 0;
//	printf("%d\n", sizeof(a = b + c));
//	printf("%d\n", a);
//	return 0;
//}

#include <stdio.h>
int main()
{
	int i = 0, a = 0, b = 2, c = 3, d = 4;
	//i = a++ && ++b && d++;
	i = a++||++b||d++;
	printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
	return 0;
}