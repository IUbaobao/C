#define _CRT_SECURE_NO_WARNINGS




#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"Stack.h"
// 排序实现的接口
// 插入排序
void InsertSort(int* a, int n)
{

	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tem = a[end + 1];//保存后一个值
		while (end >= 0)
		{
			if (tem < a[end])//后一个值小，前面的值往后移
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tem;//把小的值插到属于它的位置
	}

}
// 希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap;i++)
		{
			int end = i;
			int tem = a[end + gap];//保存第后gap的值
			while (end >= 0)
			{
				if (tem < a[end])//后gap的值小，前面的值往后移
				{
					a[end + gap] = a[end];
					end-= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tem;//把小的值插到属于它的位置
		}

	}
}

void Swap(int* e1, int* e2)
{
	int tem = *e1;
	*e1 = *e2;
	*e2 = tem;
}
// 选择排序
void SelectSort(int* a, int n)
{
	int begin = 0, end = n-1 ;
	while (begin < end)
	{
		int maxi = begin, mini = begin;
		//选数，同时选出最大的和最小的
		for (int i = begin; i <= end; i++)
		{
			if (a[maxi] < a[i])//选出大的那个下标
				maxi = i;
			if (a[mini] > a[i])//选出小的那个下标
				mini = i;
		}
		Swap(&a[mini], &a[begin]);
		//如果刚好最大值在begin位置，则要更新maxi
		if (maxi == begin)
			maxi = mini;
		Swap(&a[maxi], &a[end]);

		begin++;
		end--;
	}
}
//向下调整算法
void AdjustDwon(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])//升序建大堆
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
// 堆排序
void HeapSort(int* a, int n)
{
	//建堆
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	//排序
	for (int i = 0; i < n; i++)
	{
		Swap(&a[0], &a[n-i-1]);//把大的放到后面
		AdjustDwon(a, n - i-1, 0);//重新调整堆
	}
}
// 冒泡排序
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
				flag = 1;//标志本趟有交换元素
			}
		}
		//在一趟比较中，如果没有发生交换元素，说明已经有序，不需要再排序
		if (flag == 0)
			break;
	}
}

//三数取中
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[right] > a[left])
			return left;
		else
			return right;
	}
	else//a[left] <= a[mid]
	{
		if (a[left] > a[right])
			return left;
		else if (a[right] > a[mid])
			return mid;
		else
			return right;
	}
}


// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[left]);
	int keyi = left;
	while (left < right)
	{
		//找小
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		//找大
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		if (left < right)
		{
			//交换
			Swap(&a[left], &a[right]);
		}
		
	}

	Swap(&a[left], &a[keyi]);
	return left;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[left]);
	int key = a[left];//保存基准值
	int hole = left;//坑位
	while (left < right)
	{
		//找小
		while (left < right && a[right] >= key)
		{
			right--;
		}
		//放坑位
		if (left < right)
		{
			a[hole] = a[right];
			hole = right;//更新坑位
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
// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[left]);
	int keyi = left;
	int prev = left;
	int cur = left+1;
	while (cur <= right)
	{
		//cur从左往右找小跟prev换
		if (a[cur] < a[keyi]  && ++prev!=cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int pivot=PartSort2(a, left, right);
	//分成了两个区域 [left,pivot] pivot [pivot+1,right];

	if (right - left < 8)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		QuickSort(a, left, pivot - 1);
		QuickSort(a, pivot + 1, right);
	}

}



// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);

	StackPush(&st, right);
	StackPush(&st, left);
	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		//小区间优化
		if (end - begin < 8)
		{
			InsertSort(a + begin, end - begin + 1);
			continue;
		}
		int pivot = PartSort2(a, begin, end);
		//分出的区间：[begin, pivot-1] pivot [pivot+1,end]

		//当区间有数才入栈
		if (end - pivot > 1)
		{
			StackPush(&st, end);
			StackPush(&st, pivot + 1);
		}

		if (pivot - begin > 1)
		{
			StackPush(&st, pivot - 1);
			StackPush(&st, begin);
		}
	}
}

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	//取中间数
	int mid = begin + (end - begin) / 2;
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//合并
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
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

// 归并排序递归实现
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail\n");
		return;
	}

	_MergeSort(a, 0, n - 1, tmp);
	
	free(tmp);
	tmp = NULL;
}
// 归并排序非递归实现
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
		for (int j = 0; j < n; j += 2 * gap)
		{
			//合并
			int begin1 = j, end1 = j+gap-1;
			int begin2 = j+gap, end2 = j+2*gap-1;
			int i = j;

			//end1越界
			if (end1 >= n)
			{
				break;
			}
			//begin2 这组全部越界
			if (begin2 >= n)
			{
				break;
			}
			//end2越界
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
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
			memcpy(a + j, tmp + j, (end2 - j + 1) * sizeof(int));
		}
		gap *= 2;
	}
}
// 计数排序
void CountSort(int* a, int n)
{
	int max, min;
	max = min = a[0];
	//找出最大最小值
	for (int i = 0; i < n; ++i)
	{
		if (max < a[i])
			max = a[i];
		if (min > a[i])
			min = a[i];
	}
	//开辟对应大小的空间
	int* count = (int*)malloc(sizeof(int) * (max - min + 1));
	if (count == NULL)
	{
		perror("malloc fail\n");
		return;
	}
	//将辅助数组中的值初始化成0
	memset(count, 0, sizeof(int) * (max - min + 1));

	//统计每个数出现的次数
	for (int i = 0; i < n; ++i)
	{
		count[a[i] - min]++;
	}

	//开始拷贝回原数组
	int i = 0, j = 0;
	while (j < n)
	{
		if (count[i] == 0)
		{
			i++;
			continue;
		}
		a[j++] = i + min;
		count[i]--;
	}
}

// 测试排序的性能对比
void TestOP()
{
	srand(time(0));
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	int* a8 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];


}

	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	SelectSort(a2, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();

	int begin7 = clock();
	QuickSortNonR(a7, 0, N - 1);
	int end7 = clock();

	int begin8 = clock();
	MergeSortNonR(a8, N);
	int end8 = clock();

	printf("时间复杂度为O(N^2)的排序：\n");
	printf("InsertSort:%d\n", end1 - begin1);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("效率相对较快的排序：\n");
	printf("ShellSort:%d\n", end2 - begin2);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	printf("QuickSortNonR:%d\n", end7 - begin7);
	printf("MergeSortNonR:%d\n", end8 - begin8);


	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);

}

void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}




void TestshellSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int n = sizeof(a) / sizeof(a[0]);
	ShellSort(a, n);
	Print(a, n);
}



void TestInsert()
{
	int a[] = { 6,4,1,2,9,3,7,8,10,5 };
	int n = sizeof(a) / sizeof(a[0]);
	InsertSort(a, n);
	Print(a, n);
}


void TestSelectSort()
{
	int a[] = { 6,4,1,2,9,3,7,8,10,5 };
	int n = sizeof(a) / sizeof(a[0]);
	SelectSort(a, n);
	Print(a, n);
}


void TestHeapSort()
{
	int a[] = { 30,60,12,40,8,10,70 };
	int n = sizeof(a) / sizeof(a[0]);
	HeapSort(a, n);
	Print(a, n);
}

void TestBubbleSort()
{
	int a[] = { 6,4,1,2,9,3,7,8,10,5 };
	int n = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, n);
	Print(a, n);
}

void TestQuickSort()
{
	int a[] = { 6,4,1,2,9,3,7,8,10,5 };
	int n = sizeof(a) / sizeof(a[0]);
	QuickSort(a, 0,n-1);
	Print(a, n);
}

void TestQuickSortNonR()
{
	int a[] = { 6,4,1,2,9,3,7,8,10,5 };
	//int a[] = { 30,60,12,40,8,10,70 };

	int n = sizeof(a) / sizeof(a[0]);
	QuickSortNonR(a, 0, n - 1);
	Print(a, n);
}

void TestMergeSort()
{
	//int a[] = { 6,4,1,2,9,3,7,8,10,5 };
	int a[] = { 30,60,12,40,8,10,70 };

	int n = sizeof(a) / sizeof(a[0]);
	MergeSort(a, n);
	Print(a, n);
}


void TestMergeSortNonR()
{
	int a[] = { 6,4,1,2,9,3,7,8,10,5 };
	//int a[] = { 3,2,6,4,1,8,3,9 };
	//int a[] = { 30,60,12,40,8,10,70 };

	int n = sizeof(a) / sizeof(a[0]);
	MergeSortNonR(a, n);
	Print(a, n);
}


void TestCountSort()
{
	//int a[] = { 6,4,1,2,9,3,7,8,10,5 };
	int a[] = { 1,4,1,2,5,2,4,1,8 };
	//int a[] = { 30,60,12,40,8,10,70 };

	int n = sizeof(a) / sizeof(a[0]);
	CountSort(a, n);
	Print(a, n);
}

int main()
{

	//TestCountSort();
	TestOP();
	return 0;
}