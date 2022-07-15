#define _CRT_SECURE_NO_WARNINGS


//
//集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且 有一个数字重复 。
//
//给定一个数组 nums 代表了集合 S 发生错误后的结果。
//
//请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
//
//
//
//示例 1：
//
//输入：nums = [1, 2, 2, 4]
//输出：[2, 3]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/set-mismatch
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include<stdio.h>
int cmp(int* a, int* b) {
    return *a - *b;
}


int* findErrorNums(int* nums, int numsSize, int* returnSize) {

    int i = 0;
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    int* a = (int*)malloc(sizeof(int) * 2);
    if (a == NULL)
    {
        printf("malloc file\n");
        return NULL;
    }
    int prev = 0;
    int cur = 0;
    for (i = 0; i < numsSize; i++)
    {
        cur = nums[i];
        if (cur == prev) {
            a[0] = prev;
        }
        else if (cur - prev > 1) {
            a[1] = prev + 1;
        }
        prev = cur;
    }
    if (nums[numsSize - 1] != numsSize) {
        a[1] = numsSize;
    }
    *returnSize = 2;
    return a;
}