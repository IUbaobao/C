#pragma once 

#include <iostream>
#include <cassert>
#include <ctime>
using namespace std;

enum Color
{
	RED,
	BLACK,
};

template <class T>
struct RBTreeNode
{
	RBTreeNode<T> *_parent;
	RBTreeNode<T>*_left;
	RBTreeNode<T>* _right;
	T _data;
	Color _col;

	RBTreeNode(const T& data)
		:_data(data), _parent(nullptr), _left(nullptr), _right(nullptr), _col(RED)
	{}
};

template<class T,class Ptr,class Ref>
class _RBTreeIterator
{
public:
	typedef RBTreeNode<T> Node;
	typedef _RBTreeIterator<T,Ptr,Ref> Self;
	typedef _RBTreeIterator<T, T*, T&> iterator;

	_RBTreeIterator( Node* ptr)
		:_node(ptr)
	{}

	_RBTreeIterator(const iterator& it)
		:_node(it._node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}


	Self& operator++()
	{
		//����Һ��Ӵ��ڣ������Һ��ӵ�����ڵ�
		if (_node->_right)
		{
			Node* cur = _node->_right;
			while (cur->_left)
			{
				cur = cur->_left;
			}
			_node = cur;
		}
		else//�Һ��Ӳ�����Ҫ�ң������Ǹ��׵���ڵ�
		{
			Node* parent = _node->_parent;
			Node* cur = _node;
			while (parent && parent->_right == cur)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	
	Self& operator--()
	{
		//������Ӵ��ڣ��������ӵ����ҽڵ�
		if (_node->_left)
		{
			Node* cur = _node->_left;
			while (cur->_right)
			{
				cur=cur->_right
			}
			_node = cur;
		}
		else//���Ӳ�����Ҫ�ң������Ǹ��׵��ҽڵ�
		{
			Node* parent = _node->_parent;
			Node* cur = _node;
			while (parent && parent->_left==cur)
			{
				cur = parent;
				parent=cur->_parent
			}
			_node = parent;
		}
		return *this;
	}

	bool operator!=(const Self& it)const
	{
		return _node != it._node;
	}

	bool operator==(const Self& it)const
	{
		return _node == it._node;
	}
	Node* _node;
};


template <class K, class T,class KeyOfT>
class RBTree
{
public:
	typedef RBTreeNode<T> Node;
	typedef _RBTreeIterator<T,T*,T&> iterator;
	typedef _RBTreeIterator<T, const T*, const T&> const_iterator;

	iterator begin()
	{
		Node* cur = _root;
		while (cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	const_iterator begin() const
	{
		Node* cur = _root;
		while (cur->_left)
		{
			cur = cur->_left;
		}
		return const_iterator(cur);
	}

	const_iterator end()const
	{
		return const_iterator(nullptr);
	}

	pair<iterator,bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root),true);
		}
		KeyOfT kot;
		Node* cur = _root;
		Node* parent = _root;
		//�Һ���λ�ò���
		while (cur)
		{
			//if (cur->_kv.first > kv.first)
			if (kot(cur->_data)> kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			//else if (cur->_kv.first < kv.first)
			else if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else//��Ȳ�����
			{
				return make_pair(iterator(cur),false);
			}
		}
		cur = new Node(data);
		Node* newNode = cur;
		cur->_col = RED;//Ĭ�ϲ����ɫ�ڵ�
		//�ж����ĸ���������
		//if (parent->_kv.first > kv.first)
		if (kot(parent->_data) > kot(data))
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;

		//�ж��Ƿ���Ϻ��������û����Ҫ����ɫ
		while (parent&& parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node*uncle = grandfather->_right;
				//���һ���˾˽ڵ������Ϊ��,�ø��׽ڵ�;˾˽ڵ��ڣ��游���
				if (uncle&& uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//�������uncle�ڵ���ܲ����ڿ���Ϊ�ڽڵ㣬����cur��parent�����
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						cur->_col = grandfather->_col = RED;

					}
					//�������uncle�ڵ���ܲ����ڿ���Ϊ�ڽڵ㣬��cur��parent���ұ�
					else
					{
						RotateL(parent);
						RotateR(grandfather);
						parent->_col = grandfather->_col = RED;
						cur->_col = BLACK;

					}
					break;

				}
			}
			else//grandfather->_right == parent
			{
				Node*uncle = grandfather->_left;
				//���һ���˾˽ڵ������Ϊ��,�ø��׽ڵ�;˾˽ڵ��ڣ��游���
				if (uncle&& uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//�������ϵ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//�������uncle�ڵ���ܲ����ڿ���Ϊ�ڽڵ㣬����cur��parent���ұ�
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						cur->_col = grandfather->_col = RED;

					}
					//�������uncle�ڵ���ܲ����ڿ���Ϊ�ڽڵ㣬��cur��parent�����
					else
					{
						RotateR(parent);
						RotateL(grandfather);
						parent->_col = grandfather->_col = RED;
						cur->_col = BLACK;

					}
					break;
				}

			}
		}
		_root->_col = BLACK;
		return make_pair(iterator(newNode),true);
	}

	void RotateL(Node* parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;

		Node* pparent = parent->_parent;

		parent->_right = SubRL;
		//SubRL��Ϊ�վ�Ҫ��parent
		if (SubRL)
			SubRL->_parent = parent;

		SubR->_left = parent;
		parent->_parent = SubR;
		SubR->_parent = pparent;

		if (pparent == nullptr)//pparentΪ����Ҫ�ĸ�
		{
			_root = SubR;
			_root->_parent = nullptr;
		}
		else // ��Ϊ����Ҫ�ж�λ���Ǹ�����
		{
			if (pparent->_left == parent)
			{
				pparent->_left = SubR;
			}
			else
			{
				pparent->_right = SubR;
			}
		}

	}

	void RotateR(Node* parent)
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;

		Node* pparent = parent->_parent;

		parent->_left = SubLR;
		//SubLR��Ϊ�վ�Ҫ��parent
		if (SubLR)
			SubLR->_parent = parent;

		SubL->_right = parent;
		parent->_parent = SubL;

		SubL->_parent = pparent;
		if (pparent == nullptr)//pparentΪ����Ҫ�ĸ�
		{
			_root = SubL;
			_root->_parent = nullptr;
		}
		else//��Ϊ����Ҫ�ж�λ���Ǹ�����
		{
			if (pparent->_left == parent)
			{
				pparent->_left = SubL;
			}
			else
			{
				pparent->_right = SubL;
			}
		}
	}
	void Inorder()
	{
		Inorder(_root);
	}
	//�ж��Ƿ�������������
	bool IsValidRBTree()
	{
		//����Ҳ����
		if (_root == nullptr)
			return true;
		//�жϸ��Ƿ����
		if (_root->_col != BLACK)
			return false;
		//��һ��·����¼��ɫ�ڵ�ĸ���
		Node* cur = _root;
		int BlackNum = 0;
		while (cur)
		{
			if (cur->_col == BLACK)
				BlackNum++;
			cur = cur->_left;
		}
		//��¼ÿһ��·���ĺڽڵ����
		int k = 1;

		return _IsValidRBTree(_root->_left, k, BlackNum)
			&& _IsValidRBTree(_root->_right, k, BlackNum);
	}
private:
	void Inorder(Node* root)
	{
		if (root == nullptr)
			return;

		Inorder(root->_left);
		cout << root->_kv.first << "," << root->_kv.second << endl;
		Inorder(root->_right);
	}

private:
	bool _IsValidRBTree(Node* root, int k, int BlackNum)
	{
		//�����գ��ж�����·���ϵĺڽڵ��Ƿ����Ҫ��
		if (root == nullptr)
		{
			if (k != BlackNum)
			{
				cout << "Υ��������·��������ͬ�ĺڽڵ�����Ĺ���" << endl;
				return false;
			}
			return true;
		}
		//�����ڽڵ�++k
		if (root->_col == BLACK)
			k++;
		//�ж��Ƿ���ϲ����������ĺ�ڵ�
		if (root->_parent && root->_col == RED && root->_parent->_col == RED)
		{
			cout << "Υ���˲��ܳ���������ڵ�Ĺ���" << endl;
			return false;
		}
		return _IsValidRBTree(root->_left, k, BlackNum)
			&& _IsValidRBTree(root->_right, k, BlackNum);
	}


	Node* _root = nullptr;
};


//
//void TestRBTree1()
//{
//	//int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//	RBTree<int, int> t;
//	for (auto e : a)
//	{
//		t.Insert(make_pair(e, e));
//	}
//
//	t.Inorder();
//
//	cout << t.IsValidRBTree() << endl;
//}
//
//
//void TestRBTree2()
//{
//	srand(time(0));
//	const size_t N = 10000;
//	RBTree<int, int> t;
//	for (size_t i = 0; i < N; ++i)
//	{
//		size_t x = rand();
//		t.Insert(make_pair(x, x));
//		//cout << t.IsBalance() << endl;
//	}
//
//	t.Inorder();
//
//	cout << t.IsValidRBTree() << endl;
//}