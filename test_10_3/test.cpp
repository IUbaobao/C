#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdlib.h>
using namespace std;

//typedef int DataType;
//struct Stack
//{
//	DataType* _array;
//	size_t _capacity;
//	size_t _size;
//	void Init(size_t capacity)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(const DataType& data)
//	{
//		// 扩容
//		_array[_size] = data;
//		++_size;
//	}
//	DataType Top()
//	{
//		return _array[_size - 1];
//	}
//	void Destroy()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//};
//
//int main()
//{
//	Stack s;
//	s.Init(10);
//	s.Push(1);
//	cout << s.Top() << endl;
//	s.Destroy();
//	return 0;
//}




//// 我们看看这个函数，是不是很僵硬？
//class Date
//{
//public:
//	void Init(int year)
//	{
//		// 这里的year到底是成员变量，还是函数形参？
//		year = year;
//	}
//private:
//	int year;
//};
//// 所以一般都建议这样
//class Date
//{
//public:
//	void Init(int year)
//	{
//		_year = year;
//	}
//private:
//	int _year;
//};
//// 或者这样
//class Date
//{
//public:
//	void Init(int year)
//	{
//		mYear = year;
//	}
//private:
//	int mYear;
//};
//// 其他方式也可以的，主要看公司要求。一般都是加个前缀或者后缀标识区分就行
//



class Person
{
public:
	void PrintPersonInfo();
private:
	char _name[20];
	char _gender[3];
	int _age;
};

// 这里需要指定PrintPersonInfo是属于Person这个类域
//我们可以想象一下，如果不加操作符::那么，它会怎么样？
void Person::PrintPersonInfo()
{
	cout << _name << " " << _gender << " " << _age << endl;
}