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
	printf("\n********ɨ����Ϸ*********\n");
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
	printf("\n********ɨ����Ϸ*********\n");

}



void setmine(char board[ROWS][COLS], int row, int col)
{
	//countΪ�׵�����
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (board[x][y] == '0')
		{
			//ÿ��һ���ף��Ͱ�count-1
			count--;
			board[x][y] = '1';
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	//���������Χ8�������ж��ٸ���
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

////����չ������
//void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
//{
//
//	int x = 0;
//	int y = 0;
//	//winΪҪʤ�����׵��ܴ���
//	int win = row*col- EASY_COUNT;
//	while (win)
//	{
//		printf("��������:>");
//		scanf("%d%d", &x, &y);
//		//�ж������Ƿ�Ϸ�
//		if (x >= 1 && x <= row && y >= 1 && y <= col)
//		{
//			if (show[x][y]!='*')
//			{
//				printf("�����ѱ�ռ�ã�����������\n");
//				
//			}
//			else
//			{
//				if (mine[x][y] == '1')
//				{
//					printf("���ź����㱻ը����\n");
//					//��Ϸ����ǰ��ӡ�׵Ĳ���λ�ø���ҿ�
//					BoardPrint(mine, ROW, COL);
//
//					break;
//				}
//				else
//				{
//					//û���ף��Ͱ�win-1��ֱ��winΪ0��ʤ��
//					win--;
//					//��ȡ��Χ�׵ĸ���
//					int  count = get_mine_count(mine, x, y);
//					//���ַ�'0'��Ϊ�˽����ֱ�Ϊ�ַ���ʾ
//
//					show[x][y] = count + '0';
//					BoardPrint(show, row, col);
//				}
//			}
//		}
//		else
//		{
//			printf("����Ƿ�������������\n");
//		}
//	}
//	if(win==0)
//	printf("��ϲ�㣬��Ϸʤ��!\n");
//}
//


int win = ROW * COL - EASY_COUNT;
//չ������
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
	//winΪҪʤ�����׵��ܴ���

	while (win)
	{
		printf("��������:>");
		scanf("%d%d", &x, &y);
		//�ж������Ƿ�Ϸ�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("�����ѱ�ռ�ã�����������\n");

			}
			else
			{
				if (mine[x][y] == '1')
				{
					printf("���ź����㱻ը����\n");
					//��Ϸ����ǰ��ӡ�׵Ĳ���λ�ø���ҿ�
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
			printf("����Ƿ�������������\n");
		}
	}
	if (win == 0)
		printf("��ϲ�㣬��Ϸʤ��!\n");
}





