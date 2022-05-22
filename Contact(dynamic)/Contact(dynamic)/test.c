#define _CRT_SECURE_NO_WARNINGS

#include"Contact.h"
void test1()
{
	Contact pc;
	ContactInit(&pc);
	ContactAdd(&pc);
	ContactAdd(&pc);
	ContactPrint(&pc);
	ContactDel(&pc);
	ContactPrint(&pc);



	ContactDestroy(&pc);
}


enum contact
{
	Exit,
	Print,
	Add,
	Del,
	Find,
	Save
};

void Print1()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
}
void menu()
{
	printf("\t\t\t\t\t====================================\t\t\t\t\t\n");
	printf("\t\t\t\t\t1.查看联系人信息        2.增加联系人\t\t\t\t\t\n");
	printf("\t\t\t\t\t3.删除联系人            4.查找联系人\t\t\t\t\t\n");
	printf("\t\t\t\t\t5.保存                  0.退出      \t\t\t\t\t\n");
	printf("\t\t\t\t\t====================================\t\t\t\t\t\n");


}

int main()
{
	//test1();
	int input = 0;
	Contact pc;
	ContactInit(&pc);
	int pos = 0;
	int flag = 0;
	int Q = 0;
	do
	{
		if (Q != 0)
		{
			printf("请按1继续，按0退出....................\n");
			scanf("%d", &flag);
			if (flag == 0)
			{
				input = 0;
				printf("退出成功\n");
				break;
			}
		}
		menu();
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
			printf("请输入你要查找联系人的姓名\n");
			char FindName[MAX_NAME] = { 0 };
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
		case Save:
			system("cls");
			ContactSave(&pc);
			printf("保存成功\n");
			break;
		case Exit:
			system("cls");
			ContactSave(&pc);
			printf("退出成功\n");
			ContactDestroy(&pc);
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