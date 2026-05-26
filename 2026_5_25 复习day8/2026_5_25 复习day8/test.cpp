#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;


void test01()
{
	//list<int> l1;
	//list<string>l2;

	//list<int> l3(5);//5个0
	//list<int> l4(5, 10);
	//list<string> l5(3, "happy");

	//list<string> l6(l5.begin(), l5.end());
	//list<string> l7(l6); list<string> l8 = l7;

	////初始化列表
	//list<int> a = { 1,2,3,4,5 };


	//for (auto e : a)
	//{
	//	cout << e << " ";
	//}

	//list<int> a = { 10,20,30,40,50 };

	///*for_each(a.begin(), a.end(), [](int x)
	//	{
	//		cout << x << " ";
	//	}
	//);*/

	////for_each(++a.begin(), a.end(), [](int x) {cout << x << " "; });

	//for_each(a.rbegin(), a.rend(), [](int x) {cout << x << " "; });

	list<int> a = { 1,2,3,4,5 };

	/*auto it = a.begin();
	++it;
	a.insert(it, 3);
	for_each(a.begin(), a.end(), [](int x) {cout << x << " "; }); cout << endl;*/

	//auto it2 = a.begin();
	//it2++; it2++;
	//a.insert(it2, 3, 0);
	//for_each(a.begin(), a.end(), [](int x) {cout << x << " "; }); 
	//cout << endl;//1 0 0 0 2 3 4 5

	//auto it = a.begin();
	//++it;
	//a.erase(it);
	//for_each(a.begin(), a.end(), [](int x) {cout << x << " "; });

	//auto first = a.begin(), last = a.end();
	//a.erase(first, last);
	//for_each(a.begin(), a.end(), [](int x) {cout << x << " "; });
}

void test02()
{
	//list<int> l1 = { 1, 2, 3, 4, 5 };
	//list<int> l2 = { 10, 20, 30 };

	//auto it = --l2.end();
	//l1.splice(l1.end(), l2, it);//1 2 3 4 5 30
	///*for_each(l1.begin(), l1.end(), [](int x) {cout << x << " "; });*/
	///*for (auto e : l1)
	//{
	//	cout << e << " ";
	//}*/

	///*l1.remove(2);*/
	//l1.remove_if([](int x) {return x % 2 == 0; });//1 3 5
	//for (auto e : l1)
	//{
	//	cout << e << " ";
	//}

	list<int> l1 = { 1,2,3,2,3,4,5,4 };
	l1.sort();
	l1.unique();//只能删除连续相等的元素
	for_each(l1.begin(), l1.end(), [](int x) {cout << x << " "; });


}


int main()
{
	test01();
	test02();
	return 0;
}