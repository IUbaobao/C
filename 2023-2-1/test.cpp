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


//有序数组的平方
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

//长度最小的子数组
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
//	//创建栈容器 栈容器必须符合先进后出
//	stack<int> s;
//
//	//向栈中添加元素，叫做 压栈 入栈
//	s.push(10);
//	s.push(20);
//	s.push(30);
//
//	while (!s.empty()) {
//		//输出栈顶元素
//		cout << "栈顶元素为： " << s.top() << endl;
//		//弹出栈顶元素
//		s.pop();
//	}
//	cout << "栈的大小为：" << s.size() << endl;
//
//	return 0;
//}


//
//int main()
//{
//	//创建队列容器 队列容器必须符合先进先出
//	queue<int> q;
//
//	//向队列中添加元素，叫做 入队列
//	q.push(10);
//	q.push(20);
//	q.push(30);
//
//	while (!q.empty()) {
//		//输出队头元素
//		cout << "队头元素为： " << q.front() << endl;
//		//弹出队头元素
//		q.pop();
//	}
//	cout << "队列的大小为：" << q.size() << endl;
//
//	return 0;
//}

#include <queue>
#include <functional> // greater算法的头文件
//int main()
//{
//	// 默认情况下，创建的是大堆，其底层按照小于号比较
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
//	// 如果要创建小堆，将第三个模板参数换成greater比较方式
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
	// 大堆，需要用户在自定义类型中提供<的重载
	//因为编译器并不知道用户自定义类型的比较方式是怎么样的
	priority_queue<Date> q1;
	q1.push(Date(2018, 10, 29));
	q1.push(Date(2018, 10, 28));
	q1.push(Date(2018, 10, 30));
	cout << q1.top() << endl;
	// 如果要创建小堆，需要用户提供>的重载
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