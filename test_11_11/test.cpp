//#include<iostream>
//using namespace std;
//
//
//string replaceSpace(string s) {
//	int count = 0; // ͳ�ƿո�ĸ���
//	int sOldSize = s.size() - 1;
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] == ' ') {
//			count++;
//		}
//	}
//	// �����ַ���s�Ĵ�С��Ҳ����ÿ���ո��滻��"%20"֮��Ĵ�С
//	s.resize(s.size() + count * 2);
//	int sNewSize = s.size() - 1;
//	while (sOldSize >= 0)
//	{
//		if (s[sOldSize] == ' ')
//		{
//			s[sNewSize--] = '0';
//			s[sNewSize--] = '2';
//			s[sNewSize--] = '%';
//			sOldSize--;
//		}
//		else
//		{
//			s[sNewSize--] = s[sOldSize--];
//		}
//	}
//	return s;
//}
//
//
////��ת�ַ����еĵ���
//string reverseWords(string s) {
//	int slow = 0;
//	for (int i = 0; i<s.size(); ++i)//ȥ�ո�
//	{
//		if (s[i] != ' ')
//		{
//			if (slow != 0)
//				s[slow++] = ' ';
//			while (i<s.size() && s[i] != ' ')
//			{
//				s[slow++] = s[i++];
//			}
//		}
//	}
//
//	s.resize(slow);
//	reverse(s.begin(), s.end());
//	int prev = 0;
//	for (int i = 0; i<s.size(); ++i)
//	{
//		if (s[i] == ' ')
//		{
//			reverse(s.begin() + prev, s.begin() + i);
//			prev = i + 1;
//		}
//	}
//	reverse(s.begin() + prev, s.end());
//
//	return s;
//
//}
//
//int main()
//{
//	//replaceSpace("We are happy.");
//	//string s("hello world");
//	//cout << s.size() << endl;
//	//s.reserve(16);
//	//cout << s.size() << endl;
//	reverseWords("  world hello  ");
//	return 0;
//}
//
//
////��ָ Offer 58 - II. ����ת�ַ���
//string reverseLeftWords(string s, int n) {
//	n %= s.size();
//	reverse(s.begin(), s.end());
//	reverse(s.begin(), s.begin() + s.size() - n);
//	reverse(s.begin() + s.size() - n, s.end());
//
//	return s;
//}
//
//
////�ҳ��ַ����е�һ��ƥ������±�
//int strStr(string haystack, string needle) {
//	int begin = 0;
//	int cur1 = 0, cur2 = 0;
//	while (begin<haystack.size())
//	{
//		while (haystack[cur1] == needle[cur2] && haystack[cur1] != '\0')
//		{
//			cur1++;
//			cur2++;
//		}
//		if (needle[cur2] == '\0')
//		{
//			return begin;
//		}
//		cur1 = ++begin;
//		cur2 = 0;
//	}
//	return -1;
//
//}
//
//
////�ظ������ַ���
///*�����ж��ַ���s�Ƿ����ظ��Ӵ���ɣ�ֻҪ����sƴ����һ�����滹����һ��s�Ļ�����˵�������ظ��Ӵ���ɡ�
//��Ȼ���������ж� s + s ƴ�ӵ��ַ������Ƿ����һ��s�ĵ�ʱ��
//Ҫ�ٳ� s + s �����ַ���β�ַ�������������s + s��������ԭ����s������Ҫ���������м�ƴ�ӳ�����s*/��
//bool repeatedSubstringPattern(string s) {
//	string t = s + s;
//	t.erase(t.begin());
//	t.erase(t.end() - 1);
//
//	int pos = t.find(s);
//	return pos != std::string::npos;
//}
//
//
//
////�ϲ�������
//TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//	if (root1 == nullptr)
//		return root2;
//	if (root2 == nullptr)
//		return root1;
//
//	root1->val += root2->val;
//	root1->left = mergeTrees(root1->left, root2->left);
//	root1->right = mergeTrees(root1->right, root2->right);
//	return root1;
//
//}
//
//
//
//
////118. �������
//class Solution {
//public:
//	vector<vector<int>> generate(int numRows) {
//		vector<vector<int> > vv;
//		vv.resize(numRows);
//		for (size_t i = 0; i< vv.size(); ++i)
//		{
//			vv[i].resize(i + 1, 0);
//			vv[i][0] = vv[i][vv[i].size() - 1] = 1;
//		}
//		for (size_t i = 0; i<vv.size(); ++i)
//		{
//			for (size_t j = 0; j<vv[i].size(); ++j)
//			{
//				if (vv[i][j] == 0)
//				{
//					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
//				}
//			}
//		}
//		return vv;
//	}
//};
//
//
////�����������е�����
//TreeNode* searchBST(TreeNode* root, int val) {
//	if (root == NULL || root->val == val) return root;
//	if (root->val > val) return searchBST(root->left, val);
//	if (root->val < val) return searchBST(root->right, val);
//	return NULL;
//}
//
//
////��֤����������
//class Solution {
//public:
//	TreeNode*prev = nullptr;
//	bool isValidBST(TreeNode* root) {
//		if (!root)
//			return true;
//		bool left = isValidBST(root->left);
//		if (prev != nullptr && prev->val >= root->val)
//			return false;
//		prev = root;
//		bool right = isValidBST(root->right);
//		return left&&right;
//	}
//};
//
//
//
////530. ��������������С���Բ�
//class Solution {
//public:
//	TreeNode*prev = nullptr;
//	int min = INT_MAX;
//	int getMinimumDifference(TreeNode* root) {
//		if (root == nullptr)
//			return 0;
//		getMinimumDifference(root->left);
//		if (prev != nullptr && abs(root->val - prev->val)<min)
//		{
//			min = abs(root->val - prev->val);
//		}
//		prev = root;
//		getMinimumDifference(root->right);
//		return min;
//	}
//};
//
//
//
////501. �����������е�����
//class Solution {
//public:
//	TreeNode*prev = nullptr;
//	int count = 0, maxcount = 0;
//	vector<int> result;
//	vector<int> findMode(TreeNode* root) {
//		_findMode(root);
//		return result;
//	}
//	void _findMode(TreeNode* cur)
//	{
//		if (cur == nullptr)
//			return;
//		_findMode(cur->left);
//		if (prev != nullptr && prev->val == cur->val)
//		{
//			count++;
//		}
//		else
//		{
//			count = 1;
//		}
//		prev = cur;
//		if (count == maxcount)
//		{
//			result.push_back(cur->val);
//		}
//		if (count>maxcount)
//		{
//			result.clear();
//			maxcount = count;
//			result.push_back(cur->val);
//		}
//		_findMode(cur->right);
//	}
//
//};
//
//
//
////��Ӿ�����ˮƽ���
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int cmpint(const void * e1, const void* e2)
//{
//	return *(int*)e2 - *(int*)e1;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	for (int i = 0; i < 3 * n; ++i)
//	{
//		int num;
//		cin >> num;
//		v.push_back(num);
//	}
//
//	qsort(&v[0], v.size(), sizeof(v[0]), cmpint);
//
//	int sum = 0;
//	int i = 1 ;
//	//for (auto e : v)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//	while (n--)
//	{
//		sum += v[i];
//		i += 2;
//	}
//	cout << sum << endl;
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string s1, s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	for (size_t i = 0; i<s2.size(); ++i)
//	{
//		for (size_t j = 0; j<s1.size(); ++j)
//		{
//			if (s1[j] == s2[i])
//			{
//				s1.erase(j,1);
//			}
//		}
//	}
//	cout << s1 << endl;
//	return 0;
//}





//#include<iostream>
//#include<string>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	string s;
//	getline(cin, s);
//	reverse(s.begin(), s.end());
//	int begin = 0;
//	for (int i = 0; i < s.size(); ++i)
//	{
//		if (s[i] == ' ')
//		{
//			reverse(s.begin() + begin, s.begin() + i);
//			begin = i + 1;
//		}
//	}
//	reverse(s.begin() + begin, s.end());
//	cout << s << endl;
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	long long int n;
//	cin >> n;
//	vector<long long int> v;
//	v.resize(n+1);
//	for (long long int i = 0; i < n; ++i)
//	{
//		cin >> v[i];
//	}
//	 int count = 0;
//	 int i = 0;
//	 while (i < n)
//	 {
//		 if (v[i]>v[i + 1])
//		 {
//			 while (i<n && v[i] >= v[i + 1])
//			 {
//				 i++;
//			 }
//			 count++;
//			 i++;
//		 }
//		 else if (v[i] < v[i + 1])
//		 {
//			 while (i<n && v[i] <= v[i + 1])
//			 {
//				 i++;
//			 }
//			 count++;
//			 i++;
//		 }
//		 else
//		 {
//			 i++;
//		 }
//	 }
//	cout << count << endl;
//	return 0;
//}
//

//�ַ������ҳ�����������ִ�
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//bool isnum(char&s)
//{
//	if (s >= '0' && s <= '9')
//	{
//		return true;
//	}
//	return false;
//}
//int main()
//{
//	string s;
//	cin >> s;
//	int begin = 0,prev=0;
//	int count = 0,maxcount=0,i=0;
//	while (i<s.size())
//	{
//		while (i<s.size() && !isnum(s[i]))
//		{
//			i++;
//		}
//		begin = i;
//		while (i<s.size() && isnum(s[i++]))
//		{
//			count++;
//		}
//		if (maxcount < count)
//		{
//			prev = begin;
//			maxcount = count;
//		}
//		count = 0;
//	}
//	for (int j = prev; j < maxcount + prev; ++j)
//	{
//		cout << s[j];
//	}
//	cout << endl;
//	return 0;
//}


//// �����г��ִ�������һ�������
//����һ�£��������Щ���ֵ������֣�һ�����ֺ�����һ�����ִ���������
//ͬ���ھ������ʣ�µ��ǲ����������������ˡ�����Ҫ����һ��������ĳ���˵���Ŀһ��Ҫ������������һ�롣
//�㷨���裺����ѡ�����������е�һ��Ԫ����Ϊ��ѡԪ��candidate������������ִ���Ϊcount = 1��
//���������顣��������candidate��ͬ��Ԫ�أ�count + 1; ��ͬ��Ԫ�أ�count - 1����countΪ0��ʱ��
//ѡ����һ��Ԫ��Ϊ��ѡԪ�أ�������count = 1����������������ʣ�µ�candidate����Ҫ��Ľ����
//int candidate = numbers[0], count = 1;
//for (int i = 0; i<numbers.size(); ++i)
//{
//	if (candidate == numbers[i])
//	{
//		count++;
//	}
//	else{
//		count--;
//	}
//	if (count == 0)
//	{
//		candidate = numbers[i];
//		count = 1;
//	}
//}
//	return candidate;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int> v;
//	//v.reserve(100);
//	//cout << v.capacity() << endl;
//	//v.reserve(50);
//	//cout << v.capacity() << endl;
//	v.resize(10);
//	//cout << v[10] << endl;
//	cout << v.at(10) << endl;
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	printf("%s,%20.3s\n", "hello", "computer");
//	printf("%10.3f",123.123123);
//
//	return 0;
//}


//#include<iostream>
//
//int main()
//{
//	int a = 123;
//	printf("%o\n", a);
//	return 0;
//}

#include<iostream>
using namespace std;
int main()
{
	int a, b, c,d;
	cin >> a >> b >> c>>d;

	int B = (b + d) / 2;
	int A = (a + c) / 2;
	int C = B - b;
	if (A - B == a &&B - C == b&&A + B == c&&B + C == d)
		cout << A << " " << B << " " << C << endl;
	else
		cout << "No" << endl;
	return 0;
}