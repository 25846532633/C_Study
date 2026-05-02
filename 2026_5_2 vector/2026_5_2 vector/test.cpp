#include <iostream>
#include <vector>
using namespace std;

void test1()
{
	vector<int> v1;
	/*for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;*/

	vector<int> v2(10,1);
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v3(v2);
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v4(v3.begin()+3,v3.end()-4);
	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test2()
{
	/*vector<int> v2(10, 1);
	vector<int>::iterator start = v2.begin();
	while (start != v2.end())
	{
		cout << *start << " ";
		start++;
	}
	cout << endl;*/
	
	//vector<int> v2;
	//v2.push_back(1);
	//v2.push_back(2);
	//v2.push_back(4);
	//v2.push_back(5);
	//v2.push_back(6);
	///*vector<int>::reverse_iterator start = v2.rbegin();
	//while (start != v2.rend())
	//{
	//	cout << *start << " ";
	//	start++;
	//}
	//cout << endl;*/
	//cout << v2.size() << endl;
	//cout << v2.capacity() << endl;
	////v2.reserve(100);
	///*v2.resize(15);*/
	//v2.resize(15, 1);
	//vector<int>::reverse_iterator start = v2.rbegin();
	//while (start != v2.rend())
	//{
	//	cout << *start << " ";
	//	start++;
	//}
	//cout << endl;

	size_t sz;
	vector<int> v;
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
	
}

int main()
{
	//test1();
	test2();
	return 0;
}