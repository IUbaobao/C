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

//��һ�����ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӡ�
//���ӣ�����һֻ���ӵ�3���³�������ô����5���¿�ʼ��ÿ������һֻ���ӡ�
//һ�µ�ʱ����һֻ���ӣ��������Ӷ��������ʵ�n���µ���������Ϊ���٣�
//���ݷ�Χ���������� 1 \le n \le 31 \1��n��31

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