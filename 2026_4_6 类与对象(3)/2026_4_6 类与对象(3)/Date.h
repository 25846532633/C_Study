#pragma once

#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);
public:
	//缺省参数只能指定一次
	explicit Date(int year)
		:_year(year)
	{}
	//Date(int year = 1, int month = 1, int day = 1); 
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	// d1 + 100
	Date& operator+=(int day);
	Date operator+(int day);
	// d1 - 100
	Date operator-(int day);
	Date& operator-=(int day);

	// ++d1
	Date& operator++();
	// 特殊处理：解决语法逻辑不自洽，自相矛盾的问题
	// d1++
	// 为了跟前置++区分，强行增加一个int形参，够成重载区分
	Date operator++(int);

	Date operator--(int);
	Date& operator--();

	// d1 - d2
	int operator-(const Date& d);

	// 本质就是inline
	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);
		static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		// 365   自转  公转  365 5+h
		// 366
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}

		return monthDays[month];
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

//class A
//{
//public:
//	A() { ++_scount; }
//	A(const A& t) { ++_scount; }
//	~A() { --_scount; }
//	static int GetACount() { return _scount; }
//private:
//	static int  _scount;
//};
//
//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year, int month, int day)
//		:
//		_year(year),
//		_month(month),
//		_day(day)
//	{}
//		// d1 << cout; -> d1.operator<<(&d1, cout);  不符合常规调用
//		// 因为成员函数第一个参数一定是隐藏的this，所以d1必须放在<<的左侧
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};

ostream& operator<<(ostream& _cout,const Date&d)
{
	_cout <<d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}

istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}