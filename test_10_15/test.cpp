

//根据输入的日期，计算是这一年的第几天。
//保证年份为4位数且日期合法。
//进阶：时间复杂度：O(n)\O(n) ，空间复杂度：O(1)\O(1)
//输入描述：
//输入一行，每行空格分割，分别是年，月，日
//
//输出描述：
//输出是这一年的第几天
//示例1
//输入：
//2012 12 31
//复制
//输出：
//366
//#include <iostream>
//using namespace std;
//
//int main() {
//	int year, month, day;
//	cin >> year >> month >> day;
//	static int GetMontDayArry[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int n = 0;
//	for (int i = 1; i<month; i++)
//	{
//		n += GetMontDayArry[i];
//	}
//	n += day;
//
//	if (month>2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//	{
//		++n;
//	}
//	cout << n << endl;
//}


//描述
//有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天
//输入描述：
//有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
//输出描述：
//每组数据输出一行，即日期差值
//示例1
//输入：
//20110412
//20110422
//复制
//输出：
//11
//#include<iostream>
//using namespace std;
//
//int GetMontDay(int year, int month)
//{
//	static int GetMonthDayArry[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
//	{
//		return 29;
//	}
//	else
//	{
//		return GetMonthDayArry[month];
//	}
//}
//
//
//int main()
//{
//	int n1, n2;
//	cin >> n1 >> n2;
//	int year1, month1, day1, year2, month2, day2;
//	//获取日期
//	day1 = n1 % 100, month1 = (n1 / 100) % 100, year1 = n1 / 10000;
//	day2 = n2 % 100, month2 = (n2 / 100) % 100, year2 = n2 / 10000;
//	//找出较大和较小的日期
//	int maxyear = year1, maxmonth = month1, maxday = day1;
//	int minyear = year2, minmonth = month2, minday = day2;
//	if (maxyear<minyear || (maxyear == minyear && maxmonth<minmonth)
//		|| (maxyear == minyear && maxmonth == minmonth && maxday<minday))
//	{
//		maxyear = year2, maxmonth = month2, maxday = day2;
//		minyear = year1, minmonth = month1, minday = day1;
//	}
//
//	int n = 0;
//	//把小的日期加+1，直到与大的日期相等
//	while (maxyear != minyear || maxmonth != minmonth || maxday != minday)
//	{
//		n++;
//		minday++;
//		if (minday> GetMontDay(minyear, minmonth))
//		{
//			minmonth++;
//			minday = 1;
//		}
//		if (minmonth == 13)
//		{
//			minyear++;
//			minmonth = 1;
//		}
//	}
//	n++;
//	cout << n << endl;
//
//	return 0;
//}

//
//#include<iostream>
//using namespace std;
//
//class sum
//{
//public:
//	sum()
//	{
//		n++;
//	}
//
//	static int n;
//};
//
//int sum::n = 0;
//
//int main()
//{
//	int k;
//	cin >> k;
//	//sum arr[k];
//	sum arr[10];
//	cout << sum::n << endl;
//	return 0;
//}



//
//描述
//给出年分m和一年中的第n天，算出第n天是几月几号。
//输入描述：
//输入包括两个整数y(1 <= y <= 3000)，n(1 <= n <= 366)。
//输出描述：
//可能有多组测试数据，对于每组数据， 按 yyyy - mm - dd的格式将输入中对应的日期打印出来。
//示例1
//输入：
//2000 3
//2000 31
//2000 40
//2000 60
//2000 61
//2001 60
//复制
//输出：
//2000 - 01 - 03
//2000 - 01 - 31
//2000 - 02 - 09
//2000 - 02 - 29
//2000 - 03 - 01
//2001 - 03 - 01
//#include <iostream>
//#include<stdio.h>
//using namespace std;
//
//
//int GetMontDay(int year, int month)
//{
//	static int GetMonthDayArry[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
//	{
//		return 29;
//	}
//	else
//	{
//		return GetMonthDayArry[month];
//	}
//}
//
//int main()
//{
//	int year, day;
//
//	while (cin >> year >> day)
//	{
//		int month = 1;
//		while (day>GetMontDay(year, month))
//		{
//			day -= GetMontDay(year, month);
//			month++;
//			if (month == 13)
//			{
//				year++;
//				month = 1;
//			}
//		}
//		printf("%d-%0.2d-%0.2d\n", year, month, day);
//
//	}
//	return 0;
//}

//描述
//设计一个程序能计算一个日期加上若干天后是什么日期。
//输入描述：
//输入第一行表示样例个数m，接下来m行每行四个整数分别表示年月日和累加的天数。
//输出描述：
//输出m行，每行按yyyy - mm - dd的个数输出。
//示例1
//输入：
//1
//2008 2 3 100
//复制
//输出：
//2008 - 05 - 13

#include <iostream>
using namespace std;
//
//int GetMontDay(int year, int month)
//{
//	static int GetMonthDayArry[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
//	{
//		return 29;
//	}
//	else
//	{
//		return GetMonthDayArry[month];
//	}
//}
//
//int main() {
//	int m;
//	cin >> m;
//	for (int i = 0; i<m; i++)
//	{
//		int year, month, day, n;
//		cin >> year >> month >> day >> n;
//
//		day += n;
//		while (day>GetMontDay(year, month))
//		{
//			day -= GetMontDay(year, month);
//			month++;
//			if (month == 13)
//			{
//				year++;
//				month = 1;
//			}
//		}
//		printf("%d-%0.2d-%0.2d\n", year, month, day);
//	}
//	return 0;
//}
//#include<string.h>
//int main()
//{
//	char*p = "abc";
//	cout << p << endl;
//	cout << (void*)p << endl;
//	cout << sizeof(p) << endl;
//	cout << strlen(p) << endl;
//
//	return 0;
//}
/////////////////////////////////////////////////////////////////////
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 10000; i <= 99999; i++)
//	{
//		//判断i是否为lily number
//		int j = 10;
//		int sum = 0;
//		int tmp = i;
//		for (j = 10; j <= 10000; j *= 10)
//		{
//			sum += (tmp%j)*(tmp / j);
//		}
//		if (sum == i)
//			printf("%d ", i);
//	}
//	return 0;
//}


//
//double fact(int a)
//{
//	int j = 1;
//	double sum = 1;
//	for (j = 1; j <= a; j++)
//	{
//		sum = sum * j;
//	}
//	return sum;
//}
//int main()
//{
//	double i = 0;
//	double sum = 1;
//	double a = 0;
//	int b = 1;
//	double c = 1;
//	double d = 0;
//	scanf("%lf", &i);
//	do
//	{
//		a = pow(i, b);
//		c = fact(b);
//		d = a / c;
//		sum = sum + d;
//		b++;
//	} while (fabs(d) >= 0.00001);
//	printf("s=%lf", sum);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int n, i, j, k;
//	cin >> n;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = i; j <= n; j++)                    
//		{
//			for (k = j; k <= n; k++)              
//			{
//				if (i*i + j*j == k*k && k>=150 && k<=160)           
//					cout << k  << endl;
//			}
//		}
//	}
//	return 0;
//}
//
//


//int main()
//{
//	int n = 0;
//	int i = 1;
//	int arr[10] = { 0 };
//
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int j = 1;
//	scanf("%d", &n);
//	printf("NO1:%d\n",n);
//	for (c = b + 1; c < 1000; c++)
//	{
//		for (a = 1; a<1000; a++)
//		{
//			for (b = a + 1; b<1000; b++)
//			{
//				if (a * a + b * b == c * c && c > n&&i<=10)
//				{
//					arr[i - 1] = c;
//					i++;
//				}
//			}
//		}
//	}
//	
//	int tem = 0;
//	i = 1;
//	for (j = 0; j < 10; j++)
//	{
//		if (arr[j] != tem)
//		{
//			printf("NO%d:%d\n", ++i, arr[j]);
//			tem = arr[j];
//		}
//		if (i == 4)
//		{
//			break;
//		}
//	}
//	return 0;
//}
//

//
//#include<stdio.h>
//int main()
//{
//	double sum = 0;
//	int n = 0;
//	scanf("%d", &n);
//	double a = 2.0;
//	double b = 1.0;
//	for (int i = 0; i < n; i++)
//	{
//		double tem = a;//保存分母
//		sum += a / b;//求和
//		//迭代往后
//		a += b;
//		b = tem;//前一个分母为后一个分子
//	}
//	printf("%0.2lf\n", sum);
//	return 0;
//}


//
//
//long double zi(int a)
//{
//	double sum = 0;
//	int i = 0;
//	double b = 1;
//	double c = 2;
//	i = 3;
//	if (a == 1)
//	{
//		return b;
//	}
//	else if (a == 2)
//		return c;
//	if (a >= 3)
//	{
//		for (i = 3; i <= a; i++)
//		{
//			sum = b + c;
//			b = c;
//			c = sum;
//		}
//		return sum;
//	}
//}
//int main()
//{
//	int i = 0;
//	long double sum = 0;
//	int a = 0;
//	long  double b = 0;
//	long double c = 0;
//	long double d = 0;
//	scanf("%d", &i);
//
//
//	for (a = 1; a <= i; a++)
//	{
//		b = zi(a + 1);
//		c = zi(a);
//		d = b / c;
//		sum = sum + d;
//	}
//	printf("s=%.2f", sum);
//	return 0;
//}




//
//#include<math.h>
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int i = 1;
//	int j = 2;
//	scanf("%d%d", &m, &n);
//	while (i <= n)
//	{
//		int flag = 0;//标志
//		for (j = 2; j <= sqrt(m); j++)
//		{
//			if (m % j == 0)
//			{
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0)
//		{
//			printf("%d\n", m);
//			i++;
//		}
//		m--;
//
//	}
//	return 0;
//}


//#include<math.h>
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int i = 1;
//	int j = 2;
//	scanf("%d%d", &m, &n);
//	while (i <= n)
//	{
//		for (j = 2; j<sqrt(m); j++)
//		{
//			if (m % j == 0)
//			{
//				m--;
//				j = 1;
//				continue;
//			}
//		}
//		printf("%d\n", m);
//		m--;
//		i++;
//	}
//}
//////////////////////////////////////////////////////////

//
//#include<iostream>
//using namespace std;
//int main()
//{
//	int* pa = new int(10);
//	int *pb = new int[10]{1,3,4};
//
//	delete pa;
//	delete[] pb;
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间
//	//还会调用构造函数和析构函数
//		A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1);
//	free(p1);
//	delete p2;
//	// 内置类型是几乎是一样的
//	int* p3 = (int*)malloc(sizeof(int)); // C
//	int* p4 = new int;
//	free(p3);
//	delete p4;
//	A* p5 = (A*)malloc(sizeof(A) * 10);
//	A* p6 = new A[10];
//	free(p5);
//	delete[] p6;
//	return 0;
//}


//如何实现一个通用的交换函数呢??
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
//写法麻烦
//1. 重载的函数仅仅是类型不同，代码复用率比较低，只要有新类型出现时，就需要用户自己增加对应的函
//数
//2. 代码的可维护性比较低，一个出错可能所有的重载均出错


//模板
//template<typename T>
//void Swap(T&left, T&right)
//{
//	T tem = left;
//	left = right;
//	right = tem;
//}

//int main()
//{
//	int a = 10, b = 20;
//	double c = 1.1, d = 2.2;
//	cout << a << "-" << b << endl;
//	cout << c << "-" << d << endl;
//
//	Swap(a, b);
//	Swap<int>(a, b);
//
//	Swap(c, d);
//
//	cout << a << "-" << b << endl;
//	cout << c << "-" << d << endl;
//	Swap<int>(a, b);
//
//	cout << a << "-" << b << endl;
//
//	return 0;
//}
