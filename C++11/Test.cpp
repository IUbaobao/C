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
	//统一的初始化列表
//	/*C++11扩大了用大括号括起的列表(初始化列表)的使用范围，使其可用于所有的内置类型和用户自
//		定义的类型，使用初始化列表时，可添加等号(= )，也可不添加*/
//	//int arr[]{1, 2, 3, 4, 5, 6};
//	//int x = 2;
//	////自己玩的时候不建议这样用
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
//	//// C++11中列表初始化也可以适用于new表达式中
//	//int* pa = new int[3]{ 1, 2, 3 };
//	//cout << pa[0] << endl;
//	//delete[] pa;
//
	//auto i1 = { 1, 2, 3, 4, 5 };//class std::initializer_list<int>
	////std::initializer_list作为参数的构造函数，这样初始化容器对象就更方便了。也可以作为operator=
	////的参数，这样就可以用大括号赋值
	//cout << typeid(i1).name() << endl;
	//vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8 };//std::initializer_list作为参数的构造函数
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//list<int> lt = { 6, 5, 4, 3, 2, 1, 0 };//std::initializer_list作为参数的构造函数
	//for (auto e : lt)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//list<int> lt2;
	//lt2 = { 1, 1, 1, 1, 1 };//作为operator=的参数
	//for (auto e : lt2)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	////这里的{"sort","排序"}会先构造一个pair对象
	//map<string, string> dict = { { "sort", "排序" }, { "apple", "苹果" } };
	//for (const auto& e : dict)
	//{
	//	cout << e.first << ":" << e.second << endl;
	//}
	/////////////////////////////////////////////////////////////////////////////////////////////


	//声明
	//c++11提供了多种简化声明的方式，尤其是在使用模板时。
	//auto --- 自动推导类型
//	int i = 0;
//	auto p = &i;
//	cout << typeid(p).name() << endl;
//	map<string, string> dict{ { "sort", "排序" }, { "Apple", "苹果" } };
//	//map<string,string>::iterator it = dict.begin();
//	auto it = dict.begin();
//	cout << typeid(it).name() << endl;
//
//	
//	return 0;
//}


// decltype的一些使用使用场景--这里auto也能推出类型
template<class T1,class T2>
void F(T1 x, T2 y)
{
	//关键字decltype将变量的类型声明为表达式指定的类型
	decltype(x*y) ret;//这个可以定义变量的时候不用初始化
	auto reslut = x*y;//这个要初始化
	cout << typeid(ret).name() << endl;
	cout << typeid(reslut).name() << endl;

}

//int main()
//{
//	//关键字decltype将变量的类型声明为表达式指定的类型
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
	//左值引用和右值引用
	//左值:左值是一个表示数据的表达式(如变量名或解引用的指针)，我们可以获取它的地址+可以对它赋
	//值，左值可以出现赋值符号的左边，右值不能出现在赋值符号左边

	//以下的p、b、c、*p都是左值
	//int*p = new int(0);
	//int b = 1;
	//const int c = 1;

	////以下几个是对上面左值的左值引用
	//int& rb = b;
	//int*&rp = p;
	//const int&rc = c;
	//int& pvalue = *p;


	//右值:右值也是一个表示数据的表达式，如：字面常量、表达式返回值，函数返回值(这个不能是左值引
	//用返回)等等，右值可以出现在赋值符号的右边，但是不能出现出现在赋值符号的左边，右值不能
	//取地址。右值引用就是对右值的引用，给右值取别名

	/*double x = 1.1, y = 2.2;*/

	//常见的右值
	//10;
	//x + y;
	//getmin(x, y);

	//右值的引用
	//int&& rr1 = 10;
	//double&& rr2 = x + y;
	//double&& rr3 = getmin(x, y);

	//下面的编译器会报错： error C2106: “=”: 左操作数必须为左值
	//10 = 1;
	//x + y = 2;
	//getmin(x, y) = 3;


	//右值是不能取地址的，但是给右值取别名后，会导致右值被存储到特定位置，且可
	//以取到该位置的地址，也可以修改
	//double x1 = 1.1, y1 = 1.2;
	//int&& rr1 = 10;
	////如果不想rr1被修改，可以用const int&& rr1 去引用
	//const double&& rr2 = x + y;

	////
	//rr1 = 15;
	//编译器会报错：“rr2”: 不能给常量赋值
	//rr2 = 5.5;
	/////////////////////////////////////////////////////////////////////////////////////

	//左值引用总结
	//1. 左值引用只能引用左值，不能引用右值。
	//int a = 10;
	//int& ra1 = a;
	//int&ra2 = 10;//编译失败，10是右值

	//2. 但是const左值引用既可引用左值，也可引用右值
	//const int&ra3 = 10;
	//const int&ra4 = a;


	//右值引用总结：

	//1. 右值引用只能右值，不能引用左值。
//	int&&rr1 = 10;
//
//	//编译会报错:“初始化”: 无法从“int”转换为“int &&”
//	//无法将左值绑定到右值引用
//	int a = 10;
//	//int&&rra = a;
//
//	//2. 但是右值引用可以move以后的左值。
//	int&& rra = std::move(a);
//
//	//更多右值引用的知识...后续博客笔记写
//
//
//
//	return 0; 
//}
/////////////////////////////////////////////////////////////////////////////

///可变参数模板
// Args是一个模板参数包，args是一个函数形参参数包
// 声明一个参数包Args...args，这个参数包中可以包含0到任意个模板参数。
//template <class ...Args>
//void ShowList(Args... args)
//{}


//递归函数方式展开参数包
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
//	ShowList(args...);//当参数只剩一个的时候就调用上面的，而参数有一个以上就递归调用自己
//}

//逗号表达式展开参数包
//template<class T>
//void PrintArg(T val)
//{
//	cout << val << " ";
//}
////展开元素
//template<class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { (PrintArg(args), 0)... };//逗号表达式会按顺序执行逗号前面的表达式，返回最右的那个值
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
//lambda表达式

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
//	//默认按照小于比较，排出来结果是升序
//	sort(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	// 如果需要降序，需要改变元素的比较规则
//	//sort(arr, arr + sizeof(arr) / sizeof(arr[0]),greater<int>());库里面的greater
//	sort(arr, arr + sizeof(arr) / sizeof(arr[0]), mygreater());//可能会根据需要自己写的仿函数,比如一些自定义类型的比较
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
//	// 最简单的lambda表达式, 该lambda表达式没有任何意义
//	[]{};
//
//	// 省略参数列表和返回值类型，返回值类型由编译器推导为int ,[=]表示捕捉父作用域全部变量(包括this)
//	int a = 10, b = 20;
//	auto f = [=]{return a + b; };
//	cout << typeid(f).name() << endl;//class <lambda_20a5e18c78724c4cfb60d4d19f95f13a>底层是一个类，名称是随机生成的
//	cout << f() << endl;
//
//	//// 省略了返回值类型，无返回值类型[&]引用传递捕捉所有父作用域中的变量(包括this)
//	auto fun1 = [&](int c){b = a + c; };
//	fun1(100);
//	cout << a << "  " << b << endl;
//
//	// 各部分都很完善的lambda函数
//	auto fun2 = [=, &b](int c)->int{return b += a + c; };//引用传递捕捉变量b
//	cout << fun2(200) << endl;
//
//	//// 复制捕捉x
//	int x = 10;
//	auto fun3 = [x](int a)mutable{x *= 2; return a + x; };//lambda函数总是一个const函数,mutable可以取消其常量性
//	cout << fun3(10) << endl;
//
//
//	//[var]：表示值传递方式捕捉变量var
//	//[=]：表示值传递方式捕获所有父作用域中的变量(包括this)
//	//[&var]：表示引用传递捕捉变量var
//	//[&]：表示引用传递捕捉所有父作用域中的变量(包括this)
//	//[this]：表示值传递方式捕捉当前的this指针
//	return 0;
//}


