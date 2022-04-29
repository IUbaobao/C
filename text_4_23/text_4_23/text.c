#define _CRT_SECURE_NO_WARNINGS

//递归和非递归分别实现求n的阶乘（不考虑溢出的问题）
//#include<stdio.h>
//
////递归
//int fun1(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * fun1(n - 1);
//}
//
////迭代
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
////递归和非递归分别实现strlen
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


//递归方式实现打印一个整数的每一位
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


//递归和非递归分别实现求第n个斐波那契数
//#include<stdio.h>
////递归
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
////非递归
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
//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//输入：1729，输出：19
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



////编写一个函数实现n的k次方，使用递归实现。
#include<stdio.h>
double fun(int n, int k)
{
	//k不为负时
	if (k >= 0)
	{
		if (k != 0)
		{
			return n * fun(n, k - 1);
		}
		else
			return 1;
	}
	//k为负时
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
	printf("%d的%d次方为%lf ", n, k, ret);
	return 0;
}

//
//编写一个函数 reverse_string(char* string)（递归实现）
//实现：将参数字符串中的字符反向排列，不是逆序打印。
//要求：不能使用C函数库中的字符串操作函数。

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