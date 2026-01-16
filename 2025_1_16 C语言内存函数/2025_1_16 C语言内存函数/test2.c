//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//void* my_memmove(void* dst, const void* src, size_t count)
//{
//	void* ret = dst;//保留起始位置
//	if (dst <= src || (char*)dst >= ((char*)src + count)) {
//		while (count--)
//		{
//			*(char*)dst = *(char*)src;
//			dst = (char*)dst + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else//从后往前复制
//	{
//		dst = (char*)dst + count - 1;
//		src = (char*)src + count - 1;
//		while (count--)
//		{
//			*(char*)dst = *(char*)src;
//			dst = (char*)dst - 1;
//			src = (char*)src - 1;
//		}
//	}
//	return ret;
//}
//
//
//int main()
//{
//	int arr1[20] = { 1,2,3,4,5 };
//	int arr2[10] = {6,7,8,9,10};
//	my_memmove(arr1+3, arr1, 20);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}