#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

void menu()
{
	printf("**********************\n");
	printf("********1.play********\n");
	printf("********0.exit********\n");
	printf("**********************\n");

}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//��ʼ���׵�����
	BoardInit(mine, ROWS, COLS, '0');
	//��ʼ��չ�ֵ�����
	BoardInit(show, ROWS, COLS, '*');

	BoardPrint(show, ROW, COL);

	//����
	setmine(mine, ROW, COL);
	//BoardPrint(mine, ROW, COL);  //���׿���
	
	//�Ų���
	FindMine(mine, show, ROW, COL);


	//ɨ�׿�ʼ
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
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}