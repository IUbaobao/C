#pragma once 
#include "HashTable.h"

namespace hdm
{
	template <class K>
	class KeyofK
	{
	public:
		const K&operator()(const K&key)
		{
			return key;
		}
	};

	template <class K,class hash=hashFunc<K>,class KeyofK=KeyofK<K>>
	class unordered_set
	{
	public:
		typedef typename buckethash::hashtable<K, K, hash, KeyofK>::iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}

		pair<iterator, bool> insert(const K& key)
		{
			return _ht.Insert(key);
		}

	private:
		buckethash::hashtable<K, K, hash, KeyofK> _ht;
	};


	void test_unordered_set()
	{
		unordered_set<int> us;
		us.insert(13);
		us.insert(3);
		us.insert(23);
		us.insert(5);
		us.insert(5);
		us.insert(6);
		us.insert(15);
		us.insert(223342);
		us.insert(22);

		unordered_set<int>::iterator it = us.begin();
		while (it != us.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : us)
		{
			cout << e << " ";
		}
		cout << endl;
	}


}