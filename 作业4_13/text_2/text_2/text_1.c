#define _CRT_SECURE_NO_WARNINGS
//д���뽫�������������Ӵ�С�����
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

////дһ�������ӡ1 - 100֮������3�ı���������
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
////���������������������������Լ��
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


//дһ�����룺��ӡ100~200֮�������
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


//��ӡ1000�굽2000��֮�������

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