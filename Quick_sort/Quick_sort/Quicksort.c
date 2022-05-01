#define _CRT_SECURE_NO_WARNINGS
//

#include <stdio.h>
#include <stdlib.h>
//����˼��
//
//1ѡ��Pivot������
//2������Pivot�����ַ���Pivot���ұ�
//3��С��Pivot�����ַ���Pivot�����
//4�ֱ�������������ظ�ǰ��������
//LΪҪ�������ʼ�±꣬RΪ����Ҫ�����Ԫ�ص��±�
void QuickSort(int arr[], int L, int R)
{
	if (L >= R)			//�趨��������
		return;
	int right = R;	//��������洢�������ʼλ�ú�ĩβ
	int left = L;
	int point = arr[L];//ѡ��������
	while (left < right)
	{
		while (left < right && point <= arr[right])
		{								//��left<right�����£��ѱ��������ķ����ұߣ�С�ķ������
			right--;		//�����������������������������ұߣ�������ƶ�right
		}
		if (left < right)	//�����������ѭ������һ������Ϊrightָ���ֵ��������С������Ҫ�����ƶ������	
		{
			arr[left++] = arr[right];
		}
		while (left < right && point > arr[left])
		{
			left++;//��������������С����������������ߣ�������ƶ�left
		}
		if (left < right)//ͬ�������������ѭ������һ������Ϊleftָ���ֵ�������������Ҫ�����ƶ����ұ�		
		{
			arr[right--] = arr[left];
		}	//��������ƶ���ͬһλ�ã��ͰѸղ�ѡ���������������λ����
		arr[left] = point;
	}
	//�����Ѿ�����һ�����򣬷ֳ����飬һ��������������ߣ�һ���������С�����ұ�
	QuickSort(arr, L, right - 1);//�ݹ齫��ߵĽ�������
	QuickSort(arr, right + 1, R);//�ݹ齫�ұߵĽ�������
}


int main()
{
	int arr[] = { 4,49,9,5,2,3,1,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, sz-1);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

