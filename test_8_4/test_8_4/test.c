#define _CRT_SECURE_NO_WARNINGS



//给定一个只包括 '('，')'，'{'，'}'，'['，']'?的字符串 s ，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//
//
//示例 1：
//
//输入：s = "()"
//输出：true
//示例?2：
//
//输入：s = "()[]{}"
//输出：true
//示例?3：
//
//输入：s = "(]"
//输出：false
//示例?4：
//
//输入：s = "([)]"
//输出：false
//示例?5：
//
//输入：s = "{[]}"
//输出：true
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/valid-parentheses
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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








