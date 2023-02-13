#include <iostream>
#include <string>
#include <vector>
using namespace std;

//class Person
//{
//public:
//	Person()
//	{}
//	Person(string name,int age)
//		:_name(name), _age(age)
//	{}
//	void Print()
//	{
//		cout << _name << " " << _age << endl;
//	}
//protected:
//	string _name;
//private:
//	int _age;
//};
//
//class Student :public Person
//{
//public:
//	Student(string name,int age,int num=0)
//		:Person(name, age), _num(num)
//	{}
//
//protected:
//	int _num;
//};
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

//螺旋矩阵II
class Solution1 {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int> > vv(n, vector<int>(n, 0));
		int startx = 0, starty = 0;
		int mid = n / 2;
		int i = 0, j = 0;
		int offset = 1;
		int count = 1;
		while (mid--)
		{
			for (j = starty; j<n - offset; ++j)
			{
				vv[startx][j] = count++;
			}
			for (i = startx; i<n - offset; ++i)
			{
				vv[i][j] = count++;
			}
			for (j; j>starty; --j)
			{
				vv[i][j] = count++;
			}
			for (i; i>startx; --i)
			{
				vv[i][j] = count++;
			}
			offset++;
			startx++;
			starty++;
		}
		if (n % 2 == 1)
		{
			vv[n / 2][n / 2] = count++;
		}
		return vv;
	}
};

//int main()
//{
//	//hdm::priority_queue<int,vector<int>,hdm::greater<int>> q1;
//	//q1.push(2);
//	//q1.push(3);
//	//q1.push(1);
//	//q1.push(4);
//	//q1.push(10);
//
//	//while (!q1.empty())
//	//{
//	//	cout << q1.top() << " ";
//	//	q1.pop();
//	//}
//	//cout << endl;
//	auto vv=Solution1().generateMatrix(6);
//	for (int i = 0; i < vv.size(); ++i)
//	{
//		for (int j = 0; j < vv[i].size(); ++j)
//		{
//			cout << vv[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	return 0;
//}

//
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "Person--买票-全价" << endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "Student--买票-半价" << endl;
//	}
//};
//
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//
//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);
//	Func(st);
//	return 0;
//}

//
//#include "BSTress.h"
//
//int main()
//{
//	BSTress<int> t;
//	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	for (auto e : a)
//	{
//		t.insert(e);
//	}
//	t.InOrder();
//	cout << endl;
//	//auto f = t.Find(13);
//	//if (f != nullptr)
//	//{
//	//	cout << f->_val << endl;
//	//}
//	BSTress<int> t1(t);
//	t1.InOrder();
//	cout << endl;
//	BSTress<int> t2;
//	t2 = t1;
//	t2.InOrder();
//	cout << endl;
//
//	for (auto e : a)
//	{
//		t.eraseR(e);
//		t.InOrder();
//		cout << endl;
//	}
//	//t.erase(8);
//	//t.InOrder();
//	//cout << endl;
//
//	//t.erase(14);
//	//t.InOrder();
//	//cout << endl;
//	return 0;
//}


//class A
//{
//public:
//	int _a;
//};
//// class B : public A
//class B :  virtual public A
//{
//public:
//	int _b;
//};
//// class C : public A
//class C : virtual public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	d._a = 6;
//	cout << sizeof(D) << endl;
//	return 0;
//}

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//	int _age = 18; // 年龄
//};
//// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了
////Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可
////以看到变量的复用。调用Print可以看到成员函数的复用。
//class Student : public Person
//{
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};


//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//void Test()
//{
//	Student sobj;
//	// 1.子类对象可以赋值给父类对象/指针/引用
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	//2.基类对象不能赋值给派生类对象
//	sobj = pobj;
//	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
//	pp = &sobj;
//	Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
//	ps1->_No = 10;
//	pp = &pobj;
//	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
//	ps2->_No = 10;
//}



// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//void Test()
//{
//	Student s1;
//	s1.Print();
//};
// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	b.fun(10);
//	return 0;
//}


//class Person
//{
//public:
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//public:
//	Student(const char* name, int num)
//		: Person(name)//派生类要显示调用基类构造函数
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//	Student(const Student& s)
//		: Person(s)
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//	Student& operator = (const Student& s)
//	{
//		cout << "Student& operator= (const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator =(s);//显示调用基类赋值重载
//			_num = s._num;
//		}
//		return *this;
//	}
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num; //学号
//};
//int main()
//{
//	Student s1("jack", 18);
//	Student s2(s1);
//	Student s3("rose", 17);
//	s1 = s3;
//	return 0;
//}


//
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;//运行错误，友元关系不能继承
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}


//class Base {
//public:
//	static void func()
//	{
//		cout << "Base - static void func()" << endl;
//	}
//	static void func(int a)
//	{
//		cout << "Base - static void func(int a)" << endl;
//	}
//
//	static int m_A;
//};
//
//int Base::m_A = 100;
//
//class Son : public Base {
//public:
//	static void func()
//	{
//		cout << "Son - static void func()" << endl;
//	}
//	static int m_A;
//};
//
//int Son::m_A = 200;
//
////同名成员属性
//void test01()
//{
//	//通过对象访问
//	cout << "通过对象访问： " << endl;
//	Son s;
//	cout << "Son  下 m_A = " << s.m_A << endl;
//	cout << "Base 下 m_A = " << s.Base::m_A << endl;
//
//	//通过类名访问
//	cout << "通过类名访问： " << endl;
//	cout << "Son  下 m_A = " << Son::m_A << endl;
//	cout << "Base 下 m_A = " << Son::Base::m_A << endl;
//}
//
////同名成员函数
//void test02()
//{
//	//通过对象访问
//	cout << "通过对象访问： " << endl;
//	Son s;
//	s.func();
//	s.Base::func();
//
//	cout << "通过类名访问： " << endl;
//	Son::func();
//	Son::Base::func();
//	//出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作作用域访问
//	Son::Base::func(100);
//}
//int main() {
//
//	test01();
//	test02();
//	return 0;
//}


//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void Test()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	a._name = "peter";
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}


//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void Test()
//{
//	Assistant a;
//	a._name = "peter";
//}

//
//
//class A
//{
//public:
//	int _a;
//};
////class B : public A
//class B : virtual public A
//{
//public:
//	int _b;
//};
////class C : public A
//class C : virtual public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	d._a = 6;
//	return 0;
//}
//
//
////根据二叉树创建字符串
//class Solution {
//public:
//	string tree2str(TreeNode* root) {
//		if (root == nullptr)
//			return string();
//		string str;
//		str += to_string(root->val);
//		if (root->left)
//		{
//			str += "(";
//			str += tree2str(root->left);
//			str += ")";
//		}
//		else if (root->right)
//		{
//			str += "()";
//		}
//		if (root->right)
//		{
//			str += "(";
//			str += tree2str(root->right);
//			str += ")";
//		}
//
//		return str;
//	}
//};


//二叉树的层序遍历
//class Solution {
//public:
//	vector<vector<int>> levelOrder(TreeNode* root) {
//		queue<TreeNode*> q;
//		vector<vector<int> >vv;
//		int leaveSize = 0;
//		if (root)
//		{
//			q.push(root);
//			leaveSize = 1;
//		}
//		while (!q.empty())
//		{
//			vector<int> v;
//			while (leaveSize--)
//			{
//				TreeNode* cur = q.front();
//				q.pop();
//				v.push_back(cur->val);
//				if (cur->left)
//					q.push(cur->left);
//				if (cur->right)
//					q.push(cur->right);
//			}
//			vv.push_back(v);
//			leaveSize = q.size();
//		}
//		return vv;
//	}
//};


////二叉树的最近公共祖先
////方法一：
//class Solution {
//public:
//	bool findTress(TreeNode* root, TreeNode*x)
//	{
//		if (root == nullptr)
//			return false;
//		return root == x || findTress(root->left, x)
//			|| findTress(root->right, x);
//	}
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//		if (!root)
//			return root;
//		if (root == p || root == q)
//			return root;
//
//		bool pInleft = findTress(root->left, p);
//		bool pInright = !pInleft;
//		bool qInleft = findTress(root->left, q);
//		bool qInright = !qInleft;
//
//		if (qInleft &&pInleft)
//			return lowestCommonAncestor(root->left, p, q);
//		else if (qInright&& pInright)
//			return lowestCommonAncestor(root->right, p, q);
//		else
//			return root;
//	}
//};
//
////方法二：
//class Solution {
//public:
//	bool findPah(TreeNode* root, TreeNode* x, stack<TreeNode*>& st)
//	{
//		if (root == nullptr)
//			return false;
//		st.push(root);
//		if (root == x)
//			return true;
//		if (findPah(root->left, x, st))
//			return true;
//		if (findPah(root->right, x, st))
//			return true;
//		st.pop();
//		return false;
//	}
//
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//		if (root == nullptr)
//			return root;
//		stack<TreeNode*> p_st;
//		stack<TreeNode*> q_st;
//		//找p的路径
//		findPah(root, p, p_st);
//		//栈q的路径
//		findPah(root, q, q_st);
//		while (q_st.size() != p_st.size())
//		{
//			if (q_st.size()>p_st.size())
//			{
//				q_st.pop();
//			}
//			else
//			{
//				p_st.pop();
//			}
//		}
//
//		while (q_st.top() != p_st.top())
//		{
//			q_st.pop();
//			p_st.pop();
//		}
//		return q_st.top();
//	}
//};
//
////三
//class Solution {
//public:
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//		if (root == nullptr)
//			return root;
//		if (root == q || root == p)
//			return root;
//
//		TreeNode* leftleave = lowestCommonAncestor(root->left, p, q);
//		TreeNode* rightleave = lowestCommonAncestor(root->right, p, q);
//
//		if (leftleave && rightleave)
//			return root;
//		if (leftleave == nullptr && rightleave)
//			return rightleave;
//		if (rightleave == nullptr && leftleave)
//			return leftleave;
//		return nullptr;
//	}
//};

//class A
//{
//public:
//	virtual void test(int a) = 0;
//};
//
//int main()
//{
//	//A a;
//	A fun(int);
//	return 0;
//}


//二叉搜索树与双向链表
//class Solution {
//public:
//	void _Convert(TreeNode* root, TreeNode* &prev)
//	{
//		if (root == nullptr)
//			return;
//
//		_Convert(root->left, prev);
//		root->left = prev;
//		if (prev != nullptr)
//		{
//			prev->right = root;
//		}
//		prev = root;
//		_Convert(root->right, prev);
//	}
//	TreeNode* Convert(TreeNode* pRootOfTree) {
//		if (pRootOfTree == nullptr)
//			return nullptr;
//		TreeNode* cur = pRootOfTree;
//		while (cur->left)
//		{
//			cur = cur->left;
//		}
//		TreeNode* prev = nullptr;
//		_Convert(pRootOfTree, prev);
//		return cur;
//	}
//};

//从前序与中序遍历序列构造二叉树
//class Solution {
//public:
//	TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int &previ, int inbegin, int inend)
//	{
//		if (inbegin>inend)
//			return nullptr;
//		TreeNode* newNode = new TreeNode(preorder[previ]);
//		int rooti = inbegin;
//		while (preorder[previ] != inorder[rooti])
//		{
//			++rooti;
//		}
//		previ++;
//		//[inbegin ,rooti-1]rooti[rooti+1,inend]
//		newNode->left = _buildTree(preorder, inorder, previ, inbegin, rooti - 1);
//		newNode->right = _buildTree(preorder, inorder, previ, rooti + 1, inend);
//		return newNode;
//	}
//	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//		int previ = 0;
//		return _buildTree(preorder, inorder, previ, 0, inorder.size() - 1);
//	}
//};
//#include <vector>
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//	
//};
//
//
//
//class Solution {
//public:
//	TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int &posti, int inbegin, int inend)
//	{
//		if (inbegin>inend)
//			return nullptr;
//		TreeNode* newNode = new TreeNode(preorder[posti]);
//		int rooti = inbegin;
//		while (preorder[previ] != inorder[rooti])
//		{
//			++rooti;
//		}
//		posti--;
//		//[inbegin ,rooti-1]rooti[rooti+1,inend]
//		newNode->right = _buildTree(preorder, inorder, posti, rooti + 1, inend);
//		newNode->left = _buildTree(preorder, inorder, posti, inbegin, rooti - 1);
//		return newNode;
//	}
//	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//		int posti = postorder.size() - 1;
//		return _buildTree(postorder, inorder, posti, 0, inorder.size() - 1);
//	}
//};

//#include <map>
//#include <string>
//int main()
//{
//	// 统计水果出现的次数
//	string arr[] = { "苹果", "西瓜", "香蕉", "草莓", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };;
//	map<string, int> m;
//	for (auto& e : arr)
//	{
//		m[e]++;
//	}
//	for (const auto& kv : m)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//	return 0;
//}
#include "AVLTree.h"

int main()
{
	TestAVLTree();
	return 0;
}






////二叉树的前序遍历  非递归
//class Solution {
//public:
//	vector<int> preorderTraversal(TreeNode* root) {
//		stack<TreeNode*> st;
//		vector<int> v;
//		TreeNode* cur = root;
//		while (cur || !st.empty())
//		{
//			while (cur)
//			{
//				st.push(cur);
//				v.push_back(cur->val);
//				cur = cur->left;
//			}
//
//			TreeNode* tmp = st.top();
//			st.pop();
//			cur = tmp->right;
//		}
//
//		return v;
//	}
//};
//
//
////二叉树的中序遍历  -- 非递归
//class Solution {
//public:
//	vector<int> inorderTraversal(TreeNode* root) {
//		stack<TreeNode*> st;
//		vector<int> v;
//		TreeNode* cur = root;
//		while (cur || !st.empty())
//		{
//			while (cur)
//			{
//				st.push(cur);
//				cur = cur->left;
//			}
//
//			TreeNode* tmp = st.top();
//			v.push_back(tmp->val);
//			st.pop();
//			cur = tmp->right;
//
//		}
//		return v;
//	}
//};
//
//
//
////二叉树的后序遍历  --非递归
//class Solution {
//public:
//	vector<int> postorderTraversal(TreeNode* root) {
//		stack<TreeNode*> st;
//		vector<int> v;
//		TreeNode* cur = root;
//		TreeNode* prev = nullptr;
//		while (cur || !st.empty())
//		{
//			while (cur)
//			{
//				st.push(cur);
//				cur = cur->left;
//			}
//
//			TreeNode* tmp = st.top();
//			if (tmp->right == nullptr || tmp->right == prev)
//			{
//				v.push_back(tmp->val);
//				st.pop();
//				prev = tmp;
//			}
//			else
//			{
//				cur = tmp->right;
//			}
//		}
//		return v;
//	}
//};