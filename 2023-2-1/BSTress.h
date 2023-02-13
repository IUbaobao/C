#pragma once 

#include <iostream>
using namespace std;

template<class T>
class BSTNode
{
public:
	BSTNode<T>* _left;
	BSTNode<T>* _right;
	T _val;
	BSTNode(const T& val) :_left(nullptr), _right(nullptr), _val(val){}
};


template<class T>
class BSTrees
{
	typedef BSTNode<T> Node;
public:
	BSTrees() :_root(nullptr){}

	BSTress(const BSTress& t)
	{
		_root=Copy(t._root);
	}

	BSTress<T>& operator=(BSTress<T> tmp)
	{
		swap(_root, tmp._root);
		return *this;
	}

	Node* Find(const T& x)
	{
		Node*cur = _root;
		while (cur)
		{
			if (cur->_val > x)
			{
				cur = cur->_left;
			}
			else if (cur->_val < x)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}
	bool erase(const T& val)
	{
		if (_root == nullptr)
		{
			return false;
		}
		Node* cur = _root;
		Node* parent = _root;
		while (cur)
		{
			if (cur->_val > val)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_val < val)
			{
				parent = cur;
				cur = cur->_right;
				
			}
			else
			{
				if (cur->_left == nullptr)
				{
					if (_root == cur)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
					
					delete cur;
					cur = nullptr;
				}
				else if (cur->_right==nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
					delete cur;
					cur = nullptr;
				}
				else
				{
					Node* minright = cur->_right;
					Node*minparent = cur;
					while (minright->_left)
					{
						minparent = minright;
						minright = minright->_left;
					}
					cur->_val = minright->_val;
					if (minparent->_right == minright)
					{
						minparent->_right = minright->_right;
					}
					else
					{
						minparent->_left = minright->_right;
					}

					delete minright;
				}
			}
		}
		
		return true;
	}

	bool insert(const T& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
		}
		Node* parent = _root;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_val < val)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_val>val)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		if (parent->_val > val)
		{
			parent->_left = new Node(val);
		}
		else
		{
			parent->_right = new Node(val);
		}
		return true;
	}
	
	~BSTress()
	{
		_Destroy(_root);
		_root = nullptr;
	}

	

	void InOrder()
	{
		_InOrder(_root);
	}

	bool insertR(const T& x)
	{
		return _insertR(_root, x);
	}

	Node* FindR(const T& x)
	{
		return _FindR(_root, x);
	}

	bool eraseR(const T&x)
	{
		return _eraseR(_root, x);
	}
private:
	Node* Copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* newNode = new Node(root->_val);
		newNode->_left = Copy(root->_left);
		newNode->_right = Copy(root->_right);
		return newNode;
	}

	bool _eraseR(Node*& root, const T&x)
	{
		if (root == nullptr)
			return false;
		if (root->_val > x)
			return _eraseR(root->_left, x);
		else if (root->_val < x)
			return _eraseR(root->_right, x);
		else
		{
			Node* del = root;
			if (root->_left == nullptr)
			{
				root = root->_right;

			}
			else if (root->_right == nullptr)
			{
				root = root->_left;
			}
			else
			{
				Node* minRight = root->_right;
				while (minRight->_left)
				{
					minRight = minRight->_left;
				}
				swap(root->_val, minRight->_val);
				return _eraseR(root->_right, x);
			}
			delete del;
			return true;
		}

	}
	Node* _FindR(Node* root, const T&x)
	{
		if (root == nullptr)
			return root;
		if (root->_val > x)
		{
			return _FindR(root->_left, x);
		}
		else if (root->_val < x)
		{
			return _FindR(root->_right, x);
		}
		else
		{
			return root;
		}
	}
	bool _insertR(Node*& root, const T& x)
	{
		if (root == nullptr)
		{
			root = new Node(x);
			return true;
		}
		if (root->_val > x)
		{
			return _insertR(root->_left, x);
		}
		else if (root->_val < x)
		{
			return _insertR(root->_right, x);
		}
		return false;
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_val << " ";
		_InOrder(root->_right);
	}
	void _Destroy(Node* root)
	{
		if (root == nullptr)
			return;
		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
		root = nullptr;
	}

private:
	Node* _root;
};
