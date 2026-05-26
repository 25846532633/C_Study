#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//void test01()
//{
//	/*stack<int> a;
//	a.push(1);
//	a.push(2);
//	while (!a.empty())
//	{
//		cout << a.top() << endl;
//		a.pop();
//	}*/
//
//	queue<int> q;
//	q.push(1);
//	q.push(1);
//	q.push(3);
//
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}
//	cout << endl;
//}

bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
{
	stack<int> st;
	int popi = 0;
	for (auto& e : pushV)
	{
		st.push(e);
		while (!st.empty() && st.top() == popV[popi])
		{
			st.pop();
			popi++;
		}
	}
	return st.empty();

}

int evalRPN(vector<string>& tokens)
{
	stack<int> st;
	for (auto& e : tokens)//e - string - "as.."
	{
		if (e == "+" || e == "-" || e == "*" || e == "/")
		{
			int right = st.top(); st.pop();
			int left = st.top(); st.pop();
			switch (e[0])
			{
			case '+':
				st.push(right + left); break;
			case '-':
				st.push(left - right); break;
			case '*':
				st.push(left * right); break;
			case'/':
				st.push(left / right); break;
			}
		}
		else 
		{
			st.push(stoi(e));
		}
	}
	return st.top();
}


class MyQueue 
{
public:
	void push(int x)
	{
		pushStack.push(x);
	}

	int pop()
	{
		if (popStack.empty())
		{
			transfer();
		}
		int top = popStack.top();
		popStack.pop();
		return top;
	}

	int front()
	{
		if (popStack.empty())
			transfer();
		return popStack.top();
	}
private:
	stack<int> pushStack;
	stack<int> popStack;

	void transfer()
	{
		while (!pushStack.empty())
		{
			popStack.push(pushStack.top());
			pushStack.pop();
		}
	}
};


int main()
{
	//test01();
	return 0;
}