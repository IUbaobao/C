#define _CRT_SECURE_NO_WARNINGS

#include"List.h"

void textList1()
{
	LTNode* list=ListInit();
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPushBack(list, 4);

	ListPrint(list);
	ListPopBack(list);
	ListPrint(list);
	ListPopBack(list);
	ListPrint(list);
	ListPopBack(list);
	ListPrint(list);
	ListPopBack(list);
	ListPrint(list);

}
void textList2()
{
	LTNode* list = ListInit();
	ListPushFront(list, 1);
	ListPushFront(list, 2);
	ListPushFront(list, 3);
	ListPushFront(list, 4);
	ListPrint(list);

	ListPopFront(list);
	ListPrint(list);
	ListPopFront(list);
	ListPrint(list);
	ListPopFront(list);
	ListPrint(list);
	ListPopFront(list);
	ListPrint(list);

}
void textList3()
{
	LTNode* list = ListInit();
	ListPushFront(list, 1);
	ListPushFront(list, 2);
	ListPushFront(list, 3);
	ListPushFront(list, 4);
	ListPrint(list);

	LTNode* pos = ListFind(list, 4);

	ListInsert(pos, 11);
	ListPrint(list);
	 pos = ListFind(list, 1);

	ListErase(pos);
	ListPrint(list);


}
void menu()
{
	printf("*******************************\n");
	printf("       1.尾插   2.尾删         \n");
	printf("       3.头插   4.头删         \n");
	printf("       5.插入   6查找          \n");
	printf("       7.删除   -1.退出        \n");
	printf("       8.打印                  \n");
	printf("*******************************\n");
	printf(" 请选择>:   \n");

}
void Textmenu()
{
	LTNode* list = ListInit();
	int input = 0;
	LTDateType x1 = 0;
	LTNode* pos = NULL;
	while(input != -1)
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入要尾插的数据，以-1为结束\n");
			scanf("%d", &x1);
			while(x1 != -1)
			{
				ListPushBack(list, x1);
				scanf("%d", &x1);
			}
			printf("尾插成功\n");
			break;
		case 2:
			ListPopBack(list);
			printf("尾删成功\n");
			break;
		case 3:
			printf("请输入要头插的数据，以-1为结束\n");
			scanf("%d", &x1);
			while (x1 != -1)
			{
				ListPushFront(list, x1);
				scanf("%d", &x1);
			}
			printf("头插成功\n");
			break;
		case 4:
			ListPopFront(list);
			printf("头删成功\n");
			break;
		case 5:
			printf("请输入你要在哪里个数据前插入>:\n");
			scanf("%d", &x1);
			 pos= ListFind(list, x1);
			 if (pos != NULL)
			 {
				 printf("请输入你要插入的数据>:\n");
				 scanf("%d", &x1);
				 ListInsert(pos, x1);
				 printf("插入成功\n");
			 }
			 else
			 {
				 printf("无此数据\n");
			 }
			break;
		case 6:
			printf("请输入你要查找的数据\n");
			scanf("%d", &x1);
			pos=ListFind(list, x1);
			if (pos != NULL)
			{
				printf("%d的地址为%p\n", x1, pos);
			}
			else
			{
				printf("链表没有此数据\n");
			}
			break;
		case 7:
			printf("请输入你要删除的数据\n");
			scanf("%d", &x1);
			pos = ListFind(list, x1);
			if (pos != NULL)
			{
				ListErase(pos);
				printf("删除成功\n");
			}
			else
			{
				printf("链表中没有此数据\n");
			}
			break;
		case 8:
			printf("链表数据为：");
			ListPrint(list);
			break;
		case -1:
			printf("退出成功\n");
			break;
		default:
			printf("无此选项，请重新输入！\n");
			break;
		}
	}
	//记得最后把销毁链表，还要把list置空
	ListDestroy(list);
	list = NULL;
	
}

int main()
{
	/*textList1();
	textList2();
	textList3();*/

	Textmenu();

}





