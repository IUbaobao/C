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
}SList;


//打印链表
void SListPrint(SList* phead);

//销毁链表
void SListDestroy(SList** pphead);

//尾插
void SListPushBack(SList** pphead,SLDateType x);

//尾删
void SListPopBack(SList** pphead);

//头插
void SListPushFront(SList** pphead, SLDateType x);

//头删
void SListPopFront(SList** pphead);

//查找，找到了返回x地址，找不到返回NULL
SList* SListFind(SList* plist, SLDateType x);

//在pos位置后面插入
void SListInsertAfter(SList* pos, SLDateType x);

//删除pos位置后一个
void SListEraseAfter(SList* pos);
