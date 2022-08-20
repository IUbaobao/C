#define _CRT_SECURE_NO_WARNINGS

//
//
//int findPeakElement(int* nums, int numsLen) {
//    // write code here
//    int max = nums[0];
//    int pos = 0;
//    for (int i = 0; i < numsLen; ++i)
//    {
//        if (max < nums[i])
//        {
//            max = nums[i];
//            pos = i;
//        }
//    }
//    return pos;
//}
//
//
//
//#include<stdio.h>
//
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    int a = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int b = 0;
//        scanf("%d", &b);
//        a ^= b;
//    }
//    printf("%d\n", a);
//
//    return 0;
//}