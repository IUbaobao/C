#define _CRT_SECURE_NO_WARNINGS

#include"Heap.h"


int main()
{
	Heap hp;
	HeapInit(&hp);
	int arr[] = { 60,70,65,50,32,100 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		HeapPush(&hp, arr[i]);
	}
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	return 0;
}