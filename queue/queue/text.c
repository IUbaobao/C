#define _CRT_SECURE_NO_WARNINGS

#include"Queue.h"

void textQueue()
{
	Queue queue;
	QueueInit(&queue);
	QueuePush(&queue, 1);
	QueuePush(&queue, 2);
	QueuePush(&queue, 3);
	QueuePush(&queue, 5);
	QueuePush(&queue, 6);
	QueuePush(&queue, 4);
	printf("%d ", QueueBack(&queue));
	printf("\n%d\n ", QueueSize(&queue));

	while (!QueueEmpty(&queue))
	{
		printf("%d ", QueueFront(&queue));
		QueuePop(&queue);
	}
}
void menu()
{

		printf("*******************************\n");
		printf("       1.����   2.����         \n");
		printf("       3.��ȡ����ͷԪ��        \n");
		printf("       4.��ȡ���ж�βԪ��      \n");
		printf("       5.��ȡ��������ЧԪ�ظ���\n");
		printf("       6.������  7.��ӡ����  \n");
		printf("       -1.�˳�                 \n");
		printf("*******************************\n");
		printf(" ��ѡ��>:   \n");


}
void textMenu()
{
	Queue queue;
	QueueInit(&queue);
	int input = 0;
	QDataType x1 = 0;
	int  ret = 0;
	while (input != -1)
	{
			menu();
			scanf("%d", &input);
			switch (input)
			{
				case 1:
					printf("������Ҫ���е�ֵ����-1Ϊ����\n");
					scanf("%d", &x1);
					while (x1 != -1)
					{
						QueuePush(&queue, x1);
						scanf("%d", &x1);
					}
					break;
				case 2:
					QueuePop(&queue);
					printf("���гɹ�\n");
					break;
				case 3:
					printf("ͷ��Ԫ��Ϊ��%d \n", QueueFront(&queue));
					break;
				case 4:
					printf("β��Ԫ��Ϊ��%d \n", QueueBack(&queue));
					break;
				case 5:
					printf("��Ч�����У�%d \n", QueueSize(&queue));
					break;
				case 6:
					  ret = QueueEmpty(&queue);
					if (ret == 0)
					{
						printf("���зǿ�\n");
					}
					else
					{
						printf("����Ϊ��\n");
					}
					break;
				case 7:
					//���в�Ϊ��һֱ��ӡ
					while (!QueueEmpty(&queue))
					{
						printf("%d ", QueueFront(&queue));
						//��ӡһ��Popһ��
						QueuePop(&queue);
					}printf("\n");
					break;

				case -1:
					printf("�˳��ɹ�\n");
					break;
				default:
					printf("�޴�ѡ�����������\n");
					break;
			}
	}
	QueueDestroy(&queue);
}

int main()
{
	//textQueue();
	textMenu();
	return 0;
}