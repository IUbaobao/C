#define _CRT_SECURE_NO_WARNINGS

//#include<iostream>
//using namespace std;
//
//////�����ռ�
////namespace test
////{
////	int rand = 1;
////}
////
//////��������
////int add(int a, int b)
////{
////	return a + b;
////}
////
////float add(float a, float b)
////{
////	return a + b;
////}
////double add(double a, double b)
////{
////	return a + b;
////}
////
//////ȱʡ����
////void f(int a = 0, int b = 0)
////{
////	cout << a << endl;
////	cout << b << endl;
////}
////
////int main()
////{
////	//int a, b;
////	//char c;
////	//cin >> a >> b >> c;
////	//cout << a << ' ' << b << ' ' << c << endl;
////	/*cout << test::rand << endl;*/
////
////	////cout << add(1, 2) << '\n' << add(2.1, 3.2) << endl;
////	//f();
////	//f(1);
////	//f(1, 2);
////
////
////	return 0;
////}
//
//
//
////��ֵ
//void swap(int e1, int e2)
//{
//	int tmp = e1;
//	e1 = e2;
//	e2 = tmp;
//}
//
////��ָ��
//void swap(int* e1, int* e2)
//{
//	int tmp = *e1;
//	*e1 = *e2;
//	*e2 = tmp;
//}
//
////������
//void swap(int& e1, int& e2)
//{
//	int tmp = e1;
//	e1 = e2;
//	e2 = tmp;
//}
//
////
//////�����÷�
////int& f()
////{
////	int n = 0;
////	n++;
////	return n;
////}
//
//int f1(int& a)
//{
//	return 1;
//}
//
//////////////////////////////////
////��ȷ�÷�    ������������Ҫ��֤�÷���ֵ���������򻹴���
//int& f()
//{
//	 static int n = 0;
//	n++;
//	return n;
//}
//
//
//int f2(const int& a)
//{
//	return 1;
//}
//
//
//
//
//int main()
//{
//
//	//int a = 10;
//	////����--ra��a�ı���,���ñ����ʼ��
//	//int& ra = a;
//	//cout << ra << ' ' << a << endl;
//	//cout << &ra << ' ' << &a << endl;
//	//ra = 20;
//	//cout << ra << ' ' << a << endl;
//
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
//	//f(ra);
//	
//	//����Ȩ������,Ȩ�޲�������
//	//f1(ra);
//	f2(ra);
//	return 0;
//}


////C�����µġ�hello world��
//#include<stdio.h>
//int main()
//{
//	printf("hello world\n");
//	return 0;
//}
//
//
////C++�µġ�hello world��
////��ʽһ��
//#include<iostream>
//int main()
//{
//	std::cout << "hello world" << std::endl;
//	return 0;
//}
//
//
////��ʽ����
//#include<iostream>
//using namespace std;
//int main()
//{
//	cout << "hello world" << endl;
//	return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//
//int rand = 0;
//// C����û�취�������������������ͻ���⣬����C++�����namespace�����
//int main()
//{
//	printf("%d ", rand);
//	// �����󱨴�error C2365: ��rand��: �ض��壻��Ϊrand�Ķ����ǡ���������rand�ǻ�ȡ�������һ������
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
// hdm�������ռ�����֣�һ�㿪����������Ŀ�����������ռ�����
// ����������ʾ��Ҫhdm��������ȥ�Ժ��Լ���ϰ���Լ�������д���ɣ���������zs
// 1. �����������ռ䶨��
//namespace hdm
//{
//	// �����ռ��п��Զ������/����/����
//	int rand = 1;
//
//	struct stu
//	{
//		int age;
//		char name[10];
//	};
//
//	void print()
//	{
//		printf("hello namespace\n");
//	}
//}

//int main()
//{
//	//���������ռ�ı���Ҫ   �����ռ�����+::+Ҫ���ʵĶ���
//	//ָ���������������ռ��е�rand
//	printf("�����ռ�hdm�е�rand��%d \n", hdm::rand);
//	
//	//����Ҳ���Դ�ӡһ��stdlib.h��rand�����ĵ�ַ
//	printf("stdlib.h�е�rand������ַ��%p\n ", rand);
//
//	
//	return 0;
//}


//namespace hdm1
//{
//	int a = 1;
//	
//	//2.�����ռ����Ƕ��ʹ��
//	namespace hdm2
//	{
//		int b = 2;
//	}
//}
//
//int main()
//{
//	//Ƕ��ʹ�ú����b�ķ�ʽ��
//	printf("%d", hdm1::hdm2::b);
//	return 0;
//}



//3. ͬһ��������������ڶ����ͬ���Ƶ������ռ�,����������ϳ�ͬһ�������ռ��С�
// ps��һ�������е�test.h������test.cpp������hdm1�ᱻ�ϲ���һ��

//�����������test.h�ļ�
//namespace hdm1
//{
//	int a = 1;
//}
//
//
////�����test.cpp�ļ�
//namespace hdm1
//{
//	int b = 2;
//}


//��ô���ǻ�ϲ���һ�������µ�����
//namespace hdm1
//{
//	int a = 1;
//	int b = 2;
//}


//int main()
//{
//	printf("%d\n", hdm1::a);
//	printf("%d\n", hdm1::b);
//
//	return 0;
//}



//namespace hdm
//{
//	int a = 10;
//}
//
//int main()
//{
//
//	printf("%d\n",hdm:: a);
//	return 0;
//}
//#include<iostream>
//int main()
//{
//	std::cout << "hello world" << std::endl;
//	return 0;
//}

//namespace hdm
//{
//	int a = 10;
//	int b = 20;
//}

////��ʹ��using namespace �����ռ����� ���루չ����
//int main()
//{
//	printf("%d\n", hdm::a);
//	printf("%d\n", hdm::b);
//
//}
 

//namespace hdm
//{
//	int a = 10;
//	int b = 20;
//}
//int b = 200;
////ʹ��using�������ռ���ĳ����Ա����
////������ֻ���aչ��������b��ȫ�ֱ����е�b��ͻ
//using  hdm::a;
//int main()
//{
//	printf("%d\n", a);
//	printf("%d\n", hdm::b);
//	printf("%d\n",::b);//ע�⣺����ȫ�ֵı������ո�/ʲô����д+::+������
//	return 0;
//}



//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a;
//	double b;
//	char c;
//	//����ֵ
//	// �����Զ�ʶ�����������
//	cin >> a >> b >> c;
//
//	//��ӡ
//	cout << a << ' ' << b << ' ' << c << endl;
//	return 0;
//}



//void f(int a = 0)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	//��������Ĭ��0
//	f();
//
//	//���ε����
//	f(100);
//	return 0;
//}



//void fun(int a = 10, int b = 20, int c = 30)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//
//int main()
//{
//	//���Բ�����Ҳ���Դ�һ�����߶��(����Ǻ����������õĸ���)
//	fun();
//	fun(1);
//	fun(1,2);
//	fun(1,2,3);
//	return 0;
//}


////��ȱʡ����
//void fun(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//int main()
//{
//	//��Ϊ��һ������û��Ĭ��ֵ���������ٴ�һ������
//	fun(1);
//	fun(1, 2);
//	fun(1, 2, 3);
//	return 0;
//}

//
////��ȱʡ��������**��������**���������������ܼ���Ÿ�
////�����ȱʡ������ʾ
//void fun(int a = 10, int b, int c=3)
//{
//	cout << a << b << c << endl;
//}
//
////�����ȱʡ������ʾ
//void fun(int a = 10, int b=2, int c)
//{
//	cout << a << b << c << endl;
//}


//ȱʡ���������ں��������Ͷ�����ͬʱ����

//������ʾ
//void fun(int a = 1);
//void fun(int a = 1)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	fun();
//	//����ᱨ����fun��: �ض���Ĭ�ϲ��� 
//	return 0;
//}


//��ȷ������һ�㺯����������ȱʡ��ʵ�ֲ���ȱʡ
//void fun(int a = 1);
//void fun(int a)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	fun();
//	return 0;
//}


//
//
//#include<iostream>
//using namespace std;
//// 1���������Ͳ�ͬ
//int Add(int e1, int e2)
//{
//	return e1 + e2;
//}
//double Add(double e1, double e2)
//{
//	return e1 + e2;
//}
//// 2������������ͬ
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//// 3����������˳��ͬ
//void fun(int a, char b)
//{
//	cout << "fun(int a,char b)" << endl;
//}
//void fun(char b, int a)
//{
//	cout << "fun(char b,int a)" << endl;
//}
//
//int main()
//{	
//	//�������Ͳ�ͬ
//	cout << Add(1, 2) << "  " << Add(3.14, 3.14) << endl;
//	//����������ͬ
//	f();
//	f(1);
//	//��������˳��ͬ
//	fun(1, 'b');
//	fun('b', 1);
//	return 0;
//}

//
//
//#include<iostream>
//using namespace std;
//
////C++�տ�ʼ����
//struct Stack
//{
//	void Init(int n = 4)
//	{
//		//.....
//	}
//	void Push(int x)
//	{
//		//.....
//	}
//
//
//	int* a;
//	int top;
//	int capacity;
//};
//
//
//class Queue
//{
//	//���з���
//public:
//	void Init(int n = 4)
//	{
//		//....
//	}
//	void Push(int x)
//	{
//		//...
//	}
//
////˽������
//private:
//	int* a;
//	int size;
//	int capacity;
//};
//
//int main()
//{
//
//	return 0;
//}



#include<iostream>
using namespace std;

//class Data
//{
//public:
//	//���캯��  --���������ʱ������ִ�У�������������������Ҳ������������
//	Data(int year=0,int month=0,int day=0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "    " << _month << "   " << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};


class Data
{
public:
	//���캯��  --���������ʱ������ִ�У�������������������Ҳ������������

	void Print()
	{
		cout << _year << "    " << _month << "   " << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data AA;
	AA.Print();
	return 0;
}