

//������������ڣ���������һ��ĵڼ��졣
//��֤���Ϊ4λ�������ںϷ���
//���ף�ʱ�临�Ӷȣ�O(n)\O(n) ���ռ临�Ӷȣ�O(1)\O(1)
//����������
//����һ�У�ÿ�пո�ָ�ֱ����꣬�£���
//
//���������
//�������һ��ĵڼ���
//ʾ��1
//���룺
//2012 12 31
//����
//�����
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


//����
//���������ڣ�����������֮�������������������������������ǹ涨����֮�������Ϊ����
//����������
//�ж������ݣ�ÿ�����������У��ֱ��ʾ�������ڣ���ʽΪYYYYMMDD
//���������
//ÿ���������һ�У������ڲ�ֵ
//ʾ��1
//���룺
//20110412
//20110422
//����
//�����
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
//	//��ȡ����
//	day1 = n1 % 100, month1 = (n1 / 100) % 100, year1 = n1 / 10000;
//	day2 = n2 % 100, month2 = (n2 / 100) % 100, year2 = n2 / 10000;
//	//�ҳ��ϴ�ͽ�С������
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
//	//��С�����ڼ�+1��ֱ�������������
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
//����
//�������m��һ���еĵ�n�죬�����n���Ǽ��¼��š�
//����������
//���������������y(1 <= y <= 3000)��n(1 <= n <= 366)��
//���������
//�����ж���������ݣ�����ÿ�����ݣ� �� yyyy - mm - dd�ĸ�ʽ�������ж�Ӧ�����ڴ�ӡ������
//ʾ��1
//���룺
//2000 3
//2000 31
//2000 40
//2000 60
//2000 61
//2001 60
//����
//�����
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

//����
//���һ�������ܼ���һ�����ڼ������������ʲô���ڡ�
//����������
//�����һ�б�ʾ��������m��������m��ÿ���ĸ������ֱ��ʾ�����պ��ۼӵ�������
//���������
//���m�У�ÿ�а�yyyy - mm - dd�ĸ��������
//ʾ��1
//���룺
//1
//2008 2 3 100
//����
//�����
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