#define _CRT_SECURE_NO_WARNINGS
#include"List.h"


LTNode* ListInit()
{
	LTNode* phead = BuyListNode(0);

	phead->prev = phead;
	phead->next = phead;
	
	return phead;
}

void ListPrint(LTNode* phead)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->date);
		cur = cur->next;
	}
	printf("\n");
}


void ListPushBack(LTNode* phead,LTDateType x)
{
	assert(phead);
	//�½ڵ�
	//LTNode* newNode = BuyListNode(x);
	////��β
	//LTNode* tail = phead->prev;
	////����
	//tail->next = newNode;
	//newNode->prev = tail;
	//newNode->next = phead;
	//phead->prev = newNode;
	
	//���ò��뺯������β��
	ListInsert(phead, x);
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	//LTNode* tail = phead->prev;
	//LTNode* tailPrev = tail->prev;
	//free(tail);
	//tailPrev->next = phead;
	//phead->prev = tailPrev;

	//����ɾ����������βɾ
	ListErase(phead->prev);
}

void ListPushFront(LTNode* phead, LTDateType x)
{
	assert(phead);
	////LTNode* newNode = BuyListNode(x);
	////����
	////LTNode* next = phead->next;
	////phead->next = newNode;
	////newNode->prev = phead;

	////newNode->next = next;
	////next->prev = newNode;

	//���ò��뺯������ͷ��
	ListInsert(phead->next, x);

}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	//����Ϊ��
	assert(phead->next != phead);

	//LTNode* next = phead->next;
	//LTNode* nextNext = next->next;
	//free(next);
	//phead->next = nextNext;
	//nextNext->prev = phead;

	//����ɾ����������ͷɾ
	ListErase(phead->next);

}


LTNode* ListFind(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->date == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}


void ListInsert(LTNode* pos, LTDateType x)
{
	assert(pos);

	LTNode* newNode = BuyListNode(x);


	LTNode* posPrev = pos->prev;

	posPrev->next = newNode;
	newNode->prev = posPrev;
	newNode->next = pos;
	pos->prev = newNode;
}

void ListErase(LTNode* pos)
{
	assert(pos);

	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
}

LTNode* BuyListNode(LTDateType x)
{
	LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
	if (newNode == NULL)
	{
		exit(-1);
	}
	newNode->date = x;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}
