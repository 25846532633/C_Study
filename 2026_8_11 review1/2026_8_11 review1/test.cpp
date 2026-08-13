#include <iostream>
using namespace std;

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int(*p)(int x, int y) = Add;
//	cout << p(2, 3) << endl;
//}
//class A {
//public:
//    A() { cout << "构造函数" << endl; }
//    ~A() { cout << "析构函数" << endl; }
//};
//
//
//int main()
//{
//    A* p = (A*)operator new(sizeof(A));
//    cout << "空间已经申请，但是还未构造" << endl;
//    new(p) A;
//    cout << "对象已经构造" << endl;
//
//    p->~A();
//    operator delete(p);
//    return 0;
//}

#include <new>  // placement new 需要这个头文件

class A {
public:
    A()
    {
        cout << "A()" << endl;
    }
    A(int x) : _x(x) {
        cout << "A(int)" << endl;
    }
    ~A() {
        cout << "~A()" << endl;
    }
    int _x = 44;
};

int main()
{
    void* mem = malloc(sizeof(A));

    A* p = new(mem) A;
    cout << p->_x << endl;

    p->~A();
    operator delete(p);
}