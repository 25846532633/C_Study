#include <fstream>
#include <iostream>
using namespace std;
//int main()
//{
//    fstream fs(
//        "test.txt",
//        ios::in | ios::out | ios::trunc
//    );
//
//    if (!fs)
//    {
//        std::cerr << "文件打开失败\n";
//        return 1;
//    }
//
//    // 使用 ostream 部分
//    fs << "100 200";
//    fs.flush();
//
//    // 将读取位置移动到开头
//    fs.seekg(0, ios::beg);
//
//    // 使用 istream 部分
//    int x = 0;
//    int y = 0;
//    fs >> x >> y;
//
//    std::cout << x << ' ' << y << '\n';
//}\

//int main()
//{
//	int x = 0;
//	std::ios_base::sync_with_stdio(false);//取消C++标准流与C标准流的同步
//	cin.tie(nullptr);// 解除cin和cout的绑定
//	//以前:cin.tie() == cout
//	cout << "请输入一个整数:";
//	cin >> x;
//	return 0;
// 
// 
// 
//}



#include <iostream>

int main()
{
    int x = 100;
    std::cin >> x;

    cout << "x = " << x << '\n';
    cout << "fail = " << std::cin.fail() << '\n';

    cin.clear();

    char ch = '\0';
    while (cin.get(ch) && ch != '\n');
    cin >> x;
    cout << "x = " << x << '\n';
    cout << "fail = " << std::cin.fail() << '\n';
}