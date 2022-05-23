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
	printf("\t\t\t\t\t=========��ӭ����ͨѶ¼��¼ϵͳ=========\t\t\t\t\t\n");
	printf("\t\t\t\t\t========================================\t\t\t\t\t\n");
	printf("\t\t\t\t\t*                1.��¼                *\t\t\t\t\t\n");
	printf("\t\t\t\t\t*                2.ע��                *\t\t\t\t\t\n");
	printf("\t\t\t\t\t*                0.�˳�                *\t\t\t\t\t\n");
	printf("\t\t\t\t\t========================================\t\t\t\t\t\n");




}

void menu()
{
	printf("\t\t\t\t==================================================\t\t\t\t\t\n");
	printf("\t\t\t\t*      1.�鿴��ϵ����Ϣ        2.������ϵ��      *\t\t\t\t\t\n");
	printf("\t\t\t\t*      3.ɾ����ϵ��            4.������ϵ��      *\t\t\t\t\t\n");
	printf("\t\t\t\t*      5.�޸�                  6.����            *\t\t\t\t\t\n");
	printf("\t\t\t\t*      0.�˳�                                    *\t\t\t\t\t\n");
	printf("\t\t\t\t===================================================\t\t\t\t\t\n");


}

int main()
{
	system("color 6");//60��ƣ�70��ɫ

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

		printf("��ѡ��>:");

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
			printf("\n\t\t\t����%d���˺���ϵͳ����������ע��%d���˺ţ���������ϵ����Ա����\t\t\t\t\t\n\n", user1.begin,N-user1.begin);
			 p=CheckUser(&user1);
			 if (p != -1)
			 {
				 Userreg(&user1);
			 }

			break;
		case 0:
			UserSave(&user1);
			printf("�˳��ɹ�\n");
			return 0;
		default:
			system("cls");
			printf("�޴�ѡ�����������\n");
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
			printf("\n\n�밴1�˳��˽��棬��0�˳�ϵͳ....................\n");

			scanf("%d", &flag);
			if (flag == 0)
			{
				input = 0;
				ContactSave(&pc);
				UserSave(&user1);
				ContactDestroy(&pc);
				printf("�˳��ɹ�\n");
				break;
			}
		}
		system("cls");
		Print1();
		printf("\t\t\t\t\t    ��ӭ%s����ͨѶ¼����ϵͳ\t\t\t\t\t\n", user1.val[pos1].userName);

		menu();
		Print2();

		printf("��ѡ��>:");
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
			printf("��������Ҫ������ϵ�˵�����\n\n");
			char FindName[MAX_NAME] = { 0 };
			Print2();

			scanf("%s", FindName);
			pos = ContactFind(&pc, FindName);
			if (pos == -1)
			{
				printf("�޴���ϵ��\n");
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
			printf("����ɹ�\n");
			break;
		case Exit:
			system("cls");
			ContactSave(&pc);
			UserLoad(&user1);
			ContactDestroy(&pc);
			printf("�˳��ɹ�\n");
			
			break;
		default:
			system("cls");
			printf("�޴�ѡ�����������\n");
			break;
		}
		Q++;

	} while (input);
	return 0;
}