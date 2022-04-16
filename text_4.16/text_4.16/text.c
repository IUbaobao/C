#define _CRT_SECURE_NO_WARNINGS

//猜数字游戏
//#include<stdio.h>
//#include<time.h>//初始化随机需要的头文件
//#include<stdlib.h>//生成随机数要用的头文件 
////菜单
//void menu()
//{
//	printf("*****************************************\n");
//	printf("***************0.退出游戏****************\n");
//	printf("***************1.开始游戏****************\n");
//	printf("*****************************************\n");
//
//}
////游戏实现
//void game()
//{
//	int put = rand() % 100 + 1;//随机获取1-100的数
//	int b;
//	printf("请猜一个数字>:");
//	while (1)
//	{
//		scanf("%d", &b); //接收用户输入的数值
//		 //与随机数比较给出提示
//		if (b > put)
//			printf("猜大了\n");
//		else if (b < put)
//			printf("猜小了\n");
//		else//猜对就退出循环
//		{
//			printf("恭喜你，猜对了\n");
//			break;
//		}
//}
//}
//int main()
//{
//	int  iput = 0;
//	srand((unsigned int)time(NULL)); //随机数初始化
//	do
//	{
//		
//		menu();   //打印菜单
//		printf("请选择>:");
//		scanf("%d", &iput);
//		switch(iput)
//		{
//			case 1:
//				game();
//				break;
//			case 0:
//				printf("退出成功\n");
//				break;
//			default:
//				printf("输入错误，请重新选择\n");
//		}
//
//	} while (iput);
//	return 0;
//}




////编写程序数一下 1到 100 的所有整数中出现多少个数字9
//#include<stdio.h>
//
//int main()
//{
//	int i = 1;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 9 == 0 || (i>10&&(i / 10) % 9 == 0))
//		{
//			count++;
//		}
//	}
//	printf("%d\n ",count);
//	return 0;
//}


//计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值，打印出结果
//#include<stdio.h>
//
//int main()
//{
//	int i = 1;
//	double sum = 0.0;
//	int j = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += j*1.0 / i;
//		j = -j;
//	}
//	printf("%lf", sum);
//	return 0;
//}
//
//int main()
//{
//	int i = 1;
//	double sum = 0.0;
//	int j = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 1)
//		{
//			sum += 1.0 / i;
//		}
//		else
//			sum += -1 * 1.0 / i;
//	}
//	printf("%lf", sum);
//	return 0;
//}
//


//求10 个整数中最大值
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int max = arr[0];
//	for (i = 0; i < 10; i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d", max);
//	return 0;
//}
//



//// 在屏幕上输出9 * 9乘法口诀表
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%-d*%-d=%-d ",j,i ,i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//编写代码在一个整形有序数组中查找具体的某个数
//要求：找到了就打印数字所在的下标，找不到则输出：找不到。
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 5;
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0])-1;
//	while (left < right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，下标为%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}