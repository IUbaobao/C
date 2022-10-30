@[TOC](文章目录)



----



# 1. C++内存分布



C++程序在执行时，将内存大方向划分为**4个区域**

- 代码区：存放函数体的二进制代码，由操作系统进行管理的
- 数据区：存放全局变量和静态变量以及常量
- 栈区：由编译器自动分配释放, 存放函数的参数值,局部变量等
- 堆区：由程序员分配和释放,若程序员不释放,程序结束时由操作系统回收



  

![image-20221029201152979](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210292012655.png)

【说明】

1. 栈又叫堆栈--非静态局部变量/函数参数/返回值等等，栈是向下增长的。

2. 内存映射段是高效的I/O映射方式，用于装载一个共享的动态内存库。用户可使用系统接口
   创建共享共享内存，做进程间通信。

3. 堆用于程序运行时动态内存分配，堆是可以上增长的。

4. 数据段--存储全局数据和静态数据。

5. 代码段--可执行的代码/只读常量  。



## 1.1程序运行前

​	在程序编译后，生成了exe可执行程序，**未执行该程序前**分为两个区域

​	**代码区：**

​		存放 CPU 执行的机器指令

​		代码区是**共享**的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可

​		代码区是**只读**的，使其只读的原因是防止程序意外地修改了它的指令

​	**全局区：**

​		全局变量和静态变量存放在此.

​		全局区还包含了常量区, 字符串常量和其他常量也存放在此.

​		==该区域的数据在程序结束后由操作系统释放==.



### 1.2 程序运行后



​	**栈区：**

​		由编译器自动分配释放, 存放函数的参数值,局部变量等

​		注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放



**堆区：**

​		由程序员分配释放,若程序员不释放,程序结束时由操作系统回收

​		在C++中主要利用new在堆区开辟内存



**总结：**

堆区数据由程序员管理开辟和释放

堆区数据利用new关键字进行开辟内存





**内存四区意义：**

不同区域存放的数据，赋予不同的生命周期, 给我们更大的灵活编程

---



# 2. C++内存管理方式  



C语言内存管理方式在C++中仍然可以继续使用，但有些地方就无能为力，而且使用起来比较麻烦，因
此C++又提出了自己的内存管理方式：通过new和delete操作符进行动态内存管理。  



## 2.1 new/delete操作内置类型  





​	C++中利用==new==操作符在堆区开辟数据

​	堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符 ==delete==

​	语法：` new 数据类型`

​	利用new创建的数据，会返回该数据对应的类型的指针



```cpp
void Test()
{
// 动态申请一个int类型的空间
int* ptr4 = new int;
// 动态申请一个int类型的空间并初始化为10
int* ptr5 = new int(10);
// 动态申请10个int类型的空间
int* ptr6 = new int[3];
delete ptr4;
delete ptr5;
delete[] ptr6;
}
```



![image-20221029202144821](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210292021944.png)





【注意】：**申请和释放单个元素的空间，使用new和delete操作符，申请和释放连续的空间，使用
new[]和delete[]，注意：匹配起来使用**。  



---



## 2.2 new和delete操作自定义类型 



**new/delete 和 C语言传统的malloc/free最大区别是 new/delete对于【自定义类型】除了开空间
还会调用构造函数和析构函数**  



```cpp
class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};
int main()
{
	// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间
	//还会调用构造函数和析构函数
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = new A(1);
	free(p1);
	delete p2;
	// 内置类型是几乎是一样的
	int* p3 = (int*)malloc(sizeof(int)); // C语言传统方式
	int* p4 = new int;
	free(p3);
	delete p4;
	A* p5 = (A*)malloc(sizeof(A) * 10);
	A* p6 = new A[10];
	free(p5);
	delete[] p6;
	return 0;
}
```



![image-20221029203102761](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210292031929.png)



【注意】：在申请自定义类型的空间时，new会调用构造函数，delete会调用析构函数，而malloc与
free不会  



---





# 3. operator new与operator delete函数  





new和delete是用户进行动态内存申请和释放的操作符，operator new 和operator delete是
系统提供的全局函数，new在底层调用operator new全局函数来申请空间，delete在底层通过
operator delete全局函数来释放空间。  



```cpp
/*
operator new：该函数实际通过malloc来申请空间，当malloc申请空间成功时直接返回；申请空间
失败，尝试执行空 间不足应对措施，如果改应对措施用户设置了，则继续申请，否则抛异常。
*/
void *__CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
{
	// try to allocate size bytes
	void *p;
	while ((p = malloc(size)) == 0)
		if (_callnewh(size) == 0)
		{
			// report no memory
			// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
			static const std::bad_alloc nomem;
			_RAISE(nomem);
		}
	return (p);
}
/*
operator delete: 该函数最终是通过free来释放空间的
*/
void operator delete(void *pUserData)
{
	_CrtMemBlockHeader * pHead;
	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
	if (pUserData == NULL)
		return;
	_mlock(_HEAP_LOCK); /* block other threads */
	__TRY
		/* get a pointer to memory block header */
		pHead = pHdr(pUserData);
	/* verify block type */
	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
	_free_dbg(pUserData, pHead->nBlockUse);
	__FINALLY
		_munlock(_HEAP_LOCK); /* release other threads */
	__END_TRY_FINALLY
		return;
}
/*
free的实现
*/
#define free(p) _free_dbg(p, _NORMAL_BLOCK)

```



通过上述两个全局函数的实现知道，**operator new 实际也是通过malloc来申请空间**，如果
malloc申请空间成功就直接返回，否则执行用户提供的空间不足应对措施，如果用户提供该措施
就继续申请，否则就抛异常。**operator delete 最终是通过free来释放空间的**。  



---





# 4. new和delete的实现原理  





## 4.1 内置类型  



如果申请的是内置类型的空间，new和malloc，delete和free基本类似，不同的地方是：
new/delete申请和释放的是单个元素的空间，new[]和delete[]申请的是连续空间，而且new在申
请空间失败时会抛异常，malloc会返回NULL。  





## 4.2 自定义类型  





new的原理

1. 调用operator new函数申请空间

2. 在申请的空间上执行构造函数，完成对象的构造



delete的原理

1. 在空间上执行析构函数，完成对象中资源的清理工作

2. 调用operator delete函数释放对象的空间   



new T[N]的原理

1. 调用operator new[]函数，在operator new[]中实际调用operator new函数完成N个对
   象空间的申请

2. 在申请的空间上执行N次构造函数



delete[]的原理

1. 在释放的对象空间上执行N次析构函数，完成N个对象中资源的清理

2. 调用operator delete[]释放空间，实际在operator delete[]中调用operator delete来释
   放空间  













---







# 5. malloc/free和new/delete的区别  



malloc/free和new/delete的共同点是：都是从堆上申请空间，并且需要用户手动释放。不同的地
方是：

1. **malloc和free是函数，new和delete是操作符**

2. malloc申请的空间**不会**初始化，new**可以初始化**

3. malloc申请空间时，需要手动**计算空间**大小并传递，new只需在其后跟上空间的类型即可，
   如果是多个对象，[]中指定对象个数即可

4. **malloc的返回值为void\*, 在使用时必须强转，new不需要，因为new后跟的是空间的类型**

5. malloc申请空间**失败**时，返回的是**NULL**，因此使用时必须判空，new不需要，但是new需
   要捕获**异常**

6. 申请自定义类型对象时，**malloc/free只会开辟空间**，不会调用构造函数与析构函数，而new
   在申请空间后会**调用构造函数**完成对象的初始化，delete在释放空间前会**调用析构函数**完成
   空间中资源的清理  











---





# 6. 内存泄漏  



什么是内存泄漏，内存泄漏的危害  ？



什么是内存泄漏：内存泄漏指因为疏忽或错误造成程序未能释放已经不再使用的内存的情况。内
存泄漏并不是指内存在物理上的消失，而是应用程序分配某段内存后，因为设计错误，失去了对
该段内存的控制，因而造成了内存的浪费。

内存泄漏的危害：长期运行的程序出现内存泄漏，影响很大，如操作系统、后台服务等等，出现
内存泄漏会导致响应越来越慢，最终卡死。  











# 7. 定位new表达式(placement-new)  （了解）





定位new表达式是在已分配的原始内存空间中调用构造函数初始化一个对象。

**使用格式**：

new (place_address) type或者new (place_address) type(initializer-list)
place_address必须是一个指针，initializer-list是类型的初始化列表

**使用场景**：

定位new表达式在实际中一般是配合内存池使用。因为内存池分配出的内存没有初始化，所以如
果是自定义类型的对象，需要使用new的定义表达式进行显示调构造函数进行初始化  





```cpp
class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};


// 定位new/replacement new
int main()
{
	// p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没
	//有执行
	A* p1 = (A*)malloc(sizeof(A));
	new(p1)A; // 注意：如果A类的构造函数有参数时，此处需要传参
	p1->~A();
	free(p1);
	A* p2 = (A*)operator new(sizeof(A));
	new(p2)A(10);
	p2->~A();
	operator delete(p2);
	return 0;
}
```

