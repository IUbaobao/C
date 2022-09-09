#define _CRT_SECURE_NO_WARNINGS


#include"Sort.h"

void TestInsertSort()
{
	int a[] = { 3,2,5,6,7,1,0,9,10,8,4 };
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
void TestShellSort()
{
	int a[] = { 3,2,5,6,7,1,0,9,10,8,4 };
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
void TestSelectSort()
{
	//int a[] = { 3,2,5,6,7,1,0,9,10,8,4 };
	int a[] = { 9,1,2,3,4,5 };
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestHeapSort()
{
	int a[] = { 3,2,5,6,7,1,0,9,10,8,4 };
	//int a[] = { 9,1,2,3,4,5 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestBubbleSort()
{
	int a[] = { 3,2,5,6,7,1,0,9,10,8,4 };
	//int a[] = { 9,1,2,3,4,5 };
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}


void TestQuickSort()
{
	int a[] = { 3,2,5,6,7,1,0,9,10,8,4 };
	//int a[] = { 6,1,3,4,6,6,6,6 };
	QuickSort(a, 0,sizeof(a) / sizeof(a[0])-1);
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestQuickSortNonR()
{
	int a[] = { 3,2,5,6,7,1,0,9,10,8,4 };
	//int a[] = { 6,1,3,4,6,6,6,6 };
	QuickSortNonR(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestMergeSort()
{
	//int a[] = { 10,6,7,1,3,9,4,2 };
	//int a[] = { 6,1,3,4,6,6,6,6 };
	int a[] = { 3,2,5,6,7,1,0,9,10,8,4 };

	MergeSort(a,sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
void TestMergeSortNonR()
{
	//int a[] = { 10,6,7,1,3,9,4,2 };
	//int a[] = { 6,1,3,4,6,6,6,6 };
	int a[] = { 3,2,5,6,7,1,0,9,10,8,4 };

	MergeSortNonR(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestCountSort()
{
	//int a[] = { 10,6,7,1,3,9,4,2 };
	//int a[] = { 6,1,3,4,6,6,6,6 };
	int a[] = { 3,2,5,6,7,1,0,9,10,8,4 };

	CountSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}



// 测试排序的性能对比
void TestOP()
{
	srand(time(0));
	const int N = 10000000;
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
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	//ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	//HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	//QuickSort(a4, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();

	int begin7 = clock();
	//QuickSortNonR(a7, 0, N - 1);
	int end7 = clock();

	int begin8 = clock();
	MergeSortNonR(a8,N);
	int end8 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
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
}


int main()
{
	TestCountSort();
	//TestOP();
	return 0;
}