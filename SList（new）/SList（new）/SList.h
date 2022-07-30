#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDataType;
typedef struct SList
{
	SLDataType data;
	struct SList* next;
}SList;

//打印
void SListPrint(SList* phead);
//申请一个节点
SList* BuySListNode(SLDataType x);

//增删查改
void SListPushFront(SList** pphead, SLDataType x);
void SListPushBack(SList** pphead, SLDataType x);
void SListPopFront(SList** pphead);
void SListPopBack(SList** pphead);
SList* SListFind(SList* phead, SLDataType x);

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？  —— 前插入麻烦，时间复杂度O(N)
void SListInsertAfter(SList* pos, SLDataType x);


// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？  —— 前插入麻烦，时间复杂度O(N)
void SListEraseAfter(SList* pos);

void SListDestroy(SList* phead);
