#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.Init(2022, 10, 5);
//	d1.Print();
//	Date d2;
//	d2.Init(2022, 10, 6);
//	d2.Print();
//	return 0;
//}

//class Date
//{
//public:
//	// 1.�޲ι��캯��
//	Date()
//	{}
//	// 2.���ι��캯��
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void TestDate()
//{
//	Date d1; // �����޲ι��캯��
//	Date d2(2015, 1, 1); // ���ô��εĹ��캯��
//
//	// ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������
//	// ���´���ĺ�����������d3�������ú����޲Σ�����һ���������͵Ķ���
//	// warning C4930: ��Date d3(void)��: δ����ԭ�ͺ���(�Ƿ��������ñ��������?)
//	Date d3();
//}

//
//
//class Date
//{
//public:
//	
//	// ����û���ʽ�����˹��캯��������������������
//	Date(int year, int month, int day)
//	{
//	_year = year;
//	_month = month;
//	_day = day;
//	}
//	
//
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	// ��Date���й��캯�����κ󣬴������ͨ�����룬��Ϊ������������һ���޲ε�Ĭ�Ϲ��캯��
//		// ��Date���й��캯���ſ����������ʧ�ܣ���Ϊһ����ʽ�����κι��캯��������������������
//		// �޲ι��캯�����ſ��󱨴�error C2512: ��Date��: û�к��ʵ�Ĭ�Ϲ��캯������
//		Date d1;
//	return 0;
//}
//


//class Date
//{
//public:
//	//ȫȱʡ
//	Date(int year=1, int month=1, int day=1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//�޲�
//	Date()
//	{
//		_year = 0;
//		_month = 0;
//		_day = 0;
//	}
//
//	
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;//����Ҳ����Σ���������֪���õ�����һ���������Ͳ����˶�����
//	return 0;
//}







//
//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "-" << _month<<"-"<<_day << endl;
//	}
//private:
//	// ��������(��������)
//	int _year=0;//ע����ֻ�Ǹ�Ĭ��ֵ����û�п��ٿռ䣬�������ϵ�ȱʡ�������
//	int _month=0;
//	int _day=0;
//	//// �Զ�������
//	//Time _t;
//};
//int main()
//{
//	Date d;
//	d.Print();
//	return 0;
//	
//}

//
//#include<stdio.h>
//int main()
//{
//	int a, b,c;
//	char f;//����+-*/
//	printf("�������һ����\n");
//	scanf("%d", &a);
//
//	printf("������ڶ�����\n");
//	scanf("%d", &b);
//
//	getchar();//��ջ����е�'\n'
//
//	printf("������ִ�еķ���:+-*/ :");
//	scanf("%c", &f); //����char���͵��ַ���Ҫ%c
//
//		switch (f)
//		{
//		case '+':
//			c = a + b;
//			break;
//		case '-':
//			c = a - b;
//			break;
//
//		case '*':
//			c = a * b;
//			break;
//
//		case '/':
//			c = a / b;
//			break;
//
//		default:
//			printf("��Ч����\n");
//			return 0;
//		}
//	printf("���Ϊ%d\n", c);
//	return 0;
//}
//


//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc����ռ�ʧ��!!!");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	// ��������...
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//int main()
//{
//	Stack s;
//	s.Push(1);
//	s.Push(2);
//	return 0;
//}

//
//class Time
//{
//public:
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// ��������(��������)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// �Զ�������
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}
// �������н����������~Time()
// ��main�����и���û��ֱ�Ӵ���Time��Ķ���Ϊʲô�������Time�������������
// ��Ϊ��main�����д�����Date����d����d�а���4����Ա����������_year, _month, _day������
// �������ͳ�Ա������ʱ����Ҫ��Դ�������ϵͳֱ�ӽ����ڴ���ռ��ɣ���_t��Time�����������
// d����ʱ��Ҫ�����ڲ�������Time���_t�������٣�����Ҫ����Time����������������ǣ�main����
// �в���ֱ�ӵ���Time�������������ʵ��Ҫ�ͷŵ���Date��������Ա����������Date���������
// ������Dateû����ʽ�ṩ������������Date������һ��Ĭ�ϵ�����������Ŀ���������ڲ�����Time
// �����������������Date��������ʱ��Ҫ��֤���ڲ�ÿ���Զ�����󶼿�����ȷ����
// main�����в�û��ֱ�ӵ���Time������������������ʽ���ñ�����ΪDate�����ɵ�Ĭ����������
// ע�⣺�����ĸ���Ķ�������ø�������������������Ǹ���Ķ�������ø������������


//
//class Date
//{
//public:
//	Date(int year=1,int month=1,int day=1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	bool operator==(const Date& d1)
//	{
//		return _year == d1._year
//			&& _month == d1._month
//			&& _day == d1._day;
//	}
//	
//	bool operator>(const Date& d1)
//	{
//		if (_year > d1._year)
//		{
//			return true;
//		}
//		else if (_year == d1._year && _month > d1._month)
//		{
//			return true;
//		}
//		else if (_year == d1._year && _month == d1._month && _day > d1._day)
//		{
//			return true;
//		}
//		
//		return false;
//	}
//	bool operator>=(const Date& d1)
//	{
//		return *this > d1
//			|| *this == d1;
//	}
//	int GetMonthDay(int year, int month)
//	{
//		static int MonthDayArr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		if ( month==2 &&((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
//		{
//			return 29;
//		}
//		return MonthDayArr[month];
//	}
//
//	Date& operator+=(int day)
//	{
//		_day += day;
//		while (_day > GetMonthDay(_year,_month))
//		{
//			_day -= GetMonthDay(_year, _month);
//			_month++;
//			if (_month == 13)
//			{
//				_year++;
//				_month = 1;
//			}
//		}
//		return *this;
//	}
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2022,9,22);
////	Date d2(2022, 10, 7);
//
//	//cout << (d1 == d2) << endl;
////	cout << (d1 >= d2) << endl;
//
//	d1 += 50;
//
//
//	return 0;
//}


//����
//#include <iostream>
//using namespace std;
//int r(cin >> int x);
//
//int main()
//{
//    r(6);
//    cout << r << endl;
//}
//int r(cin >> int x)
//{
//    return 2 * x;
//}

//��ȷд��
//#include <iostream>
//using namespace std;
//int r(int x);
//
//int main()
//{
//    r(6);
//    int x;
//        cin >> x;
//    cout << x << endl;
//    cout << r << endl;
//}
//int r(int x)
//{
//    return 2 * x;
//}



class Date
{
public:
	Date(int year=1,int month=1,int day=1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool operator==(const Date& d1)
	{
		return _year == d1._year
			&& _month == d1._month
			&& _day == d1._day;
	}
	
	bool operator>(const Date& d1)
	{
		if (_year > d1._year)
		{
			return true;
		}
		else if (_year == d1._year && _month > d1._month)
		{
			return true;
		}
		else if (_year == d1._year && _month == d1._month && _day > d1._day)
		{
			return true;
		}
		
		return false;
	}
	bool operator>=(const Date& d1)
	{
		return *this > d1
			|| *this == d1;
	}

	bool operator<(const Date& d1)
	{
		return  !(*this > d1);
	}

	bool operator<=(const Date& d1)
	{
		return !(*this > d1)
			|| *this == d1;
	}

	bool operator!=(const Date& d1)
	{
		return !(*this == d1);
	}

	int GetMonthDay(int year, int month)
	{
		static int MonthDayArr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if ( month==2 &&((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		return MonthDayArr[month];
	}

	Date& operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year,_month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
	Date operator+(int day)
	{
		Date d1(*this);
		return d1 += day;
	}
	//�������
	//Date& operator-=(int day)
	//{
	//	_day -= day;
	//	while (_day<=0)
	//	{
	//		--_month;
	//		if (_month == 0)
	//		{
	//			_year--;
	//			_month = 12;
	//		}
	//		_day += GetMonthDay(_year, _month);
	//	}
	//	return *this;
	//}

	Date& operator-=(int day)
	{
		_day -= day;
		while (_day<=0)
		{
			--_month;
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

	Date operator-(int day)
	{
		Date d1(*this);
		return d1 -= day;
	}

	//ǰ��++
	Date& operator++()
	{
		*this+=1;
		return *this;
	}

	//����++
	Date operator++(int)
	{
		Date tem(*this);
		*this += 1;
		return tem;
	}

	//ǰ��--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	//����--
	Date operator--(int)
	{
		Date tem(*this);
		*this -= 1;
		return tem;
	}
	//d1-d2  ������-������
	int operator-(const Date& d)
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
		return n * flag;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2022, 10, 7);
	//Date d2(d1);//Ĭ�����ɵĿ�������
	//d2.Print();
	//Date d2(2022, 10, 8);
	//cout << (d1 != d2) << endl;

	//Date d3 = d1 + 1000;
	//d3.Print();

	//d3 -= 1000;
	//d3.Print();

	//Date d4 = d2 - 1;
	//d4.Print();
	//(d1++).Print();
	//(++d1).Print();
	//(d1--).Print();
	//(--d1).Print();
	
	//Date d2;
	//d2 = d1;//��ֵ����
	//d2.Print();
	Date d2(2022, 10, 10);

	cout << (d2 - d1) << endl;
	cout << (d1 - d2) << endl;
	return 0;
}	