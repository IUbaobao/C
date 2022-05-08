#define _CRT_SECURE_NO_WARNINGS

#include"Stack.h"

void textStack1()
{
	Stack stack;
	StackInit(&stack);
	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackPush(&stack, 3);
	StackPush(&stack, 4);
	while (StackEmpty(&stack) == 0)
	{
		printf("%d ", StackTop(&stack));
		StackPop(&stack);
	}

}
void menu()
{

		printf("*******************************\n");
		printf("       1.入栈   2.出栈         \n");
		printf("       3.获取栈顶元素          \n");
		printf("       4.获取栈中有效元素个数  \n");
		printf("       5.检测栈  6.打印栈数据   \n");
		printf("       -1.退出                 \n");
		printf("*******************************\n");
		printf(" 请选择>:   \n");

}
void textMenu()
{
	Stack stack;
	StackInit(&stack);
	int input = 0;
	STDataType x1 = 0;
	int  ret = 0;
	while (input != -1)
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("输入你要入栈的值，以-1为结束\n");
			scanf("%d", &x1);
			while (x1 != -1)
			{
				StackPush(&stack, x1);
				scanf("%d", &x1);
			}
			break;
		case 2:
			StackPop(&stack);
			printf("出栈成功\n");
			break;
		case 3:
			printf("栈顶元素为：%d \n", StackTop(&stack));
			break;
		case 4:
			printf("有效个数有：%d \n", StackSize(&stack));
			break;
		case 5:
			ret = StackEmpty(&stack);
			if (ret == 0)
			{
				printf("栈非空\n");
			}
			else
			{
				printf("栈为空\n");
			}
			break;
		case 6:		
			//栈不为空一直打印
			while (!StackEmpty(&stack))
			{
				printf("%d ", StackTop(&stack));
				//打印一个Pop一个
				StackPop(&stack);
			}printf("\n");
			break;
		case -1:
			printf("退出成功\n");
			break;
		default:
			printf("无此选项，请重新输入\n");
			break;
		}
	}
	StackDestroy(&stack);
}
int main()
{
	//textStack1();
	textMenu();

	return 0;
}