#include <iostream>
using namespace std;

class Date
{
public:
	void Init(int year, int month, int day) {
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	int _year;
	int _month;
	int _day;
};

struct A {

	long a1;

	short a2;

	int a3;

	int* a4;

};
int main()
{
	//Date d1;
	///*d1.Init(2025, 1, 2);
	//d1.Print();
	//cout << d1._year << endl;*/
	//cout << sizeof(d1) << endl;

	Date d1, d2;
	d1.Init(2022, 1, 11);
	d2.Init(2022, 1, 12);
	d1.Print();
	d2.Print();
	cout << sizeof(struct A) << endl;
	return 0;
	return 0;
}

//class A1
//{
//
//};
//
//class A2
//{
//public:
//	void f1() {}
//private:
//	int _a;
//};
//
//class A3
//{
//public:
//	void f2() {}
//};
//
//int main()
//{
//	cout << sizeof(A1) << endl;
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//	return 0;
//}