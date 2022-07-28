#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"


void CheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tem = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tem == NULL)
		{
			perror("realloc fail\n");
			exit(-1);
		}
		ps->a = tem;
		ps->capacity = newcapacity;
	}
}


void SeqListInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}


void SeqListDestroy(SL* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}



void SeqListPushFront(SL* ps,SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	int i = ps->size;
	while (i)
	{
		ps->a[i] = ps->a[i - 1];
		i--;
	}

	ps->a[0] = x;
	ps->size++;
}


void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}


void SeqListPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->size--;
}


void SeqListPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	int i = 0;
	while (i < ps->size-1)
	{
		ps->a[i] = ps->a[i + 1];
		i++;
	}
	ps->size--;
}

void SeqListPrint(SL* ps)
{
	assert(ps);
	int i = 0;
	while (i < ps->size)
	{
		printf("%d ", ps->a[i]);
		i++;
	}
	printf("\n");
}


int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i;
	}

	return -1;
}

void SeqListInsert(SL* ps, size_t pos, SLDataType x)
{
	assert(ps);
	assert(pos <= ps->size);
	CheckCapacity(ps);
	int i = ps->size;
	while (i > pos)
	{
		ps->a[i] = ps->a[i-1];
		i--;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SeqListErase(SL* ps, size_t pos)
{
	assert(ps);
	assert(pos < ps->size);
	int i = pos;
	while (i <ps->size-1)
	{
		ps->a[i] = ps->a[i + 1];
		i++;
	}
	ps->size--;
}