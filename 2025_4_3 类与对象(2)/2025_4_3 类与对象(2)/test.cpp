#include <iostream>
using namespace std;

//class Time
//{
//public:
//
//	Time()
//	{
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//
//	int _hour;
//	int _minute;
//	int _second;
//};


//class Date
//{
//public:
//
//	////构造函数
//	//Date(int year,int month,int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	Date()
//	{
//		_year = 0;
//		_month = 0;
//		_day = 0;
//	}
//
//	///*Date(int year = 100, int month = 2, int day = 20)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//*/}
//
//	~Date()
//	{
//		_year = 0;
//		_month = 0;
//		_day = 0;
//		cout << "~Date" << endl;
//	}
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << "/" << endl;
//		//cout << _t._hour << "/" << _t._minute << "/" << _t._second << "/" << endl;
//	}
//
//	int _year;
//	int _month;
//	int _day;
//	//Time _t;
//};
//
//int main()
//{
//	//Date d1(2025, 2, 20);
//	Date d2;
//
//	//d1.Print();
//	d2.Print();
//	return 0;
//}

//class Time
//{
//public:
//
//	Time()
//	{
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//
//class Date
//{
//public:
//
//	Date()
//	{
//		_year = 0;
//		_month = 0;
//		_day = 0;
//	}
//
//	~Date()
//	{
//		_year = 0;
//		_month = 0;
//		_day = 0;
//		cout << "~Date" << endl;
//	}
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << "/" << endl;
//		//cout << _t._hour << "/" << _t._minute << "/" << _t._second << "/" << endl;
//	}
//
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};


//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		_array = (int*)malloc(sizeof(int) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	void Push(int data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	bool Empty()
//	{
//		return _size == 0;
//	}
//
//	int Top()
//	{
//		return _array[_size - 1];
//	}
//
//	void Pop()
//	{
//		//..
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//		}
//
//		_size = _capacity = 0;
//	}
//
//private:
//	int* _array;
//	int _capacity;
//	int _size;
//};
//
//// 默认生成的析构函数跟构造函数类似
//// 内置类型不做处理，自定义类型的成员去调用他的析构
////class MyQueue
////{
////private:
////	Stack _st1;
////	Stack _st2;
////};
//
//bool isValid(const char* s) {
//	Stack st;
//
//	while (*s)
//	{
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			st.Push(*s);
//		}
//		else
//		{
//			if (st.Empty())
//			{
//				return false;
//			}
//			char topVal = st.Top();
//			st.Pop();
//			if ((*s == ']' && topVal != '[')
//				|| (*s == ')' && topVal != '(')
//				|| (*s == '}' && topVal != '{'))
//			{
//				return false;
//			}
//		}
//
//		++s;
//	}
//
//	return st.Empty();
//}
//
//int main()
//{
//
//	Stack d1;
//	Stack d2;
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 2015,int month = 2,int day = 28)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	~Date()
//	{
//		cout << "~Date()->"<<_year<< endl;
//	}
//
//	Date(Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//private:
//	// 基本类型(内置类型)
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2016,2,3);
//	//下面二者都会发生拷贝构造
//	Date d2(d1);
//
//	Date d3 = d2;
//}


//void func()
//{
//	Date d3(3);
//	static Date d4(4);
//}
//
//Date d5(5);
//static Date d7(7);
//Date d6(6);
//static Date d8(8);
//
//// 局部对象（后定义先析构） -》 局部的静态 -》全局对象（后定义先析构）
//int main()
//{
//	Date d1(1);
//	Date d2(2);
//	func();
//
//	return 0;
//}

//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	// Stack st2(st1);
//	Stack(const Stack& s)
//	{
//		DataType* tmp = (DataType*)malloc(s._capacity *(sizeof(DataType)));
//		if (tmp == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//
//		memcpy(tmp, s._array, sizeof(DataType) * s._size);
//
//		_array = tmp;
//		_size = s._size;
//		_capacity = s._capacity;
//	}
//
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	/*~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}*/
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//
//class MyQueue
//{
//private:
//	Stack _st1;
//	Stack _st2;
//};
//
//void func(const MyQueue& qq)
//{}
//int main()
//{
//	Stack st1;
//	Stack st2(st1);
//
//	MyQueue q1;
//	MyQueue q2(q1);
//
//	func(q1);
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year, int minute, int day)
//	{
//		cout << "Date(int,int,int):" << this << endl;
//	}
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d):" << this << endl;
//	}
//	~Date()
//	{
//		cout << "~Date():" << this << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//Date Test(Date d)
//{
//	Date temp(d);
//	return temp;
//}
//
//int main()
//{
//	Date d1(2022, 1, 13);
//	Test(d1);
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	bool operator==(const Date& d2)
//	{
//		return _year == d2._year
//			&& _month == d2._month
//			&& _day == d2._day;
//	}
//
//	int _year;
//	int _month;
//	int _day;
//};
//bool operator==(const Date& d1, const Date& d2) {
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}

//Date& operator=(Date& left, const Date& right)
//{
//	if (&left != &right)
//	{
//		
//	}
//
//	return left;
//}


//Date& Date::operator+=(int day)
//{
//	_day += day;
//	while(_day > )
//}


//
//int main()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 9, 27);
//	//d1.operator==(d2)
//	cout << (d1 == d2) << endl;
//	return 0;
//}