#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

struct pos
{
	int x;
	int y;
};


//int main()
//{
	//ͳһ�ĳ�ʼ���б�
//	/*C++11�������ô�����������б�(��ʼ���б�)��ʹ�÷�Χ��ʹ����������е��������ͺ��û���
//		��������ͣ�ʹ�ó�ʼ���б�ʱ������ӵȺ�(= )��Ҳ�ɲ����*/
//	//int arr[]{1, 2, 3, 4, 5, 6};
//	//int x = 2;
//	////�Լ����ʱ�򲻽���������
//	//int a = { 2 };
//	//int b{ 3 };
//	//pos p{ 1, 2 };
//	//cout << p.x << ":" << p.y << endl;
//	//for (auto e : arr)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//	//// C++11���б��ʼ��Ҳ����������new���ʽ��
//	//int* pa = new int[3]{ 1, 2, 3 };
//	//cout << pa[0] << endl;
//	//delete[] pa;
//
	//auto i1 = { 1, 2, 3, 4, 5 };//class std::initializer_list<int>
	////std::initializer_list��Ϊ�����Ĺ��캯����������ʼ����������͸������ˡ�Ҳ������Ϊoperator=
	////�Ĳ����������Ϳ����ô����Ÿ�ֵ
	//cout << typeid(i1).name() << endl;
	//vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8 };//std::initializer_list��Ϊ�����Ĺ��캯��
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//list<int> lt = { 6, 5, 4, 3, 2, 1, 0 };//std::initializer_list��Ϊ�����Ĺ��캯��
	//for (auto e : lt)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//list<int> lt2;
	//lt2 = { 1, 1, 1, 1, 1 };//��Ϊoperator=�Ĳ���
	//for (auto e : lt2)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	////�����{"sort","����"}���ȹ���һ��pair����
	//map<string, string> dict = { { "sort", "����" }, { "apple", "ƻ��" } };
	//for (const auto& e : dict)
	//{
	//	cout << e.first << ":" << e.second << endl;
	//}
	/////////////////////////////////////////////////////////////////////////////////////////////


	//����
	//c++11�ṩ�˶��ּ������ķ�ʽ����������ʹ��ģ��ʱ��
	//auto --- �Զ��Ƶ�����
//	int i = 0;
//	auto p = &i;
//	cout << typeid(p).name() << endl;
//	map<string, string> dict{ { "sort", "����" }, { "Apple", "ƻ��" } };
//	//map<string,string>::iterator it = dict.begin();
//	auto it = dict.begin();
//	cout << typeid(it).name() << endl;
//
//	
//	return 0;
//}


// decltype��һЩʹ��ʹ�ó���--����autoҲ���Ƴ�����
template<class T1,class T2>
void F(T1 x, T2 y)
{
	//�ؼ���decltype����������������Ϊ���ʽָ��������
	decltype(x*y) ret;//������Զ��������ʱ���ó�ʼ��
	auto reslut = x*y;//���Ҫ��ʼ��
	cout << typeid(ret).name() << endl;
	cout << typeid(reslut).name() << endl;

}

//int main()
//{
//	//�ؼ���decltype����������������Ϊ���ʽָ��������
//	int a = 2;
//	double b= 2.2;
//	F(a, b);
//	decltype(&a) p;
//	cout << typeid(p).name() << endl;
//
//	return 0;
//}

template<class T1>
T1 getmin(T1 x, T1 y)
{
	return x > y ? y : x;
}


//int main()
//{
	//��ֵ���ú���ֵ����
	//��ֵ:��ֵ��һ����ʾ���ݵı��ʽ(�������������õ�ָ��)�����ǿ��Ի�ȡ���ĵ�ַ+���Զ�����
	//ֵ����ֵ���Գ��ָ�ֵ���ŵ���ߣ���ֵ���ܳ����ڸ�ֵ�������

	//���µ�p��b��c��*p������ֵ
	//int*p = new int(0);
	//int b = 1;
	//const int c = 1;

	////���¼����Ƕ�������ֵ����ֵ����
	//int& rb = b;
	//int*&rp = p;
	//const int&rc = c;
	//int& pvalue = *p;


	//��ֵ:��ֵҲ��һ����ʾ���ݵı��ʽ���磺���泣�������ʽ����ֵ����������ֵ(�����������ֵ��
	//�÷���)�ȵȣ���ֵ���Գ����ڸ�ֵ���ŵ��ұߣ����ǲ��ܳ��ֳ����ڸ�ֵ���ŵ���ߣ���ֵ����
	//ȡ��ַ����ֵ���þ��Ƕ���ֵ�����ã�����ֵȡ����

	/*double x = 1.1, y = 2.2;*/

	//��������ֵ
	//10;
	//x + y;
	//getmin(x, y);

	//��ֵ������
	//int&& rr1 = 10;
	//double&& rr2 = x + y;
	//double&& rr3 = getmin(x, y);

	//����ı������ᱨ�� error C2106: ��=��: �����������Ϊ��ֵ
	//10 = 1;
	//x + y = 2;
	//getmin(x, y) = 3;


	//��ֵ�ǲ���ȡ��ַ�ģ����Ǹ���ֵȡ�����󣬻ᵼ����ֵ���洢���ض�λ�ã��ҿ�
	//��ȡ����λ�õĵ�ַ��Ҳ�����޸�
	//double x1 = 1.1, y1 = 1.2;
	//int&& rr1 = 10;
	////�������rr1���޸ģ�������const int&& rr1 ȥ����
	//const double&& rr2 = x + y;

	////
	//rr1 = 15;
	//�������ᱨ����rr2��: ���ܸ�������ֵ
	//rr2 = 5.5;
	/////////////////////////////////////////////////////////////////////////////////////

	//��ֵ�����ܽ�
	//1. ��ֵ����ֻ��������ֵ������������ֵ��
	//int a = 10;
	//int& ra1 = a;
	//int&ra2 = 10;//����ʧ�ܣ�10����ֵ

	//2. ����const��ֵ���üȿ�������ֵ��Ҳ��������ֵ
	//const int&ra3 = 10;
	//const int&ra4 = a;


	//��ֵ�����ܽ᣺

	//1. ��ֵ����ֻ����ֵ������������ֵ��
//	int&&rr1 = 10;
//
//	//����ᱨ��:����ʼ����: �޷��ӡ�int��ת��Ϊ��int &&��
//	//�޷�����ֵ�󶨵���ֵ����
//	int a = 10;
//	//int&&rra = a;
//
//	//2. ������ֵ���ÿ���move�Ժ����ֵ��
//	int&& rra = std::move(a);
//
//	//������ֵ���õ�֪ʶ...�������ͱʼ�д
//
//
//
//	return 0; 
//}
/////////////////////////////////////////////////////////////////////////////

///�ɱ����ģ��
// Args��һ��ģ���������args��һ�������ββ�����
// ����һ��������Args...args������������п��԰���0�������ģ�������
//template <class ...Args>
//void ShowList(Args... args)
//{}


//�ݹ麯����ʽչ��������
//template<class T>
//void ShowList(T val)
//{
//	cout << val << endl;
//}
//
//template<class T,class ...Args>
//void ShowList(T val,Args... args)
//{
//	cout << val << " ";
//	ShowList(args...);//������ֻʣһ����ʱ��͵�������ģ���������һ�����Ͼ͵ݹ�����Լ�
//}

//���ű��ʽչ��������
//template<class T>
//void PrintArg(T val)
//{
//	cout << val << " ";
//}
////չ��Ԫ��
//template<class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { (PrintArg(args), 0)... };//���ű��ʽ�ᰴ˳��ִ�ж���ǰ��ı��ʽ���������ҵ��Ǹ�ֵ
//	//cout << endl;
//	//for (auto e : arr)
//	//{
//	//	cout << e << " ";
//	//}
//	cout << endl;
//}
//
//int main()
//{
//	ShowList(1);
//	ShowList(1,"string:::");
//	ShowList(1,"string",1.1);
//	ShowList(1, "string", 1.1,'A');
//
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////
//lambda���ʽ

//struct mygreater
//{
//	bool operator()(int left, int right)
//	{
//		return left > right;
//	}
//};
//
//int main()
//{
//	int arr[] = { 4, 3, 1, 6, 7, 8, 9 };
//	//Ĭ�ϰ���С�ڱȽϣ��ų������������
//	sort(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	// �����Ҫ������Ҫ�ı�Ԫ�صıȽϹ���
//	//sort(arr, arr + sizeof(arr) / sizeof(arr[0]),greater<int>());�������greater
//	sort(arr, arr + sizeof(arr) / sizeof(arr[0]), mygreater());//���ܻ������Ҫ�Լ�д�ķº���,����һЩ�Զ������͵ıȽ�
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//lambda
//	int arr1[] = { 4, 3, 1, 6, 7, 8, 9 };
//	sort(arr1, arr1 + sizeof(arr) / sizeof(arr1[0]), [](int a, int b){return a > b; });
//	for (auto e : arr1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//
//	// ��򵥵�lambda���ʽ, ��lambda���ʽû���κ�����
//	[]{};
//
//	// ʡ�Բ����б�ͷ���ֵ���ͣ�����ֵ�����ɱ������Ƶ�Ϊint ,[=]��ʾ��׽��������ȫ������(����this)
//	int a = 10, b = 20;
//	auto f = [=]{return a + b; };
//	cout << typeid(f).name() << endl;//class <lambda_20a5e18c78724c4cfb60d4d19f95f13a>�ײ���һ���࣬������������ɵ�
//	cout << f() << endl;
//
//	//// ʡ���˷���ֵ���ͣ��޷���ֵ����[&]���ô��ݲ�׽���и��������еı���(����this)
//	auto fun1 = [&](int c){b = a + c; };
//	fun1(100);
//	cout << a << "  " << b << endl;
//
//	// �����ֶ������Ƶ�lambda����
//	auto fun2 = [=, &b](int c)->int{return b += a + c; };//���ô��ݲ�׽����b
//	cout << fun2(200) << endl;
//
//	//// ���Ʋ�׽x
//	int x = 10;
//	auto fun3 = [x](int a)mutable{x *= 2; return a + x; };//lambda��������һ��const����,mutable����ȡ���䳣����
//	cout << fun3(10) << endl;
//
//
//	//[var]����ʾֵ���ݷ�ʽ��׽����var
//	//[=]����ʾֵ���ݷ�ʽ�������и��������еı���(����this)
//	//[&var]����ʾ���ô��ݲ�׽����var
//	//[&]����ʾ���ô��ݲ�׽���и��������еı���(����this)
//	//[this]����ʾֵ���ݷ�ʽ��׽��ǰ��thisָ��
//	return 0;
//}


