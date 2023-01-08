#pragma once 
#include <iostream>
using namespace std;

namespace hdm
{
	// List�Ľڵ���
	template <class T>
	 struct ListNode
	{
		ListNode(const T& val=T())
			:_val(val)
			, _next(nullptr)
			, _prev(nullptr)
		{}

		T _val;
		ListNode* _next;
		ListNode* _prev;
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

	 template <class T,class Ref, class Ptr>
	 class ListIterator
	 {
	 public:
		 typedef ListNode<T> Node;
		 typedef ListIterator<T, Ref, Ptr> Self;
	 public:
		 // Ref �� Ptr ������Ҫ�ض����£�ʵ�ַ��������ʱ��Ҫ�õ�
		 typedef Ref Ref;
		 typedef Ptr Ptr;
		 ListIterator(Node* node=nullptr)
			 :_node(node)
		 {}
		 //////////////////////////////////////////////
		 // ����ָ��������Ϊ
		 Ref operator*()
		 {
			 return _node->_val;
		 }

		 Ptr operator->()
		 {
			 return &(_node->_val);
		 }
		 //////////////////////////////////////////////
		 // ������֧���ƶ�
		 Self operator++()
		 {
			 _node = _node->_next;
			 return *this;
		 }

		 Self operator++(int)
		 {
			 Self tem(*this);
			 _node = _node->_next;
			 return tem;
		 }
		 Self operator--()
		 {
			 _node = _node->_prev;
			 return *this;
		 }
		 Self operator--(int)
		 {
			 Self tem(*this);
			 _node = _node->_prev;
			 return tem;
		 }

		 //////////////////////////////////////////////
		 // ������֧�ֱȽ�
		 bool operator!=(const Self& lt)const
		 {
			 return _node != lt._node;
		 }

		 bool operator==(const Self& lt)const
		 {
			 return _node == lt._node;
		 }



		 Node* _node;
	 };

	 //������
	 // ���Ҳ�ͬ������������������������Ӧ�����������Ҫ�ķ��������
	 template <class iterator>
	 class ReverseIterator
	 {
		 // ע�⣺�˴�typename����������ȷ���߱�������Ref��Iterator���е�һ�����ͣ������Ǿ�̬��Ա����
		 // �������������ʱ�Ͳ�֪��Ref��Iterator�е����ͻ��Ǿ�̬��Ա����
		 // ��Ϊ��̬��Ա����Ҳ�ǰ��� ����::��̬��Ա������ �ķ�ʽ���ʵ�
	 public:
		 typedef typename iterator::Ref Ref;
		 typedef typename iterator::Ptr Ptr;
		 typedef ReverseIterator<iterator> Self;

		 ReverseIterator(iterator it)
			 :_it(it)
		 {}

		 Self operator++()
		 {
			 --_it;
			 return *this;
		 }

		 Self operator--()
		 {
			 ++_it;
			 return *this;
		 }

		 Ref operator*()
		 {
			 iterator tmp = _it;
			 return *(--tmp);
		 }
		 
		 Ptr operator->()
		 {
			 return &(operator*());
		 }

		 bool operator!=(const Self & l) const
		 {
			 return _it != l._it;
		 }
	 private:
		 iterator _it;
	 };



	template <class T>
	class list
	{
	public:
		typedef ListNode<T> Node;
		// ���������
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;

		// ���������
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef ReverseIterator<const_iterator> const_reverse_iterator;

		list()
		{
			CreatNode();
		}

		list(int n, const T& val = T())
		{
			CreatNode();
			while (n--)
			{
				push_back(val);
			}
		}

		//����������
		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			CreatNode();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//��������
		list(const list<T>& l)
		{
			CreatNode();
			list<T> tmp(l.begin(), l.end());
			swap(tmp);
		}

		list<T>& operator=(list<T> tmp)
		{
			swap(tmp);	
			return *this;
		}


		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}


		///////////////////////////////////////////////////////////////
		// List�ĵ�����
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const 
		{
			return const_iterator(_head->_next);
		}

		const_iterator end()const
		{
			return const_iterator(_head);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const 
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend() const 
		{
			return reverse_iterator(begin());
		}
		///////////////////////////////////////////////////////////////
		// List���������

		size_t size() const
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

		bool empty()const
		{
			return _head->_next == _head;	
		}

		void resize(size_t newsize, const T& val = T())
		{
			size_t oldsize = size();
			//newsize<oldsize����Ԫ�ؼ��ٵ�newsize
			if (newsize <= oldsize)
			{
				while (newsize < oldsize)
				{
					pop_back();
					--oldsize;
				}
			}
			else
			{
				while (newsize > oldsize)
				{
					push_back(val);
					oldsize++;
				}
			}
		}

		////////////////////////////////////////////////////////////
		// List��Ԫ�ط��ʲ���
		// ע�⣺List��֧��operator[]

		T& front()
		{
			return _head->_next -> val;
		}
		const T& front()const 
		{
			return _head->_next->val;
		}

		T& back()
		{
			return _head->_prev->_val;
		}
		const T& back() const 
		{
			return _head->_prev->_val;
		}

		////////////////////////////////////////////////////////////
		// List�Ĳ����ɾ��
		
		// ��posλ��ǰ����ֵΪval�Ľڵ�
		iterator insert(iterator pos, const T& x)
		{
			Node* newNode = new Node(x);
			Node* cur = pos._node;
			//���½ڵ����
			cur->_prev->_next = newNode;
			newNode->_prev = cur->_prev;
			cur->_prev = newNode;
			newNode->_next = cur;

			return	iterator(newNode);
		}

		void push_back(const T& val)
		{
			insert(iterator(_head), val);
		}

		void push_front(const T&val)
		{
			insert(iterator(_head->_next), val);
		}

		// ɾ��posλ�õĽڵ㣬���ظýڵ����һ��λ��
		iterator erase(iterator pos)
		{
			Node* del = pos._node;
			Node* Ret = del->_next;

			//ɾ���ڵ�
			del->_prev->_next = Ret;
			Ret->_prev = del->_prev;
			delete del;
			return iterator(Ret);
		}

		void pop_back()
		{
			erase(_head->_prev);
		}

		void pop_front()
		{
			erase(_head->_next);
		}

		void clear()
		{
			Node*cur = _head->_next;
			while (cur != _head)
			{
				Node* del = cur;
				cur = cur->_next;
				delete del;
			}
		}

		void swap(list<T>& l)
		{
			std::swap(_head, l._head);
		}
	private:
		void CreatNode()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
	private:
		Node* _head;
	};


	///////////////////////////////////////////////////////
	// ��ģ��ʵ�ֵ�list���в���
	// �����ӡ����
	template<class T>
	void PrintList(const hdm::list<T>& l)
	{
		auto it = l.begin();
		while (it != l.end())
		{
			cout << *it << " ";
			++it;
		}

		cout << endl;
	}

	// ����List�Ĺ���
	void TesthdmList1()
	{
		hdm::list<int> l1;
		hdm::list<int> l2(10, 5);
		PrintList(l2);

		int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
		hdm::list<int> l3(array, array + sizeof(array) / sizeof(array[0]));
		PrintList(l3);

		hdm::list<int> l4(l3);
		PrintList(l4);

		l1 = l4;
		PrintList(l1);
	}

	// PushBack()/PopBack()/PushFront()/PopFront()
	void TesthdmList2()
	{
		// ����PushBack��PopBack
		hdm::list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		PrintList(l);

		l.pop_back();
		l.pop_back();
		PrintList(l);

		l.pop_back();
		cout << l.size() << endl;

		// ����PushFront��PopFront
		l.push_front(1);
		l.push_front(2);
		l.push_front(3);
		PrintList(l);

		l.pop_front();
		l.pop_front();
		PrintList(l);

		l.pop_front();
		cout << l.size() << endl;
	}

	// ����insert��erase
	void TesthdmList3()
	{
		int array[] = { 1, 2, 3, 4, 5 };
		hdm::list<int> l(array, array + sizeof(array) / sizeof(array[0]));

		auto pos = l.begin();
		l.insert(l.begin(), 0);
		PrintList(l);

		++pos;
		l.insert(pos, 2);
		PrintList(l);

		l.erase(l.begin());
		l.erase(pos);
		PrintList(l);

		// posָ��Ľڵ��Ѿ���ɾ����pos������ʧЧ
		cout << *pos << endl;

		auto it = l.begin();
		while (it != l.end())
		{
			it = l.erase(it);
		}
		cout << l.size() << endl;
	}

	// ���Է��������
	void TesthdmList4()
	{
		int array[] = { 1, 2, 3, 4, 5 };
		hdm::list<int> l(array, array + sizeof(array) / sizeof(array[0]));

		auto rit = l.rbegin();
		while (rit != l.rend())
		{
			cout << *rit << " ";
			++rit;
		}
		cout << endl;

		const hdm::list<int> cl(l);
		auto crit = l.rbegin();
		while (crit != l.rend())
		{
			cout << *crit << " ";
			++crit;
		}
		cout << endl;
	}
}