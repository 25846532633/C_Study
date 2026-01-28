#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");
//	fwrite(&a, 4, 1, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	//打开文件
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		perror("Fopen");
//		return 1;
//	}
//	//写文件
//	char ch = 0;
//	for (ch = 'a'; ch <= 'd'; ch++)
//	{
//		fputc(ch, pf);
//	}
//	//读文件
//	//int ch = 0;
//	///*ch = fgetc(pf);
//	//printf("%c ", ch);
//	//ch = fgetc(pf);
//	//printf("%c ", ch);
//	//ch = fgetc(pf);
//	//printf("%c ", ch);*/
//	//while ((ch = fgetc(pf)) != EOF)
//	//{
//	//	printf("%c ", ch);
//	//}
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	fputs("hello", pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	char arr[100] = { 0 };
//	fgets(arr, 100, pf);//从pf读取hello - 因为遇到换行符就结束
//	printf("%s", arr);
//
//	char arr2[100] = { 0 };
//	fgets(arr2, 100, pf);//从pf读取world
//	printf("%s", arr2);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct S
//{
//	float f;
//	char c;
//	int n;
//};

//int main()
//{
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	struct S s = { 3.14f,'w',100 };
//	//读文件
//	fscanf(pf, "%f-%c-%d", &(s.f), &(s.c), &(s.n));
//	printf("%f-%c-%d", s.f, s.c, s.n);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	struct S s = { 3.14f,'w',100 };
//	写文件
//	fprintf(pf, "%f-%c-%d", s.f, s.c, s.n);
//	
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("data.txt", "rb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//二进制写文件
//	//fwrite(arr, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), pf);
//	fread(arr, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), pf);
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL) {
//		perror("fopen");
//		return 1;
//	}
//	//读文件
//	int ch = fgetc(pf);
//	printf("%c\n", ch);//a
//
//	ch = fgetc(pf);
//	printf("%c\n", ch);//b
//
//	ch = fgetc(pf);
//	printf("%c\n", ch);//c
//
//	ch = fgetc(pf);
//	printf("%c\n", ch);//d
//
//	int pos = ftell(pf);
//	printf("pos = %d\n", pos);
//
//	//ch = fgetc(pf);
//	//printf("%c\n", ch);//e
//	//fseek(pf, -4,SEEK_CUR);//从当前位置倒走4步
//	//ch = fgetc(pf);
//	//printf("%c\n", ch);//a
//	//fseek(pf, 0, SEEK_SET);//设置指针在0处
//	//ch = fgetc(pf);
//	//printf("%c\n", ch);//a
//	//fseek(pf, -9, SEEK_END);//从文件尾部倒数9步
//	//ch = fgetc(pf);
//	//printf("%c\n", ch);//无
//	
//
//	rewind(pf);
//	int pos2 = ftell(pf);
//	printf("pos2 = %d\n", pos2);
//	ch = fgetc(pf);
//	printf("%c\n", ch);//a
//	
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int c; 
	FILE* fp = fopen("data.txt", "r");
	if(!fp) {
		perror("File opening failed");
		return EXIT_FAILURE;
	}
//fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF 
	while ((c = fgetc(fp)) != EOF)
    {
		putchar(c);
	}
	//判断是什么原因结束的
	if (ferror(fp))
		puts("I/O error when reading");
	else if (feof(fp))
		puts("End of file reached successfully");
	fclose(fp);
	fp = NULL;
	return 0;
}