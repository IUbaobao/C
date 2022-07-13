#define _CRT_SECURE_NO_WARNINGS

#include"Contact.h"
enum contact
{
	Exit,
	Print,
	Add,
	Del,
	Find,
	SORE
};

void menu()
{
	printf("\t\t\t\t\t====================================\t\t\t\t\t\n");
	printf("\t\t\t\t\t1.查看联系人信息        2.增加联系人\t\t\t\t\t\n");
	printf("\t\t\t\t\t3.删除联系人            4.查找联系人\t\t\t\t\t\n");
	printf("\t\t\t\t\t5.排序                  0.退出      \t\t\t\t\t\n");
	printf("\t\t\t\t\t====================================\t\t\t\t\t\n");


}

int main()
{
	int input = 0;
	Contact pc;
	ContactInit(&pc);
	int pos = 0;
	do
	{

		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case Print:
			ContactPrint(&pc);
			break;
		case Add:
			ContactAdd(&pc);

			break;
		case Del:
			ContactDel(&pc);
			break;
		case Find:
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
		case SORE:
			qsort(&pc, pc.size, sizeof(people), cmp_nanme);
			printf("排序成功\n");
			break;
		case Exit:

			printf("退出成功\n");
			ContactDestroy(&pc);
			break;
		default:
			system("cls");
			printf("无此选项，请重新输入\n");
			break;
		}

	} while (input);
	return 0;
}



