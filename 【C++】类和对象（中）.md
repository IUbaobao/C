@[TOC](文章目录)



----





# 1. 类的6个默认成员函数   



在上一章我们提到如果一个类中什么成员都没有，简称为空类 。

而且空类的大小为1个字节，那空类中真的什么都没有吗？

并不是，任何类在什么都不写时，**编译器会自动生成以下6个默认成员
函数**  

默认成员函数：**用户没有显式实现，编译器会生成的成员函数称为默认成员函数**。

> 这里的显示实现是如果用户在一个工程中用代码写出来的都叫显示实现。





![image-20221005190911228](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210051909646.png)

----





# 2. 对象的初始化和清理



*  生活中我们买的电子产品都基本会有出厂设置，在某一天我们不用时候也会删除一些自己信息数据保证安全
*  C++中的面向对象来源于生活，每个对象也都会有初始设置以及 对象销毁前的清理数据的设置。

对象的**初始化和清理**也是两个非常重要的安全问题

​	一个对象或者变量没有初始状态，对其使用后果是未知

​	同样的使用完一个对象或变量，没有及时清理，也会造成一定的安全问题



c++利用了**构造函数**和**析构函数**解决上述问题，这两个函数将会被编译器自动调用，完成对象初始化和清理工作。

对象的初始化和清理工作是编译器强制要我们做的事情，因此如果**我们不提供构造和析构，编译器会提供**





----





## 2.1构造函数  



### 2.1.1概念  

构造函数：**主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用**。





这究竟是怎么一回事呢？

我们来看这样的一个例子：对于以下Date类  



```cpp
class Date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	d1.Init(2022, 10, 5);
	d1.Print();
	Date d2;
	d2.Init(2022, 10, 6);
	d2.Print();
	return 0;
}
```



对于Date类，可以通过 Init 公有方法给对象设置日期，但如果每次创建对象时都调用该方法设置
信息，未免有点麻烦，那能否在对象创建时，就将信息设置进去呢？  

**构造函数**是一个**特殊的成员函数**，名字与类名相同,**创建类类型对象时由编译器自动调用**，以保证
每个数据成员都有 一个合适的初始值，**并且在对象整个生命周期内只调用一次** 



----



### 2.1.2特性  



**构造函数是特殊的成员函数**	，需要注意的是，构造函数虽然名称叫构造，但是构造函数的主要任
务**并不是开空间创建对象，而是初始化对象**。  

  **造函数语法：**`类名(){}`

其特征如下：

1. **构造函数，没有返回值也不写void**
2. **函数名称与类名相同**
3. **对象实例化时编译器自动调用对应的构造函数  ，无须手动调用,而且只会调用一次**
4. **构造函数可以有参数，因此可以发生重载**

上面的date类就可以写下面的样子

```cpp
class Date
{
public:
	// 1.无参构造函数
	Date()
	{}
	// 2.带参构造函数
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
void TestDate()
{
	Date d1; // 调用无参构造函数
	Date d2(2015, 1, 1); // 调用带参的构造函数
    
     //以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象
	Date d3();// warning C4930: “Date d3(void)”: 未调用原型函数(是否是有意用变量定义的?)
}
```

==注意==：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明

5. **如果类中没有显式定义构造函数，则C++编译器会自动生成一个无参的默认构造函数，一旦
   用户显式定义编译器将不再生成**。  



```cpp
class Date
{
public:
	/*
	// 如果用户显式定义了构造函数，编译器将不再生成
	Date(int year, int month, int day)
	{
	_year = year;
	_month = month;
	_day = day;
	}
	*/
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	// 将Date类中构造函数屏蔽后，代码可以通过编译，因为编译器生成了一个无参的默认构造函数
		Date d1;
	return 0;
}

```





![image-20221005194355774](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210051943840.png)

上述代码如果将Date类中构造函数放开，代码编译失败，因为一旦显式定义任何构造函数，编译器将不再生成

无参构造函数，放开后报错：error C2512: “Date”: 没有合适的默认构造函数可用，这是为什么呢？

> 解释上面的为什么其实我相信大部分朋友都知道，就是因为我们上面自己定义的构造函数是需要传参数的，
>
> 但我想说的是这里的默认构造函数又是什么意思呢？



6. **无参**的构造函数和**全缺省**的构造函数都称为**默认构造函数**，并且**默认构造函数只能有一个**。
   注意：无参构造函数、全缺省构造函数、我们没写编译器默认生成的构造函数，都可以认为
   是默认构造函数。  （用一句话就是“**不传参数可以调用的构造函数，就叫默认构造函数**”）



问题来了，为什么默认构造只能有一个呢？

原因也很简单，我们在学函数重载的时候就提过，无参的和全缺省的函数重载虽然语法上是正确的，

但是在调用的时候可能会出现**二义性**



![image-20221005195803244](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210051958284.png)







我们来看构造最后的一个特性，我们提过如果不写构造函数，编译器会默认给我们生成一个构造函数

那看下面代码

```cpp
class Date
{
public:
	void Print()
	{
		cout << _year << "-" << _month<<"-"<<_day << endl;

	}
private:
	// 基本类型(内置类型)
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d;
	d.Print();
	return 0;
}
```



![image-20221005200708302](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210052007341.png)

不是说编译器会帮我们生成默认的构造函数吗？怎么还是随机值呢？

我们再来看一段代码

```cpp
class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	void Print()
	{
		cout << _year << "-" << _month<<"-"<<_day << endl;
	}
private:
	// 基本类型(内置类型)
	int _year;
	int _month;
	int _day;
	// 自定义类型
	Time _t;
};
int main()
{
	Date d;
	d.Print();
	return 0;
}
```

![image-20221005201643767](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210052016814.png)

为什么我创建Date的类编译器会自动调用time类的构造函数呢？



这就是构造函数的最后一个特性（也是C++中的一个大坑，很多朋友都弄不清楚）

7. 关于编译器生成的默认成员函数，很多朋友会有疑惑：不实现构造函数的情况下，编译器会
   生成默认的构造函数。但是看起来默认构造函数又没什么用？d对象调用了编译器生成的默
   认构造函数，但是d对象_year/_month/_day，依旧是随机值。也就说在这里编译器生成的
   默认构造函数并没有什么用？？  

解答：C++把类型分成**内置类型(基本类型)**和**自定义类型**。**内置类型就是语言提供的数据类
型**，如：int/char...，**自定义类型就是我们使用class/struct/union等自己定义的类型**，看看
上面的程序，就会发现**编译器生成默认的构造函数会对自定类型成员_t调用的它的默认成员
函数**。  （**编译器对内置类型不处理，自定义类型会调用它的默认构造**）



> 因为C++对内置类型不处理，从而让很多C++的初学者刚开始都在这个地方困惑了许久，
>
> 也让许多人吐槽过，至于为什么后来没有改这个机制，理由也很简单，C++是向前兼容的
>
> 像之前那个NULL那样，只会打补丁加了个关键字nullptr，一般不会修改以前的机制，
>
> 同样后来这个机制也打了不少补丁

注意：C++11 中针对内置类型成员不初始化的缺陷，又打了补丁，即：**内置类型成员变量在
类中声明时可以给默认值**。  



```cpp
class Date
{
public:
	void Print()
	{
		cout << _year << "-" << _month<<"-"<<_day << endl;
	}
private:
	// 基本类型(内置类型)
	int _year=0; //注意这只是给默认值，并没有开辟空间，跟函数上的缺省可以类比
	int _month=0;
	int _day=0;
};
int main()
{
	Date d;
	d.Print();
	return 0;
}
```

![image-20221005202611061](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210052026101.png)



----



## 2.2析构函数  



### 2.2.1概念  

通过前面构造函数的学习，我们知道一个对象是怎么来的，那一个对象又是怎么没的呢？
析构函数：与构造函数功能相反，析构函数不是完成对对象本身的销毁，局部对象销毁工作是由
编译器完成的。而**对象在销毁时会自动调用析构函数，完成对象中资源的清理工作**。  



---



### 2.2.2特性  

析构函数是特殊的成员函数，其特征如下：  

**析构函数语法：** `~类名(){}`

1. **析构函数，没有返回值也不写void**
2. **函数名称与类名相同,在名称前加上符号  ~**
3. **一个类只能有一个析构函数。若未显式定义，系统会自动生成默认的析构函数。注意：析构
   函数不能重载**  
4. **对象生命周期结束时会自动调用析构，无须手动调用,而且只会调用一次**



比如我们看下面的一段代码：一个栈的类，我们定义了一个析构函数，通过调试来看编译器是否帮我们进行了调用

```cpp
typedef int DataType;
class Stack
{
public:
	Stack(size_t capacity = 3)
	{
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (NULL == _array)
		{
			perror("malloc申请空间失败!!!");
			return;
		}
		_capacity = capacity;
		_size = 0;
	}
	void Push(DataType data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	// 其他方法...
	~Stack()
	{
		if (_array)
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	DataType* _array;
	int _capacity;
	int _size;
};
int main()
{
	Stack s;
	s.Push(1);
	s.Push(2);
	return 0;
}
```



![image-20221006141002122](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210061410193.png)



事实证明，编译器确实会帮我们在对象生命周期结束时自动调用析构函数。



5. **关于编译器自动生成的析构函数，是否会完成一些事情呢？下面的程序我们会看到，编译器 生成的默认析构函数，对自定类型成员调用它的析构函数**。



```cpp
class Time
{
public:
	~Time()
	{
		cout << "~Time()" << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
private:
	// 基本类型(内置类型)
	int _year = 1970;
	int _month = 1;
	int _day = 1;
	// 自定义类型
	Time _t;
};
int main()
{
	Date d;
	return 0;
}
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
```



![image-20221006141654857](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210061416894.png)









6. **如果类中没有申请资源时，析构函数可以不写，直接使用编译器生成的默认析构函数，比如 Date类；有资源申请时，一定要写，否则会造成资源泄漏，比如Stack（栈）类**。







----





# 3. 拷贝构造函数 



## 3.1 概念



   在现实生活中，可能存在一个与你一样的自己，我们称其为双胞胎  



![image-20221011194627704](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210111946068.png)





那在创建对象时，可否创建一个与已存在对象一某一样的新对象呢？  



**拷贝构造函数：只有单个形参，该形参是对本类类型对象的引用(一般常用const修饰)，在用已存
在的类类型对象创建新对象时由编译器自动调用**。  





## 3.2 特征  



拷贝构造函数也是特殊的成员函数，其特征如下：  



1. **拷贝构造函数是构造函数的一个重载形式**。  
2. **拷贝构造函数的参数只有一个且必须是类类型对象的引用，使用传值方式编译器直接报错，
   因为会引发无穷递归调用**。  



```cpp
class Date
{
public:
	Date(int year = 1970, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// Date(const Date d) // 错误写法：编译报错，会引发无穷递归
	Date(const Date& d) // 正确写法
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	Date d2(d1);
	return 0;
}
```

![image-20221011195746278](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210111957333.png)

> 函数传值传参，本质上就是实参的一份拷贝，这时候是会调用拷贝构造函数，比如下面的例子就可以验证





```cpp
class Date
{
public:
	Date(int year = 1970, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d) // 假设拷贝构造已经存在了
	{
		cout << "Date(const Date& d)" << endl;
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};

void DateTest1(Date d1)
{
	//传值，会发生拷贝构造
}

void DateTest2(Date& d)
{
	//传引用
}
int main()
{
	Date d1;
	DateTest1(d1);
	DateTest2(d1);
	return 0;
}
```





![image-20221011200327557](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210112003599.png)





> 运行结果证明传值的方式是会调用拷贝构造的，所以如果拷贝构造函数使用传值的方式，则会无穷调用自己本身。





3. **若未显式定义，编译器会生成默认的拷贝构造函数**。 默认的拷贝构造函数对象按内存存储按
   字节序完成拷贝，这种拷贝叫做浅拷贝，或者值拷贝。  



```cpp
class Time
{
public:
	Time()
	{
		_hour = 1;
		_minute = 1;
		_second = 1;
	}
	Time(const Time& t)
	{
		_hour = t._hour;
		_minute = t._minute;
		_second = t._second;
		cout << "Time::Time(const Time&)" << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	void Print()
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}
private:
	// 基本类型(内置类型)
	int _year = 1970;
	int _month = 1;
	int _day = 1;
	// 自定义类型
	Time _t;
};
int main()
{
	Date d1;
	// 用已经存在的d1拷贝构造d2，此处会调用Date类的拷贝构造函数
	// 但Date类并没有显式定义拷贝构造函数，则编译器会给Date类生成一个默认的拷贝构造函数
	Date d2(d1);
	d2.Print();
	return 0;
}
```

![image-20221011201013967](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210112010016.png)







==注意==：在编译器生成的默认拷贝构造函数中，**内置类型是按照字节方式直接拷贝的，而自定
义类型是调用其拷贝构造函数完成拷贝的**。  





4. **编译器生成的默认拷贝构造函数已经可以完成字节序的值拷贝了**，还需要自己显式实现吗？
   像日期类这样的类当然是没必要的，那么所有类都不需要吗？

显然不是，比如还是我们之前stack（栈）类

```cpp
// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
typedef int DataType;
class Stack
{
public:
	Stack(size_t capacity = 10)
	{
		_array = (DataType*)malloc(capacity * sizeof(DataType));
		if (nullptr == _array)
		{
			perror("malloc申请空间失败");
			return;
		}
		_size = 0;
		_capacity = capacity;
	}
	void Push(const DataType& data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	~Stack()
	{
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
};
int main()
{
	Stack s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	Stack s2(s1);
	return 0;
}
```







![image-20221011202306373](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210112023431.png) 





> 其实本质上还是因为编译器默认生成的拷贝构造只是完成值拷贝，这就会导致两个栈都指向了同一块空间，而但它们结束生命周期后会调用析构函数，同一个空间释放了两次，自然就报错了。



![image-20221011202445320](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210112025752.png)

==总结==：类中如果没有涉及资源申请时，拷贝构造函数是否写都可以；一旦涉及到资源申请
时，则拷贝构造函数是一定要写的，否则就是浅拷贝(如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题)。  



深浅拷贝是面试经典问题，也是常见的一个坑



浅拷贝：简单的赋值拷贝操作



深拷贝：在堆区重新申请空间，进行拷贝操作







5. **拷贝构造函数典型调用场景**:

+ 使用已存在对象创建新对象
+ 函数参数类型为类类型对象
+ 函数返回值类型为类类型对象  



> 为了提高程序效率，一般对象传参时，尽量使用引用类型，返回时根据实际场景，能用引用
> 尽量使用引用。  





----





# 4.赋值运算符重载  





## 4.1 运算符重载  

> 运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型

**C++为了增强代码的可读性引入了运算符重载，运算符重载是具有特殊函数名的函数**，也具有其
返回值类型，函数名字以及参数列表，其返回值类型与参数列表与普通的函数类似。
函数名字为：关键字**operator后面接需要重载的运算符符号**。
函数原型：**返回值类型 operator操作符(参数列表)**  





注意：  

1. 不能通过连接其他符号来创建新的操作符：比如operator@  
2. 重载操作符必须有一个类类型参数  
3. 用于内置类型的运算符，其含义不能改变，例如：内置的整型+，不 能改变其含义  
4. 作为类成员函数重载时，其形参看起来比操作数数目少1，因为成员函数的第一个参数为隐
   藏的this  
5. `.* :: sizeof ?: .  `  注意以上5个运算符不能重载。这个经常在笔试选择题中出现。  



















