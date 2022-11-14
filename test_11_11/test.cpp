#include<iostream>
using namespace std;


string replaceSpace(string s) {
	int count = 0; // 统计空格的个数
	int sOldSize = s.size() - 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			count++;
		}
	}
	// 扩充字符串s的大小，也就是每个空格替换成"%20"之后的大小
	s.resize(s.size() + count * 2);
	int sNewSize = s.size() - 1;
	while (sOldSize >= 0)
	{
		if (s[sOldSize] == ' ')
		{
			s[sNewSize--] = '0';
			s[sNewSize--] = '2';
			s[sNewSize--] = '%';
			sOldSize--;
		}
		else
		{
			s[sNewSize--] = s[sOldSize--];
		}
	}
	return s;
}


//反转字符串中的单词
string reverseWords(string s) {
	int slow = 0;
	for (int i = 0; i<s.size(); ++i)//去空格
	{
		if (s[i] != ' ')
		{
			if (slow != 0)
				s[slow++] = ' ';
			while (i<s.size() && s[i] != ' ')
			{
				s[slow++] = s[i++];
			}
		}
	}

	s.resize(slow);
	reverse(s.begin(), s.end());
	int prev = 0;
	for (int i = 0; i<s.size(); ++i)
	{
		if (s[i] == ' ')
		{
			reverse(s.begin() + prev, s.begin() + i);
			prev = i + 1;
		}
	}
	reverse(s.begin() + prev, s.end());

	return s;

}

int main()
{
	//replaceSpace("We are happy.");
	//string s("hello world");
	//cout << s.size() << endl;
	//s.reserve(16);
	//cout << s.size() << endl;
	reverseWords("  world hello  ");
	return 0;
}


//剑指 Offer 58 - II. 左旋转字符串
string reverseLeftWords(string s, int n) {
	n %= s.size();
	reverse(s.begin(), s.end());
	reverse(s.begin(), s.begin() + s.size() - n);
	reverse(s.begin() + s.size() - n, s.end());

	return s;
}


//找出字符串中第一个匹配项的下标
int strStr(string haystack, string needle) {
	int begin = 0;
	int cur1 = 0, cur2 = 0;
	while (begin<haystack.size())
	{
		while (haystack[cur1] == needle[cur2] && haystack[cur1] != '\0')
		{
			cur1++;
			cur2++;
		}
		if (needle[cur2] == '\0')
		{
			return begin;
		}
		cur1 = ++begin;
		cur2 = 0;
	}
	return -1;

}


//重复的子字符串
/*所以判断字符串s是否有重复子串组成，只要两个s拼接在一起，里面还出现一个s的话，就说明是又重复子串组成。
当然，我们在判断 s + s 拼接的字符串里是否出现一个s的的时候，
要刨除 s + s 的首字符和尾字符，这样避免在s + s中搜索出原来的s，我们要搜索的是中间拼接出来的s*/。
bool repeatedSubstringPattern(string s) {
	string t = s + s;
	t.erase(t.begin());
	t.erase(t.end() - 1);

	int pos = t.find(s);
	return pos != std::string::npos;
}



//合并二叉树
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
	if (root1 == nullptr)
		return root2;
	if (root2 == nullptr)
		return root1;

	root1->val += root2->val;
	root1->left = mergeTrees(root1->left, root2->left);
	root1->right = mergeTrees(root1->right, root2->right);
	return root1;

}