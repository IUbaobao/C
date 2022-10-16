

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
#include<string.h>
int main()
{
	char*p = "abc";
	cout << p << endl;
	cout << (void*)p << endl;
	cout << sizeof(p) << endl;
	cout << strlen(p) << endl;

	return 0;
}