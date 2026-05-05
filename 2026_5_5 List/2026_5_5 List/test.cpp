#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void test01()
{
	list<int> l1;
	list<int> l2(4, 100);
	for (auto e : l2)
	{
		cout << e << " " ;
	}
	cout << endl;
	for (list<int>::iterator it = l2.begin(); it != l2.end(); it++)
	{
		cout << *it << " " << endl;
	}

	list<int> l3(l2.begin()++, l2.end()--);
	list<int> l4(l3);
	list<int> l5 = l4;
}



void test02()
{
	list<int> mylist(10, 4);
	mylist.insert(++mylist.begin(), 1);
	for (auto e : mylist)
	{
		cout << e << " ";
	}
	cout << endl;
	mylist.insert(mylist.begin(), 2, 30);//在开头插入两个30
	for (auto e : mylist)
	{
		cout << e << " ";
	}
	list<int> l1(3, 3);
	cout << endl;
	list<int>::iterator l2 = mylist.begin();
	advance(l2, 2);
	mylist.insert(l2, l1.begin(), l1.end());
	for (auto e : mylist)
	{
		cout << e << " ";
	}
	cout << endl;
	mylist.sort();
	for (auto e : mylist)
	{
		cout << e << " ";
	}
	cout << endl;

	mylist.reverse();
	for (auto e : mylist)
	{
		cout << e << " ";
	}
	/*mylist.push_back(3);
	cout << mylist.front() << endl;
	cout << mylist.back() << endl;
	list<int> l2(3, 3);
	mylist.assign(10, 10);
	cout << mylist.front() << endl;
	cout << mylist.back() << endl;*/

}
void test03();

int main()
{
	//test01();
	test02();
	//test03();
	return 0;
}