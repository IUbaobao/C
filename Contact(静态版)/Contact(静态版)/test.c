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
	printf("\t\t\t\t\t1.�鿴��ϵ����Ϣ        2.������ϵ��\t\t\t\t\t\n");
	printf("\t\t\t\t\t3.ɾ����ϵ��            4.������ϵ��\t\t\t\t\t\n");
	printf("\t\t\t\t\t5.����                  0.�˳�      \t\t\t\t\t\n");
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
		printf("��ѡ��>:");
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
			printf("��������Ҫ������ϵ�˵�����\n");
			char FindName[MAX_NAME] = { 0 };
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
		case SORE:
			qsort(&pc, pc.size, sizeof(people), cmp_nanme);
			printf("����ɹ�\n");
			break;
		case Exit:

			printf("�˳��ɹ�\n");
			ContactDestroy(&pc);
			break;
		default:
			system("cls");
			printf("�޴�ѡ�����������\n");
			break;
		}

	} while (input);
	return 0;
}



