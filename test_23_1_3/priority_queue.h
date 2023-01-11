#pragma once 

#include <vector>

namespace hdm
{
	template<class T>
	class less
	{
	public:
		bool operator()(const T& x1, const T& x2)
		{
			return x1 < x2;
		}
	};

	template<class T>
	class greater
	{
	public:
		bool operator()(const T& x1, const T& x2)
		{
			return x1 > x2;
		}
	};

	template <class T, class Container=vector<T>,class Compare=less<T>>
	class priority_queue
	{
	public:
		// �޲ι���---����յ����ȼ�����
		priority_queue()
		{}

		//����������
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:_con(first,last)
		{
			//�����ɶ�
			int size = _con.size();
			int root = (size - 2) >> 1;
			for (root, root >= 0, --root)
			{
				AdjustDown(root);
			}
		}
		void push(const T& val)
		{
			_con.push_back(val);
			AdjustUp(size() - 1);
		}

		void pop()
		{
			if (empty())
				return;
			std::swap(_con.front(), _con.back());
			_con.pop_back();
			AdjustDown(0);
		}

		size_t size()const 
		{
			return _con.size();
		}

		bool empty()const
		{
			return _con.empty();
		}
		// �Ѷ�Ԫ�ز������޸ģ���Ϊ���Ѷ�Ԫ���޸Ŀ��Ի��ƻ��ѵ�����
		const T& top()
		{
			return _con.front();
		}
	private:
		//���ϵ����㷨
		void AdjustUp(int child)
		{
			Compare _com;
			int parent = (child - 1) / 2;
			while (child>0)
			{
				//if (_con[parent] < _con[child])
				if (_com(_con[parent],_con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		//���µ����㷨
		void AdjustDown(int parent)
		{
			Compare _com;
			int child = parent * 2 + 1;
			while (child<size())
			{
				//Ĭ�ϴ��
				//if (child+1 < size() && _con[child] < _con[child + 1])
				if (child + 1 < size() && _com(_con[child],_con[child+1]))
				{
					child++;
				}
				//if (_con[parent] < _con[child])
				if (_com(_con[parent],_con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}

		}

	private:
		Container _con;
	};
}