//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//void* my_memcpy(void* destination, const void* source, size_t num)
//{
//	void* ret = destination;//保留起始位置
//	assert(destination && source);//确保指针非空
//	while (num--)
//	{
//		*(char*)destination = *(char*)source;
//		destination = (char*)destination + 1;//记住void*指针要转换为具体类型后才能运算
//		source = (char*)source + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[10] = { 0 };
//	my_memcpy(arr2, arr1, 20);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}