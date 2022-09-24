//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int& ra = a;//ra就是a的引用
//
//	//它们两个的地址是一样的
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
//	// int &ra;  不初始化编译器会报错
//	int& ra = a;//ra就是a的引用
//	int& rra = a;//rra也是a的引用
//
//	ra = b; //这是赋值操作，不是更改引用
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
//	//不加const值可以修改，加const让它权限缩小，无法修改
//	//记住权限只能缩小，不能扩大
//	const int a = 10;
//	int b = 20;
//	//权限不能扩大
//	//int& ra = a;
//
//	//权限平移
//	int& rb = b;
//	const int& ra = a;
//
//	//权限缩小
//	const int& rrb = b;
//
//}
//
//void TestConst()
//{
//	const int a = 10;
//	//int& ra = a; // 该语句编译时会出错，a为常量(这里是权限扩大)
//	const int& ra = a;
//
//	// int& b = 10; // 该语句编译时会出错，b为常量(这里是权限扩大)
//	const int& b = 10;
//
//	double d = 12.34;
//	//int& rd = d; // 该语句编译时会出错，类型不同
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

//////错误用法（n出了作用域之后就销毁了）
////int& f()
////{
////	int n = 0;
////	n++;
////	return n;
////}
/////////////////////////////////////////////////////////
////正确用法    用引用作返回要保证该返回值出了作用域还存在
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
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;//传值运行时间
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;//引用传值运行时间
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
//// 值返回
//A TestFunc1() { return a; }
//// 引用返回
//A& TestFunc2() { return a; }
//void TestReturnByRefOrValue()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// 计算两个函数运算完成之后的时间
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
//	int* pa = &a;//定义一个指针变量
//
//	//自动转换为 int* const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
//	int& ref = a;
//	ref = 20; //内部发现ref是引用，自动帮我们转换为: *ref = 20;
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
////无法解析的外部符号 "int __cdecl Add(int,int)" (?Add@@YAHHH@Z)，函数 _main 中引用了该符号





//#include <string>
//#include <map>
//
//typedef std::map<std::string, std::string> Map;
//int main()
//{
//	Map m{ { "apple", "苹果" }, { "orange","橙子" },{"pear","梨"} };
//	Map::iterator it = m.begin();
//	return 0;
//}
//std::map<std::string, std::string>::iterator 是一个类型，但是该类型太长了，特别容
//易写错。聪明的朋友可能已经想到：可以通过typedef给类型取别名，比如：


//#include<iostream>
//using namespace std;
//typedef char* pstring;
//int main()
//{	
//	const  char a[] = "123";
//   // const pstring p1=a; // 编译成功还是失败？失败//cstr是指向char的常量指针；
//	const pstring* p2; // 编译成功还是失败？成功//ps是一个指针，它的对象是指向char的常量指针；
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
//	//下面的无法通过编译，使用auto定义变量时必须对其进行初始化
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
//	auto a = 10, b = 20;//同一类型可以同一行定义
//	auto c=30, d=3.14// 该行代码会编译失败，因为c和d的初始化表达式类型不同
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
	f(NULL);//NULL是空指针，按正常来说应该执行f(int*)，但实际并没有
	f((int*)NULL);
	return 0;
}
