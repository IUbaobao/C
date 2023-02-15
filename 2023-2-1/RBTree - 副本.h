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

template <class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V> *_parent;
	RBTreeNode<K, V>*_left;
	RBTreeNode<K, V>* _right;
	pair<K, V> _kv;
	Color _col;

	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv), _parent(nullptr), _left(nullptr), _right(nullptr), _col(RED)
	{}
};


template <class K, class V>
class RBTree
{
public:
	typedef RBTreeNode<K, V> Node;
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}
		Node* cur = _root;
		Node* parent = _root;
		//找合适位置插入
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else//相等不插入
			{
				return false;
			}
		}
		cur = new Node(kv);
		cur->_col = RED;//默认插入红色节点
		//判断往哪个子树插入
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;

		//判断是否符合红黑树规则，没有则要改颜色
		while (parent&& parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node*uncle = grandfather->_right;
				//情况一：舅舅节点存在且为红,让父亲节点和舅舅节点变黑，祖父变红
				if (uncle&& uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//情况二，uncle节点可能不存在可能为黑节点，而且cur在parent的左边
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						cur->_col = grandfather->_col = RED;

					}
					//情况三，uncle节点可能不存在可能为黑节点，但cur在parent的右边
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
				//情况一：舅舅节点存在且为红,让父亲节点和舅舅节点变黑，祖父变红
				if (uncle&& uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//进行向上调整
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//情况二，uncle节点可能不存在可能为黑节点，而且cur在parent的右边
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						cur->_col = grandfather->_col = RED;

					}
					//情况三，uncle节点可能不存在可能为黑节点，但cur在parent的左边
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
		return true;
	}

	void RotateL(Node* parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;

		Node* pparent = parent->_parent;

		parent->_right = SubRL;
		//SubRL不为空就要改parent
		if (SubRL)
			SubRL->_parent = parent;

		SubR->_left = parent;
		parent->_parent = SubR;
		SubR->_parent = pparent;

		if (pparent == nullptr)//pparent为空则要改根
		{
			_root = SubR;
			_root->_parent = nullptr;
		}
		else // 不为空则要判断位于那个子树
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
		//SubLR不为空就要改parent
		if (SubLR)
			SubLR->_parent = parent;

		SubL->_right = parent;
		parent->_parent = SubL;

		SubL->_parent = pparent;
		if (pparent == nullptr)//pparent为空则要改根
		{
			_root = SubL;
			_root->_parent = nullptr;
		}
		else//不为空则要判断位于那个子树
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
	//判断是否满足红黑树性质
	bool IsValidRBTree()
	{
		//空树也符合
		if (_root == nullptr)
			return true;
		//判断根是否符合
		if (_root->_col != BLACK)
			return false;
		//找一条路径记录黑色节点的个数
		Node* cur = _root;
		int BlackNum = 0;
		while (cur)
		{
			if (cur->_col == BLACK)
				BlackNum++;
			cur = cur->_left;
		}
		//记录每一个路径的黑节点个数
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
		//遇到空，判断这条路径上的黑节点是否符合要求
		if (root == nullptr)
		{
			if (k != BlackNum)
			{
				cout << "违反了任意路径都有相同的黑节点个数的规则" << endl;
				return false;
			}
			return true;
		}
		//遇到黑节点++k
		if (root->_col == BLACK)
			k++;
		//判断是否符合不存在连续的红节点
		if (root->_parent && root->_col == RED && root->_parent->_col == RED)
		{
			cout << "违反了不能出现连续红节点的规则" << endl;
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
void TestRBTree2()
{
	srand(time(0));
	const size_t N = 10000;
	RBTree<int, int> t;
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand();
		t.Insert(make_pair(x, x));
		//cout << t.IsBalance() << endl;
	}

	t.Inorder();

	cout << t.IsValidRBTree() << endl;
}
