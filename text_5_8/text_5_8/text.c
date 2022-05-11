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

#include<stdio.h>

int main()
{
    int n = 0;

    int i = 0;
    int j = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (j == i || j == n - i - 1)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}