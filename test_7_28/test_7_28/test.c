#define _CRT_SECURE_NO_WARNINGS


//给你一个数组 nums?和一个值 val，你需要 原地 移除所有数值等于?val?的元素，并返回移除后数组的新长度。
//
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/remove-element
//

//int removeElement(int* nums, int numsSize, int val) {
//
//    int src = 0, des = 0;
//    while (src < numsSize)
//    {
//        if (nums[src] != val)//双下标在原地找
//        {
//            nums[des++] = nums[src++];
//        }
//        else
//            src++;
//    }
//
//    return des;
//}


//给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，
//返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
//输入：nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
//输出：5, nums = [0, 1, 2, 3, 4]

//int removeDuplicates(int* nums, int numsSize) {
//    int des = 0, src = 0;
//    while (src < numsSize)
//    {
//        if (nums[src] != nums[des])
//        {
//            nums[++des] = nums[src++];
//        }
//        else
//        {
//            src++;
//        }
//    }
//
//    return des + 1;
//}


//合并两个有序数组
//给你两个按 非递减顺序 排列的整数数组?nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int end1 = m - 1, end2 = n - 1, i = m + n - 1;

    while (end1 >= 0 && end2 >= 0)
    {
        if (nums1[end1] > nums2[end2])
        {
            nums1[i--] = nums1[end1--];
        }
        else
        {
            nums1[i--] = nums2[end2--];
        }
    }

    //num2没结束
    while (end2 >= 0)
    {
        nums1[i--] = nums2[end2--];
    }
}