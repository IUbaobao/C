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
		printf("       1.��ջ   2.��ջ         \n");
		printf("       3.��ȡջ��Ԫ��          \n");
		printf("       4.��ȡջ����ЧԪ�ظ���  \n");
		printf("       5.���ջ  6.��ӡջ����   \n");
		printf("       -1.�˳�                 \n");
		printf("*******************************\n");
		printf(" ��ѡ��>:   \n");

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
			printf("������Ҫ��ջ��ֵ����-1Ϊ����\n");
			scanf("%d", &x1);
			while (x1 != -1)
			{
				StackPush(&stack, x1);
				scanf("%d", &x1);
			}
			break;
		case 2:
			StackPop(&stack);
			printf("��ջ�ɹ�\n");
			break;
		case 3:
			printf("ջ��Ԫ��Ϊ��%d \n", StackTop(&stack));
			break;
		case 4:
			printf("��Ч�����У�%d \n", StackSize(&stack));
			break;
		case 5:
			ret = StackEmpty(&stack);
			if (ret == 0)
			{
				printf("ջ�ǿ�\n");
			}
			else
			{
				printf("ջΪ��\n");
			}
			break;
		case 6:		
			//ջ��Ϊ��һֱ��ӡ
			while (!StackEmpty(&stack))
			{
				printf("%d ", StackTop(&stack));
				//��ӡһ��Popһ��
				StackPop(&stack);
			}printf("\n");
			break;
		case -1:
			printf("�˳��ɹ�\n");
			break;
		default:
			printf("�޴�ѡ�����������\n");
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