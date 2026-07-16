#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;
//template<class F, class T>
//T useF(F f, T x,T y)
//{
//	static int count = 0;
//
//	cout << "count: " << ++count << endl;
//	cout << "address: " << &count << endl;
//
//	return f(x,y);
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//struct Functor
//{
//	int operator()(int x, int y)
//	{
//		return x + y;
//	}
//};
//
//int main()
//{
//	function<int(int, int)> func1 = Add;
//	function<int(int, int)> func2 = Functor();
//	function<int(int, int)> func3 = [](int x ,int y)->int
//		{
//			return x + y;
//		};
//	//cout << &func1 << endl << &func2 << endl << &func3 << endl;
//
//	//调用的时候，包装器进行了包装，不同的可调用对象的functino类型相同
//	//所以最后只会实例化一份对应的可调用对象
//	cout << useF(func1, 1,2) << endl;
//	cout << useF(func2, 1,2) << endl;
//	cout << useF(func3, 2,2) << endl;
//	return 0;
//}



//class Plus
//{
//public:
//    /*static int plusi(int x, int y)
//    {
//        return x + y;
//    }*/
//
//    double plusd(double x, double y)
//    {
//        return x + y;
//    }
//
//};
//
//
//int main()
//{
//    //function<int(int, int)> func = &Plus::plusi;
//    //Plus -> Plus对象（左值右值都可以）
//    //Plus* -> Plus对象的地址（但是右值不行）
//    /*function<double(Plus,double, double)> func = &Plus::plusd;*/
//    function<double(Plus*, double, double)> func = &Plus::plusd;
//    Plus plus;
//    // 不行 - cout << func(&Plus(), 1, 2) << endl;
//    cout << func(&plus, 1, 2) << endl;
//    return 0;
//}



//int Sub(int& z,int x, int y)
//{
//	z++;
//	return x - y + z;
//}
//
////void PrintState(const string& name, int hp, int mp)
////{
////	cout << name << " -> [血量:" << hp
////		<< ", 蓝量:" << mp << "]" << endl;
////}
//
//
//
//int main()
//{
//	//1.参数顺序的调换
//	//_1 _2 -> 参数顺序：我们可以也可以自己调换
//	/*auto func = bind(Sub, placeholders::_2, placeholders::_1);
//	cout << func(5, 10) << endl;*/
//
//	//2.固定某些参数，减少新函数的参数个数
//	/*function<void(int,int)> player1 = bind(PrintState, "曹操", _1, _2);
//	player1(80, 20);
//	player1(8, 20);
//	player1(40, 20);
//	
//
//	function<void(string, int)> func = bind(PrintState, _1, 80, _2);
//	func("武则天", 50);
//	func("韩信", 40);*/
//	
//	//3.需要修改传入的参数时，需要用引用接收，并且必须用ref包裹住
//	int z = 10;
//	auto func = bind(Sub,ref(z), _1,_2);
//	cout << func(10, 20) << endl;
//	cout << z << endl;
//	return 0;
//}

//class Sub
//{
//public:
//	Sub(int factor)
//		:_factor(factor)
//	{}
//
//	int sub(int x, int y)
//	{
//		return (x - y) * _factor;
//	}
//private:
//	int _factor;
//};
//
//int main()
//{
//	//1.不绑定对象
//	auto func = bind(&Sub::sub, _1, _2, _3);
//	cout << func(Sub(10), 10, 5) << endl;
//
//	//2.提前绑定对象
//	auto func2 = bind(&Sub::sub, Sub(1), _1, _2);
//	cout << func2(10, 5) << endl;
//	return 0;
//}

#include <thread>              // thread、this_thread
#include <mutex>               // mutex、lock_guard、unique_lock
#include <atomic>              // atomic
#include <condition_variable>  // condition_variable
#include <chrono>               //时间与sleep_for


//void ThreadFunc(int x)
//{
//    cout << "ordinary function: " << x << endl;
//}
//
//struct Task
//{
//    void operator()() const
//    {
//        cout << "function object" << endl;
//    }
//};
//
//int main()
//{
//    thread t; // 构造了一个线程对象
//
//    thread t1(ThreadFunc, 10);
//    cout << "t1 id: " << t1.get_id() << endl;
//    t1.join();
//   
//    Task task;
//    thread t2(task);
//    cout << "t2 id: " << t2.get_id() << endl;
//    t2.join();
//    
//    thread t3([]
//        {
//            cout << "lambda" << endl;
//        });
//    cout << "t3 id: " << t3.get_id() << endl;
//    t3.join(); //join - 等待进程结束，join会让调用的线程阻塞
//    //等待对应关联的线程执行完毕，然后继续向后运行
//    
//    cout << "main thread id: "<< this_thread::get_id()<< endl;
//    return 0;
//}

//void BackgroundTask(std::string message)
//{
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//    std::cout << "后台线程：" << message << '\n';
//}
//
//int main()
//{
//    std::thread t(BackgroundTask, std::string("日志写入完成"));
//
//    std::cout << "detach 前：" << t.joinable() << '\n';
//
//    t.detach();
//
//    std::cout << "detach 后：" << t.joinable() << '\n';
//
//    std::cout << "主线程继续执行其他工作\n";
//
//    // 仅为了演示，让进程不要过早结束
//    std::this_thread::sleep_for(std::chrono::seconds(2));
//
//    return 0;
//}

//#include <iostream>
//#include <thread>
//
//void Task()
//{
//    std::cout << "子线程正在运行\n";
//}
//
//int main()
//{
//    std::thread t;
//    std::cout << "默认构造后：" << t.joinable() << '\n';
//
//    t = std::thread(Task);
//    std::cout << "关联线程后：" << t.joinable() << '\n';
//    if (t.joinable())
//    {
//        t.join();
//    }
//    std::cout << "调用 join 后：" << t.joinable() << '\n';
//
//    return 0;
//}

//void Add(int& x)
//{
//	x += 10;
//}

//void Add(int* px)
//{
//	*px += 10;
//}

//void Add(int n, int& x, mutex& mtx)
//{
//    mtx.lock();
//
//    for (int i = 0; i < n; ++i)
//    {
//        ++x;
//    }
//
//    mtx.unlock();
//}
//
//int main()
//{
//	int x = 0;
//    mutex mtx;
//	thread t1(Add,100000,ref(x),ref(mtx));
//
//	t1.join();
//	cout << x << endl;
//
//	return 0;
//}

//class Task
//{
//public:
//    void Run(int x)
//    {
//        cout << x << endl;
//    }
//};
//
//int main()
//{
//    Task task;
//    thread t1(&Task::Run, &task, 10);
//    t1.join();
//}

//mutex mtx;
//避免出现更新丢失的现象：1.要修改的变量改为原子性 2.加锁
//atomic<int> sum = 0;
//void Add(size_t n)
//{
//    for (size_t i = 0; i < n; ++i)
//    {
//        //mtx.lock();
//        ++sum;
//       // mtx.unlock();
//    }
//}
//
//int main()
//{
//    thread t1(Add, 1000000);
//    thread t2(Add, 2000000);
//    t1.join();
//    t2.join();
//    cout << sum << endl;
//    //sum = 10;
//    sum.store(10);
//
//    //原子对象之间的赋值只能通过store，而不是=
//    printf("%d", sum.load());//print打印的时候，需要用load加载
//    return 0;
//
//}
//
//int main()
//{
//	int x = 0;
//	mutex mtx;
//	{
//		lock_guard<mutex> lock(mtx);//构造时lock，出作用域自动unlock
//		++x;
//	}
//}

//mutex mtx;
//condition_variable cv;
//bool ready = false;
//
//void PrintId(int id)
//{
//    //所有成功进入 cv.wait(lck) 的线程，都会释放 mtx，进入阻塞状态
//    // 并被挂到条件变量 cv 对应的等待队列（等待集合）中
//    unique_lock<mutex> lck(mtx);
//    while (!ready)
//    {
//        cv.wait(lck);
//    }
//    cout << "thread " << id << '\n';
//}
//
//void Go()
//{
//    {
//        lock_guard<mutex> lock(mtx);
//        ready = true;
//    }
//    cv.notify_all();
//}
//
//int main()
//{
//    thread threads[10];
//    for (int i = 0; i < 10; ++i)
//    {
//        threads[i] = thread(PrintId, i);
//    }
//    cout << "10 threads ready to race...\n";
//    this_thread::sleep_for(chrono::milliseconds(100));
//    Go();
//    for (auto& th : threads)
//    {
//        th.join();
//    }
//
//    return 0;
//}

//void TwoThreadPrint()
//{
//    mutex mtx;
//    condition_variable cv;
//
//    const int n = 100;
//    bool flag = true;
//
//    // 偶数线程
//    thread t1([&]
//    {
//        int i = 0;
//        while (i < n)
//        {
//            unique_lock<mutex> lck(mtx);
//            cv.wait(lck, [&]
//                {
//                    return flag;
//                });
//            cout << i << endl;
//            i += 2;
//            flag = false;
//            cv.notify_one();
//        }
//    });
//
//    // 奇数线程
//    thread t2([&]
//    {
//        int j = 1;
//        while (j < n)
//        {
//            unique_lock<mutex> lck(mtx);
//            cv.wait(lck, [&]
//                {
//                    return !flag;
//                });
//            cout << j << endl;
//            j += 2;
//            flag = true;
//            cv.notify_one();
//        }
//    });
//    t1.join();
//    t2.join();
//}
//
//int main()
//{
//    TwoThreadPrint();
//    return 0;
//}