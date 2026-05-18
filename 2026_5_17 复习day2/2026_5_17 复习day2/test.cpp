#include "type.h"


//int main()
//{
//	Date d1;
//	d1.Init(2022, 2, 3);
//	d1.Print();
//	d1.check1();
//	return 0;
//}

//class A
//{};
//
//class B
//{
//public:
//	void Print()
//	{}
//private:
//	int _b;
//};
//
//class C
//{
//private:
//	char _c;
//	int _i;
//};

class Date
{
public:
    void Init(int year, int month, int day)
    {
        this->_year = year;
        this->_month = month;
        this->_day = day;
    }

    void Print()
    {
        cout << this->_year << "/" << this->_month << "/" << this->_day << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};


int main()
{
    Date d1;
    Date d2;

    d1.Init(2024, 1, 1);
    d2.Init(2025, 2, 2);

    d1.Print();
    d2.Print();

}