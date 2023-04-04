#pragma once 

#include <iostream>
#include <ctime>
using namespace std;


namespace hdm
{
	enum Color
	{
		RED,//red红色
		BLACK,//black黑色
	};

	template<class T>
	struct RBTreeNode
	{
		//在节点的定义中，为什么要将节点的默认颜色给成红色的？---因为这样违反的红黑树规则最少，方便处理
		RBTreeNode(const T& val, Color color = RED)
			:_val(val), _left(nullptr), _right(nullptr), _parent(nullptr), _color(color)
		{}

		T _val;// 节点的值
		RBTreeNode<T>* _left;// 节点的左孩子
		RBTreeNode<T>* _right;// 节点的右孩子
		RBTreeNode<T>* _parent;// 节点的双亲(红黑树需要旋转，为了实现简单给出该字段)
		Color _color;// 节点的颜色
	};
	


	template<class T>
	class RBTree
	{
	public:
		typedef RBTreeNode<T> Node;

		bool Insert(const T& x)
		{
			if (_root == nullptr)
			{
				_root = new Node(x);
				_root->_color = BLACK;//规定根节点都是黑色
				return true;
			}

			Node* cur = _root;
			Node* parent = cur;//记录parent方便后续插入
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
			cur = new Node(x);
			cur->_color = RED;//默认插入红色节点
			if (parent->_val > x)//如果x的值小于parent就往左边插入
			{
				parent->_left = cur;
			}
			else//如果x的值大于parent就往右边插入
			{
				parent->_right = cur;
			}
			cur->_parent = parent;

			//判断是否符合红黑树规则，没有则要改颜色
			while (parent&& parent->_color == RED)
			{
				//大致分两个大种情况：
				//1.叔叔节点存在且为红---看图
				//2.叔叔节点不存在或者存在且为黑
				
				Node* grandparent = parent->_parent;
				if (grandparent->_left == parent)//确定叔叔节点的位置
				{
					Node* uncle = grandparent->_right;
					if (uncle && uncle->_color == RED)
					{
						//情况一：叔叔节点存在且为红
						//处理方式：变色处理
						parent->_color = uncle->_color = BLACK;
						grandparent->_color = RED;

						//这种情况因为改了祖父节点的颜色有可能影响到其他节点,所以要继续向上调整
						cur = grandparent;
						parent = cur->_parent;
					}
					else
					{
						//有可能是uncle节点不存在，也有可能是uncle是黑节点---对应就是情况二和三
						
						//uncle节点可能不存在或者为黑节点
						if (parent->_left == cur)//cur与parent是同侧
						{
							//右旋+变色
							RotateR(grandparent);
							parent->_color = BLACK;
							grandparent->_color = RED;
						}
						else//cur和parent不是同一侧--情况三
						{
							//左右旋+变色
							RotateL(parent);
							RotateR(grandparent);
							cur->_color = BLACK;
							grandparent->_color = RED;
						}
						break;
					}
				}
				else//grandparent->_right == parent---其实跟上面的情况类似，只不过方向相反
				{
					Node*uncle = grandparent->_left;
					if (uncle&& uncle->_color == RED)//情况一：叔叔节点存在且为空
					{
						uncle->_color = parent->_color = BLACK;
						grandparent->_color = RED;

						//继续向上调整
						cur = grandparent;
						parent = cur->_parent;
					}
					else
					{
						//可能是情况二或者三

						if (parent->_right == cur)//当cur与parent是同侧的时候
						{
							//左旋+变色
							RotateL(grandparent);
							parent->_color = BLACK;
							grandparent->_color = RED;
						}
						else//不同侧
						{
							//右左旋转+变色
							RotateR(parent);
							RotateL(grandparent);
							cur->_color = BLACK;
							grandparent->_color = RED;
						}
						break;
					}
				}	
			}

			_root->_color = BLACK;//因为上面的操作有可能把跟节点变红,不管怎么样直接加这句代码就不用管它不可能出现根是红的情况

			return true;
		}
		void InorderTree()
		{
			InorderTree(_root);
			cout << endl;
		}

		bool IsValidRBTree()
		{
			if (_root == nullptr)//空树也是红黑树
				return true;
			if (_root->_color != BLACK)
			{
				cout << "违反了红黑树性质二：根节点必须为黑色" << endl;
				return false;
			}
			//获取任意一个节点的黑色节点
			size_t blackCount = 0;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_color == BLACK)
					blackCount++;
				cur = cur->_left;
			}
			// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
			size_t k = 0;
			return IsValidRBTree(_root,blackCount,k);
		}

	private:

		bool IsValidRBTree(Node* root,size_t blackCount,size_t k)
		{
			//走到null之后，判断k和black是否相等
			if (root == nullptr)
			{
				if (k != blackCount)
				{
					cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
					return false;
				}
				return true;
			}
			// 统计黑色节点的个数
			if (root->_color == BLACK)
				k++;
			// 检测当前节点与其双亲是否都为红色
			Node* parent = root->_parent;
			if (parent && parent->_color == RED&& root->_color == RED)
			{
				cout << "违反性质三：不能存在连在一起的红色节点" << endl;
				return false;
			}
			
			return IsValidRBTree(root->_left,blackCount,k) && 
					IsValidRBTree(root->_right,blackCount,k);
		}

		void InorderTree(Node* root)
		{
			if (root == nullptr)
				return;
			InorderTree(root->_left);
			cout << root->_val << " ";
			InorderTree(root->_right);
		}
		void RotateL(Node* parent)//左旋
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			Node* pparent = parent->_parent;
			if (subRL)//如果存在subRL，就把它的父子关系连上
				subRL->_parent = parent;
			parent->_right = subRL;
			subR->_left = parent;
			parent->_parent = subR;

			if (pparent == nullptr)//pparent为空表示parent为根节点
			{
				_root = subR;
				_root->_parent = nullptr;
			}
			else
			{
				//pparent存在，要判断parent之前是位置pparent的那一边
				if (pparent->_left == parent)
				{
					pparent->_left = subR;
				}
				else
				{
					pparent->_right = subR;
				}
			}
			subR->_parent = pparent;
		}

		void RotateR(Node* parent)//右旋
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			Node* pparent = parent->_parent;

			if (subLR)//如果存在subLR，就把它的父子关系连上
				subLR->_parent = parent;
			parent->_left = subLR;
			subL->_right = parent;
			parent->_parent = subL;
			if (pparent == nullptr)//说明parent是根节点
			{
				_root = subL;
				_root->_parent = nullptr;
			}
			else
			{
				//pparent存在，要判断parent之前是位置pparent的那一边
				if (pparent->_left == parent)
				{
					pparent->_left = subL;
				}
				else
				{
					pparent->_right = subL;
				}
			}
			subL->_parent = pparent;
		}
	private:
		Node* _root=nullptr;
	};


	void RBTreeTest1()
	{
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		//	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
		RBTree<int> t;
		for (auto e : a)
		{
			if (e == 13)
				int i = 0;
			t.Insert(e);
		}
		t.InorderTree();
	}


	void RBTreeTest2()
	{
		srand(time(0));
		const size_t N = 10000;
		RBTree<int> t;
		for (size_t i = 0; i < N; ++i)
		{
			size_t x = rand();
			t.Insert(x);
			//cout << t.IsBalance() << endl;
		}

		t.InorderTree();

		cout << t.IsValidRBTree() << endl;
	}
}

