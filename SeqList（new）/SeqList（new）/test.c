#define _CRT_SECURE_NO_WARNINGS


#include"SeqList.h"

void SeqListTest1()
{
	SL s;
	SeqListInit(&s);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);
	//SeqListPushFront(&s, 5);
	//SeqListPushFront(&s, 6);
	SeqListPrint(&s);
	//SeqListPushBack(&s, 5);
	//SeqListPushBack(&s, 6);
	//SeqListPushBack(&s, 7);
	//SeqListPrint(&s);

	//SeqListPopBack(&s);
	//SeqListPopBack(&s);
	//SeqListPopBack(&s);
	//SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);

	SeqListPrint(&s);

	SeqListDestroy(&s);

}
void SeqListTest2()
{
	SL s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);

	SeqListInsert(&s, 0, 10);
	SeqListPrint(&s);
	int x = 0; 
		scanf("%d", &x);
	int pos = SeqListFind(&s, x);
	//SeqListInsert(&s, pos, x*10);
	SeqListErase(&s, pos);
	SeqListPrint(&s);
	SeqListDestroy(&s);

}
int main()
{
	SeqListTest2();

	return 0;
}