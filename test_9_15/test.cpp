#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

////命名空间
//namespace test
//{
//	int rand = 1;
//}
//
////函数重载
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
////缺省参数
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



//传值
void swap(int e1, int e2)
{
	int tmp = e1;
	e1 = e2;
	e2 = tmp;
}

//传指针
void swap(int* e1, int* e2)
{
	int tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

//传引用
void swap(int& e1, int& e2)
{
	int tmp = e1;
	e1 = e2;
	e2 = tmp;
}

//
////错误用法
//int& f()
//{
//	int n = 0;
//	n++;
//	return n;
//}

int f1(int& a)
{
	return 1;
}

////////////////////////////////
//正确用法    用引用作返回要保证该返回值出了作用域还存在
int& f()
{
	 static int n = 0;
	n++;
	return n;
}


int f2(const int& a)
{
	return 1;
}




int main()
{

	//int a = 10;
	////引用--ra是a的别名,引用必须初始化
	//int& ra = a;
	//cout << ra << ' ' << a << endl;
	//cout << &ra << ' ' << &a << endl;
	//ra = 20;
	//cout << ra << ' ' << a << endl;

	const int a = 10;
	int b = 20;
	//权限不能扩大
	//int& ra = a;

	//权限平移
	int& rb = b;
	const int& ra = a;

	//权限缩小
	const int& rrb = b;

	//f(ra);
	
	//还是权限问题,权限不能扩大
	//f1(ra);
	f2(ra);
	return 0;
}