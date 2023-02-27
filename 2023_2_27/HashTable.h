#pragma once 
#include <iostream>
#include <vector>
using namespace std;
namespace hdm
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE,
	};

	template <class K, class V>
	struct HashDate
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};


	template <class K, class V>
	class Hashtable
	{
	public:
		typedef HashDate<K, V> Date;
		Hashtable()
			:_n(0)
		{
			_tables.resize(10);
		}
		bool Insert(const pair<K, V>& kv)
		{
			if (find(kv.first))
				return false;
			if (_n * 10 / _tables.size() >= 7)
			{
				//À©ÈÝ
				Hashtable<K, V> newtable;
				newtable._tables.resize(_tables.size() * 2);
				for (auto& e : _tables)
				{
					if (e._state==EXIST)
					newtable.Insert(e._kv);
				}
				_tables.swap(newtable._tables);
			}

			size_t hashi = kv.first%_tables.size();
			while (_tables[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _tables.size();
			}
			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_n;
		}

		bool erase(const K& key)
		{
			for (int i = 0; i < _tables.size(); ++i)
			{
				if (key == _tables[i]._kv.first && _tables[i]._state==EXIST)
				{
					_tables[i]._state = DELETE;
					return true;
				}
			}
			return false;
		}

		bool find(const K& key)
		{
			for (int i = 0; i < _tables.size(); ++i)
			{
				if (key == _tables[i]._kv.first && _tables[i]._state==EXIST)
				{
					return true;
				}
			}
			return false;
		}

	private:
		vector<Date> _tables;
		size_t _n;
	};


	void TestHashTable1()
	{
		Hashtable<int, int> ht;
		int a[] = { 18, 8, 7, 27, 57, 3, 38, 18 };
		//int a[] = { 1,4,5,6,7,8,44,9 };

		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}
		ht.Insert(make_pair(17, 17));
		ht.Insert(make_pair(5, 5));

		cout << ht.find(7) << endl;
		cout << ht.find(8) << endl;

		ht.erase(7);
		cout << ht.find(7) << endl;
		cout << ht.find(8) << endl;
	}

}