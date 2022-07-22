#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//
//int main()
//{
//	int x = 0;
//	int b=((x = 2 * 5, x + 5), x + 6);
//	printf("%d\n", x);
//	printf("%d\n", b);
//	return 0;
//}



//自除数?是指可以被它包含的每一位数整除的数。
//
//例如，128 是一个 自除数 ，因为?128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
//自除数 不允许包含 0 。
//
//给定两个整数?left?和?right ，返回一个列表，列表的元素是范围?[left, right]?内所有的 自除数 。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/self-dividing-numbers
//
//int* selfDividingNumbers(int left, int right, int* returnSize) {
//
//    int* a = (int*)malloc(sizeof(int) * (right - left));
//    int pos = 0;
//    for (int i = left; i <= right; i++)
//    {
//        int j = i;
//        int flag = 1;//标记是否能整除
//        while (j)
//        {
//            if (j % 10 == 0)//含零不为自除数
//            {
//                flag = 0; break;
//            }
//            if (j % 10 != 0)
//            {
//                if (i % (j % 10) != 0)//自除不为零不为自除数
//                {
//                    flag = 0;
//                    break;
//                }
//            }
//            j /= 10;
//        }
//        if (flag == 1)
//            a[pos++] = i;
//    }
//    *returnSize = pos;
//    return a;
//}

//给你一个整数数组?nums，返回 数组?answer?，其中?answer[i]?等于?nums?中除?nums[i]?之外其余各元素的乘积?。
//
//题目数据 保证 数组?nums之中任意元素的全部前缀元素和后缀的乘积都在? 32 位 整数范围内。
//
//请不要使用除法，且在?O(n) 时间复杂度内完成此题。
//
//
//
//示例 1:
//
//输入: nums = [1, 2, 3, 4]
//输出 : [24, 12, 8, 6]
//示例 2 :
//
//	输入 : nums = [-1, 1, 0, -3, 3]
//	输出 : [0, 0, 9, 0, 0]
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode.cn/problems/product-of-array-except-self

//
//int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
//
//    int L[numsSize];
//    int R[numsSize];
//    int* a = (int*)malloc(sizeof(int) * numsSize);
//    L[0] = 1;
//    for (int i = 1; i < numsSize; i++)//所有前缀乘积
//    {
//        L[i] = nums[i - 1] * L[i - 1];
//    }
//    R[numsSize - 1] = 1;
//    for (int i = numsSize - 2; i >= 0; i--)//所有后缀乘积
//    {
//        R[i] = nums[i + 1] * R[i + 1];
//    }
//    for (int i = 0; i < numsSize; i++)//自身除外的乘积
//    {
//        a[i] = R[i] * L[i];
//    }
//    *returnSize = numsSize;
//    return a;
//}