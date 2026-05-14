#include <iostream>
#include <assert.h>
#include <string>
using namespace std;


//namespace bite
//{
//	template<class T, size_t N =10>
//	class array
//	{
//	public:
//		T& operator[](size_t index)
//		{
//			assert(index < N);
//			return _array[index];
//		}
//
//		size_t size() const
//		{
//			return _size;
//		}
//		bool empty() const
//		{
//			return 0 == _size;
//		}
//	private:
//		T _array[N];
//		size_t _size;
//	};
//}
//
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//
//
////要有特化版本前需要先有一个通用模板
//template<> 
//bool Less<int*>(int* left, int* right)
//{
//	return *left < *right;
//}
//
////函数模板不支持偏特化- bool Less(int* left, T*right)
//
//
//int main()
//{
//	/*bite::array<int, 10> a;
//	cout << a[0] << endl;
//	cout << sizeof(a) << endl;*/
//
//	int* a = new int(3);
//	int* b = new int(4);
//
//	cout << Less(1, 2) << endl;
//	cout << Less(a, b) << endl;
//	return 0;
//}

template<class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

//全特化
template<>
class Data<int, char>
{
	friend ostream& operator<<(ostream& out, const Data<int, char>& d);
public:
	Data(int _a, char _c)
		:a1(_a),
		a2(_c)
	{
		cout << "Data<int,char>" << endl;
	}

	Data& operator()()
	{
		return *this;
	}
private:
	int a1;
	char a2;

};

ostream& operator<<(ostream& out, const Data<int,char>& d)
{
	out << d.a1 << "-" << d.a2;
	return out;
}

//偏特化
template<class T1>
class Data<char, T1>
{
public:
	Data()
	{
		cout << "Data<char,T1>" << endl;
	}
};

template<class T1>
ostream& operator<<(ostream& out, const Data<char, T1>& a)
{
	cout << "happy day" << endl;
	return out;
}

template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
};

int main()
{
	Data<int, int>d1;
	Data<int, char>d2(10,'c');
	cout << d2 << endl;
	Data<char, int>d3;
	cout << d3 << endl;
	Data<int*, string*> d5;
}


