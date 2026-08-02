#include <iostream>
using namespace std;
#include <memory>
////不可构造，不可移动
//class CopyBan
//{
//public:
//	CopyBan() = default;
//
//	//删除构造和拷贝构造 - 禁止拷贝：C++11才支持delete
//	CopyBan(const CopyBan& cb) = delete;
//	CopyBan& operator=(const CopyBan& cb) = delete;
//
//	//删除移动构造和移动赋值
//	//CopyBan(CopyBan&& cb) = delete;
//	//CopyBan& operator=(CopyBan&& cb) = delete;
//	//注意：哪怕没有禁止移动构造，但如果禁止了拷贝构造和拷贝复制，也会抑制系统生成拷贝构造和拷贝赋值
//};
//
//
////不可构造，可以移动
//class Test
//{
//	Test();
//
//	Test(const Test& st) = delete;
//	Test& operator=(const Test& st) = delete;
//
//	Test(Test&&) = default;
//	Test& operator=(Test&&) noexcept = default;
//};
//
//
//int main()
//{
//	CopyBan b1;
//	//CopyBan b2(b1);
//	//CopyBan b2 = b1;
//	//CopyBan b2(move(b1));
//	//CopyBan b2(move(b1));
//
//	return 0;
//}



//创建一个只能在堆上创建对象的类
////1.构造函数私有化，提供静态调用方法
////禁止构造和拷贝构造，构造函数私有化
//class HeapOnly
//{
//public:
//	//静态成员没有this指针，但是可以访问类的私有成员
//	/*static HeapOnly* CreateObj()
//	{
//		return new HeapOnly;
//	}*/
//
//	//避免忘记delete，利用智能指针
//	static unique_ptr<HeapOnly> CreateObj()
//	{
//		return unique_ptr<HeapOnly>(new HeapOnly());
//	}
//
//	HeapOnly(const HeapOnly& hp) = delete;
//	HeapOnly& operator=(const HeapOnly& hp) = delete;
//private:
//	HeapOnly(){}
//};


//2.私有析构函数
//创建的局部对象，无法访问私有析构函数，编译器直接拒绝创建
//在类外delete也不行，毕竟delete的底层也需要调用类的析构函数，而类外无权调用

//class HeapOnly
//{
//public:
//	void Release()
//	{
//		delete this;
//	}
//
//private:
//	~HeapOnly()
//	{}
//};

//避免智能指针底层删除器default_delete<HeapOnly>无法调用私有析构的问题
//我们可以加一个删除器

//class HeapOnly;
//struct HeapOnlyDeleter
//{
//	void operator()(HeapOnly* p) const
//	{
//		delete p;
//	}
//};
//
//class HeapOnly
//{
//public:
//	typedef typename unique_ptr<HeapOnly, HeapOnlyDeleter> Ptr;
//
//	static Ptr Create()
//	{
//		return Ptr(new HeapOnly);
//	}
//
//	HeapOnly(const HeapOnly&) = delete;
//	HeapOnly& operator=(const HeapOnly&) = delete;
//
//private:
//	friend struct HeapOnlyDeleter;
//	HeapOnly() = default;
//	~HeapOnly() = default;
//};
//
////void HeapOnlyDeleter::operator()(HeapOnly* p)const
////{
////	delete p;
////}
//
//
//int main()
//{
//	//auto p = HeapOnly::Create();
//	auto p = HeapOnly::Create();
//	//auto p = HeapOnly::CreateObj();
//	/*HeapOnly* p1 = new HeapOnly;
//	p1->Release();*/
//	/*HeapOnly hp;
//	HeapOnly hp1(hp);*/
//	return 0;
//}


//创建一个只能在栈上创建的类
//禁掉operator new和operator delete - 避免了拷贝构造、new和delete

class StackOnly
{
public:
	static StackOnly CreateObj()
	{
		return StackOnly();
	}

	//禁止
	void* operator new(size_t) = delete;
	void operator delete(void*) = delete;

	void* operator new[](size_t) = delete;
	void operator delete[](void*) = delete;

private:
	StackOnly() = default;
};