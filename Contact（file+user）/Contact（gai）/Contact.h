#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include <conio.h>

#define MAX_NAME 20        //名字的最长个数
#define MAX_SEX 10         //存储性别
#define MAX_TELE 12        //电话的最长个数
#define MAX_ADDR 30        //地址的最长个数
#define MAX_ACC 20         //账号最长个数
#define MAX_PASS 20		   //密码的最长个数
#define N 6                //账号最多注册的个数
 
//用户账号结构体
typedef struct personnel
{
	char userName[MAX_NAME];  //账号名称
	char Account[MAX_ACC];    //账号
	char password[MAX_PASS];   //密码
}personnel;

//账号管理结构体
typedef struct User
{
	struct personnel val[N];
	int begin;
}user;

//联系人的信息结构体
typedef struct people
{
	char name[MAX_NAME];//姓名
	char sex[MAX_SEX]; //性别
	char age[4];    //年龄
	char tele[MAX_TELE];//电话号码
	char addr[MAX_ADDR];//地址
}people;


//通讯录
typedef struct Contact
{
	people* data;
	int size;	//有效数据个数
	int capacity;//容量
}Contact;


//通讯功能选择的枚举
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

//登录系统
int UserLongsonSystem(user* user1);
//通讯录菜单
void menu();

//登录菜单
void menu1();
//换行美观
void Print1(int n);



//初始化登录账号
void UserInit(user* pu);


//检查用户账号是否满了
int CheckUser(user* pu);

//登录    登录成功返回对应密码下标，否则返回-1
int UserLongin(user* pu);

//注册
void Userreg(user* pu);

//找回密码
void GetbackPassword(user* user1);

//账号管理员登录
void Administrator(user*user1);

//管理员管理
void Manage(user* user1);

//修改账号信息
void ReviseUser(user* user1,int pos);

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

//查找指定联系人  ，找到了返回对应下标，找不到返回-1
int  ContactFind(Contact* pc, char* FindName,int pos);

//修改指定联系人
void ContactRevise(Contact* pc);

//销毁通讯录
void ContactDestroy(Contact* pc);

//保存通讯录信息到文件
void ContactSave(Contact* pc);

//加载文件内容到通讯录
void ContactLoad(Contact* pc);

//检测内存是否满了
void CheckCapacity(Contact* pc);
