#define _CRT_SECURE_NO_WARNINGS

#include"game.h"


//初始化成空格
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void BoardPrint(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if(j<col-1)
			printf("|");
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			printf("---");
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
	}
}


void PlayerMove(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		printf("请输入坐标>:");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		//判断坐标是否合法
		if (x <= 3 && x > 0 && y <= 3 && y > 0)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，不能下棋，请选择其他位置\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
}

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
//}
////版本1.0
////玩家赢返回"*"，电脑赢返回""#，棋盘满了返回"Q"
//char  DetermineEnd1(char board[ROW][COL])
//{
//	//玩家赢的情况
//	if ((board[0][0] == board[0][1]  && board[0][1] == board[0][2]&&board[0][0]=='*')
//		|| (board[1][0] == board[1][1]  && board[1][1] == board[1][2] && board[1][0] == '*')
//		|| (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == '*')
//		|| (board[0][0] == board[1][0]  && board[1][0] == board[2][0]&&board[0][0] == '*')
//		|| (board[0][1] == board[1][1]  && board[1][1] == board[2][1] && board[0][1] == '*')
//		|| (board[0][2] == board[1][2]  && board[1][2] == board[2][2] && board[0][2] == '*')
//		|| (board[0][0] == board[1][1]  && board[1][1] == board[2][2] && board[0][0] == '*')
//		|| (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == '*'))
//	{
//		
//		return '*';
//	}
//	//电脑赢的情况
//	else if ((board[0][0] == board[0][1] && board[0][1] == board[0][2]&&board[0][0]=='#')
//		|| (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == '#')
//		|| (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == '#')
//		|| (board[0][0] == board[1][0]  && board[1][0] == board[2][0]&&board[0][0] == '#')
//		|| (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == '#')
//		|| (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == '#')
//		|| (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == '#')
//		|| (board[0][2] == board[1][1]  && board[1][1] == board[2][0] && board[0][02] == '#'))
//	{
//		
//		return '#';
//	}
//	else
//	{
//		//判断棋盘是否满了
//		for (int i = 0; i < ROW; i++)
//		{
//			for (int j = 0; j < COL; j++)
//			{
//				if (board[i][j] == ' ')
//					return '0';
//			}
//		}
//	}
//	//程序走到这里就说明没有分出胜负，而且棋盘已经满了，故为和局
//	return 'Q';
//}

//版本2.0
// 判断游戏是否结束     玩家赢返回"*"，电脑赢返回"#"，棋盘满了返回"Q"
char  DetermineEnd2(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断行
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' '))
		{
			return board[i][1];
		}
	}
	//判断列
	for (i = 0; i < row; i++)
	{
		if ((board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' '))
		{
			return board[1][i];
		}
	}
	//判断对角
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//判断棋盘是否满了
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			//其中有一个空格就说明还没满，返回"0"
			if (board[i][j] == ' ')
				return '0';
		}
	}
	//程序走到这里就说明没有分出胜负，而且棋盘已经满了，故为和局
	return 'Q';
}

