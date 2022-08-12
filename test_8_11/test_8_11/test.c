#define _CRT_SECURE_NO_WARNINGS





//typedef int BTDataType;
//// ������
//struct BinaryTreeNode
//{
//	struct BinTreeNode* pLeft; // ָ��ǰ�ڵ�����
//	struct BinTreeNode* pRight; // ָ��ǰ�ڵ��Һ���
//	BTDataType data; // ��ǰ�ڵ�ֵ��
//}
//// ������
//struct BinaryTreeNode
//{
//	struct BinTreeNode* pParent; // ָ��ǰ�ڵ��˫��
//	struct BinTreeNode* pLeft; // ָ��ǰ�ڵ�����
//	struct BinTreeNode* pRight; // ָ��ǰ�ڵ��Һ���
//	BTDataType data; // ��ǰ�ڵ�ֵ��
//}��


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
//		//��С����С���Ǹ����ӣ�������ҵĴ�ĺ���
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
////������
//void HeapSort(int* a, int n)
//{
//	//����
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
//	for (int i = 0; i < n;  ++i)//��С��
//	{
//		AdjustUp(arr, i);
//	}
//
//	//for (int i = (n - 1-1)/2; i >= 0; --i)//��С��
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
////���µ����㷨
//void AdjustDown(int* a, int n, int parent)
//{
//	int midchild = parent * 2 + 1;
//	while (midchild < n)
//	{
//		//��С����С���Ǹ����ӣ�������ҵĴ�ĺ���
//		if (midchild + 1 < n && a[midchild] > a[midchild + 1])
//		{
//			midchild++;
//		}
//		if (a[parent] > a[midchild])
//		{
//			Swap(&a[parent], &a[midchild]);//����
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
//	//�����һ����Ҷ�ӽڵ㿪ʼ���������һ����Ҷ�ӽڵ�������һ���ڵ�ĸ��ף�
//	//parent=(child-1)/2,  ��������һ��Ԫ��Ϊn-1������child=n-1����parent=(n-1-1)/2
//	for (int i = (n - 1-1)/2; i >= 0; --i)//�����
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

//���µ����㷨
void AdjustDown(int* a, int n, int parent)
{
	int midchild = parent * 2 + 1;
	while (midchild < n)
	{
		//��С����С���Ǹ����ӣ�������ҵĴ�ĺ���
		if (midchild + 1 < n && a[midchild] > a[midchild + 1])
		{
			midchild++;
		}
		if (a[parent] > a[midchild])
		{
			Swap(&a[parent], &a[midchild]);//����
			parent = midchild;
			midchild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


//����������ǰ10����
void PrintTopK(int* a, int n, int k)
{
	// 1. ����--��a��ǰk��Ԫ�ؽ�С��
	int i = 0;
	for (i = (k - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, k, i);
	}
	
// 2. ��ʣ��n-k��Ԫ��������Ѷ�Ԫ�ؽ��������������滻
	for (i = k; i < n; i++)
	{
		if (a[i] > a[0])//��С�ѵ��������⣬�Ѵ��ڶѶ���Ԫ�����
		{
			a[0] = a[i];
			AdjustDown(a, k, 0);//���½�������Ԫ�����λ�����µ�����ʹ���ΪС��
		}
	}

	printf("\nǰTop10�ֱ�Ϊ��");
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
		a[i] = rand() % 1000000;//����10000��С��1000000�������
	}
	//�ֶ�������1000000�������ϣ��������⣬����ѡ���ľ�����Щ������Ϊ������ǰtop10
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