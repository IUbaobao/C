#pragma once 

#include "RBTree.h"
#include <string>

namespace hdm
{
	template<class K,class V>
	class map
	{
	public:
		struct MapKeyOfV
		{
			const K& operator()(const pair<K,V>& kv)
			{
				return kv.first;
			}
		};
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfV>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		pair<iterator,bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}
		V& operator[](K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}
	private:
		RBTree<K, pair<const K, V>, MapKeyOfV> _t;
	};


	void test_map()
	{
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
		map<int, int> m;
		for (auto e : a)
		{
			m.insert(make_pair(e, e));
		}
		//for (auto& e : m)
		//{
		//	cout << e.first << ":" << e.second << endl;
		//}
		auto it = m.begin();
		while (it != m.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
	}

	void TestMap()
	{
		//统计水果出现的次数
		std::string arr[] = { "苹果", "西瓜", "香蕉", "草莓", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
		map<string, int> mapcount;
		for (auto& e : arr)
		{
			mapcount[e]++;
		}

		for (auto& e : mapcount)
		{
			cout << e.first << ":" << e.second << endl;
		}
	}
}

