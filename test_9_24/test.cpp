//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int& ra = a;//ra����a������
//
//	//���������ĵ�ַ��һ����
//	cout << &a << endl;
//	cout << &ra << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int b = 20;
//	// int &ra;  ����ʼ���������ᱨ��
//	int& ra = a;//ra����a������
//	int& rra = a;//rraҲ��a������
//
//	ra = b; //���Ǹ�ֵ���������Ǹ�������
//
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//void Test()
//{
//	//����constֵ�����޸ģ���const����Ȩ����С���޷��޸�
//	//��סȨ��ֻ����С����������
//	const int a = 10;
//	int b = 20;
//	//Ȩ�޲�������
//	//int& ra = a;
//
//	//Ȩ��ƽ��
//	int& rb = b;
//	const int& ra = a;
//
//	//Ȩ����С
//	const int& rrb = b;
//
//}
//
//void TestConst()
//{
//	const int a = 10;
//	//int& ra = a; // ��������ʱ�����aΪ����(������Ȩ������)
//	const int& ra = a;
//
//	// int& b = 10; // ��������ʱ�����bΪ����(������Ȩ������)
//	const int& b = 10;
//
//	double d = 12.34;
//	//int& rd = d; // ��������ʱ��������Ͳ�ͬ
//	const int& rd = d;
//}
//int main()
//{
//	TestConst();
//	return 0;
//}
//

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}




//
//int& Count()
//{
//	static int n = 0;
//	n++;
//	// ...
//	return n;
//}

//////�����÷���n����������֮��������ˣ�
////int& f()
////{
////	int n = 0;
////	n++;
////	return n;
////}
/////////////////////////////////////////////////////////
////��ȷ�÷�    ������������Ҫ��֤�÷���ֵ���������򻹴���
//int& f()
//{
//	 static int n = 0;
//	n++;
//	return n;
//}
//
//#include<iostream>
//using namespace std;
//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}


//
//
//
//#include<iostream>
//#include <time.h>
//using namespace std;
//struct A { int a[10000]; };
//void TestFunc1(A a) {}
//void TestFunc2(A& a) {}
//void TestRefAndValue()
//{
//	A a;
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;//��ֵ����ʱ��
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;//���ô�ֵ����ʱ��
//}
//
//int main()
//{
//	TestRefAndValue();
//	return 0;
//}
//#include<iostream>
//#include <time.h>
//using namespace std;
//#include <time.h>
//struct A { int a[10000]; };
//A a;
//// ֵ����
//A TestFunc1() { return a; }
//// ���÷���
//A& TestFunc2() { return a; }
//void TestReturnByRefOrValue()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// �������������������֮���ʱ��
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//int main()
//{
//	TestReturnByRefOrValue();
//	return 0;
//}





//#include<iostream>
//using namespace std;
//
//int main() {
//	int a = 10;
//
//	int* pa = &a;//����һ��ָ�����
//
//	//�Զ�ת��Ϊ int* const ref = &a; ָ�볣����ָ��ָ�򲻿ɸģ�Ҳ˵��Ϊʲô���ò��ɸ���
//	int& ref = a;
//	ref = 20; //�ڲ�����ref�����ã��Զ�������ת��Ϊ: *ref = 20;
//
//	return 0;
//}



//inline int Add(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int ret = 0;
//	ret = Add(1, 2);
//	return 0;
//}


////Add.h
//inline int Add(int a, int b);
//
//
////Add.cpp
//#include"test.h"
//
//int  Add(int a, int b)
//{
//	return a + b;
//}
//
////test.cpp
//#include"test.h"
//int main()
//{
//	int ret =Add(1,2);
//	return 0;
//}
////�޷��������ⲿ���� "int __cdecl Add(int,int)" (?Add@@YAHHH@Z)������ _main �������˸÷���





//#include <string>
//#include <map>
//
//typedef std::map<std::string, std::string> Map;
//int main()
//{
//	Map m{ { "apple", "ƻ��" }, { "orange","����" },{"pear","��"} };
//	Map::iterator it = m.begin();
//	return 0;
//}
//std::map<std::string, std::string>::iterator ��һ�����ͣ����Ǹ�����̫���ˣ��ر���
//��д�����������ѿ����Ѿ��뵽������ͨ��typedef������ȡ���������磺


//#include<iostream>
//using namespace std;
//typedef char* pstring;
//int main()
//{	
//	const  char a[] = "123";
//   // const pstring p1=a; // ����ɹ�����ʧ�ܣ�ʧ��//cstr��ָ��char�ĳ���ָ�룻
//	const pstring* p2; // ����ɹ�����ʧ�ܣ��ɹ�//ps��һ��ָ�룬���Ķ�����ָ��char�ĳ���ָ�룻
//
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(pstring).name() << endl;
//	cout << typeid(p2).name() << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	//������޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��
//	//auto f;
//	//auto e; 
//	return 0;
//}

//
//#include<iostream>
//using namespace std;
//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	*a = 20;
//	*b = 30;
//	c = 40;
//	return 0;
//}


//void test()
//{
//	auto a = 10, b = 20;//ͬһ���Ϳ���ͬһ�ж���
//	auto c=30, d=3.14// ���д�������ʧ�ܣ���Ϊc��d�ĳ�ʼ�����ʽ���Ͳ�ͬ
//}

#include<iostream>
using namespace std;
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//	//{
//	//	cout << arr[i] << endl;
//	//}
//	//
//	for (auto e : arr)
//		cout << e << endl;
//
//	return 0;
//}

//void TestFor(int array[])
//{
//	for (auto& e : array)
//		cout << e << endl;
//}

//int main()
//{
//	int* p1 = NULL;
//	return 0;
//}
//
//
//#ifndef NULL
//#ifdef __cplusplus
//#define NULL 0
//#else
//#define NULL ((void *)0)
//#endif
//#endif






void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);
	f(NULL);//NULL�ǿ�ָ�룬��������˵Ӧ��ִ��f(int*)����ʵ�ʲ�û��
	f((int*)NULL);
	return 0;
}
