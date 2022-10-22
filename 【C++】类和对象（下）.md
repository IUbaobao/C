@[TOC](文章目录)



---

# 1. 再谈构造函数 

## 1.1 构造函数体赋值 



在之前的章节中我们在创建对象时，编译器通过调用构造函数，给对象中各个成员变量一个合适的初始值  

```cpp
class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

```

 

> 虽然上述构造函数调用之后，对象中已经有了一个初始值，但是不能将其称为对对象中成员变量
> 的初始化，构造函数体中的语句只能将其称为赋初值，而不能称作初始化。因为初始化只能初始
> 化一次，而构造函数体内可以多次赋值。  



## 1.2 初始化列表



**作用：**

C++提供了初始化列表语法，用来初始化属性



**语法：**`构造函数()：属性1(值1),属性2（值2）... {}`



>初始化列表：以一个冒号开始，接着是一个以逗号分隔的数据成员列表，每个"成员变量"后面跟
>一个放在括号中的初始值或表达式。  



```cpp
class Date
{
public:
	////传统方式初始化
	//Date(int year, int month, int day)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

	//初始化列表方式初始化
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
```





==【注意】==

1. **每个成员变量在初始化列表中只能出现一次(初始化只能初始化一次)**

2. 类中包含以下成员，必须放在初始化列表位置进行初始化：
   **引用成员变量****
   **const成员变量**
   **自定义类型成员(且该类没有默认构造函数时)**  

3. **尽量使用初始化列表初始化，因为不管你是否使用初始化列表，对于自定义类型成员变量，
   一定会先使用初始化列表初始化**。  

4. **成员变量**在类中**声明次序**就是其在初始化列表中的**初始化顺序**，**与其在初始化列表中的先后
   次序无关  **





## 1.3 explicit关键字  



构造函数不仅可以构造与初始化对象，**对于单个参数或者除第一个参数无默认值其余均有默认值
的构造函数，还具有类型转换的作用**  



```cpp
class Date
{
public:
    // 1. 单参构造函数，没有使用explicit修饰，具有类型转换作用
	// explicit修饰构造函数，禁止类型转换---explicit加上去后，这段代码不可以通过编译
    //explicit  Date(int year)
	//	:_year(year)
	//{}
	 Date(int year)
		:_year(year)
	{}
	// 2. 虽然有多个参数，但是创建对象时后两个参数可以不传递，没有使用explicit修饰，具
	//有类型转换作用
	// explicit修饰构造函数，禁止类型转换
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2022);
	// 用一个整形变量给日期类型对象赋值
	// 实际编译器背后会用2023构造一个无名对象，最后用无名对象给d1对象进行赋值
	d1 = 2023;
    // 将1加上explicit编译就会失败，因为explicit修饰构造函数，禁止了单参构造函数类型转
	//换的作用
	return 0;
}

/////////////////////////////////////
class Data
{
public:
	Data(int year=1970,int month=0,int day=0)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Data()" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d1 = 1;
	Data d2 = { 2022, 10, 21 };//C++11支持类型转化的多参数构造、
    //结果上跟Data d2(2022,10,21)一样，实际上，上面会存在构造+拷贝构造，而这一行只存在构造
	return 0;
}
```

>上述代码可读性不是很好，用explicit修饰构造函数，将会禁止构造函数的隐式转换  





---



# 2. 静态成员



## 2.1概念  



声明为static的类成员称为类的静态成员，用static修饰的成员变量，称之为静态成员变量；用
static修饰的成员函数，称之为静态成员函数。静态成员变量一定要在类外进行初始化  



## 2.2 特性  



静态成员分为：



*  静态成员变量
   *  静态成员为所有类对象所共享，不属于某个具体的对象，存放在静态区  (所有对象共享同一份数据)
   *  在编译阶段分配内存
   *  静态成员变量必须在类外定义，定义时不添加static关键字，类中只是声明  (类内声明，类外初始化)
   *  类静态成员即可用 类名::静态成员 或者 对象.静态成员 来访问  
   *  静态成员也是类的成员，受public、protected、private 访问限定符的限制  
*  静态成员函数
   *  所有对象共享同一个函数
   *  静态成员函数没有隐藏的this指针，不能访问任何非静态成员 (静态成员函数只能访问静态成员变量) 





-----



# 3. 友元friend 

生活中你的家有客厅(Public)，有你的卧室(Private)

客厅所有来的客人都可以进去，但是你的卧室是私有的，也就是说只有你能进去

但是呢，你也可以允许你的好闺蜜好基友进去。



在程序里，有些私有属性 也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术



友元的目的就是让一个函数或者类 访问另一个类中私有成员



友元的关键字为  ==friend==



友元的三种实现

* 全局函数做友元
* 类做友元
* 成员函数做友元



友元提供了一种突破封装的方式，有时提供了便利。但是友元会增加耦合度，破坏了封装，所以
友元不宜多用。
友元分为：友元函数和友元类   





## 3.1 友元函数 



 友元函数的其中一种应用情况：

>现在尝试去重载operator<<，然后发现没办法将operator<<重载成成员函数。因为cout的
>输出流对象和隐含的this指针在抢占第一个参数的位置。this指针默认是第一个参数也就是左操作
>数了。但是实际使用中cout需要是第一个形参对象，才能正常使用。所以要将operator<<重载成
>全局函数。但又会导致类外没办法访问成员，此时就需要友元来解决。operator>>同理。  



```cpp
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	// d1 << cout; -> d1.operator<<(&d1, cout); 不符合常规调用
	// 因为成员函数第一个参数一定是隐藏的this，所以d1必须放在<<的左侧
	ostream& operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-" << _day << endl;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
};
```



**友元函数**可以直接**访问类的私有成员**，它是**定义在类外部的普通函数**，不属于任何类，但需要在
类的**内部声明**，声明时需要加**friend关键字**。  





```cpp
class Date
{
	//友元声明（可在类中的任意位置声明，不包括成员函数体内）
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);
public:
	Date(int year = 1970, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}
int main()
{
	Date d;
	cin >> d;
	cout << d << endl;
	return 0;
}
```







![image-20221021174019113](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210211741453.png)







==【注意】==

1. **友元函数可访问类的私有和保护成员**，但不是类的成员函数

2. 友元函数**不能用const修饰**

3. 友元函数可以在类定义的任何地方声明，不受类访问限定符限制

4. **一个函数**可以是**多个类**的**友元函数**

5. 友元函数的调用与普通函数的调用原理相同  







## 3.2 友元类  



友元类的所有成员函数都可以是另一个类的友元函数，都可以访问另一个类中的非公有成员。

+ 友元关系是单向的，不具有交换性。
  比如上述Time类和Date类，在Time类中声明Date类为其友元类，那么可以在Date类中直接
  访问Time类的私有成员变量，但想在Time类中访问Date类中私有的成员变量则不行。

+ 友元关系不能传递
  如果C是B的友元， B是A的友元，则不能说明C时A的友元。  
+ 友元关系不能继承 (继承后面章节再学习)





```cpp
class Time
{
	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	void SetTimeOfDate(int hour, int minute, int second)
	{
		// 直接访问时间类私有的成员变量
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
```





---



#   4. 一些特别的语法

## 4.1 内部类

### 

概念：**如果一个类定义在另一个类的内部**，这个内部类就叫做**内部类**。内部类是一个独立的类，
它不属于外部类，更不能通过外部类的对象去访问内部类的成员。外部类对内部类没有任何优越
的访问权限。
==【注意】==：**内部类就是外部类的友元类**，参见友元类的定义，内部类可以通过外部类的对象参数来访
问外部类中的所有成员。但是外部类不是内部类的友元。  



特性 ：

1. 内部类可以定义在外部类的public、protected、private都是可以的。

2. 注意内部类可以直接访问外部类中的static成员，不需要外部类的对象/类名。

3. sizeof(外部类)=外部类，和内部类没有任何关系  



```cpp
class stu
{
public:
	class cat
	{
	private:
		int age;
		char name[10];
	};
private:
	int age;
	char name[10];
};

int main()
{
	cout << sizeof(stu) << endl;
	cout << sizeof(stu::cat) << endl;
	return 0;
}
```



![image-20221021192050593](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210211920638.png)





## 4.2 匿名对象 



**C++有匿名对象，只在当行代码有用，离开当行代码将立即析构!!!**



**匿名对象**可以理解为是**一个临时对象**，一般系统自动生成的，如你的函数返回一个对象，这个对象在返回时会生成一个临时对象。 



```cpp
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};
class Solution {
public:
	int Sum_Solution(int n) {
		//...
		return n;
	}
};
int main()
{
	A aa1;
	// 不能这么定义对象，因为编译器无法识别下面是一个函数声明，还是对象定义
	//A aa1();
	// 但是我们可以这么定义匿名对象，匿名对象的特点不用取名字，
	// 但是他的生命周期只有这一行，我们可以看到下一行他就会自动调用析构函数
	A();
	A aa2(2);
	// 匿名对象在这样场景下就很好用，当然还有一些其他使用场景
	Solution().Sum_Solution(10);
	return 0;
}
```





![image-20221021192843111](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210211928224.png)







---



# 5. 拷贝对象时的一些编译器优化  



在传参和传返回值的过程中，一般编译器会做一些优化，减少对象的拷贝，这个在一些场景下还
是非常有用的。  



```cpp
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}
	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};
void f1(A aa)
{}
A f2()
{
	A aa;
	return aa;
}
int main()
{
	A a1 = 1; //A tem(1) + A a1(tem) -> 优化 A a1(1)
	cout << endl;

	// 传值传参
	A aa1;
	f1(aa1);//f1中的临时aa拷贝构造aa1，而且具有常属性const
	cout << endl;

	// 传值返回
	f2();//同理，f2中的aa是传值返回，也要拷贝构造一个临时对象返回，也具有常属性const
	cout << endl;

	// 一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造
	A ret = f2();
    //下面这种情况就无法优化了
	//A ret;
	//ret = f2();
	cout << endl;

	// 一个表达式中，连续拷贝构造+赋值重载->无法优化
	aa1 = f2();
	cout << endl;
	return 0;
}
```





![image-20221021201023088](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210212010146.png)

![image-20221021200810714](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210212008790.png)

----

