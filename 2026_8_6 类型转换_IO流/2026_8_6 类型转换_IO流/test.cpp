//#include <iostream>
//using namespace std;
//
///*
////class Number
////{
////public:
////	explicit Number(int value)
////		: _value(value)
////	{}
////
////	explicit operator int()const
////	{
////		return _value;
////	}
////private:
////	int _value = 10;
////};
////static_cast
////int main()
////{
//	/*1.算数类型转换*/
//	//double d = 12.32;
//	//int x = static_cast<int>(d);//我明确要求转换
//
//	/*2.void*到具体指针的转换*/
//	//如果是void*指针的转换：转换回某个对应类型时，这个指针本身必须指向这个对应类型的对象
//	//double x = 10; - 最后要转换为int*的指针，所以p本身就必须指向一个int对象
//	/*int x = 10;
//	void* p = &x;
//
//	int* hp = static_cast<int*>(p);
//	cout << *hp << endl;*/
//
//	/*3.显示调用转换构造函数*/
//	//Number n = static_cast<Number>(10);// Number n(10)
//
//	/*4.调用类型转换运算符*/
//	/*Number n = static_cast<Number>(10);
//	int value = static_cast<int>(n);*/
//
//	//const int* a = 10;
//	////int* b = static_cast<int*>(a); 
//	//// const int 可以利用static转为int,但是const int* 不能利用static_cast转化为int*
//	////前者没有去修改原来的const对象，只是复制了值
//	////后者
////	return 0;
////}*/
//
//
//
////reinterpret_cast:改变编译器对这个表达式的理解，从而允许我执行一些操作
////int main()
////{
////	//1.不相关对象的指针转换
////	int value = 100;
////	int* pi = &value;
////
////	unsigned char* bytes = reinterpret_cast<unsigned char*>(pi);
////	return 0;
////}
//
//
//////const_cast
////int main()
////{
////	//1.去掉指针指向对象的const
////	int value = 10;
////	const int* pc = &value;
////
////	int* p = const_cast<int*>(pc);
////	*p = 20;
////
////	cout << value << endl;
////
////	//2.修改真正的常量为未定义行为
////	const int value = 10;
////	const int* pc = &value;
////
////	int* p = const_cast<int*>(pc);
////	*p = 20;//未定义行为
////
////	cout << value << endl;//仍然打印20
////
////	//原本的对象为非const，去掉const后修改可能合法
////	//原本的对象为const，去掉const后属于未定义行为
////	return 0;
////}
//
//
