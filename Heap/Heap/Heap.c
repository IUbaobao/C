#define _CRT_SECURE_NO_WARNINGS

#include"Heap.h"


void HeapInit(Heap* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void HeapDestroy(Heap* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void Swap(HPDataType* x1, HPDataType* x2)
{
	HPDataType tem = *x1;
	*x1 = *x2;
	*x2 = tem;
}


void AdjustUp(HPDataType* a, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent= (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}


void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	if (php->capacity == php->size)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tem = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newcapacity);
		if(tem==NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		php->a = tem;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a,php->size-1);
}

void AdjustDown(HPDataType* a, int n, int parent)
{
	int midchild = parent * 2 + 1;
	while (midchild < n)
	{	
		// 找出小的那个孩子
		if (midchild +1< n && a[midchild] > a[midchild + 1])
		{
			midchild++;
		}
		if (a[parent] > a[midchild])
		{
			Swap(&a[parent], &a[midchild]);
			parent = midchild;
			midchild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(Heap* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	AdjustDown(php->a, php->size, 0);
}
HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	return php->a[0];
}
int HeapSize(Heap* php)
{
	assert(php);
	return php->size;
}
bool HeapEmpty(Heap* php)
{
	assert(php);
	return php->size == 0;
}

void HeapPrint(Heap* php)
{
	assert(php);
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}