#define _CRT_SECURE_NO_WARNINGS

#include"game.h"
void menu()
{
	printf("******************************\n");
	printf("******* 1. play    0. exit*****\n");
	printf("******************************\n");
}

void game()
{
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	BoardPrint(board, ROW, COL);
	char ret;
	while (1)
	{
		printf("�������\n");
		PlayerMove(board, ROW, COL);
		ret= DetermineEnd2(board,ROW,COL);
		if (ret != '0')
		{
			break;
		}
		BoardPrint(board, ROW, COL);
		printf("��������\n");
		ComputerMove(board, ROW, COL);
		ret = DetermineEnd2(board, ROW, COL);
		if (ret != '0')
		{
			break;
		}
		BoardPrint(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	BoardPrint(board, ROW, COL);

}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do 
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳��ɹ�\n");
			break;
		default:
			printf("�޴�ѡ�������ѡ��\n");
			break;
		}

	} while (input);
	return 0;
}