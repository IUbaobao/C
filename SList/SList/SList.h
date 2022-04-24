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


//��ӡ����
void SListPrint(SLNode* phead);

//��������
void SListDestroy(SLNode** pphead);

//β��
void SListPushBack(SLNode** pphead,SLDateType x);

//βɾ
void SListPopBack(SLNode** pphead);

//ͷ��
void SListPushFront(SLNode** pphead, SLDateType x);

//ͷɾ
void SListPopFront(SLNode** pphead);

//���ң��ҵ��˷���x��ַ���Ҳ�������NULL
SLNode* SListFind(SLNode* plist, SLDateType x);

//��posλ�ú������
void SListInsertAfter(SLNode* pos, SLDateType x);

//ɾ��posλ�ú�һ��
void SListEraseAfter(SLNode* pos);
