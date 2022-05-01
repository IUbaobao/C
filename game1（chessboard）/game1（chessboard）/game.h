#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3		//行
#define COL 3		//列

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);
//打印棋盘
void BoardPrint(char board[ROW][COL], int row, int col);
//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);
//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//  版本1.0     判断游戏是否结束     玩家赢返回"*"，电脑赢返回"#"，棋盘满了返回"Q"
char  DetermineEnd1(char board[ROW][COL]);


//版本2.0    判断游戏是否结束     玩家赢返回"*"，电脑赢返回"#"，棋盘满了返回"Q"
char  DetermineEnd2(char board[ROW][COL],int row,int col);



