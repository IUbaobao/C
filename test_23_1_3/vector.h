#pragma once 
#include <iostream>
#include <assert.h>
using namespace std;

namespace hdm
{
	template <class T>
	class vector
	{
	public:
		// vector的迭代器是一个原生指针
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		//无参构造
		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}

		vector(size_t n,const T& val=T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				push_back(val);
			}
		}
		/*
		* 理论上将，提供了vector(size_t n, const T& value = T())之后
		* vector(int n, const T& value = T())就不需要提供了，但是对于：
		* vector<int> v(10, 5);
		* 编译器在编译时，认为T已经被实例化为int，而10和5编译器会默认其为int类型
		* 就不会走vector(size_t n, const T& value = T())这个构造方法，
		* 最终选择的是：vector(InputIterator first, InputIterator last)
		* 因为编译器觉得区间构造两个参数类型一致，因此编译器就会将InputIterator实例化为int
		* 但是10和5根本不是一个区间，编译时就报错了
		* 故需要增加该构造方法
		*/
		vector(int n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				push_back(val);
			}
		}

		// 若使用iterator做迭代器，会导致初始化的迭代器区间[first,last)只能是vector的迭代器
		// 重新声明迭代器，迭代器区间[first,last)可以是任意容器的迭代器
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}


		//拷贝构造
		//传统写法
		//vector(const vector<T>& v)
		//	:_start(nullptr)
		//	, _finish(nullptr)
		//	, _end_of_storage(nullptr)
		//{
		//	reserve(v.capacity());
		//	auto it = v.begin();
		//	auto it1 = begin();
		//	while (it != v.end())
		//	{
		//		*it1++ = *it++;
		//	}
		//	_finish = it1;
		//}

		//拷贝构造
		//现代写法
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		//赋值重载
		//现代写法
		vector& operator=(vector<T> tmp)
		{
			swap(tmp);
			return *this;
		}

		
		/////////////////////////////////////////////////////
		// vector的修改操作
		void push_back(const T& val)
		{
			if (_finish == _end_of_storage)
			{
				//空间满了就2倍扩容，
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = val;
			++_finish;
		}
		void pop_back()
		{
			erase(end() - 1);
		}

		iterator insert(iterator pos,const T& x)
		{
			assert(pos >= _start &&pos <= _finish);
			if (_finish == _end_of_storage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			auto cur = end();
			while (cur>pos)
			{
				*cur = *(cur - 1);
				--cur;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish && pos!=nullptr);
			auto cur = pos;
			while (cur < _finish - 1)
			{
				*cur = *(cur + 1);
				++cur;
			}
			--_finish;
			return pos;
		}

		void swap(vector<T> & v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		//////////////////////////////////////////////////
		// 容量相关
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldsize = size();
				T* tmp = new T[n];
				if (size() != 0)
				{
					for (size_t i = 0; i < oldsize; i++)
					{
						tmp[i] = _start[i];//这种赋值，即使在vector<vector>这样的深拷贝中也不会出现问题
					}					   //因为它在这种情况下它会调用赋值重载

					//这种写法在深一层的拷贝就会出错，比如vector<vector>二维数组
					/*memcpy(tmp, _start, size()*sizeof(T));*/

					delete[] _start;
				}
				_start = tmp;
				_finish = _start + oldsize;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n,const T& x=T())
		{
			//容量不够先扩容
			if (n > capacity())
			{
				reserve(n);
			}
			for (size_t i = size(); i < n; ++i)
			{
				_start[i] = x;
			}
			_finish = _start + n;
		}

		size_t capacity()  const
		{
			return _end_of_storage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		bool empty()
		{
			return _finish == _start;
		}
		///////////////////////////////////////////////////////////
		// 元素访问
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const 
		{
			assert(pos < size());
			return _start[pos];
		}

		T& front()
		{
			return *_start;
		}

		const T& front() const
		{
			return *_start;
		}

		T& back()
		{
			return *(_finish - 1);
		}
		const T& back() const 
		{
			return *(_finish - 1);
		}



		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

	private:
		T* _start; //容量空间的首地址
		T* _finish;  // 指向有效数据的尾
		T* _end_of_storage;  //容量空间的尾地址
	};



	/// /////////////////////////////////
	/// 对模拟实现的vector进行严格测试
	void TestVector1()
	{
		hdm::vector<int> v1;
		hdm::vector<int> v2(10, 5);

		int array[] = { 1, 2, 3, 4, 5 };
		hdm::vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));

		hdm::vector<int> v4(v3);

		for (size_t i = 0; i < v2.size(); ++i)
		{
			cout << v2[i] << " ";
		}
		cout << endl;

		auto it = v3.begin();
		while (it != v3.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v4)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void TestVector2()
	{
		hdm::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		cout << v.size() << endl;
		cout << v.capacity() << endl;
		cout << v.front() << endl;
		cout << v.back() << endl;
		cout << v[0] << endl;
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.pop_back();
		v.pop_back();
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.insert(v.begin(), 0);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.erase(v.begin() + 1);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void vector_test1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		vector<int> v1(v);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		vector<int> v2;
		v2 = v1;
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void vector_test2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		//v.insert(v.begin(), 0);
		//v.insert(v.end(), 6);
		/*v.insert(v.begin()+4, 6);*/

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		//v.erase(v.begin());
		//v.erase(v.begin());
		//v.erase(v.begin());
		//v.erase(v.begin());
		//v.erase(v.end()-1);
		/*v.erase(v.begin()+6);*/
		v.pop_back();

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void vector_test3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		v.resize(20, 10);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}