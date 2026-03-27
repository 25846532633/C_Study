#define _CRT_SECURE_NO_WARNINGS
#include "area.h"
using namespace std;
//using namespace N1;
//using N1::rand;

//int main()
//{
//	//cout << N1::rand2 << endl;
//	//访问
//	/*cout << N1::rand << endl;
//	cout << N2::N3::Sub(2, 3) << endl;*/
//
//	int a = 0;
//	char ch;
//	cin >> a >> ch;
//	cout << a << " " << ch << endl;
//	scanf("%d %c", &a, &ch);
//	printf("%d %c", a, ch);
//	
//	return 0;
//}

////1.全缺省
//void Func(int a = 0,int b = 1,int c = 2)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//
//
//int main()
//{
//	Func(1);
//	Func(1, 2);
//	Func(1, 2, 3);
//	//Func(, 1, 2);
//	return 0;
//}

//int Add(int left, double right)
//{
//	cout << "int" << endl;
//	return left + right;
//}
//
//int Add(double left, int right)
//{
//	cout << "change" << endl;
//	return left + right;
//
//}

//double Add(double left, double right)
//{
//	cout << "double" << endl;
//	return left + right;
//}
//
//double Add(double left)
//{
//	cout << "One sigle" << endl;
//	return left;
//}


//int main()
//{
//	//cout << Add(1, 2) << endl;
//	////cout << Add(1.0, 2) << endl;
//	//cout << Add(1.0, 2.0) << endl;
//	//return 0;
//	cout << Add(1.0, 2) << endl;
//	cout << Add(1,2.0) << endl;
//}

//int main()
//{
//	int a = 10;
//	int& b = a;
//	int& c = a;
//	int d = 10;
//	int& c = d;
//	printf("%p\n", &a);
//	printf("%p\n", &b);
//	printf("%p\n", &c);
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
//
//int main()
//{
//	int& b = count();
//	test();              // 函数调用可能覆盖了 b 指向的内存
//	cout << b << endl;   // 可能输出随机值，不再是 1
//	return 0;
//}
#include <time.h>
//struct A { int a[10000]; };
//void TestFunc1(A a) {}
//void TestFunc2(A& a) {}
//void TestRefAndValue()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//
//int main()
//{
//	TestRefAndValue();
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& ra = a;
//	ra = 20;
//	int* pa = &a;
//	*pa = 20;
//	return 0;
//}

//
//int main()
//{
//	int ret = 0;
//	ret = Add(1, 2);
//	return 0;
//}

//int TestAuto()
//{
//	return 10;
//}

//void TestAuto(int a = 0)
//{
//	auto a = 1, b = 2;
//	auto c = 3, d = 4;  // 该行代码会编译失败，因为c和d的初始化表达式类型不同
//	
//
//}
//void TestAuto(int a = 0)
//{
//	int a[] = { 1,2,3 };
//	auto b[] = { 2,3,4 };
//}

//int main()
//{
//	/*int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	return 0;*/
//	/*int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	*a = 20;
//	*b = 30;
//	c = 40;*/
//	TestAuto();
//}

//
//int main()
//{
//	int a[] = { 1,2,3 };
//
//	for (auto e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	for (auto& e : a)
//	{
//		e *= 2;
//		cout << e << " ";
//	}
//}

void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);
	f(nullptr);
	f((int*)NULL);
	return 0;
}