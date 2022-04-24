#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>

typedef int SLDateType;
typedef struct SList
{
	SLDateType data;
	struct SList* next;
}SLNode;


//打印链表
void SListPrint(SLNode* phead);

//销毁链表
void SListDestroy(SLNode** pphead);

//尾插
void SListPushBack(SLNode** pphead,SLDateType x);

//尾删
void SListPopBack(SLNode** pphead);

//头插
void SListPushFront(SLNode** pphead, SLDateType x);

//头删
void SListPopFront(SLNode** pphead);

//查找，找到了返回x地址，找不到返回NULL
SLNode* SListFind(SLNode* plist, SLDateType x);

//在pos位置后面插入
void SListInsertAfter(SLNode* pos, SLDateType x);

//删除pos位置后一个
void SListEraseAfter(SLNode* pos);
