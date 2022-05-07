#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define ROW 10
#define COL 10

#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 30
//初始化棋盘
void BoardInit(char board[ROWS][COLS], int rows, int cols, char set);

//打印棋盘
void BoardPrint(char board[ROWS][COLS], int row, int col);

//布置雷
void setmine(char board[ROWS][COLS], int row, int col);

//扫雷开始
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS],int row, int col);

