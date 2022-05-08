#define _CRT_SECURE_NO_WARNINGS

#include"Stack.h"

void StackInit(Stack* ps)
{
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tem = (STDataType*)realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (tem == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tem;
		ps->capacity = newCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	
	ps->top--;
}

STDataType StackTop(Stack* ps)
{
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}

int StackSize(Stack* ps)
{
	return ps->top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	return ps->top == 0;
}

void StackDestroy(Stack* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}



