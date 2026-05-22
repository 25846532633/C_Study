#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//int main()
//{
//	vector<int> v1;
//	vector<int> v2(3);//3个0
//	vector<int> v3(3, 25);
//	vector<string> v4(3, "hello");
//
//
//	//这里的拷贝构造都是深拷贝
//	vector<int> v5(v2);
//	vector<int> v6 = v2;
//	
//	vector<int> v7(v6.begin()+1, v6.end());
//	
//	
//	vector<int> v8 = { 1,2,3,4,5 };
//
//	//vector<int> createVector() 
//	//{
//	//	vector<int> temp = { 1,2,3,4,5 };
//	//	return temp;
//	//}//不会产生额外的拷贝
//	//vector<int> v16 = createVector();
//	for (auto c : v8)
//	{
//		cout << c << " ";
//	}
//
//
//
//	return 0;
//}

//int main()
//{
//	vector<int> v1 = { 10,20,30,40,50 };
//
//	for (size_t i = 0; i < v1.size(); i++)
//	{
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	for_each(v1.begin(), v1.end(), [](int x) {cout << x << " ";});
//	cout << endl;
//	for (auto it = v1.rbegin(); it != v1.rend(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	vector<int> v1 = { 1,2,3,4,5 };
//	cout << v1.size() << endl;
//	cout << v1.capacity() << endl;
//	v1.reserve(100);
//	cout << v1.size() << endl;
//	cout << v1.capacity() << endl;
//	v1.resize(20,'x');
//	cout << v1.size() << endl;
//	cout << v1.capacity() << endl;
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	return 0;
//}


//#include <stdexcept>
//
//
//int main() {
//    vector<int> v = { 1, 2, 3 };
//
//    // v[5] = 10;      // 越界！不报错，未定义行为（可能崩也可能不崩）
//
//    try {
//        v.at(5) = 10;  // 越界！抛出 std::out_of_range 异常
//    }
//    catch (const out_of_range& e) {
//        cout << "捕获异常：" << e.what() << endl;
//    }
//
//    return 0;
//}

//void c_style_func(const int* arr, size_t n) {
//    for (size_t i = 0; i < n; ++i) {
//        printf("%d ", arr[i]);
//    }
//}
//
//
//int main()
//{
//	vector<int> v = { 1, 2, 3, 4, 5 };
//    c_style_func(v.data(), v.size());  // 输出: 1 2 3 4 5
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Person {
//public:
//    string name;
//    int age;
//
//    Person(const string& n, int a) : name(n), age(a) {
//        cout << "Person 构造：" << name << endl;
//    }
//    Person(const Person& other) : name(other.name), age(other.age) {
//        cout << "Person 拷贝构造：" << name << endl;
//    }
//    Person(Person&& other) noexcept : name(move(other.name)), age(other.age) {
//        cout << "Person 移动构造：" << name << endl;
//    }
//};
//
//int main() {
//    vector<Person> v;
//    v.reserve(10);  // 提前预留空间，避免扩容干扰观察
//
//    cout << "=== push_back ===" << endl;
//    v.push_back(Person("Alice", 25));
//    // 输出：构造 → 移动构造
//
//    cout << "=== emplace_back ===" << endl;
//    v.emplace_back("Bob", 30);
//    // 输出：构造（只有一次！）
//
//    return 0;
//}



//int main()
//{
//	vector<int> v = { 1, 2, 3, 4, 5 };
//	
//	/*auto it = v.begin() + 2;
//	v.insert(it, 10);
//	*/
//
//	//v.insert(v.begin(), 3, 0);
//	vector<int> extra = { 100,200 };
//	//v.insert(v.end(), extra.begin(), extra.end());//1.2.3.4.5.100,200
//	//v.erase(v.begin());//2.3.4.5.100.200
//	//v.erase(v.begin() + 1, v.begin() + 3);//2/5/100/200
//	
//	
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//
//	return 0;
//}




int main()
{

	return 0;
}