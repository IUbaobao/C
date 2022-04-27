#define _CRT_SECURE_NO_WARNINGS

#include"SList.h"

void SListText1()
{
	SLNode* list=NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPrint(list);

	SListPopBack(&list);
	SListPrint(list);
	SListPopBack(&list);
	SListPrint(list);
	SListPopBack(&list);
	SListPrint(list);

}

void SListText2()
{
	SLNode* list = NULL;
	SListPushFront(&list, 1);
	SListPushFront(&list, 2);
	SListPushFront(&list, 3);
	SListPushFront(&list, 4);
	SListPushFront(&list, 5);
	SListPrint(list);
	int i = 1;
	SLNode* pos = SListFind(list, 2);
	SListEraseAfter(pos);
	SListPrint(list);
	//while (pos)
	//{
	//	printf("第%d个pos节点：%p->%d\n", i++, pos, pos->data);
	//	pos = SListFind(pos->next, 3);

	////}
	//SListInsertAfter(pos, 30);
	//SListPrint(list);

	// pos = SListFind(list, 1);
	//SListInsertAfter(pos, 10);
	//SListPrint(list);
	//SListPopFront(&list);
	//SListPrint(list);
	//SListPopFront(&list);
	//SListPrint(list);
	//SListPopFront(&list);
	//SListPrint(list);
	//SListPopFront(&list);
	//SListPrint(list);

}
void menu()
{
	printf("************************************\n");
	printf("    1.头插   2.头删\n");
	printf("    3.尾插   4.尾删\n");
	printf("    5.打印   6.插入\n");
	printf("    7.查找   8.删除指定位置后一个\n");
	printf("    -1.退出\n");
	printf("************************************\n");
	printf(" 请选择>:   \n");

}

void menuText()
{
	SLNode* list = NULL;
	int input = 0;
	SLDateType x1 = 0;
	while (input != -1)
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
				SListPushFront(&list, x1);
				scanf("%d", &x1);
			}
			printf("头插成功\n");
			break;
		case 2:
			SListPopBack(&list);
			printf("头删成功\n");
			break;
		case 3:
			printf("请输入你要尾插入的数，以-1为结束\n");
			scanf("%d", &x1);
			while (x1 != -1)
			{
				SListPushBack(&list, x1);
				scanf("%d", &x1);
			}
			printf("尾插成功\n");
			break;
		case 4:
			SListPopBack(&list);
			printf("尾删成功\n");
			break;
		case 5:
			SListPrint(list);
			break;
		case 6:
			printf("在pos位置后面插入,请输入你在哪个位置后插入\n");
				scanf("%d", &x1);
				SLNode* pos = SListFind(list, x1);
				if (pos != NULL)
				{
					printf("OK,请输入你要插入的数据\n");
					scanf("%d", &x1);
					SListInsertAfter(pos,x1);
					printf("插入成功\n");
				}
				else
				{
					printf("无此数据\n");
				}
			break;
		case 7:
			printf("你要查找哪个数据(pos)>\n");
			scanf("%d", &x1);
			int i = 1;
			pos=SListFind(list, x1);
			if (pos == NULL)
			{
				printf("无此数据\n");
			}
			while (pos)
			{
				printf("第%d个pos节点：%p->%d\n", i++, pos, pos->data);
				pos = SListFind(pos->next, x1);

			}
			break;
		case 8:
			printf("你要删除哪个位置后的数据>\n");
			scanf("%d", &x1);
			pos = SListFind(list, x1);
			if (pos != NULL)
			{
				SListEraseAfter(pos);
				printf("删除成功\n");
			}
			else
			{
				printf("无此数据\n");
			}
			break;
		case -1:
			printf("退出成功\n");
			break;
		default:
			printf("无此选项，请重新输入\n");
			break;
		}
	}
}
int main()
{
	//SListText1();
	//SListText2();
	menuText();
}