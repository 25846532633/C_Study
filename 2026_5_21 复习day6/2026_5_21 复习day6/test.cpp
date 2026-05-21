#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;


void test1()
{
	string s1;
	string s2("hello");
	string s3(s2);
	string s4 = s2;
	string s5("abcedf", 3);
	string s6(10, 'x');
}

void test2()
{
	//string s = "hello";

	//cout << s.size() << endl;      // 5
	//cout << s.capacity() << endl;  // 当前容量

	//s.clear();
	//cout << s.size() << endl;      // 0
	//cout << s.capacity() << endl;  // 容量通常不变

	//s.reserve(100);                // 预留空间
	//s.resize(10, 'x');             // size 变成 10，多出来的用 x 填充
	//cout << s.size() << endl;     //10
	//cout << s.capacity() << endl;  //111

	/*string s2("hello");
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	cout << "第一次扩容,  size < n < capacity:" << endl;
	s2.resize(10);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	cout << "第二次扩容，n > capacity:" << endl;
	s2.resize(20);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;*/

	string s2("hello");
	/*cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	s2.reserve(10);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	s2.reserve(50);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	for (auto it = s2.begin(); it != s2.end(); ++it)
	{
		cout << *it << " ";
	}*/
	/*for (auto ch : s2)
	{
		cout << ch << " ";
	}*/
}

//void test3()
//{
//	/*string s1 = "hello";*/
//	//cout << s[10] << endl;
//	/*cout << s.at(10) << endl;*/
//
//	/*s.push_back('!');
//	cout << s << endl;
//	s += "jo";
//	cout << s << endl;*/
//
//	/*s.append("hallo");
//	cout << s << endl;
//	*/
//	//string s1 = "hello";
//	///*size_t pos1 = s1.find('c');
//	//size_t pos2 = s1.find("ell");
//	//if (pos2 == -1)
//	//	cout << "fail" << endl;*/
//
//	//size_t pos1 = s1.rfind("oll");
//	//if (pos1 == -1)
//	//	cout << "out" << endl;
//
//	/*string s = "abcdef";
//	s.insert(2, "XXX");
//	cout << s << endl;*/
//
//	//string str = "We are right now";
//	//string str2 = str.substr(3);
//	//cout << str2 << endl;//are right now
//	//size_t pos = str.find("right");
//	//if (pos != string::npos)
//	//{
//	//	string str4 = str.substr(pos);
//	//	cout << str4 << endl;
//	//}
//
//	/*string s = "hello";
//	const char* p = s.c_str();
//	cout << *p << endl;
//	cout << typeid(s).name() << endl;
//	cout << typeid(p).name() << endl;*/
//
//	//string s;
//	//cin >> s;
//	//cout << s << endl;
//	///*cin.ignore(10000,'\n');*/
//	//getline(cin, s);
//	//cout << s << endl;
//
//	/*double x = 3.1415926;
//	cout << fixed << setprecision(2) << x << endl;
//
//	cout << setw(10) << x << endl;*/
//	string line = "aa bb cc";
//	stringstream ss(line);
//	string word;
//	while (ss >> word)
//	{
//		cout << word << endl;
//	}
//}

string addStrings(string num1, string num2)
{
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	int carry = 0;
	string ret;
	while (i >= 0 || j >= 0 || carry)
	{
		int x = i >= 0 ? num1[i--] - '0' : 0;
		int y = j >= 0 ? num2[j--] - '0' : 0;
		
		int sum = x + y + carry;
		carry = sum / 10;
		ret += sum % 10 + '0';
	}

	reverse(ret.begin(), ret.end());
	return ret;
}


int main()
{
	string str = addStrings("123", "23");
	cout << str << endl;
	//test1();
	//test2();
	//test3();
	return 0;
}