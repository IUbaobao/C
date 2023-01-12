////155. ��Сջ
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
////ջ��ѹ�롢��������
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
////�沨�����ʽ��ֵ
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
//	vector<int> v1; //�޲ι���
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	printVector(v1);
//
//	vector<int> v2(v1.begin(), v1.end());//ʹ�õ��������г�ʼ������
//	printVector(v2);
//
//	vector<int> v3(10, 100); //���첢��ʼ��10��100
//	printVector(v3);
//
//	vector<int> v4(v3);//��������
//	printVector(v4);
//	return 0;
//}

//int main()
//{
//	vector<int> v(10, 1);//����10��1
//	std::vector<int>::iterator it = v.begin();//��ȡv�Ŀ�ʼ�ĵ�������������std::vector<int>::iterator
//	//auto it1 = v.begin();//����̫��������ʹ��auto
//	std::vector<int>::iterator end = v.end();//��ȡv�Ľ�β�ĵ�����
//	while (it != end)
//	{
//		cout << *it << " "; //*������֮�󣬾Ϳ����õ����ݣ���ָ��*p�Ĳ���һ��
//		++it;//�õ�����������һλ����ָ���++p����
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
//	//�����ɾ��
//	vector<int> v1;
//	//β��
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//	v1.push_back(50);
//	printVector(v1);
//	//βɾ
//	v1.pop_back();
//	printVector(v1);
//	//����
//	v1.insert(v1.begin(), 100);
//	printVector(v1);
//
//	v1.insert(v1.begin(), 2, 1000);
//	printVector(v1);
//
//	//ɾ��
//	v1.erase(v1.begin());
//	printVector(v1);
//
//	//���
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
//	cout << "v1�ĵ�һ��Ԫ��Ϊ�� " << v1.front() << endl;
//	cout << "v1�����һ��Ԫ��Ϊ�� " << v1.back() << endl;
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
//	vector<int> v1; //�޲ι���
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	printVector(v1);
//
//	vector<int>v2;
//	v2 = v1;//��ֵ����
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
//	// ����ЧԪ�ظ������ӵ�100���������λ��ʹ��8��䣬�����ڼ�ײ������
//	// v.resize(100, 8);
//	// reserve�����þ��Ǹı����ݴ�С�����ı���ЧԪ�ظ����������ڼ���ܻ�����ײ������ı�
//	// v.reserve(100);
//	// ����Ԫ���ڼ䣬���ܻ��������ݣ�������ԭ�ռ䱻�ͷ�
//	// v.insert(v.begin(), 0);
//	// v.push_back(8);
//	// ��vector���¸�ֵ�����ܻ�����ײ������ı�
//	v.assign(100, 8);
//	/*
//	����ԭ�����ϲ��������п��ܻᵼ��vector���ݣ�Ҳ����˵vector�ײ�ԭ��ɿռ䱻�ͷŵ���
//	���ڴ�ӡʱ��it��ʹ�õ����ͷ�֮��ľɿռ䣬�ڶ�it����������ʱ��ʵ�ʲ�������һ���Ѿ����ͷŵ�
//	�ռ䣬�������������ʱ������
//	�����ʽ�������ϲ������֮�������Ҫ����ͨ������������vector�е�Ԫ�أ�ֻ���it����
//	��ֵ���ɡ�
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
//	// ʹ��find����3����λ�õ�iterator
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	// ɾ��posλ�õ����ݣ�����pos������ʧЧ��
//	v.erase(pos);
//	cout << *pos << endl; // �˴��ᵼ�·Ƿ�����
//	return 0;
//}
//

//// ����vector��Ĭ�����ݻ���
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
//vs�����н����vs��ʹ�õ�STL�����ǰ���1.5����ʽ����
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
//g++���н����linux��ʹ�õ�STL�����ǰ���2����ʽ����
//making foo grow :
//capacity changed : 1
//capacity changed : 2
//capacity changed : 4
//capacity changed : 8
//capacity changed : 16
//capacity changed : 32
//capacity changed : 64
//capacity changed : 128


// ����Ѿ�ȷ��vector��Ҫ�洢Ԫ�ش�Ÿ�����������ǰ���ռ������㹻
// �Ϳ��Ա���߲�������ݵ���Ч�ʵ��µ�������
//void TestVectorExpandOP()
//{
//	vector<int> v;
//	size_t sz = v.capacity();
//	v.reserve(100); // ��ǰ���������úã����Ա���һ�����һ������
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
// list�Ĺ���
void TestList1()
{
	list<int> l1;                         // ����յ�l1
	list<int> l2(4, 100);                 // l2�з�4��ֵΪ100��Ԫ��
	list<int> l3(l2.begin(), l2.end());  // ��l2��[begin(), end()������ҿ������乹��l3
	list<int> l4(l3);                    // ��l3��������l4

	// ������Ϊ���������乹��l5
	int array[] = { 16, 2, 77, 29 };
	list<int> l5(array, array + sizeof(array) / sizeof(int));

	// �б��ʽ��ʼ��C++11
	list<int> l6{ 1, 2, 3, 4, 5 };

	// �õ�������ʽ��ӡl5�е�Ԫ��
	list<int>::iterator it = l5.begin();
	while (it != l5.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// C++11��Χfor�ķ�ʽ����
	for (auto& e : l5)
		cout << e << " ";

	cout << endl;
}

// list��������ʹ��
// ע�⣺��������ֻ���õ������ͷ�Χfor
void PrintList(const list<int>& l)
{
	// ע��������õ���list�� begin() const������list��const_iterator����
	for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";
		// *it = 10; ���벻ͨ��
	}

	cout << endl;
}

void TestList2()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	// ʹ���������������list�е�Ԫ��
	// list<int>::iterator it = l.begin();   // C++98���﷨
	auto it = l.begin();                     // C++11֮���Ƽ�д��
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// ʹ�÷�������������ӡlist�е�Ԫ��
	// list<int>::reverse_iterator rit = l.rbegin();
	auto rit = l.rbegin();
	while (rit != l.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}
//��ֵ�ͽ���
void TestList3()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	PrintList(L1);

	//��ֵ
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

//����
void TestList4()
{

	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	list<int>L2;
	L2.assign(10, 100);

	cout << "����ǰ�� " << endl;
	PrintList(L1);
	PrintList(L2);

	cout << endl;

	L1.swap(L2);

	cout << "������ " << endl;
	PrintList(L1);
	PrintList(L2);

}

// list�����ɾ��
// push_back/pop_back/push_front/pop_front
void TestList5()
{
	int array[] = { 1, 2, 3 };
	list<int> L(array, array + sizeof(array) / sizeof(array[0]));

	// ��list��β������4��ͷ������0
	L.push_back(4);
	L.push_front(0);
	PrintList(L);

	// ɾ��listβ���ڵ��ͷ���ڵ�
	L.pop_back();
	L.pop_front();
	PrintList(L);
}

// insert /erase 
void TestList6()
{
	int array1[] = { 1, 2, 3 };
	list<int> L(array1, array1 + sizeof(array1) / sizeof(array1[0]));

	// ��ȡ�����еڶ����ڵ�
	auto pos = ++L.begin();
	cout << *pos << endl;

	// ��posǰ����ֵΪ4��Ԫ��
	L.insert(pos, 4);
	PrintList(L);

	// ��posǰ����5��ֵΪ5��Ԫ��
	L.insert(pos, 5, 5);
	PrintList(L);

	// ��posǰ����[v.begin(), v.end)�����е�Ԫ��
	vector<int> v{ 7, 8, 9 };
	L.insert(pos, v.begin(), v.end());
	PrintList(L);

	// ɾ��posλ���ϵ�Ԫ��
	L.erase(pos);
	PrintList(L);

	// ɾ��list��[begin, end)�����е�Ԫ�أ���ɾ��list�е�����Ԫ��
	L.erase(L.begin(), L.end());
	PrintList(L);
}

// resize/swap/clear
void TestList7()
{
	// ������������list
	int array1[] = { 1, 2, 3 };
	list<int> l1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
	PrintList(l1);

	// ����l1��l2�е�Ԫ��
	list<int> l2;
	l1.swap(l2);
	PrintList(l1);
	PrintList(l2);

	// ��l2�е�Ԫ�����
	l2.clear();
	cout << l2.size() << endl;
}

//��С����
void TestList8()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	if (L1.empty())
	{
		cout << "L1Ϊ��" << endl;
	}
	else
	{
		cout << "L1��Ϊ��" << endl;
		cout << "L1�Ĵ�СΪ�� " << L1.size() << endl;
	}

	//����ָ����С
	L1.resize(10);
	PrintList(L1);

	L1.resize(2);
	PrintList(L1);
}
//���ݴ�ȡ
void TestList9()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);


	//cout << L1.at(0) << endl;//���� ��֧��at��������
	//cout << L1[0] << endl; //����  ��֧��[]��ʽ��������
	cout << "��һ��Ԫ��Ϊ�� " << L1.front() << endl;
	cout << "���һ��Ԫ��Ϊ�� " << L1.back() << endl;

	//list�����ĵ�������˫�����������֧���������
	list<int>::iterator it = L1.begin();
	//it = it + 1;//���󣬲�������Ծ���ʣ���ʹ��+1
}
//#include "list_stl.h"
//int main()
//{
//	hdm::TesthdmList4();
//	return 0;
//}

//43. �ַ������
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
		//��num1ÿһλȥ��num2��ÿһλ�����浽�������i+j+1��λ���ϣ����ý�λ��ô��
		for (int i = len1 - 1; i >= 0; --i)
		{
			int x1 = num1[i] - '0';
			for (int j = len2 - 1; j >= 0; --j)
			{
				int x2 = num2[j] - '0';
				ansArr[i + j + 1] += x1*x2;
			}
		}
		//��ʼ�����λ
		for (int i = len1 + len2 - 1; i>0; --i)
		{
			ansArr[i - 1] += ansArr[i] / 10;
			ansArr[i] %= 10;
		}
		string ret;
		//�������λ�Ƿ����㣬�Ǿʹ�1��ʼ��
		int index = ansArr[0] == 0 ? 1 : 0;
		//ת���ַ���
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
			int carry = (A&B) << 1;//��Ž�λ
			A ^= B;//���õ����ǽ�λ�ĺ�
			B = carry;//��λ��B����
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



//����ǿ�ȵȼ�
#include <iostream>
#include <string>
using namespace std;
//�ж��Ƿ��ǺϷ�����
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
	//�������볤�ȵ÷�
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
	//�ж��Ƿ��д�Сд
	int isupperflag = 0, islowerflag = 0, isalphaflag = 0;
	int isdigitflag = 0;//�ж������ж��ٸ�
	int issymbolflag = 0;//�жϷ����ж��ٸ�
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
	//��Сд����
	if (islowerflag == 1 && isupperflag == 1)
	{
		score += 20;
	}//��Сдռһ��
	else if (islowerflag == 1 || isupperflag == 1)
	{
		score += 10;
	}
	//�ж����ֵ÷�
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
	//�жϷ��ŵ÷�
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
	//�жϽ����÷�
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
	//��������
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
