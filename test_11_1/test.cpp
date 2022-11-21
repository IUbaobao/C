
//字符串最后一个单词的长度
//#include <iostream>
//using namespace std;
//
//int main() {
//
//	string s;
//	getline(cin, s);
//
//	int ret = s.rfind(' ');
//
//	cout << s.size() - ret - 1 << endl;
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string s("123");
//	//s.reserve(111);
//	//s.reserve(50);
//	//s.resize(2);
//	//cout << s.capacity() << " "<<s.size()<<  endl;
//	int a;
//	a = s.find('3') != string::npos;
//	cout << a << endl;
//
//	return 0;
//}
//
//int main()
//{
//
//	string strText = "How are you?";
//	string strSeparator = " ";
//	string strResult;
//	int size_pos = 0;
//	int size_prev_pos = 0;
//
//	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
//	{
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//		size_prev_pos = ++size_pos;
//	}
//	if (size_prev_pos != strText.size())
//	{
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//	}
//	cout << endl;
//	return 0;
//}

//把字符串转换成整数
//class Solution {
//public:
//	int StrToInt(string str) {
//
//		int sum = 0;
//		int flag = 1;
//		for (int i = str.size() - 1; i >= 0; --i)
//		{
//			if (str[i] >= '0'&& str[i] <= '9')
//			{
//				sum += (str[i] - '0')*flag;
//				flag *= 10;
//			}
//			else if (i == 0 && str[i] == '-')
//			{
//				sum *= -1;
//			}
//			else if (i == 0 || i == str.size() - 1)
//			{
//				continue;
//			}
//
//			else{
//				return 0;
//			}
//		}
//		return sum;
//
//	}
//};

//反转字符串中的单词 III
////给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//class Solution {
//public:
//	string reverseWords(string s) {
//		int begin = 0;
//		for (int i = 0; i<s.size(); ++i)
//		{
//			if (s[i] == ' ')
//			{
//				reverse(s.begin() + begin, s.begin() + i);
//				begin = i + 1;
//			}
//		}
//		reverse(s.begin() + begin, s.end());
//		return s;
//	}
//};


//完全二叉树的节点个数
//class Solution {
//public:
//	int countNodes(TreeNode* root) {
//		if (!root)
//			return 0;
//		TreeNode*left = root->left;
//		TreeNode*right = root->right;
//		int count1 = 0, count2 = 0;
//		//分别计算直左直右长度是否相等
//		while (left)
//		{
//			count1++;
//			left = left->left;
//		}
//		while (right)
//		{
//			count2++;
//			right = right->right;
//		}
//		//相等即为满二叉树：2^n-1
//		if (count1 == count2)
//		{
//			return (2 << count1) - 1;
//		}
//
//		return  countNodes(root->left) +
//			countNodes(root->right) + 1;
//	}
//};
//
//// 左叶子之和
//class Solution {
//public:
//	int sumOfLeftLeaves(TreeNode* root) {
//		if (!root)
//			return 0;
//		int leftval = 0;
//		if (root->left != nullptr && root->left->left == nullptr &&root->left->right == nullptr)
//		{
//			leftval = root->left->val;
//		}
//
//		return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + leftval;
//	}
//};


//#include<stdio.h>
//int main()
//{
//	char arr[10][10];
	//for (int i = 0; i< 10; i++)
	//{
	//	scanf("%s", arr[i]);
	//}
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0] + 1);
//	printf("%p\n", &arr[0][0]);
//	printf("%p\n", &arr[0][0] + 1);
//
//	return 0;
//}
//#include<iostream>
//#include<stack>
//#include<vector>
//using namespace std;
//class Treenode
//{
//public:
//	int _val;
//	Treenode*left;
//	Treenode*right;
//
//	Treenode(int val=0)
//		:_val(val)
//		, left(nullptr)
//		, right(nullptr)
//	{}
//
//};
//void TreePrev(Treenode*root)
//{
//	if (!root)
//		return;
//	cout << root->_val << " ";
//	TreePrev(root->left);
//	TreePrev(root->right);
//}
//
//void Tree(Treenode*root)
//{
//	if (!root)
//		return;
//	Tree(root->left);
//	Tree(root->right);
//	cout << root->_val << " ";
//}
//
//vector<int> TreePrevNoNR(Treenode*root)
//{
//	stack<Treenode*>st;
//	vector<int> v;
//	st.push(root);
//	while (!st.empty())
//	{
//		Treenode*node = st.top();
//		st.pop();
//		if (node == nullptr)
//			continue;
//		v.push_back(node->_val);
//		if (node->right)
//			st.push(node->right);
//		if (node->left != nullptr)
//			st.push(node->left);
//	}
//	return v;
//}
//
//vector<int> TreeNoNR(Treenode*root)
//{
//	stack<Treenode*>st;
//	vector<int> v;
//	st.push(root);
//	while (!st.empty())
//	{
//		Treenode*node = st.top();
//		st.pop();
//		if (node == nullptr)
//			continue;
//		v.push_back(node->_val);
//		if (node->left != nullptr)
//			st.push(node->left);
//		if (node->right)
//			st.push(node->right);
//	}
//	reverse(v.begin(), v.end());
//	return v;
//}
//
//
//int main()
//{
//	Treenode n1(5);
//	Treenode n2(4);
//	Treenode n3(6);
//	Treenode n4(1);
//	Treenode n5(2);
//	n1.left = &n2;
//	n1.right = &n3;
//	n2.left = &n4;
//	n2.right = &n5;
//	TreePrev(&n1);
//	cout << endl;
//	vector<int> result=TreePrevNoNR(&n1);
//	for (auto e : result)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	Tree(&n1);
//	cout << endl;
//
//	vector<int> result2 = TreeNoNR(&n1);
//	for (auto e : result2)
//	{
//		cout << e << " ";
//	}
//	return 0;
//}

//
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//	/*
//	该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
//	通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，
//	编译器无法确定此处到底该将T确定为int 或者 double类型而报错
//	注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
//	Add(a1, d1);
//	*/
//	// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
//	Add(a1, (int)d1);
//	return 0;
//}
//
//
//
//
//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//	Add<int>(1, 2); // 调用编译器特化的Add版本
//}
//
//
//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//
//}
//
//
//// 动态顺序表
//// 注意：Vector不是具体的类，是编译器根据被实例化的类型生成具体类的模具
//template<class T>
//class Vector
//{
//public:
//	Vector(size_t capacity = 10)
//		: _pData(new T[capacity])
//		, _size(0)
//		, _capacity(capacity)
//	{}
//	// 使用析构函数演示：在类中声明，在类外定义。
//	~Vector();
//	void PushBack(const T& data)；
//		void PopBack()；
//		// ...
//private:
//	T* _pData;
//	size_t _size;
//	size_t _capacity;
//};

#include"string.h"

#include<string>

int main()
{
	hdm::Test_String6();
	//string s("hello world");
	//s.resize(15, '!');
	//cout << s << endl;
	//s.resize(100,'!');
	//cout << s << endl;
	//string s;
	//cin >> s;
	//cout << s << endl;
	/*char arr1[10] = "123";
	char arr2[10] = "234";*/
	//cout << strcmp(arr2, arr1) << endl;


	return 0;
}


//
////两两交换链表中的节点
//ListNode* swapPairs(ListNode* head) {
//	ListNode* newhead = new ListNode(0);
//	newhead->next = head;
//	ListNode* cur = newhead;
//	while (cur->next != nullptr && cur->next->next != nullptr)
//	{
//		ListNode*tem1 = cur->next;
//		ListNode*tem2 = cur->next->next->next;
//
//		cur->next = cur->next->next;
//		cur->next->next = tem1;
//		tem1->next = tem2;
//
//		cur = cur->next->next;
//	}
//	return newhead->next;
//}
//
//
////删除链表的倒数第 N 个结点
//class Solution {
//public:
//	ListNode* removeNthFromEnd(ListNode* head, int n) {
//		ListNode* newhead = new ListNode(0);
//		newhead->next = head;
//		ListNode*fast = newhead, *slow = newhead;
//		while (n-- && fast != nullptr)
//		{
//			fast = fast->next;
//		}
//		while (fast != nullptr&& fast->next != nullptr)
//		{
//			fast = fast->next;
//			slow = slow->next;
//		}
//		slow->next = slow->next->next;
//		return newhead->next;
//	}
//};
//
//
//
//// 链表相交
//class Solution {
//public:
//	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//		int count1 = 0, count2 = 0;
//		ListNode *cur1 = headA, *cur2 = headB;
//		//统计链表长度
//		while (cur1)
//		{
//			count1++;
//			cur1 = cur1->next;
//		}
//		while (cur2)
//		{
//			count2++;
//			cur2 = cur2->next;
//		}
//
//		//让长的那个先走差距步
//		ListNode * longlist = headA, *shortlist = headB;
//		if (count1<count2)
//		{
//			longlist = headB;
//			shortlist = headA;
//		}
//		int gap = abs(count1 - count2);
//		while (gap--)
//		{
//			longlist = longlist->next;
//		}
//		//两个链表一起走，有相等即为相交
//		while (longlist && shortlist)
//		{
//			if (longlist == shortlist)
//				return longlist;
//			longlist = longlist->next;
//			shortlist = shortlist->next;
//		}
//		return nullptr;
//	}
//};
//
//
//
//
//
//
////找树左下角的值
//class Solution {
//public:
//	int maxDepth = INT_MIN;
//	int reslut;
//	int findBottomLeftValue(TreeNode* root) {
//		int depth = 1;
//		_findBottomLeftValue(root, depth);
//		return reslut;
//	}
//
//	void _findBottomLeftValue(TreeNode* root, int depth)
//	{
//		if (root->left == nullptr && root->right == nullptr)
//		{
//			if (depth>maxDepth)
//			{
//				maxDepth = depth;
//				reslut = root->val;
//			}
//		}
//
//		if (root->left)
//		{
//			_findBottomLeftValue(root->left, depth + 1);
//		}
//		if (root->right)
//		{
//			_findBottomLeftValue(root->right, depth + 1);
//		}
//	}
//};
//
//
//
////左叶子之和
//
//class Solution {
//public:
//	int sumOfLeftLeaves(TreeNode* root) {
//		if (root == nullptr)
//			return 0;
//		int leftleav = 0;
//		if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
//		{
//			leftleav = root->left->val;
//		}
//
//		return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + leftleav;
//	}
//};