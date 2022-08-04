#define _CRT_SECURE_NO_WARNINGS


#include"Queue.h"
#include"Stack.h"
void QueueTest1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePop(&q);

	printf("%d\n", QueueFront(&q));
	printf("%d\n", QueueBack(&q));
	printf("%d\n ", QueueSize(&q));

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");

	QueueDestroy(&q);

}

void StackTest1()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	printf("%d ", StackTop(&s));
	StackPop(&s);
	StackPush(&s, 4);

	while (!StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	printf("\n");
	StackDestroy(&s);

}
int main()
{
	//QueueTest1();
	StackTest1();
	return 0;
}