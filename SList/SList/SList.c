#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

//��ӡ����
void SListPrint(SList* phead)
{
	SList* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


////��������
void SListDestroy(SList** pphead)
{
	SList* cur = *pphead;
	while (cur)
	{
		cur = cur->next;
		free(*pphead);
		*pphead = cur;
	}
}


//β��
void SListPushBack(SList** pphead,SLDateType x)
{
	SList* newnode = (SList*)malloc(sizeof(SList));
	newnode->data = x;
	newnode->next = NULL;

	SList* tail = *pphead;
	//�������Ϊ�գ���ֱ�Ӱ��µĽڵ��pphead
	if (*pphead==NULL)
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


//βɾ
void SListPopBack(SList** pphead)
{
	SList* tail = *pphead;
	//prev������¼tail��ǰһ���ڵ�
	SList* prev = NULL;
	//ֻ��һ���ڵ��ʱ��
	if (tail->next==NULL)
	{
		free(tail);
		*pphead = prev;
	}
	//�������������ϵĽڵ�
	else
	{
		//��β�ڵ�
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		//�ͷ�β�ڵ�
		free(tail);
		//β�ڵ�ǰһ���ڵ��next�ÿ�
		prev->next = NULL;
	}
}


//ͷ��
void SListPushFront(SList** pphead, SLDateType x)
{
	//cur��¼ͷ�ڵ�λ��
	SList* cur = *pphead;
	SList* newnode = (SList*)malloc(sizeof(SList));
	newnode->data = x;
	//�½ڵ��nextָ��ͷ�ڵ�
	newnode->next = cur;
	//newnode��Ϊ�µ�ͷ�ڵ�
	*pphead = newnode;
}


//ͷɾ
void SListPopFront(SList** pphead)
{
	//����Ϊ�վͱ���
	assert((*pphead) != NULL);
	SList* cur = *pphead;
	SList* latter = cur->next;	//��latter�洢ͷ���ĺ�һ���ڵ�
	free(cur);
	*pphead = latter;	//������ͷ�ڵ�
}


//����
SList* SListFind(SList* plist, SLDateType x)
{
	SList* cur = plist;
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

//��posλ�ú������
void SListInsertAfter(SList* pos, SLDateType x)
{
	assert(pos != NULL);
	//�����½ڵ�
	SList* newnode = (SList*)malloc(sizeof(SList));
	newnode->data = x;
	newnode->next = NULL;
	//��pos�����
		SList* tem = pos->next;
		pos->next = newnode;
		newnode->next = tem;

}


//ɾ��posλ�ú�һ��
void SListEraseAfter(SList* pos)
{
	//�ж�Ҫɾ�Ľڵ��Ƿ�Ϊ�գ�Ϊ�վͱ���
	assert(pos->next != NULL);
	//��ΪҪɾpos��һ����㣬ʹ����Ҫ��pos��һ���ڵ����һ���ڵ�洢������ֹ����Ͽ�
	SList* latterTwo = pos->next->next;
	free(pos->next);
	pos->next = latterTwo;

}