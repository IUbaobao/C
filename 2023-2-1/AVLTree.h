#pragma once 

#include <iostream>
#include <cassert>
#include <ctime>
using namespace std;

template <class K, class V>
struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf;//平衡因子

	AVLTreeNode(const pair<K, V> kv)
		:_kv(kv), _left(nullptr), _right(nullptr), _parent(nullptr), _bf(0)
	{}
};


template <class K, class V>
class AVLTree
{
public:
	typedef AVLTreeNode<K, V> Node;

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
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
			else//相等则不插入
			{
				return false;
			}
		}

		cur = new Node(kv);
		//判断应该插入那一边
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;

		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		//更新平衡因子
		while (parent)// parent为空，也就更新到根
		{
			//新增在右,parent->_bf++
			//新增在左,parent->_bf--
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			// 是否继续更新依据：子树的高度是否变化
			// 1、parent->_bf == 0说明之前parent->_bf是 1 或者 -1
			// 说明之前parent一边高一边低，这次插入填上矮的那边，parent所在子树高度不变，不需要继续往上更新
			// 2、parent->_bf == 1 或 -1 说明之前是parent->_bf == 0，两边一样高，现在插入一边更高了，
			// parent所在子树高度变了，继续往上更新
			// 3、parent->_bf == 2 或 -2，说明之前parent->_bf == 1 或者 -1，现在插入严重不平衡，违反规则
			// 就地处理--旋转

			// 旋转：
			// 1、让这颗子树左右高度不超过1
			// 2、旋转过程中继续保持他是搜索树
			// 3、更新调整孩子节点的平衡因子
			// 4、让这颗子树的高度跟插入前保持一致
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = cur->_parent;
			}
			else if (parent->_bf == -2 || parent->_bf == 2)
			{
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					//左单旋
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					//右单旋
					RotateR(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					//左右旋
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					//右左旋
					RotateRL(parent);
				}
				else//未知错误
				{
					cout << parent->_kv.first << endl;
					cout << cur->_kv.first << endl;
					assert(false);
				}
				break;
			}
			else//未知错误
			{
				assert(false);
			}
		}
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
		
		parent->_bf = SubR->_bf = 0;
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
		parent->_bf = SubL->_bf = 0;
	}
	void RotateLR(Node* parent)
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;
		int oldBF = SubLR->_bf;//记录平衡因子，清楚新节点的插入位置

		RotateL(parent->_left);
		RotateR(parent);

		SubLR->_bf = 0;
		if (oldBF == -1)//左子树新增
		{
			SubL->_bf = 0;
			parent->_bf = 1;
		}
		else if (oldBF==1)//右子树新增
		{
			SubL->_bf = -1;
			parent->_bf = 0;
		}
		else if (oldBF == 0)//自己就是新增
		{
			SubL->_bf = 0;
			parent->_bf = 0;
		}
		else//未知错误
		{
			assert(false);
		}

	}

	void RotateRL(Node* parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;
		int oldBF = SubRL->_bf;

		RotateR(SubR);
		RotateL(parent);
		
		//更新平衡因子
		SubRL->_bf = 0;
		if (oldBF == 0)//自己是新增节点	
		{
			parent->_bf = 0;
			SubR->_bf = 0;
		}
		else if (oldBF == 1)//右子树新增
		{
			parent->_bf = -1;
			SubR->_bf = 0;
		}
		else if (oldBF==-1)//左子树新增
		{
			parent->_bf = 0;
			SubR->_bf = 1;
		}
		else//未知错误
		{
			assert(false);
		}
	}
	bool IsBalance()
	{
		return _IsBalance(_root);
	}
	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;
		int ldepth = Heigth(root->_left);
		int rdepth = Heigth(root->_right);

		if (rdepth - ldepth != root->_bf)
		{
			cout <<root->_kv.first<< "平衡因子异常" << endl;
		}
		return abs(ldepth - rdepth) < 2 && _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}

	int Heigth(Node* root)
	{
		if (root == nullptr)
			return 0;
		int ldepth = Heigth(root->_left);
		int rdepth = Heigth(root->_right);

		return ldepth > rdepth ? ldepth + 1 : rdepth + 1;
	}
	void Inorder()
	{
		_Inorder(_root);
	}
private:
	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_Inorder(root->_right);
	}

private:
	Node* _root=nullptr;
};


//void TestAVLTree()
//{
//	//int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//	AVLTree<int, int> t;
//	for (auto e : a)
//	{
//		t.Insert(make_pair(e, e));
//	}
//
//	t.Inorder();
//
//	cout << t.IsBalance() << endl;
//}


void TestAVLTree()
{
	srand(time(0));
	const size_t N = 10000;
	AVLTree<int, int> t;
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand();
		t.Insert(make_pair(x, x));
		//cout << t.IsBalance() << endl;
	}

	t.Inorder();

	cout << t.IsBalance() << endl;
}