#define _CRT_SECURE_NO_WARNINGS

#include"Contact.h"

enum contact
{
	Exit,
	Print,
	Add,
	Del,
	Find,
	Revise,
	Save
};
void Print1()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");

}
void Print2()
{
	printf("\n");
	printf("\n");
	printf("\n");
}
void menu1()
{
	Print1();
	printf("\t\t\t\t\t=========欢迎来到通讯录登录系统=========\t\t\t\t\t\n");
	printf("\t\t\t\t\t========================================\t\t\t\t\t\n");
	printf("\t\t\t\t\t*                1.登录                *\t\t\t\t\t\n");
	printf("\t\t\t\t\t*                2.注册                *\t\t\t\t\t\n");
	printf("\t\t\t\t\t*                0.退出                *\t\t\t\t\t\n");
	printf("\t\t\t\t\t========================================\t\t\t\t\t\n");




}

void menu()
{
	printf("\t\t\t\t==================================================\t\t\t\t\t\n");
	printf("\t\t\t\t*      1.查看联系人信息        2.增加联系人      *\t\t\t\t\t\n");
	printf("\t\t\t\t*      3.删除联系人            4.查找联系人      *\t\t\t\t\t\n");
	printf("\t\t\t\t*      5.修改                  6.保存            *\t\t\t\t\t\n");
	printf("\t\t\t\t*      0.退出                                    *\t\t\t\t\t\n");
	printf("\t\t\t\t===================================================\t\t\t\t\t\n");


}

int main()
{
	system("color 6");//60金黄，70白色

	int input = 0;
	Contact pc = {0};
	int pos1 = 0;
	user user1 = { 0 };
	int p = 0;
	UserInit(&user1);
	ContactInit(&pc);
	ContactLoad(&pc);
	do {
		menu1();
		Print2();

		printf("请选择>:");

		scanf("%d", &input);
		switch (input)
		{
		case 1:
			pos1=UserLongin(&user1);
			if (pos1 == -1)
			{
				continue;
			}
			else
			{
				input = 0;
			}
			break;
		case 2:
			printf("\n\t\t\t已有%d个账号在系统，最多可以再注册%d个账号，满了请联系管理员增加\t\t\t\t\t\n\n", user1.begin,N-user1.begin);
			 p=CheckUser(&user1);
			 if (p != -1)
			 {
				 Userreg(&user1);
			 }

			break;
		case 0:
			UserSave(&user1);
			printf("退出成功\n");
			return 0;
		default:
			system("cls");
			printf("无此选项，请重新输入\n");
			break;
		}

	} while (input);
	int pos = 0;
	int flag = 0;
	int Q = 0;
	Sleep(1200);

	do
	{
		if (Q != 0)
		{
			printf("\n\n请按1退出此界面，按0退出系统....................\n");

			scanf("%d", &flag);
			if (flag == 0)
			{
				input = 0;
				ContactSave(&pc);
				UserSave(&user1);
				ContactDestroy(&pc);
				printf("退出成功\n");
				break;
			}
		}
		system("cls");
		Print1();
		printf("\t\t\t\t\t    欢迎%s来到通讯录管理系统\t\t\t\t\t\n", user1.val[pos1].userName);

		menu();
		Print2();

		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case Print:
			system("cls");
			Print1();
			ContactPrint(&pc);
			break;
		case Add:
			system("cls");
			ContactAdd(&pc);

			break;
		case Del:
			system("cls");
			ContactDel(&pc);
			break;
		case Find:
			system("cls");
			printf("请输入你要查找联系人的姓名\n\n");
			char FindName[MAX_NAME] = { 0 };
			Print2();

			scanf("%s", FindName);
			pos = ContactFind(&pc, FindName);
			if (pos == -1)
			{
				printf("无此联系人\n");
				break;
			}

			printf(" % -20s % -10s % -4d % -12s % -30s\n", pc.data[pos].name,
				pc.data[pos].sex, pc.data[pos].age, pc.data[pos].tele, pc.data[pos].addr);
			
			break;
		case Revise:
			ContactRevise(&pc);
			break;
		case Save:
			system("cls");
			ContactSave(&pc);
			UserSave(&user1);
			printf("保存成功\n");
			break;
		case Exit:
			system("cls");
			ContactSave(&pc);
			UserLoad(&user1);
			ContactDestroy(&pc);
			printf("退出成功\n");
			
			break;
		default:
			system("cls");
			printf("无此选项，请重新输入\n");
			break;
		}
		Q++;

	} while (input);
	return 0;
}