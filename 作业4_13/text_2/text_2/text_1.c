#define _CRT_SECURE_NO_WARNINGS
//写代码将三个整数数按从大到小输出。
//#include<stdio.h>
//int main()
//{
//	int a, b, c,tem;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		tem = a;
//		a = b;;
//		b = tem;
//	}
//	if (a < c)
//	{
//		tem = a;
//		a = c;
//		c = tem;
//	}
//	if (b < c)
//	{
//		tem = b;
//		b = c;
//		c = tem;
//	}
//	printf("%d %d %d", a, b, c);
//		
//	return 0;
//}

////写一个代码打印1 - 100之间所有3的倍数的数字
//#include<stdio.h>
//
//int main()
//{
//	int i;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//			printf("%d ", i);
//		i++;
//	}
//	return 0;
//}
//
////给定两个数，求这两个数的最大公约数
//
//#include<stdio.h>
//
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	while (a % b)
//	{
//		int tem = a % b;
//		a = b;
//		b = tem;
//	}
//	printf("%d ", b);
//	return 0;
//}


//写一个代码：打印100~200之间的素数
////
//#include<stdio.h>
//
//int main()
//{
//
//	for (int i = 101; i <= 200; i++)
//	{
//		int count = 0;
//		for (int j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//				count = 1;
//		}
//		if (count == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//
//	return 0;
//}


//打印1000年到2000年之间的闰年

#include<stdio.h>

int main()
{
	int i,j=0;
	for (i = 1000; i < 2000; i++)
	{
		if (i % 4 == 0 && i % 100 != 0||i%400==0)
		{
			printf("%d ", i);
		}
	}

	return 0;
}