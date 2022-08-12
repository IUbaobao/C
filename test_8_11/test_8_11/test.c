#define _CRT_SECURE_NO_WARNINGS





//typedef int BTDataType;
//// 二叉链
//struct BinaryTreeNode
//{
//	struct BinTreeNode* pLeft; // 指向当前节点左孩子
//	struct BinTreeNode* pRight; // 指向当前节点右孩子
//	BTDataType data; // 当前节点值域
//}
//// 三叉链
//struct BinaryTreeNode
//{
//	struct BinTreeNode* pParent; // 指向当前节点的双亲
//	struct BinTreeNode* pLeft; // 指向当前节点左孩子
//	struct BinTreeNode* pRight; // 指向当前节点右孩子
//	BTDataType data; // 当前节点值域
//}；


//
//
//#include<stdio.h>
//void Swap(int* e1, int* e2)
//{
//	int tem = *e1;
//	*e1 = *e2;
//	*e2 = tem;
//}
//void AdjustDown(int* a, int n, int parent)
//{
//	int midchild = parent * 2 + 1;
//	while (midchild < n)
//	{
//		//建小堆找小的那个孩子，建大堆找的大的孩子
//		if (midchild + 1 < n && a[midchild] < a[midchild + 1])
//		{
//			midchild++;
//		}
//		if (a[parent] < a[midchild])
//		{
//			Swap(&a[parent], &a[midchild]);
//			parent = midchild;
//			midchild = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
////堆排序
//void HeapSort(int* a, int n)
//{
//	//建堆
//	int i = 0;
//	for (i = (n-2)/2; i >= 0; --i)
//	{
//		AdjustDown(a, n, i);
//	}
//	
//	for (i = 0; i < n; i++)
//	{
//		Swap(&a[0], &a[n - i - 1]);
//		AdjustDown(a, n - i-1, 0);
//	}
//}
//
//
//int main()
//{
//	int arr[] = { 30,60,12,40,8,10,70 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	HeapSort(arr,n);
//	for (int i = 0; i < n; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//
//#include<stdio.h>
//
//void AdjustUp(int* a, int child)
//{
//	int parent = (child - 1) / 2;
//	while (child > 0)
//	{
//		if (a[parent] < a[child])
//		{
//			Swap(&a[parent], &a[child]);
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//
//int main()
//{
//	int arr[] = { 30,60,12,40,8,10,70 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//
//	for (int i = 0; i < n;  ++i)//建小堆
//	{
//		AdjustUp(arr, i);
//	}
//
//	//for (int i = (n - 1-1)/2; i >= 0; --i)//建小堆
//	//{
//	//	AdjustDown(arr,n, i);
//	//}
//
//	for (int i = 0; i < n; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//
//#include<stdio.h>
//
//void Swap(int* e1, int* e2)
//{
//	int tem = *e1;
//	*e1 = *e2;
//	*e2 = tem;
//}
//
////向下调整算法
//void AdjustDown(int* a, int n, int parent)
//{
//	int midchild = parent * 2 + 1;
//	while (midchild < n)
//	{
//		//建小堆找小的那个孩子，建大堆找的大的孩子
//		if (midchild + 1 < n && a[midchild] > a[midchild + 1])
//		{
//			midchild++;
//		}
//		if (a[parent] > a[midchild])
//		{
//			Swap(&a[parent], &a[midchild]);//交换
//			parent = midchild;
//			midchild = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,5,3,8,7,6 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	//从最后一个非叶子节点开始调整，最后一个非叶子节点就是最后一个节点的父亲，
//	//parent=(child-1)/2,  这里的最后一个元素为n-1，所以child=n-1，故parent=(n-1-1)/2
//	for (int i = (n - 1-1)/2; i >= 0; --i)//建大堆
//	{
//		AdjustDown(arr,n, i);
//	}
//
//	for (int i = 0; i <n; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}



#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Swap(int* e1, int* e2)
{
	int tem = *e1;
	*e1 = *e2;
	*e2 = tem;
}

//向下调整算法
void AdjustDown(int* a, int n, int parent)
{
	int midchild = parent * 2 + 1;
	while (midchild < n)
	{
		//建小堆找小的那个孩子，建大堆找的大的孩子
		if (midchild + 1 < n && a[midchild] > a[midchild + 1])
		{
			midchild++;
		}
		if (a[parent] > a[midchild])
		{
			Swap(&a[parent], &a[midchild]);//交换
			parent = midchild;
			midchild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


//咱们求最大的前10个数
void PrintTopK(int* a, int n, int k)
{
	// 1. 建堆--用a中前k个元素建小堆
	int i = 0;
	for (i = (k - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, k, i);
	}
	
// 2. 将剩余n-k个元素依次与堆顶元素交换，不满则则替换
	for (i = k; i < n; i++)
	{
		if (a[i] > a[0])//建小堆的意义在这，把大于堆顶的元素入堆
		{
			a[0] = a[i];
			AdjustDown(a, k, 0);//重新将数组首元素这个位置向下调整，使其成为小堆
		}
	}

	printf("\n前Top10分别为：");
	for (i = 0; i < k; i++)
	{
		printf("%d ", a[i]);
	}
}

void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand( (unsigned int )time(0));
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;//制造10000个小于1000000的随机数
	}
	//手动将大于1000000的数加上，不出意外，等下选出的就是这些数，因为他们是前top10
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
	free(a);
}


int main()
{
	TestTopk();

	return 0;
}