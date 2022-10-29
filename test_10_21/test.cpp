#include<iostream>
using namespace std;


//class Date
//{
//public:
//	////传统方式初始化
//	//Date(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	//初始化列表方式初始化
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Date
//{
//public:
//	// 1. 单参构造函数，没有使用explicit修饰，具有类型转换作用
//	// explicit修饰构造函数，禁止类型转换---explicit去掉之后，代码可以通过编译
//	 Date(int year)
//		:_year(year)
//	{}
//	
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2022);
//	// 用一个整形变量给日期类型对象赋值
//	// 实际编译器背后会用2023构造一个无名对象，最后用无名对象给d1对象进行赋值
//	d1 = 2023;
//	// 将1加上explicit编译就会失败，因为explicit修饰构造函数，禁止了单参构造函数类型转
//	//换的作用
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	// d1 << cout; -> d1.operator<<(&d1, cout); 不符合常规调用
//	// 因为成员函数第一个参数一定是隐藏的this，所以d1必须放在<<的左侧
//	ostream& operator<<(ostream& _cout)
//	{
//		_cout << _year << "-" << _month << "-" << _day << endl;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//
//class Date
//{
//	//友元声明（可在类中的任意位置声明，不包括成员函数体内）
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year = 1970, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}


//class Time
//{
//	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};


//class stu
//{
//public:
//	class cat
//	{
//	private:
//		int age;
//		char name[10];
//	};
//private:
//	int age;
//	char name[10];
//};
//
//int main()
//{
//	cout << sizeof(stu) << endl;
//	cout << sizeof(stu::cat) << endl;
//	return 0;
//}
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//...
//		return n;
//	}
//};
//int main()
//{
//	A aa1;
//	// 不能这么定义对象，因为编译器无法识别下面是一个函数声明，还是对象定义
//	//A aa1();
//	// 但是我们可以这么定义匿名对象，匿名对象的特点不用取名字，
//	// 但是他的生命周期只有这一行，我们可以看到下一行他就会自动调用析构函数
//	A();
//	A aa2(2);
//	// 匿名对象在这样场景下就很好用，当然还有一些其他使用场景
//	Solution().Sum_Solution(10);
//	return 0;
//}


//class Data
//{
//public:
//	Data(int year=1970,int month=0,int day=0)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Data()" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Data d1 = 1;
//	Data d2 = { 2022, 10, 21 };
//	return 0;
//}

//
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		if (this != &aa)
//		{
//			_a = aa._a;
//		}
//		return *this;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//void f1(A aa)
//{}
//A f2()
//{
//	A aa;
//	return aa;
//}
//int main()
//{
//	A a1 = 1; //A tem(1) + A a1(tem) -> 优化 A a1(1)
//	cout << endl;
//
//	// 传值传参
//	A aa1;
//	f1(aa1);//f1中的临时aa拷贝构造aa1，而且具有常属性const
//	cout << endl;
//
//	// 传值返回
//	f2();//同理，f2中的aa是传值返回，也要拷贝构造一个临时对象返回，也具有常属性const
//	cout << endl;
//
//	// 一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造
//	A ret = f2();
//	//下面这种情况就无法优化了
///*	A ret;
//	ret = f2()*/;
//	cout << endl;
//
//	// 一个表达式中，连续拷贝构造+赋值重载->无法优化
//	aa1 = f2();
//	cout << endl;
//	return 0;
//}
//
//

//int main()
//{
//	int x = 3, y = 4;
//
//	x = (y++, y + 5, y / 5);
//	cout << x<<endl;
//	cout << y << endl;
//	return 0;
//}

//23. 合并K个升序链表
//int cmp_int(const void* e1, const void*e2)
//{
//	return *((int*)e1) - *((int*)e2);
//}
//
//struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
//	if (lists == NULL || listsSize == 0)
//		return NULL;
//	int n = 0;
//	for (int i = 0; i<listsSize; ++i)
//	{
//		struct ListNode*cur = lists[i];
//		while (cur)
//		{
//			n++;
//			cur = cur->next;
//		}
//	}
//	if (n == 0)
//		return NULL;
//	int*a = (int*)malloc(sizeof(int)*n);
//	int j = 0;
//	for (int i = 0; i<listsSize; ++i)
//	{
//		struct ListNode*cur = lists[i];
//		while (cur)
//		{
//			a[j++] = cur->val;
//			cur = cur->next;
//		}
//	}
//	struct ListNode*phead = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode*cur = phead;
//	qsort(a, n, sizeof(int), cmp_int);
//	for (int i = 0; i<n; i++)
//	{
//		struct ListNode*new = (struct ListNode*)malloc(sizeof(struct ListNode));
//		new->val = a[i];
//		new->next = NULL;
//		cur->next = new;
//		cur = cur->next;
//	}
//	return phead->next;
//}
//


//917. 仅仅反转字母
//class Solution {
//public:
//	string reverseOnlyLetters(string s) {
//		int begin = 0, end = s.size();
//		while (begin<end)
//		{
//			while (begin<end && !isalpha(s[begin]))
//				++begin;
//			while (begin<end && !isalpha(s[end]))
//				--end;
//
//			swap(s[begin], s[end]);
//			++begin;
//			--end;
//		}
//		return s;
//	}
//};


//字符串中的第一个唯一字符
//输入: s = "leetcode"
//输出 : 0
//	 示例 2 :
//
// 输入 : s = "loveleetcode"
//  输出 : 2
//class Solution {
//public:
//	int firstUniqChar(string s) {
//		int a[33] = { 0 };
//		for (int i = 0; i<s.size(); ++i)
//		{
//			a[s[i] - 'a']++;
//		}
//		char cout = '1';
//		for (int i = 0; i<s.size(); ++i)
//		{
//			if (a[s[i] - 'a'] == 1)
//			{
//				cout = s[i];
//				break;
//			}
//		}
//		int ret = -1;
//		for (int i = 0; i<s.size(); ++i)
//		{
//			if (s[i] == cout)
//			{
//				ret = i;
//				break;
//			}
//		}
//		return ret;
//	}
//};
//优化
//class Solution {
//public:
//	int firstUniqChar(string s) {
//		int a[256] = { 0 };
//		int size = s.size();
//		for (int i = 0; i<size; ++i)
//		{
//			a[s[i]]++;
//		}
//		for (int i = 0; i<size; ++i)
//		{
//			if (1 == a[s[i]])
//				return i;
//		}
//		return -1;
//	}
//};


/////////////////////////
////415. 字符串相加
//#include <algorithm>
//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//		string ret;
//		ret.reserve(max(num1.size(), num2.size()) + 1);
//		int end1 = num1.size()-1, end2 = num2.size()-1;
//		int carry = 0;
//		while (end1 >= 0 || end2 >= 0)
//		{
//			int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
//			int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
//
//			int sum = val1 + val2 + carry;
//
//			carry = sum / 10;
//			sum %= 10;
//
//			ret += sum + '0';
//			--end1;
//			--end2;
//		}
//		if (carry == 1)
//			ret += '1';
//
//		reverse(ret.begin(), ret.end());
//		return ret;
//	}
//};
//
//
//int main()
//{
//	Solution s;
//	char num1[] = "12";
//	char num2[] = "11";
//	 string s1 = s.addStrings(num1, num2);
//	 for (auto& e : s1)
//	 {
//		 cout << e;
//	 }
//
//	return 0;
//}


//#include <stdio.h>
//#include <iostream>
//using namespace std;
//
//int main() {
//
//	char arr[50000];
//	fgets(arr, sizeof(arr), stdin);
//	string s(arr);
//	int count = 0;
//	for (int i = s.size() - 1; i >= 0; --i)
//	{
//	
//		if (s[i] == ' ')
//		{
//			cout << count << endl;
//			break;
//		}
//		count++;
//	}
//}
////验证回文串
//bool isPalindrome(string s) {
//	for (auto& e : s)
//	{
//		if (isalpha(e) && e >= 'A'&& e <= 'Z')
//		{
//			e = e + 32;
//		}
//	}
//	int begin = 0, end = s.size() - 1;
//	while (begin<end)
//	{
//		while (begin<end && !(isalpha(s[begin]) || isdigit(s[begin])))
//			++begin;
//		while (begin<end && !(isalpha(s[end]) || isdigit(s[end])))
//			--end;
//		if (s[begin] != s[end])
//			return false;
//
//		++begin;
//		--end;
//	}
//	return true;
//
//}
//
//
//void Swap(char&e1, char&e2)
//{
//	char tem = e1;
//	e1 = e2;
//	e2 = tem;
//}
//string reverseStr(string s, int k) {
//	int count = 0, flag = 1;
//	for (int i = 0; i<s.size(); ++i)
//	{
//		count++;
//		if (count == k &&flag == 1)
//		{
//			Swap(s[i - 1], s[i]);
//			flag = 0;
//			count = 0;
//		}
//		else if (count == k)
//		{
//			flag = 1;
//			count = 0;
//		}
//	}
//	return s;
//}
//void Reverse(string& s, int begin, int end)
//{
//	while (begin<end)
//	{
//		char tem = s[begin];
//		s[begin] = s[end];
//		s[end] = tem;
//
//		++begin;
//		--end;
//	}
//}
//string reverseStr(string s, int k) {
//	int n = s.size();
//	for (int i = 0; i<s.size(); i += 2 * k)
//	{
//		if (i + k<n)
//		{
//			reverse(s.begin() + i, s.begin() + i + k);
//			continue;
//		}
//		reverse(s.begin() + i, s.begin()+ n);
//
//	}
//	return s;
//
//}
//
//
//int main()
//{
//	string s("abcdefg");
//	reverseStr(s, 1);
//	return 0;
//}


//206. 反转链表（递归法）
//class Solution {
//public:
//	ListNode* reverseList(ListNode* head) {
//		if (head == NULL || head->next == NULL)
//		{
//			return head;
//		}
//		ListNode*newhead = reverseList(head->next);
//		head->next->next = head;
//		head->next = NULL;
//		return newhead;
//	}
//};

//
//int main()
//{
//	string s("hello");
//	cout << s.size() << endl;
//	return 0;
//}








////977. 有序数组的平方
//class Solution {
//public:
//	vector<int> sortedSquares(vector<int>& nums) {
//		int k = nums.size() - 1;
//		vector<int> result(k + 1, 0);
//		int begin = 0, end = k;
//		while (begin <= end)
//		{
//			if (nums[begin] * nums[begin]>nums[end] * nums[end])
//			{
//				result[k--] = nums[begin] * nums[begin];
//				++begin;
//			}
//			else
//			{
//				result[k--] = nums[end] * nums[end];
//				--end;
//			}
//		}
//		return result;
//	}
//};
//
////209.长度最小的子数组
//class Solution {
//public:
//	int minSubArrayLen(int target, vector<int>& nums) {
//		int n = nums.size();
//		int j = 0, sum = 0, result = INT_MAX;
//		for (int i = 0; i<n; ++i)
//		{
//			sum += nums[i];
//			while (sum >= target)
//			{
//				if (i - j + 1<result)
//					result = i - j + 1;
//				sum -= nums[j];
//				j++;
//			}
//		}
//
//		return result == INT_MAX ? 0 : result;
//	}
//};
//
//
//
//void Reverse(int*a, int begin, int end)
//{
//	while (begin < end)
//	{
//		int tem = a[begin];
//		a[begin] = a[end];
//		a[end] = tem;
//
//		++begin;
//		--end;
//	}
//}
//
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int k;
//	scanf("%d", &k);
//	int n = sizeof(arr) / sizeof(arr[0]);
//	k %= n;
//	Reverse(arr, 0, n - 1);//整体逆置
//	Reverse(arr, 0, n - k - 1);//逆置前n-k个
//	Reverse(arr, n - k, n - 1);//逆置后k个
//
//	for (int i = 0; i < n; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	
//	return 0;
//}


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	if (!root)
		return root;
	if (root == q || root == p)
		return root;

	struct TreeNode*left = lowestCommonAncestor(root->left, p, q);
	struct TreeNode*right = lowestCommonAncestor(root->right, p, q);

	if (left != NULL && right != NULL)
		return root;
	if (left == NULL && right != NULL)
		return right;
	if (left != NULL && right == NULL)
		return left;

	return NULL;
}