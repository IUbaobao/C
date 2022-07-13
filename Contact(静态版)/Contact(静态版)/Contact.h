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
	char name[MAX_NAME];//姓名
	char sex[MAX_SEX]; //性别
	int age;    //年龄
	char tele[MAX_TELE];//电话号码
	char addr[MAX_ADDR];//地址
}people;



typedef struct Contact
{
	people data[MAX];
	int size;	//有效数据个数
}Contact;



//初始化通讯录
void ContactInit(Contact* pc);

//增加联系人
void ContactAdd(Contact* pc);

//打印联系人信息
void ContactPrint(Contact* pc);


//删除联系人的信息
void ContactDel(Contact* pc);

//查找指定联系人
int  ContactFind(Contact* pc, char* FindName);

//修改指定联系人
void ContactRevise(Contact* pc);

//销毁通讯录
void ContactDestroy(Contact* pc);

//以名字排序
int cmp_nanme(const void* e1, const void* e2);


