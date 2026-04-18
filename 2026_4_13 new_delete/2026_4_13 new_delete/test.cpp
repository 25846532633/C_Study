#include <iostream>
using namespace std;

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
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = new A;
	free(p1);
	delete p2;

	return 0;
}