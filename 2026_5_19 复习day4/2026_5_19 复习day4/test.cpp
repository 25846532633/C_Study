#include <iostream>
#include <cstdlib>
using namespace std;

//int main()
//{
//	//1.malloc - 只申请空间而不初始化
//	//int* ptr = (int*)malloc(sizeof(int));
//	//if (ptr == NULL)
//	//{
//	//	perror("malloc fail");
//	//	return 1;
//	//}
//
//	//*ptr = 10;
//	//cout << *ptr << endl;
//	//free(ptr);
//	//ptr = NULL;
//
//
//	//2.calloc - 申请对应大小size字节的空间，并且整块内存初始化为0
//	/*int* ptr2 = (int*)calloc(5, sizeof(int));
//	if (ptr2 == nullptr)
//	{
//		perror("calloc fail");
//		exit(-1);
//	}
//
//	for (int i = 0; i < 5; i++)
//	{
//		cout << *(ptr2 + i) << " ";
//	}
//	cout << endl;
//
//	free(ptr2);
//	ptr2 = nullptr;
//	*/
//	
//	////3.调整空间大小
//	//int* st = (int*)calloc(5, sizeof(int));
//	//int* ptr3 = (int*)realloc(st, sizeof(int) * 10);
//	//if (ptr3 == nullptr)
//	//{
//	//	free(st);
//	//	st = nullptr;
//	//	exit(-1);
//	//}
//
//	//cout << &st << " " << &ptr3 << endl;
//	//st = nullptr;
//	//free(ptr3);
//	//ptr3 = nullptr;
//
//
//	/*int* pt1 = new int;
//	int* pt2 = new int(3);
//	int* pt3 = new int[5];
//	delete pt1;
//	delete pt2;
//	delete[ ] pt3;*/
//
//
//
//	return 0;
//}	

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};


int main()
{
	void* mem = malloc(sizeof(A));
	A* p = new(mem) A(10);

	p->~A();
	free(mem);
	return 0;
}



//int main()
//{
//	//A* p1 = new A;//调用构造函数
//	//A* p2 = (A*)malloc(sizeof(A));//不调用
//
//	//free(p2);
//	//p2 = nullptr;
//	//delete p1;
//
//
//	A* p1 = new A[3];
//	delete[] p1;
//
//	return 0;
//}