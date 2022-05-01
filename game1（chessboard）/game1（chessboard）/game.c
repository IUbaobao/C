#define _CRT_SECURE_NO_WARNINGS

#include"game.h"


//��ʼ���ɿո�
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

//��ӡ����
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
		printf("����������>:");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		//�ж������Ƿ�Ϸ�
		if (x <= 3 && x > 0 && y <= 3 && y > 0)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ�ã��������壬��ѡ������λ��\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
}

//��������
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
////�汾1.0
////���Ӯ����"*"������Ӯ����""#���������˷���"Q"
//char  DetermineEnd1(char board[ROW][COL])
//{
//	//���Ӯ�����
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
//	//����Ӯ�����
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
//		//�ж������Ƿ�����
//		for (int i = 0; i < ROW; i++)
//		{
//			for (int j = 0; j < COL; j++)
//			{
//				if (board[i][j] == ' ')
//					return '0';
//			}
//		}
//	}
//	//�����ߵ������˵��û�зֳ�ʤ�������������Ѿ����ˣ���Ϊ�;�
//	return 'Q';
//}

//�汾2.0
// �ж���Ϸ�Ƿ����     ���Ӯ����"*"������Ӯ����"#"���������˷���"Q"
char  DetermineEnd2(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�ж���
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' '))
		{
			return board[i][1];
		}
	}
	//�ж���
	for (i = 0; i < row; i++)
	{
		if ((board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' '))
		{
			return board[1][i];
		}
	}
	//�ж϶Խ�
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//�ж������Ƿ�����
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			//������һ���ո��˵����û��������"0"
			if (board[i][j] == ' ')
				return '0';
		}
	}
	//�����ߵ������˵��û�зֳ�ʤ�������������Ѿ����ˣ���Ϊ�;�
	return 'Q';
}

