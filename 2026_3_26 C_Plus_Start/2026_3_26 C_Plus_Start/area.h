#pragma once
#include <iostream>
using namespace std;

//1.一般的命名
namespace N1
{
	//1.命名变量
	int rand = 10;
	
	//2.函数
	int Add(int x, int y)
	{
		return x + y;
	}
	//3.结构体
	typedef struct Node
	{
		struct Node* next;
		int val;
	}Node,*PNode;
}

//3. 同名
namespace N1
{
	int rand2 = 10;
	int rand3 = 100;
}

//2.嵌套实现
namespace N2
{
	//1.命名变量
	int rand = 10;

	//2.函数
	int Add(int x, int y)
	{
		return x + y;
	}
	//3.结构体
	typedef struct Node
	{
		struct Node* next;
		int val;
	}Node, * PNode;

	//嵌套结构体访问
	namespace N3
	{
		int c;
		int d;
		int Sub(int left, int right)
		{
			return left - right;
		}
	}
}