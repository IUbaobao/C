#define _CRT_SECURE_NO_WARNINGS

//验证尼科彻斯定理，即：任何一个整数m的立方都可以写成m个连续奇数之和。
//
//例如：
//
//1 ^ 3 = 1
//
//2 ^ 3 = 3 + 5
//
//3 ^ 3 = 7 + 9 + 11
//
//4 ^ 3 = 13 + 15 + 17 + 19
//
//输入一个正整数m（m≤100），将m的立方写成m个连续奇数之和的形式输出。
//数据范围：1\le m\le 100\1≤m≤100
//进阶：时间复杂度：O(m)\O(m) ，空间复杂度：O(1)\O(1)
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        int i = 1;
//        int sum = 0;
//        for (i = 1; i <= pow(n, 3); i += 2)
//        {
//            sum = 0;
//            int j = 0;
//            int k = i;
//            for (j = 0; j < n; j++)
//            {
//                if (j == 0)
//                    sum = sum + k;
//                else
//                    sum = sum + k ;
//                k += 2;
//            }
//            k = 0;
//            if (sum == (int)pow(n, 3))
//            {
//                for (j = 0; j < n; j++)
//                {
//                    if (j == n - 1)
//                        printf("%d", i + k);
//                    else
//                        printf("%d+", i + k);
//                    k += 2;
//                }
//            }
//        }
//    }
//    return 0;
//}


//
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//    int m = 0;
//    while (scanf("%d", &m) != EOF)
//    {
//        int sum = pow(m, 3);
//        int i = 1;
//        for (i = 1; i < sum; i += 2)
//        {
//            int j = 0;
//            int k = 0;
//            if (sum == (m * i + m * (m - 1)))//等差数列求和sn=n*a1+n*（n-1）/2*d
//            {
//                for (j = 0; j < m; j++)
//                {
//                    if (j == m - 1)
//                        printf("%d", i + k);
//                    else
//                        printf("%d+", i + k);
//                    k += 2;
//                }
//            }
//        }
//    }
//    return 0;
//}
//
//
//等差数列 2，5，8，11，14。。。。
//（从 2 开始的 3 为公差的等差数列）
//输出求等差数列前n项和


//#include<stdio.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int sum = 0;
//    int i = 2;
//    while (n--)
//    {
//        sum += i;
//        i += 3;
//    }
//    printf("%d\n", sum);
//    return 0;
//}
//#include<stdio.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int sum = n * 2 + n * (n - 1) / 2 * 3;
//
//    printf("%d\n", sum);
//    return 0;
//}
//#include<stdio.h>
//int i;
//void prt()
//{
//	for (i = 5; i < 8; i++)
//		printf("%c", '*');
//	printf("\t");
//} 
//int main()
//{
//	for (i = 5; i <= 8; i++)
//		prt();
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 3;
//	printf("%d\n", (a += a -= a * a));
//
//}



//首先输入要输入的整数个数n，然后输入n个整数。输出为n个整数中负数的个数，和所有正整数的平均值，结果保留一位小数。
//0即不是正整数，也不是负数，不计入计算。如果没有正数，则平均值为0。
//#include<stdio.h>
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    int arr[n];
//    int i = 0;
//    int count1 = 0;
//    int count2 = 0;
//    float sum = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//        if (arr[i] < 0)
//            count1++;;
//        if (arr[i] > 0)
//        {
//            count2++;
//            sum += arr[i];
//        }
//    }
//    if (count2 != 0)
//        sum /= count2;
//
//    printf("%d %0.1f", count1, sum);
//    return 0;
//}
//
// 
// 
//// 有一个长度为 n 的非降序数组，比如[1,2,3,4,5]，将它进行旋转，即把一个数组最开始的若干个元素搬到数组的末尾，变成一个旋转数组，比如变成了[3,4,5,1,2]，或者[4,5,1,2,3]这样的。请问，给定这样一个旋转数组，求数组中的最小值。
//
//数据范围：1 \le n \le 100001≤n≤10000，数组中任意元素的值: 0 \le val \le 100000≤val≤10000
//要求：空间复杂度：O(1)O(1) ，时间复杂度：O(logn)O(logn)
//示例1
//输入：
//[3, 4, 5, 1, 2]
//复制
//返回值：
//1
//#include<stdio.h>
//int minNumberInRotateArray(int* rotateArray, int rotateArrayLen) {
//    // write code here
//    int left = 0;
//    int right = rotateArrayLen - 1;
//    int k = (left + right) / 2;
//    while (left < right)
//    {
//        k = (left + right) / 2;
//        if (rotateArray[k] > rotateArray[right])
//            left = k + 1;
//        else if (rotateArray[k] < rotateArray[right])
//            right = k;
//        else if (rotateArray[k] == rotateArray[right])
//            right--;
//
//    }
//    return rotateArray[right];
//}
//int main()
//{
//    int a[5] = { 1,0,1,1,1 };
//    int n=minNumberInRotateArray(a, 5);
//    printf("%d", n);
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int n = 0, c = 0;
//	scanf("%d%d", &n, &c);
//	int a[1000];
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	int j = 0;
//	int count = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			if (c == a[i] - a[j])
//				count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}


/*#include<stdio.h>

int main()
{
	char ch = 'a';
	int n = 0;
	for (n=0;  getchar() != '\n'; n++)
	{
		
	}
//	printf("%d", n);
////	r*/
//}
#include<stdio.h>
//int main()
//{
//	int m, n;
//	printf("Enter m,n;");
//	scanf("%d%d", &m, &n);
//	while (m != n) //1
//	{
//		while (m > n) m = m - n; //2
//		while (n > m) n = n - m; //3
//	}
//	printf("m=%d\n", m);
//	return 0;
//}

int main()
{
	int n = 2;
	char ch;
	do {
		switch (ch = getchar())
		{
		case 2:
		case 1:
			printf("hehe\n");
		default:
			printf("haha\n");
		}

	} while (ch != '\n');

}