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
	char name[MAX_NAME];//姓名
	char sex[MAX_SEX]; //性别
	int age;    //年龄
	char tele[MAX_TELE];//电话号码
	char addr[MAX_ADDR];//地址
}people;



typedef struct Contact
{
	people* data;
	int size;	//有效数据个数
	int capacity;//容量
}Contact;

//初始化登录账号
void UserInit(user* pu);


//检查用户账号是否满了
int CheckUser(user* pu);

//登录    登录成功返回对应密码坐标，否则返回-1
int UserLongin(user* pu);

//注册
void Userreg(user* pu);

//保存用户账号
void UserSave(user* pu);

//加载用户账号
void UserLoad(user* pu);

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

//保存通讯录信息到文件
void ContactSave(Contact* pc);

//加载文件内容到通讯录
void ContactLoad(Contact* pc);

//检测增容的问题
void CheckCapacity(Contact* pc);
