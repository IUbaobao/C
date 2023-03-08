#pragma once 
#include <iostream>
#include <string>
#include <vector>
using namespace std;


template <class K>
struct hashFunc
{
	size_t operator()(const K&key)
	{
		return key;
	}
};

template <>//特化
struct hashFunc<string>
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto& e : s)
		{
			hash *= 131;
			hash += e;
		}
		return hash;
	}
};




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


	template <class K, class V, class hash = hashFunc<K>>
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
				//扩容
				Hashtable<K, V> newtable;
				newtable._tables.resize(_tables.size() * 2);
				for (auto& e : _tables)
				{
					if (e._state==EXIST)
					newtable.Insert(e._kv);
				}
				_tables.swap(newtable._tables);
			}

			//size_t hashi = kv.first%_tables.size();
			size_t hashi = hash()(kv.first) %_tables.size();

			while (_tables[hashi]._state == EXIST)
			{
				++hashi;//线性探测
				hashi %= _tables.size();
			}
			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_n;
			return true;
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

		Date* find(const K& key)
		{
			for (int i = 0; i < _tables.size(); ++i)
			{
				if (key == _tables[i]._kv.first && _tables[i]._state==EXIST)
				{
					return &_tables[i];
				}
			}
			return nullptr;
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




namespace buckethash
{
	template <class T>
	struct hashNode
	{
		T _data;
		hashNode* _next;

		hashNode(const T& data)
			:_data(data), _next(nullptr)
		{}
	}; 
	template <class K, class T, class hash, class KeyOfT>
	class hashtable;

	template <class K,class T,class hash,class KeyOfT>
	class _HTiterator
	{
	public:
		typedef hashtable<K, T, hash,KeyOfT> HT;
		typedef hashNode<T> Node;
		typedef _HTiterator<K, T, hash, KeyOfT> Self;
		Node* _node;
		HT* _ht;

		_HTiterator(Node* node,HT* ht)
			:_node(node), _ht(ht)
		{}

		T& operator*()
		{
			return _node->_data;
		}
		T* operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const Self& s) const 
		{
			return _node != s._node;
		}

		Self operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				size_t n = hash()(KeyOfT()(_node->_data)) % _ht->_tables.size();
				++n;
				while (n<_ht->_tables.size())
				{
					if (_ht->_tables[n])
					{
						_node = _ht->_tables[n];
						break;
					}
					else
					{
						++n;
					}
				}
				//后面没有桶了
				if (n == _ht->_tables.size())
					_node = nullptr;
			}
			return *this;
		}

	};

	//const迭代器
	template <class K, class T,class hash, class KeyOfT>
	class const_HTiterator
	{
	public:
		typedef hashtable<K, T, hash, KeyOfT> HT;
		typedef hashNode<T> Node;
		typedef const_HTiterator<K, T, hash, KeyOfT> Self;
		const Node* _node;
		const HT* _ht;

		const_HTiterator(const Node* node, const HT* ht)
			:_node(node), _ht(ht)
		{}

		const_HTiterator()
		{}
		const_HTiterator(const Self&it)
			:_node(it._node), _ht(it._ht)
		{}

		const T* operator*()
		{
			return _node->_data;
		}
		const T& operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		Self operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				size_t n = hash()(KeyOfT()(_node->_data)) % _ht->_tables.size();
				++n;
				while (n<_ht->_tables.size())
				{
					if (_ht->_tables[n])
					{
						_node = _ht->_tables[n];
						break;
					}
					else
					{
						++n;
					}
				}
				//后面没有桶了
				if (n == _ht->_tables.size())
					_node = nullptr;
			}
			return *this;

		}

	};

	template <class K,class T,class hash,class KeyOfT>
	class hashtable
	{
	public:
		 
		template <class K, class T, class hash, class KeyOfT>
		friend class _HTiterator;
		template <class K, class T, class hash, class KeyOfT>
		friend class const_HTiterator;
			
		typedef hashNode<T> Node;
		typedef _HTiterator<K, T, hash, KeyOfT> iterator;
		typedef const_HTiterator<K, T ,hash, KeyOfT> const_iterator;

		hashtable()
		{
			_tables.resize(10,nullptr);
			_n = 0;
		}

		iterator begin()
		{
			for (auto cur : _tables)
			{
				if (cur)
				{
					return iterator(cur, this);
				}
			}
			return iterator(nullptr, this);
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		const_iterator begin() const 
		{
			for (auto cur : _tables)
			{
				if (cur)
				{
					return const_iterator(cur, this);
				}
			}
			return const_iterator(nullptr, this);
		}

		const_iterator end()const 
		{
			return const_iterator(nullptr, this);
		}

		pair<iterator,bool> Insert(const T& data)
		{
			if (Find(KeyOfT()(data) ))
				return make_pair(iterator(Find(KeyOfT()(data)), this), false);
			if (_n==_tables.size())
			{
				//扩容
				//方案一：
				//hashtable newtable;
				//newtable._tables.resize(_tables.size() * 2);
				//for (auto cur : _tables)
				//{
				//	while (cur)
				//	{
				//		newtable.Insert(cur->_kv);
				//		cur = cur->_next;
				//	}
				//}
				//std::swap(_tables, newtable._tables);
				//缺点：要重新new节点
				
				//方案二：
				vector<Node*> newtables;
				newtables.resize(__stl_next_prime(_tables.size()),nullptr);
				for (int i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t hashi = hash()(KeyOfT()(cur->_data)) % newtables.size();
						cur->_next = newtables[hashi];
						newtables[hashi] = cur;
						cur = next;
					}
					_tables[i] = nullptr;
				}
				std::swap(_tables, newtables);
			}

			size_t hashi = hash()(KeyOfT()(data)) % _tables.size();
			Node* newNode = new Node(data);
			newNode->_next = _tables[hashi];
			_tables[hashi] = newNode;
			_n++;
			return make_pair(iterator(newNode,this),true);
		}

		Node* Find(const K& key)
		{
			for (auto cur : _tables)
			{
				while (cur)
				{
					if (KeyOfT()(cur->_data) == key)
					{
						return cur;
					}
					cur = cur->_next;
				}
			}
			return nullptr;
		}


		bool Erase(const K& key)
		{
			for (int i = 0; i < _tables.size();++i)
			{
				Node* cur = _tables[i];
				Node* prev = nullptr;
				while (cur)
				{
					if (KeyOfT()(cur->_data) == key)
					{
						if (cur == _tables[i])
						{
							_tables[i] = cur->_next;
						}
						else
						{
							prev->_next = cur->_next;
						}
						delete cur;
						--_n;
						return true;
					}
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;
		}

		~hashtable()
		{
			for (auto cur : _tables)
			{
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
			}
		}

	private:
		vector<Node*> _tables;
		size_t _n;

		inline unsigned long __stl_next_prime(unsigned long n)
		{
			static const int __stl_num_primes = 28;
			static const unsigned long __stl_prime_list[__stl_num_primes] =
			{
				53, 97, 193, 389, 769,
				1543, 3079, 6151, 12289, 24593,
				49157, 98317, 196613, 393241, 786433,
				1572869, 3145739, 6291469, 12582917, 25165843,
				50331653, 100663319, 201326611, 402653189, 805306457,
				1610612741, 3221225473, 4294967291
			};

			for (int i = 0; i < __stl_num_primes; ++i)
			{
				if (__stl_prime_list[i] > n)
				{
					return __stl_prime_list[i];
				}
			}

			return __stl_prime_list[__stl_num_primes - 1];
		}
	};

	//void TestBuckethash1()
	//{
	//	string arr[] = { "苹果", "西瓜", "香蕉", "草莓", "苹果", "西瓜", 
	//		"苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
	//	hashtable<string, int> countmap;

	//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	//	{
	//		auto tmp = countmap.Find(arr[i]);
	//		if (tmp)
	//		{
	//			tmp->_kv.second++;
	//		}
	//		else
	//		{
	//			countmap.Insert(make_pair(arr[i], 1));
	//		}
	//	}
	//	int i = 0;
	//}

	//void TestBuckethash2()
	//{
	//	hashtable<int, int > table;
	//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0,12,13,14,15,156};
	//	for (auto e : arr)
	//	{
	//		table.Insert(make_pair(e, e));
	//	}
	//	table.Insert(make_pair(61, 31));
	//	table.Insert(make_pair(21, 21));
	//	table.Insert(make_pair(41, 41));
	//	table.Erase(1);
	//	table.Erase(41);
	//}

}