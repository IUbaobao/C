#define _CRT_SECURE_NO_WARNINGS 

//给定一个长度为 n 的非降序数组和一个非负数整数 k ，要求统计 k 在数组中出现的次数
//
//数据范围：0 \le n \le 1000, 0 \le k \le 1000≤n≤1000, 0≤k≤100，数组中每个元素的值满足 0 \le val \le 1000≤val≤100
//要求：空间复杂度 O(1)O(1)，时间复杂度 O(logn)O(logn)
//示例1
//输入：
//[1, 2, 3, 3, 3, 3, 4, 5], 3
//返回值：
//4
//int GetNumberOfK(int* data, int dataLen, int k) {
//    // write code here
//    int left = 0;
//    int right = dataLen - 1;
//    int count = 0;
//    while (left <= right)
//    {
//        int mid = (left + right) / 2;
//        if (data[mid] > k)
//            right = mid - 1;
//        else if (data[mid] < k)
//            left = mid + 1;
//        else//找到之后，分别从该位置向前后找合适的数
//        {
//            count++;
//            int tem = mid;
//            while (data[--tem] == k && tem >= 0)//往前找
//                count++;
//            tem = mid;
//            while (data[++tem] == k && tem < dataLen)//往后找
//                count++;
//            return count;
//        }
//    }
//    //不满足left<right跳出，不存在这样的k值
//    return 0;
//}

//
//#include<stdio.h>
//test()
//{
//	printf("haha\n");
//	return 2.1;
// }
//int main()
//{
//	int i = 0;
//	//	for (i = 0; i || i++ < 5;);
//	do {
//		printf("hehe\n");
//	} while (0);
//	i=test();
//	printf("%d", i);
//	return 0;
//
//}
//给你一个整数数组 nums ，其中总是存在 唯一的 一个最大整数 。
//
//请你找出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍 。如果是，则返回 最大元素的下标 ，否则返回 - 1 。
//
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/largest-number-at-least-twice-of-others
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
int dominantIndex(int* nums, int numsSize) {

    int i = 0;
    int max = 0;
    int j = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (max < nums[i])
        {
            max = nums[i];
            j = i;//记录它的下标
        }
    }
    for (i = 0; i < numsSize; i++)
    {
        if (i != j)//依次将非最大值*2与max比较
        {
            if (nums[i] * 2 > max)
                return -1;
        }
    }
    return j;
}
