#include"Date.h"

bool Date::operator==(Date&d)const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator!=(Date&d)const
{
	return !(*this == d);
}

bool Date::operator>(Date&d)const
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year && _month > d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator>=(Date&d)const
{
	return *this == d
		|| *this > d;
}

bool Date::operator<(Date&d)const
{
	return !(*this>=d);
}

bool Date::operator<=(Date&d)const
{
	return !(*this >d);
}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
		_day -= GetMonthDay(_year, _month);
	}
	return *this;
}

Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator+(int day)const
{
	Date tem(*this);

	tem += day;
	return tem;
}

Date Date::operator-(int day)const
{
	Date tem(*this);
	tem -= day;
	return tem;
}

int Date::operator-(Date&d)const
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++n;
		++min;
	}

	return n*flag;
}

//前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
//后置++
Date Date::operator++(int)
{
	Date tem(*this);
	*this += 1;
	return tem;
}

//前置--
Date& Date::operator--()
{
	return (*this -= 1);
}
//后置--
Date Date::operator--(int)
{
	Date tem(*this);
	*this -= 1;
	return tem;
}

Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;

	return *this;
}


ostream& operator<<(ostream& out, const Date&d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}

istream& operator>>(istream& in, Date&d)
{
	in >> d._year ;
	in >> d._month;
	in >> d._day;
	return in;
}