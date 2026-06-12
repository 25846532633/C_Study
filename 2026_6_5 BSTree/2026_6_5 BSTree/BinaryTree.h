//#pragma once
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//
//namespace key_value
//{
//	template<class K,class V>
//	struct BSTreeNode
//	{
//		BSTreeNode<K,V>* _left; //左子节点
//		BSTreeNode<K,V>* _right; //右子节点
//		K _key; // 存储的关键值
//		V _value;
//
//		BSTreeNode(const K& key,const V& value)
//			:_left(nullptr),
//			_right(nullptr),
//			_key(key),
//			_value(value)
//		{}
//	};
//
//
//	template<class K,class V>
//	class BSTree
//	{
//		typedef BSTreeNode<K,V> Node;
//	public:
//		Node* Find(const K& key)
//		{
//			Node* cur = _root;
//			while (cur)
//			{
//				if (cur->_key < key)
//				{
//					cur = cur->_right;
//				}
//				else if (cur->_key > key)
//				{
//					cur = cur->_left;
//				}
//				else
//				{
//					return cur;
//				}
//			}
//			return cur;
//		}
//
//		bool Insert(const K& key,const V& value)
//		{
//			if (_root == nullptr)
//			{
//				_root = new Node(key,value);
//				return true;
//			}
//
//			Node* parent = nullptr;
//			Node* cur = _root;
//
//			while (cur)
//			{
//				if (cur->_key < key)
//				{
//					parent = cur;
//					cur = cur->_right;
//				}
//				else if (cur->_key > key)
//				{
//					parent = cur;
//					cur = cur->_left;
//				}
//				else
//				{
//					return false;
//				}
//			}
//
//			cur = new Node(key,value);
//			//看看挂父亲的哪一边
//			if (parent->_key < key)
//				parent->_right = cur;
//			else
//				parent->_left = cur;
//
//			return true;
//		}
//
//
//		bool Erase(const K& key)
//		{
//			Node* parent = nullptr;
//			Node* cur = _root;
//			while (cur)
//			{
//				if (cur->_key < key)
//				{
//					parent = cur;
//					cur = cur->_right;
//				}
//				else if (cur->_key > key)
//				{
//					parent = cur;
//					cur = cur->_left;
//				}
//				else
//				{
//					//左为空，父亲指向我的右
//					if (cur->_left == nullptr)
//					{
//						if (cur == _root)
//						{
//							_root = cur->_right;
//						}
//						else
//						{
//							if (cur == parent->_left)
//							{
//								parent->_left = cur->_right;
//							}
//							else
//							{
//								parent->_right = cur->_right;
//							}
//						}
//
//						delete cur;
//					}
//					else if (cur->_right == nullptr)
//					{
//						//右为空，父亲指向我的左
//						if (cur == _root)
//						{
//							_root = cur->_left;
//						}
//						else
//						{
//							if (cur == parent->_left)
//							{
//								parent->_left = cur->_left;
//							}
//							else
//							{
//								parent->_right = cur->_left;
//							}
//						}
//						delete cur;
//					}
//					else
//					{
//						Node* rightMinParent = cur;
//						Node* rightMin = cur->_right;
//
//						//找到右子树的最左节点 - 右边最小的节点
//						while (rightMin->_left)
//						{
//							rightMinParent = rightMin;
//							rightMin = rightMin->_left;
//						}
//
//						swap(cur->_key, rightMin->_key);
//
//						if (rightMinParent->_left == rightMin) {
//							rightMinParent->_left = rightMin->_right;
//						}
//						else {
//							rightMinParent->_right = rightMin->_right;
//						}
//
//						delete rightMin;
//					}
//					return true;
//				}
//			}
//			return false;
//		}
//		void InOrder()
//		{
//			_InOrder(_root);
//			cout << endl;
//		}
//	private:
//		void _InOrder(Node* root)
//		{
//			if (root == nullptr)
//			{
//				return;
//			}
//
//			_InOrder(root->_left);
//			cout << root->_key << ":" << root->_value << endl;
//			_InOrder(root->_right);
//		}
//	private:
//		Node* _root = nullptr;
//	};
//
//	void TestBSTree2()
//	{
//		BSTree<string, string> dict;
//		dict.Insert("string", "字符串");
//		dict.Insert("left", "左边");
//		dict.Insert("insert", "插入");
//		//...
//
//		string str;
//		while (cin >> str)
//		{
//			BSTreeNode<string, string>* ret = dict.Find(str);
//			if (ret)
//			{
//				cout << ret->_value << endl;
//			}
//			else
//			{
//				cout << "无此单词，请重新输入" << endl;
//			}
//		}
//	}
//
//
//	void TestBSTree3()
//	{
//		string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
//					 "苹果", "香蕉", "苹果", "香蕉", "苹果", "草莓", "苹果", "草莓" };
//
//		BSTree<string, int> countTree;
//
//		for (auto& str : arr)
//		{
//			auto ret = countTree.Find(str);
//			if (ret == nullptr)
//			{
//				countTree.Insert(str, 1);
//			}
//			else
//			{
//				ret->_value++;
//			}
//		}
//
//		countTree.InOrder();
//	}
//};
//
//namespace key
//{
//	template<class K>
//	struct BSTreeNode
//	{
//		BSTreeNode<K>* _left; //左子节点
//		BSTreeNode<K>* _right; //右子节点
//		K _key; // 存储的关键值
//
//		BSTreeNode(const K& val)
//			:_left(nullptr),
//			_right(nullptr),
//			_key(val)
//		{}
//	};
//
//
//	template<class K>
//	class BSTree
//	{
//		typedef BSTreeNode<K> Node;
//	public:
//		bool Find(const K& val)
//		{
//			Node* cur = _root;
//			while (cur)
//			{
//				if (cur->_key < val)
//				{
//					cur = cur->_right;
//				}
//				else if (cur->_key > val)
//				{
//					cur = cur->_left;
//				}
//				else
//				{
//					return true;
//				}
//			}
//			return false;
//		}
//
//		bool Insert(const K& val)
//		{
//			if (_root == nullptr)
//			{
//				_root = new Node(val);
//				return true;
//			}
//
//			Node* parent = nullptr;
//			Node* cur = _root;
//
//			while (cur)
//			{
//				if (cur->_key < val)
//				{
//					parent = cur;
//					cur = cur->_right;
//				}
//				else if (cur->_key > val)
//				{
//					parent = cur;
//					cur = cur->_left;
//				}
//				else
//				{
//					return false;
//				}
//			}
//
//			cur = new Node(val);
//			//看看挂父亲的哪一边
//			if (parent->_key < val)
//				parent->_right = cur;
//			else
//				parent->_left = cur;
//
//			return true;
//		}
//
//
//		bool Erase(const K& val)
//		{
//			Node* parent = nullptr;
//			Node* cur = _root;
//			while (cur)
//			{
//				if (cur->_key < val)
//				{
//					parent = cur;
//					cur = cur->_right;
//				}
//				else if (cur->_key > val)
//				{
//					parent = cur;
//					cur = cur->_left;
//				}
//				else
//				{
//					//左为空，父亲指向我的右
//					if (cur->_left == nullptr)
//					{
//						if (cur == _root)
//						{
//							_root = cur->_right;
//						}
//						else
//						{
//							if (cur == parent->_left)
//							{
//								parent->_left = cur->_right;
//							}
//							else
//							{
//								parent->_right = cur->_right;
//							}
//						}
//
//						delete cur;
//					}
//					else if (cur->_right == nullptr)
//					{
//						if (cur == _root)
//						{
//							_root = cur->_left;
//						}
//						else
//						{
//							if (cur == parent->_left)
//							{
//								parent->_left = cur->_left;
//							}
//							else
//							{
//								parent->_right = cur->_left;
//							}
//						}
//						delete cur;
//					}
//					else
//					{
//						Node* rightMinParent = cur;
//						Node* rightMin = cur->_right;
//
//						//找到右子树的最左节点 - 右边最小的节点
//						while (rightMin->_left)
//						{
//							rightMinParent = rightMin;
//							rightMin = rightMin->_left;
//						}
//
//						swap(cur->_key, rightMin->_key);
//
//						if (rightMinParent->_left == rightMin) {
//							rightMinParent->_left = rightMin->_right;
//						}
//						else {
//							rightMinParent->_right = rightMin->_right;
//						}
//
//						delete rightMin;
//					}
//					return true;
//				}
//			}
//			return false;
//		}
//		void InOrder()
//		{
//			_InOrder(_root);
//			cout << endl;
//		}
//	private:
//		void _InOrder(Node* root)
//		{
//			if (root == nullptr)
//			{
//				return;
//			}
//
//			_InOrder(root->_left);
//			cout << root->_key << " ";
//			_InOrder(root->_right);
//		}
//	private:
//		Node* _root = nullptr;
//	};
//
//	void TestBSTree1() {
//		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//		BSTree<int> t1;
//		for (auto e : a) {
//			t1.Insert(e);
//		}
//
//		t1.InOrder();         // 中序遍历：1 3 4 6 7 8 10 13 14
//
//		t1.Erase(8);          // 删除根节点
//		t1.InOrder();         // 1 3 4 6 7 10 13 14
//
//		// 依次删除所有节点
//		for (auto e : a) {
//			t1.Erase(e);
//			t1.InOrder();
//		}
//	}
//}