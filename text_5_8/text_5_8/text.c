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
////����������ʱ������������������������
//int main()
//{
//	int a = 1;
//	int b = 2;
//	printf("����ǰa=%d,b=%d\n", a, b);
//
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("������a=%d,b=%d\n", a, b);
//
//	return 0;
//}


////��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int i = 0;
//	int m = a;
//	int p = 1;
//	printf("����λ�Ķ���������Ϊ��");
//	for (i = 0; i < 16; i++)
//	{
//		printf("%d ", a & p);
//		a >>= 2;
//	}
//	printf("\nż��λ�Ķ���������Ϊ��");
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

//����·�����
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
//X��ͼ��
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
////дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣
////arr��һ������һά���顣
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
////��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
////���磺2 + 22 + 222 + 2222 + 22222
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
////���0��100000֮������С�ˮ�ɻ������������
////��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ�������
////�� : 153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������
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
////��ӡ����
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
//��������:
//����һ���ַ����������пո�
//�������:
//���������ַ���


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