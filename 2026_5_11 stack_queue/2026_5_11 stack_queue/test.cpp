//#include "Stack.h"
//#include "queue.h"
#include "priority_queue.h"
#include "List.h"


//void test_op1() {
//    srand(time(0));
//    const int N = 1000000;
//
//    deque<int> dq;
//    vector<int> v;
//
//    for (int i = 0; i < N; ++i) {
//        auto e = rand() + i;
//        v.push_back(e);
//        dq.push_back(e);
//    }
//
//    int begin1 = clock();
//    sort(v.begin(), v.end());
//    int end1 = clock();
//
//    int begin2 = clock();
//    sort(dq.begin(), dq.end());
//    int end2 = clock();
//
//    printf("vector:%d\n", end1 - begin1);
//    printf("deque:%d\n", end2 - begin2);
//}
//
//void test2()
//{
//    bite::Stack<int> t1;
//    t1.push(1);
//    t1.push(2);
//    t1.push(3);
//
//    while (!t1.empty())
//    {
//        cout << t1.top() << endl;
//        t1.pop();
//    }
//
//   std::deque<int> mydeque = { 1, 2, 3, 4 };
//
//    const bite::Stack<int> t2(mydeque);
//    cout << t2.top() << endl;
//    /*t2.push(1);
//    t2.push(2);
//    t2.push(3);*/
//
//   /* while (!t1.empty())
//    {
//        cout << t2.top() << endl;
//        t1.top()++;
//    }
//    cout << endl;*/
//}
//
//void test3()
//{
//    bite::queue<int> q;
//    q.push(1);
//    q.push(2);
//    q.push(3);
//    q.push(4);
//
//    while (!q.empty())
//    {
//        cout << q.front() << " ";
//        q.pop();
//    }
//    cout << endl;
//}
//
//bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
//{
//    bite::Stack<int> v;
//    int pushi = 0, popi = 0;
//    while (pushi < pushV.size())
//    {
//        v.push(pushV[pushi]);
//        pushi++;
//        while (!popV.empty() && v.top() == popV[popi])
//        {
//            v.pop();
//            popi++;
//        }
//    }
//    return v.empty();
//}


//int findKthLargest(vector<int>& nums, int k)
//{
//    priority_queue<int,greater<int>> t1;
//    for (auto& e : nums)
//    {
//        if (t1.size() < k)
//        {
//            t1.push(e);
//        }
//        else if (e > t1.top())
//        {
//            t1.pop();
//            t1.push(e);
//        }
//    }
//    return t1.top();
//}

void test4()
{
	bite::list<int> lt = { 1,2,3,4 };
	bite::list<int>::reverse_iterator rit = lt.rbegin();
	while (rit != lt.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}


int main()
{
	//test_op1();
    //test2();
   // test3();
    /*bite::test_priority_queue();*/
	test4();
	return 0;
}