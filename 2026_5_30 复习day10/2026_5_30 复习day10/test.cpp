#include <iostream>
using namespace std;

//class Person 
//{
//public:
//    void Print() 
//    {
//        cout << "name:" << _name << endl;
//        cout << "age:" << _age << endl;
//    }
//public:
//    string _name = "peter";
//    int _age = 18;
//};
//
//class Student :public Person
//{
//public:
//    void func() 
//    {
//       // cout << _name << endl;              // 可以访问父类的 protected 成员
//        // cout << _age << endl;            // 不能直接访问父类的 private 成员
//        Print();                            // 可以间接调用父类的 public 函数
//    }
//protected:
//    int _stuid = 1;    // 学号
//};
//
//
//
//int main()
//{
//    Student s;
//    Person p;
//    p = s; //只拷贝Person的部分
//
//    Person& ref = s;//只引用Student中Person的部分
//    Person* ret = &s;//只指向Student中Person的部分
//  
//    ref._name += "happy";
//    ref._age = 20;
//    s.func();
//
//    ret->_age = 100;
//    ret->_name = "superlady";
//    s.func();
//
//	return 0;
//}

//class Person 
//{
//public:
//    void func()
//    {
//        cout << "func()" << endl;
//    }
//protected:
//    string _name = "peter";
//    int _num = 0;           // Person 的 _num
//};
//
//class Student : public Person {
//public:
//    void func() {
//        // Student 中也有 _num
//        cout << _num << endl;           // 默认访问子类的 _num
//        cout << Person::_num << endl;   // 显式访问父类继承来的 _num
//    }
//
//protected:
//    int _num = 1;           // Student 自己的 _num
//};
//
//int main()
//{
//    Student s;
//    s.func();
//    s.Person::func();
//    return 0;
//}


//class Person
//{
//public:
//	Person(const char* name=" ")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//
//private:
//	string _name;
//};
//
//class Student : public Person 
//{
//public:
//	// 派生类构造函数——必须调用基类构造函数初始化基类部分
//	Student(int num, const char* str, const char* name)
//		: Person(name),         // 显式调用基类构造函数
//		_num(num)
//		, _str(str)
//	{
//		cout << "Student()" << endl;
//	}
//
//	Student(const Student& s)
//		:Person(s)
//		,_num(s._num)
//		,_str(s._str)
//	{}
//
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_num = s._num;
//			_str = s._str;
//		}
//		return *this;
//	}
//
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//
//	// ...
//
//protected:
//	int _num;
//	string _str;
//};
//
//
//int main()
//{
//	//Person p("haven");
//	Student s(12,"Peter","haven");
//	return 0;
//}

class A {
public:
    int _a;
};

class B : virtual public A {
public:
    int _b;
};

class C : virtual public A {
public:
    int _c;
};

class D : public C, public B {
public:
    int _d;
};

int main()
{
    D d;
    d._a = 0;      //没有二义性——只有一份 A::_a
    d._b = 3;
    d._c = 4;
    d._d = 5;
    return 0;
}