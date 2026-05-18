#include <iostream>
using namespace std;

//class T
//{
//public:
//	T()
//	{
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//		cout << "T()" << endl;
//	}
//	void Print()
//	{
//		cout << _hour << "/" << _minute << "/" << _second << endl;
//	}
//
//	~T()
//	{
//		cout << "~T()" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//
//
//
//class Date
//{
//public:
//
//	Date()
//	{
//		cout << "Date()" << endl;
//	}
//
//	Date(int year,int month,int day,const T& _time)
//		:_year(year),
//		_month(month),
//		_day(day),
//		_t(_time)
//	{
//		cout << "Date(int year,int month,int day,T _time)" << endl;
//	}
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//		_t.Print();
//	}
//
//	~Date()
//	{
//		_year = 0;
//		_month = 0;
//		_day = 0;
//		cout << "~Date()" << endl;
//	}
//
//
//private:
//	int _year = 2022;
//	int _month = 3;
//	int _day = 18;
//	T _t;
//};
//
//
//int main()
//{
//	T t1;
//	Date d1(2022,2,4,t1);
//	d1.Print();
//	return 0;
//}


//class Stack
//{
//public:
//	Stack(int capacity = 3,int size = 10)
//		:_capacity(capacity),
//		_size(size)
//	{
//		_array = new int[capacity];
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		delete[] _array;
//		_array = nullptr;
//
//		_size = _capacity = 0;
//	}
//
//	Stack(const Stack& s)
//	{
//		cout << "Stack(const Stack& s)" << endl;
//		int* tmp = new int[s._capacity];
//		
//		for (int i = 0; i < s._size; i++)
//		{
//			_array[i] = s._array[i];
//		}
//
//		_size = s._size;
//		_capacity = s._capacity;
//	}
//
//private:
//	int* _array;
//	int _capacity;
//	int _size;
//};
//
//int main()
//{
//	Stack d1;
//	Stack d2 = d1;
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 2015, int month = 2, int day = 28)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	~Date()
//	{
//		cout << "~Date()->" << _year << endl;
//	}
//
//	//用const可以避免被修改
//	//同时如果不用const的话，就无法实现const对象的拷贝构造
//	Date(const Date& d)
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
//	Date d1(2026, 5, 18);
//	Date d2(d1);
//	Date d3 = d2;
//	return 0;
//}


//class Date
//{
//public:
//
//	int GetMonthDay(int year, int month)
//	{
//		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,
//		31 };
//		int day = days[month];
//		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//		{
//			day += 1;
//		}
//		return day;
//	}
//
//	Date(int year, int month, int day)
//		:_year(year),
//		_month(month),
//		_day(day)
//	{
//		//cout << "Date(int,int,int):" << this << endl;
//		
//	}
//	Date(const Date& d)
//		: _year(d._year),
//		_month(d._month),
//		_day(d._day)
//	{
//		cout << "Date(const Date& d):" << this << endl;
//	}
//	~Date()
//	{
//		//cout << "~Date():" << this << endl;
//	}
//
//	bool operator==(const Date& d2)
//	{
//		return _year == d2._year
//			&& _month == d2._month
//			&& _day == d2._day;
//	}
//
//	bool operator!=(const Date& d)
//	{
//		return !(*this == d);
//	}
//
//	Date& operator=(const Date& d2)
//	{
//		if (this != &d2)
//		{
//			_year = d2._year;
//			_month = d2._month;
//			_day = d2._day;
//		}
//
//		return *this;
//	}
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//	Date& operator++()
//	{
//		_day += 1;
//		return *this;
//	}
//	Date operator++(int)
//	{
//		Date temp(*this);
//		_day += 1;
//		return temp;
//	}
//	Date& operator+=(int day)
//	{
//		_day += day;
//		while (_day > GetMonthDay(_year, _month))
//		{
//			_day -= GetMonthDay(_year, _month);
//			++_month;
//			if (_month > 12)
//			{
//				++_year;
//				_month = 1;
//			}
//		}
//		return *this;
//	}
//
//	Date operator+(int day)
//	{
//		Date tmp(*this);
//		tmp += day;
//		return tmp;
//	}
//
//private:
//	int _year = 2022;
//	int _month = 3;
//	int _day = 16;
//};
//
//Date Test(Date d)
//{
//	Date temp(d);
//	return temp;
//}
//
//
//int main()
//{
//	Date d1(2022, 1, 13);
//	Date d2 = d1 + 2;
//	d1.Print();
//	d2.Print();
//	/*Date d2 = d1++;
//	d2.Print(); 
//	Date d3 = ++d1;
//	d3.Print();*/
//	////Test(d1);//temp直接构成返回值对象，在这句语句之后才销毁
//	//Date d2(2024, 2, 14);
//	//d2.Print();
//
//	//d2 = d1;
//	//d2.Print();
//	
//	return 0;
//}


//class A
//{
//public:
//    static int GetCount()
//    {
//        return _count;
//    }
//
//private:
//    static int _count;
//};
//
//int A::_count = 0;
//
//int main()
//{
//    cout << A::GetCount() << endl;
//    return 0;
//}

//class Date
//{
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//public:
//	Date()
//	{
//		_year = 0;
//		_month = 0;
//		_day = 0;
//	}
//	Date(int year, int month, int day)
//		:
//		_year(year),
//		_month(month),
//		_day(day)
//	{}
//	// d1 << cout; -> d1.operator<<(&d1, cout);  不符合常规调用
//	// 因为成员函数第一个参数一定是隐藏的this，所以d1必须放在<<的左侧
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << d._month << d._day << endl;
//	return out;
//}
//
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year;
//	in >> d._month;
//	in >> d._day;
//	return in;
//}
//int main()
//{
//	Date d1;
//	cin >> d1;
//	cout << d1 << endl;
//}

//#include <iostream>
//using namespace std;
//
//class Outer
//{
//public:
//    class Inner
//    {
//    public:
//        int b;
//    };
//
//private:
//    int a;
//    Inner obj;   // 这才是“成员对象”
//};
//
//int main()
//{
//    cout << "sizeof(Outer) = " << sizeof(Outer) << endl;
//    cout << "sizeof(Outer::Inner) = " << sizeof(Outer::Inner) << endl;
//    return 0;
//}
class Stack
{
public:
	Stack(size_t capacity = 4)
		:_array(new int[capacity]),
		_size(0),
		_capacity(capacity)
	{}

	Stack(const Stack& st)
		:_array(new int[st._capacity]),
		_size(st._size),
		_capacity(st._capacity)
	{
		for (size_t i = 0; i < _size; i++)
		{
			_array[i] = st._array[i];
		}
	}

	Stack& operator=(const Stack& st)
	{
		if (this != &st)
		{
			int* tmp = new int[st._capacity];

			for (size_t i = 0; i < st._size; i++)
			{
				tmp[i] = st._array[i];
			}

			delete[] _array;

			_array = tmp;
			_size = st._size;
			_capacity = st._capacity;
		}
		return *this;
	}

	~Stack()
	{
		delete[] _array;
		_array = nullptr;
		_size = _capacity = 0;
	}

private:
	int* _array;
	size_t _size;
	size_t _capacity;
};