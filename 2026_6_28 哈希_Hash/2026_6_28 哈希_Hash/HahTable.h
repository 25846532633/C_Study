#pragma once
#include <vector>

template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

template<>
struct HashFunc<string>
{
	// abcd
	// bcad
	// aadd
	// BKDR
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (auto ch : key)
		{
			hash *= 131;
			hash += ch;
		}

		return hash;
	}
};

namespace bit
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K,class T>
	struct HashData
	{
		pair<K, T> _kv;
		State _state;
	};

	template<class K,class V,class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable()
		{
			_tables.resize(10);
		}

		bool Insert(const pair<K, V>& kv)
		{
			//1.已经有了，不用再插入
			if (Find(kv.first))
			{
				return false;
			}


			//2.超过定义的负载因子
			if (_n * 10 / _tables.size() >= 7)
			{
				HashTable<K, V, Hash> newHT;
				newHT._tables.resize(_tables.size() * 2);

				for (size_t i = 0; i < _tables.size(); i++)
				{
					if (_tables[i]._state == EXIST)
					{
						newHT.Insert(_tables[i]._kv);
					}
				}

				_tables.swap(newHT._tables); 
			}


			Hash hs;
			size_t hashi = hs(kv.first) % _tables.size();

			while (_tables[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _tables.size();
			}

			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_n;

			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			Hash hs;
			size_t hashi = hs(key) % _tables.size();

			while (_tables[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._state == EXIST &&
					_tables[hashi]._kv.first == key)
					return &_tables[hashi];

				++hashi;
				hashi %= _tables.size();
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret == nullptr)
			{
				return false;
			}
			else
			{
				ret->_state = DELETE;
				--_n;
				return true;
			}
		}


	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0;
	};

	void TestHT1()
	{
		int a[] = { 10001,11,55,24,19,12,31 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		cout << ht.Find(55) << endl;
		cout << ht.Find(31) << endl;

		ht.Erase(55);
		cout << ht.Find(55) << endl;
		cout << ht.Find(31) << endl;
	}

	struct Person
	{
		//string _id;

		string _name;
		int _age;
		string school;
	};

	void TestHT3()
	{
		HashTable<Person, int> xxht;

		//HashTable<string, int, StringHashFunc> ht;
		HashTable<string, int> ht;
		ht.Insert(make_pair("sort", 1));
		ht.Insert(make_pair("left", 1));
		ht.Insert(make_pair("insert", 1));

	}
}


namespace hash_bucket
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode* _next;

		HashNode(const T& data)
			:_data(data),
			_next(nullptr)
		{}
	};

	// 前置声明
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	template<class K,class T,class KeyOfT,class Hash>
	class HashTable
	{
		typedef HashNode<T> Node;
	public:


		template<class Ptr,class Ref>
		struct __HTIterator
		{
			typedef HashNode<T> Node;
			typedef __HTIterator Self;

			Node* _node;
			const HashTable* _pht;


			__HTIterator(Node* node, const HashTable* pht)
				:_node(node),
				_pht(pht)
			{}

			Ref operator*()
			{
				return _node->_data;
			}

			Ptr operator->()
			{
				return &_node->_data;
			}

			Self& operator++()
			{
				if (_node->_next)
				{
					_node = _node->_next;
				}
				else
				{
					KeyOfT kt;
					Hash hs;

					size_t i = hs(kt(_node->_data)) % _pht->_tables.size();
					i++;
					for (; i < _pht->_tables.size(); i++)
					{
						if (_pht->_tables[i])
							break;
					}

					if (i == _pht->_tables.size())
						_node = nullptr;
					else
						_node = _pht->_tables[i];
				}
				return *this;
			}

			bool operator!=(const Self& s)
			{
				return _node != s._node;
			}
		};
		typedef __HTIterator<T*, T&> iterator;
		typedef __HTIterator<const T*, const T&> const_iterator;

		iterator begin()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				if (cur)
				{
					return iterator(cur, this);
				}
			}
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}


		const_iterator begin() const
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				if (cur)
				{
					// this -> const HashTable*
					return const_iterator(cur, this);
				}
			}

			return end();
		}

		const_iterator end() const
		{
			return const_iterator(nullptr, this);
		}

		//构造器
		HashTable()
		{
			_tables.resize(10, nullptr);
			n = 0;
		}

		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;

					cur = next;
				}
				_tables[i] = nullptr;
			}
		}

		iterator Find(const K& key)
		{
			KeyOfT kot;
			Hash hs;

			size_t hashi = hs(key) % _tables.size();
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (kot(cur->_data) == key)
					return iterator(cur, this);
				
				cur = cur->_next;
			}

			return end();
		}


		pair<iterator, bool> Insert(const T& data)
		{
			KeyOfT kt;
			Hash hs;
			iterator it = Find(kt(data));
			if (it != end())
				return make_pair(it, false);

			//容量不够 - 扩容
			if (n == _tables.size())
			{
				//创建一个新的HashTable，完成映射后，利用swap进行交换
				vector<Node*> newTables(_tables.size() * 2, nullptr);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						size_t hashi = hs(kt(cur->_data)) % newTables.size();
						cur->_next = newTables[hashi];
						newTables[hashi] = cur;

						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newTables);
			}
			//找到对应位置
			size_t hashi = hs(kt(data)) % _tables.size();
			//今天头插
			Node* newnode = new Node(data);

			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++n;

			return make_pair(iterator(newnode, this), true);
		}

		bool Erase(const K& key)
		{
			KeyOfT kt;
			Hash hs;
			size_t hashi = hs(kt(key)) % _tables.size();

			Node* prev = nullptr;
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (kt(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;

					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;
		}


	private:
		vector<Node*> _tables;
		size_t n;
	};


}