#pragma once

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

typedef struct people
{
	char name[MAX_NAME];//����
	char sex[MAX_SEX]; //�Ա�
	int age;    //����
	char tele[MAX_TELE];//�绰����
	char addr[MAX_ADDR];//��ַ
}people;



typedef struct Contact
{
	people data[MAX];
	int size;	//��Ч���ݸ���
}Contact;



//��ʼ��ͨѶ¼
void ContactInit(Contact* pc);

//������ϵ��
void ContactAdd(Contact* pc);

//��ӡ��ϵ����Ϣ
void ContactPrint(Contact* pc);


//ɾ����ϵ�˵���Ϣ
void ContactDel(Contact* pc);

//����ָ����ϵ��
int  ContactFind(Contact* pc, char* FindName);

//�޸�ָ����ϵ��
void ContactRevise(Contact* pc);

//����ͨѶ¼
void ContactDestroy(Contact* pc);

//����������
int cmp_nanme(const void* e1, const void* e2);


