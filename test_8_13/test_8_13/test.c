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
	//int a[] = { 3,2,5,6,7,1,0,9,10,8,4 };
	int a[] = { 6,1,3,4,6,6,6,6 };
	QuickSort(a, 0,sizeof(a) / sizeof(a[0])-1);
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

int main()
{
	TestQuickSort();
	return 0;
}