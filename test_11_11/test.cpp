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