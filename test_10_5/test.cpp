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
//	// 1.无参构造函数
//	Date()
//	{}
//	// 2.带参构造函数
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
//	Date d1; // 调用无参构造函数
//	Date d2(2015, 1, 1); // 调用带参的构造函数
//
//	// 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
//	// 以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象
//	// warning C4930: “Date d3(void)”: 未调用原型函数(是否是有意用变量定义的?)
//	Date d3();
//}

//
//
//class Date
//{
//public:
//	
//	// 如果用户显式定义了构造函数，编译器将不再生成
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
//	// 将Date类中构造函数屏蔽后，代码可以通过编译，因为编译器生成了一个无参的默认构造函数
//		// 将Date类中构造函数放开，代码编译失败，因为一旦显式定义任何构造函数，编译器将不再生成
//		// 无参构造函数，放开后报错：error C2512: “Date”: 没有合适的默认构造函数可用
//		Date d1;
//	return 0;
//}
//


//class Date
//{
//public:
//	//全缺省
//	Date(int year=1, int month=1, int day=1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//无参
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
//	Date d1;//如果我不传参，编译器不知道该调用哪一个函数，就产生了二义性
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
//	// 基本类型(内置类型)
//	int _year=0;//注意这只是给默认值，并没有开辟空间，跟函数上的缺省可以类比
//	int _month=0;
//	int _day=0;
//	//// 自定义类型
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
//	char f;//接收+-*/
//	printf("请输入第一个数\n");
//	scanf("%d", &a);
//
//	printf("请输入第二个数\n");
//	scanf("%d", &b);
//
//	getchar();//清空缓存中的'\n'
//
//	printf("请输入执行的法则:+-*/ :");
//	scanf("%c", &f); //接收char类型的字符需要%c
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
//			printf("无效法则\n");
//			return 0;
//		}
//	printf("结果为%d\n", c);
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
//			perror("malloc申请空间失败!!!");
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
//	// 其他方法...
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
//	// 基本类型(内置类型)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}
// 程序运行结束后输出：~Time()
// 在main方法中根本没有直接创建Time类的对象，为什么最后会调用Time类的析构函数？
// 因为：main方法中创建了Date对象d，而d中包含4个成员变量，其中_year, _month, _day三个是
// 内置类型成员，销毁时不需要资源清理，最后系统直接将其内存回收即可；而_t是Time类对象，所以在
// d销毁时，要将其内部包含的Time类的_t对象销毁，所以要调用Time类的析构函数。但是：main函数
// 中不能直接调用Time类的析构函数，实际要释放的是Date类对象，所以编译器会调用Date类的析构函
// 数，而Date没有显式提供，则编译器会给Date类生成一个默认的析构函数，目的是在其内部调用Time
// 类的析构函数，即当Date对象销毁时，要保证其内部每个自定义对象都可以正确销毁
// main函数中并没有直接调用Time类析构函数，而是显式调用编译器为Date类生成的默认析构函数
// 注意：创建哪个类的对象则调用该类的析构函数，销毁那个类的对象则调用该类的析构函数


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


//错误
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

//正确写法
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
	//不好理解
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

	//前置++
	Date& operator++()
	{
		*this+=1;
		return *this;
	}

	//后置++
	Date operator++(int)
	{
		Date tem(*this);
		*this += 1;
		return tem;
	}

	//前置--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	//后置--
	Date operator--(int)
	{
		Date tem(*this);
		*this -= 1;
		return tem;
	}
	//d1-d2  日期类-日期类
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
	//Date d2(d1);//默认生成的拷贝构造
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
	//d2 = d1;//赋值重载
	//d2.Print();
	Date d2(2022, 10, 10);

	cout << (d2 - d1) << endl;
	cout << (d1 - d2) << endl;
	return 0;
}	