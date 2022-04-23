#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

//打印链表
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


////销毁链表
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


//尾插
void SListPushBack(SList** pphead,SLDateType x)
{
	SList* newnode = (SList*)malloc(sizeof(SList));
	newnode->data = x;
	newnode->next = NULL;

	SList* tail = *pphead;
	//如果链表为空，则直接把新的节点给pphead
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


//尾删
void SListPopBack(SList** pphead)
{
	SList* tail = *pphead;
	//prev用来记录tail的前一个节点
	SList* prev = NULL;
	//只有一个节点的时候
	if (tail->next==NULL)
	{
		free(tail);
		*pphead = prev;
	}
	//两个及两个以上的节点
	else
	{
		//找尾节点
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		//释放尾节点
		free(tail);
		//尾节点前一个节点的next置空
		prev->next = NULL;
	}
}


//头插
void SListPushFront(SList** pphead, SLDateType x)
{
	//cur记录头节点位置
	SList* cur = *pphead;
	SList* newnode = (SList*)malloc(sizeof(SList));
	newnode->data = x;
	//新节点的next指向头节点
	newnode->next = cur;
	//newnode作为新的头节点
	*pphead = newnode;
}


//头删
void SListPopFront(SList** pphead)
{
	//链表为空就报错
	assert((*pphead) != NULL);
	SList* cur = *pphead;
	SList* latter = cur->next;	//用latter存储头结点的后一个节点
	free(cur);
	*pphead = latter;	//设置新头节点
}


//查找
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

//在pos位置后面插入
void SListInsertAfter(SList* pos, SLDateType x)
{
	assert(pos != NULL);
	//创建新节点
	SList* newnode = (SList*)malloc(sizeof(SList));
	newnode->data = x;
	newnode->next = NULL;
	//在pos后插入
		SList* tem = pos->next;
		pos->next = newnode;
		newnode->next = tem;

}


//删除pos位置后一个
void SListEraseAfter(SList* pos)
{
	//判断要删的节点是否为空，为空就报错
	assert(pos->next != NULL);
	//因为要删pos下一个结点，使所以要把pos下一个节点的下一个节点存储起来防止链表断开
	SList* latterTwo = pos->next->next;
	free(pos->next);
	pos->next = latterTwo;

}