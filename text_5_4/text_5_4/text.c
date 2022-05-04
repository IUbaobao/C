#define _CRT_SECURE_NO_WARNINGS


//1、熟练掌握链表的基本操作；
//2、完成链表节点的定义和初始化、查找、销毁等基本操作；
//3、将两个非递减的有序链表合并为一个非递增的有序链表，仍然用原来的存储空间；

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDateType;
typedef struct SList
{
	SLDateType data;
	struct SList* next;
}SLNode;

//打印链表
void SListPrint(SLNode* phead);
//销毁链表
void SListDestroy(SLNode** pphead);
//尾插
void SListPushBack(SLNode** pphead, SLDateType x);
//查找，找到了返回x地址，找不到返回NULL
SLNode* SListFind(SLNode* plist, SLDateType x);
//合并两个有序链表
SLNode* Merge(SLNode* pHead1, SLNode* pHead2);


int main()
{
	//初始化
	SLNode* list1 = NULL;
	SLNode* list2 = NULL;
	printf("排序前>:\n");
	SListPushBack(&list1, 3);
	SListPushBack(&list1, 6);
	SListPushBack(&list1, 8);
	SListPushBack(&list1, 9);
	SListPrint(list1);

	SListPushBack(&list2, 2);
	SListPushBack(&list2, 5);
	SListPushBack(&list2, 8);
	SListPushBack(&list2, 10);
	SListPushBack(&list2, 12);
	SListPushBack(&list2, 16);
	SListPrint(list2);

	SLNode* head = Merge(list1, list2);
	printf("\n排序合并后>:\n");
	SListPrint(head);


	return 0;
}

//
SLNode* Merge(SLNode* pHead1, SLNode* pHead2)
{
	if (pHead1 == NULL)
	{
		return pHead2;
	}
	if (pHead2 == NULL)
	{
		return pHead1;
	}
	SLNode* head = (SLNode*)malloc(sizeof(SLNode));
	SLNode* cur = head;
	while (pHead1 && pHead2)
	{
		if (pHead1->data > pHead2->data)
		{
			cur->next = pHead2;
			pHead2 = pHead2->next;
		}
		else
		{
			cur->next = pHead1;
			pHead1 = pHead1->next;
		}
		cur = cur->next;
	}
	if (pHead1 != NULL)
	{
		cur->next = pHead1;
	}
	else
	{
		cur->next = pHead2;
	}
	cur = head->next;
	free(head);
	return cur;
}





//打印链表
void SListPrint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//销毁链表
void SListDestroy(SLNode** pphead)
{
	SLNode* cur = *pphead;
	while (cur)
	{
		cur = cur->next;
		free(*pphead);
		*pphead = cur;
	}
}
//尾插
void SListPushBack(SLNode** pphead, SLDateType x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	newnode->data = x;
	newnode->next = NULL;

	SLNode* tail = *pphead;
	//如果链表为空，则直接把新的节点给pphead
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}

}
//查找,找到返回x地址，找不到返回NULL
SLNode* SListFind(SLNode* plist, SLDateType x)
{
	SLNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


