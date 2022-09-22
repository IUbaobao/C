#define _CRT_SECURE_NO_WARNINGS

//#include<iostream>
//using namespace std;
//
//////命名空间
////namespace test
////{
////	int rand = 1;
////}
////
//////函数重载
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
//////缺省参数
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
////传值
//void swap(int e1, int e2)
//{
//	int tmp = e1;
//	e1 = e2;
//	e2 = tmp;
//}
//
////传指针
//void swap(int* e1, int* e2)
//{
//	int tmp = *e1;
//	*e1 = *e2;
//	*e2 = tmp;
//}
//
////传引用
//void swap(int& e1, int& e2)
//{
//	int tmp = e1;
//	e1 = e2;
//	e2 = tmp;
//}
//
////
//////错误用法
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
////正确用法    用引用作返回要保证该返回值出了作用域还存在
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
//	////引用--ra是a的别名,引用必须初始化
//	//int& ra = a;
//	//cout << ra << ' ' << a << endl;
//	//cout << &ra << ' ' << &a << endl;
//	//ra = 20;
//	//cout << ra << ' ' << a << endl;
//
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
//	//f(ra);
//	
//	//还是权限问题,权限不能扩大
//	//f1(ra);
//	f2(ra);
//	return 0;
//}


////C语言下的“hello world”
//#include<stdio.h>
//int main()
//{
//	printf("hello world\n");
//	return 0;
//}
//
//
////C++下的“hello world”
////方式一：
//#include<iostream>
//int main()
//{
//	std::cout << "hello world" << std::endl;
//	return 0;
//}
//
//
////方式二：
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
//// C语言没办法解决类似这样的命名冲突问题，所以C++提出了namespace来解决
//int main()
//{
//	printf("%d ", rand);
//	// 编译后后报错：error C2365: “rand”: 重定义；因为rand的定义是“函数”，rand是获取随机数的一个函数
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
// hdm是命名空间的名字，一般开发中是用项目名字做命名空间名。
// 这里给大家演示就要hdm，我们下去以后自己练习用自己名字缩写即可，如张三：zs
// 1. 正常的命名空间定义
//namespace hdm
//{
//	// 命名空间中可以定义变量/函数/类型
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
//	//访问命名空间的变量要   命名空间名字+::+要访问的对象
//	//指定输入我们命名空间中的rand
//	printf("命名空间hdm中的rand：%d \n", hdm::rand);
//	
//	//我们也可以打印一下stdlib.h中rand函数的地址
//	printf("stdlib.h中的rand函数地址：%p\n ", rand);
//
//	
//	return 0;
//}


//namespace hdm1
//{
//	int a = 1;
//	
//	//2.命名空间可以嵌套使用
//	namespace hdm2
//	{
//		int b = 2;
//	}
//}
//
//int main()
//{
//	//嵌套使用后访问b的方式：
//	printf("%d", hdm1::hdm2::b);
//	return 0;
//}



//3. 同一个工程中允许存在多个相同名称的命名空间,编译器最后会合成同一个命名空间中。
// ps：一个工程中的test.h和上面test.cpp中两个hdm1会被合并成一个

//如现在这个是test.h文件
//namespace hdm1
//{
//	int a = 1;
//}
//
//
////这个是test.cpp文件
//namespace hdm1
//{
//	int b = 2;
//}


//那么它们会合并在一起变成以下的样子
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

////不使用using namespace 命名空间名称 引入（展开）
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
////使用using将命名空间中某个成员引入
////比如我只想把a展开，避免b与全局变量中的b冲突
//using  hdm::a;
//int main()
//{
//	printf("%d\n", a);
//	printf("%d\n", hdm::b);
//	printf("%d\n",::b);//注意：访问全局的变量，空格/什么都不写+::+变量名
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
//	//接收值
//	// 可以自动识别变量的类型
//	cin >> a >> b >> c;
//
//	//打印
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
//	//不传参数默认0
//	f();
//
//	//传参的情况
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
//	//可以不传，也可以传一个或者多个(最多是函数本身设置的个数)
//	fun();
//	fun(1);
//	fun(1,2);
//	fun(1,2,3);
//	return 0;
//}


////半缺省参数
//void fun(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//int main()
//{
//	//因为有一个参数没有默认值，所以至少传一个参数
//	fun(1);
//	fun(1, 2);
//	fun(1, 2, 3);
//	return 0;
//}

//
////半缺省参数必须**从右往左**依次来给出，不能间隔着给
////错误的缺省参数演示
//void fun(int a = 10, int b, int c=3)
//{
//	cout << a << b << c << endl;
//}
//
////错误的缺省参数演示
//void fun(int a = 10, int b=2, int c)
//{
//	cout << a << b << c << endl;
//}


//缺省参数不能在函数声明和定义中同时出现

//错误演示
//void fun(int a = 1);
//void fun(int a = 1)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	fun();
//	//程序会报错：“fun”: 重定义默认参数 
//	return 0;
//}


//正确做法：一般函数声明定义缺省，实现不用缺省
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
//// 1、参数类型不同
//int Add(int e1, int e2)
//{
//	return e1 + e2;
//}
//double Add(double e1, double e2)
//{
//	return e1 + e2;
//}
//// 2、参数个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//// 3、参数类型顺序不同
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
//	//参数类型不同
//	cout << Add(1, 2) << "  " << Add(3.14, 3.14) << endl;
//	//参数个数不同
//	f();
//	f(1);
//	//参数类型顺序不同
//	fun(1, 'b');
//	fun('b', 1);
//	return 0;
//}

//
//
//#include<iostream>
//using namespace std;
//
////C++刚开始的类
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
//	//公有方法
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
////私有属性
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
//	//构造函数  --》创建类的时候主动执行（不主动创建，编译器也会主动创建）
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
	//构造函数  --》创建类的时候主动执行（不主动创建，编译器也会主动创建）

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