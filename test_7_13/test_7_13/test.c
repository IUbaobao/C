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
//�������� n����˳���ӡ���� 1 ������ n λʮ���������������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��
//1. �÷���һ�������б��������ӡ
//2. n Ϊ��������0 < n <= 5
//int* printNumbers(int n, int* returnSize) {
//    // write code here
//    int k = 1;
//    int sum = 0;
//    while (n--)//�������ֵ
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
//    for (i = 1; i <= sum; i++)//��ֵ
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
        printf("���ڷǷ�\n");
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