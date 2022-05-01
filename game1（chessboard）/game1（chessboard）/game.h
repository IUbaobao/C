#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3		//��
#define COL 3		//��

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ����
void BoardPrint(char board[ROW][COL], int row, int col);
//�������
void PlayerMove(char board[ROW][COL], int row, int col);
//��������
void ComputerMove(char board[ROW][COL], int row, int col);

//  �汾1.0     �ж���Ϸ�Ƿ����     ���Ӯ����"*"������Ӯ����"#"���������˷���"Q"
char  DetermineEnd1(char board[ROW][COL]);


//�汾2.0    �ж���Ϸ�Ƿ����     ���Ӯ����"*"������Ӯ����"#"���������˷���"Q"
char  DetermineEnd2(char board[ROW][COL],int row,int col);



