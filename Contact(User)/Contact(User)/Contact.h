#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX_ACC 20
#define MAX_PASS 20
#define N 6
typedef struct user
{
	char userName[MAX_NAME];
	char Account[MAX_ACC];
	char password[MAX_PASS];
}user1;
 typedef struct User
 {
	 struct user val[N];
	 int begin;
 }user;


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
	people* data;
	int size;	//��Ч���ݸ���
	int capacity;//����
}Contact;

//��ʼ����¼�˺�
void UserInit(user* pu);


//����û��˺��Ƿ�����
int CheckUser(user* pu);

//��¼    ��¼�ɹ����ض�Ӧ�������꣬���򷵻�-1
int UserLongin(user* pu);

//ע��
void Userreg(user* pu);

//�����û��˺�
void UserSave(user* pu);

//�����û��˺�
void UserLoad(user* pu);

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

//����ͨѶ¼��Ϣ���ļ�
void ContactSave(Contact* pc);

//�����ļ����ݵ�ͨѶ¼
void ContactLoad(Contact* pc);

//������ݵ�����
void CheckCapacity(Contact* pc);
