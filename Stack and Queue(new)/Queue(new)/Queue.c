#define _CRT_SECURE_NO_WARNINGS

#include"Queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->head = q->tail = NULL;
	q->size = 0;
}

void QueuePush(Queue* q, QDataType x)
{
	assert(q);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	if (q->tail == NULL)
	{
		q->tail = q->head = newNode;
	}
	else
	{
		q->tail->next = newNode;
		q->tail = newNode;
	}
	newNode->data = x;
	newNode->next = NULL;
	q->size++;
}

void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	if (q->head->next == NULL)
	{
		free(q->head);
		q->head = q->tail = NULL;
	}
	else
	{
		QueueNode* del = q->head;
		q->head = q->head->next;
		free(del);
	}
	q->size--;
}

QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->head->data;
}

QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->tail->data;
	
}

bool QueueEmpty(Queue* q)
{
	assert(q);
	return q->head == NULL;
}

int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}

void QueueDestroy(Queue* q)
{
	assert(q);
	
	while (q->head)
	{
		QueueNode* del = q->head;
		q->head = q->head->next;
		free(del);
	}
	q->head = q->tail = NULL;
	q->size = 0;
}