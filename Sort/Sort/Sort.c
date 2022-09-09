#define _CRT_SECURE_NO_WARNINGS


#include"Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


void InsertSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void Swap(int* e1, int* e2)
{
	int tem = *e1;
	*e1 = *e2;
	*e2 = tem;
}

void SelectSort(int* a, int n)
{
	int end = n - 1, begin = 0;
	while (begin < end)
	{
		int maxi = begin, mini =begin;
		for (int i = begin; i < end; i++)
		{
			if (a[maxi] < a[i])
				maxi = i;
			if (a[mini] > a[i])
				mini = i;
		}
		Swap(&a[begin], &a[mini]);
		//maxi在开始位置的时候，要更新maxi
		if (begin == maxi)
			maxi = mini;
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
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
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
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
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	for (int i = 0; i < n; i++)
	{
		Swap(&a[0], &a[n - 1 - i]);
		AdjustDown(a, n - i - 1, 0);
	}
}


void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 1;
			}
		}

		if (flag == 0)
			break;
	}
}


int  GetMidIndex(int *a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else//left >= mid
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);
	int keyi = left;
	while (left < right)
	{
		//找小
		while (left<right && a[right] >= a[keyi])
		{
			right--;
		}
		//找大
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		if (left < right)
			Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);
	return left;

}


//挖坑法
int PartSort2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

	int key = a[left];
	int hole = left;
	while (left < right)
	{
		//找小
		while (left< right && a[right] >= key)
		{
			right--;
		}
		if (left < right)
		{
			a[hole] = a[right];
			hole = right;
		}
		//找大
		while (left < right && a[left] <= key)
		{
			left++;
		}
		if (left < right)
		{
			a[hole] = a[left];
			hole = left;
		}
	}
	a[hole] = key;
	return hole;
}

//前后指针法
int PartSort3(int* a, int left, int right)
{

	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);
	int keyi = left;
	int prev = left;
	int cur = left + 1;
	
	while (cur <= right)
	{
		//找小
		if (a[cur] < a[keyi]  && ++prev!=cur )
			Swap(&a[cur], &a[prev]);
		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}


void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int point = PartSort2(a, left, right);

	if (right - left <= 8)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		QuickSort(a, left, point - 1);
		QuickSort(a, point + 1, right);
	}

}


void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, left);
	StackPush(&st, right);
	while (!StackEmpty(&st))
	{
		int end = StackTop(&st);
		StackPop(&st);
		int begin = StackTop(&st);
		StackPop(&st);

		//if (end - begin <= 1)
		//	continue;

		int mid = PartSort2(a, begin, end);

		//[begin mid-1]  mid [mid+1,end]
		if (mid + 1 < end)
		{
			StackPush(&st, mid + 1);
			StackPush(&st, end);
		}

		if ( begin < mid - 1)
		{
			StackPush(&st, begin);
			StackPush(&st, mid - 1);
		}

	}
}

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	int mid = begin + (end - begin) / 2;
	// [begin, mid] [mid+1, end]
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	// 归并
	int begin1 = begin,  end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1<=end1 && begin2<=end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];

		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];

	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	
	//拷贝回去
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fial\n");
		return;
	}
	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}


void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail\n");
		return;
	}
	int gap = 1;
	while (gap < n)
	{
		for (int j = 0; j < n; j += 2*gap)
		{
			// 归并
			int begin1 = j, end1 = j + gap - 1;
			int begin2 = j + gap, end2 = j + 2 * gap - 1;
			int i = j;

			//end1越界
			if (end1 >= n)
			{
				break;
			}
			//begin2整个组越界
			if (begin2 >= n)
			{
				break;
			}
			// end2越界
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					tmp[i++] = a[begin1++];
				}
				else
				{
					tmp[i++] = a[begin2++];

				}
			}

			while (begin1 <= end1)
			{
				tmp[i++] = a[begin1++];

			}

			while (begin2 <= end2)
			{
				tmp[i++] = a[begin2++];
			}
			memcpy(a + j, tmp + j, (end2 - j + 1) * sizeof(int));
		}
		gap *= 2;
	}
	free(tmp);
	tmp = NULL;
}



void CountSort(int* a, int n)
{
	int max, min;
	max = min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//开辟对应空间
	int* tmp = (int*)malloc(sizeof(int) * (max - min+1));
	if (tmp == NULL)
	{
		perror("malloc fail\n");
		return;
	}
	memset(tmp, 0, sizeof(int) * (max - min + 1));
	//映射计数
	for (int i = 0; i < n; i++)
	{
		tmp[a[i] - min]++;
	}
	int i = 0,j=0;
	//拷贝回原数组
	while ( j<n)
	{
		if (tmp[i] == 0)
		{
			i++;
			continue;
		}
		a[j++] = i + min;
		tmp[i]--;
	}
}