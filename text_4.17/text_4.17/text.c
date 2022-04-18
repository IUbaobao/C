#define _CRT_SECURE_NO_WARNINGS

//关机程序
//#include<stdio.h>
//#include<windows.h>
//
//int main()
//{
//	char iput[20] = { 0 };
//	system("shutdown -s -t 100");
//	again:
//	printf("你的电脑还有100秒就关机，请输入“我是猪”，就取消关机\n");
//	scanf("%s", iput);
//		if (strcmp(iput, "我是猪") == 0)
//		{
//			system("shutdown -a");
//			printf("已取消\n");
//		}
//		else
//		{
//			goto again;
//		}
//	return 0;
//}

//
//
////实现一个函数来交换两个整数的内容。
//#include<stdio.h>
////交换两个数
//void swap(int* a, int* b)
//{
//	int tem = *a;
//	*a = *b;
//	*b = tem;
//	//位运算
//	//*a = (*a) ^ (*b);
//	//*b = (*a) ^ (*b);
//	//*a = (*a) ^ (*b);
//
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("交换前a=%d,b=%d\n", a, b);
//	swap(&a, &b);
//	printf("交换后a=%d,b=%d\n", a, b);
//	return 0;
//}

//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
//如：输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。
//#include<stdio.h>
//void fun(int a)
//{
//	int i, j;
//	for (i = 1; i <= a; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%-d*%-d=%-4d\t", j, i, i * j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	fun(a);
//	return 0;
//}