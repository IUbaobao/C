#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int LTDateType;

typedef struct ListNode
{
	LTDateType date;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

//初始化
LTNode* ListInit();

//打印
void ListPrint(LTNode* phead);

//创建新节点
LTNode* BuyListNode(LTDateType x);

//尾插
void ListPushBack(LTNode* phead, LTDateType x);

//尾删
void ListPopBack(LTNode* phead);

//头插
void ListPushFront(LTNode* phead, LTDateType x);

//头删
void ListPopFront(LTNode* phead);

//查找,找到返回对应数据地址，找不到返回NULL
LTNode* ListFind(LTNode* phead, LTDateType x);

//插入，在pos位置之前插入
void ListInsert(LTNode* pos, LTDateType x);

//删除指定位置
void ListErase(LTNode* pos);

//销毁链表
void ListDestroy(LTNode* phead);
