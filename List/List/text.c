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


int main()
{
	textList1();
	textList2();
	textList3();


}