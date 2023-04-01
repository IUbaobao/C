#pragma once 
#include <iostream>
#include <cassert>
using namespace std;

namespace hdm
{
	//Binary Search Tree---二叉搜索树或二叉排序树

	template<class T>
	struct BSTreeNode
	{
		T _val;
		BSTreeNode<T>* _left;//左孩子
		BSTreeNode<T>* _right;//右孩子

		BSTreeNode(const T& val = T())
			:_val(val), _left(nullptr), _right(nullptr)
		{}
	};


	template<class T>
	class BSTree
	{
	public:
		typedef BSTreeNode<T> Node;

		Node* find(const T& x)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_val > x)//比cur小往左子树找
				{
					cur = cur->_left;
				}
				else if (cur->_val < x)//比cur大往右子树找
				{
					cur = cur->_right;
				}
				else//相等即返回
				{
					return cur;
				}
			}

			return nullptr;
		}

		bool insert(const T& x)
		{
			if (_root == nullptr)//_root==nullptr说明为空树
			{
				_root = new Node(x);
				return true;
			}
			Node* cur = _root;
			Node* parent = cur;//记录父节点用于连接新节点

			while (cur)
			{
				//cur往子树走的同时记录子树的父节点
				if (cur->_val > x)//比cur小往左子树找
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_val < x)//比cur大往右子树找
				{
					parent = cur;
					cur = cur->_right;
				}
				else//进入else说明cur->_val==x,表示已经存在该节点，不需要插入，返回false表示插入失败
				{
					return false;
				}
			}

			//程序走到这说明cur=nullptr，最后x就应该要插入在parent的下面，至于是插入左边还是右边
			//具体看x与parent->_val 之间值的关系

			if (parent->_val > x)//如果x的值小于parent就往左边插入
			{
				parent->_left = new Node(x);
			}
			else//如果x的值大于parent就往右边插入
			{
				parent->_right = new Node(x);
			}

			return true;
		}


		bool erase(const T& x)
		{
			if (!find(x))//如果该树不存在这节点就返回false表示删除失败
				return false;

			Node* cur = _root;
			Node* parent = cur;
			while (cur)
			{
				//cur往子树走的同时记录子树的父节点
				if (cur->_val > x)//比cur小往左子树找
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_val < x)//比cur大往右子树找
				{
					parent = cur;
					cur = cur->_right;
				}
				else//已找到--分情况删除
				{
					//1.左孩子不存在
					//2.右孩子不存在
					//3.左右孩子都存在--替换删

					if (cur->_left == nullptr)//情况1：左孩子不存在
					{
						if (cur == _root)//如果_root刚好是要删除的节点的情况
						{
							_root = cur->_right;
						}
						//比较parent和cur的值，要分清cur的parent的那一个孩子
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
						delete cur;
						cur = nullptr;
					}
					else if (cur->_right == nullptr)//情况2.右孩子不存在
					{
						if (cur == _root)//跟上面一样_root刚好是要删除的节点的情况
						{
							_root = cur->_left;
						}
						//同样要判断cur是parent的哪一边
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
						delete cur;
						cur = nullptr;
					}
					else if (cur->_left!=nullptr && cur->_right!=nullptr)//情况3.左右孩子都存在--替换删
					{
						//这里找的是右子树的最小节点(就是右子树的最左节点)
						Node* min_right = cur->_right;
						Node* min_right_parent = cur;//记录右子树最小节点的父节点，用于后续连接
						while (min_right->_left)
						{
							min_right_parent = min_right;
							min_right = min_right->_left;
						}
						swap(cur->_val, min_right->_val);//可以交换也可以覆盖原来要删除的节点
						//cur->_val = min_right->_val;//这个是覆盖

						//要删除min_right，把它的右孩子要连上
						if (min_right_parent->_left == min_right)
						{
							min_right_parent->_left = min_right->_right;
						}
						else
						{
							min_right_parent->_right = min_right->_right;
						}
						delete min_right;
						min_right = nullptr;
						break;
					}
					else
					{
						//如果进入了else，说明都没有出现上面的情况，就是程序哪里写错了，直接断言报错
						assert(false);
					}

				}
			}

			return true;
		}

		void InorderTree()
		{
			_InorderTree(_root);
			cout << endl;
		}
		Node* findNonR(const T& x)//查找的递归版本
		{
			return findNonR(_root, x);
		}

		bool insertNonR(const T& x)//插入的递归版本
		{
			return insertNonR(_root, x);
		}

		bool eraseNonR(const T& x)//删除的递归版本
		{
			return eraseNonR(_root, x);
		}

	private:

		bool eraseNonR(Node*& root, const T& x)
		{
			if (root == nullptr)
				return false;
			if (root->_val > x)
			{
				return eraseNonR(root->_left, x);
			}
			else if (root->_val < x)
			{
				return eraseNonR(root->_right, x);
			}
			else
			{
				//1.左孩子不存在
				//2.右孩子不存在
				//3.左右孩子都存在
				Node* del = root;
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else if (root->_left && root->_right)
				{
					Node* right_min = root->_right;
					Node* parent_min = root;
					while (right_min->_left)
					{
						parent_min = right_min;
						right_min = right_min->_left;
					}
					swap(root->_val, right_min->_val);
					return eraseNonR(root->_right, x);//然后再让root->_right去递归删除交换后的x
				}
				else
				{
					//未知错误
					assert(false);
				}
				delete del;
				del = nullptr;
				return true;
			}
		}


		bool insertNonR(Node*& root,const T& x)//插入的递归版本
		{
			if (root == nullptr)
			{
				root = new Node(x);
				return true;
			}

			if (root->_val > x)
			{
				return insertNonR(root->_left, x);
			}
			else if (root->_val < x)
			{
				return insertNonR(root->_right, x);
			}
			else
			{
				return false;
			}

		}

		Node* findNonR(Node* root,const T& x)//查找的递归版本
		{
			if (root == nullptr)
				return root;
			if (root->_val > x)
				return findNonR(root->_left, x);
			else if (root->_val < x)
				return findNonR(root->_right, x);
			else
				return root;
		}

		void _InorderTree(Node* root)
		{
			if (root == nullptr)
				return;
			_InorderTree(root->_left);
			cout << root->_val << " ";
			_InorderTree(root->_right);
		}
	private:
		Node* _root = nullptr;
	};
	


	void BSTreeTest1()
	{
		BSTree<int> bs;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };

		for (auto e : a)
		{
			bs.insertNonR(e);
		}
		bs.InorderTree();
		auto n = bs.findNonR(13);
		if (n)
			cout << n->_val << endl;
		else
			cout << "nullptr" << endl;
		for (auto e : a)
		{
			bs.eraseNonR(e);
			bs.InorderTree();
		}
	}
}