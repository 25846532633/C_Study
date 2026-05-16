#include <iostream>
#include <string>
using namespace std;
#include "happy.h"

//int main()
//{
//	/*cout << rand1 << endl;
//	cout << add(1, 2) << endl;
//	cout << sub(2, 1) << endl;*/
//
//
//	int x = 0;
//	char c = 'b';
//	cin >> x >> c;
//	cout << x << c << endl;
//
//	x = cin.get();
//	c = cin.get();
//	cout << x <<" "<< c << endl;
//
//	string name;
//	getline(cin, name);
//
//	return 0;
//}

//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//
//void Func2(int a = 0, int b = 1, int c = 2)
//{
//	cout << a << b << c << endl;
//}
//
//void Func3(int a, int b = 2)
//{
//	cout << a << b << endl;
//}


//int main()
//{
//	Func();
//
//	return 0;
//}


//void add(int x, int y)
//{
//	cout << "add(int x, int y)" << endl;
//}
//void add(int x, double y)
//{
//	cout << "add(int x, double y)" << endl;
//}
//void add(double x, double y)
//{
//	cout << "add(double x, double y)" << endl;
//}
//void add(double x, int y)
//{
//	cout << "add(double x, int y)" << endl;
//}
//void add(int x)
//{
//	cout << "add(int x)" << endl;
//}
//int main()
//{
//	add(1, 2);
//	add(1.0, 2);
//	add(1, 2.0);
//	add(1.0, 2.0);
//	add(1);
//	return 0;
//}


//void Swap(int& left, int& right)
//{
//	std::swap(left, right);
//}
//
//
//int main()
//{
//	//int a = 10;
//	//int& ra = a;
//	//int& rb = a;
//	//int c = 10;
//	//cout << &a << "-" <<& ra <<"-" << &rb << endl;
//
//	const int a = 10;
//	const int& ra = a;
//
//
//
//	return 0;
//}

//int& count()
//{
//	int a = 0;
//	a++;
//	return a;
//}
//void test()
//{
//	int x = 100;
//}

//int main()
//{
//	int x = 10;
//	auto a = x;
//	auto b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4 };
//	for (auto& e : arr)
//	{
//		e *= 2;
//	}
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//}

void f(int)
{
	cout << "int" << endl;
}

void f(int*)
{
	cout << "int*" << endl;
}

int main()
{
	f(0);
	f(nullptr);
	return 0;
}