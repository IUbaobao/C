#define _CRT_SECURE_NO_WARNINGS


//1��������������Ļ���������
//2���������ڵ�Ķ���ͳ�ʼ�������ҡ����ٵȻ���������
//3���������ǵݼ�����������ϲ�Ϊһ���ǵ���������������Ȼ��ԭ���Ĵ洢�ռ䣻

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDateType;
typedef struct SList
{
	SLDateType data;
	struct SList* next;
}SLNode;

//��ӡ����
void SListPrint(SLNode* phead);
//��������
void SListDestroy(SLNode** pphead);
//β��
void SListPushBack(SLNode** pphead, SLDateType x);
//���ң��ҵ��˷���x��ַ���Ҳ�������NULL
SLNode* SListFind(SLNode* plist, SLDateType x);
//�ϲ�������������
SLNode* Merge(SLNode* pHead1, SLNode* pHead2);


int main()
{
	//��ʼ��
	SLNode* list1 = NULL;
	SLNode* list2 = NULL;
	printf("����ǰ>:\n");
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
	printf("\n����ϲ���>:\n");
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





//��ӡ����
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

//��������
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
//β��
void SListPushBack(SLNode** pphead, SLDateType x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	newnode->data = x;
	newnode->next = NULL;

	SLNode* tail = *pphead;
	//�������Ϊ�գ���ֱ�Ӱ��µĽڵ��pphead
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
//����,�ҵ�����x��ַ���Ҳ�������NULL
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


