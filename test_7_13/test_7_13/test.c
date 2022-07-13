#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//char* GetMemory(void)
//{
//	char* p = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
//
//
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char a[] = "\141\t";
//	printf("%s", a);
//	double b = 0.0;
//	if (b == 0.0f)
//		printf("==");
//	else
//		printf("!=");
//	return 0;
//}
//
//输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
//1. 用返回一个整数列表来代替打印
//2. n 为正整数，0 < n <= 5
//int* printNumbers(int n, int* returnSize) {
//    // write code here
//    int k = 1;
//    int sum = 0;
//    while (n--)//计算最大值
//    {
//        sum += 9 * k;
//        k *= 10;
//    }
//    int* a = (int*)malloc(sizeof(int) * sum);
//    if (a == NULL)
//    {
//        printf("malloc file!\n");
//        return NULL;
//    }
//    int i = 0;
//    for (i = 1; i <= sum; i++)//赋值
//    {
//        a[i - 1] = i;
//    }
//    *returnSize = sum;
//    return a;
//}

#include<stdio.h>
int main()
{
    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    if (y < 1000 || y>9999 && m > 12 || m < 1 || d < 1 || d>31)
    {
        printf("日期非法\n");
        return 1;
    }
    int sum = 0;
    switch (m - 1)
    {
    case 12:
        sum += 31;
    case 11:
        sum += 30;
    case 10:
        sum += 31;
    case 9:
        sum += 30;
    case 8:
        sum += 31;
    case 7:
        sum += 31;
    case 6:
        sum += 30;
    case 5:
        sum += 31;
    case 4:
        sum += 30;
    case 3:
        sum += 31;
    case 2:
        if (y % 100 != 0 && y % 4 == 0 || y % 400 == 0)
            sum += 29;
        else
            sum += 28;
    case 1:
        sum += 31;
        break;
    }
    sum += d;
    printf("%d\n", sum);
    return 0;
}