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
	printf("       1.β��   2.βɾ         \n");
	printf("       3.ͷ��   4.ͷɾ         \n");
	printf("       5.����   6����          \n");
	printf("       7.ɾ��   -1.�˳�        \n");
	printf("       8.��ӡ                  \n");
	printf("*******************************\n");
	printf(" ��ѡ��>:   \n");

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
			printf("������Ҫβ������ݣ���-1Ϊ����\n");
			scanf("%d", &x1);
			while(x1 != -1)
			{
				ListPushBack(list, x1);
				scanf("%d", &x1);
			}
			printf("β��ɹ�\n");
			break;
		case 2:
			ListPopBack(list);
			printf("βɾ�ɹ�\n");
			break;
		case 3:
			printf("������Ҫͷ������ݣ���-1Ϊ����\n");
			scanf("%d", &x1);
			while (x1 != -1)
			{
				ListPushFront(list, x1);
				scanf("%d", &x1);
			}
			printf("ͷ��ɹ�\n");
			break;
		case 4:
			ListPopFront(list);
			printf("ͷɾ�ɹ�\n");
			break;
		case 5:
			printf("��������Ҫ�����������ǰ����>:\n");
			scanf("%d", &x1);
			 pos= ListFind(list, x1);
			 if (pos != NULL)
			 {
				 printf("��������Ҫ���������>:\n");
				 scanf("%d", &x1);
				 ListInsert(pos, x1);
				 printf("����ɹ�\n");
			 }
			 else
			 {
				 printf("�޴�����\n");
			 }
			break;
		case 6:
			printf("��������Ҫ���ҵ�����\n");
			scanf("%d", &x1);
			pos=ListFind(list, x1);
			if (pos != NULL)
			{
				printf("%d�ĵ�ַΪ%p\n", x1, pos);
			}
			else
			{
				printf("����û�д�����\n");
			}
			break;
		case 7:
			printf("��������Ҫɾ��������\n");
			scanf("%d", &x1);
			pos = ListFind(list, x1);
			if (pos != NULL)
			{
				ListErase(pos);
				printf("ɾ���ɹ�\n");
			}
			else
			{
				printf("������û�д�����\n");
			}
			break;
		case 8:
			printf("��������Ϊ��");
			ListPrint(list);
			break;
		case -1:
			printf("�˳��ɹ�\n");
			break;
		default:
			printf("�޴�ѡ����������룡\n");
			break;
		}
	}
	//�ǵ���������������Ҫ��list�ÿ�
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





