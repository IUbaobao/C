#define _CRT_SECURE_NO_WARNINGS

#include"Contact.h"

int main()
{
	system("color 6");//��������ɫ    60��ƣ�70��ɫ

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
					 n++;//ȷ��ֻ��ӡһ�α���
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