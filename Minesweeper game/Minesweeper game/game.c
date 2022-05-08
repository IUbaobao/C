#define _CRT_SECURE_NO_WARNINGS

#include"game.h"


void BoardInit(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols;j++)
		{
			board[i][j] = set;
		}
	}
}

void BoardPrint(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	printf("\n********扫雷游戏*********\n");
	printf(" ");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 0; i <= col; i++)
	{
		printf("--");
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		if (i < 10)
			printf("%d |", i);
		else
			printf("%d|", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);

		}
		printf("\n");
	}
	printf("\n********扫雷游戏*********\n");

}



void setmine(char board[ROWS][COLS], int row, int col)
{
	//count为雷的数量
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (board[x][y] == '0')
		{
			//每布一个雷，就把count-1
			count--;
			board[x][y] = '1';
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	//检查坐标周围8个格子有多少个雷
	return (mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0');
}
//

////不带展开功能
//void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
//{
//
//	int x = 0;
//	int y = 0;
//	//win为要胜利排雷的总次数
//	int win = row*col- EASY_COUNT;
//	while (win)
//	{
//		printf("输入坐标:>");
//		scanf("%d%d", &x, &y);
//		//判断坐标是否合法
//		if (x >= 1 && x <= row && y >= 1 && y <= col)
//		{
//			if (show[x][y]!='*')
//			{
//				printf("坐标已被占用，请重新输入\n");
//				
//			}
//			else
//			{
//				if (mine[x][y] == '1')
//				{
//					printf("很遗憾，你被炸死了\n");
//					//游戏结束前打印雷的布置位置给玩家看
//					BoardPrint(mine, ROW, COL);
//
//					break;
//				}
//				else
//				{
//					//没踩雷，就把win-1，直至win为0就胜利
//					win--;
//					//获取周围雷的个数
//					int  count = get_mine_count(mine, x, y);
//					//加字符'0'是为了将数字变为字符表示
//
//					show[x][y] = count + '0';
//					BoardPrint(show, row, col);
//				}
//			}
//		}
//		else
//		{
//			printf("坐标非法，请重新输入\n");
//		}
//	}
//	if(win==0)
//	printf("恭喜你，游戏胜利!\n");
//}
//


int win = ROW * COL - EASY_COUNT;
//展开功能
void openshow(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int win = ROW * COL - EASY_COUNT;
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
	{
		win--;
		int count = get_mine_count(mine, x, y);
		if (count == 0)
		{
			if (show[x][y] != '0')
			{
				show[x][y] = '0';
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -1; j <= 1; j++)
					{
						openshow(mine, show, x + i, y + j);
					}
				}
			}

		}
		else
		{
			show[x][y] = count + '0';
			return;
		}
	}

}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	win= ROW * COL - EASY_COUNT;
	int x = 0;
	int y = 0;
	//win为要胜利排雷的总次数

	while (win)
	{
		printf("输入坐标:>");
		scanf("%d%d", &x, &y);
		//判断坐标是否合法
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("坐标已被占用，请重新输入\n");

			}
			else
			{
				if (mine[x][y] == '1')
				{
					printf("很遗憾，你被炸死了\n");
					//游戏结束前打印雷的布置位置给玩家看
					BoardPrint(mine, ROW, COL);

					break;
				}
				else
				{
					openshow(mine, show, x, y);
					BoardPrint(show, row, col);
				}
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
	if (win == 0)
		printf("恭喜你，游戏胜利!\n");
}





