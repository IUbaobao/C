#define _CRT_SECURE_NO_WARNINGS

//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ���������������⣩
//#include<stdio.h>
//
////�ݹ�
//int fun1(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * fun1(n - 1);
//}
//
////����
//int fun2(int n)
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//int ret = fun1(n);
//	int ret = fun2(n);
//	printf("%d\n", ret);
//	return 0;
//}


//
////�ݹ�ͷǵݹ�ֱ�ʵ��strlen
//#include<stdio.h>
//
//int my_strlen(char* p)
//{
//	if (*p == '\0')
//		return 0;
//	else
//		return 1 + my_strlen(p + 1);
//}
//int main()
//{
//	char arr[] = "abc";
//	int ret = my_strlen(arr);
//	printf("%d ", ret);
//	return 0;
//}


//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
//#include<stdio.h>
//void print(int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//	return 0;
//}


//�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
//#include<stdio.h>
////�ݹ�
////int fib(int n)
////{
////	if (n <= 2)
////	{
////		return 1;
////	}
////	else
////	{
////		return fib(n - 1) + fib(n - 2);
////	}
////}
//
////�ǵݹ�
//int fib1(int n)
//{
//		int a = 1;
//		int b = 1;
//		int c = 1;
//		while (n >= 3)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//			n--;
//		}
//		return c;
//
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fib1(n);
//	printf("%d ", ret);
//	return 0;
//}

//
//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
//���룺1729�������19
//#include<stdio.h>
//unsigned int DigitSum(n)
//{
//	if (n > 9)
//	{
//		return n % 10 + DigitSum(n / 10);
//	}
//	else
//	{
//		return n % 10;
//	}
//}
//int main()
//{
//	unsigned int n = 0;
//	scanf("%d", &n);
//	unsigned int ret = DigitSum(n);
//	printf("%d ", ret);
//}



////��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ�֡�
#include<stdio.h>
double fun(int n, int k)
{
	//k��Ϊ��ʱ
	if (k >= 0)
	{
		if (k != 0)
		{
			return n * fun(n, k - 1);
		}
		else
			return 1;
	}
	//kΪ��ʱ
	else
	{
		if (k != 0)
		{
			return 1.0/n * fun(n, k + 1);
		}
		else
			return 1;
	}
}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	double ret = fun(n, k);
	printf("%d��%d�η�Ϊ%lf ", n, k, ret);
	return 0;
}

//
//��дһ������ reverse_string(char* string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������У����������ӡ��
//Ҫ�󣺲���ʹ��C�������е��ַ�������������

//#include<stdio.h>
//void reverse_string(char* string)
//{
//	
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s", arr);
//	return 0;
//}