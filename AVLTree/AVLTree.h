#pragma once 
#include <iostream>
namespace hdm
{
	template<class T>
	struct AVLTreeNode
	{
		T _val;
		AVLTreeNode<T>*_left;// �ýڵ������
		AVLTreeNode<T>* _right;// �ýڵ���Һ���
		AVLTreeNode<T>* _parent;// �ýڵ��˫��
		int _bf;// �ýڵ��ƽ������

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
			Node* parent = cur;//��¼���ڵ����������½ڵ�

			while (cur)
			{
				//cur�������ߵ�ͬʱ��¼�����ĸ��ڵ�
				if (cur->_val > x)//��curС����������
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_val < x)//��cur������������
				{
					parent = cur;
					cur = cur->_right;
				}
				else//����else˵��cur->_val==x,��ʾ�Ѿ����ڸýڵ㣬����Ҫ���룬����false��ʾ����ʧ��
				{
					return false;
				}
			}

			//�����ߵ���˵��cur=nullptr�����x��Ӧ��Ҫ������parent�����棬�����ǲ�����߻����ұ�
			//���忴x��parent->_val ֮��ֵ�Ĺ�ϵ
			cur = new Node(x);
			if (parent->_val > x)//���x��ֵС��parent������߲���
			{
				parent->_left = cur;
			}
			else//���x��ֵ����parent�����ұ߲���
			{
				parent->_right = cur;
			}
			//ע���������������ṹ��Ҫ�Ѹ��ӹ�ϵ����
			cur->_parent = parent;


			//����ƽ������
			while (parent)//parentΪ�վͽ�����Ҳ���Ǹ��µ�����λ�þ�ֹͣ
			{
				//��������,parent->_bf++
				//��������,parent->_bf--
				if (parent->_left == cur)
				{
					parent->_bf--;
				}
				else
				{
					parent->_bf++;
				}

				/*�ж��Ƿ���µ����ݣ������ĸ߶��Ƿ�仯
				1.parent->_bf==0,˵��parent->_bf��1����-1,Ҳ����˵��֮ǰ��һ�߸�һ���ߵ�
				��β������ϰ����Ǳߣ�parent���������߶Ȳ��䣬
				���ڲ���Ľڵ�պ�����ƽ���ˣ��Ͳ���Ҫ���ϸ�����
				2.parent->_bf==1 �� parent->_bf==-1,˵��֮ǰparent->_bf=0,����ǰ��ƽ��ģ�����֮��
				����һ�߸�һ�ߵͣ����ʱ���Ҫ�������ϸ���
				3.parent->_bf==2 �� parent->_bf==-2 ,˵��֮ǰparent->_bf==1 �� -1�ģ����ڲ���Ľڵ�
				�������ز�ƽ�⣬Υ���˹��򣬾�Ҫ���о͵ش���--��ת
				*/

				//��ת��
				//1.������������Ҹ߶Ȳ�����1
				//2.��ת�����н��б�������������
				//3.���µ������ӽڵ�ĸ߶�ƽ������
				//3.����������ĸ߶ȸ�����ǰ����һ��

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
					//��ת
					if (parent->_bf == -2 && cur->_bf == -1)
					{
						//�ҵ���
						RotateR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == 1)
					{
						//����
						RotateL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == 1)
					{
						//������
						RotateLR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == -1)
					{
						//������
						RotateRL(parent);
					}
					else
					{
						//δ֪����(�������д��)
						assert(false);
					}
					break;//��ת����֮��Ҫbreak
				}
				else
				{
					//δ֪����
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
				if (cur->_val > x)//��curС����������
				{
					cur = cur->_left;
				}
				else if (cur->_val < x)//��cur������������
				{
					cur = cur->_right;
				}
				else//��ȼ�����
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

		bool IsBalanceTree()//����ƽ�������
		{
			return IsBalanceTree(_root);
		}
	private:

		bool IsBalanceTree(Node* root)
		{
			if (root == nullptr)//����Ҷ��AVL��
				return true;
			// ����root�ڵ��ƽ�����ӣ���root���������ĸ߶Ȳ�
			int leftHeight = GetTreeHeight(root->_left);
			int rightHeight = GetTreeHeight(root->_right);
			int diff = rightHeight - leftHeight;
			// ����������ƽ��������pRoot��ƽ�����Ӳ���ȣ�����
			// pRootƽ�����ӵľ���ֵ����1����һ������AVL��
			if (diff != root->_bf || diff>1 || diff<-1)
			{
				std::cout << root->_val << "->�ýڵ�ƽ�����Ӵ���!" << "root->_bf:" 
					<< root->_bf << "ʵ��_bf" << diff << std::endl;
				return false;
			}
			// root��������������AVL���������һ����AVL��
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

		void RotateR(Node* parent)//�ҵ���
		{
			/*��Ҫע��ĵ���ǣ�������������ṹ��Ҫע�⴦��parent�ڵ�*/
			Node* subL = parent->_left;
			Node* subLR = subL->_right;//��������������

			Node* pparent = parent->_parent;
			
			if (subLR)//subLR ��Ϊ�վ�Ҫ�޸�����parent
				subLR->_parent = parent;
			
			parent->_left = subLR;
			subL->_right = parent;
			parent->_parent = subL;

			if (pparent == nullptr)//pparentΪ�վͱ�ʾparentΪ_root����Ҫ�޸��������ĸ�
			{
				_root = subL;
				_root->_parent = nullptr;
			}
			else//���Ǹ��ڵ��Ҫ�ж���λ��pparent����һ��
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

			//����ƽ������
			subL->_bf = parent->_bf = 0;

		}

		void RotateL(Node* parent)//����
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			Node* pparent = parent->_parent;
			
			if (subRL)//subRL��Ϊ�վ�Ҫ��������parent
				subRL->_parent = parent;

			parent->_right = subRL;
			subR->_left = parent;
			parent->_parent = subR;

			if (pparent == nullptr)//pparentΪ�վͱ�ʾparentΪ_root����Ҫ�޸��������ĸ�
			{
				_root = subR;
				_root->_parent = nullptr;
			}
			else//���Ǹ��ڵ��Ҫ�ж���λ��pparent����һ��
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

			//����ƽ������
			subR->_bf = parent->_bf = 0;
		}

		void RotateLR(Node* parent)//������
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			int oldBf = subLR->_bf;//��¼�ɵ�ƽ������,������֪�������Ĳ�����½ڵ�

			//������,Ȼ�����ҵ���
			RotateL(parent->_left);
			RotateR(parent);

			subLR->_bf = 0;
			if (oldBf == -1)//������ԭ�ڵ������������
			{
				parent->_bf = 1;
				subL->_bf = 0;
			}
			else if(oldBf == 1)//����������
			{
				subL->_bf = -1;
				parent->_bf = 0;
			}
			else if (oldBf == 0)//�Լ����������Ľڵ�
			{
				subL->_bf = parent->_bf = 0;
			}
			else
			{
				//�������������ֻ������Щ�ط�д����
				assert(false);
			}
		}

		void RotateRL(Node* parent)//������
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			int oldBf = subRL->_bf;//��¼�ɵ�ƽ������

			RotateR(parent->_right);
			RotateL(parent);


			//����ƽ������
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
				//δ֪����
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