#define _CRT_SECURE_NO_WARNINGS

#include"SList.h"

void SListText1()
{
	SList* list=NULL;
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
	SList* list = NULL;
	SListPushFront(&list, 1);
	SListPushFront(&list, 2);
	SListPushFront(&list, 3);
	SListPushFront(&list, 4);
	SListPushFront(&list, 5);
	SListPrint(list);
	int i = 1;
	SList* pos = SListFind(list, 2);
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

int main()
{
	//SListText1();
	SListText2();
}