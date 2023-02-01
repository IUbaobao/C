#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person()
	{}
	Person(string name,int age)
		:_name(name), _age(age)
	{}
	void Print()
	{
		cout << _name << " " << _age << endl;
	}
protected:
	string _name;
private:
	int _age;
};

class Student :public Person
{
public:
	Student(string name,int age,int num=0)
		:Person(name, age), _num(num)
	{}

protected:
	int _num;
};
//
//int main()
//{
//	Person p("����", 19);
//	p.Print();
//	Student s("����",1);
//	s.Print();
//	return 0;
//}

//�ַ���ѹ��
class Solution {
public:
	string compressString(string S) {
		if (S.size() == 0)
			return S;
		string ret;
		char c = S[0];
		char prev;
		int count = 0;
		for (auto e : S)
		{
			if (c == e)
			{
				count++;
				prev = e;
			}
			else
			{
				ret += prev;
				ret += to_string(count);
				count = 1;
				c = e;
				prev = e;
			}
		}
		ret += S[S.size() - 1];
		ret += to_string(count);
		if (ret.size() >= S.size())
			return S;
		return ret;

	}
};

//int main()
//{
//	string s = Solution().compressString("aabcccccaa");
//	return 0;
//}

// ��Խ���
//��10101010����0xaa����Ϊ������ȡ����λ������01010101����0x55����Ϊ������ȡż��λ��
//��ȡ����λ�������Ƶ�ż��λ��λ�ã���ȡż��λ�������Ƶ�����λ��λ�ã����л����㼴�ɡ�

class Solution {
public:
	int exchangeBits(int num) {
		return (num & 0xaaaaaaaa) >> 1 | (num & 0x55555555) << 1;
	}
};