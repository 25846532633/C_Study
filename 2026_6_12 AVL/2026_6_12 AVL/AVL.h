#pragma once
#include <iostream>
#include <assert.h>
#include <algorithm>
using namespace std;

namespace AVL
{
	template<class K, class V>
	struct AVLTreeNode
	{
		AVLTreeNode<K, V>* _left;
		AVLTreeNode<K, V>* _right;
		AVLTreeNode<K, V>* _parent;
		pair<K, V> _kv;

		int _bf;

		AVLTreeNode(const pair<K, V>& kv)
			:_left(nullptr),
			_right(nullptr),
			_parent(nullptr),
			_kv(kv),
			_bf(0)
		{}
	};

	template<class K,class V>
	class AVLTree
	{
		typedef AVLTreeNode<K, V> Node;
	public:
		bool Insert(const pair<K, V>& kv)
		{
			//1.是空树
			if (_root == nullptr)
			{
				_root = new Node(kv);
				return true;
			}

			//2.按照BST的规则找位置
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_kv.first < kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if(cur->_kv.first > kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;//已存在
				}
			}

			//3.放入新节点
			cur = new Node(kv);
			if (parent->_kv.first > kv.first)
				parent->_left = cur;
			else
				parent->_right = cur;
			cur->_parent = parent;


			//4.更新平衡银子
			while (parent)
			{
				//1.先更新parent的平衡因子 - 左边--，右边++
				if (cur == parent->_left)
				{
					parent->_bf--;
				}
				else
				{
					parent->_bf++;
				}


				//2.通过平衡因子判断当前子树是否符合AVL树的要求
				if (parent->_bf == 0) // 1、-1->0
				{
					break;
				}
				else if(parent->_bf == 1 || parent->_bf == -1)// 0 -> 1、-1
				{
					//向上更新
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					if (parent->_bf == -2 && cur->_bf == -1)
					{
						RotateR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == 1)
					{
						RotateL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == 1)
					{
						RotateLR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == -1)
					{
						RotateRL(parent);
					}
					else
					{
						assert(false);
					}
					break;
				}
			}
			return true;
		}

		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			parent->_left = subLR;
			if (subLR)
			{
				subLR->_parent = parent;
			}
			subL->_right = parent;

			Node* ppNode = parent->_parent;
			parent->_parent = subL;
			if (parent == _root)
			{
				_root = subL;
				_root->_parent = nullptr;
			}
			else
			{
				if (ppNode->_left == parent)
					ppNode->_left = subL;
				else
					ppNode->_right = subL;

				subL->_parent = ppNode;
			}

			parent->_bf = subL->_bf = 0;
		}

		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			parent->_right = subRL;
			if (subRL)
			{
				subRL->_parent = parent;
			}
			subR->_left = parent;

			Node* ppNode = parent->_parent;
			parent->_parent = subR;

			if (parent == _root)
			{
				_root = subR;
				_root->_parent = nullptr;
			}
			else
			{
				if (parent == ppNode->_left)
					ppNode->_left = subR;
				else
					ppNode->_right = subR;

				subR->_parent = ppNode;
			}

			parent->_bf = subR->_bf = 0;
		}

		void RotateRL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			int bf = subRL->_bf;

			RotateR(subR);
			RotateL(parent);

			subRL->_bf = 0;
			if (bf == 1)
			{
				subR->_bf = 0;
				parent->_bf = -1;
			}
			else if (bf == -1)
			{
				parent->_bf = 0;
				subR->_bf = 1;
			}
			else
			{
				parent->_bf = 0;
				subR->_bf = 0;
			}
		}

		void RotateLR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			int bf = subLR->_bf;

			RotateL(parent->_left);
			RotateR(parent);

			if (bf == -1)
			{
				subLR->_bf = 0;
				subL->_bf = 0;
				parent->_bf = 1;
			}
			else if (bf == 1)
			{
				subLR->_bf = 0;
				subL->_bf = -1;
				parent->_bf = 0;
			}
			else if (bf == 0)
			{
				subLR->_bf = 0;
				subL->_bf = 0;
				parent->_bf = 0;
			}
			else
			{
				assert(false);
			}
		}

		bool IsBalance()
		{
			return _IsBalance(_root);
		}

		int Height()
		{
			return _Height(_root);
		}

		int Size()
		{
			return _Size(_root);
		}

		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_kv.first < key)
				{
					cur = cur->_right;
				}
				else if (cur->_kv.first > key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}

			return nullptr;
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_InOrder(root->_left);
			cout << root->_kv.first << ":" << root->_kv.second << endl;
			_InOrder(root->_right);
		}
	private:

		int _Size(Node* root)
		{
			if (root == nullptr)
				return 0;

			return  _Size(root->_left) + _Size(root->_right) + 1;
		}

		int _Height(Node* root)
		{
			if (root == nullptr)
				return 0;

			return 1 + max(_Height(root->_left), _Height(root->_right));
		}

		bool _IsBalance(Node* root)
		{
			if (root == nullptr)
				return true;

			int leftHeight = _Height(root->_left);
			int rightHeight = _Height(root->_right);

			if(abs(leftHeight - rightHeight) >= 2)
			{
				cout << root->_kv.first << endl;
				return false;
			}
			if (rightHeight - leftHeight != root->_bf)
			{
				cout << root->_kv.first << endl;
				return false;
			}

			return _IsBalance(root->_left) && _IsBalance(root->_right);
		}


	private:
		Node* _root = nullptr;
	};

	void TestAVLTree1()
	{
		//int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
		AVLTree<int, int> t1;
		for (auto e : a)
		{
			/*if (e == 4)
			{
				int i = 0;
			}*/

			// 1、先看是插入谁导致出现的问题
			// 2、打条件断点，画出插入前的树
			// 3、单步跟踪，对比图一一分析细节原因
			t1.Insert({ e,e });

			cout << "Insert:" << e << "->" << t1.IsBalance() << endl;
		}

		t1.InOrder();

		cout << t1.IsBalance() << endl;
	}


};