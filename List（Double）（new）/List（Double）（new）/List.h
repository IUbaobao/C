#pragma once


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

//����ͷ���
ListNode* ListCreate();

void ListPrint(ListNode* phead);
//��ɾ���
ListNode* ListFind(ListNode* phead, LTDataType x);
void ListPushFront(ListNode* phead, LTDataType x);
void ListPushBack(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);
void ListPopBack(ListNode* phead);
//��pos֮ǰ����
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);

void ListDestroy(ListNode* phead);