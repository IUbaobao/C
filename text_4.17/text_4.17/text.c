#define _CRT_SECURE_NO_WARNINGS

//�ػ�����
//#include<stdio.h>
//#include<windows.h>
//
//int main()
//{
//	char iput[20] = { 0 };
//	system("shutdown -s -t 100");
//	again:
//	printf("��ĵ��Ի���100��͹ػ��������롰����������ȡ���ػ�\n");
//	scanf("%s", iput);
//		if (strcmp(iput, "������") == 0)
//		{
//			system("shutdown -a");
//			printf("��ȡ��\n");
//		}
//		else
//		{
//			goto again;
//		}
//	return 0;
//}

//
//
////ʵ��һ�������������������������ݡ�
//#include<stdio.h>
////����������
//void swap(int* a, int* b)
//{
//	int tem = *a;
//	*a = *b;
//	*b = tem;
//	//λ����
//	//*a = (*a) ^ (*b);
//	//*b = (*a) ^ (*b);
//	//*a = (*a) ^ (*b);
//
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("����ǰa=%d,b=%d\n", a, b);
//	swap(&a, &b);
//	printf("������a=%d,b=%d\n", a, b);
//	return 0;
//}

//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
//�磺����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���
//#include<stdio.h>
//void fun(int a)
//{
//	int i, j;
//	for (i = 1; i <= a; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%-d*%-d=%-4d\t", j, i, i * j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	fun(a);
//	return 0;
//}