#pragma once 

#include "HashTable.h"


namespace hdm
{
	template<class K,class V>
	struct keyofT
	{
		const K& operator()(const pair<K, V>& kv)
		{
			return kv.first;
		}
	};

	template<class K,class V,class hash=hashFunc<K>,class keyofT=keyofT<K,V>>
	class unordered_map
	{
	public:
		typedef typename buckethash::hashtable<K, pair<const K, V>, hash, keyofT>::iterator iterator;
		typedef typename buckethash::hashtable<K, pair<const K, V>, hash, keyofT>::const_iterator const_iterator;

		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}


		const_iterator begin()const 
		{
			return _ht.begin();
		}
		const_iterator end()const
		{
			return _ht.end();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
			return ret.first->second;
		}

	private:
		buckethash::hashtable<K, pair<const K, V>, hash, keyofT> _ht;
	};

	void test_unordered_map()
	{
		string arr[] = { "2", "0", "1", "3", "2", "0", "2", "2", "0", "2", "2", "3", "3" };

		unordered_map<string, int> countMap;
		for (auto& e : arr)
		{
			countMap[e]++;
		}

		for (const auto& kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}

	}

	void test_unordered_map2()
	{
		string arr[] = { "苹果", "西瓜", "香蕉", "草莓", "苹果", "西瓜", 
			"苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
		unordered_map<string, int> countMap;
		for (auto& e : arr)
		{
			countMap[e]++;
		}

		for (const auto& kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
	}

}


