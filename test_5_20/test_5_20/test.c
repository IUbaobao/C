#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void Swap(int* p1, int* p2)
{
	int tem = *p1;
	*p1 = *p2;
	*p2 = tem;
}
//向下调整算法     前提是首先得满足左右子数为大（小）堆
//可以先从最后一个非叶子节点开始调整，因为那样就保证的左右子数为堆
void AdjustDown(int* p, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1; //默认是左孩子
	while (child < n )
	{
		//child+1<n   避免它最后那个非叶子节点没有右孩子的时候越界
		if (child + 1 < n && p[child + 1] > p[child])
		{
			child++;
		}
		if (p[child] > p[parent])
		{
			Swap(&p[child], &p[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//堆排序
void HeapSort(int* p, int n)
{
	int i = 0;
	//建堆     排升序建大堆
	for (i = (n-1-1)/2; i>=0; i--)
	{
		AdjustDown(p, n, i);
	}
	//将最大的哪个换到最后，然后再向下调整找出次大的，依次重复操作
	for (i = n-1; i>=0; i--)
	{
		Swap(&p[0], &p[i]);
		AdjustDown(p,i, 0);
	}
}


//插入排序
void InsertSort(int* p, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int tem = p[end + 1];

		while (end >= 0)
		{
			if (p[end] > tem)
			{
				p[end + 1] = p[end];
				end = end - 1;
			}
			else
			{
				break;
			}
		}
		p[end + 1] = tem;
	}
	
}
//希尔排序
void ShellSort(int* p, int n)
{
	int i = 0;
	int gap = n;
	while (gap>1)
	{
		gap = gap / 3 + 1;
		for (i = 0; i < n - gap; i++)
		{
			int end = i;
			int tem = p[end + gap];

			while (end >= 0)
			{
				if (p[end] > tem)
				{
					p[end + gap] = p[end];
					end = end - gap;
				}
				else
				{
					break;
				}
			}
			p[end + gap] = tem;
		}
	}
}

//快速排序
void QuickSort(int* p, int L, int R)
{
	if (L >= R)
		return;

	int left = L;
	int right = R;
	int point = p[left];
	while (left < right)
	{
		while (left < right && p[right] >= point)
		{
			right--;
		}
		if (p[right] < point)
		{
			p[left++] = p[right];
		}
		while (left < right && p[left] <= point)
		{
			left++;
		}
		if (p[left] > point)
		{
			p[right--] = p[left];
		}
		p[left] = point;
	}
	
	QuickSort(p, L, right - 1);
	QuickSort(p, left + 1, R);

}

//冒泡排序
void BBsort(int* p, int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (p[j] > p[j + 1])
			{
				int tem = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tem;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

int main()
{
	int arr[] = { 3,4,5,2,6,1,9,0,7,8 };
	int arr1[] = { 3,4,5,2,6,1,9,0,7,8 ,33,34,456,234,456,234,567,234,45,63,5645,67,54,5645,35,345,34};

	int sz = sizeof(arr1) / sizeof(arr1[0]);
	//InsertSort(arr, sz);
	//HeapSort(arr1, sz);
	//ShellSort(arr, sz);
	//QuickSort(arr1, 0, sz-1 );
	BBsort(arr1, sz);
	int i = 0;
	for (i=0; i < sz; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}