#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>

typedef int SLDateType;
//��̬˳���
typedef struct SeqList
{
	SLDateType* a;
	int size;		//��ʾ������˶��ٸ���Ч����
	int capacity;	//����ʵ���ܴ���ٸ�����
}SL;

//��ӡ˳���
void SeqListPrint(SL* ps);
//��ʼ��
void SeqListInit(SL* ps);
//�ݻ�˳���
void SeqListDestroy(SL* ps);
//�������
void SeqListCheckCapacity(SL* ps);
//β��
void SeqListPushBack(SL* ps, SLDateType x);
//βɾ
void SeqListPopBack(SL* ps);
//ͷ��
void SeqListPushFront(SL* ps, SLDateType x);
//ͷɾ
void SeqListPopFront(SL* ps);
//�ҵ��˷���xλ�õ��±꣬�Ҳ�������-1
int SeqListFind(SL* ps, SLDateType  x);
//ָ��pos�±�λ�ò���
void SeqListInsert(SL* ps, int pos, SLDateType x);
//ɾ��posλ�õ�����
void SeqListErase(SL* ps, int pos);