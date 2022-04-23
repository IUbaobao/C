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


//��ӡ����
void SListPrint(SList* phead);

//��������
void SListDestroy(SList** pphead);

//β��
void SListPushBack(SList** pphead,SLDateType x);

//βɾ
void SListPopBack(SList** pphead);

//ͷ��
void SListPushFront(SList** pphead, SLDateType x);

//ͷɾ
void SListPopFront(SList** pphead);

//���ң��ҵ��˷���x��ַ���Ҳ�������NULL
SList* SListFind(SList* plist, SLDateType x);

//��posλ�ú������
void SListInsertAfter(SList* pos, SLDateType x);

//ɾ��posλ�ú�һ��
void SListEraseAfter(SList* pos);
