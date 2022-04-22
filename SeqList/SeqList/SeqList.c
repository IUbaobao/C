#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"


//��ӡ˳���
void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}


//��ʼ��
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}



//�ݻ�˳���
void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}


//�������
void SeqListCheckCapacity(SL* ps)
{
	//����ڴ治������û���ڴ������
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

//β��
void SeqListPushBack(SL* ps, SLDateType x)
{
	//����β��ʱ��Ҫ��������Ƿ����ˣ���Ȼ����Խ�����
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}


//βɾ
void SeqListPopBack(SL* ps)
{
	assert(ps->a != NULL&&ps->size!=0);
	ps->size--;
}


//ͷ��
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


//ͷɾ
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


//�ҵ��˷���xλ�õ��±꣬�Ҳ�������-1
int  SeqListFind(SL* ps,SLDateType x)
{
	assert(ps->a != NULL && ps->size != 0);
	int i = 0;
	//����˳���
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}


//ָ��pos�±�λ�ò���
void SeqListInsert(SL* ps,int pos,SLDateType x)
{
	assert(pos<=ps->size&&pos>=0);
		int end = ps->size-1;
		SeqListCheckCapacity(ps);
		//Ų������
		while(end >= pos)
		{
			ps->a[end + 1] = ps->a[end];
			end--;
		}

	ps->a[pos] = x;
	ps->size++;
}

//ɾ��ָ��posλ�õ����� 
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