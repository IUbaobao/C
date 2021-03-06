#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

void menu()
{
	printf("\n**********************\n");
	printf("********1.play********\n");
	printf("********0.exit********\n");
	printf("**********************\n");

}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化雷的棋盘
	BoardInit(mine, ROWS, COLS, '0');
	//初始化展现的棋盘
	BoardInit(show, ROWS, COLS, '*');

	BoardPrint(show, ROW, COL);

	//布雷
	setmine(mine, ROW, COL);
	//BoardPrint(mine, ROW, COL);  //作弊开关
	
	//排查雷
	FindMine(mine, show, ROW, COL);


	//扫雷开始
	//FindMine(mine, show, ROW, COL);

}

int main()
{
	system("color 2");
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}