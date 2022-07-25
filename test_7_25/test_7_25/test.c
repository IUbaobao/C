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
//	//a %= 2;  double不能取模，int类型才可以
//	//func();
//	//printf("%ld", a);
//	int i = 1;
//	int b=sizeof(i++);
//	printf("%d\n", i);
//	printf("%d", b);
//	return 0;
//}



//
//给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。
//
//示例 1：
//
//输入：nums = [1, 1, 0, 1, 1, 1]
//输出：3
//解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/max-consecutive-ones
//
//int findMaxConsecutiveOnes(int* nums, int numsSize) {
//
//    int count = 0;
//    int max = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == 1)//统计连续1的个数
//            count++;
//        else
//        {
//            if (max < count)//取大的保存
//                max = count;
//            count = 0;
//        }
//    }
//    if (max < count)//判断循环结束时的count是否是最大
//        max = count;
//
//    return max;
//}


//
//完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
//
//它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
//
//例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1 + 2 + 4 + 7 + 14 = 28。
//
//输入n，请输出n以内(含n)完全数的个数。
//
//数据范围： 1 \le n \le 5 \times 10 ^ {5} \1≤n≤5×10
//5
//
//输入描述：
//输入一个数字n
//
//输出描述：
//输出不超过n的完全数的个数
//
//示例1
//输入：
//1000
//
//输出：
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
            if (i % j == 0 && i != j)//把可以整除的加起来
                sum += j;
        }
        if (sum == i)//比较是否相等
            count++;
    }
    printf("%d\n", count);
    return 0;
}