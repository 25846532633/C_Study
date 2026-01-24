#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



//int main()
//{
//	int* p = (int*)malloc(sizeof(int) * 10);
//	if (p == NULL) //需要判断当前指针是否为空指针
//	{
//		perror("malloc");
//		return;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	//用完后要释放
//	free(p);
//	p = NULL;//避免被再次访问，如果再次访问会崩溃
//	return 0;
//}

//int main()
//{
//	int* p = calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		perror("calloc");
//		return;
//	}
//	/*for (int i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}*/
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//	//空间不够，希望调整空间为20个整形
//	int* ptr = (int*)realloc(p, 20 * sizeof(int));
//	if (ptr != NULL)
//	{
//		p = ptr;//开辟成功后，将开辟的地址赋给原地址
//	}
//	for (int i = 0; i < 20; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	//释放
//	free(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	//这种方式就等价于malloc(5*sizeof(int))
//	int* p = (int*)realloc(NULL, 20);//malloc(100);
//	if (p == NULL)
//	{
//		perror("realloc");
//		return;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		*(p + i) = i;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}