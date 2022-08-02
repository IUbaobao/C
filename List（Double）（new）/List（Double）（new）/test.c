#define _CRT_SECURE_NO_WARNINGS

#include"List.h"

void test1()
{
	ListNode* head = ListCreate();

	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPrint(head);

	//ListPushFront(head, 1);
	//ListPushFront(head, 2);
	//ListPushFront(head, 3);
	//ListPushFront(head, 4);
	//ListPrint(head);

	ListPopBack(head);
	ListPrint(head);
	ListPopBack(head);
	ListPrint(head);
	ListPopBack(head);
	ListPrint(head);
	ListPopBack(head);
	ListPrint(head);

	//ListPopFront(head);
	//ListPrint(head);
	//ListPopFront(head);
	//ListPrint(head);
	//ListPopFront(head);
	//ListPrint(head);
	//ListPopFront(head);
	//ListPrint(head);


	ListDestroy(head);
}

int main()
{
	test1();
	return 0;
}