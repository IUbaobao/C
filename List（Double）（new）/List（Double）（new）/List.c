#define _CRT_SECURE_NO_WARNINGS


#include"List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = x;
	newNode->next = newNode->prev = newNode;
	return newNode;
}

ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;
	return head;
}


ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newNode = BuyListNode(x);
	ListNode* prev = pos->prev;

	//Á¬½Ó
	prev->next = newNode;
	newNode->prev = prev;

	newNode->next = pos;
	pos->prev = newNode;
}


void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListInsert(phead->next,x);
}

void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListInsert(phead, x);
}


void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	printf("head<=>");
	while (cur != phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* prev = pos->prev;
	ListNode* next = pos->next;

	prev->next = next;
	next->prev = prev;
	free(pos);
	//pos=NULL;
}


void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListErase(phead->next);
}
void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListErase(phead->prev);
}



void ListDestroy(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* del = cur;
		cur = cur->next;
		free(del);
	}
	free(phead);
	//phead=NULL;
}