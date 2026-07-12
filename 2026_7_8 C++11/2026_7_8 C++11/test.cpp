#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;
//
//
//struct Point
//{
//    int _x;
//    int _y;
//};
//
//
//int main()
//{
//    int a[] = { 1,2,3,4,5 };
//    int b[]{ 1,2,3,4,5 };
//    int c[5]{ 0 };
//
//    int* pa = new int[4]{1,2,3,4};
//
//    for (int i = 0; i < 4; i++)
//    {
//        cout << *(pa + i) << endl;
//    }
//	return 0;
//}

//class A
//{
//public:
//     explicit A(int x)
//        : _x(x)
//        , _y(x)
//    {}
//
//private:
//    int _x;
//    int _y;
//};

//int main()
//{
//    //A aa(1);
//    ////A bb = 1;
//    //A bb{ 1 };
//    //return 0;
//    auto il = { 10,20,30 };
//    cout << typeid(il).name() << endl;
//    return 0;
//}

//int main()
//{
//	/*int i = 0;
//	int& j = i;
//
//	auto& z = j;
//
//	z++;
//	cout << i << endl;*/
//	
//	//const int a = 10;
//	//auto b = a;
//
//	//b++;
//	////a++;
//
//	/*map<string, string> dict = { {"sort", "排序"}, {"insert", "插入"} };
//
//	for (auto& [x, y] : dict)
//	{
//		cout << x << ":" << y << endl;
//		y += '2';
//	}*/
//
//	/*int&& r1 = 10;
//	int b = 0;
//	int&& r2 = move(b);
//	r2++;
//	cout << b << endl;*/
//
//	string s1("hello world");
//	string s2(s1);
//
//	cout << s1 << endl;
//
//	return 0;
//}

#include <utility>
using namespace std;

void Fun(int& x)
{
    cout << "左值引用" << endl;
}

void Fun(const int& x)
{
    cout << "const 左值引用" << endl;
}

void Fun(int&& x)
{
    cout << "右值引用" << endl;
}

void Fun(const int&& x)
{
    cout << "const 右值引用" << endl;
}

template<class T>
void PerfectForward(T&& t)
{
    Fun(forward<T>(t));
}

int main()
{
    PerfectForward(10);

    int a = 0;
    PerfectForward(a);
    PerfectForward(move(a));

    const int b = 8;
    PerfectForward(b);
    PerfectForward(move(b));
}