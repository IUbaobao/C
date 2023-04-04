#pragma once 

#include <iostream>
#include <ctime>
using namespace std;


namespace hdm
{
	enum Color
	{
		RED,//red��ɫ
		BLACK,//black��ɫ
	};

	template<class T>
	struct RBTreeNode
	{
		//�ڽڵ�Ķ����У�ΪʲôҪ���ڵ��Ĭ����ɫ���ɺ�ɫ�ģ�---��Ϊ����Υ���ĺ�����������٣����㴦��
		RBTreeNode(const T& val, Color color = RED)
			:_val(val), _left(nullptr), _right(nullptr), _parent(nullptr), _color(color)
		{}

		T _val;// �ڵ��ֵ
		RBTreeNode<T>* _left;// �ڵ������
		RBTreeNode<T>* _right;// �ڵ���Һ���
		RBTreeNode<T>* _parent;// �ڵ��˫��(�������Ҫ��ת��Ϊ��ʵ�ּ򵥸������ֶ�)
		Color _color;// �ڵ����ɫ
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
				_root->_color = BLACK;//�涨���ڵ㶼�Ǻ�ɫ
				return true;
			}

			Node* cur = _root;
			Node* parent = cur;//��¼parent�����������
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
			cur->_color = RED;//Ĭ�ϲ����ɫ�ڵ�
			if (parent->_val > x)//���x��ֵС��parent������߲���
			{
				parent->_left = cur;
			}
			else//���x��ֵ����parent�����ұ߲���
			{
				parent->_right = cur;
			}
			cur->_parent = parent;

			//�ж��Ƿ���Ϻ��������û����Ҫ����ɫ
			while (parent&& parent->_color == RED)
			{
				//���·��������������
				//1.����ڵ������Ϊ��---��ͼ
				//2.����ڵ㲻���ڻ��ߴ�����Ϊ��
				
				Node* grandparent = parent->_parent;
				if (grandparent->_left == parent)//ȷ������ڵ��λ��
				{
					Node* uncle = grandparent->_right;
					if (uncle && uncle->_color == RED)
					{
						//���һ������ڵ������Ϊ��
						//����ʽ����ɫ����
						parent->_color = uncle->_color = BLACK;
						grandparent->_color = RED;

						//���������Ϊ�����游�ڵ����ɫ�п���Ӱ�쵽�����ڵ�,����Ҫ�������ϵ���
						cur = grandparent;
						parent = cur->_parent;
					}
					else
					{
						//�п�����uncle�ڵ㲻���ڣ�Ҳ�п�����uncle�Ǻڽڵ�---��Ӧ�������������
						
						//uncle�ڵ���ܲ����ڻ���Ϊ�ڽڵ�
						if (parent->_left == cur)//cur��parent��ͬ��
						{
							//����+��ɫ
							RotateR(grandparent);
							parent->_color = BLACK;
							grandparent->_color = RED;
						}
						else//cur��parent����ͬһ��--�����
						{
							//������+��ɫ
							RotateL(parent);
							RotateR(grandparent);
							cur->_color = BLACK;
							grandparent->_color = RED;
						}
						break;
					}
				}
				else//grandparent->_right == parent---��ʵ�������������ƣ�ֻ���������෴
				{
					Node*uncle = grandparent->_left;
					if (uncle&& uncle->_color == RED)//���һ������ڵ������Ϊ��
					{
						uncle->_color = parent->_color = BLACK;
						grandparent->_color = RED;

						//�������ϵ���
						cur = grandparent;
						parent = cur->_parent;
					}
					else
					{
						//�����������������

						if (parent->_right == cur)//��cur��parent��ͬ���ʱ��
						{
							//����+��ɫ
							RotateL(grandparent);
							parent->_color = BLACK;
							grandparent->_color = RED;
						}
						else//��ͬ��
						{
							//������ת+��ɫ
							RotateR(parent);
							RotateL(grandparent);
							cur->_color = BLACK;
							grandparent->_color = RED;
						}
						break;
					}
				}	
			}

			_root->_color = BLACK;//��Ϊ����Ĳ����п��ܰѸ��ڵ���,������ô��ֱ�Ӽ�������Ͳ��ù��������ܳ��ָ��Ǻ�����

			return true;
		}
		void InorderTree()
		{
			InorderTree(_root);
			cout << endl;
		}

		bool IsValidRBTree()
		{
			if (_root == nullptr)//����Ҳ�Ǻ����
				return true;
			if (_root->_color != BLACK)
			{
				cout << "Υ���˺�������ʶ������ڵ����Ϊ��ɫ" << endl;
				return false;
			}
			//��ȡ����һ���ڵ�ĺ�ɫ�ڵ�
			size_t blackCount = 0;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_color == BLACK)
					blackCount++;
				cur = cur->_left;
			}
			// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
			size_t k = 0;
			return IsValidRBTree(_root,blackCount,k);
		}

	private:

		bool IsValidRBTree(Node* root,size_t blackCount,size_t k)
		{
			//�ߵ�null֮���ж�k��black�Ƿ����
			if (root == nullptr)
			{
				if (k != blackCount)
				{
					cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << endl;
					return false;
				}
				return true;
			}
			// ͳ�ƺ�ɫ�ڵ�ĸ���
			if (root->_color == BLACK)
				k++;
			// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
			Node* parent = root->_parent;
			if (parent && parent->_color == RED&& root->_color == RED)
			{
				cout << "Υ�������������ܴ�������һ��ĺ�ɫ�ڵ�" << endl;
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
		void RotateL(Node* parent)//����
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			Node* pparent = parent->_parent;
			if (subRL)//�������subRL���Ͱ����ĸ��ӹ�ϵ����
				subRL->_parent = parent;
			parent->_right = subRL;
			subR->_left = parent;
			parent->_parent = subR;

			if (pparent == nullptr)//pparentΪ�ձ�ʾparentΪ���ڵ�
			{
				_root = subR;
				_root->_parent = nullptr;
			}
			else
			{
				//pparent���ڣ�Ҫ�ж�parent֮ǰ��λ��pparent����һ��
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

		void RotateR(Node* parent)//����
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			Node* pparent = parent->_parent;

			if (subLR)//�������subLR���Ͱ����ĸ��ӹ�ϵ����
				subLR->_parent = parent;
			parent->_left = subLR;
			subL->_right = parent;
			parent->_parent = subL;
			if (pparent == nullptr)//˵��parent�Ǹ��ڵ�
			{
				_root = subL;
				_root->_parent = nullptr;
			}
			else
			{
				//pparent���ڣ�Ҫ�ж�parent֮ǰ��λ��pparent����һ��
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

