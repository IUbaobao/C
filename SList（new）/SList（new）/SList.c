#define _CRT_SECURE_NO_WARNINGS

#include"SList.h"

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

SList* BuySListNode(SLDataType x)
{
	SList* newNode = (SList*)malloc(sizeof(SList));
	if (newNode == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void SListPushFront(SList** pphead, SLDataType x)
{
	assert(pphead);
	SList* newNode = BuySListNode(x);
	newNode->next = *pphead;
	(*pphead) = newNode;
}

void SListPushBack(SList** pphead, SLDataType x)
{
	assert(pphead);
	SList* newNode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		SList* cur = *pphead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

void SListPopFront(SList** pphead)
{
	assert(pphead && *pphead);
	SList* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

void SListPopBack(SList** pphead)
{
	assert(pphead && * pphead);
	SList* cur = *pphead;
	if (cur->next==NULL)
	{
		free(cur);
		*pphead = NULL;
	}
	else
	{
		while (cur->next->next)
		{
			cur = cur->next;
		}
		SList* del = cur->next;
		cur->next = NULL;
		free(del);
		del = NULL;
	}
}


SList* SListFind(SList* phead, SLDataType x)
{
	SList* cur = phead;
	while (cur)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}


void SListInsertAfter(SList* pos, SLDataType x)
{
	assert(pos);
	SList* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}

void SListEraseAfter(SList* pos)
{
	assert(pos&& pos->next);
	SList* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}


void SListDestroy(SList* phead)
{
	SList* cur = phead;
	while (cur)
	{
		SList* del = cur;
		cur = cur->next;
		free(del);
	}
}