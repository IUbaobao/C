#define _CRT_SECURE_NO_WARNINGS

#include"Queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->head = q->tail = NULL;
}

void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	Qnode* newNode = (Qnode*)malloc(sizeof(Qnode));
	newNode->date = data;
	newNode->next = NULL;

	if (q->head == NULL)
	{
		q->head = q->tail = newNode;
	}
	else
	{
		q->tail->next = newNode;
		q->tail = q->tail->next;
	}
}

void QueuePop(Queue* q)
{
	assert(q);
	assert(q->head);
	Qnode* next = q->head->next;
	free(q->head);
	q->head = next;
}

QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->head);
	return q->head->date;
}

QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->tail);
	return q->tail->date;
}

int QueueSize(Queue* q)
{
	assert(q);
	Qnode* cur = q->head;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->head == NULL;
}

void QueueDestroy(Queue* q)
{
	assert(q);
	Qnode* cur = q->head;
	while (cur)
	{
		Qnode* next = cur->next;
		free(cur);
		cur=next;
	}
	q->tail=q->head = NULL;

}