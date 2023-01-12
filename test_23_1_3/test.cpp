////155. 最小栈
//class MinStack {
//public:
//	MinStack() {
//
//	}
//
//	void push(int val) {
//		_st.push(val);
//		if (_minst.empty() || val <= _minst.top())
//		{
//			_minst.push(val);
//		}
//	}
//
//	void pop() {
//		if (_st.top() == _minst.top())
//		{
//			_minst.pop();
//		}
//		_st.pop();
//	}
//
//	int top() {
//		return _st.top();
//	}
//
//	int getMin() {
//		return _minst.top();
//	}
//
//	stack<int> _st;
//	stack<int> _minst;
//};
//
//
////栈的压入、弹出序列
//class Solution {
//public:
//	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//		stack<int> st;
//		int popi = 0;
//		for (auto e : pushV)
//		{
//			st.push(e);
//			while (!st.empty() && st.top() == popV[popi])
//			{
//				st.pop();
//				++popi;
//			}
//		}
//		return st.empty();
//	}
//};
//
////逆波兰表达式求值
//class Solution {
//public:
//	int evalRPN(vector<string>& tokens) {
//		stack<int> st;
//		for (auto e : tokens)
//		{
//			if (e == "+" || e == "-" || e == "/" || e == "*")
//			{
//				int right = st.top();
//				st.pop();
//				int left = st.top();
//				st.pop();
//				switch (e[0])
//				{
//				case '+':
//					st.push(left + right);
//					break;
//				case '-':
//					st.push(left - right);
//					break;
//				case 1:
//					st.push(left*right);
//					break;
//				case '/':
//					st.push(left / right);
//					break;
//				}
//			}
//			else
//			{
//				st.push(stoi(e));
//			}
//		}
//		return st.top();
//	}
//};

//#include <iostream>
//
//#include "stack.h"
//#include "queue.h"
//using namespace std;


//int main()
//{
//	hdm::stack<int,list<int>> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl;
//	return 0;
//}


//int main()
//{
//	hdm::queue<int, list<int>> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}
//	cout << endl;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//void printVector(vector<int>& v) {
//
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//int main() {
//
//	vector<int> v1; //无参构造
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	printVector(v1);
//
//	vector<int> v2(v1.begin(), v1.end());//使用迭代器进行初始化构造
//	printVector(v2);
//
//	vector<int> v3(10, 100); //构造并初始化10个100
//	printVector(v3);
//
//	vector<int> v4(v3);//拷贝构造
//	printVector(v4);
//	return 0;
//}

//int main()
//{
//	vector<int> v(10, 1);//构造10个1
//	std::vector<int>::iterator it = v.begin();//获取v的开始的迭代器，类型是std::vector<int>::iterator
//	//auto it1 = v.begin();//类型太长，可以使用auto
//	std::vector<int>::iterator end = v.end();//获取v的结尾的迭代器
//	while (it != end)
//	{
//		cout << *it << " "; //*解引用之后，就可以拿到数据，跟指针*p的操作一样
//		++it;//让迭代器往后移一位，跟指针的++p类似
//	}
//	cout << endl;
//	return 0;
//}



//#include <vector>
//void printVector(vector<int>& v) {
//
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//int main() {
//	//插入和删除
//	vector<int> v1;
//	//尾插
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//	v1.push_back(50);
//	printVector(v1);
//	//尾删
//	v1.pop_back();
//	printVector(v1);
//	//插入
//	v1.insert(v1.begin(), 100);
//	printVector(v1);
//
//	v1.insert(v1.begin(), 2, 1000);
//	printVector(v1);
//
//	//删除
//	v1.erase(v1.begin());
//	printVector(v1);
//
//	//清空
//	v1.erase(v1.begin(), v1.end());
//	v1.clear();
//	printVector(v1);
//	return 0;
//}


//int main()
//{
//	vector<int>v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//
//	for (int i = 0; i < v1.size(); i++)
//	{
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//
//	for (int i = 0; i < v1.size(); i++)
//	{
//		cout << v1.at(i) << " ";
//	}
//	cout << endl;
//
//	cout << "v1的第一个元素为： " << v1.front() << endl;
//	cout << "v1的最后一个元素为： " << v1.back() << endl;
//	return 0;
//}
//
//#include <vector>
//
//void printVector(vector<int>& v) {
//
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	vector<int> v1; //无参构造
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	printVector(v1);
//
//	vector<int>v2;
//	v2 = v1;//赋值重载
//	printVector(v2);
//	vector<int>v3;
//	v3.assign(v1.begin(), v1.end());
//	printVector(v3);
//
//	vector<int>v4;
//	v4.assign(10, 100);
//	printVector(v4);
//	return 0;
//}
//
//
//



//
//#include <iostream>
//using namespace std;
//#include <vector>
//int main()
//{
//	vector<int> v{ 1, 2, 3, 4, 5, 6 };
//	auto it = v.begin();
//	// 将有效元素个数增加到100个，多出的位置使用8填充，操作期间底层会扩容
//	// v.resize(100, 8);
//	// reserve的作用就是改变扩容大小但不改变有效元素个数，操作期间可能会引起底层容量改变
//	// v.reserve(100);
//	// 插入元素期间，可能会引起扩容，而导致原空间被释放
//	// v.insert(v.begin(), 0);
//	// v.push_back(8);
//	// 给vector重新赋值，可能会引起底层容量改变
//	v.assign(100, 8);
//	/*
//	出错原因：以上操作，都有可能会导致vector扩容，也就是说vector底层原理旧空间被释放掉，
//	而在打印时，it还使用的是释放之间的旧空间，在对it迭代器操作时，实际操作的是一块已经被释放的
//	空间，而引起代码运行时崩溃。
//	解决方式：在以上操作完成之后，如果想要继续通过迭代器操作vector中的元素，只需给it重新
//	赋值即可。
//	*/
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}
//


//
//#include <iostream>
//using namespace std;
//#include <vector>
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	// 使用find查找3所在位置的iterator
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	// 删除pos位置的数据，导致pos迭代器失效。
//	v.erase(pos);
//	cout << *pos << endl; // 此处会导致非法访问
//	return 0;
//}
//

//// 测试vector的默认扩容机制
//void TestVectorExpand()
//{
//	size_t sz;
//	vector<int> v;
//	sz = v.capacity();
//	cout << "making v grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		v.push_back(i);
//		if (sz != v.capacity())
//		{
//			sz = v.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//vs：运行结果：vs下使用的STL基本是按照1.5倍方式扩容
//making foo grow :
//capacity changed : 1
//capacity changed : 2
//capacity changed : 3
//capacity changed : 4
//capacity changed : 6
//capacity changed : 9
//capacity changed : 13
//capacity changed : 19
//capacity changed : 28
//capacity changed : 42
//capacity changed : 63
//capacity changed : 94
//capacity changed : 141
//
//g++运行结果：linux下使用的STL基本是按照2倍方式扩容
//making foo grow :
//capacity changed : 1
//capacity changed : 2
//capacity changed : 4
//capacity changed : 8
//capacity changed : 16
//capacity changed : 32
//capacity changed : 64
//capacity changed : 128


// 如果已经确定vector中要存储元素大概个数，可以提前将空间设置足够
// 就可以避免边插入边扩容导致效率低下的问题了
//void TestVectorExpandOP()
//{
//	vector<int> v;
//	size_t sz = v.capacity();
//	v.reserve(100); // 提前将容量设置好，可以避免一遍插入一遍扩容
//	cout << "making bar grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		v.push_back(i);
//		if (sz != v.capacity())
//		{
//			sz = v.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}


//#include "vector.h"
//int main()
//{
//	hdm::TestVector2();
//	return 0;
//}

#include <iostream>
using namespace std;
#include <list>
#include <vector>
// list的构造
void TestList1()
{
	list<int> l1;                         // 构造空的l1
	list<int> l2(4, 100);                 // l2中放4个值为100的元素
	list<int> l3(l2.begin(), l2.end());  // 用l2的[begin(), end()）左闭右开的区间构造l3
	list<int> l4(l3);                    // 用l3拷贝构造l4

	// 以数组为迭代器区间构造l5
	int array[] = { 16, 2, 77, 29 };
	list<int> l5(array, array + sizeof(array) / sizeof(int));

	// 列表格式初始化C++11
	list<int> l6{ 1, 2, 3, 4, 5 };

	// 用迭代器方式打印l5中的元素
	list<int>::iterator it = l5.begin();
	while (it != l5.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// C++11范围for的方式遍历
	for (auto& e : l5)
		cout << e << " ";

	cout << endl;
}

// list迭代器的使用
// 注意：遍历链表只能用迭代器和范围for
void PrintList(const list<int>& l)
{
	// 注意这里调用的是list的 begin() const，返回list的const_iterator对象
	for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";
		// *it = 10; 编译不通过
	}

	cout << endl;
}

void TestList2()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	// 使用正向迭代器正向list中的元素
	// list<int>::iterator it = l.begin();   // C++98中语法
	auto it = l.begin();                     // C++11之后推荐写法
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 使用反向迭代器逆向打印list中的元素
	// list<int>::reverse_iterator rit = l.rbegin();
	auto rit = l.rbegin();
	while (rit != l.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}
//赋值和交换
void TestList3()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	PrintList(L1);

	//赋值
	list<int>L2;
	L2 = L1;
	PrintList(L2);

	list<int>L3;
	L3.assign(L2.begin(), L2.end());
	PrintList(L3);

	list<int>L4;
	L4.assign(10, 100);
	PrintList(L4);

}

//交换
void TestList4()
{

	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	list<int>L2;
	L2.assign(10, 100);

	cout << "交换前： " << endl;
	PrintList(L1);
	PrintList(L2);

	cout << endl;

	L1.swap(L2);

	cout << "交换后： " << endl;
	PrintList(L1);
	PrintList(L2);

}

// list插入和删除
// push_back/pop_back/push_front/pop_front
void TestList5()
{
	int array[] = { 1, 2, 3 };
	list<int> L(array, array + sizeof(array) / sizeof(array[0]));

	// 在list的尾部插入4，头部插入0
	L.push_back(4);
	L.push_front(0);
	PrintList(L);

	// 删除list尾部节点和头部节点
	L.pop_back();
	L.pop_front();
	PrintList(L);
}

// insert /erase 
void TestList6()
{
	int array1[] = { 1, 2, 3 };
	list<int> L(array1, array1 + sizeof(array1) / sizeof(array1[0]));

	// 获取链表中第二个节点
	auto pos = ++L.begin();
	cout << *pos << endl;

	// 在pos前插入值为4的元素
	L.insert(pos, 4);
	PrintList(L);

	// 在pos前插入5个值为5的元素
	L.insert(pos, 5, 5);
	PrintList(L);

	// 在pos前插入[v.begin(), v.end)区间中的元素
	vector<int> v{ 7, 8, 9 };
	L.insert(pos, v.begin(), v.end());
	PrintList(L);

	// 删除pos位置上的元素
	L.erase(pos);
	PrintList(L);

	// 删除list中[begin, end)区间中的元素，即删除list中的所有元素
	L.erase(L.begin(), L.end());
	PrintList(L);
}

// resize/swap/clear
void TestList7()
{
	// 用数组来构造list
	int array1[] = { 1, 2, 3 };
	list<int> l1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
	PrintList(l1);

	// 交换l1和l2中的元素
	list<int> l2;
	l1.swap(l2);
	PrintList(l1);
	PrintList(l2);

	// 将l2中的元素清空
	l2.clear();
	cout << l2.size() << endl;
}

//大小操作
void TestList8()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	if (L1.empty())
	{
		cout << "L1为空" << endl;
	}
	else
	{
		cout << "L1不为空" << endl;
		cout << "L1的大小为： " << L1.size() << endl;
	}

	//重新指定大小
	L1.resize(10);
	PrintList(L1);

	L1.resize(2);
	PrintList(L1);
}
//数据存取
void TestList9()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);


	//cout << L1.at(0) << endl;//错误 不支持at访问数据
	//cout << L1[0] << endl; //错误  不支持[]方式访问数据
	cout << "第一个元素为： " << L1.front() << endl;
	cout << "最后一个元素为： " << L1.back() << endl;

	//list容器的迭代器是双向迭代器，不支持随机访问
	list<int>::iterator it = L1.begin();
	//it = it + 1;//错误，不可以跳跃访问，即使是+1
}
//#include "list_stl.h"
//int main()
//{
//	hdm::TesthdmList4();
//	return 0;
//}

//43. 字符串相乘
class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1[0] == '0' || num2[0] == '0')
		{
			return "0";
		}
		int len1 = num1.size();
		int len2 = num2.size();
		vector<int> ansArr;
		ansArr.resize(len1 + len2);
		//用num1每一位去乘num2的每一位，保存到新数组的i+j+1的位置上，不用进位这么快
		for (int i = len1 - 1; i >= 0; --i)
		{
			int x1 = num1[i] - '0';
			for (int j = len2 - 1; j >= 0; --j)
			{
				int x2 = num2[j] - '0';
				ansArr[i + j + 1] += x1*x2;
			}
		}
		//开始计算进位
		for (int i = len1 + len2 - 1; i>0; --i)
		{
			ansArr[i - 1] += ansArr[i] / 10;
			ansArr[i] %= 10;
		}
		string ret;
		//看它最高位是否是零，是就从1开始算
		int index = ansArr[0] == 0 ? 1 : 0;
		//转成字符串
		while (index<len1 + len2)
		{
			ret += ansArr[index++] + '0';
		}
		return ret;

	}
};



//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	string str[n];
//	for (int i = 0; i<n; ++i)
//	{
//		cin >> str[i];
//	}
//	int flag1, flag2;
//	flag1 = flag2 = 1;
//	for (int i = 0; i<n - 1; ++i)
//	{
//		if (str[i]>str[i + 1])
//		{
//			flag1 = 0;
//			break;
//		}
//	}
//	for (int i = 0; i<n - 1; ++i)
//	{
//		if (str[i].size()>str[i + 1].size())
//		{
//			flag2 = 0;
//			break;
//		}
//	}
//	if (flag1 == 1 && flag2 == 1)
//	{
//		cout << "both" << endl;
//	}
//	else if (flag1 == 1)
//	{
//		cout << "lexicographically" << endl;
//	}
//	else if (flag2 == 1)
//	{
//		cout << "lengths" << endl;
//	}
//	else
//	{
//		cout << "none" << endl;
//	}
//
//	return 0;
//}
//
//



//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	while (a % b)
//	{
//		int c = a%b;
//		a = b;
//		b = c;
//	}
//	cout << b << endl;
//	return 0;
//}
//
//
//
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include "priority_queue.h"

//using namespace std;
//int main()
//{
//	//priority_queue<int,vector<int>,less<int>> pq;
//
//	/*priority_queue<int, vector<int>, greater<int>> pq;*/
//	hdm::priority_queue<int,vector<int>,hdm::greater<int>> pq;
//
//	pq.push(1);
//	pq.push(3);
//	pq.push(2);
//	pq.push(4);
//	pq.push(5);
//	pq.push(6);
//
//
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;
//
//	return 0;
//}

class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
		while (B != 0)
		{
			int carry = (A&B) << 1;//存放进位
			A ^= B;//异或得到不是进位的和
			B = carry;//进位给B继续
		}
		return A;
	}
};

//int count = 0;
//
//void getGo(int n, int m)
//{
//	if (n == 0 && m == 0)
//	{
//		::count++;
//		return;
//	}
//	if (n != 0)
//	{
//		getGo(n - 1, m);
//	}
//	if (m != 0)
//	{
//		getGo(n, m - 1);
//	}
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	getGo(n, m);
//	cout << ::count << endl;
//	return 0;
//}
//
//int main()
//{
//	const int a = 10;
//	int *p = (int*)(&a);
//	*p = 20;
//	cout << *p << endl;
//	cout << a << endl;
//	return 0;
//}



//密码强度等级
#include <iostream>
#include <string>
using namespace std;
//判断是否是合法符号
bool issymbol(int c)
{
	if ((c >= 0x21 && c < 0x2F) || (c >= 0x3A && c <= 0x40) || (c >= 0x5B && c <= 0x60) || (c >= 0x7B && c <= 0x7E))
	{
		return true;
	}
	return false;
}

int main()
{
	string passwd;
	cin >> passwd;
	int score = 0;
	//计算密码长度得分
	if (passwd.size() >= 8)
	{
		score += 25;
	}
	else if (passwd.size() >= 5)
	{
		score += 10;
	}
	else
	{
		score += 5;
	}
	//判断是否有大小写
	int isupperflag = 0, islowerflag = 0, isalphaflag = 0;
	int isdigitflag = 0;//判断数字有多少个
	int issymbolflag = 0;//判断符号有多少个
	for (auto e : passwd)
	{
		if (isupper(e))
		{
			isupperflag = 1;
			isalphaflag = 1;
		}
		else if (islower(e))
		{
			islowerflag = 1;
			isalphaflag = 1;
		}
		if (isdigit(e))
		{
			isdigitflag++;
		}
		if (issymbol(e))
		{
			issymbolflag++;
		}

	}
	//大小写都有
	if (islowerflag == 1 && isupperflag == 1)
	{
		score += 20;
	}//大小写占一个
	else if (islowerflag == 1 || isupperflag == 1)
	{
		score += 10;
	}
	//判断数字得分
	if (isdigitflag > 0)
	{
		if (isdigitflag > 1)
		{
			score += 20;
		}
		else
		{
			score += 10;
		}
	}
	//判断符号得分
	if (issymbolflag > 0)
	{
		if (issymbolflag > 1)
		{
			score += 25;
		}
		else
		{
			score += 10;
		}
	}
	//判断奖励得分
	if ((isupperflag == 1 && islowerflag == 1) && isdigitflag >= 1 && issymbolflag >= 1)
	{
		score += 5;
	}
	else if (isalphaflag == 1 && isdigitflag > 0 && issymbolflag > 0)
	{
		score += 3;
	}
	else if (isalphaflag == 1 && isdigitflag > 0)
	{
		score += 2;
	}
	//最终评分
	if (score >= 90)
	{
		cout << "VERY_SECURE" << endl;
	}
	else if (score >= 80)
	{
		cout << "SECURE" << endl;
	}
	else if (score >= 70)
	{
		cout << "VERY_STRONG" << endl;
	}
	else if (score >= 60)
	{
		cout << "STRONG" << endl;
	}
	else if (score >= 50)
	{
		cout << "AVERAGE" << endl;
	}
	else if (score >= 25)
	{
		cout << "WEAK" << endl;
	}
	else
	{
		cout << "VERY_WEAK" << endl;
	}

	return 0;
}
