#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
//void func()
//{
//	int k = 1 ^ (1 << 31 >> 31);
//	printf("%d\n", k);
//}
//int main()
//{
//	//double a = 3.0;
//	//a %= 2;  double����ȡģ��int���Ͳſ���
//	//func();
//	//printf("%ld", a);
//	int i = 1;
//	int b=sizeof(i++);
//	printf("%d\n", i);
//	printf("%d", b);
//	return 0;
//}



//
//����һ������������ nums �� ��������������� 1 �ĸ�����
//
//ʾ�� 1��
//
//���룺nums = [1, 1, 0, 1, 1, 1]
//�����3
//���ͣ���ͷ����λ��������λ�������� 1 ������������� 1 �ĸ����� 3.
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/max-consecutive-ones
//
//int findMaxConsecutiveOnes(int* nums, int numsSize) {
//
//    int count = 0;
//    int max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == 1)//ͳ������1�ĸ���
//            count++;
//        else
//        {
//            if (max < count)//ȡ��ı���
//                max = count;
//            count = 0;
//        }
//    }
//    if (max < count)//�ж�ѭ������ʱ��count�Ƿ������
//        max = count;
//
//    return max;
//}


//
//��ȫ����Perfect number�����ֳ����������걸������һЩ�������Ȼ����
//
//�����е������ӣ����������������Լ�����ĺͣ������Ӻ�������ǡ�õ���������
//
//���磺28������Լ��1��2��4��7��14��28����ȥ������28�⣬����5������ӣ�1 + 2 + 4 + 7 + 14 = 28��
//
//����n�������n����(��n)��ȫ���ĸ�����
//
//���ݷ�Χ�� 1 \le n \le 5 \times 10 ^ {5} \1��n��5��10
//5
//
//����������
//����һ������n
//
//���������
//���������n����ȫ���ĸ���
//
//ʾ��1
//���룺
//1000
//
//�����
//3

#include<stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int sum = 0;
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        sum = 0;
        for (int j = 1; j < n / 2; j++)
        {
            if (i % j == 0 && i != j)//�ѿ��������ļ�����
                sum += j;
        }
        if (sum == i)//�Ƚ��Ƿ����
            count++;
    }
    printf("%d\n", count);
    return 0;
}