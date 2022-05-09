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
		printf("       1.入列   2.出列         \n");
		printf("       3.获取队列头元素        \n");
		printf("       4.获取队列队尾元素      \n");
		printf("       5.获取队列中有效元素个数\n");
		printf("       6.检测队列  7.打印队列  \n");
		printf("       -1.退出                 \n");
		printf("*******************************\n");
		printf(" 请选择>:   \n");


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
					printf("输入你要入列的值，以-1为结束\n");
					scanf("%d", &x1);
					while (x1 != -1)
					{
						QueuePush(&queue, x1);
						scanf("%d", &x1);
					}
					break;
				case 2:
					QueuePop(&queue);
					printf("出列成功\n");
					break;
				case 3:
					printf("头部元素为：%d \n", QueueFront(&queue));
					break;
				case 4:
					printf("尾部元素为：%d \n", QueueBack(&queue));
					break;
				case 5:
					printf("有效个数有：%d \n", QueueSize(&queue));
					break;
				case 6:
					  ret = QueueEmpty(&queue);
					if (ret == 0)
					{
						printf("队列非空\n");
					}
					else
					{
						printf("队列为空\n");
					}
					break;
				case 7:
					//队列不为空一直打印
					while (!QueueEmpty(&queue))
					{
						printf("%d ", QueueFront(&queue));
						//打印一个Pop一个
						QueuePop(&queue);
					}printf("\n");
					break;

				case -1:
					printf("退出成功\n");
					break;
				default:
					printf("无此选项，请重新输入\n");
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