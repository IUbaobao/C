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
		printf("玩家下棋\n");
		PlayerMove(board, ROW, COL);
		ret= DetermineEnd2(board,ROW,COL);
		if (ret != '0')
		{
			break;
		}
		BoardPrint(board, ROW, COL);
		printf("电脑下棋\n");
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
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
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
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出成功\n");
			break;
		default:
			printf("无此选项，请重新选择\n");
			break;
		}

	} while (input);
	return 0;
}