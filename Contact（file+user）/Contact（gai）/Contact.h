#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include <conio.h>

#define MAX_NAME 20        //���ֵ������
#define MAX_SEX 10         //�洢�Ա�
#define MAX_TELE 12        //�绰�������
#define MAX_ADDR 30        //��ַ�������
#define MAX_ACC 20         //�˺������
#define MAX_PASS 20		   //����������
#define N 6                //�˺����ע��ĸ���
 
//�û��˺Žṹ��
typedef struct personnel
{
	char userName[MAX_NAME];  //�˺�����
	char Account[MAX_ACC];    //�˺�
	char password[MAX_PASS];   //����
}personnel;

//�˺Ź���ṹ��
typedef struct User
{
	struct personnel val[N];
	int begin;
}user;

//��ϵ�˵���Ϣ�ṹ��
typedef struct people
{
	char name[MAX_NAME];//����
	char sex[MAX_SEX]; //�Ա�
	char age[4];    //����
	char tele[MAX_TELE];//�绰����
	char addr[MAX_ADDR];//��ַ
}people;


//ͨѶ¼
typedef struct Contact
{
	people* data;
	int size;	//��Ч���ݸ���
	int capacity;//����
}Contact;


//ͨѶ����ѡ���ö��
enum contact
{
	Exit,
	Print,
	Add,
	Del,
	Find,
	Revise,
	Save,
	Reviseuser
};

//��¼ϵͳ
int UserLongsonSystem(user* user1);
//ͨѶ¼�˵�
void menu();

//��¼�˵�
void menu1();
//��������
void Print1(int n);



//��ʼ����¼�˺�
void UserInit(user* pu);


//����û��˺��Ƿ�����
int CheckUser(user* pu);

//��¼    ��¼�ɹ����ض�Ӧ�����±꣬���򷵻�-1
int UserLongin(user* pu);

//ע��
void Userreg(user* pu);

//�һ�����
void GetbackPassword(user* user1);

//�˺Ź���Ա��¼
void Administrator(user*user1);

//����Ա����
void Manage(user* user1);

//�޸��˺���Ϣ
void ReviseUser(user* user1,int pos);

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

//����ָ����ϵ��  ���ҵ��˷��ض�Ӧ�±꣬�Ҳ�������-1
int  ContactFind(Contact* pc, char* FindName,int pos);

//�޸�ָ����ϵ��
void ContactRevise(Contact* pc);

//����ͨѶ¼
void ContactDestroy(Contact* pc);

//����ͨѶ¼��Ϣ���ļ�
void ContactSave(Contact* pc);

//�����ļ����ݵ�ͨѶ¼
void ContactLoad(Contact* pc);

//����ڴ��Ƿ�����
void CheckCapacity(Contact* pc);
