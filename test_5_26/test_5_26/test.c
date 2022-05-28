#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//
//
//void AdjustArr(int* p, int len)
//{
//	int left = 0;
//	int right = len - 1;
//	while (left < right)
//	{
//		//找出左边不为奇数的
//		while (p[left] % 2 != 0 && left < right)
//		{
//			left++;
//		}
//		//找出右边不为偶数的
//		while (p[right] % 2 == 0 && left < right)
//		{
//			right--;
//		}
//		//交换
//		if (p[left] % 2 == 0 && p[right] % 2 != 0 && left < right)
//		{
//			int tem = p[left];
//			p[left] = p[right];
//			p[right] = tem;
//		}
//	}
//}
//int main()
//{
//	int arr[10] = {0};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	//调整
//	AdjustArr(arr, sz);
//	
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//    char a[1000];
//    int i;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", strlen(a));
//    return 0;
//}





//#include<stdio.h>
//int main()
//{
//	int a = 20;
//	int b = -10;
//	return 0;
//}


////下面程序输出上面？
//#include <stdio.h>
//int main()
//{
//    char a = -128;
//    printf("%u\n", a);
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    char a = -1;
//    signed char b = -1;
//    unsigned char c = -1;
//    printf("a=%d,b=%d,c=%d", a, b, c);
//    return 0;
//}

//下面程序输出什么？
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    char a[1000];
//    int i;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", strlen(a));
//    return 0;
//}
// 


//
////下面程序输出什么？
//#include<stdio.h>
//int main()
//{
//	int n = 9;
//	float* pFloat = (float*)&n;
//	printf("n的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", *pFloat);
//	*pFloat = 9.0;
//	printf("num的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", *pFloat);
//	return 0;
//}


///*在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1
//…*/…
//#include<stdio.h>
//#define ROW 100
//#define COL 100
//int main()
//{
//	int arr[ROW][COL] = {0};
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int j = 0;
//	//初始化
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			if ( j == 0 || j == i)
//				arr[i][j] = 1;
//			else
//			arr[i][j] = 0;
//		}
//	}
//	//杨辉三角
//	for (i = 2; i < n; i++)
//	{
//		for (j = 1; j < n; j++)
//		{
//			if (j != 0 || j != i)
//			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//	//输出
//	int k = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (k = 0; k < n-i-1; k++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < n; j++)
//		{
//			if (arr[i][j] != 0)
//			{
//			
//				printf("%d ", arr[i][j]);
//			}
//		}
//		printf("\n");
//	}
//
//	return 0;
//}



//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
#include<stdio.h>
//暴力求解
int main()
{
	int a, b, c, d, e;
	for (a = 1; a <= 5; a++)
		for (b = 1; b <= 5; b++)
			for (c = 1; c <= 5; c++)
				for (d = 1; d <= 5; d++)
					for (e = 1; e <= 5; e++)					//因为每位选手都说对了一半，所以可以用逻辑“||”或来表示
						if (((b != 2 && a == 3)|| (b == 2 && a != 3))
							&& ((b != 2 && e == 4)|| (b == 2 && e != 4))
							&& ((c != 1 && d == 2) || (c == 1 && d != 2))
							&& ((c != 5 && d == 3)  || (c == 5 && d != 3))
							&& ((e != 4 && a == 1)   || (e == 4 && a != 1)) == 1)
						{
							if (a * b * c * d * e == 120)			//因为1*2*3*4*5=120，如果没有这个判断则会出现多种结果
								printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
						}


	return 0;
}