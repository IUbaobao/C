#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>

typedef int SLDateType;
//动态顺序表
typedef struct SeqList
{
	SLDateType* a;
	int size;		//表示数组存了多少个有效数据
	int capacity;	//数组实际能存多少个数据
}SL;

//打印顺序表
void SeqListPrint(SL* ps);
//初始化
void SeqListInit(SL* ps);
//摧毁顺序表
void SeqListDestroy(SL* ps);
//检查容量
void SeqListCheckCapacity(SL* ps);
//尾插
void SeqListPushBack(SL* ps, SLDateType x);
//尾删
void SeqListPopBack(SL* ps);
//头插
void SeqListPushFront(SL* ps, SLDateType x);
//头删
void SeqListPopFront(SL* ps);
//找到了返回x位置的下标，找不到返回-1
int SeqListFind(SL* ps, SLDateType  x);
//指定pos下标位置插入
void SeqListInsert(SL* ps, int pos, SLDateType x);
//删除pos位置的数据
void SeqListErase(SL* ps, int pos);