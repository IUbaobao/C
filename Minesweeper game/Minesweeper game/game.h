#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 4
//��ʼ������
void BoardInit(char board[ROWS][COLS], int rows, int cols, char set);

//��ӡ����
void BoardPrint(char board[ROWS][COLS], int row, int col);

//������
void setmine(char board[ROWS][COLS], int row, int col);

//ɨ�׿�ʼ
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS],int row, int col);

