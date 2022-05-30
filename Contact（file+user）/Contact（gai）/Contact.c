#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE

#include"Contact.h"

//换行美观
void Print1(int n) 
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("\n");
	}
}

//菜单
void menu()
{
	printf("\t\t\t\t==================================================\t\t\t\t\t\n");
	printf("\t\t\t\t*      1.查看联系人信息        2.增加联系人      *\t\t\t\t\t\n");
	printf("\t\t\t\t*      3.删除联系人            4.查找联系人      *\t\t\t\t\t\n");
	printf("\t\t\t\t*      5.修改联系人            6.保存            *\t\t\t\t\t\n");
	printf("\t\t\t\t*      7.账号中心              0.退出            *\t\t\t\t\t\n");
	printf("\t\t\t\t===================================================\t\t\t\t\t\n");

}



//登录菜单
void menu1()
{
	Print1(7);
	printf("\t\t\t\t\t=========欢迎来到通讯录登录系统=========\t\t\t\t\t\n");
	printf("\t\t\t\t\t========================================\t\t\t\t\t\n");
	printf("\t\t\t\t\t*                1.登录                *\t\t\t\t\t\n");
	printf("\t\t\t\t\t*                2.注册                *\t\t\t\t\t\n");
	printf("\t\t\t\t\t*                3.找回密码            *\t\t\t\t\t\n");
	printf("\t\t\t\t\t*                4.管理账号            *\t\t\t\t\t\n");
	printf("\t\t\t\t\t*                0.退出                *\t\t\t\t\t\n");
	printf("\t\t\t\t\t========================================\t\t\t\t\t\n");
}

//初始化通讯录
void ContactInit(Contact* pc)
{
	
	pc->data = NULL;
	pc->capacity = pc->size = 0;
	
	ContactLoad(pc);//加载通讯录信息
}


//检测内存是否满了
void CheckCapacity(Contact* pc)
{
	//如果通讯录容量为空，就先赋值4个空间，满了就扩容两倍
	if (pc->capacity == pc->size)
	{
		int newcapacity = pc->capacity == 0 ? 4 : pc->capacity * 2;
		people* tem = (people*)realloc(pc->data,sizeof(people) * newcapacity);
		if (tem == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
		pc->data = tem;
		pc->capacity = newcapacity;
	}
}

//增加联系人
void ContactAdd(Contact* pc)
{
	//断言，判断pc是否为NULL
	assert(pc);  
	//增加联系人前先检查容量
	CheckCapacity(pc);
	printf("\n\t\t\t\t\t请输入姓名:");
	scanf("%s", pc->data[pc->size].name);

	printf("\n\t\t\t\t\t请输入性别:");
	scanf("%s", pc->data[pc->size].sex);

	printf("\n\t\t\t\t\t请输入年龄:");
	scanf("%s", pc->data[pc->size].age);

	printf("\n\t\t\t\t\t请输入电话号码:");
	scanf("%s", pc->data[pc->size].tele);

	printf("\n\t\t\t\t\t请输入地址:");
	scanf("%s", pc->data[pc->size].addr);


	pc->size++;
	printf("\t\t\t\t\t添加成功\n");
}


//销毁通讯录
void ContactDestroy(Contact* pc)
{
	//断言，判断pc是否为NULL
	assert(pc);
	free(pc->data);
	pc->data = NULL;
	pc->capacity = pc->size = 0;

}

//打印联系人信息
void ContactPrint(Contact* pc)
{
	//断言，判断pc是否为NULL
	assert(pc);
	int i = 0;
	printf("%-20s %-10s %-8s %-18s %-30s\n\n", "姓名", "性别", "年龄", "电话号码", "地址");

	for (i = 0; i < pc->size; i++)
	{
		printf("%-20s %-10s %-8s %-18s %-30s\n", pc->data[i].name, pc->data[i].sex, pc->data[i].age, pc->data[i].tele, pc->data[i].addr);
	}
	printf("\n\n总计有%d个联系人\n", pc->size);
}

//查找指定联系人  ，找到了返回对应下标，找不到返回-1
int  ContactFind(Contact* pc, char* FindObject,int pos)
{
	//断言，判断pc是否为NULL
	assert(pc);
	int i = 0;
	for (i = pos; i < pc->size; i++)//搜索所有满足条件的元素进行返回
	{
		//对所有联系人的名字，性别，电话，地址，年龄进行一一比较
		if (strcmp(FindObject, pc->data[i].name) == 0 || strcmp(FindObject,pc->data[i].sex) == 0 || strcmp(FindObject, pc->data[i].tele) == 0
			|| strcmp(FindObject, pc->data[i].age) == 0 || strcmp(FindObject, pc->data[i].addr) == 0)
		{
			return i;
		}
	}
	return -1;
}

//删除联系人的信息
void ContactDel(Contact* pc)
{
	assert(pc);
	printf("\n\t\t\t\t\t你输入要删除的联系人名字:");
	char DelName[MAX_NAME] = { 0 };
	scanf("%s", DelName);
	int  del = ContactFind(pc, DelName,0);   //对用户要删除的名字进行搜索，有该联系人就进行删除
	if (del == -1)
	{
		printf("\n\t\t\t\t\t该联系人不存在\n");
		return;
	}
	int i = 0;
	for (i = del; i < pc->size; i++)  //删除
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->size--;
	printf("\n\t\t\t\t\t删除成功\n");
}



//修改指定联系人
void ContactRevise(Contact* pc)
{
	assert(pc);
	int input = 0;
	printf("\n\n\t\t\t\t\t请输入你要修改联系人的名字:");
	char RevName[MAX_NAME] = { 0 };
	scanf("%s", RevName);
	int pos = ContactFind(pc, RevName,0);    //对用户要修改的名字进行搜索，有该联系人就进行修改
	if (pos == -1)
	{
		printf("\n\t\t\t\t\t该联系人不存在!");
		return;
	}
	system("cls");
	//修改前先打印该联系人信息
	printf("\n\n%-20s %-10s %-8s %-18s %-30s\n", "姓名", "性别", "年龄", "电话号码", "地址");
	printf("\n%-20s %-10s % -8s % -18s %-30s\n", pc->data[pos].name,
		pc->data[pos].sex, pc->data[pos].age, pc->data[pos].tele, pc->data[pos].addr);

	//让用户选择修改的对象
	do
	{
		printf("\n\n\t\t请选择要修改的信息!\n");
		printf("\n\t\t1.姓名   2.性别   3.年龄   4.电话号码   5.地址   6.全部重新修改   0.退出\n");
		printf("\n\t\t请选择:>");
		scanf("%d", &input);

		switch(input)
		{
			case 1:
				printf("\n\t\t请输入姓名:");
				scanf("%s", pc->data[pos].name);
				printf("\n\t\t修改成功\n");
				printf("\n\t\t是否进行修改,按\"1\"继续，按\"0\"退出\n");
				scanf("%d", &input);
				break;
			case 2:
				printf("\n\t\t请输入性别:");
				scanf("%s", pc->data[pos].sex);
				printf("\n\t\t修改成功\n");
				printf("\n\t\t是否进行修改,按\"1\"继续，按\"0\"退出\n");
				scanf("%d", &input);

				break;
			case 3:
				printf("\n\t\t请输入年龄:");
				scanf("%s", pc->data[pos].age);
				printf("\n\t\t修改成功\n");
				printf("\n\t\t是否进行修改,按\"1\"继续，按\"0\"退出\n");
				scanf("%d", &input);
				break;
			case 4:
				printf("\n\t\t请输入电话号码:");
				scanf("%s", pc->data[pos].tele);
				printf("\n\t\t修改成功\n");
				printf("\n\t\t是否进行修改,按\"1\"继续，按\"0\"退出\n");
				scanf("%d", &input);
				break;
			case 5:
				printf("\n\t\t请输入地址:");
				scanf("%s", pc->data[pos].addr);
				printf("\n\t\t修改成功\n");
				printf("\n\t\t是否进行修改,按\"1\"继续，按\"0\"退出\n");
				scanf("%d", &input);
				break;
			case 6:
				printf("\n\t\t请输入姓名:");
				scanf("%s", pc->data[pos].name);

				printf("\n\t\t请输入性别:");
				scanf("%s", pc->data[pos].sex);

				printf("\n\t\t请输入年龄:");
				scanf("%s", pc->data[pos].age);

				printf("\n\t\t请输入电话号码:");
				scanf("%s", pc->data[pos].tele);

				printf("\n\t\t请输入地址:");
				scanf("%s", pc->data[pos].addr);
				printf("\n\t\t修改成功\n");
				input = 0;
				break;
			case 0:
				printf("退出成功\n");
				break;
			default:
				printf("\n\t\t\t\t\t无此选项，请重新输入\n");
				break;
		}

	} while (input);

}

//保存通讯录信息到文件
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
	for (i = 0; i < pc->size; i++)  //保存通讯录信息到文件
	{
		fwrite(&pc->data[i], sizeof(people), 1, pf);
	}

	fclose(pf);
	pf = NULL;
}

//加载文件内容到通讯录
void ContactLoad(Contact* pc)
{
	//读文件信息
	FILE* pf = fopen("people.data", "rb");
	if (pf == NULL)  //如果pf==NULL，则文件没有，进去此地方 先预打开一个文件就达到了 自动创建一个文件的目标
	{
		pf = NULL;
		pf = fopen("people.data", "wb");//创建文件
		if (pf == NULL)
		{
			printf("ContactLoad::打开文件失败\n");
			exit(-1);
		}
		fclose(pf);
		pf = NULL;
		pf = fopen("people.data", "rb");//再重新打开文件
		if (pf == NULL)
		{
			printf("ContactLoad::失败\n");
			exit(-1);
		}

	}
	people tmp = { 0 };  //用来临时接收文件内的信息
	while (fread(&tmp, sizeof(people), 1, pf))  //从文件加载通讯录信息
	{
		CheckCapacity(pc);
		pc->data[pc->size] = tmp;
		pc->size++;
		
	}

	fclose(pf);  //关闭文件
	pf = NULL;
}

//初始化登录账号
void UserInit(user* pu)
{
	assert(pu);
	pu->begin = 0;

	UserLoad(pu);  //加载账号信息到数组里
}

//注册
void Userreg(user* pu)
{
	assert(pu);
	Print1(7);

	printf("\n\t\t\t\t\t\t\t\tPS:此界面任意时刻输入\"exit\"即可退出此界面\n");
	printf("\n\t\t\t\t\t请开始注册账号\n");
	printf("\n\t\t\t\t\t账号:");
	scanf("%s", pu->val[pu->begin].Account);  //接收用户输入的账号

	if (strcmp(pu->val[pu->begin].Account, "exit") == 0)   //接收用户的退出条件
	{
		system("cls");
		return;
	}
	printf("\n\t\t\t\t\t密码:");
	scanf("%s", pu->val[pu->begin].password);   //接收密码
	if (strcmp(pu->val[pu->begin].password, "exit") == 0)   //接收用户的退出条件
	{
		system("cls");

		return;
	}

	printf("\n\t\t请给你的账号起个漂亮的名称,它将是你以后进来的名字！同时也是你找回密码的根据！！\n");
	printf("\n\t\t\t\t\t");
	scanf("%s", pu->val[pu->begin].userName);
	if (strcmp(pu->val[pu->begin].userName, "exit") == 0)//接收用户的退出条件
	{
		system("cls");

		return;
	}


	pu->begin++;
	system("cls");
	printf("\t\t\t\t\t注册成功\n");
}


//密码输入处理，对屏幕回显‘*’
void Getpassword(char* pass, int sz)
{
	assert(pass);
	char c = 0;
	int i = 0;
	while ((c = getch()) != 13)
	{

		pass[i] = c;
		i++;
		putchar('*');  //屏幕回显‘*’
		if (i > sz - 2)
		{
			printf("\n密码过长\n");
			break;
		}
	}
	pass[i] = '\0';
}


//登录    登录成功返回对应密码下标，否则返回-1
int UserLongin(user* pu)
{
	char UName[MAX_NAME] = { 0 };
	char Pass[MAX_PASS] = { 0 };
	int i = 0;
	int flag = 0;
	system("cls");
	printf("\n\n\t\t\t\t\t=============================\n");
	printf("\t\t\t\t\t*          登录界面         *\n");
	printf("\t\t\t\t\t=============================\n");



	printf("\n\t\t\t\t\t账号:");
	scanf("%s", UName);
	for (i = 0; i <= pu->begin; i++)  //对用户输入的账号进行和文件中获取的账号逐一对比
	{

		if (strcmp(UName, pu->val[i].Account) == 0)  //有相同的账号则让用户输入密码
		{
			while (strcmp(Pass, "exit") != 0)
			{

				printf("\n\t\t\t\t\t密码:");
				
				Getpassword(Pass, MAX_PASS); //接收密码，同时对屏幕回显‘*’

				if (strcmp(Pass, pu->val[i].password) == 0) //密码输入正确就返回改账号的数组下标，然后进入通讯
				{
					system("cls");

					printf("\n\n\n\n登录成功,正在加载通讯录................................\n");
					return i;
				}
				else//输入错误可以提醒用户是否进行输入
				{
					printf("\t\t\t\t\t\n密码错误,可以输入exit退出,继续输入按1\n");
					scanf("%s", Pass);
					if (strcmp(Pass, "exit") == 0)
					{
						flag = 1;
						break;
					}
					else
						continue;
					
				}
			}
		}

	}
	if (flag == 0) //如果账号对不上就提醒用户
	{
		system("cls");
		printf("\t\t\t\t\t无此账号\n");
		Sleep(300);
	}
	return -1;
}



//保存用户账号
void UserSave(user* pu)
{
	assert(pu);
	FILE* pf = fopen("user.data", "wb");
	if (pf == NULL)
	{
		printf("UserSave::打开文件失败\n");
		exit(-1);
	}
	int i = 0;
	for (i = 0; i < pu->begin; i++)		//保存账号信息到文件
	{
		fwrite(&pu->val[i], sizeof(personnel), 1, pf); //把信息写进文件里
	}

	fclose(pf);
	pf = NULL;
}

//加载用户账号
void UserLoad(user* pu)
{
	//读文件信息
	FILE* pf = fopen("user.data", "rb");
	if (pf == NULL)  //如果pf==NULL，则文件没有，进去此地方 先预打开一个文件就达到了 自动创建一个文件的目标
	{
		pf = NULL;
	    pf = fopen("user.data", "wb");//创建文件
		if (pf == NULL)
		{
			printf("UserSave::打开文件失败\n");
			exit(-1);
		}
		fclose(pf);   //再关闭
		pf = NULL;
		pf = fopen("user.data", "rb");//再重新打开文件
		 if (pf == NULL)
		 {
			 printf("UserLoad::失败\n");
			 exit(-1);
		}

	}
	//读文件信息
	int i = 0;
	while (fread(&pu->val[i], sizeof(personnel), 1, pf))
	{
		i++;
		pu->begin++;
	}

	fclose(pf);
	pf = NULL;
}

//检查用户账号是否满了
int  CheckUser(user* pu)
{

	assert(pu);
	if (pu->begin >= N)  
	{
		printf("\t\t\t\t\t用户账号已满\n");
		return -1;
	}
	return 1;
}


//修改账号信息
void ReviseUser(user* user1,int pos)
{
	assert(user1);
	system("cls");
	Print1(7);

	printf("\n\t\t\t\t1.修改名称   2.修改账号   3.修改密码   4.查看账号信息   5.退出此界面\n");
	printf("\n\t\t\t\t请选择:");
		int input = 0;
		scanf("%d", &input);  //接收用户选择修改对象的功能
		switch (input)
		{
		case 1:
			printf("\n\t\t\t\t原名称:%s", user1->val[pos].userName);
			printf("\n\t\t\t\t请修改:");
			scanf("%s", user1->val[pos].userName);
			break;
		case 2:
			printf("\n\t\t\t\t原账号:%s", user1->val[pos].Account);
			printf("\n\t\t\t\t请修改:");
			scanf("%s", user1->val[pos].Account);
			break;
		case 3:
			printf("\n\t\t\t\t原账号:%s", user1->val[pos].password);
			printf("\n\t\t\t\t请修改:");
			scanf("%s", user1->val[pos].password);
			break;
		case 4:
			printf("\n\t\t\t\t名称:%s", user1->val[pos].userName);
			printf("\n\t\t\t\t账号:%s", user1->val[pos].Account);
			printf("\n\t\t\t\t密码:%s", user1->val[pos].password);

		case 5:
			break;
		default:
			printf("\n\t\t\t\t无此选项\n");
			break;
		}
}

//管理员管理
void Manage(user* user1)
{
	assert(user1);
	int input = 0;
	int i = 0;
	int n = 0;
	do
	{
		printf("\n\t\t\t\t1.查看所有账号   2.修改账号信息   3.删除账号  0.退出\n");
		printf("\n\t\t\t\t\t请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1: //查看所有账号
			
			for (i = 0; i < user1->begin; i++)
			{
				printf("\n\t\t\t\t%d.名称:%s",i,user1->val[i].userName);
				printf("\n\t\t\t\t  账号:%s", user1->val[i].Account);
				printf("\n\t\t\t\t  密码:%s\n\n", user1->val[i].password);
			}
			break;
		case 2:      //修改账号信息
			system("cls");
			for (i = 0; i < user1->begin; i++)
			{
				printf("\n\t\t\t\t%d.名称:%s", i, user1->val[i].userName);
				printf("\n\t\t\t\t  账号:%s", user1->val[i].Account);
				printf("\n\t\t\t\t  密码:%s\n\n", user1->val[i].password);
			}
			printf("\n\t\t\t\t请选择要修改的序号:>");
			scanf("%d", &n);
			if(n>=0&& n<user1->begin)
			{
				ReviseUser(user1, n); //修改账号信息函数
				UserSave(user1);    //修改完就保存同步到文件
			}
			else
			{
				printf("\n无效选择\n");
			}
			
			break;
		case 3:  //删除账号
			system("cls");
			for (i = 0; i < user1->begin; i++)
			{
				printf("\n\t\t\t\t%d.名称:%s", i, user1->val[i].userName);
				printf("\n\t\t\t\t  账号:%s", user1->val[i].Account);
				printf("\n\t\t\t\t  密码:%s\n\n", user1->val[i].password);
			}
			printf("\n\t\t\t\t请选择要删除的序号:>");
			scanf("%d", &n);
			if (n >= 0 && n < user1->begin)  
			{
				for (i = 0; i < user1->begin; i++)
				{
					if (n+1 == user1->begin) //如果只有一个，或者删除最后一个直接对数组总数减一即可
					{
						break;
					}
					else  //覆盖删除
					{
						strcpy(user1->val[i].userName, user1->val[i + 1].userName);
						strcpy(user1->val[i].Account, user1->val[i + 1].Account);
						strcpy(user1->val[i].password, user1->val[i + 1].Account);

					}		
				}
				user1->begin--;
				UserSave(user1); //修改完就保存同步到文件
			}
			else
			{
				printf("\n无效选择\n");
			}
			
			break;

			break;
		case 0:  //退出
				break;
		default:
			printf("\n无此选项，请重新选择\n");
			break;

		}
	} while (input);
}



//账号管理员登录
void Administrator(user* user1)
{
	assert(user1);
	char account[MAX_ACC] = {0};
	char password[MAX_PASS] = {0};
	system("cls");
	printf("\n\n\t\t\t\t\t管理员登录界面\n");
	
		printf("\n\t\t\t\t\t账号:");
		scanf("%s", account);
		if (strcmp(account, "admin") == 0)  //管理员账号是唯一的，是程序内定的
		{
			while (strcmp(password,"exit")!=0)
			{
				printf("\n\t\t\t\t\t密码:");
				Getpassword(password, MAX_PASS); 
				if (strcmp(password, "123") == 0)  //密码也是唯一的
				{
					 Manage(user1); //管理员管理界面
					
					break;
				}
				else
				{
					printf("\n\t\t\t\t\t密码错误，忘记请联系开发人员\n");
				}
			}
		}
		else
		{
			printf("\n\t\t\t\t\t账号错误,忘记请联系开发人员\n");
		}
}

////找回密码           
void  GetbackPassword(user* user1) 
{
	assert(user1);
	char account[MAX_ACC] = {0};
	//system("cls");
	printf("\n\t\t\t\t\t输入你的账号:");
	scanf("%s", account);
	int input = 1;
	int i = 0;
	for (i = 0; i < user1->begin; i++)  //查找对应的账号
	{
		if (strcmp(account, user1->val[i].Account) == 0)
		{
			char UserName[MAX_NAME] = { 0 };
			input = 1; //接收退出条件
			while (input)
			{
				//system("cls");
				printf("\n\t\t\t\t\t请输入你注册时的名称:");   //注册时的名称作为找回密码的准则
				scanf("%s", UserName);
				if (strcmp(UserName, user1->val[i].userName) == 0)
				{
					system("cls");
					Print1(7);
					printf("\n\t\t\t\t\t账号:");
					printf("%s", user1->val[i].Account);
					printf("\n\t\t\t\t\t密码为:");
					printf("%s", user1->val[i].password);
					printf("\t\t\tPS:按0退出此界面\n");
					printf("\n\t\t\t\t\t");
					scanf("%d", &input);
					system("cls");
					break;
				}
				else
				{
					printf("\n\t\t\t\t\t跟你刚注册时的名称不符\n");
					Print1(7);
					printf("\t\t\tPS:按1继续，按0退出此界面\n");
					scanf("%d", &input);
					
				}
			}
		}
		if (input == 0)
		{
			system("cls");
			return;
		}
	}
		system("cls");
		printf("\n\t\t\t\t\t无此账号\n");
		Sleep(400); //让程序停400ms
}



//登录系统
int UserLongsonSystem(user* user1)
{
	int p = 0;
	int input = 0;
	int pos1 = 0;
	do {
		system("cls");
		menu1();
		Print1(3);

		printf("\t\t\t\t\t请选择>:");

		scanf("%d", &input);  //接收用户选择的功能
		switch (input)
		{
		case 1:  //登录
			pos1 = UserLongin(user1);
			if (pos1 == -1)
			{
				continue;
			}
			else
			{
				input = 0;
			}
			break;
		case 2:  //注册
			system("cls");
			printf("\n\t\t\t已有%d个账号在系统，最多可以再注册%d个账号，满了请联系管理员增加\t\t\t\t\t\n\n", user1->begin, N - user1->begin);
			p = CheckUser(user1);

			if (p != -1)//账号未满进入注册
			{
				Userreg(user1);
				UserSave(user1);
			}

			break;

		case 3:  //找回密码
			GetbackPassword(user1);
			
			break;
		case 4:  //管理员登录
			Administrator(user1);
			break;
		case 0:  //退出程序
			UserSave(user1);
			printf("\t\t\t\t\t退出成功\n");
			return -1;
		default:  //选择错误提醒
			system("cls");
			printf("\t\t\t\t\t无此选项，请重新输入\n");
			break;
		}

	} while (input);
	return pos1;
}


