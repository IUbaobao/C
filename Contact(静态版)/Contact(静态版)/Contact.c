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
	printf("%-20s %-10s %-8s %-18s %-30s\n\n", "姓名", "性别", "年龄", "电话号码", "地址");
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
		printf("容量已满\n");
		return;
	}
	printf("请输入姓名\n");
	scanf("%s", pc->data[pc->size].name);
	printf("请输入性别\n");
	scanf("%s", pc->data[pc->size].sex);
	printf("请输入年龄\n");
	scanf("%d", &pc->data[pc->size].age);
	printf("请输入电话号码\n");
	scanf("%s", pc->data[pc->size].tele);
	printf("请输入地址\n");
	scanf("%s", pc->data[pc->size].addr);
	pc->size++;
	printf("添加成功\n");
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
	printf("请输入你要删除人的名字\n");
	char Name[MAX_NAME];
	scanf("%s", Name);
	int pos = ContactFind(pc, Name);
	if (pos == -1)
	{
		printf("不存在此联系人\n");
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
		printf("删除成功\n");
	}
}


void ContactRevise(Contact* pc)
{
	assert(pc);
	printf("请输入你要修改人的名字\n");
	char name[MAX_NAME];
	scanf("%s", name);
	int pos = ContactFind(pc, name);
	if (pos == -1)
	{
		printf("该联系人不存在\n");
		return;
	}
	else
	{
		printf("请输入姓名\n");
		scanf("%s", pc->data[pos].name);
		printf("请输入性别\n");
		scanf("%s", pc->data[pos].sex);
		printf("请输入年龄\n");
		scanf("%d", &pc->data[pos].age);
		printf("请输入电话号码\n");
		scanf("%s", pc->data[pos].tele);
		printf("请输入地址\n");
		scanf("%s", pc->data[pos].addr);
		printf("修改成功\n");
	}
}

int cmp_nanme(const void* e1, const void* e2)
{
	return strcmp((char*)e1, (char*)e2);
}

