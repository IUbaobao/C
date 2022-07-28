#define _CRT_SECURE_NO_WARNINGS


//����һ������ nums?��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ����?val?��Ԫ�أ��������Ƴ���������³��ȡ�
//
//��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣
//
//Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/remove-element
//

//int removeElement(int* nums, int numsSize, int val) {
//
//    int src = 0, des = 0;
//    while (src < numsSize)
//    {
//        if (nums[src] != val)//˫�±���ԭ����
//        {
//            nums[des++] = nums[src++];
//        }
//        else
//            src++;
//    }
//
//    return des;
//}


//����һ�� �������� ������ nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ��
//����ɾ����������³��ȡ�Ԫ�ص� ���˳�� Ӧ�ñ��� һ�� ��
//���룺nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
//�����5, nums = [0, 1, 2, 3, 4]

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


//�ϲ�������������
//���������� �ǵݼ�˳�� ���е���������?nums1 �� nums2�������������� m �� n ���ֱ��ʾ nums1 �� nums2 �е�Ԫ����Ŀ��
//
//���� �ϲ� nums2 �� nums1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�

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

    //num2û����
    while (end2 >= 0)
    {
        nums1[i--] = nums2[end2--];
    }
}