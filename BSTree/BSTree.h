#pragma once 
#include <iostream>
#include <cassert>
using namespace std;

namespace hdm
{
	//Binary Search Tree---���������������������

	template<class T>
	struct BSTreeNode
	{
		T _val;
		BSTreeNode<T>* _left;//����
		BSTreeNode<T>* _right;//�Һ���

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

		bool insert(const T& x)
		{
			if (_root == nullptr)//_root==nullptr˵��Ϊ����
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

			if (parent->_val > x)//���x��ֵС��parent������߲���
			{
				parent->_left = new Node(x);
			}
			else//���x��ֵ����parent�����ұ߲���
			{
				parent->_right = new Node(x);
			}

			return true;
		}


		bool erase(const T& x)
		{
			if (!find(x))//���������������ڵ�ͷ���false��ʾɾ��ʧ��
				return false;

			Node* cur = _root;
			Node* parent = cur;
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
				else//���ҵ�--�����ɾ��
				{
					//1.���Ӳ�����
					//2.�Һ��Ӳ�����
					//3.���Һ��Ӷ�����--�滻ɾ

					if (cur->_left == nullptr)//���1�����Ӳ�����
					{
						if (cur == _root)//���_root�պ���Ҫɾ���Ľڵ�����
						{
							_root = cur->_right;
						}
						//�Ƚ�parent��cur��ֵ��Ҫ����cur��parent����һ������
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
					else if (cur->_right == nullptr)//���2.�Һ��Ӳ�����
					{
						if (cur == _root)//������һ��_root�պ���Ҫɾ���Ľڵ�����
						{
							_root = cur->_left;
						}
						//ͬ��Ҫ�ж�cur��parent����һ��
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
					else if (cur->_left!=nullptr && cur->_right!=nullptr)//���3.���Һ��Ӷ�����--�滻ɾ
					{
						//�����ҵ�������������С�ڵ�(����������������ڵ�)
						Node* min_right = cur->_right;
						Node* min_right_parent = cur;//��¼��������С�ڵ�ĸ��ڵ㣬���ں�������
						while (min_right->_left)
						{
							min_right_parent = min_right;
							min_right = min_right->_left;
						}
						swap(cur->_val, min_right->_val);//���Խ���Ҳ���Ը���ԭ��Ҫɾ���Ľڵ�
						//cur->_val = min_right->_val;//����Ǹ���

						//Ҫɾ��min_right���������Һ���Ҫ����
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
						//���������else��˵����û�г����������������ǳ�������д���ˣ�ֱ�Ӷ��Ա���
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
		Node* findNonR(const T& x)//���ҵĵݹ�汾
		{
			return findNonR(_root, x);
		}

		bool insertNonR(const T& x)//����ĵݹ�汾
		{
			return insertNonR(_root, x);
		}

		bool eraseNonR(const T& x)//ɾ���ĵݹ�汾
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
				//1.���Ӳ�����
				//2.�Һ��Ӳ�����
				//3.���Һ��Ӷ�����
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
					return eraseNonR(root->_right, x);//Ȼ������root->_rightȥ�ݹ�ɾ���������x
				}
				else
				{
					//δ֪����
					assert(false);
				}
				delete del;
				del = nullptr;
				return true;
			}
		}


		bool insertNonR(Node*& root,const T& x)//����ĵݹ�汾
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

		Node* findNonR(Node* root,const T& x)//���ҵĵݹ�汾
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