//#include<iostream>
//using namespace std;
//
//
//string replaceSpace(string s) {
//	int count = 0; // 统计空格的个数
//	int sOldSize = s.size() - 1;
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] == ' ') {
//			count++;
//		}
//	}
//	// 扩充字符串s的大小，也就是每个空格替换成"%20"之后的大小
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
////反转字符串中的单词
//string reverseWords(string s) {
//	int slow = 0;
//	for (int i = 0; i<s.size(); ++i)//去空格
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
////剑指 Offer 58 - II. 左旋转字符串
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
////找出字符串中第一个匹配项的下标
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
////重复的子字符串
///*所以判断字符串s是否有重复子串组成，只要两个s拼接在一起，里面还出现一个s的话，就说明是又重复子串组成。
//当然，我们在判断 s + s 拼接的字符串里是否出现一个s的的时候，
//要刨除 s + s 的首字符和尾字符，这样避免在s + s中搜索出原来的s，我们要搜索的是中间拼接出来的s*/。
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
////合并二叉树
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
////118. 杨辉三角
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
////二叉搜索树中的搜索
//TreeNode* searchBST(TreeNode* root, int val) {
//	if (root == NULL || root->val == val) return root;
//	if (root->val > val) return searchBST(root->left, val);
//	if (root->val < val) return searchBST(root->right, val);
//	return NULL;
//}
//
//
////验证二叉搜索树
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
////530. 二叉搜索树的最小绝对差
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
////501. 二叉搜索树中的众数
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
////组队竞赛求水平最高
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

//字符串中找出最长的连续数字串
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


//// 数组中出现次数超过一半的数字
//想象一下，如果把这些数字当做人种，一个数字和另外一个数字打了起来，
//同归于尽。最后剩下的是不是人数最多的那种人。这里要满足一个条件：某类人的数目一定要大于总人数的一半。
//算法步骤：我们选择输入数组中第一个元素作为候选元素candidate，并设置其出现次数为count = 1。
//随后遍历数组。当遇到与candidate相同的元素，count + 1; 不同的元素，count - 1。当count为0的时候，
//选择下一个元素为候选元素，并且置count = 1。遍历到数组的最后，剩下的candidate就是要求的结果。
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

//#include<iostream>
//using namespace std;
//int main()
//{
//	int a, b, c,d;
//	cin >> a >> b >> c>>d;
//
//	int B = (b + d) / 2;
//	int A = (a + c) / 2;
//	int C = B - b;
//	if (A - B == a &&B - C == b&&A + B == c&&B + C == d)
//		cout << A << " " << B << " " << C << endl;
//	else
//		cout << "No" << endl;
//	return 0;
//}



//进制转换
//#include <iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	string s1("0123456789ABCDEFG");
//	string s;
//	int flag = 1;
//	if (m<0)
//	{
//		m *= -1;
//		flag = -1;
//	}
//	while (m)
//	{
//		s += s1[m%n];
//		m /= n;
//	}
//	if (flag == -1)
//	{
//		s += '-';
//	}
//	reverse(s.begin(), s.end());
//	if (s.size() != 0)
//		cout << s << endl;
//	else
//		cout << '0' << endl;
//	return 0;
//}



//#include<iostream>
//#include<algorithm>
//#include<string>
//using namespace std;
//
//bool ispalindrome(string& s)
//{
//	int begin = 0, end = s.size() - 1;
//	while (begin < end)
//	{
//		if (s[begin] != s[end])
//		{
//			return false;
//		}
//		begin++;
//		end--;
//	}
//	return true;
//}
//
//int main()
//{
//	string s1, s2;
//	cin >> s1 >> s2;
//	int count = 0;
//	for (size_t j = 0; j < s1.size(); j++)
//	{
//		s1.insert(j, s2);
//		if (ispalindrome(s1))
//		{
//			count++;
//		}
//		s1.erase(j,s2.size());
//	}
//	cout << count << endl;
//	return 0;
//}



//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int maxsum = 0;

//void max_arry(int n, int sum, int startIndex)
//{
//	if (startIndex==n)
//	{
//		return;
//	}
//		
//	for (int i = startIndex; i < n; ++i)
//	{
//		sum += v[i];
//		if (sum > maxsum)
//		{
//			maxsum = sum;
//		}
//		max_arry(n, sum, i + 1);
//		sum -= v[i];
//	}
//}

//int main()
//{
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; ++i)
//	{
//		int k;
//		cin >> k;
//		v.push_back(k);
//	}
//	int sum = 0;
//	max_arry(n,sum,0);
//	cout << maxsum << endl;
//	return 0;
//}

//
//
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> v(n);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> v[i];
//	}
//	int sum = 0,maxsum=0,begin=0;
//	for (int i = 0; i < v.size(); ++i)
//	{
//		sum += v[i];
//		if (sum > maxsum)
//		{
//			while (i<v.size() && sum + v[i]>maxsum)
//			{
//				sum += v[i++];
//			}
//			maxsum = sum;
//		}
//		while (begin<=i && sum - v[begin]>maxsum )
//		{
//			sum -= v[begin++];
//		}
//
//		
//	}
//	cout << maxsum << endl;
//	return 0;
//}
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() 
//{
//	//string构造
//	string s1; //创建空字符串，调用无参构造函数
//	cout << "str1 = " << s1 << endl;
//
//	const char* str = "hello world";
//	string s2(str); //把c_string转换成了string
//
//	cout << "str2 = " << s2 << endl;
//
//	string s3(s2); //调用拷贝构造函数
//	cout << "str3 = " << s3 << endl;
//
//	string s4(10, 'a');
//	cout << "str3 = " << s3 << endl;
//	return 0;
//}


#include <iostream>
#include <string>
using namespace std;
//int main() {
//	//赋值
//	string str1;
//	str1 = "hello world";
//	cout << "str1 = " << str1 << endl;
//
//	string str2;
//	str2 = str1;
//	cout << "str2 = " << str2 << endl;
//
//	string str3;
//	str3 = 'a';
//	cout << "str3 = " << str3 << endl;
//
//	string str4;
//	str4.assign("hello c++");
//	cout << "str4 = " << str4 << endl;
//
//	string str5;
//	str5.assign("hello c++", 5);
//	cout << "str5 = " << str5 << endl;
//
//
//	string str6;
//	str6.assign(str5);
//	cout << "str6 = " << str6 << endl;
//
//	string str7;
//	str7.assign(5, 'x');
//	cout << "str7 = " << str7 << endl;
//
//	return 0;
//}

//
//int main() {
//	//字符串拼接
//	string str1 = "我";
//
//	str1 += "爱玩游戏";
//
//	cout << "str1 = " << str1 << endl;
//
//	str1 += ':';
//
//	cout << "str1 = " << str1 << endl;
//
//	string str2 = "Minecraft";
//
//	str1 += str2;
//
//	cout << "str1 = " << str1 << endl;
//
//	string str3 = "I";
//	str3.append(" love ");
//	str3.append("game abcde", 4);
//	//str3.append(str2);
//	str3.append(str2, 4, 3); // 从下标4位置开始 ，截取3个字符，拼接到字符串末尾
//	cout << "str3 = " << str3 << endl;
//
//	return 0;
//}


//查找和替换
void test01()
{
	//查找
	string str1 = "abcdefgde";

	int pos = str1.find("de");

	if (pos == -1)
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "pos = " << pos << endl;
	}


	pos = str1.rfind("de");

	cout << "pos = " << pos << endl;

}

void test02()
{
	//替换
	string str1 = "abcdefgde";
	str1.replace(1, 3, "1111");

	cout << "str1 = " << str1 << endl;
}


void test03()
{
	string str = "hello world";

	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;


	//字符修改
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl;

}

//
//int main() {
//
//	test03();
//	return 0;
//}

//字符串插入和删除
//int main() {
//	string str = "hello";
//	str.insert(1, "111");
//	cout << str << endl;
//
//	str.erase(1, 3);  //从1号位置开始3个字符
//	cout << str << endl;
//	return 0;
//}

//
////子串
//int main() {
//
//	string str = "abcdefg";
//	string subStr = str.substr(1, 3);
//	cout << "subStr = " << subStr << endl;
//
//	string email = "hello@sina.com";
//	int pos = email.find("@");
//	string username = email.substr(0, pos);
//	cout << "username: " << username << endl;
//
//	return 0;
//}

//
//#include<string>
//#include"string.h"
//
//int main()
//{
//	hdm::stringtest2();
//	//string s1("hello world");
//
//	//cout << s1.c_str() << endl;
//	//size_t pos = s1.find('d');
//	//if (pos != -1)
//	//{
//	//	s1.insert(pos,1,'u');
//	//}
//	//cout << s1.c_str() << endl;
//
//	return 0;
//}

//字符串转整数
//#include<iostream>
//#include<string>
//using namespace std;
//class Solution {
//public:
//	int StrToInt(string str) {
//		int flag = 1;
//		if (str[0] == '-')
//		{
//			flag = -1;
//			str.erase(0,1);
//
//		}
//		else if (str[0] == '+')
//		{
//			flag = 1;
//			str.erase(0,1);
//		}
//		else if (!isnum(str[0]))
//		{
//			return 0;
//		}
//		long long sum = 0;
//		int j = 1;
//		for (int i = str.size() - 1; i>=0; --i)
//		{
//			if (isnum(str[i]))
//			{
//				sum += (str[i] - '0')*j;
//				j *= 10;
//			}
//			else
//			{
//				return 0;
//			}
//		}
//		return sum*flag;
//
//	}
//
//	bool isnum(const char& s)
//	{
//		if (s >= '0'&& s <= '9')
//		{
//			return true;
//		}
//		return false;
//	}
//};
//
//
//int main()
//{
//	string s;
//	cin >> s;
//	cout << Solution().StrToInt(s) << endl;
//	return 0;
//}


//DP6 连续子数组最大和
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int Getmax(int a, int b)
//{
//	return a>b ? a : b;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> v(n);
//	v.resize(n);
//	for (int i = 0; i<n; ++i)
//		cin >> v[i];
//
//	int sum = v[0], max = v[0];
//	for (int i = 1; i<v.size(); ++i)
//	{
//		sum = Getmax(sum + v[i], v[i]);
//		if (sum>max)
//		{
//			max = sum;
//		}
//	}
//	cout << max << endl;
//	return 0;
//}

//
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s("hello world");
//	cout << "字符串s的长度为："<<s.size() << endl;
//
//	s.resize(20, '!');
//	cout <<"resize()之后的s："<< s << endl;
//	cout << "字符串s的长度为：" << s.size() << endl;
//
//	cout << endl;
//	cout << "字符串s的修改前的容量为为：" << s.capacity() << endl;
//	s.reserve(95);
//	cout << "字符串s的修改后的容量为为：" << s.capacity() << endl;
//
//	return 0;
//}





//
//#include <iostream>
//#include <limits.h>
//using namespace std;
//
//int main()
//{
//	long long int n;
//	cin >> n;
//	long long int a = 0, b = 1, c = 0, min = INT_MAX;
//	while (1)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		if (min>abs(n - c))
//		{
//			min = abs(n - c);
//		}
//		else
//		{
//			break;
//		}
//	}
//	cout << min << endl;
//	return 0;
//}


//合法括号序列判断
#include<stack>
#include<iostream>
using namespace std;
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {

		stack<char> st;
		if (A[0] == '(') st.push(A[0]);
		else  return false;

		int i = 1;
		while (i<n)
		{
			if (A[i] == '(')
			{
				st.push(A[i]);
			}
			else
			{
				if (!st.empty())
				{
					char tem = st.top();
					st.pop();
					if (A[i] != ')')
						return false;
				}
				else
					return false;
			}
			i++;
		}
		if (!st.empty())
			return false;
		return true;

	}
};
int main()
{
	cout << Parenthesis().chkParenthesis("()()(((())))", 12) << endl;
	return 0;
}






//17. 电话号码的字母组合

class Solution {
public:

	string numstring[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	void _letterCombinations(string digits, int i, string path, vector<string>&vs)
	{
		if (i == digits.size())
		{
			vs.push_back(path);
			return;
		}
		int num = digits[i] - '0';
		string str = numstring[num];
		for (auto e : str)
		{
			_letterCombinations(digits, i + 1, path + e, vs);
		}
	}

	vector<string> letterCombinations(string digits) {
		vector<string> vs;
		if (digits.size() == 0)
			return vs;

		string path;
		_letterCombinations(digits, 0, path, vs);
		return vs;

	}
};