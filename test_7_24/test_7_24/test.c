#define _CRT_SECURE_NO_WARNINGS


//#include<stdio.h>
//
//int Add(int num1, int num2) {
//    // write code here 
//    int sum = num1;
//    while (num2)//��λΪ�����
//    {
//        sum = num1 ^ num2;//���㵱ǰλ�ĺ�
//        num2 = (num1 & num2) << 1;//�����λ
//        num1 = sum;
//    }
//    return sum;
//}
//int main()
//{
//    Add(3, 0);
//    return 0;
//}

//����һ���� n ������������ nums ������ nums[i] ������[1, n] �ڡ������ҳ�������[1, n] ��Χ�ڵ�û�г����� nums �е����֣������������ʽ���ؽ����
//
//ʾ�� 1��
//
//���룺nums = [4, 3, 2, 7, 8, 2, 3, 1]
//�����[5, 6]
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array

//#include<stdio.h>
//#include<stdlib.h>
//
//int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
//
//    int* a = (int*)malloc(sizeof(int) * (numsSize + 1));
//
//    for (int i = 0; i < numsSize; i++)
//    {
//        a[nums[i]] = 1;//��¼����Ԫ��
//    }
//    int k = 0;
//    for (int i = 1; i <= numsSize; i++)
//    {
//        if (a[i] != 1)//���δ���ֵ�
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


//����: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
//��� : [5, 6, 7, 1, 2, 3, 4]
//���� :
//    ������ת 1 �� : [7, 1, 2, 3, 4, 5, 6]
//    ������ת 2 �� : [6, 7, 1, 2, 3, 4, 5]
//    ������ת 3 �� : [5, 6, 7, 1, 2, 3, 4]
//
//    ��Դ�����ۣ�LeetCode��
//    ���ӣ�https ://leetcode.cn/problems/rotate-array
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

    //������ǰn-k��
    Reverse(nums, 0, numsSize - k - 1);
    //���������k��
    Reverse(nums, numsSize - k, numsSize - 1);
    //����������
    Reverse(nums, 0, numsSize - 1);
}