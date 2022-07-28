#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


#define N 100

typedef int SLDataType;

//静态顺序表
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};



//动态顺序表
typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;



//初始化
void SeqListInit(SL* ps);

//销毁
void SeqListDestroy(SL* ps);


//增删查改
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);
int SeqListFind(SL* ps, SLDataType x);
void SeqListInsert(SL* ps, size_t pos, SLDataType x);
void SeqListErase(SL* ps, size_t pos);

void SeqListPrint(SL* ps);
