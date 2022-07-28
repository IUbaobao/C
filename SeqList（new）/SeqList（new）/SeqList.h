#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


#define N 100

typedef int SLDataType;

//��̬˳���
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};



//��̬˳���
typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;



//��ʼ��
void SeqListInit(SL* ps);

//����
void SeqListDestroy(SL* ps);


//��ɾ���
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);
int SeqListFind(SL* ps, SLDataType x);
void SeqListInsert(SL* ps, size_t pos, SLDataType x);
void SeqListErase(SL* ps, size_t pos);

void SeqListPrint(SL* ps);
