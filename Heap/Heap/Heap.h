#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;


void HeapInit(Heap* php);
void HeapDestroy(Heap* php);
void HeapPrint(Heap* php);
void HeapPush(Heap* php, HPDataType x);
void HeapPop(Heap* php);
HPDataType HeapTop(Heap* php);
int HeapSize(Heap* php);
bool HeapEmpty(Heap* php);
