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