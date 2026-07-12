#pragma once

namespace bit
{
	template<class K, class V, class Hash = HashFunc<K>>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash>::iterator iterator;
		
		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
			return ret.first->second;
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}
	private:
		hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash> _ht;
	};

	void test_unordered_map()
	{
		string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
	"苹果", "香蕉", "苹果", "香蕉","苹果","草莓", "苹果","草莓" };
		unordered_map<string, int> countMap;
		for (auto& e : arr)
		{
			countMap[e]++;
		}

		unordered_map<string, int>::iterator it = countMap.begin();
		while (it != countMap.end())
		{
			//it->first += 'x'; // key不能修改
			it->second += 1;  // value可以修改
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;

		for (auto& kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
		cout << endl;
	}
}