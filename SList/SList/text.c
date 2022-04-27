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
	//	printf("��%d��pos�ڵ㣺%p->%d\n", i++, pos, pos->data);
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
	printf("    1.ͷ��   2.ͷɾ\n");
	printf("    3.β��   4.βɾ\n");
	printf("    5.��ӡ   6.����\n");
	printf("    7.����   8.ɾ��ָ��λ�ú�һ��\n");
	printf("    -1.�˳�\n");
	printf("************************************\n");
	printf(" ��ѡ��>:   \n");

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
			printf("��������Ҫͷ�����������-1Ϊ����\n");
			scanf("%d", &x1);
			while (x1 != -1)
			{
				SListPushFront(&list, x1);
				scanf("%d", &x1);
			}
			printf("ͷ��ɹ�\n");
			break;
		case 2:
			SListPopBack(&list);
			printf("ͷɾ�ɹ�\n");
			break;
		case 3:
			printf("��������Ҫβ�����������-1Ϊ����\n");
			scanf("%d", &x1);
			while (x1 != -1)
			{
				SListPushBack(&list, x1);
				scanf("%d", &x1);
			}
			printf("β��ɹ�\n");
			break;
		case 4:
			SListPopBack(&list);
			printf("βɾ�ɹ�\n");
			break;
		case 5:
			SListPrint(list);
			break;
		case 6:
			printf("��posλ�ú������,�����������ĸ�λ�ú����\n");
				scanf("%d", &x1);
				SLNode* pos = SListFind(list, x1);
				if (pos != NULL)
				{
					printf("OK,��������Ҫ���������\n");
					scanf("%d", &x1);
					SListInsertAfter(pos,x1);
					printf("����ɹ�\n");
				}
				else
				{
					printf("�޴�����\n");
				}
			break;
		case 7:
			printf("��Ҫ�����ĸ�����(pos)>\n");
			scanf("%d", &x1);
			int i = 1;
			pos=SListFind(list, x1);
			if (pos == NULL)
			{
				printf("�޴�����\n");
			}
			while (pos)
			{
				printf("��%d��pos�ڵ㣺%p->%d\n", i++, pos, pos->data);
				pos = SListFind(pos->next, x1);

			}
			break;
		case 8:
			printf("��Ҫɾ���ĸ�λ�ú������>\n");
			scanf("%d", &x1);
			pos = SListFind(list, x1);
			if (pos != NULL)
			{
				SListEraseAfter(pos);
				printf("ɾ���ɹ�\n");
			}
			else
			{
				printf("�޴�����\n");
			}
			break;
		case -1:
			printf("�˳��ɹ�\n");
			break;
		default:
			printf("�޴�ѡ�����������\n");
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