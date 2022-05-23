#define _CRT_SECURE_NO_WARNINGS

#include"Contact.h"

void ContactInit(Contact* pc)
{

	pc->data = NULL;
	pc->capacity = pc->size = 0;

	//ContactLoad(pc);
}

void CheckCapacity(Contact* pc)
{
	int newcapacity = pc->capacity == 0 ? 4 : pc->capacity * 2;
	if (pc->capacity == pc->size)
	{
		people* tem = (people*)malloc(sizeof(people) * newcapacity);
		if (tem == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
		pc->data = tem;
		pc->capacity = newcapacity;
	}
}


void ContactAdd(Contact* pc)
{
	assert(pc);
	//������ϵ��ǰ�ȼ������
	CheckCapacity(pc);
	printf("����������\n\n");
	scanf("%s", pc->data[pc->size].name);
	printf("�������Ա�\n\n");
	scanf("%s", pc->data[pc->size].sex);
	printf("����������\n\n");
	scanf("%d", &pc->data[pc->size].age);
	printf("������绰����\n\n");
	scanf("%s", pc->data[pc->size].tele);
	printf("�������ַ\n\n");
	scanf("%s", pc->data[pc->size].addr);


	pc->size++;
	printf("��ӳɹ�\n");
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
	printf("%-20s %-10s %-8s %-18s %-30s\n\n", "����", "�Ա�", "����", "�绰����", "��ַ");

	for (i = 0; i < pc->size; i++)
	{
		printf("%-20s %-10s %-8d %-18s %-30s\n", pc->data[i].name, pc->data[i].sex, pc->data[i].age, pc->data[i].tele, pc->data[i].addr);
	}
	printf("\n\n�ܼ���%d����ϵ��\n", pc->size);
}


int  ContactFind(Contact* pc, char* FindName)
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
	printf("������Ҫɾ������ϵ������\n");
	char DelName[MAX_NAME] = { 0 };
	scanf("%s", DelName);
	int  del = ContactFind(pc, DelName);
	if (del == -1)
	{
		printf("����ϵ�˲�����\n");
		return;
	}
	int i = 0;
	for (i = del; i < pc->size; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->size--;
	printf("ɾ���ɹ�\n");
}



void ContactRevise(Contact* pc)
{
	assert(pc);
	printf("��������Ҫ�޸���ϵ�˵�����\n");
	char RevName[MAX_NAME] = { 0 };
	scanf("%s", RevName);
	int pos = ContactFind(pc, RevName);
	if (pos == -1)
	{
		printf("����ϵ�˲�����\n");
		return;
	}
	printf("�������޸ĵ���Ϣ\n");
	printf("����������\n\n");
	scanf("%s", pc->data[pos].name);
	printf("�������Ա�\n\n");
	scanf("%s", pc->data[pos].sex);
	printf("����������\n\n");
	scanf("%d", &pc->data[pos].age);
	printf("������绰����\n\n");
	scanf("%s", pc->data[pos].tele);
	printf("�������ַ\n\n");
	scanf("%s", pc->data[pos].addr);
	printf("�޸ĳɹ�\n");

}


void ContactSave(Contact* pc)
{
	assert(pc);
	FILE* pf = fopen("people.data", "wb");
	if (pf == NULL)
	{
		printf("ContactSave::���ļ�ʧ��\n");
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
		printf("ContactLoad::���ļ�ʧ��\n");
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
void UserInit(user* pu)
{
	assert(pu);
	pu->begin = 0;

	UserLoad(pu);
}


void Userreg(user* pu)
{
	assert(pu);
	printf("���������ͨѶ¼����,���������Ժ�����ĳƺţ�\n");
	scanf("%s", pu->val[pu->begin].userName);

	printf("����������˺�\n");
	scanf("%s",pu->val[pu->begin].Account);
	printf("�������������\n");
	scanf("%s", pu->val[pu->begin].password);

	pu->begin++;
	system("cls");
	printf("ע��ɹ�\n");
}



int UserLongin(user* pu)
{
	char UName[MAX_NAME] = { 0 };
	char Pass[MAX_PASS] = { 0 };
	int i = 0;
	int flag = 0;
	printf("����������˺�\n");
	scanf("%s", UName);
	for (i = 0; i <= pu->begin; i++)
	{

		if (strcmp(UName, pu->val[i].Account) == 0)
		{
		while (strcmp(Pass,"exit")!=0)
		{
			
				printf("�������������,����exit�˳�\n");
				scanf("%s", Pass);
				if (strcmp(Pass, "exit") == 0)
				{
					flag = 1;
					continue;
				}
				if (strcmp(Pass, pu->val[i].password) == 0)
				{
					system("cls");

					printf("\n\n\n\n��¼�ɹ�,���ڼ���ͨѶ¼................................\n");
					return i;
				}
				else
				{
					printf("�������\n");
				}
		}
		}

	}
	if (flag == 0)
	{
		system("cls");
		printf("�޴��˺�\n");
	}
	return -1;
}

void UserSave(user* pu)
{
	assert(pu);
	FILE* pf = fopen("people1.data", "wb");
	if (pf == NULL)
	{
		printf("UserSave::���ļ�ʧ��\n");
		exit(-1);
	}
	int i = 0;
	for (i = 0; i < pu->begin; i++)
	{
		fwrite(&pu->val[i], sizeof(user1), 1, pf);
	}

	fclose(pf);
	pf = NULL;
}


void UserLoad(user* pu)
{
	FILE* pf = fopen("people1.data", "rb");
		if (pf == NULL)
		{
			printf("UserLoad::ʧ��\n");
			exit(-1);
		}
		int i = 0;
		while (fread(&pu->val[i], sizeof(user1), 1, pf))
		{
			i++;
			pu->begin++;
		}

		fclose(pf);
		pf = NULL;
}


int  CheckUser(user* pu)
{
	assert(pu);
	if (pu->begin >= N)
	{
		printf("�û��˺�����\n");
		return -1;
	}
	return 1;
}
