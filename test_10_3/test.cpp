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
//			perror("malloc����ռ�ʧ��");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(const DataType& data)
//	{
//		// ����
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




//// ���ǿ�������������ǲ��Ǻܽ�Ӳ��
//class Date
//{
//public:
//	void Init(int year)
//	{
//		// �����year�����ǳ�Ա���������Ǻ����βΣ�
//		year = year;
//	}
//private:
//	int year;
//};
//// ����һ�㶼��������
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
//// ��������
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
//// ������ʽҲ���Եģ���Ҫ����˾Ҫ��һ�㶼�ǼӸ�ǰ׺���ߺ�׺��ʶ���־���
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

// ������Ҫָ��PrintPersonInfo������Person�������
//���ǿ�������һ�£�������Ӳ�����::��ô��������ô����
void Person::PrintPersonInfo()
{
	cout << _name << " " << _gender << " " << _age << endl;
}