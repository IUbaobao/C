

//������������ڣ���������һ��ĵڼ��졣
//��֤���Ϊ4λ�������ںϷ���
//���ף�ʱ�临�Ӷȣ�O(n)\O(n) ���ռ临�Ӷȣ�O(1)\O(1)
//����������
//����һ�У�ÿ�пո�ָ�ֱ����꣬�£���
//
//���������
//�������һ��ĵڼ���
//ʾ��1
//���룺
//2012 12 31
//����
//�����
//366
//#include <iostream>
//using namespace std;
//
//int main() {
//	int year, month, day;
//	cin >> year >> month >> day;
//	static int GetMontDayArry[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int n = 0;
//	for (int i = 1; i<month; i++)
//	{
//		n += GetMontDayArry[i];
//	}
//	n += day;
//
//	if (month>2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//	{
//		++n;
//	}
//	cout << n << endl;
//}


//����
//���������ڣ�����������֮�������������������������������ǹ涨����֮�������Ϊ����
//����������
//�ж������ݣ�ÿ�����������У��ֱ��ʾ�������ڣ���ʽΪYYYYMMDD
//���������
//ÿ���������һ�У������ڲ�ֵ
//ʾ��1
//���룺
//20110412
//20110422
//����
//�����
//11
//#include<iostream>
//using namespace std;
//
//int GetMontDay(int year, int month)
//{
//	static int GetMonthDayArry[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
//	{
//		return 29;
//	}
//	else
//	{
//		return GetMonthDayArry[month];
//	}
//}
//
//
//int main()
//{
//	int n1, n2;
//	cin >> n1 >> n2;
//	int year1, month1, day1, year2, month2, day2;
//	//��ȡ����
//	day1 = n1 % 100, month1 = (n1 / 100) % 100, year1 = n1 / 10000;
//	day2 = n2 % 100, month2 = (n2 / 100) % 100, year2 = n2 / 10000;
//	//�ҳ��ϴ�ͽ�С������
//	int maxyear = year1, maxmonth = month1, maxday = day1;
//	int minyear = year2, minmonth = month2, minday = day2;
//	if (maxyear<minyear || (maxyear == minyear && maxmonth<minmonth)
//		|| (maxyear == minyear && maxmonth == minmonth && maxday<minday))
//	{
//		maxyear = year2, maxmonth = month2, maxday = day2;
//		minyear = year1, minmonth = month1, minday = day1;
//	}
//
//	int n = 0;
//	//��С�����ڼ�+1��ֱ�������������
//	while (maxyear != minyear || maxmonth != minmonth || maxday != minday)
//	{
//		n++;
//		minday++;
//		if (minday> GetMontDay(minyear, minmonth))
//		{
//			minmonth++;
//			minday = 1;
//		}
//		if (minmonth == 13)
//		{
//			minyear++;
//			minmonth = 1;
//		}
//	}
//	n++;
//	cout << n << endl;
//
//	return 0;
//}

//
//#include<iostream>
//using namespace std;
//
//class sum
//{
//public:
//	sum()
//	{
//		n++;
//	}
//
//	static int n;
//};
//
//int sum::n = 0;
//
//int main()
//{
//	int k;
//	cin >> k;
//	//sum arr[k];
//	sum arr[10];
//	cout << sum::n << endl;
//	return 0;
//}



//
//����
//�������m��һ���еĵ�n�죬�����n���Ǽ��¼��š�
//����������
//���������������y(1 <= y <= 3000)��n(1 <= n <= 366)��
//���������
//�����ж���������ݣ�����ÿ�����ݣ� �� yyyy - mm - dd�ĸ�ʽ�������ж�Ӧ�����ڴ�ӡ������
//ʾ��1
//���룺
//2000 3
//2000 31
//2000 40
//2000 60
//2000 61
//2001 60
//����
//�����
//2000 - 01 - 03
//2000 - 01 - 31
//2000 - 02 - 09
//2000 - 02 - 29
//2000 - 03 - 01
//2001 - 03 - 01
//#include <iostream>
//#include<stdio.h>
//using namespace std;
//
//
//int GetMontDay(int year, int month)
//{
//	static int GetMonthDayArry[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
//	{
//		return 29;
//	}
//	else
//	{
//		return GetMonthDayArry[month];
//	}
//}
//
//int main()
//{
//	int year, day;
//
//	while (cin >> year >> day)
//	{
//		int month = 1;
//		while (day>GetMontDay(year, month))
//		{
//			day -= GetMontDay(year, month);
//			month++;
//			if (month == 13)
//			{
//				year++;
//				month = 1;
//			}
//		}
//		printf("%d-%0.2d-%0.2d\n", year, month, day);
//
//	}
//	return 0;
//}

//����
//���һ�������ܼ���һ�����ڼ������������ʲô���ڡ�
//����������
//�����һ�б�ʾ��������m��������m��ÿ���ĸ������ֱ��ʾ�����պ��ۼӵ�������
//���������
//���m�У�ÿ�а�yyyy - mm - dd�ĸ��������
//ʾ��1
//���룺
//1
//2008 2 3 100
//����
//�����
//2008 - 05 - 13

#include <iostream>
using namespace std;
//
//int GetMontDay(int year, int month)
//{
//	static int GetMonthDayArry[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
//	{
//		return 29;
//	}
//	else
//	{
//		return GetMonthDayArry[month];
//	}
//}
//
//int main() {
//	int m;
//	cin >> m;
//	for (int i = 0; i<m; i++)
//	{
//		int year, month, day, n;
//		cin >> year >> month >> day >> n;
//
//		day += n;
//		while (day>GetMontDay(year, month))
//		{
//			day -= GetMontDay(year, month);
//			month++;
//			if (month == 13)
//			{
//				year++;
//				month = 1;
//			}
//		}
//		printf("%d-%0.2d-%0.2d\n", year, month, day);
//	}
//	return 0;
//}
//#include<string.h>
//int main()
//{
//	char*p = "abc";
//	cout << p << endl;
//	cout << (void*)p << endl;
//	cout << sizeof(p) << endl;
//	cout << strlen(p) << endl;
//
//	return 0;
//}
/////////////////////////////////////////////////////////////////////
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 10000; i <= 99999; i++)
//	{
//		//�ж�i�Ƿ�Ϊlily number
//		int j = 10;
//		int sum = 0;
//		int tmp = i;
//		for (j = 10; j <= 10000; j *= 10)
//		{
//			sum += (tmp%j)*(tmp / j);
//		}
//		if (sum == i)
//			printf("%d ", i);
//	}
//	return 0;
//}


//
//double fact(int a)
//{
//	int j = 1;
//	double sum = 1;
//	for (j = 1; j <= a; j++)
//	{
//		sum = sum * j;
//	}
//	return sum;
//}
//int main()
//{
//	double i = 0;
//	double sum = 1;
//	double a = 0;
//	int b = 1;
//	double c = 1;
//	double d = 0;
//	scanf("%lf", &i);
//	do
//	{
//		a = pow(i, b);
//		c = fact(b);
//		d = a / c;
//		sum = sum + d;
//		b++;
//	} while (fabs(d) >= 0.00001);
//	printf("s=%lf", sum);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int n, i, j, k;
//	cin >> n;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = i; j <= n; j++)                    
//		{
//			for (k = j; k <= n; k++)              
//			{
//				if (i*i + j*j == k*k && k>=150 && k<=160)           
//					cout << k  << endl;
//			}
//		}
//	}
//	return 0;
//}
//
//


//int main()
//{
//	int n = 0;
//	int i = 1;
//	int arr[10] = { 0 };
//
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int j = 1;
//	scanf("%d", &n);
//	printf("NO1:%d\n",n);
//	for (c = b + 1; c < 1000; c++)
//	{
//		for (a = 1; a<1000; a++)
//		{
//			for (b = a + 1; b<1000; b++)
//			{
//				if (a * a + b * b == c * c && c > n&&i<=10)
//				{
//					arr[i - 1] = c;
//					i++;
//				}
//			}
//		}
//	}
//	
//	int tem = 0;
//	i = 1;
//	for (j = 0; j < 10; j++)
//	{
//		if (arr[j] != tem)
//		{
//			printf("NO%d:%d\n", ++i, arr[j]);
//			tem = arr[j];
//		}
//		if (i == 4)
//		{
//			break;
//		}
//	}
//	return 0;
//}
//

//
//#include<stdio.h>
//int main()
//{
//	double sum = 0;
//	int n = 0;
//	scanf("%d", &n);
//	double a = 2.0;
//	double b = 1.0;
//	for (int i = 0; i < n; i++)
//	{
//		double tem = a;//�����ĸ
//		sum += a / b;//���
//		//��������
//		a += b;
//		b = tem;//ǰһ����ĸΪ��һ������
//	}
//	printf("%0.2lf\n", sum);
//	return 0;
//}


//
//
//long double zi(int a)
//{
//	double sum = 0;
//	int i = 0;
//	double b = 1;
//	double c = 2;
//	i = 3;
//	if (a == 1)
//	{
//		return b;
//	}
//	else if (a == 2)
//		return c;
//	if (a >= 3)
//	{
//		for (i = 3; i <= a; i++)
//		{
//			sum = b + c;
//			b = c;
//			c = sum;
//		}
//		return sum;
//	}
//}
//int main()
//{
//	int i = 0;
//	long double sum = 0;
//	int a = 0;
//	long  double b = 0;
//	long double c = 0;
//	long double d = 0;
//	scanf("%d", &i);
//
//
//	for (a = 1; a <= i; a++)
//	{
//		b = zi(a + 1);
//		c = zi(a);
//		d = b / c;
//		sum = sum + d;
//	}
//	printf("s=%.2f", sum);
//	return 0;
//}




//
//#include<math.h>
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int i = 1;
//	int j = 2;
//	scanf("%d%d", &m, &n);
//	while (i <= n)
//	{
//		int flag = 0;//��־
//		for (j = 2; j <= sqrt(m); j++)
//		{
//			if (m % j == 0)
//			{
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0)
//		{
//			printf("%d\n", m);
//			i++;
//		}
//		m--;
//
//	}
//	return 0;
//}


//#include<math.h>
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int i = 1;
//	int j = 2;
//	scanf("%d%d", &m, &n);
//	while (i <= n)
//	{
//		for (j = 2; j<sqrt(m); j++)
//		{
//			if (m % j == 0)
//			{
//				m--;
//				j = 1;
//				continue;
//			}
//		}
//		printf("%d\n", m);
//		m--;
//		i++;
//	}
//}
//////////////////////////////////////////////////////////

//
//#include<iostream>
//using namespace std;
//int main()
//{
//	int* pa = new int(10);
//	int *pb = new int[10]{1,3,4};
//
//	delete pa;
//	delete[] pb;
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	// new/delete �� malloc/free��������� new/delete���ڡ��Զ������͡����˿��ռ�
//	//������ù��캯������������
//		A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1);
//	free(p1);
//	delete p2;
//	// ���������Ǽ�����һ����
//	int* p3 = (int*)malloc(sizeof(int)); // C
//	int* p4 = new int;
//	free(p3);
//	delete p4;
//	A* p5 = (A*)malloc(sizeof(A) * 10);
//	A* p6 = new A[10];
//	free(p5);
//	delete[] p6;
//	return 0;
//}


//���ʵ��һ��ͨ�õĽ���������??
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
//д���鷳
//1. ���صĺ������������Ͳ�ͬ�����븴���ʱȽϵͣ�ֻҪ�������ͳ���ʱ������Ҫ�û��Լ����Ӷ�Ӧ�ĺ�
//��
//2. ����Ŀ�ά���ԱȽϵͣ�һ������������е����ؾ�����


//ģ��
//template<typename T>
//void Swap(T&left, T&right)
//{
//	T tem = left;
//	left = right;
//	right = tem;
//}

//int main()
//{
//	int a = 10, b = 20;
//	double c = 1.1, d = 2.2;
//	cout << a << "-" << b << endl;
//	cout << c << "-" << d << endl;
//
//	Swap(a, b);
//	Swap<int>(a, b);
//
//	Swap(c, d);
//
//	cout << a << "-" << b << endl;
//	cout << c << "-" << d << endl;
//	Swap<int>(a, b);
//
//	cout << a << "-" << b << endl;
//
//	return 0;
//}
