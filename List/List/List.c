#define _CRT_SECURE_NO_WARNINGS
#include"List.h"

//初始化
LTNode* ListInit()
{
	LTNode* phead = BuyListNode(0);

	phead->prev = phead;
	phead->next = phead;
	
	return phead;
}
//打印
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

//尾插
void ListPushBack(LTNode* phead,LTDateType x)
{
	assert(phead);
	//新节点
	//LTNode* newNode = BuyListNode(x);
	//找尾
	//LTNode* tail = phead->prev;
	//连接
	//tail->next = newNode;
	//newNode->prev = tail;
	//newNode->next = phead;
	//phead->prev = newNode;
	
	//可用插入函数代替尾插
	ListInsert(phead, x);
}
//尾删
void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	//LTNode* tail = phead->prev;
	//LTNode* tailPrev = tail->prev;
	//free(tail);
	//tailPrev->next = phead;
	//phead->prev = tailPrev;

	//可用删除函数代替尾删
	ListErase(phead->prev);
}

//头插
void ListPushFront(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* newNode = BuyListNode(x);
	//连接
	LTNode* next = phead->next;
	phead->next = newNode;
	newNode->prev = phead;

	newNode->next = next;
	next->prev = newNode;

	//可用插入函数代替头插
	//ListInsert(phead->next, x);

}

//头删
void ListPopFront(LTNode* phead)
{
	assert(phead);
	//链表为空
	assert(phead->next != phead);

	LTNode* next = phead->next;
	LTNode* nextNext = next->next;
	free(next);
	phead->next = nextNext;
	nextNext->prev = phead;

	//可用删除函数代替头删
	//ListErase(phead->next);

}

//查找
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

//插入
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
//删除
void ListErase(LTNode* pos)
{
	assert(pos);

	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
}
//创建新节点
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

//销毁链表
void ListDestroy(LTNode* phead)
{
	LTNode* cur = phead->next;

	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}
