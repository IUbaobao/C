#include<iostream>
using namespace std;


string replaceSpace(string s) {
	int count = 0; // ͳ�ƿո�ĸ���
	int sOldSize = s.size() - 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			count++;
		}
	}
	// �����ַ���s�Ĵ�С��Ҳ����ÿ���ո��滻��"%20"֮��Ĵ�С
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


//��ת�ַ����еĵ���
string reverseWords(string s) {
	int slow = 0;
	for (int i = 0; i<s.size(); ++i)//ȥ�ո�
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


//��ָ Offer 58 - II. ����ת�ַ���
string reverseLeftWords(string s, int n) {
	n %= s.size();
	reverse(s.begin(), s.end());
	reverse(s.begin(), s.begin() + s.size() - n);
	reverse(s.begin() + s.size() - n, s.end());

	return s;
}


//�ҳ��ַ����е�һ��ƥ������±�
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


//�ظ������ַ���
/*�����ж��ַ���s�Ƿ����ظ��Ӵ���ɣ�ֻҪ����sƴ����һ�����滹����һ��s�Ļ�����˵�������ظ��Ӵ���ɡ�
��Ȼ���������ж� s + s ƴ�ӵ��ַ������Ƿ����һ��s�ĵ�ʱ��
Ҫ�ٳ� s + s �����ַ���β�ַ�������������s + s��������ԭ����s������Ҫ���������м�ƴ�ӳ�����s*/��
bool repeatedSubstringPattern(string s) {
	string t = s + s;
	t.erase(t.begin());
	t.erase(t.end() - 1);

	int pos = t.find(s);
	return pos != std::string::npos;
}



//�ϲ�������
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