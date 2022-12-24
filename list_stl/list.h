#pragma once 

#include<iostream>
#include<assert.h>
using namespace std;

namespace hdm
{
	template <class T>
	
	//链表节点
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
		
		//前置++
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		//后置++
		Self& operator++(int)
		{
			Self ret(*this);
			_node = _node->_next;
			return ret;
		}

		//前置--
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		//后置--
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
	// 类名  类型
	// 普通类  类名 等价于 类型
	// 类模板  类名  不等价于  类型
	// 如：list模板 类名list  类型list<T> 
	// 类模板里面可以用类名代表类型，但是建议不要那么用
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

		//无参构造
		list()
		{
			CreateNode();
		}
		//迭代器构造
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

		//拷贝构造
		list(const list<T>& lt)
		{
			CreateNode();
			list<T> tem(lt.begin(), lt.end());
			swap(tem);
		}

		//赋值重载
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

		//尾插
		void push_back(const T& x)
		{
			insert(iterator(_head), x);
		}

		//头插
		void push_front(const T&x)
		{
			insert(iterator(_head->_next), x);
		}

		//尾删
		void pop_back()
		{
			erase(iterator(_head->_prev));
		}

		//头删
		void pop_front()
		{
			erase(iterator(_head->_next));
		}

		// 在pos位置前插入值为val的节点
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
		// 删除pos位置的节点，返回该节点的下一个位置
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
		//双向循环链表
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