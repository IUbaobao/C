#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

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


////��������
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
void SListPushBack(SLNode** pphead,SLDateType x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	newnode->data = x;
	newnode->next = NULL;

	SLNode* tail = *pphead;
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
void SListPopBack(SLNode** pphead)
{
	SLNode* tail = *pphead;
	//prev������¼tail��ǰһ���ڵ�
	SLNode* prev = NULL;
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
void SListPushFront(SLNode** pphead, SLDateType x)
{
	//cur��¼ͷ�ڵ�λ��
	SLNode* cur = *pphead;
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	newnode->data = x;
	//�½ڵ��nextָ��ͷ�ڵ�
	newnode->next = cur;
	//newnode��Ϊ�µ�ͷ�ڵ�
	*pphead = newnode;
}


//ͷɾ
void SListPopFront(SLNode** pphead)
{
	//����Ϊ�վͱ���
	assert((*pphead) != NULL);
	SLNode* cur = *pphead;
	SLNode* latter = cur->next;	//��latter�洢ͷ���ĺ�һ���ڵ�
	free(cur);
	*pphead = latter;	//������ͷ�ڵ�
}


//����
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

//��posλ�ú������
void SListInsertAfter(SLNode* pos, SLDateType x)
{
	assert(pos != NULL);
	//�����½ڵ�
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	newnode->data = x;
	newnode->next = NULL;
	//��pos�����
	SLNode* tem = pos->next;
		pos->next = newnode;
		newnode->next = tem;

}


//ɾ��posλ�ú�һ��
void SListEraseAfter(SLNode* pos)
{
	//�ж�Ҫɾ�Ľڵ��Ƿ�Ϊ�գ�Ϊ�վͱ���
	assert(pos->next != NULL);
	//��ΪҪɾpos��һ����㣬ʹ����Ҫ��pos��һ���ڵ����һ���ڵ�洢������ֹ����Ͽ�
	SLNode* latterTwo = pos->next->next;
	free(pos->next);
	pos->next = latterTwo;

}