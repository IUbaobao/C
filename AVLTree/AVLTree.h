#pragma once 
#include <iostream>
namespace hdm
{
	template<class T>
	struct AVLTreeNode
	{
		T _val;
		AVLTreeNode<T>*_left;// 该节点的左孩子
		AVLTreeNode<T>* _right;// 该节点的右孩子
		AVLTreeNode<T>* _parent;// 该节点的双亲
		int _bf;// 该节点的平衡因子

		AVLTreeNode(const T& data)
			:_val(data), _left(nullptr), _right(nullptr), _parent(nullptr), _bf(0)
		{}
	};


	template<class T>
	class AVLTree
	{
	public:
		typedef AVLTreeNode<T> Node;

		

		bool insert(const T& x)
		{
			if (_root == nullptr)
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
			cur = new Node(x);
			if (parent->_val > x)//如果x的值小于parent就往左边插入
			{
				parent->_left = cur;
			}
			else//如果x的值大于parent就往右边插入
			{
				parent->_right = cur;
			}
			//注意这里是三叉链结构，要把父子关系连上
			cur->_parent = parent;


			//更新平衡因子
			while (parent)//parent为空就结束，也就是更新到根的位置就停止
			{
				//新增在右,parent->_bf++
				//新增在左,parent->_bf--
				if (parent->_left == cur)
				{
					parent->_bf--;
				}
				else
				{
					parent->_bf++;
				}

				/*判断是否更新的依据：子树的高度是否变化
				1.parent->_bf==0,说明parent->_bf是1或者-1,也就是说明之前是一边高一个边低
				这次插入填上矮的那边，parent所在子树高度不变，
				现在插入的节点刚好让它平衡了，就不需要向上更新了
				2.parent->_bf==1 或 parent->_bf==-1,说明之前parent->_bf=0,插入前是平衡的，插入之后
				导致一边高一边低，这个时候就要继续向上更新
				3.parent->_bf==2 或 parent->_bf==-2 ,说明之前parent->_bf==1 或 -1的，现在插入的节点
				导致严重不平衡，违反了规则，就要进行就地处理--旋转
				*/

				//旋转：
				//1.让这棵子树左右高度不超过1
				//2.旋转过程中进行保持它是搜索树
				//3.更新调整孩子节点的高度平衡因子
				//3.让这颗子树的高度跟插入前保持一致

				if (parent->_bf == 0)
				{
					break;
				}
				else if (parent->_bf == -1 || parent->_bf == 1)
				{
					cur = parent;
					parent = cur->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					//旋转
					if (parent->_bf == -2 && cur->_bf == -1)
					{
						//右单旋
						RotateR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == 1)
					{
						//左单旋
						RotateL(parent);
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
					else
					{
						//未知错误(比如程序写错)
						assert(false);
					}
					break;//旋转完了之后要break
				}
				else
				{
					//未知错误
					assert(false);
				}

			}

			return true;
		}

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

		void InorderTree()
		{
			InorderTree(_root);
			std::cout << std::endl;
		}

		bool IsBalanceTree()//检验平衡二叉树
		{
			return IsBalanceTree(_root);
		}
	private:

		bool IsBalanceTree(Node* root)
		{
			if (root == nullptr)//空树叶是AVL树
				return true;
			// 计算root节点的平衡因子：即root左右子树的高度差
			int leftHeight = GetTreeHeight(root->_left);
			int rightHeight = GetTreeHeight(root->_right);
			int diff = rightHeight - leftHeight;
			// 如果计算出的平衡因子与pRoot的平衡因子不相等，或者
			// pRoot平衡因子的绝对值超过1，则一定不是AVL树
			if (diff != root->_bf || diff>1 || diff<-1)
			{
				std::cout << root->_val << "->该节点平衡因子错误!" << "root->_bf:" 
					<< root->_bf << "实际_bf" << diff << std::endl;
				return false;
			}
			// root的左和右如果都是AVL树，则该树一定是AVL树
			return IsBalanceTree(root->_left) && IsBalanceTree(root->_right);
		}

		int GetTreeHeight(Node* root)
		{
			if (root == nullptr)
				return 0;
			int left = GetTreeHeight(root->_left);
			int right = GetTreeHeight(root->_right);
			return left > right ? left + 1 : right + 1;
		}

		void InorderTree(Node* root)
		{
			if (root == nullptr)
				return;
			InorderTree(root->_left);
			std::cout << root->_val << " ";
			InorderTree(root->_right);
		}

		void RotateR(Node* parent)//右单旋
		{
			/*最要注意的点就是：这个是三叉链结构，要注意处理parent节点*/
			Node* subL = parent->_left;
			Node* subLR = subL->_right;//左子树的右子树

			Node* pparent = parent->_parent;
			
			if (subLR)//subLR 不为空就要修改它的parent
				subLR->_parent = parent;
			
			parent->_left = subLR;
			subL->_right = parent;
			parent->_parent = subL;

			if (pparent == nullptr)//pparent为空就表示parent为_root，就要修改整棵树的根
			{
				_root = subL;
				_root->_parent = nullptr;
			}
			else//不是根节点就要判断是位于pparent的那一边
			{
				if (pparent->_left == parent)
				{
					pparent->_left = subL;
				}
				else
				{
					pparent->_right = subL;
				}
				subL->_parent = pparent;
			}

			//更新平衡因子
			subL->_bf = parent->_bf = 0;

		}

		void RotateL(Node* parent)//左单旋
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			Node* pparent = parent->_parent;
			
			if (subRL)//subRL不为空就要连接它的parent
				subRL->_parent = parent;

			parent->_right = subRL;
			subR->_left = parent;
			parent->_parent = subR;

			if (pparent == nullptr)//pparent为空就表示parent为_root，就要修改整棵树的根
			{
				_root = subR;
				_root->_parent = nullptr;
			}
			else//不是根节点就要判断是位于pparent的那一边
			{
				if (pparent->_left == parent)
				{
					pparent->_left = subR;
				}
				else
				{
					pparent->_right = subR;
				}
				subR->_parent = pparent;
			}

			//更新平衡因子
			subR->_bf = parent->_bf = 0;
		}

		void RotateLR(Node* parent)//左右旋
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			int oldBf = subLR->_bf;//记录旧的平衡因子,这样才知道是在哪插入的新节点

			//先左单旋,然后再右单旋
			RotateL(parent->_left);
			RotateR(parent);

			subLR->_bf = 0;
			if (oldBf == -1)//就是在原节点的左子树插入
			{
				parent->_bf = 1;
				subL->_bf = 0;
			}
			else if(oldBf == 1)//右子树新增
			{
				subL->_bf = -1;
				parent->_bf = 0;
			}
			else if (oldBf == 0)//自己就是新增的节点
			{
				subL->_bf = parent->_bf = 0;
			}
			else
			{
				//都不是上述情况只能是有些地方写错了
				assert(false);
			}
		}

		void RotateRL(Node* parent)//右左旋
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			int oldBf = subRL->_bf;//记录旧的平衡因子

			RotateR(parent->_right);
			RotateL(parent);


			//更新平衡因子
			subRL->_bf = 0;
			if (oldBf == -1)
			{
				parent->_bf = 0;
				subR->_bf = 1;
			}
			else if (oldBf == 1)
			{
				parent->_bf = -1;
				subR->_bf = 0;
			}
			else if (oldBf == 0)
			{
				parent->_bf = subR->_bf = 0;
			}
			else
			{
				//未知错误
				assert(false);
			}
		}
	private:

		Node* _root = nullptr;
	};

	void AVLTreeTest1()
	{
		int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 ,1,2,4,3,4,4,4,4,4};
		AVLTree<int> avl;
		for (auto e: a)
		{
			avl.insert(e);
		}
		avl.InorderTree();
		cout << avl.IsBalanceTree() << endl;
	}
}