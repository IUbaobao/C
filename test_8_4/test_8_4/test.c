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

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


typedef char STDataType;

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


bool isValid(char* s) {
	Stack stack;
	StackInit(&stack);
	while (*s)
	{
		if (*s == '{' || *s == '(' || *s == '[')
		{
			StackPush(&stack, *s);
		}
		else
		{
			if (StackEmpty(&stack))
			{
				StackDestroy(&stack);
				return false;
			}
			char top1 = StackTop(&stack);
			StackPop(&stack);
			if ((top1 == '{' && *s != '}')
				|| (top1 == '[' && *s != ']')
				|| (top1 == '(' && *s != ')'))
			{
				StackDestroy(&stack);
				return false;
			}
		}
		s++;
	}
	bool flag = StackEmpty(&stack);
	StackDestroy(&stack);

	return flag;
}






int main()
{
	char arr[] = "()[]{}";
	bool flag=isValid(arr);
	return 0;
}








