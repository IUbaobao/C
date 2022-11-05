
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


#include"string.h"

int main()
{
	hdm::Test_String1();
	return 0;
}