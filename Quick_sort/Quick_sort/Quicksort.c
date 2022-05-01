#define _CRT_SECURE_NO_WARNINGS
//

#include <stdio.h>
#include <stdlib.h>
//基本思想
//
//1选定Pivot中心轴
//2将大于Pivot的数字放在Pivot的右边
//3将小于Pivot的数字放在Pivot的左边
//4分别对左右子序列重复前三步操作
//L为要排序的起始下标，R为数组要排最后元素的下标
void QuickSort(int arr[], int L, int R)
{
	if (L >= R)			//设定结束条件
		return;
	int right = R;	//另设变量存储数组的起始位置和末尾
	int left = L;
	int point = arr[L];//选定中心轴
	while (left < right)
	{
		while (left < right && point <= arr[right])
		{								//在left<right条件下，把比中心轴大的放在右边，小的放在左边
			right--;		//如果本身比中心轴大的数就在中心轴右边，则继续移动right
		}
		if (left < right)	//如果跳出上面循环，则一定是因为right指向的值比中心轴小，则需要把它移动到左边	
		{
			arr[left++] = arr[right];
		}
		while (left < right && point > arr[left])
		{
			left++;//如果本身比中心轴小的数就在中心轴左边，则继续移动left
		}
		if (left < right)//同样如果跳出上面循环，则一定是因为left指向的值比中心轴大，则需要把它移动到右边		
		{
			arr[right--] = arr[left];
		}	//最后两数移动到同一位置，就把刚才选中心轴的数放在这位置上
		arr[left] = point;
	}
	//上面已经进行一次排序，分成两组，一组比中心轴大，在左边，一组比中心轴小，在右边
	QuickSort(arr, L, right - 1);//递归将左边的进行排序
	QuickSort(arr, right + 1, R);//递归将右边的进行排序
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

