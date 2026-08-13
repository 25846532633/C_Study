//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
////void* my_memcpy(void* des, void* src, int num)
////{
////	void* ret = des;
////	assert(des && src);
////	while (num--)
////	{
////		*(char*)des = *(char*)src;
////		des = (char*)des + 1;
////		src = (char*)src + 1;
////	}
////
////	return ret;
////}
//
//void* my_memmove(void* des, const void* src, size_t count)
//{
//	void* ret = des;
//	//1.目标区域在源区域之前或者目标区域完全在源区域之后
//	if (des <= src || 
//		(char*)des >= ((char*)src + count))
//	{
//		while (count--)
//		{
//			*(char*)des = *(char*)src;
//			des = (char*)des + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		des = (char*)des + count - 1;
//		src = (char*)src + count - 1;
//		while (count--)
//		{
//			*(char*)des = *(char*)src;
//			des = (char*)des - 1;
//			src = (char*)src - 1;
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	//int arr1[] = { 1,2,3,4,5 };
//	//int arr2[10] = { 0 };
//	//my_memcpy(arr2, arr1, 20);//将arr1后面的20个字节拷贝到arr2
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	printf("%d\n", arr2[i]);
//	//}
//	//return 0;
//
//	int arr1[10] = { 1,2,3,4,5 };
//	int arr2[10] = { 0 };
//	my_memmove(arr1, arr2, 12);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//
//	/*char str[] = "hello world";
//	memset(str, 'x', 6);
//	printf(str);*/
//
//
//	/*char buffer1[] = "abcds";
//	char buffer2[] = "sadas";
//	printf("%d", memcmp(buffer1, buffer2, 5));
//	return 0;*/
//}

//#include <iostream>
//using namespace std;
//
//class Date
//{
//public:
//
//	Date(int year, int month, int day)
//		:_year(year),
//		_month(month),
//		_day(day)
//	{}
//
//	bool operator<(const Date& d)
//	{
//		return _year < d._year &&
//			_month < d._month &&
//			_day < d._day;
//	}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//
//template<class T>
//bool Less(T left, T right)
//{
//	cout << "bool Less(T left, T right)" << endl;
//	return left < right;
//}
//
//template<>
//bool Less(Date* d1, Date* d2)
//{
//	cout << "bool Less(Date* d1, Date* d2)" << endl;
//	return *left < *right;
//}
#include <iostream>
using namespace std;

template<class T1, class T2>
class Data
{
public:
	Data() { cout << "①" << endl; }
};

template<>
class Data<int, char>
{
public:
	Data() { cout << "②" << endl; }
};

template<class T1>
class Data<T1, char>
{
public:
	Data() { cout << "③" << endl; }
};

template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "④" << endl; }
};
int main()
{
	Data<int, double> a;//①
	Data<int, char> b;//②
	Data<double, char> c;//③
	Data<int*, double*> d;//④
	Data<int*, double> e;//①

	return 0;
}