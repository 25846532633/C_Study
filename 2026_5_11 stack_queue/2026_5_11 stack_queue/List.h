#pragma once
#include <iostream>
#include <initializer_list>

using namespace std;

namespace bite
{
    template<class T>
    struct ListNode
    {
        ListNode<T>* _prev;
        ListNode<T>* _next;
        T _data;

        ListNode(const T& val = T())
            :_prev(nullptr),
            _next(nullptr),
            _data(val)
        {}
    };

    template<class T, class Ref, class Ptr>
    struct ListIterator
    {
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self;
        PNode _node;

        ListIterator(PNode pNode = nullptr)
            :_node(pNode)
        {}

        ListIterator(const Self& l)
            :_node(l._node)
        {}



        T& operator*()
        {
            return _node->_data;
        }

        T* operator->()
        {
            return &_node->_data;
        }
        //前置++
        Self& operator++()
        {
            _node = _node->_next;
            return *this;
        }
        //后置++
        Self operator++(int)
        {
            Self tmp(*this);
            _node = _node->_next;
            return tmp;
        }

        Self& operator--()
        {
            _node = _node->_prev;
            return *this;
        }

        Self operator--(int)
        {
            Self tmp(*this);
            _node = _node->_prev;
            return tmp;
        }

        bool operator!=(const Self& l)
        {
            return _node != l._node;
        }

        bool operator==(const Self& l)
        {
            return _node == l._node;
        }

    };

    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T*> const_iterator;
        typedef ReverseIterator<iterator, T&, T*> reverse_iterator;
        typedef ReverseIterator<const_iterator, const T&, const T*> const_reverse_iterator;
    public:
        ///////////////////////////////////////////////////////////////
        // List的构造

        void empty_init()
        {
            _head = new Node;
            _head->_next = _head;
            _head->_prev = _head;
            _size = 0;
        }

        list(initializer_list<T> il)
        {
            empty_init();

            for (const auto& e : il)
            {
                push_back(e);
            }
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }

        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }


        list()
        {
            empty_init();
        }
        list(int n, const T& value = T())
        {
            empty_init();
            int i = 0;
            while (i < n)
            {
                push_back(value);
                i++;
            }
        }

        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            empty_init();
            while (first != last)
            {
                push_back(*first);
                first++;
            }
        }
        list(const list<T>& l)
        {
            empty_init();
            for (auto& e : l)
            {
                push_back(e);
            }
        }

        list<T>& operator=(const list<T> l)
        {
            if (this != &l)
            {
                list<T> tmp(l);
                swap(tmp);
            }
            return *this;
            /*Node* cur = _head->_next;
            for (auto e : l)
            {
                cur->_data = e;
                cur = cur->_next;
            }

            return _head;*/
        }

        ~list()
        {
            clear();
            delete _head;
            _head = nullptr;
        }


        ///////////////////////////////////////////////////////////////
        // List Iterator
        iterator begin()
        {
            return iterator(_head->_next);
        }
        iterator end()
        {
            return iterator(_head);
        }
        const_iterator begin() const
        {
            return const_iterator(_head->_next);
        }
        const_iterator end() const
        {
            return const_iterator(_head);
        }


        ///////////////////////////////////////////////////////////////
        // List Capacity
        size_t size()const
        {
            return _size;
        }
        bool empty()const
        {
            return _size == 0;
        }


        ////////////////////////////////////////////////////////////
        // List Access
        T& front()
        {
            return _head->_next->_data;
        }
        const T& front()const
        {
            return _head->_next->_data;
        }
        T& back()
        {
            return _head->_prev->_data;
        }
        const T& back()const
        {
            return _head->_prev->_data;
        }


        ////////////////////////////////////////////////////////////
        // List Modify
        iterator push_back(const T& val)
        {
            return insert(end(), val);
        }
        void pop_back() { erase(--end()); }
        iterator push_front(const T& val)
        {
            return insert(begin(), val);
        }
        void pop_front() { erase(begin()); }
        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val)
        {
            Node* cur = pos._node;
            Node* newnode = new Node(val);
            Node* prev = cur->_prev;

            prev->_next = newnode;
            newnode->_prev = prev;
            newnode->_next = cur;
            cur->_prev = newnode;

            _size++;

            return iterator(newnode);
        }
        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos)
        {
            Node* cur = pos._node;
            Node* prev = cur->_prev;
            Node* next = cur->_next;

            prev->_next = next;
            next->_prev = prev;
            delete cur;
            _size--;

            return iterator(next);
        }
        void clear()
        {
            iterator it = begin();
            while (it != end())
            {
                it = erase(it);
            }
        }
        void swap(list<T>& lt)
        {
            std::swap(_head, lt._head);
            std::swap(_size, lt._size);
        }
    private:
        size_t _size;
        Node* _head;
    };

    // 辅助打印函数
    void PrintList(const list<int>& lst)
    {
        for (auto it = lst.begin(); it != lst.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    void PrintListInfo(const list<int>& lst)
    {
        cout << "size=" << lst.size() << ", empty=" << (lst.empty() ? "true" : "false") << ", elements: ";
        PrintList(lst);
    }


    void test_constructor()
    {
        cout << "\n========== 测试1: 构造和赋值 ==========" << endl;

        // 默认构造
        list<int> lst1;
        cout << "lst1(默认构造): ";
        PrintListInfo(lst1);

        // 带n和value的构造
        list<int> lst2(5, 100);
        cout << "lst2(5,100): ";
        PrintListInfo(lst2);

        // 迭代器区间构造
        int arr[] = { 1, 2, 3, 4, 5 };
        list<int> lst3(arr, arr + 5);
        cout << "lst3(迭代器区间): ";
        PrintListInfo(lst3);

        // 拷贝构造
        list<int> lst4(lst3);
        cout << "lst4(拷贝lst3): ";
        PrintListInfo(lst4);

        // 赋值运算符
        list<int> lst5;
        lst5 = lst3;
        cout << "lst5(赋值lst3): ";
        PrintListInfo(lst5);
    }

    // 测试2: push_back 和返回值
    void test_push_back()
    {
        cout << "\n========== 测试2: push_back ==========" << endl;

        list<int> lst;

        // 不接收返回值
        cout << "不接收返回值: ";
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        PrintList(lst);

        // 接收返回值
        list<int> lst2;
        auto it1 = lst2.push_back(100);
        auto it2 = lst2.push_back(200);
        auto it3 = lst2.push_back(300);

        cout << "接收返回值: ";
        PrintList(lst2);
        cout << "it1指向: " << *it1 << endl;
        cout << "it2指向: " << *it2 << endl;
        cout << "it3指向: " << *it3 << endl;
    }

    // 测试3: push_front
    void test_push_front()
    {
        cout << "\n========== 测试3: push_front ==========" << endl;

        list<int> lst;
        lst.push_back(3);
        lst.push_back(4);
        lst.push_back(5);
        cout << "原始: ";
        PrintList(lst);

        lst.push_front(2);
        lst.push_front(1);
        cout << "push_front 2,1后: ";
        PrintList(lst);
    }

    // 测试4: pop_back 和 pop_front
    void test_pop()
    {
        cout << "\n========== 测试4: pop_back 和 pop_front ==========" << endl;

        list<int> lst;
        for (int i = 1; i <= 5; i++)
            lst.push_back(i);
        cout << "原始: ";
        PrintList(lst);

        lst.pop_back();
        cout << "pop_back后: ";
        PrintList(lst);

        lst.pop_front();
        cout << "pop_front后: ";
        PrintList(lst);

        // 连续删除
        lst.pop_back();
        lst.pop_front();
        cout << "再删头尾各一次: ";
        PrintList(lst);
    }

    // 测试5: insert
    void test_insert()
    {
        cout << "\n========== 测试5: insert ==========" << endl;

        list<int> lst;
        for (int i = 1; i <= 5; i++)
            lst.push_back(i);
        cout << "原始: ";
        PrintList(lst);

        // 头插
        lst.insert(lst.begin(), 100);
        cout << "头插100: ";
        PrintList(lst);

        // 尾插
        lst.insert(lst.end(), 200);
        cout << "尾插200: ";
        PrintList(lst);

        // 中间插入
        auto it = lst.begin();
        ++it; ++it; // 指向第3个元素
        lst.insert(it, 300);
        cout << "第3个位置前插300: ";
        PrintList(lst);

        // 接收返回值
        auto newIt = lst.insert(lst.begin(), 999);
        cout << "插入并返回迭代器，指向: " << *newIt << endl;
        PrintList(lst);
    }

    // 测试7: 迭代器遍历和修改
    void test_iterator()
    {
        cout << "\n========== 测试7: 迭代器 ==========" << endl;

        list<int> lst;
        for (int i = 1; i <= 5; i++)
            lst.push_back(i);

        // 正向遍历
        cout << "正向遍历: ";
        for (auto it = lst.begin(); it != lst.end(); ++it)
            cout << *it << " ";
        cout << endl;

        // 反向遍历
        cout << "反向遍历: ";
        auto it = lst.end();
        while (it != lst.begin())
        {
            --it;
            cout << *it << " ";
        }
        cout << endl;

        // 修改元素
        cout << "修改元素(全部x10): ";
        for (auto it = lst.begin(); it != lst.end(); ++it)
            *it = *it * 10;
        PrintList(lst);

        // const迭代器测试
        const list<int>& const_lst = lst;
        cout << "const迭代器遍历: ";
        for (auto cit = const_lst.begin(); cit != const_lst.end(); ++cit)
            cout << *cit << " ";
        cout << endl;
        // *const_lst.begin() = 100; // 这行会编译错误，正确！
    }

    // 测试8: front 和 back
    void test_front_back()
    {
        cout << "\n========== 测试8: front 和 back ==========" << endl;

        list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);

        cout << "原始: ";
        PrintList(lst);
        cout << "front = " << lst.front() << ", back = " << lst.back() << endl;

        // 修改
        lst.front() = 100;
        lst.back() = 300;
        cout << "修改后: ";
        PrintList(lst);
        cout << "front = " << lst.front() << ", back = " << lst.back() << endl;

        // const版本
        const list<int>& const_lst = lst;
        cout << "const: front = " << const_lst.front() << ", back = " << const_lst.back() << endl;
    }

    // 测试9: clear 和 swap
    void test_clear_swap()
    {
        cout << "\n========== 测试9: clear 和 swap ==========" << endl;

        // clear测试
        list<int> lst1;
        for (int i = 1; i <= 5; i++)
            lst1.push_back(i);
        cout << "clear前: ";
        PrintListInfo(lst1);

        lst1.clear();
        cout << "clear后: ";
        PrintListInfo(lst1);

        // swap测试
        list<int> lst2;
        list<int> lst3;
        for (int i = 1; i <= 3; i++) lst2.push_back(i);
        for (int i = 100; i <= 105; i++) lst3.push_back(i);

        cout << "\nswap前:" << endl;
        cout << "lst2: "; PrintList(lst2);
        cout << "lst3: "; PrintList(lst3);

        lst2.swap(lst3);

        cout << "swap后:" << endl;
        cout << "lst2: "; PrintList(lst2);
        cout << "lst3: "; PrintList(lst3);
    }

    // 测试10: 边界条件
    void test_boundary()
    {
        cout << "\n========== 测试10: 边界条件 ==========" << endl;

        // 空链表操作
        list<int> empty_lst;
        cout << "空链表: ";
        PrintListInfo(empty_lst);

        // 在空链表上插入
        empty_lst.insert(empty_lst.begin(), 999);
        cout << "在空链表insert后: ";
        PrintListInfo(empty_lst);

        // 删到空
        empty_lst.pop_back();
        cout << "pop_back到空后: ";
        PrintListInfo(empty_lst);

        // 再插入
        empty_lst.push_back(888);
        cout << "再push_back后: ";
        PrintListInfo(empty_lst);
    }

    // 测试11: 不同数据类型
    void test_different_types()
    {
        cout << "\n========== 测试11: 不同数据类型 ==========" << endl;

        // string类型
        list<string> strList;
        strList.push_back("hello");
        strList.push_back("world");
        strList.push_back("!");

        cout << "string list: ";
        for (auto it = strList.begin(); it != strList.end(); ++it)
            cout << *it << " ";
        cout << endl;

        // double类型
        list<double> dblList;
        dblList.push_back(1.1);
        dblList.push_back(2.2);
        dblList.push_back(3.3);

        cout << "double list: ";
        for (auto it = dblList.begin(); it != dblList.end(); ++it)
            cout << *it << " ";
        cout << endl;

        // char类型
        list<char> charList;
        charList.push_back('A');
        charList.push_back('B');
        charList.push_back('C');

        cout << "char list: ";
        for (auto it = charList.begin(); it != charList.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }

    // 测试12: 综合场景
    void test_comprehensive()
    {
        cout << "\n========== 测试12: 综合场景 ==========" << endl;

        // 交替插入删除
        list<int> lst;
        cout << "交替操作: ";
        for (int i = 1; i <= 10; i++)
        {
            if (i % 2 == 0)
                lst.push_back(i);
            else
                lst.push_front(i);
        }
        PrintList(lst);

        // 删除所有偶数
        auto it = lst.begin();
        while (it != lst.end())
        {
            if (*it % 2 == 0)
                it = lst.erase(it);
            else
                ++it;
        }
        cout << "删除所有偶数后: ";
        PrintList(lst);

        // 在每个奇数后面插入它的两倍
        it = lst.begin();
        while (it != lst.end())
        {
            int val = *it;
            ++it;
            lst.insert(it, val * 2);
        }
        cout << "每个奇数后插入两倍: ";
        PrintList(lst);
    }
    // 测试13: insert 和 erase 返回值链式调用
    void test_chaining()
    {
        cout << "\n========== 测试13: 链式操作 ==========" << endl;

        list<int> lst;

        // 连续插入
        auto it = lst.insert(lst.begin(), 3);
        it = lst.insert(it, 2);
        it = lst.insert(it, 1);
        cout << "连续前插1,2,3: ";
        PrintList(lst);

        // 连续删除
        it = lst.begin();
        it = lst.erase(it);  // 删1
        it = lst.erase(it);  // 删2
        cout << "连续删除头两个: ";
        PrintList(lst);
    }
}