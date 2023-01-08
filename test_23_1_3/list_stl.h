#pragma once 
#include <iostream>
using namespace std;

namespace hdm
{
	// List的节点类
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
	 List 的迭代器
	 迭代器有两种实现方式，具体应根据容器底层数据结构实现：
	 1. 原生态指针，比如：vector
	 2. 将原生态指针进行封装，因迭代器使用形式与指针完全相同，因此在自定义的类中必须实现以下方法：
	 1. 指针可以解引用，迭代器的类中必须重载operator*()
	 2. 指针可以通过->访问其所指空间成员，迭代器类中必须重载oprator->()
	 3. 指针可以++向后移动，迭代器类中必须重载operator++()与operator++(int)
	 至于operator--()/operator--(int)释放需要重载，根据具体的结构来抉择，双向链表可以向前移动，所以需要重载，如果是forward_list就不需要重载--
	 4. 迭代器需要进行是否相等的比较，因此还需要重载operator==()与operator!=()
	 */

	 template <class T,class Ref, class Ptr>
	 class ListIterator
	 {
	 public:
		 typedef ListNode<T> Node;
		 typedef ListIterator<T, Ref, Ptr> Self;
	 public:
		 // Ref 和 Ptr 类型需要重定义下，实现反向迭代器时需要用到
		 typedef Ref Ref;
		 typedef Ptr Ptr;
		 ListIterator(Node* node=nullptr)
			 :_node(node)
		 {}
		 //////////////////////////////////////////////
		 // 具有指针类似行为
		 Ref operator*()
		 {
			 return _node->_val;
		 }

		 Ptr operator->()
		 {
			 return &(_node->_val);
		 }
		 //////////////////////////////////////////////
		 // 迭代器支持移动
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
		 // 迭代器支持比较
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

	 //适配器
	 // 给我不同容器的正向迭代器，适配出对应的这个容器需要的反向迭代器
	 template <class iterator>
	 class ReverseIterator
	 {
		 // 注意：此处typename的作用是明确告诉编译器，Ref是Iterator类中的一个类型，而不是静态成员变量
		 // 否则编译器编译时就不知道Ref是Iterator中的类型还是静态成员变量
		 // 因为静态成员变量也是按照 类名::静态成员变量名 的方式访问的
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
		// 正向迭代器
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;

		// 反向迭代器
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

		//迭代器构造
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

		//拷贝构造
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
		// List的迭代器
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
		// List的容量相关

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
			//newsize<oldsize，将元素减少到newsize
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
		// List的元素访问操作
		// 注意：List不支持operator[]

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
		// List的插入和删除
		
		// 在pos位置前插入值为val的节点
		iterator insert(iterator pos, const T& x)
		{
			Node* newNode = new Node(x);
			Node* cur = pos._node;
			//将新节点插入
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

		// 删除pos位置的节点，返回该节点的下一个位置
		iterator erase(iterator pos)
		{
			Node* del = pos._node;
			Node* Ret = del->_next;

			//删除节点
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
	// 对模拟实现的list进行测试
	// 正向打印链表
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

	// 测试List的构造
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
		// 测试PushBack与PopBack
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

		// 测试PushFront与PopFront
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

	// 测试insert和erase
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

		// pos指向的节点已经被删除，pos迭代器失效
		cout << *pos << endl;

		auto it = l.begin();
		while (it != l.end())
		{
			it = l.erase(it);
		}
		cout << l.size() << endl;
	}

	// 测试反向迭代器
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