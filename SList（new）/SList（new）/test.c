#define _CRT_SECURE_NO_WARNINGS

#include"SList.h"


void SListText1()
{
	SList* phead = NULL;
	//SListPushFront(&phead, 1);
	//SListPushFront(&phead, 2);
	//SListPushFront(&phead, 3);
	//SListPushFront(&phead, 4);
	//SListPrint(phead);

	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPrint(phead);

	//SListPopFront(&phead);
	//SListPrint(phead);

	//SListPopFront(&phead);
	//SListPrint(phead);

	//SListPopFront(&phead);
	//SListPrint(phead);
	//SListPopFront(&phead);
	//SListPrint(phead);
	//SListPopBack(&phead);
	//SListPrint(phead);
	//SListPopBack(&phead);
	//SListPrint(phead);
	//SListPopBack(&phead);
	//SListPrint(phead);
	//SListPopBack(&phead);
	//SListPrint(phead);
	SList* pos = SListFind(phead, 2);
	if (pos != NULL)
	{
		SListInsertAfter(pos, 20);
	}
	SListPrint(phead);
	pos = SListFind(phead, 3);
	SListEraseAfter(pos);
	SListPrint(phead);

	SListDestroy(phead);
}

int main()
{
	SListText1();
	return 0;
}