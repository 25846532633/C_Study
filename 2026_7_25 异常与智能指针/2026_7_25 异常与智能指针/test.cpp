#include <iostream>
#include <stdexcept>
using namespace std;
#include "shared_ptr.h"

//class BaseException
//{
//public:
//	virtual const char* what()const
//	{
//		return "BaseException";
//	}
//
//	virtual ~BaseException() noexcept = default;
//};
//
//class FileException:public BaseException
//{
//public:
//	const char* what()const
//	{
//		return "FileException";
//	}
//	virtual ~FileException() = default;
//};
//
//double Division(int a, int b) noexcept
//{
//	if (b == 0)
//	{
//		throw invalid_argument("除数不能为0");
//	}
//
//	return static_cast<double>(a) / b;
//}
//
//
//
//int main()
//{
//	try
//	{
//		cout << Division(10, 0) << endl;
//		//throw FileException();
//		
//	}
//	catch (const BaseException& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "Unknowned Exception" << endl;
//	}
//}

template<class T>
class SmartPtr
{
public:
	explicit SmartPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		delete _ptr;
	}
private:
	T* _ptr;
};

double Division(int a, int b) 
{
	if (b == 0)
	{
		throw invalid_argument("除数不能为0");
	}

	return static_cast<double>(a) / b;
}

//int main()
//{
//	/*SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2(new int);*/
//
//	//cout << Division(10, 0) << endl;
//	auto_ptr<int> sp1(new int(10));
//	auto_ptr<int> sp2(sp1);
//}

////unique_ptr - 独占所有权的智能指针
//int main()
//{
//	/*unique_ptr<int> p1 = make_unique<int>(10);
//	auto p2 = move(p1);*/
//
//	auto sp1 = make_shared<int>(10);
//	auto sp2 = sp1;
//	cout << sp2.use_count() << endl;
//}


int main()
{
	shared_ptr<int> sp(new int[10],
		[](int* p)
		{
			cout << "delete[]" << endl;
			delete[] p;
		}
	);
}