	/* һЩ������ͷ�ļ� */ 
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

      /*һЩ������������������*/ 
       
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
	Exit,//�˳�
	Print,//��ӡ��ϵ��
	Add,//������ϵ��
	Del,//ɾ����ϵ��
	Find,//������ϵ��
	Revise,//�޸���ϵ��
	Save,//������Ϣ���ļ�
	Reviseuser//�˺�����

};

int UserLongsonSystem(user* user1);//��¼ϵͳ
void menu();//ͨѶ¼�˵�
void menu1();//��¼�˵�
void Print1(int n);//��������
void UserInit(user* pu);//��ʼ����¼�˺�
int CheckUser(user* pu);//����û��˺��Ƿ�����
int UserLongin(user* pu);//��¼    ��¼�ɹ����ض�Ӧ�����±꣬���򷵻�-1
void Userreg(user* pu);//ע��
void GetbackPassword(user* user1);//�һ�����
void Administrator(user*user1);//�˺Ź���Ա��¼
void Manage(user* user1);//����Ա�����˺� 
void ReviseUser(user* user1,int pos);//�޸��˺���Ϣ
void UserSave(user* pu);//�����û��˺ŵ��ļ� 
void UserLoad(user* pu);//�����û��˺�
void ContactInit(Contact* pc);//��ʼ��ͨѶ¼
void ContactAdd(Contact* pc);//������ϵ��
void ContactPrint(Contact* pc);//��ӡ��ϵ����Ϣ
void ContactDel(Contact* pc);//ɾ����ϵ�˵���Ϣ
int  ContactFind(Contact* pc, char* FindName,int pos);//����ָ����ϵ�ˡ��ҵ��˷��ض�Ӧ�±ꡢ�Ҳ�������-1
void ContactRevise(Contact* pc);//�޸�ָ����ϵ��
void ContactDestroy(Contact* pc);//����ͨѶ¼
void ContactSave(Contact* pc);//����ͨѶ¼��Ϣ���ļ�
void ContactLoad(Contact* pc);//�����ļ����ݵ�ͨѶ¼
void CheckCapacity(Contact* pc);//����ڴ��Ƿ�����
int cmp_name(const void* e1, const void* e2);//����������ͨѶ¼

/*----------------------------------------------------------------------------------------* / 
   				 /*ͨѶ¼������߼�ʵ�� */ 
int main()
{
	system("color 6");//��������ɫ    60��ƣ�70��ɫ
	system("mode con cols=125 lines=38");//�趨����̨���ڴ�С 

	Contact pc = { 0 };
	
	user user1 = { 0 };
	int pos1 = 0;  //�����û���¼�󷵻�����Ķ�Ӧ�±�
	UserInit(&user1);//��ʼ���������û��˺�
	ContactInit(&pc);//��ʼ��ͨѶ¼
	
	
	pos1=UserLongsonSystem(&user1);//��¼ϵͳ ,��¼�ɹ��ͷ����˺������Ӧ���±꣬�û�ֱ���˳��ͷ���-1

	if (pos1 == -1) //��ֹ��������
	{
		return 0;
	}
	
	Sleep(300);//�ó���ͣ500ms
	

	 //ͨѶ¼����ϵͳ�߼�ʵ��
	 int input = 0;     //�����û�ѡ��Ĺ���
	 int pos = 0;		//���ղ�����ϵ�˵��±�
	 int flag = 0;		//���ڿ����˳��Ŀ���
	 int Q = 0;			//ͳ��ѡ���ܵĴ���
	 char FindObject[MAX_NAME] = { 0 };//�����û�������ϵ�˵���Ϣ
	 int pos2 = 0;   //���ڲ��Ҷ����ϵ�˵��м�ֵ
	 int n = 0; //���ղ�����ϵ��ʱ���˳�����
	 do
	 {
		 if (Q != 0)		//������Ѿ�ѡ����ĳһ����֮���ѡ����������û���ʱ�˳�������ת����ʼ����
		 {
			 printf("\n\n�밴1�˳��˽��棬��0�˳�ϵͳ....................\n");

			 scanf("%d", &flag);
			 if (flag == 0)
			 {
				 input = 0;
				 qsort(pc.data, pc.size, sizeof(pc.data[0]), cmp_name);//����������ͨѶ¼
				 ContactSave(&pc);		//�û�ѡ���˳������Ȱ�ͨѶ¼����Ϣ�������ļ���
				 UserSave(&user1);
				 ContactDestroy(&pc);
				 printf("\n�˳��ɹ�\n");
				 break;
			 }
		 }
		 system("cls");
		 Print1(7);
		 printf("\t\t\t\t\t    ��ӭ%s����ͨѶ¼����ϵͳ\t\t\t\t\t\n", user1.val[pos1].userName);

		 menu();
		 Print1(3);

		 printf("\n\t\t\t\t\t��ѡ��>:");
		 scanf("%d", &input);
		 switch (input)
		 {
		 case Print:  //��ӡȫ����ϵ����Ϣ
			 system("cls");  //����
			 Print1(7);    //��������
			 qsort(pc.data, pc.size, sizeof(pc.data[0]), cmp_name);//����������ͨѶ¼
			 ContactPrint(&pc);  
			 break;
		 case Add:   //������ϵ��
			 system("cls");
			 ContactAdd(&pc);

			 break;
		 case Del:    //ɾ����ϵ��
			 system("cls");
			 ContactPrint(&pc);
			 ContactDel(&pc);
			 break;
		 case Find:   //���������ϵ��
			 system("cls");
			 Print1(3);
			  n = 0;  //n��Ϊ�Ƿ��ҵ���ϵ�˵Ŀ���
			 printf("\n\t\t\t\t\t\t\t\tPS:����������,�Ա𣬵绰���룬��ַ������\n");
			 printf("\n\t\t\t\t\t��������Ҫ������ϵ�˵���Ϣ:");
			 scanf("%s", FindObject);   //���������Ϣ
			 pos = ContactFind(&pc, FindObject, pos);   //������ң��ҵ��˷��ض�Ӧ�±꣬�Ҳ�������-1
			  pos2 = pos;
			 while (1)						
			 {
				 if (pos2 != -1)      //��Ϊ-1�����ӡ���±��Ԫ��
				 {
					 n++;
					 if (n == 1)
						 printf("\n%-20s %-10s %-8s %-18s %-30s\n", "����", "�Ա�", "����", "�绰����", "��ַ");
					 printf("\n%-20s %-10s % -8s % -18s %-30s\n", pc.data[pos2].name,
						 pc.data[pos2].sex, pc.data[pos2].age, pc.data[pos2].tele, pc.data[pos2].addr);
					 //Ȼ���ٰ��Ѿ��ҵ���Ԫ�ص���һ�����±괫��ȥ���в��ң�ֱ���������е����Ԫ�ؾ�ֹͣ
					 pos2 = ContactFind(&pc, FindObject, pos2+1);  

				 }
				 else
				 {
					 if (n == 0)  //���һ��ʼn��Ϊ0����˵��һ��Ҳû���ҵ���Ҳ�Ͳ����ڸ���ϵ��
						 printf("\t\t\t\t\t�޴���ϵ��\n");
					 break;
				 }
			 }
			 break;

		 case Revise:  //�޸���ϵ����Ϣ
			 system("cls");
			 ContactPrint(&pc);   //�޸�ǰ�ȴ�ӡ��ϵ����Ϣ���Է����û�ѡ���޸Ķ���

			 ContactRevise(&pc);	//�޸���ϵ����Ϣ����ʵ��
			 break;

		 case Save:  //�û�Ҳ�����ֶ�������Ϣ���ļ�
			 system("cls");
			 qsort(pc.data, pc.size, sizeof(pc.data[0]), cmp_name);//����������ͨѶ¼
			 ContactSave(&pc);
			 UserSave(&user1);
			 printf("\t\t\t\t\t����ɹ�\n");
			 break;

		 case Exit:   //�˳�ǰ�ȱ���ͨѶ¼��Ϣ���˺���Ϣ���ļ����������ٿ��ٵĿռ�
			 system("cls");
			 ContactSave(&pc);
			 UserSave(&user1);
			 ContactDestroy(&pc);
			 printf("\t\t\t\t\t�˳��ɹ�\n");

			 break;

		 case Reviseuser:     //
			 ReviseUser(&user1, pos1);
			 break;

		 default:   //ѡ����������û���������
			 system("cls");
			 printf("\t\t\t\t\t�޴�ѡ�����������\n");
			 break;
		 }
		 Q++;

	 } while (input);
	
	return 0;
}

/*----------------------------------------------------------------------------------------* / 

          /*���еĺ���ʵ�� */

//��������
void Print1(int n) 
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("\n");
	}
}
//�˵�
void menu()
{
	printf("\t\t\t\t==================================================\t\t\t\t\t\n");
	printf("\t\t\t\t*      1.�鿴��ϵ����Ϣ        2.������ϵ��      *\t\t\t\t\t\n");
	printf("\t\t\t\t*      3.ɾ����ϵ��            4.������ϵ��      *\t\t\t\t\t\n");
	printf("\t\t\t\t*      5.�޸���ϵ��            6.����            *\t\t\t\t\t\n");
	printf("\t\t\t\t*      7.�˺�����              0.�˳�            *\t\t\t\t\t\n");
	printf("\t\t\t\t===================================================\t\t\t\t\t\n");

}
//��¼�˵�
void menu1()
{
	Print1(7);
	printf("\t\t\t\t\t=========��ӭ����ͨѶ¼��¼ϵͳ=========\t\t\t\t\t\n");
	printf("\t\t\t\t\t========================================\t\t\t\t\t\n");
	printf("\t\t\t\t\t*                1.��¼                *\t\t\t\t\t\n");
	printf("\t\t\t\t\t*                2.ע��                *\t\t\t\t\t\n");
	printf("\t\t\t\t\t*                3.�һ�����            *\t\t\t\t\t\n");
	printf("\t\t\t\t\t*                4.�����¼            *\t\t\t\t\t\n");
	printf("\t\t\t\t\t*                0.�˳�                *\t\t\t\t\t\n");
	printf("\t\t\t\t\t========================================\t\t\t\t\t\n");
}

//��ʼ��ͨѶ¼
void ContactInit(Contact* pc)
{
	
	pc->data = NULL;
	pc->capacity = pc->size = 0;
	
	ContactLoad(pc);//����ͨѶ¼��Ϣ
}

//����ڴ��Ƿ�����
void CheckCapacity(Contact* pc)
{
	//���ͨѶ¼����Ϊ�գ����ȸ�ֵ4���ռ䣬���˾���������
	if (pc->capacity == pc->size)
	{
		int newcapacity = pc->capacity == 0 ? 4 : pc->capacity * 2;
		people* tem = (people*)realloc(pc->data,sizeof(people) * newcapacity);
		if (tem == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
		pc->data = tem;
		pc->capacity = newcapacity;
	}
}

//������ϵ��
void ContactAdd(Contact* pc)
{
	//���ԣ��ж�pc�Ƿ�ΪNULL
	assert(pc);  
	//������ϵ��ǰ�ȼ������
	CheckCapacity(pc);
	printf("\n\t\t\t\t\t����������:");
	scanf("%s", pc->data[pc->size].name);

	printf("\n\t\t\t\t\t�������Ա�:");
	scanf("%s", pc->data[pc->size].sex);

	printf("\n\t\t\t\t\t����������:");
	scanf("%s", pc->data[pc->size].age);

	printf("\n\t\t\t\t\t������绰����:");
	scanf("%s", pc->data[pc->size].tele);

	printf("\n\t\t\t\t\t�������ַ:");
	scanf("%s", pc->data[pc->size].addr);


	pc->size++;
	printf("\t\t\t\t\t��ӳɹ�\n");
}

//����ͨѶ¼
void ContactDestroy(Contact* pc)
{
	//���ԣ��ж�pc�Ƿ�ΪNULL
	assert(pc);
	free(pc->data);
	pc->data = NULL;
	pc->capacity = pc->size = 0;

}

//��ӡ��ϵ����Ϣ
void ContactPrint(Contact* pc)
{
	//���ԣ��ж�pc�Ƿ�ΪNULL
	assert(pc);
	int i = 0;
	printf("%-20s %-10s %-8s %-18s %-30s\n\n", "����", "�Ա�", "����", "�绰����", "��ַ");

	for (i = 0; i < pc->size; i++)
	{
		printf("%-20s %-10s %-8s %-18s %-30s\n", pc->data[i].name, pc->data[i].sex, pc->data[i].age, pc->data[i].tele, pc->data[i].addr);
	}
	printf("\n\n�ܼ���%d����ϵ��\n", pc->size);
}

//����ָ����ϵ��  ���ҵ��˷��ض�Ӧ�±꣬�Ҳ�������-1
int  ContactFind(Contact* pc, char* FindObject,int pos)
{
	//���ԣ��ж�pc�Ƿ�ΪNULL
	assert(pc);
	int i = 0;
	for (i = pos; i < pc->size; i++)//������������������Ԫ�ؽ��з���
	{
		//��������ϵ�˵����֣��Ա𣬵绰����ַ���������һһ�Ƚ�
		if (strcmp(FindObject, pc->data[i].name) == 0 || strcmp(FindObject,pc->data[i].sex) == 0 || strcmp(FindObject, pc->data[i].tele) == 0
			|| strcmp(FindObject, pc->data[i].age) == 0 || strcmp(FindObject, pc->data[i].addr) == 0)
		{
			return i;
		}
	}
	return -1;
}

//ɾ����ϵ�˵���Ϣ
void ContactDel(Contact* pc)
{
	assert(pc);
	printf("\n\t\t\t\t\t������Ҫɾ������ϵ������:");
	char DelName[MAX_NAME] = { 0 };
	scanf("%s", DelName);
	int  del = ContactFind(pc, DelName,0);   //���û�Ҫɾ�������ֽ����������и���ϵ�˾ͽ���ɾ��
	if (del == -1)
	{
		printf("\n\t\t\t\t\t����ϵ�˲�����\n");
		return;
	}
	int i = 0;
	for (i = del; i < pc->size; i++)  //ɾ��
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->size--;
	printf("\n\t\t\t\t\tɾ���ɹ�\n");
}

//�޸�ָ����ϵ��
void ContactRevise(Contact* pc)
{
	assert(pc);
	int input = 0;
	printf("\n\n\t\t\t\t\t��������Ҫ�޸���ϵ�˵�����:");
	char RevName[MAX_NAME] = { 0 };
	scanf("%s", RevName);
	int pos = ContactFind(pc, RevName,0);    //���û�Ҫ�޸ĵ����ֽ����������и���ϵ�˾ͽ����޸�
	if (pos == -1)
	{
		printf("\n\t\t\t\t\t����ϵ�˲�����!");
		return;
	}
	system("cls");
	//�޸�ǰ�ȴ�ӡ����ϵ����Ϣ
	printf("\n\n%-20s %-10s %-8s %-18s %-30s\n", "����", "�Ա�", "����", "�绰����", "��ַ");
	printf("\n%-20s %-10s % -8s % -18s %-30s\n", pc->data[pos].name,
		pc->data[pos].sex, pc->data[pos].age, pc->data[pos].tele, pc->data[pos].addr);

	//���û�ѡ���޸ĵĶ���
	do
	{
		printf("\n\n\t\t��ѡ��Ҫ�޸ĵ���Ϣ!\n");
		printf("\n\t\t1.����   2.�Ա�   3.����   4.�绰����   5.��ַ   6.ȫ�������޸�   0.�˳�\n");
		printf("\n\t\t��ѡ��:>");
		scanf("%d", &input);

		switch(input)
		{
			case 1:
				printf("\n\t\t����������:");
				scanf("%s", pc->data[pos].name);
				printf("\n\t\t�޸ĳɹ�\n");
				printf("\n\t\t�Ƿ�����޸�,��\"1\"��������\"0\"�˳�\n");
				scanf("%d", &input);
				break;
			case 2:
				printf("\n\t\t�������Ա�:");
				scanf("%s", pc->data[pos].sex);
				printf("\n\t\t�޸ĳɹ�\n");
				printf("\n\t\t�Ƿ�����޸�,��\"1\"��������\"0\"�˳�\n");
				scanf("%d", &input);

				break;
			case 3:
				printf("\n\t\t����������:");
				scanf("%s", pc->data[pos].age);
				printf("\n\t\t�޸ĳɹ�\n");
				printf("\n\t\t�Ƿ�����޸�,��\"1\"��������\"0\"�˳�\n");
				scanf("%d", &input);
				break;
			case 4:
				printf("\n\t\t������绰����:");
				scanf("%s", pc->data[pos].tele);
				printf("\n\t\t�޸ĳɹ�\n");
				printf("\n\t\t�Ƿ�����޸�,��\"1\"��������\"0\"�˳�\n");
				scanf("%d", &input);
				break;
			case 5:
				printf("\n\t\t�������ַ:");
				scanf("%s", pc->data[pos].addr);
				printf("\n\t\t�޸ĳɹ�\n");
				printf("\n\t\t�Ƿ�����޸�,��\"1\"��������\"0\"�˳�\n");
				scanf("%d", &input);
				break;
			case 6:
				printf("\n\t\t����������:");
				scanf("%s", pc->data[pos].name);

				printf("\n\t\t�������Ա�:");
				scanf("%s", pc->data[pos].sex);

				printf("\n\t\t����������:");
				scanf("%s", pc->data[pos].age);

				printf("\n\t\t������绰����:");
				scanf("%s", pc->data[pos].tele);

				printf("\n\t\t�������ַ:");
				scanf("%s", pc->data[pos].addr);
				printf("\n\t\t�޸ĳɹ�\n");
				input = 0;
				break;
			case 0:
				printf("�˳��ɹ�\n");
				break;
			default:
				printf("\n\t\t\t\t\t�޴�ѡ�����������\n");
				break;
		}

	} while (input);

}

//����ͨѶ¼��Ϣ���ļ�
void ContactSave(Contact* pc)
{
	assert(pc);
	FILE* pf = fopen("people.data", "wb");
	if (pf == NULL)
	{
		printf("ContactSave::���ļ�ʧ��\n");
		exit(-1);
	}
	int i = 0;
	for (i = 0; i < pc->size; i++)  //����ͨѶ¼��Ϣ���ļ�
	{
		fwrite(&pc->data[i], sizeof(people), 1, pf);
	}

	fclose(pf);
	pf = NULL;
}

//�����ļ����ݵ�ͨѶ¼
void ContactLoad(Contact* pc)
{
	//���ļ���Ϣ
	FILE* pf = fopen("people.data", "rb");
	if (pf == NULL)  //���pf==NULL�����ļ�û�У���ȥ�˵ط� ��Ԥ��һ���ļ��ʹﵽ�� �Զ�����һ���ļ���Ŀ��
	{
		pf = NULL;
		pf = fopen("people.data", "wb");//�����ļ�
		if (pf == NULL)
		{
			printf("ContactLoad::���ļ�ʧ��\n");
			exit(-1);
		}
		fclose(pf);
		pf = NULL;
		pf = fopen("people.data", "rb");//�����´��ļ�
		if (pf == NULL)
		{
			printf("ContactLoad::ʧ��\n");
			exit(-1);
		}

	}
	people tmp = { 0 };  //������ʱ�����ļ��ڵ���Ϣ
	while (fread(&tmp, sizeof(people), 1, pf))  //���ļ�����ͨѶ¼��Ϣ
	{
		CheckCapacity(pc);
		pc->data[pc->size] = tmp;
		pc->size++;
		
	}

	fclose(pf);  //�ر��ļ�
	pf = NULL;
}

//��ʼ����¼�˺�
void UserInit(user* pu)
{
	assert(pu);
	pu->begin = 0;

	UserLoad(pu);  //�����˺���Ϣ��������
}

//ע��
void Userreg(user* pu)
{
	assert(pu);
	Print1(7);

	printf("\n\t\t\t\t\t\t\t\tPS:�˽�������ʱ������\"exit\"�����˳��˽���\n");
	printf("\n\t\t\t\t\t�뿪ʼע���˺�\n");
	printf("\n\t\t\t\t\t�˺�:");
	scanf("%s", pu->val[pu->begin].Account);  //�����û�������˺�

	if (strcmp(pu->val[pu->begin].Account, "exit") == 0)   //�����û����˳�����
	{
		system("cls");//���� 
		return;
	}
	printf("\n\t\t\t\t\t����:");
	scanf("%s", pu->val[pu->begin].password);   //��������
	if (strcmp(pu->val[pu->begin].password, "exit") == 0)   //�����û����˳�����
	{
		system("cls");

		return;
	}

	printf("\n\t\t�������˺����Ư��������,���������Ժ���������֣�ͬʱҲ�����һ�����ĸ��ݣ���\n");
	printf("\n\t\t\t\t\t");
	scanf("%s", pu->val[pu->begin].userName);
	if (strcmp(pu->val[pu->begin].userName, "exit") == 0)//�����û����˳�����
	{
		system("cls");

		return;
	}

	pu->begin++;
	system("cls");
	printf("\t\t\t\t\tע��ɹ�\n");
}

//�������봦������Ļ���ԡ�*��
void Getpassword(char* pass, int sz)
{
	assert(pass);
	char c = 0;
	int i = 0;
	while ((c = getch()) != 13)
	{

		pass[i] = c;
		i++;
		putchar('*');  //��Ļ���ԡ�*��
		if (i > sz - 2)
		{
			printf("\n�������\n");
			break;
		}
	}
	pass[i] = '\0';
}

//��¼    ��¼�ɹ����ض�Ӧ�����±꣬���򷵻�-1
int UserLongin(user* pu)
{
	char UName[MAX_NAME] = { 0 };
	char Pass[MAX_PASS] = { 0 };
	int i = 0;
	int flag = 0;//����û��ϵͳ�����ڸ��˺�ʱ�����û��Ŀ��� 
	system("cls");
	printf("\n\n\t\t\t\t\t=============================\n");
	printf("\t\t\t\t\t*          ��¼����         *\n");
	printf("\t\t\t\t\t=============================\n");

	printf("\n\t\t\t\t\t�˺�:");
	scanf("%s", UName);
	for (i = 0; i <= pu->begin; i++)  //���û�������˺Ž��к��ļ��л�ȡ���˺���һ�Ա�
	{

		if (strcmp(UName, pu->val[i].Account) == 0)  //����ͬ���˺������û���������
		{
			while (strcmp(Pass, "exit") != 0)
			{

				printf("\n\t\t\t\t\t����:");
				
				Getpassword(Pass, MAX_PASS); //�������룬ͬʱ����Ļ���ԡ�*��

				if (strcmp(Pass, pu->val[i].password) == 0) //����������ȷ�ͷ��ظ��˺ŵ������±꣬Ȼ�����ͨѶ
				{
					system("cls");

					printf("\n\n\n\n��¼�ɹ�,���ڼ���ͨѶ¼................................\n");
					return i;
				}
				else//���������������û��Ƿ��������
				{
					printf("\t\t\t\t\t\n�������,��������exit�˳�,�������밴1\n");
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
	if (flag == 0) //����˺ŶԲ��Ͼ������û�
	{
		system("cls");
		printf("\t\t\t\t\t�޴��˺�\n");
		Sleep(300);
	}
	return -1;
}

//�����û��˺�
void UserSave(user* pu)
{
	assert(pu);
	FILE* pf = fopen("user.data", "wb");
	if (pf == NULL)
	{
		printf("UserSave::���ļ�ʧ��\n");
		exit(-1);
	}
	int i = 0;
	for (i = 0; i < pu->begin; i++)		//�����˺���Ϣ���ļ�
	{
		fwrite(&pu->val[i], sizeof(personnel), 1, pf); //����Ϣд���ļ���
	}

	fclose(pf);
	pf = NULL;
}

//�����û��˺�
void UserLoad(user* pu)
{
	//���ļ���Ϣ
	FILE* pf = fopen("user.data", "rb");
	if (pf == NULL)  //���pf==NULL�����ļ�û�У���ȥ�˵ط� ��Ԥ��һ���ļ��ʹﵽ�� �Զ�����һ���ļ���Ŀ��
	{
		pf = NULL;
	    pf = fopen("user.data", "wb");//�����ļ�
		if (pf == NULL)
		{
			printf("UserSave::���ļ�ʧ��\n");
			exit(-1);
		}
		fclose(pf);   //�ٹر�
		pf = NULL;
		pf = fopen("user.data", "rb");//�����´��ļ�
		 if (pf == NULL)
		 {
			 printf("UserLoad::ʧ��\n");
			 exit(-1);
		}

	}
	//���ļ���Ϣ
	int i = 0;
	personnel tem = {0};
	while (fread(&tem, sizeof(personnel), 1, pf))//���ļ�һ��һ������������
	{
		pu->val[i] = tem;
		i++;
		pu->begin++;
	}
	fclose(pf);
	pf = NULL;
}

//����û��˺��Ƿ�����
int  CheckUser(user* pu)
{
	assert(pu);
	if (pu->begin >= N)  
	{
		printf("\t\t\t\t\t�û��˺�����\n");
		return -1;
	}
	return 1;
}

//�޸��˺���Ϣ
void ReviseUser(user* user1,int pos)
{
	assert(user1);
	system("cls");
	Print1(7);

	printf("\n\t\t\t\t1.�޸�����   2.�޸��˺�   3.�޸�����   4.�鿴�˺���Ϣ   5.�˳��˽���\n");
	printf("\n\t\t\t\t��ѡ��:");
		int input = 0;
		scanf("%d", &input);  //�����û�ѡ���޸Ķ���Ĺ���
		switch (input)
		{
		case 1:
			printf("\n\t\t\t\tԭ����:%s", user1->val[pos].userName);
			printf("\n\t\t\t\t���޸�:");
			scanf("%s", user1->val[pos].userName);
			break;
		case 2:
			printf("\n\t\t\t\tԭ�˺�:%s", user1->val[pos].Account);
			printf("\n\t\t\t\t���޸�:");
			scanf("%s", user1->val[pos].Account);
			break;
		case 3:
			printf("\n\t\t\t\tԭ�˺�:%s", user1->val[pos].password);
			printf("\n\t\t\t\t���޸�:");
			scanf("%s", user1->val[pos].password);
			break;
		case 4:
			printf("\n\t\t\t\t����:%s", user1->val[pos].userName);
			printf("\n\t\t\t\t�˺�:%s", user1->val[pos].Account);
			printf("\n\t\t\t\t����:%s", user1->val[pos].password);
		case 5:
			break;
		default:
			printf("\n\t\t\t\t�޴�ѡ��\n");
			break;
		}
}

//����Ա����
void Manage(user* user1)
{
	assert(user1);
	int input = 0;
	int i = 0;
	int n = 0;
	do
	{
		printf("\n\t\t\t\t1.�鿴�����˺�   2.�޸��˺���Ϣ   3.ɾ���˺�  0.�˳�\n");
		printf("\n\t\t\t\t\t��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1: //�鿴�����˺�
			
			for (i = 0; i < user1->begin; i++)
			{
				printf("\n\t\t\t\t%d.����:%s",i,user1->val[i].userName);
				printf("\n\t\t\t\t  �˺�:%s", user1->val[i].Account);
				printf("\n\t\t\t\t  ����:%s\n\n", user1->val[i].password);
			}
			break;
		case 2:      //�޸��˺���Ϣ
			system("cls");
			for (i = 0; i < user1->begin; i++)
			{
				printf("\n\t\t\t\t%d.����:%s", i, user1->val[i].userName);
				printf("\n\t\t\t\t  �˺�:%s", user1->val[i].Account);
				printf("\n\t\t\t\t  ����:%s\n\n", user1->val[i].password);
			}
			printf("\n\t\t\t\t��ѡ��Ҫ�޸ĵ����:>");
			scanf("%d", &n);
			if(n>=0&& n<user1->begin)
			{
				ReviseUser(user1, n); //�޸��˺���Ϣ����
				UserSave(user1);    //�޸���ͱ���ͬ�����ļ�
			}
			else
			{
				printf("\n��Чѡ��\n");
			}
			
			break;
		case 3:  //ɾ���˺�
			system("cls");
			for (i = 0; i < user1->begin; i++)
			{
				printf("\n\t\t\t\t%d.����:%s", i, user1->val[i].userName);
				printf("\n\t\t\t\t  �˺�:%s", user1->val[i].Account);
				printf("\n\t\t\t\t  ����:%s\n\n", user1->val[i].password);
			}
			printf("\n\t\t\t\t��ѡ��Ҫɾ�������:>");
			scanf("%d", &n);
			if (n >= 0 && n < user1->begin)  
			{
				for (i = 0; i < user1->begin; i++)
				{
					if (n+1 == user1->begin) //���ֻ��һ��������ɾ�����һ��ֱ�Ӷ�����������һ����
					{
						break;
					}
					else  //����ɾ��
					{
						strcpy(user1->val[i].userName, user1->val[i + 1].userName);
						strcpy(user1->val[i].Account, user1->val[i + 1].Account);
						strcpy(user1->val[i].password, user1->val[i + 1].Account);

					}		
				}
				user1->begin--;
				UserSave(user1); //�޸���ͱ���ͬ�����ļ�
			}
			else
			{
				printf("\n��Чѡ��\n");
			}		
			break;
		case 0:  //�˳�
				break;
		default:
			printf("\n�޴�ѡ�������ѡ��\n");
			break;

		}
	} while (input);
}

//�˺Ź���Ա��¼
void Administrator(user* user1)
{
	assert(user1);
	char account[MAX_ACC] = {0};
	char password[MAX_PASS] = {0};
	system("cls");
	printf("\n\n\t\t\t\t\t����Ա��¼����\n");
	
		printf("\n\t\t\t\t\t�˺�:");
		scanf("%s", account);
		if (strcmp(account, "admin") == 0)  //����Ա�˺���Ψһ�ģ��ǳ����ڶ���
		{
			while (strcmp(password,"exit")!=0)
			{
				printf("\n\t\t\t\t\t����:");
				Getpassword(password, MAX_PASS); 
				if (strcmp(password, "123") == 0)  //����Ҳ��Ψһ��
				{
					 Manage(user1); //����Ա�������		
					break;
				}
				else
				{
					printf("\n\t\t\t\t\t���������������ϵ������Ա\n");
				}
			}
		}
		else
		{
			printf("\n\t\t\t\t\t�˺Ŵ���,��������ϵ������Ա\n");
		}
}

////�һ�����           
void  GetbackPassword(user* user1) 
{
	assert(user1);
	char account[MAX_ACC] = {0};
	//system("cls");
	printf("\n\t\t\t\t\t��������˺�:");
	scanf("%s", account);
	int input = 1;
	int i = 0;
	for (i = 0; i < user1->begin; i++)  //���Ҷ�Ӧ���˺�
	{
		if (strcmp(account, user1->val[i].Account) == 0)
		{
			char UserName[MAX_NAME] = { 0 };
			input = 1; //�����˳�����
			while (input)
			{
				//system("cls");
				printf("\n\t\t\t\t\t��������ע��ʱ������:");   //ע��ʱ��������Ϊ�һ������׼��
				scanf("%s", UserName);
				if (strcmp(UserName, user1->val[i].userName) == 0)
				{
					system("cls");
					Print1(7);
					printf("\n\t\t\t\t\t�˺�:");
					printf("%s", user1->val[i].Account);
					printf("\n\t\t\t\t\t����Ϊ:");
					printf("%s", user1->val[i].password);
					printf("\t\t\tPS:��0�˳��˽���\n");
					printf("\n\t\t\t\t\t");
					scanf("%d", &input);
					system("cls");
					break;
				}
				else
				{
					printf("\n\t\t\t\t\t�����ע��ʱ�����Ʋ���\n");
					Print1(7);
					printf("\t\t\tPS:��1��������0�˳��˽���\n");
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
		printf("\n\t\t\t\t\t�޴��˺�\n");
		Sleep(400); //�ó���ͣ400ms
}

//��¼ϵͳ
int UserLongsonSystem(user* user1)
{
	int p = 0;
	int input = 0;
	int pos1 = 0;
	do {
		system("cls");
		menu1();
		Print1(3);

		printf("\t\t\t\t\t��ѡ��>:");

		scanf("%d", &input);  //�����û�ѡ��Ĺ���
		switch (input)
		{
		case 1:  //��¼
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
		case 2:  //ע��
			system("cls");
			printf("\n\t\t\t����%d���˺���ϵͳ����������ע��%d���˺ţ���������ϵ����Ա����\t\t\t\t\t\n\n", user1->begin, N - user1->begin);
			p = CheckUser(user1);

			if (p != -1)//�˺�δ������ע��
			{
				Userreg(user1);
				UserSave(user1);
			}

			break;

		case 3:  //�һ�����
			GetbackPassword(user1);
			
			break;
		case 4:  //����Ա��¼
			Administrator(user1);
			break;
		case 0:  //�˳�����
			UserSave(user1);
			printf("\t\t\t\t\t�˳��ɹ�\n");
			return -1;
		default:  //ѡ���������
			system("cls");
			printf("\t\t\t\t\t�޴�ѡ�����������\n");
			break;
		}

	} while (input);
	return pos1;
}
//����������ͨѶ¼
int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((people*)e1)->name, ((people*)e2)->name);
}



