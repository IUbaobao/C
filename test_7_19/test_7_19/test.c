#define _CRT_SECURE_NO_WARNINGS 

//����һ������Ϊ n �ķǽ��������һ���Ǹ������� k ��Ҫ��ͳ�� k �������г��ֵĴ���
//
//���ݷ�Χ��0 \le n \le 1000, 0 \le k \le 1000��n��1000, 0��k��100��������ÿ��Ԫ�ص�ֵ���� 0 \le val \le 1000��val��100
//Ҫ�󣺿ռ临�Ӷ� O(1)O(1)��ʱ�临�Ӷ� O(logn)O(logn)
//ʾ��1
//���룺
//[1, 2, 3, 3, 3, 3, 4, 5], 3
//����ֵ��
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
//        else//�ҵ�֮�󣬷ֱ�Ӹ�λ����ǰ���Һ��ʵ���
//        {
//            count++;
//            int tem = mid;
//            while (data[--tem] == k && tem >= 0)//��ǰ��
//                count++;
//            tem = mid;
//            while (data[++tem] == k && tem < dataLen)//������
//                count++;
//            return count;
//        }
//    }
//    //������left<right������������������kֵ
//    return 0;
//}


#include<stdio.h>
test()
{
	printf("haha\n");
	return 2.1;
 }
int main()
{
	int i = 0;
	//	for (i = 0; i || i++ < 5;);
	do {
		printf("hehe\n");
	} while (0);
	i=test();
	printf("%d", i);
	return 0;

}