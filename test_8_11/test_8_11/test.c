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




//#include<stdio.h>
void Swap(int* e1, int* e2)
{
	int tem = *e1;
	*e1 = *e2;
	*e2 = tem;
}
void AdjustDown(int* a, int n, int parent)
{
	int midchild = parent * 2 + 1;
	while (midchild < n)
	{
		//建小堆找小的那个孩子，建大堆找的大的孩子
		if (midchild + 1 < n && a[midchild] < a[midchild + 1])
		{
			midchild++;
		}
		if (a[parent] < a[midchild])
		{
			Swap(&a[parent], &a[midchild]);
			parent = midchild;
			midchild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//
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
//	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
//	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


#include<stdio.h>



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

void AdjustUp(int* a, int child)
{
	int parent = (child - 1) / 2;
	//while (parent >= 0)
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

int main()
{
	int arr[] = { 1,5,3,8,7,6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = n-1; i >=0;  --i)
	{
		AdjustUp(arr, i);
	}
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}