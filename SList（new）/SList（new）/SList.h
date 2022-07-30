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

//��ӡ
void SListPrint(SList* phead);
//����һ���ڵ�
SList* BuySListNode(SLDataType x);

//��ɾ���
void SListPushFront(SList** pphead, SLDataType x);
void SListPushBack(SList** pphead, SLDataType x);
void SListPopFront(SList** pphead);
void SListPopBack(SList** pphead);
SList* SListFind(SList* phead, SLDataType x);

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿  ���� ǰ�����鷳��ʱ�临�Ӷ�O(N)
void SListInsertAfter(SList* pos, SLDataType x);


// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�  ���� ǰ�����鷳��ʱ�临�Ӷ�O(N)
void SListEraseAfter(SList* pos);

void SListDestroy(SList* phead);
