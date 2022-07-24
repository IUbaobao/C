#define _CRT_SECURE_NO_WARNINGS


//#include<stdio.h>
//
//int Add(int num1, int num2) {
//    // write code here 
//    int sum = num1;
//    while (num2)//进位为零结束
//    {
//        sum = num1 ^ num2;//计算当前位的和
//        num2 = (num1 & num2) << 1;//计算进位
//        num1 = sum;
//    }
//    return sum;
//}
//int main()
//{
//    Add(3, 0);
//    return 0;
//}

//给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间[1, n] 内。请你找出所有在[1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
//
//示例 1：
//
//输入：nums = [4, 3, 2, 7, 8, 2, 3, 1]
//输出：[5, 6]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array

//#include<stdio.h>
//#include<stdlib.h>
//
//int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
//
//    int* a = (int*)malloc(sizeof(int) * (numsSize + 1));
//
//    for (int i = 0; i < numsSize; i++)
//    {
//        a[nums[i]] = 1;//记录出现元素
//    }
//    int k = 0;
//    for (int i = 1; i <= numsSize; i++)
//    {
//        if (a[i] != 1)//输出未出现的
//            a[k++] = i;
//    }
//    *returnSize = k;
//    return a;
//}
//int main()
//{
//
//    int a[] = { 4, 3, 2, 7, 8, 2, 3, 1 };
//    int i = 0;
//    int *b=findDisappearedNumbers(a, sizeof(a) / sizeof(a[0]), &i);
//    for (int j = 0; j < i; j++)
//    {
//        printf("%d ", b[j]);
//    }
//    return 0;
//}


//输入: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
//输出 : [5, 6, 7, 1, 2, 3, 4]
//解释 :
//    向右轮转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//    向右轮转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//    向右轮转 3 步 : [5, 6, 7, 1, 2, 3, 4]
//
//    来源：力扣（LeetCode）
//    链接：https ://leetcode.cn/problems/rotate-array
//

void Reverse(int* a, int left, int right)
{
    while (left < right)
    {
        int tem = a[left];
        a[left] = a[right];
        a[right] = tem;
        left++;
        right--;
    }
}


void rotate(int* nums, int numsSize, int k) {

    k %= numsSize;

    //先逆置前n-k个
    Reverse(nums, 0, numsSize - k - 1);
    //再逆置最后k个
    Reverse(nums, numsSize - k, numsSize - 1);
    //整体再逆置
    Reverse(nums, 0, numsSize - 1);
}