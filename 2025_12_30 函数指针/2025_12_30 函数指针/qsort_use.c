#include <stdio.h>
#include <stdlib.h>

//升序
int cmp_int(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

//升序
int cmp_int2(const void* a, const void* b)
{
	return *(int*)b - *(int*)a;
}

//浮点数不能直接相减返回int
int cmp_double(const void* a, const void* b)
{
	double fa = *(double*)a;
	double fb = *(double*)b;
	if (fa < fb) return -1;
	if (fa > fb) return 1;
	return 0;
}

//字符数组排序
int cmp_char(const void* a, const void* b)
{
	return *(char*)a - *(char*)b;
}
//字符串指针数组排序
int cmp_string(const void* a, const void* b)
{
	return strcmp(*(char**)b, *(char**)a);
}

typedef struct {
	char name[50];
	int age;
	float score;
} Student;

//按年龄升序
int cmp_by_age(const void* a, const void* b)
{
	return ((Student*)a)->age - ((Student*)b)->age;
}
//按分数降序
int cmp_by_score(const void* a, const void* b)
{
	float diff = ((Student*)b)->score - ((Student*)a)->score;
	if (diff > 0) return 1;
	if (diff < 0) return -1;
	return 0;
}


int main()
{
	int arr[] = { 5,2,3,1,4 };
	qsort(arr, sizeof(arr) / sizeof(arr[0]), 4, cmp_int2);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	double farr[] = { 3.14,2.71,2.45,4.52 };
	qsort(farr, sizeof(farr) / sizeof(farr[0]), 8, cmp_double);
	for (int i = 0; i < 4; i++)
	{
		printf("%f ", farr[i]);
	}
	printf("\n");

	char* names[] = { "Alice", "Bob", "Charlie", "David", "Eve" };
	qsort(names, 5, sizeof(char*), cmp_string);
	for (int i = 0; i < 5; i++)
	{
		printf("%s ", names[i]);
	}
	printf("\n"); 

	char str[] = "algorithm";
	qsort(str, strlen(str), sizeof(char), cmp_char);
	for (int i = 0; i < sizeof(str)-1; i++)
	{
		printf("%c ", str[i]);
	}
	printf("\n");


	Student student[] = { {"zhangsan",20,98.5},{"Cao",30,45},
		{"Ineraskl",24,85} };
	qsort(student, sizeof(student) / sizeof(student[0]), sizeof(Student), cmp_by_age);
	for (int i = 0; i < sizeof(student) / sizeof(student[0]); i++)
	{
		printf("%s %d %f\n", student[i].name, student[i].age, student[i].score);
	}
	printf("\n");
	return 0;
}