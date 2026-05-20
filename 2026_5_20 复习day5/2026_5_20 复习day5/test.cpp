#include <iostream>
#include <assert.h>
using namespace std;
//
//template<class T>
//void Swap(T& left, T& right)
//{
//	cout << "Swap(T& left, T& right)" << endl;
//	T temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(int left, int right)
//{
//	cout << "Swap(int left, int right)" << endl;
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//
//int main()
//{
//	int a = 10, b = 20;
//	Swap(a, b);
//	Swap<int>(a, b);//显式实例化时，直接调用模板函数
//	return 0;
//}


//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Swap(a1, a2);
//	cout << a1 << " " << a2 << endl;
//	Swap(d1, d2);
//	cout << d1 << " " << d2 << endl;
//	Swap<double>(d1, d2);
//	cout << d1 << " " << d2 << endl;//显式实例化
//	/*Swap(a1, d1);
//	cout << a1 << " " << d1 << endl;
//	Swap(a1, d2);
//	cout << a1 << " " << d2 << endl;*/
//	
//	return 0;
//}


//类模板内的成员函数如果在类外定义：1.要在类内声明 2.要在类外加模板参数列表
//template<class T>
//class Vector
//{
//public:
//    Vector(size_t capacity = 10);
//    ~Vector();
//
//private:
//    T* _pData;
//    size_t _size;
//    size_t _capacity;
//};
//
//template<class T>
//Vector<T>::Vector(size_t capacity)
//    :_pData(new T[capacity]),
//    _size(0),
//    _capacity(capacity)
//{}
//
//template<class T>
//Vector<T>::~Vector()
//{
//    delete[] _pData;
//    _pData = nullptr;
//    _size = _capacity = 0;
//}

//template<class T,size_t N = 10>
//class Tempo
//{
//public:
//	T& operator[](size_t index)
//	{
//		assert(index < size);
//		return _array[index];
//	}
//
//private:
//	T _array[N];
//	size_t size;
//};
//
//int main()
//{
//	Tempo<int, 20> d1;
//	Tempo<int, 21> d4;
//	Tempo<char, 21> d2;
//	Tempo<bool, 22> d3;
//	Tempo<size_t, 24> d4;
//}

//template<class T>
//bool Less(T left, T right) {
//    return left < right;
//}
//
//template<>
//bool Less(int* left, int* right)
//{
//    return *left < *right;
//}
//
//int main()
//{
//    cout << Less(1, 2) << endl;   
//
//    int a = 0, b = 2;
//    int* p1 = &a, * p2 = &b;
//    cout << Less(p1, p2) << endl;
//    return 0;
//}

// 通用模板
template<class T1, class T2>
class Data
{
public:
    Data() { cout << "Data<T1, T2>" << endl; }
private:
    T1 _d1;
    T2 _d2;
};

// 全特化：当 T1 = int, T2 = char 时
template<>
class Data<int, char>
{
public:
    Data() { cout << "Data<int, char>" << endl; }
};

//参数个数的偏特化
template<class T1>
class Data<T1, char>
{
public:
    Data() { cout << "Data<T1, char>" << endl; }
};

//参数类型上的偏特化 - 指针
template<class T1,class T2>
class Data<T1*, T2*>
{
public:
    Data() { cout << "Data<T1*, T2*>" << endl; }
};

template<class T1,class T2>
class Data<T1&,T2*>
{
public:
    Data(){ cout << "Data<T1&,T2*>" << endl; }
private:
    static int a;
};
template<class T1,class T2>
int Data<T1&,T2*>::a = 0;

int main()
{
    Data<double, double>d1;
    Data<int, char>d2;
    Data<double, char>d3;
    Data<int*, double*>d4;
    Data<int*, char>d5;
    Data<int&, double*>d6;
    //Data<int&, double>d7;
}