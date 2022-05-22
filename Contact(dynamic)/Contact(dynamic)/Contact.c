#define _CRT_SECURE_NO_WARNINGS

#include"Contact.h"

void ContactInit(Contact* pc)
{
	pc->data = NULL;
	pc->capacity=pc->size = 0;

	ContactLoad(pc);
}

void CheckCapacity(Contact* pc)
{
	int newcapacity = pc->capacity == 0 ? 4 : pc->capacity * 2;
	if (pc->capacity == pc->size)
	{
		people* tem = (people*)malloc(sizeof(people) * newcapacity);
		if (tem == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
		pc->data = tem;
		pc->capacity = newcapacity;
	}
}


void ContactAdd(Contact* pc)
{
	assert(pc);
	//增加联系人前先检查容量
	CheckCapacity(pc);
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

void ContactDestroy(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
	pc->capacity = pc->size = 0;
	
}


void ContactPrint(Contact* pc)
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		printf("%-20s %-10s %-4d %-12s %-30s\n", pc->data[i].name, pc->data[i].sex, pc->data[i].age, pc->data[i].tele, pc->data[i].addr);
	}
}


int  ContactFind(Contact* pc,char*FindName)
{

	assert(pc);

	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		if (strcmp(FindName, pc->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void ContactDel(Contact* pc)
{
	assert(pc);
	printf("你输入要删除的联系人名字\n");
	char DelName[MAX_NAME] = { 0 };
	scanf("%s", DelName);
	int  del=ContactFind(pc, DelName);
	if (del == -1)
	{
		printf("改联系人不存在\n");
		return;
	}
	int i = 0;
	for (i = del; i < pc->size; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->size--;
	printf("删除成功\n");
}



void ContactRevise(Contact* pc)
{
	assert(pc);
	printf("请输入你要修改联系人的姓名\n");
	char RevName[MAX_NAME] = { 0 };
	scanf("%s", RevName);
	int pos = ContactFind(pc, RevName);
	if (pos == -1)
	{
		printf("该联系人不存在\n");
		return;
	}
	printf("请输入修改的信息\n");
	ContactAdd(pc);
}


void ContactSave(Contact* pc)
{
	assert(pc);
	FILE* pf = fopen("people.data", "wb");
	if (pf == NULL)
	{
		printf("ContactSave::打开文件失败\n");
		exit(-1);
	}
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		fwrite(&pc->data[i], sizeof(people), 1, pf);
	}

	fclose(pf);
	pf = NULL;
}

void ContactLoad(Contact* pc)
{
	assert(pc);
	FILE* pf = fopen("people.data", "rb");
	if (pf == NULL)
	{
		printf("ContactLoad::打开文件失败\n");
		exit(-1);
	}
	CheckCapacity(pc);
	int i = 0;
	while (fread(&pc->data[i], sizeof(people), 1, pf))
	{
		CheckCapacity(pc);
		pc->size++;
		i++;
	}
	
	fclose(pf);
	pf = NULL;
}
