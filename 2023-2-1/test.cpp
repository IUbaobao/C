#include <iostream>
#include <string>
#include <vector>
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


//���������ƽ��
//class Solution {
//public:
//	int exchangeBits(int num) {
//		return (num & 0xaaaaaaaa) >> 1 | (num & 0x55555555) << 1;
//	}
//};
//

//class Solution {
//public:
//	vector<int> sortedSquares(vector<int>& nums) {
//		int i = 0, j = nums.size() - 1;
//		vector<int> v;
//		while (i <= j)
//		{
//			if (nums[i] * nums[i]>nums[j] * nums[j])
//			{
//				v.push_back(nums[i] * nums[i]);
//				i++;
//			}
//			else
//			{
//				v.push_back(nums[j] * nums[j]);
//				j--;
//			}
//		}
//		reverse(v.begin(), v.end());
//		return v;
//	}
//};

//������С��������
//class Solution {
//public:
//	int minSubArrayLen(int target, vector<int>& nums) {
//		int result = INT32_MAX;
//		int j = 0;
//		int sum = 0;
//		for (int i = 0; i<nums.size(); ++i)
//		{
//			sum += nums[i];
//			while (sum >= target)
//			{
//				int length = (i - j + 1);
//				result = length<result ? length : result;
//				sum -= nums[j++];
//			}
//		}
//		return result == INT32_MAX ? 0 : result;
//	}
//};


#include <stack>
//int main() 
//{
//	//����ջ���� ջ������������Ƚ����
//	stack<int> s;
//
//	//��ջ�����Ԫ�أ����� ѹջ ��ջ
//	s.push(10);
//	s.push(20);
//	s.push(30);
//
//	while (!s.empty()) {
//		//���ջ��Ԫ��
//		cout << "ջ��Ԫ��Ϊ�� " << s.top() << endl;
//		//����ջ��Ԫ��
//		s.pop();
//	}
//	cout << "ջ�Ĵ�СΪ��" << s.size() << endl;
//
//	return 0;
//}


//
//int main()
//{
//	//������������ ����������������Ƚ��ȳ�
//	queue<int> q;
//
//	//����������Ԫ�أ����� �����
//	q.push(10);
//	q.push(20);
//	q.push(30);
//
//	while (!q.empty()) {
//		//�����ͷԪ��
//		cout << "��ͷԪ��Ϊ�� " << q.front() << endl;
//		//������ͷԪ��
//		q.pop();
//	}
//	cout << "���еĴ�СΪ��" << q.size() << endl;
//
//	return 0;
//}

#include <queue>
#include <functional> // greater�㷨��ͷ�ļ�
//int main()
//{
//	// Ĭ������£��������Ǵ�ѣ���ײ㰴��С�ںűȽ�
//	priority_queue<int> q1;
//	q1.push(4);
//	q1.push(1);
//	q1.push(2);
//	q1.push(5);
//	q1.push(3);
//
//	while (!q1.empty())
//	{
//		cout << q1.top() << " ";
//		q1.pop();
//	}
//	cout << endl;
//
//
//	// ���Ҫ����С�ѣ���������ģ���������greater�ȽϷ�ʽ
//	priority_queue<int, vector<int>, greater<int>> q2;
//	q2.push(4);
//	q2.push(1);
//	q2.push(2);
//	q2.push(5);
//	q2.push(3);
//
//	while (!q2.empty())
//	{
//		cout << q2.top() << " ";
//		q2.pop();
//	}
//	cout << endl;
//	return 0;
//}


class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}
	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}
	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
};
void TestPriorityQueue()
{
	// ��ѣ���Ҫ�û����Զ����������ṩ<������
	//��Ϊ����������֪���û��Զ������͵ıȽϷ�ʽ����ô����
	priority_queue<Date> q1;
	q1.push(Date(2018, 10, 29));
	q1.push(Date(2018, 10, 28));
	q1.push(Date(2018, 10, 30));
	cout << q1.top() << endl;
	// ���Ҫ����С�ѣ���Ҫ�û��ṩ>������
	priority_queue<Date, vector<Date>, greater<Date>> q2;
	q2.push(Date(2018, 10, 29));
	q2.push(Date(2018, 10, 28));
	q2.push(Date(2018, 10, 30));
	cout << q2.top() << endl;

}

#include "priority_queue.h"

int main()
{
	hdm::priority_queue<int,vector<int>,hdm::greater<int>> q1;
	q1.push(2);
	q1.push(3);
	q1.push(1);
	q1.push(4);
	q1.push(10);

	while (!q1.empty())
	{
		cout << q1.top() << " ";
		q1.pop();
	}
	cout << endl;
	return 0;
}