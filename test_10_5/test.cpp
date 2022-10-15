//#define _CRT_SECURE_NO_WARNINGS

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

//
//
//class Date
//{
//public:
//	Date(int year=1,int month=1,int day=1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//
//		if (_month > 12 || _month <1 || day> GetMonthDay(_year, _month) || day < 1)
//		{
//			cout << "非法日期" << endl;
//		}
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
//
//	bool operator<(const Date& d1)
//	{
//		return  !(*this > d1);
//	}
//
//	bool operator<=(const Date& d1)
//	{
//		return !(*this > d1)
//			|| *this == d1;
//	}
//
//	bool operator!=(const Date& d1)
//	{
//		return !(*this == d1);
//	}
//
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
//	Date operator+(int day)
//	{
//		Date d1(*this);
//		return d1 += day;
//	}
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

//	Date& operator-=(int day)
//	{
//		_day -= day;
//		while (_day<=0)
//		{
//			--_month;
//			if (_month == 0)
//			{
//				_year--;
//				_month = 12;
//			}
//			_day += GetMonthDay(_year, _month);
//		}
//		return *this;
//	}
//
//	Date operator-(int day)
//	{
//		Date d1(*this);
//		return d1 -= day;
//	}
//
//	//前置++
//	Date& operator++()
//	{
//		*this+=1;
//		return *this;
//	}
//
//	//后置++
//	Date operator++(int)
//	{
//		Date tem(*this);
//		*this += 1;
//		return tem;
//	}
//
//	//前置--
//	Date& operator--()
//	{
//		*this -= 1;
//		return *this;
//	}
//
//	//后置--
//	Date operator--(int)
//	{
//		Date tem(*this);
//		*this -= 1;
//		return tem;
//	}
//	//d1-d2  日期类-日期类
//	int operator-(const Date& d)
//	{
//		Date max = *this;
//		Date min = d;
//		int flag = 1;
//
//		if (*this < d)
//		{
//			max = d;
//			min = *this;
//			flag = -1;
//		}
//		int n = 0;
//		while (min != max)
//		{
//			++n;
//			++min;
//		}
//		return n * flag;
//	}
//
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
//	return out;
//}
//
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year;
//	in >> d._month;
//	in >> d._day;
//	return in;
//}
//
//int main()
//{
//	Date d1(2022, 10, 7);
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
	//Date d2(2022, 10, 40);

	//cout << (d2 - d1) << endl;
	//cout << (d1 - d2) << endl;
//	Date d3;
//	cin >> d2 >> d3;
//	cout << d2 << d3;
//	return 0;
//}
//


//class Date
//{
//public:
//	Date(int year = 1970, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// Date(const Date d) // 错误写法：编译报错，会引发无穷递归
//	Date(const Date& d) // 正确写法
//	{
//		cout << "Date(const Date& d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void DateTest1(Date d1)
//{
//	//传值，会发生拷贝构造
//}
//
//void DateTest2(Date& d)
//{
//	//传引用
//}
//int main()
//{
//	Date d1;
//	//Date d2(d1);
//	DateTest1(d1);
//	DateTest2(d1);
//	return 0;
//}


//class Time
//{
//public:
//	Time()
//	{
//		_hour = 1;
//		_minute = 1;
//		_second = 1;
//	}
//	Time(const Time& t)
//	{
//		_hour = t._hour;
//		_minute = t._minute;
//		_second = t._second;
//		cout << "Time::Time(const Time&)" << endl;
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
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
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
//	Date d1;
//	// 用已经存在的d1拷贝构造d2，此处会调用Date类的拷贝构造函数
//	// 但Date类并没有显式定义拷贝构造函数，则编译器会给Date类生成一个默认的拷贝构造函数
//	Date d2(d1);
//	d2.Print();
//	return 0;
//}



// 这里会发现下面的程序会崩溃掉？这里就需要以后讲的深拷贝去解决。
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	Stack s2(s1);
//	return 0;
//}
//
//// 全局的operator==
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// 这里会发现运算符重载成全局的就需要成员变量是公有的，那么问题来了，封装性该如何保证呢？
//// 这里其实可以用我们后面学习的友元解决，或者干脆重载成成员函数。
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//
//int main()
//{
//	Date d1(2022, 10, 15);
//	Date d2(2022, 10, 15);
//	//注意要加括号，因为<<的优先级高
//	cout << (d1 == d2) << endl;//其实这里编译器它会自动转换成operator==(d1,d2);
//	cout << operator==(d1, d2) << endl;//也可以显示写，但没必要，因为运算符重载就是要让可读性更高
//	return 0;
//}
//
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//Date& operator=(const Date&d)//赋值重载
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//	return *this;
//	//}
//	void Print()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//
//	Date d1(2022, 10, 15);
//	Date d2;
//	Date d3;
//	d2 = d1;//编译器会自动转化成d2.operator=(d1)
//	d2.operator=(d1);//也可以直接这样写，但是道理也一样，没必要
//	d3 = d2 = d1;//连续赋值，需要函数有返回值才能实现
//	d2.Print();
//	d3.Print();
//	return 0;
//}
//


//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	int _year;
//	int _month;
//	int _day;
//};
//// 赋值运算符重载成全局函数，注意重载成全局函数时没有this指针了，需要给两个参数
//Date& operator=(Date& left, const Date& right)
//{
//	if (&left != &right)
//	{
//		left._year = right._year;
//		left._month = right._month;
//		left._day = right._day;
//	}
//	return left;
//}
////编译错误
//// error C2801: “operator =”必须是非静态成员
//int main()
//{
//	Date d1(2022, 10, 15);
//	Date d2;
//	d2 = d2;
//	return 0;
//}

//class Time
//{
//public:
//	Time()
//	{
//		_hour = 1;
//		_minute = 1;
//		_second = 1;
//	}
//	Time& operator=(const Time& t)
//	{
//		cout << "Time& operator=(const Time& t)" << endl;
//		if (this != &t)
//		{
//			_hour = t._hour;
//			_minute = t._minute;
//			_second = t._second;
//		}
//		return *this;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	// 基本类型(内置类型)
//	int _year ;
//	int _month ;
//	int _day;
//	// 自定义类型
//	Time _t;
//};
//
//int main()
//{
//	Date d1(2022,10.15);
//	Date d2;
//	d2 = d1;
//	return 0;
//}


// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//			_size = 0;
//		_capacity = capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType *_array;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	Stack s2;
//	s2 = s1;
//	return 0;
//}


//
//class Date
//{
//public:
//	Date(int year = 1970, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// 前置++：返回+1之后的结果
//	// 注意：this指向的对象函数结束后不会销毁，故以引用方式返回提高效率
//	Date& operator++()
//	{
//		_day += 1;
//		return *this;
//	}
//	// 后置++：
//	// 前置++和后置++都是一元运算符，为了让前置++与后置++形成能正确重载
//	// C++规定：后置++重载时多增加一个int类型的参数，但调用函数时该参数不用传递，编译器
//	//自动传递
//		// 注意：后置++是先使用后+1，因此需要返回+1之前的旧值，故需在实现时需要先将this保存
//		//一份，然后给this + 1
//		// 而temp是临时对象，因此只能以值的方式返回，不能返回引用
//	Date operator++(int)
//	{
//		Date temp(*this);
//		_day += 1;
//		return temp;
//	}
//	void Print()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	//Date d1(2022, 10, 15);
//	//Date d2(d1);
//	//d1.Print();
//	//(d1++).Print();
//
//	//d2.Print();
//	//(++d2).Print();
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << "Print()" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//	void Print() const
//	{
//		cout << "Print()const" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//
//int main()
//{
//	Date d1(2022, 10, 15);
//	d1.Print();
//	const Date d2(2022, 10, 16);
//	d2.Print();
//}

class Date
{
public:
	Date* operator&()
	{
		cout << "Date* operator&()" << endl;

		return this;
	}
	const Date* operator&()const
	{
		cout << "const Date* operator&()const" << endl;
		return this;
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};

//这两个运算符一般不需要重载，使用编译器生成的默认取地址的重载即可，只有特殊情况，才需
//要重载，比如想让别人获取到指定的内容！

int main()
{
	Date d1;
	cout << &d1 << endl;
	const Date d2;
	cout << &d2 << endl;
	return 0;
}