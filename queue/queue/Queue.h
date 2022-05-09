#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;

typedef struct Qnode
{
	QDataType date;
	struct Qnode* next;
}Qnode;

typedef struct Queue
{
	Qnode * head;
	Qnode* tail;
}Queue;


// ��ʼ������
void QueueInit(Queue* q);

// ��β�����
void QueuePush(Queue* q, QDataType data);

// ��ͷ������
void QueuePop(Queue* q);

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q);

// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q);

// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q);

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);

// ���ٶ���
void QueueDestroy(Queue* q);
