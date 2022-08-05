#define _CRT_SECURE_NO_WARNINGS



//����һ��ֻ���� '('��')'��'{'��'}'��'['��']'?���ַ��� s ���ж��ַ����Ƿ���Ч��
//
//��Ч�ַ��������㣺
//
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�
//
//
//ʾ�� 1��
//
//���룺s = "()"
//�����true
//ʾ��?2��
//
//���룺s = "()[]{}"
//�����true
//ʾ��?3��
//
//���룺s = "(]"
//�����false
//ʾ��?4��
//
//���룺s = "([)]"
//�����false
//ʾ��?5��
//
//���룺s = "{[]}"
//�����true
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/valid-parentheses
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<stdbool.h>
//
//
//typedef char STDataType;
//
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}Stack;
//
//
//void StackInit(Stack* ps);
//void StackPush(Stack* ps, STDataType x);
//void StackPop(Stack* ps);
//STDataType StackTop(Stack* ps);
//int StackSize(Stack* ps);
//bool StackEmpty(Stack* ps);
//void StackDestroy(Stack* ps);
//
//
//
//
//void StackInit(Stack* ps)
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->capacity = ps->top = 0;
//}
//
//void StackPush(Stack* ps, STDataType x)
//{
//	assert(ps);
//	if (ps->capacity == ps->top)
//	{
//		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		STDataType* tem = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
//		if (tem == NULL)
//		{
//			perror("realloc fail");
//			exit(-1);
//		}
//		ps->a = tem;
//		ps->capacity = newcapacity;
//	}
//	ps->a[ps->top] = x;
//	ps->top++;
//}
//
//void StackPop(Stack* ps)
//{
//	assert(ps);
//	ps->top--;
//}
//
//STDataType StackTop(Stack* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//	return ps->a[ps->top - 1];
//}
//
//int StackSize(Stack* ps)
//{
//	assert(ps);
//	return ps->top;
//}
//
//bool StackEmpty(Stack* ps)
//{
//	assert(ps);
//	return ps->top == 0;
//}
//
//void StackDestroy(Stack* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = ps->top = 0;
//}
//
//
//bool isValid(char* s) {
//	Stack stack;
//	StackInit(&stack);
//	while (*s)
//	{
//		if (*s == '{' || *s == '(' || *s == '[')
//		{
//			StackPush(&stack, *s);
//		}
//		else
//		{
//			if (StackEmpty(&stack))
//			{
//				StackDestroy(&stack);
//				return false;
//			}
//			char top1 = StackTop(&stack);
//			StackPop(&stack);
//			if ((top1 == '{' && *s != '}')
//				|| (top1 == '[' && *s != ']')
//				|| (top1 == '(' && *s != ')'))
//			{
//				StackDestroy(&stack);
//				return false;
//			}
//		}
//		s++;
//	}
//	bool flag = StackEmpty(&stack);
//	StackDestroy(&stack);
//
//	return flag;
//}
//
//
//
//
//
//
//int main()
//{
//	char arr[] = "()[]{}";
//	bool flag=isValid(arr);
//	return 0;
//}
//





//�ö���ʵ��ջ
//�����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ�����ֲ�����push��top��pop �� empty����
//
//ʵ�� MyStack �ࣺ
//
//void push(int x) ��Ԫ�� x ѹ��ջ����
//int pop() �Ƴ�������ջ��Ԫ�ء�
//int top() ����ջ��Ԫ�ء�
//boolean empty() ���ջ�ǿյģ����� true �����򣬷��� false
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/implement-stack-using-queues
//


//typedef int QDataType;
//
//
//typedef struct QueueNode
//{
//    QDataType data;
//    struct QueueNode* next;
//}QueueNode;
//
//
//typedef struct Queue
//{
//    QueueNode* head;
//    QueueNode* tail;
//    int size;
//}Queue;
//
//
//void QueueInit(Queue* q);
//void QueuePush(Queue* q, QDataType x);
//void QueuePop(Queue* q);
//QDataType QueueFront(Queue* q);
//QDataType QueueBack(Queue* q);
//bool QueueEmpty(Queue* q);
//int QueueSize(Queue* q);
//void QueueDestroy(Queue* q);
//
//
//
//
//
//
//
//
//typedef struct {
//    Queue queue1;
//    Queue queue2;
//} MyStack;
//
//
//
//void QueueInit(Queue* q)
//{
//    assert(q);
//    q->head = q->tail = NULL;
//    q->size = 0;
//}
//
//
//void QueuePush(Queue* q, QDataType x)
//{
//    assert(q);
//    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
//    if (newNode == NULL)
//    {
//        perror("malloc fail");
//        exit(-1);
//    }
//    if (q->tail == NULL)
//    {
//        q->tail = q->head = newNode;
//    }
//    else
//    {
//        q->tail->next = newNode;
//        q->tail = newNode;
//    }
//    newNode->data = x;
//    newNode->next = NULL;
//    q->size++;
//}
//
//
//void QueuePop(Queue* q)
//{
//    assert(q);
//    assert(!QueueEmpty(q));
//    if (q->head->next == NULL)
//    {
//        free(q->head);
//        q->head = q->tail = NULL;
//    }
//    else
//    {
//        QueueNode* del = q->head;
//        q->head = q->head->next;
//        free(del);
//    }
//    q->size--;
//}
//
//
//QDataType QueueFront(Queue* q)
//{
//    assert(q);
//    assert(!QueueEmpty(q));
//    return q->head->data;
//}
//
//
//QDataType QueueBack(Queue* q)
//{
//    assert(q);
//    assert(!QueueEmpty(q));
//    return q->tail->data;
//
//}
//
//
//bool QueueEmpty(Queue* q)
//{
//    assert(q);
//    return q->head == NULL;
//}
//
//
//int QueueSize(Queue* q)
//{
//    assert(q);
//    return q->size;
//}
//
//
//void QueueDestroy(Queue* q)
//{
//    assert(q);
//
//    while (q->head)
//    {
//        QueueNode* del = q->head;
//        q->head = q->head->next;
//        free(del);
//    }
//    q->head = q->tail = NULL;
//    q->size = 0;
//}
//
//
//
//
//
//
//
//MyStack* myStackCreate() {
//    MyStack* ret = (MyStack*)malloc(sizeof(MyStack));
//    QueueInit(&ret->queue1);
//    QueueInit(&ret->queue2);
//    return ret;
//}
//
//
//void myStackPush(MyStack* obj, int x) {
//    if (!QueueEmpty(&obj->queue1))
//    {
//        QueuePush(&obj->queue1, x);
//    }
//    else
//    {
//        QueuePush(&obj->queue2, x);
//    }
//}
//
//
//int myStackPop(MyStack* obj) {
//    Queue* empty = &obj->queue1;
//    Queue* noempty = &obj->queue2;
//    if (QueueEmpty(&obj->queue2))
//    {
//        empty = &obj->queue2;
//        noempty = &obj->queue1;
//    }
//    while (QueueSize(noempty) > 1)
//    {
//        QueuePush(empty, QueueFront(noempty));
//        QueuePop(noempty);
//    }
//    int top = QueueFront(noempty);
//    QueuePop(noempty);
//    return top;
//}
//
//
//int myStackTop(MyStack* obj) {
//    Queue* empty = &obj->queue1;
//    Queue* noempty = &obj->queue2;
//    if (QueueEmpty(&obj->queue2))
//    {
//        empty = &obj->queue2;
//        noempty = &obj->queue1;
//    }
//    return QueueBack(noempty);
//}
//
//
//bool myStackEmpty(MyStack* obj) {
//
//
//    return QueueEmpty(&obj->queue1) && QueueEmpty(&obj->queue2);
//}
//
//
//void myStackFree(MyStack* obj) {
//
//
//    QueueDestroy(&obj->queue1);
//    QueueDestroy(&obj->queue2);
//    free(obj);
//
//
//}











//��ջʵ�ֶ���
//�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����
//
//ʵ�� MyQueue �ࣺ
//
//void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
//int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
//int peek() ���ض��п�ͷ��Ԫ��
//boolean empty() �������Ϊ�գ����� true �����򣬷��� false
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/implement-queue-using-stacks



#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


typedef int STDataType;

typedef struct Stack
{
    STDataType* a;
    int top;
    int capacity;
}Stack;


void StackInit(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackSize(Stack* ps);
bool StackEmpty(Stack* ps);
void StackDestroy(Stack* ps);


void StackInit(Stack* ps)
{
    assert(ps);
    ps->a = NULL;
    ps->capacity = ps->top = 0;
}

void StackPush(Stack* ps, STDataType x)
{
    assert(ps);
    if (ps->capacity == ps->top)
    {
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        STDataType* tem = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
        if (tem == NULL)
        {
            perror("realloc fail");
            exit(-1);
        }
        ps->a = tem;
        ps->capacity = newcapacity;
    }
    ps->a[ps->top] = x;
    ps->top++;
}

void StackPop(Stack* ps)
{
    assert(ps);
    ps->top--;
}

STDataType StackTop(Stack* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));
    return ps->a[ps->top - 1];
}

int StackSize(Stack* ps)
{
    assert(ps);
    return ps->top;
}

bool StackEmpty(Stack* ps)
{
    assert(ps);
    return ps->top == 0;
}

void StackDestroy(Stack* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->top = 0;
}




typedef struct {
    Stack s1;
    Stack s2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* ret = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&ret->s1);
    StackInit(&ret->s2);
    return ret;
}

void myQueuePush(MyQueue* obj, int x) {
    StackPush(&obj->s1, x);
}

int myQueuePop(MyQueue* obj) {
    int pop = 0;
    if (!StackEmpty(&obj->s2))
    {
        pop = StackTop(&obj->s2);
        StackPop(&obj->s2);
    }
    else
    {
        while (!StackEmpty(&obj->s1))
        {
            StackPush(&obj->s2, StackTop(&obj->s1));
            StackPop(&obj->s1);
        }
        pop = StackTop(&obj->s2);
        StackPop(&obj->s2);
    }
    return pop;
}

int myQueuePeek(MyQueue* obj) {
    int top = 0;
    if (!StackEmpty(&obj->s2))
    {
        top = StackTop(&obj->s2);
    }
    else
    {
        while (!StackEmpty(&obj->s1))
        {
            StackPush(&obj->s2, StackTop(&obj->s1));
            StackPop(&obj->s1);
        }
        top = StackTop(&obj->s2);
    }
    return top;

}

bool myQueueEmpty(MyQueue* obj) {

    return (StackEmpty(&obj->s1) && StackEmpty(&obj->s2));
}

void myQueueFree(MyQueue* obj) {
    StackDestroy(&obj->s1);
    StackDestroy(&obj->s2);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/




