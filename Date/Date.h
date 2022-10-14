#pragma once 
#include<iostream>
using namespace std;

class Date
{
	//��Ա����
	//�����
	friend ostream& operator<<(ostream& out, const Date&d); 
	//������
	friend istream& operator>>(istream& in, Date&d);
public:
	Date(int year = 1970, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// �������죬���ﲻ��ʽд��Ҳ����
	//Date(const Date&d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}

	//�������������ﲻдҲ����
	//~Date()
	//{
	//	_year = 0;
	//	_month = 0;
	//	_day = 0;
	//}
	int GetMonthDay(int year, int month)
	{
		static int MonthDayArry[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month==2 && (year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			return 29;
		}
		else
		{
			return MonthDayArry[month];
		}
	}

	bool operator==(Date&d)const;

	bool operator!=(Date&d)const;

	bool operator>(Date&d)const;

	bool operator>=(Date&d)const;

	bool operator<(Date&d)const;

	bool operator<=(Date&d)const;

	Date& operator+=(int day);

	Date& operator-=(int day);

	Date operator+(int day)const;

	Date operator-(int day)const;

	int operator-(Date&d)const;

	//ǰ��++
	Date& operator++();
	//����++
	Date operator++(int);

	//ǰ��--
	Date& operator--();
	//����--
	Date operator--(int);

	Date& operator=(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};