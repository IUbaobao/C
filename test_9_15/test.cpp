#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

//�����ռ�
namespace test
{
	int rand = 1;
}

//��������
int add(int a, int b)
{
	return a + b;
}

float add(float a, float b)
{
	return a + b;
}
double add(double a, double b)
{
	return a + b;
}

//ȱʡ����
void f(int a = 0, int b = 0)
{
	cout << a << endl;
	cout << b << endl;
}

int main()
{
	//int a, b;
	//char c;
	//cin >> a >> b >> c;
	//cout << a << ' ' << b << ' ' << c << endl;
	/*cout << test::rand << endl;*/

	////cout << add(1, 2) << '\n' << add(2.1, 3.2) << endl;
	//f();
	//f(1);
	//f(1, 2);




	return 0;
}