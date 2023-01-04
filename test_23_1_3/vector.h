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
		// vector�ĵ�������һ��ԭ��ָ��
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

		//�޲ι���
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
		* �����Ͻ����ṩ��vector(size_t n, const T& value = T())֮��
		* vector(int n, const T& value = T())�Ͳ���Ҫ�ṩ�ˣ����Ƕ��ڣ�
		* vector<int> v(10, 5);
		* �������ڱ���ʱ����ΪT�Ѿ���ʵ����Ϊint����10��5��������Ĭ����Ϊint����
		* �Ͳ�����vector(size_t n, const T& value = T())������췽����
		* ����ѡ����ǣ�vector(InputIterator first, InputIterator last)
		* ��Ϊ�������������乹��������������һ�£���˱������ͻὫInputIteratorʵ����Ϊint
		* ����10��5��������һ�����䣬����ʱ�ͱ�����
		* ����Ҫ���Ӹù��췽��
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

		// ��ʹ��iterator�����������ᵼ�³�ʼ���ĵ���������[first,last)ֻ����vector�ĵ�����
		// ��������������������������[first,last)���������������ĵ�����
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}


		//��������
		//��ͳд��
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

		//��������
		//�ִ�д��
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		//��ֵ����
		//�ִ�д��
		vector& operator=(vector<T> tmp)
		{
			swap(tmp);
			return *this;
		}

		
		/////////////////////////////////////////////////////
		// vector���޸Ĳ���
		void push_back(const T& val)
		{
			if (_finish == _end_of_storage)
			{
				//�ռ����˾�2�����ݣ�
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
		// �������
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
						tmp[i] = _start[i];//���ָ�ֵ����ʹ��vector<vector>�����������Ҳ�����������
					}					   //��Ϊ�������������������ø�ֵ����

					//����д������һ��Ŀ����ͻ��������vector<vector>��ά����
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
			//��������������
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
		// Ԫ�ط���
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
		T* _start; //�����ռ���׵�ַ
		T* _finish;  // ָ����Ч���ݵ�β
		T* _end_of_storage;  //�����ռ��β��ַ
	};



	/// /////////////////////////////////
	/// ��ģ��ʵ�ֵ�vector�����ϸ����
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