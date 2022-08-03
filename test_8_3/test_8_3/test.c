#define _CRT_SECURE_NO_WARNINGS


//#include<stdio.h>
//
//int fun(unsigned int x)
//{
//	int n = 0;
//	while (x + 1)
//	{
//		n++;
//		x = x | (x + 1);
//	} 
//		return n;
//}
//int main()
//{
//	//printf("%d", fun(2014));
//	//int a[3] = { 1,2,3 },*p=a;
//	//printf("%d", *(++p));
//	return 0;
//}

//有一种兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子。
//例子：假设一只兔子第3个月出生，那么它第5个月开始会每个月生一只兔子。
//一月的时候有一只兔子，假如兔子都不死，问第n个月的兔子总数为多少？
//数据范围：输入满足 1 \le n \le 31 \1≤n≤31

//#include<stdio.h>
//
//int fun(n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	return fun(n - 1) + fun(n - 2);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	printf("%d\n", fun(n));
//	return 0;
//}

#include<stdio.h>
#include<math.h>
int main()
{
    double n, m;
    while (scanf("%lf%lf", &n, &m) == 2)
    {
        double sum = 0;
        while (m--)
        {
            sum += n;
            n = sqrt(n);
        }
        printf("%f\n", sum);

    }
    return 0;
}