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



//�Գ���?��ָ���Ա���������ÿһλ������������
//
//���磬128 ��һ�� �Գ��� ����Ϊ?128 % 1 == 0��128 % 2 == 0��128 % 8 == 0��
//�Գ��� ��������� 0 ��
//
//������������?left?��?right ������һ���б��б��Ԫ���Ƿ�Χ?[left, right]?�����е� �Գ��� ��
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/self-dividing-numbers
//
//int* selfDividingNumbers(int left, int right, int* returnSize) {
//
//    int* a = (int*)malloc(sizeof(int) * (right - left));
//    int pos = 0;
//    for (int i = left; i <= right; i++)
//    {
//        int j = i;
//        int flag = 1;//����Ƿ�������
//        while (j)
//        {
//            if (j % 10 == 0)//���㲻Ϊ�Գ���
//            {
//                flag = 0; break;
//            }
//            if (j % 10 != 0)
//            {
//                if (i % (j % 10) != 0)//�Գ���Ϊ�㲻Ϊ�Գ���
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

//����һ����������?nums������ ����?answer?������?answer[i]?����?nums?�г�?nums[i]?֮�������Ԫ�صĳ˻�?��
//
//��Ŀ���� ��֤ ����?nums֮������Ԫ�ص�ȫ��ǰ׺Ԫ�غͺ�׺�ĳ˻�����? 32 λ ������Χ�ڡ�
//
//�벻Ҫʹ�ó���������?O(n) ʱ�临�Ӷ�����ɴ��⡣
//
//
//
//ʾ�� 1:
//
//����: nums = [1, 2, 3, 4]
//��� : [24, 12, 8, 6]
//ʾ�� 2 :
//
//	���� : nums = [-1, 1, 0, -3, 3]
//	��� : [0, 0, 9, 0, 0]
//
//	��Դ�����ۣ�LeetCode��
//	���ӣ�https ://leetcode.cn/problems/product-of-array-except-self

//
//int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
//
//    int L[numsSize];
//    int R[numsSize];
//    int* a = (int*)malloc(sizeof(int) * numsSize);
//    L[0] = 1;
//    for (int i = 1; i < numsSize; i++)//����ǰ׺�˻�
//    {
//        L[i] = nums[i - 1] * L[i - 1];
//    }
//    R[numsSize - 1] = 1;
//    for (int i = numsSize - 2; i >= 0; i--)//���к�׺�˻�
//    {
//        R[i] = nums[i + 1] * R[i + 1];
//    }
//    for (int i = 0; i < numsSize; i++)//�������ĳ˻�
//    {
//        a[i] = R[i] * L[i];
//    }
//    *returnSize = numsSize;
//    return a;
//}