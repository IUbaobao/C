#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

////�����ռ�
//namespace test
//{
//	int rand = 1;
//}
//
////��������
//int add(int a, int b)
//{
//	return a + b;
//}
//
//float add(float a, float b)
//{
//	return a + b;
//}
//double add(double a, double b)
//{
//	return a + b;
//}
//
////ȱʡ����
//void f(int a = 0, int b = 0)
//{
//	cout << a << endl;
//	cout << b << endl;
//}
//
//int main()
//{
//	//int a, b;
//	//char c;
//	//cin >> a >> b >> c;
//	//cout << a << ' ' << b << ' ' << c << endl;
//	/*cout << test::rand << endl;*/
//
//	////cout << add(1, 2) << '\n' << add(2.1, 3.2) << endl;
//	//f();
//	//f(1);
//	//f(1, 2);
//
//
//	return 0;
//}



//��ֵ
void swap(int e1, int e2)
{
	int tmp = e1;
	e1 = e2;
	e2 = tmp;
}

//��ָ��
void swap(int* e1, int* e2)
{
	int tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

//������
void swap(int& e1, int& e2)
{
	int tmp = e1;
	e1 = e2;
	e2 = tmp;
}

int main()
{

	//int a = 10;
	////����--ra��a�ı���,���ñ����ʼ��
	//int& ra = a;
	//cout << ra << ' ' << a << endl;
	//cout << &ra << ' ' << &a << endl;
	//ra = 20;
	//cout << ra << ' ' << a << endl;

	const int a = 10;
	int b = 20;
	//Ȩ�޲�������
	//int& ra = a;

	//Ȩ��ƽ��
	int& rb = b;
	const int& ra = a;

	//Ȩ����С
	const int& rrb = b;

	return 0;
}