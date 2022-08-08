#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


void Swap(int* e1, int* e2)
{
	int tem = *e1;
	*e1 = *e2;
	*e2 = tem;
}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapSort(int* a, int n)
{
	int i = 0;
	//升序建大堆
	for (i = (n-1-1)/2; i >=0; --i)
	{
		AdjustDown(a, n,i);
	}
	//依次取大的往后放
	for (i = 0; i < n; i++)
	{
		Swap(&a[0], &a[n - 1 - i]);
		AdjustDown(a, n - i - 1,0);
	}
}

int main()
{
	int arr[] = { 1,5,7,3,2,1,8,23,43,65,67,87 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}