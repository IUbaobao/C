#pragma once 

#include "RBTree.h"


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

		bool insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
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
}

