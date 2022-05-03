#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int LTDateType;

typedef struct ListNode
{
	LTDateType date;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

//��ʼ��
LTNode* ListInit();

//��ӡ
void ListPrint(LTNode* phead);

//�����½ڵ�
LTNode* BuyListNode(LTDateType x);

//β��
void ListPushBack(LTNode* phead, LTDateType x);

//βɾ
void ListPopBack(LTNode* phead);

//ͷ��
void ListPushFront(LTNode* phead, LTDateType x);

//ͷɾ
void ListPopFront(LTNode* phead);

//����,�ҵ����ض�Ӧ���ݵ�ַ���Ҳ�������NULL
LTNode* ListFind(LTNode* phead, LTDateType x);

//���룬��posλ��֮ǰ����
void ListInsert(LTNode* pos, LTDateType x);

//ɾ��ָ��λ��
void ListErase(LTNode* pos);

//��������
void ListDestroy(LTNode* phead);
