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

	int _bf;//ƽ������

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
			else//����򲻲���
			{
				return false;
			}
		}

		cur = new Node(kv);
		//�ж�Ӧ�ò�����һ��
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

		//����ƽ������
		while (parent)// parentΪ�գ�Ҳ�͸��µ���
		{
			//��������,parent->_bf++
			//��������,parent->_bf--
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			// �Ƿ�����������ݣ������ĸ߶��Ƿ�仯
			// 1��parent->_bf == 0˵��֮ǰparent->_bf�� 1 ���� -1
			// ˵��֮ǰparentһ�߸�һ�ߵͣ���β������ϰ����Ǳߣ�parent���������߶Ȳ��䣬����Ҫ�������ϸ���
			// 2��parent->_bf == 1 �� -1 ˵��֮ǰ��parent->_bf == 0������һ���ߣ����ڲ���һ�߸����ˣ�
			// parent���������߶ȱ��ˣ��������ϸ���
			// 3��parent->_bf == 2 �� -2��˵��֮ǰparent->_bf == 1 ���� -1�����ڲ������ز�ƽ�⣬Υ������
			// �͵ش���--��ת

			// ��ת��
			// 1��������������Ҹ߶Ȳ�����1
			// 2����ת�����м�����������������
			// 3�����µ������ӽڵ��ƽ������
			// 4������������ĸ߶ȸ�����ǰ����һ��
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
					//����
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					//�ҵ���
					RotateR(parent);
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
				else//δ֪����
				{
					cout << parent->_kv.first << endl;
					cout << cur->_kv.first << endl;
					assert(false);
				}
				break;
			}
			else//δ֪����
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
		
		parent->_bf = SubR->_bf = 0;
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
		parent->_bf = SubL->_bf = 0;
	}
	void RotateLR(Node* parent)
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;
		int oldBF = SubLR->_bf;//��¼ƽ�����ӣ�����½ڵ�Ĳ���λ��

		RotateL(parent->_left);
		RotateR(parent);

		SubLR->_bf = 0;
		if (oldBF == -1)//����������
		{
			SubL->_bf = 0;
			parent->_bf = 1;
		}
		else if (oldBF==1)//����������
		{
			SubL->_bf = -1;
			parent->_bf = 0;
		}
		else if (oldBF == 0)//�Լ���������
		{
			SubL->_bf = 0;
			parent->_bf = 0;
		}
		else//δ֪����
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
		
		//����ƽ������
		SubRL->_bf = 0;
		if (oldBF == 0)//�Լ��������ڵ�	
		{
			parent->_bf = 0;
			SubR->_bf = 0;
		}
		else if (oldBF == 1)//����������
		{
			parent->_bf = -1;
			SubR->_bf = 0;
		}
		else if (oldBF==-1)//����������
		{
			parent->_bf = 0;
			SubR->_bf = 1;
		}
		else//δ֪����
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
			cout <<root->_kv.first<< "ƽ�������쳣" << endl;
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