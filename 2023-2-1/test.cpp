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
//	Person p("张三", 19);
//	p.Print();
//	Student s("李四",1);
//	s.Print();
//	return 0;
//}

//字符串压缩
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

// 配对交换
//用10101010（即0xaa）作为掩码提取奇数位，再用01010101（即0x55）作为掩码提取偶数位；
//提取奇数位后向右移到偶数位的位置，提取偶数位后向左移到奇数位的位置，进行或运算即可。

class Solution {
public:
	int exchangeBits(int num) {
		return (num & 0xaaaaaaaa) >> 1 | (num & 0x55555555) << 1;
	}
};