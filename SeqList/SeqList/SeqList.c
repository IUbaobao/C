#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"


//打印顺序表
void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}


//初始化
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}



//摧毁顺序表
void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}


//检查容量
void SeqListCheckCapacity(SL* ps)
{
	//如果内存不够或者没有内存就扩容
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDateType* tem = (SLDateType*)realloc(ps->a, newcapacity * sizeof(SLDateType));
		if (tem == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tem;
		ps->capacity = newcapacity;
	}
}

//尾插
void SeqListPushBack(SL* ps, SLDateType x)
{
	//进行尾插时间要检查容量是否满了，不然容易越界访问
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}


//尾删
void SeqListPopBack(SL* ps)
{
	assert(ps->a != NULL&&ps->size!=0);
	ps->size--;
}


//头插
void SeqListPushFront(SL* ps, SLDateType x)
{
	SeqListCheckCapacity(ps);
	if (ps->size == 0)
	{
		ps->a[0] = x;
	}
	int tail = 0;
	for (tail = ps->size-1; tail >= 0; tail--)
	{
		ps->a[tail + 1] = ps->a[tail];
	}
	ps->a[0] = x;
	ps->size++;
}


//头删
void SeqListPopFront(SL* ps)
{
	assert(ps->a != NULL && ps->size != 0);
	int tail = 0;
	
	for (tail = 0; tail < ps->size-1; tail++)
	{
		ps->a[tail]=ps->a[tail + 1];
	}
	ps->size--;
}


//找到了返回x位置的下标，找不到返回-1
int  SeqListFind(SL* ps,SLDateType x)
{
	assert(ps->a != NULL && ps->size != 0);
	int i = 0;
	//遍历顺序表
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}


//指定pos下标位置插入
void SeqListInsert(SL* ps,int pos,SLDateType x)
{
	assert(pos<=ps->size&&pos>=0);
		int end = ps->size-1;
		SeqListCheckCapacity(ps);
		//挪动数据
		while(end >= pos)
		{
			ps->a[end + 1] = ps->a[end];
			end--;
		}

	ps->a[pos] = x;
	ps->size++;
}

//删除指定pos位置的数据 
void SeqListErase(SL* ps, int pos)
{
	assert(pos < ps->size&& pos >= 0);
	int i =0;
	for (i = pos+1; i < ps->size; i++)
	{
		ps->a[i-1] = ps->a[i ];
	}

	ps->size--;
}