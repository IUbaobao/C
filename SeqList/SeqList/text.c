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
	printf("    1.ͷ��   2.ͷɾ\n");
	printf("    3.β��   4.βɾ\n");
	printf("    5.��ӡ   6.����\n");
	printf("    7.����   8.ɾ��ָ��λ��\n");
	printf("    -1.�˳�\n");
	printf("************************************\n");
	printf(" ��ѡ��>:   \n");

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
			printf("��������Ҫͷ�����������-1Ϊ����\n");
			scanf("%d", &x1);
			while (x1 != -1)
			{
				SeqListPushFront(&s1, x1);
				scanf("%d", &x1);
			}
			printf("����ɹ�\n");
			break;
		case 2:
			SeqListPopFront(&s1);
			printf("ͷɾ�ɹ�\n");
			break;
		case 3:
			printf("��������Ҫβ�����������-1Ϊ����\n");
			scanf("%d", &x1);
			while (x1 != -1)
			{
				SeqListPushBack(&s1, x1);
				scanf("%d", &x1);
			}
			printf("����ɹ�\n");
			break;
		case 4:
			SeqListPopBack(&s1);
			printf("βɾ�ɹ�\n");
			break;
		case 5:
			SeqListPrint(&s1);
			printf("��ӡ�ɹ�\n");
			break;
		case 6:
			printf("�����밴�����ĸ�λ�� ���롱������Ϊ˳�����롣���ڵڶ���λ�ã�����3����2 3��\n");
			scanf("%d %d", &x1, &x2);
			SeqListInsert(&s1, x1, x2);
			printf("����ɹ�\n");
			break;
		case 7:
			printf("��������Ҫ���ҵ�����\n");
			scanf("%d", &x1);
			int ret=SeqListFind(&s1, x1);
			if (ret != -1)
			{
				printf("�鵽�ˣ��±�Ϊ%d\n", ret);
			}
			else
				printf("�鲻��\n");
			break;
		case 8:
			printf("��������Ҫɾ�����ݵ�λ��\n");
			scanf("%d", &x1);
			SeqListErase(&s1, x1);
			printf("ɾ���ɹ�\n");
			break;
		case -1:
			printf("�˳��ɹ�\n");
			break;
		default:
			printf("�޴�ѡ�����������\n");
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