#pragma once 

#include<iostream>
#include<assert.h>
using namespace std;

namespace hdm
{
	template <class T>
	
	//����ڵ�
	struct ListNode
	{
		ListNode(const T& val = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _val(val)
		{}

		T _val;
		ListNode<T>* _next;
		ListNode<T>* _prev;
	};

	/*
	List �ĵ�����
	������������ʵ�ַ�ʽ������Ӧ���������ײ����ݽṹʵ�֣�
	1. ԭ��ָ̬�룬���磺vector
	2. ��ԭ��ָ̬����з�װ���������ʹ����ʽ��ָ����ȫ��ͬ��������Զ�������б���ʵ�����·�����
	1. ָ����Խ����ã������������б�������operator*()
	2. ָ�����ͨ��->��������ָ�ռ��Ա�����������б�������oprator->()
	3. ָ�����++����ƶ������������б�������operator++()��operator++(int)
	����operator--()/operator--(int)�ͷ���Ҫ���أ����ݾ���Ľṹ������˫�����������ǰ�ƶ���������Ҫ���أ������forward_list�Ͳ���Ҫ����--
	4. ��������Ҫ�����Ƿ���ȵıȽϣ���˻���Ҫ����operator==()��operator!=()
	*/
	template <class T,class Ref,class Ptr>
	class ListIterator
	{
	public:
		typedef ListNode<T> Node;
		typedef ListIterator<T,Ref,Ptr> Self;

		ListIterator(Node* node=nullptr)
			:_node(node)
		{}

		Ptr operator->()
		{
			return &(_node->_val);
		}

		Ref operator*()
		{
			return _node->_val;
		}
		
		//ǰ��++
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		//����++
		Self& operator++(int)
		{
			Self ret(*this);
			_node = _node->_next;
			return ret;
		}

		//ǰ��--
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		//����--
		Self& operator--(int)
		{
			Self ret(*this);
			_node = _node->_prev;
			return ret;
		}

		bool operator==(const Self& l)const 
		{
			return _node == l._node;
		}
		bool operator!=(const Self& l)const
		{
			return _node != l._node;
		}

		Node* _node;
	};
	// ����  ����
	// ��ͨ��  ���� �ȼ��� ����
	// ��ģ��  ����  ���ȼ���  ����
	// �磺listģ�� ����list  ����list<T> 
	// ��ģ����������������������ͣ����ǽ��鲻Ҫ��ô��
	template <class T>
	class list
	{
	public:
		typedef ListNode<T> Node;
		typedef ListIterator<T,T&,T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}


		const_iterator begin()const 
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()const 
		{
			return const_iterator(_head);
		}

		//�޲ι���
		list()
		{
			CreateNode();
		}
		//����������
		template <class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			CreateNode();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//��������
		list(const list<T>& lt)
		{
			CreateNode();
			list<T> tem(lt.begin(), lt.end());
			swap(tem);
		}

		//��ֵ����
		list<T>& operator=(list<T> tem)
		{
			CreateNode();
			swap(tem);
			return *this;
		}


		void resize(size_t n, const T& x = T())
		{
			for (size_t i = 0; i < n; i++)
			{
				push_back(x);
			}
		}

		void print()
		{
			Node* cur = _head->_next;
			while (cur != _head)
			{
				cout << cur->_val << " ";
				cur = cur->_next;
			}
			cout << endl;
		}


		

		bool empty()
		{
			return _head->_next == _head;
		}
		size_t size()
		{
			size_t count = 0;
			Node*cur = _head->_next;
			while (cur != _head)
			{
				count++;
				cur = cur->_next;
			}
			return count;
		}

		//β��
		void push_back(const T& x)
		{
			insert(iterator(_head), x);
		}

		//ͷ��
		void push_front(const T&x)
		{
			insert(iterator(_head->_next), x);
		}

		//βɾ
		void pop_back()
		{
			erase(iterator(_head->_prev));
		}

		//ͷɾ
		void pop_front()
		{
			erase(iterator(_head->_next));
		}

		// ��posλ��ǰ����ֵΪval�Ľڵ�
		iterator insert(iterator pos, const T& val)
		{
			Node*newNode = new Node(val);
			Node* cur = pos._node;
			
			cur->_prev->_next = newNode;
			newNode->_prev = cur->_prev;
			cur->_prev = newNode;
			newNode->_next = cur;

			return iterator(newNode);
		}
		// ɾ��posλ�õĽڵ㣬���ظýڵ����һ��λ��
		iterator erase(iterator pos)
		{
			Node* del = pos._node;
			Node*ret = del->_next;
			del->_prev->_next = del->_next;
			del->_next->_prev = del->_prev;
			delete del;
			return iterator(ret);
		}

		void clear()
		{
			Node*cur = _head->_next;
			while (cur != _head)
			{
				Node*del = cur;
				cur = cur->_next;
				delete del;
			}
			_head->_next = _head->_prev = _head;
		}


		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
	private:
		//˫��ѭ������
		void CreateNode()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		Node* _head;
	};


	void list_test1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_front(0);
		/*lt.print();*/
		auto it = lt.begin();
		//auto it1 = lt.end();
		//cout << *it1 << endl;
		//cout << (it == it1) << endl;
		it=lt.erase(lt.begin());
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}

		cout << endl;
		it = lt.begin();
		/*cout << it->_val << endl*/
		//cout << lt.size() << endl;
		//cout << lt.empty() << endl;
		lt.clear();
	}


	void list_test2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int> lt1(lt.begin(), lt.end());
		lt.push_front(0);
		lt1.push_back(5);
		lt.print();
		lt1.print();

		list<int> lt2(lt1);
		lt2.print();

		list<int > lt3;
		lt3 = lt;
		lt.print();

	}
	void list_test3()
	{
		list<int> lt1;
		lt1.resize(10,1);
		lt1.print();
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.print();
		lt.pop_back();
		lt.print();
		lt.pop_front();
		lt.print();

	}
}