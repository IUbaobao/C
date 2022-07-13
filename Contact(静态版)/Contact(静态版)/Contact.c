#define _CRT_SECURE_NO_WARNINGS
#include"Contact.h"


void ContactInit(Contact* pc)
{
	assert(pc);
	memset(pc->data, 0,sizeof(people)*MAX);
	pc->size = 0;
}

void ContactDestroy(Contact* pc)
{
	assert(pc);
	pc->size = 0;
}


void ContactPrint(Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s %-10s %-8s %-18s %-30s\n\n", "����", "�Ա�", "����", "�绰����", "��ַ");
	for (i = 0; i < pc->size; i++)
	{
		printf("% -20s % -10s % -4d % -12s % -30s\n", pc->data[i].name,
										pc->data[i].sex,
										pc->data[i].age, 
										pc->data[i].tele,
										pc->data[i].addr);
	}
}


void ContactAdd(Contact* pc)
{
	assert(pc);
	if (pc->size == MAX)
	{
		printf("��������\n");
		return;
	}
	printf("����������\n");
	scanf("%s", pc->data[pc->size].name);
	printf("�������Ա�\n");
	scanf("%s", pc->data[pc->size].sex);
	printf("����������\n");
	scanf("%d", &pc->data[pc->size].age);
	printf("������绰����\n");
	scanf("%s", pc->data[pc->size].tele);
	printf("�������ַ\n");
	scanf("%s", pc->data[pc->size].addr);
	pc->size++;
	printf("��ӳɹ�\n");
}


int  ContactFind(Contact* pc, char* FindName)
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		if (strcmp(pc->data[i].name, FindName) == 0)
			return i;
	}
	return -1;
}

void ContactDel(Contact* pc)
{
	assert(pc);
	printf("��������Ҫɾ���˵�����\n");
	char Name[MAX_NAME];
	scanf("%s", Name);
	int pos = ContactFind(pc, Name);
	if (pos == -1)
	{
		printf("�����ڴ���ϵ��\n");
		return;
	}
	else
	{
		int i = 0;
		for (i = pos; i < pc->size-1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->size--;
		printf("ɾ���ɹ�\n");
	}
}


void ContactRevise(Contact* pc)
{
	assert(pc);
	printf("��������Ҫ�޸��˵�����\n");
	char name[MAX_NAME];
	scanf("%s", name);
	int pos = ContactFind(pc, name);
	if (pos == -1)
	{
		printf("����ϵ�˲�����\n");
		return;
	}
	else
	{
		printf("����������\n");
		scanf("%s", pc->data[pos].name);
		printf("�������Ա�\n");
		scanf("%s", pc->data[pos].sex);
		printf("����������\n");
		scanf("%d", &pc->data[pos].age);
		printf("������绰����\n");
		scanf("%s", pc->data[pos].tele);
		printf("�������ַ\n");
		scanf("%s", pc->data[pos].addr);
		printf("�޸ĳɹ�\n");
	}
}

int cmp_nanme(const void* e1, const void* e2)
{
	return strcmp((char*)e1, (char*)e2);
}

