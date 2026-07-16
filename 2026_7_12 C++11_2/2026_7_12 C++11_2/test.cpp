#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
#include <algorithm>

//class Person
//{
//public:
//    Person(const char* name = nullptr , int age = 18)
//        : _name(nullptr)
//        , _age(age)
//    {
//        if (name != nullptr)
//        {
//            _name = new char[strlen(name) + 1];
//            strcpy(_name, name);
//        }
//    }
//
//    Person(const Person& other) = delete;
//    Person& operator=(const Person& other) = default;
//
//    /*Person(const Person& other)
//        :_name(nullptr),
//        _age(other._age)
//    {
//        if (other._name != nullptr)
//        {
//            _name = new char[strlen(other._name) + 1];
//            strcpy(_name, other._name);
//        }
//    }*/
//    
//    Person(Person&& other)
//        :_name(other._name),
//        _age(other._age)
//    {
//        other._name = nullptr;
//    }
//
//    Person& operator=(Person&& other)
//    {
//        if (this != &other)
//        {
//            delete[] _name;
//
//            _name = other._name;
//            _age = other._age;
//
//            other._name = nullptr;
//        }
//
//        return *this;
//    }
//
//   /* Person& operator=(const Person& other)
//    {
//        if (this != &other)
//        {
//            char* newName = nullptr;
//
//            if (other._name != nullptr)
//            {
//                newName = new char[strlen(other._name) + 1];
//                strcpy(newName, other._name);
//            }
//
//            delete[] _name;
//            _name = newName;
//            _age = other._age;
//        }
//        
//        return *this;
//    }*/
//private:
//    char* _name;
//    int _age;
//};
//
//int main()
//{
//    Person s1("张三",19);
//    Person s2 = s1;             // 默认拷贝构造
//    Person s3 = std::move(s1);  // 默认移动构造
//
//    Person s4;
//    s4 = std::move(s2);         // 默认移动赋值
//
//    return 0;
//}
//void _CPP()
//{
//	cout << endl;
//}
//
//
//template<class T,class ...Args>
//void _CPP(const T& val, Args ...args)
//{
//	cout << val << " ";
//	_CPP(args...);
//}
//
//
//template<class ...Args>
//void CPP(Args ...args)
//{
//	//cout << sizeof...(args) << endl;
//	_CPP(args...);
//}
//
//int main()
//{
//	CPP(1, "happy", string("try"));
//	CPP(2, "wonderland");
//}

//template<class T>
//void PrintArg(T t)
//{
//    cout << t << " ";
//}
//
//template<class... Args>
//void Cpp_Printf(Args... args)
//{
//    int arr[] = { (PrintArg(args), 0)... };
//    cout << endl;
//}
//
//int main()
//{
//    Cpp_Printf(1);
//    Cpp_Printf(1, 'A');
//    Cpp_Printf(1, 'A', std::string("sort"));
//
//    return 0;
//}

int main()
{
	int c = 10;
	int d = 9, a = 6;
	auto add1 = [&,d,a](int x, int y)mutable
		{
			d++;
			return x + y + c + d + a;
		};

	cout << add1(2, 3) << endl;
}
