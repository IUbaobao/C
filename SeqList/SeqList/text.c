#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"



void text1()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);

	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPrint(&s1);

	SeqListDestroy(&s1);
}

void text2()
{
	SL s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);

	int i=SeqListFind(&s, 5);
	printf("%d ", i);
	//SeqListPushFront(&s, 9);
	//SeqListPushFront(&s, 9);
	//SeqListPushFront(&s, 9);
	//SeqListPushFront(&s, 9);
	//SeqListPushFront(&s, 9);
	//SeqListPushFront(&s, 9);
	//SeqListPushFront(&s, 8);

	//SeqListPrint(&s);
	//SeqListPopFront(&s);
	//SeqListPopFront(&s);
	//SeqListPopFront(&s);
	//SeqListPopFront(&s);
	//SeqListPopFront(&s);
	//SeqListPopFront(&s);
	//SeqListPrint(&s);
	//SeqListDestroy(&s);
}

void text3()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPrint(&s1);

	SeqListInsert(&s1, 1, 0);
	SeqListPrint(&s1);

	SeqListErase(&s1, 2);
	SeqListPrint(&s1);
	SeqListErase(&s1, 1);
	SeqListPrint(&s1);
	SeqListDestroy(&s1);

}
void menu()
{
	printf("************************************\n");
	printf("    1.头插   2.头删\n");
	printf("    3.尾插   4.尾删\n");
	printf("    5.打印   6.插入\n");
	printf("    7.查找   8.删除指定位置\n");
	printf("    -1.退出\n");
	printf("************************************\n");
	printf(" 请选择>:   \n");

}
void menuText()
{
	SL s1;
	int input = 0;
	SLDateType x1 = 0;
	SLDateType x2 = 0;
	SeqListInit(&s1);
	while(input!=-1)
	{

		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入你要头插入的数，以-1为结束\n");
			scanf("%d", &x1);
			while (x1 != -1)
			{
				SeqListPushFront(&s1, x1);
				scanf("%d", &x1);
			}
			printf("插入成功\n");
			break;
		case 2:
			SeqListPopFront(&s1);
			printf("头删成功\n");
			break;
		case 3:
			printf("请输入你要尾插入的数，以-1为结束\n");
			scanf("%d", &x1);
			while (x1 != -1)
			{
				SeqListPushBack(&s1, x1);
				scanf("%d", &x1);
			}
			printf("插入成功\n");
			break;
		case 4:
			SeqListPopBack(&s1);
			printf("尾删成功\n");
			break;
		case 5:
			SeqListPrint(&s1);
			printf("打印成功\n");
			break;
		case 6:
			printf("请输入按“在哪个位置 插入”的数据为顺序输入。如在第二个位置，插入3，“2 3”\n");
			scanf("%d %d", &x1, &x2);
			SeqListInsert(&s1, x1, x2);
			printf("插入成功\n");
			break;
		case 7:
			printf("请输入你要查找的数据\n");
			scanf("%d", &x1);
			int ret=SeqListFind(&s1, x1);
			if (ret != -1)
			{
				printf("查到了，下标为%d\n", ret);
			}
			else
				printf("查不到\n");
			break;
		case 8:
			printf("请输入你要删除数据的位置\n");
			scanf("%d", &x1);
			SeqListErase(&s1, x1);
			printf("删除成功\n");
			break;
		case -1:
			printf("退出成功\n");
			break;
		default:
			printf("无此选项，请重新输入\n");
			break;
		}
	}
	SeqListDestroy(&s1);
}
int main()
{
	//text1();
	//text2();
	//text3();
	menuText();
}