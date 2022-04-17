#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
//����˼��
//
//1ѡ��Pivot������
//2������Pivot�����ַ���Pivot���ұ�
//3��С��Pivot�����ַ���Pivot�����
//4�ֱ�������������ظ�ǰ��������
void Quicksort(int arr[], int L, int R)
{
	if (L >= R)			//�趨��������
		return;
	int right = R;	//��������洢�������ʼλ�ú�ĩβ
	int left = L;
	int point = arr[L];//ѡ��������
	while (left < right && point <= arr[right])
	{								//��left<right�����£��ѱ��������ķ����ұߣ�С�ķ������
		right--;		//�����������������������������ұߣ�������ƶ�right
	}
	if (left < right)	//�����������ѭ������һ������Ϊrightָ���ֵ��������С������Ҫ�����ƶ������	
	{
		arr[left] = arr[right];
	}
	while (left < right && point > arr[left])
	{
		left++;//��������������С����������������ߣ�������ƶ�left
	}
	if (left < right)//ͬ�������������ѭ������һ������Ϊleftָ���ֵ�������������Ҫ�����ƶ����ұ�		
	{
		arr[right] = arr[left];
	}
	if (right == left)		//��������ƶ���ͬһλ�ã��ͰѸղ�ѡ���������������λ����
	{
		arr[right] = point;
	}//�����Ѿ�����һ�����򣬷ֳ����飬һ��������������ߣ�һ���������С�����ұ�
	Quicksort(arr, L, right - 1);//�ݹ齫��ߵĽ�������
	Quicksort(arr, right + 1, R);//�ݹ齫�ұߵĽ�������
}
int main()
{
	int arr[10] = { 2,1,3,4,5,6,9,7,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]) - 1;
	Quicksort(arr, 0, sz);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}