#define _CRT_SECURE_NO_WARNINGS


//#include<stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	b += a++;
//	printf("%d %d", a, b);
//	return 0;
//}


//
//#include<stdio.h>
////不允许创建临时变量，交换两个整数的内容
//int main()
//{
//	int a = 1;
//	int b = 2;
//	printf("交换前a=%d,b=%d\n", a, b);
//
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("交换后a=%d,b=%d\n", a, b);
//
//	return 0;
//}


////获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int i = 0;
//	int m = a;
//	int p = 1;
//	printf("奇数位的二进制序列为：");
//	for (i = 0; i < 16; i++)
//	{
//		printf("%d ", a & p);
//		a >>= 2;
//	}
//	printf("\n偶数位的二进制序列为：");
//	m >>= 1;
//	for (i = 0; i < 16; i++)
//	{
//		printf("%d ", m & p);
//		m >>= 2;
//	}
//	return 0;
//}

//000000000000000000000000

//
//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	int b = (++i)+(++i)+(++i);
//	printf("%d %d", b,i);
//	return 0;
//}
//




//
//#include<stdio.h>
//
//int main()
//{
//    int a, b, c;
//    while (scanf("%d %d %d", &a, &b, &c) != EOF)
//    {
//        if ((a + b > c) && (a + c > b) && (b + c > a))
//        {
//            if ((a == b) && (a == c) && (b == c))
//            {
//                printf("Equilateral triangle!\n");
//            }
//
//            else if ((a == b) || (a == c) || (b == c))
//            {
//                printf("Isosceles triangle!\n");
//            }
//            else
//            {
//                printf("Ordinary triangle!\n");
//            }
//        }
//        else
//            printf("Not a triangle!");
//    }
//    return 0;
//}

//获得月份天数
//#include<stdio.h>
//
//int main()
//{
//    int year = 0;
//    int month = 0;
//    while (scanf("%d %d", &year, &month) != EOF)
//    {
//        if (month == 4 || month == 6 || month == 9 || month == 11)
//        {
//            printf("30\n");
//        }
//        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//        {
//            printf("31\n");
//        }
//        if (month == 2)
//        {
//            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//            {
//                printf("29\n");
//            }
//            else
//            {
//                printf("28\n");
//            }
//        }
//    }
//
//
//}
//X形图案
//
//#include<stdio.h>
//
//int main()
//{
//    int n = 0;
//
//    int i = 0;
//    int j = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        for (i = 0; i < n; i++)
//        {
//            for (j = 0; j < n; j++)
//            {
//                if (j == i || j == n - i - 1)
//                    printf("*");
//                else
//                    printf(" ");
//            }
//            printf("\n");
//        }
//    }
//
//    return 0;
//}

//
//
//#include<stdio.h>
//int add(int x, int y)
//{
//
//	return x+y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = add(a, b);
//	printf("%d\n", c);
//	return 0;
//}


//
////写一个函数打印arr数组的内容，不使用数组下标，使用指针。
////arr是一个整形一维数组。
//#include<stdio.h>
//
//void print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	return 0;
//}

////
////求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
////例如：2 + 22 + 222 + 2222 + 22222
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int i = 0;
//	int sum = 0;
//	for (i = 0; i < 5; i++)
//	{
//		sum += a;
//		a = a * 10 + a;
//	}
//	printf("%d ", sum);
//
//	return 0;
//}
//
////
////
////求出0～100000之间的所有“水仙花数”并输出。
////“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，
////如 : 153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”。
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int i = 0;
//	int n = 0;
//	int sum = 0;
//	for (i = 1; i <= 100000; i++)
//	{
//		int j = i;
//		int n = 0;
//		while (j )
//		{
//			n++;
//			j = j / 10;
//		}
//		j = i;
//		sum = 0;
//		while (j)
//		{
//		 sum = sum + (int)pow(j % 10, n);
//			j /= 10;
//		}
//		if (sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
////}
//
////打印菱形
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= n - i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2 * i - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i = 1; i <= n-1; i++)
//	{
//		for (j = 1; j <=i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2 * (n-i) - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}
//输入描述:
//输入一个字符串，可以有空格
//输出描述:
//输出逆序的字符串


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char arr[10000];
    gets(arr);
    int i = strlen(arr) - 1;
    for (i; i >= 0; i--)
    {
        printf("%c", arr[i]);
    }
    return 0;
}