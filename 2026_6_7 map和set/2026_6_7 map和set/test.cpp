#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

void test1()
{
	/*pair<string, string> kv("sort", "ÅÅĞò");
	cout << kv.first << endl;
	cout << kv.second << endl;*/

	/*map<string, string> dict;
	dict.insert(make_pair("right", "ÓÒ±ß"));
	dict.insert(pair<string, string>("left", "×ó±ß"));
	dict.insert({ "string","×Ö·û´®" });

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}*/
	
	/*set<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(4);*/





	/*s.erase(2);

	auto it = s.find(3);
	if (it != s.end())
	{
		s.erase(it);
	}
	cout << s.count(3) << endl;*/


	/*cout << s.count(2) << endl;*/

	/*auto pos = s.find(2);
	if (pos != s.end())
	{
		cout << "Find " << *pos << endl;
	}
	else
	{
		cout << "Not Find" << endl;
	}*/

	/*for (auto &e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << s.size() << endl;
	cout << s.empty() << endl;*/

	set<int> myset = { 10,20,30,40,50,60,70,80,90 };

	auto begin = myset.upper_bound(30);
	for (auto it = begin;it != myset.end();it++)
	{
		cout << *it << " ";
	}
}

void test2()
{
	multiset<int> s;
	s.insert(1);
	s.insert(1);
	s.insert(1);
	s.insert(2);
	s.insert(2);
	s.insert(2);
	
	cout << s.count(2) << endl;
	auto range = s.equal_range(2);
	// range <=> <s.begin,s.end>
	for (auto it = range.first; it != range.second; ++it)
	{
		cout << *it << " ";
	}
	/*for (auto& e : s)
	{
		cout << e << " ";
	}*/
}

void test3()
{
	map<string, string> dict;
	dict["sort"] = "ÅÅĞò";
	dict["left"] = "×ó±ß";
	dict["right"] = "ÓÒ±ß";

	dict.insert(pair<string, string>("sort", "ÅÅĞò"));
	dict.insert(make_pair("left", "×ó±ß"));
	dict.insert({ "right", "ÓÒ±ß" });
	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}


	auto ret = dict.insert({ "right", "ÓÒ±ß" });
	if (ret.second)
	{
		cout << "²åÈë³É¹¦" << endl;
	}
	else
	{
		cout << "²åÈëÊ§°Ü£¬key ÒÑ¾­´æÔÚ" << endl;
	}
}

void test4()
{
	/*multimap<int, string> m;
	m.insert({ 1,"ÕÅÈı" });
	m.insert(pair<int, string>(2, "²Ü¾²"));
	m.insert(make_pair(3, "ÔÃºÀ"));
	m.insert({ 1,"Äß°²¶«" });
	for (auto& kv : m)
	{
		cout << kv.first << ":" << kv.second << endl;
	}*/


	/*vector<int> v = { 1,2,4,5,23,2,5 };

	set<int> s(v.begin(), v.end());

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;*/

	/*set<int> s = { 3, 2, 8, 1, 10, 2 };

	auto pos = s.find(3);

	if (pos != s.end())
	{
		s.erase(pos);
	}
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;*/

}

void test5()
{
	string arr[] = {
	   "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "Æ»¹û",
	   "Ïã½¶", "Æ»¹û", "²İİ®", "²İİ®"
	};

	map<string, int> countMap;
	
	for (auto& e : arr)
	{
		countMap[e]++;
	}

	for (auto e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
}


int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}