#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
//int main()
//{
//	//��д�ķ�ʽ��test.txt
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)//�ж��Ƿ�򿪳ɹ�
//	{
//		perror("file fail\n");
//		return 1;
//	}
//	//��test.txt�ļ���д������
//	fputs("hello word!",pf);
//	fclose(pf);//�ر��ļ�
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("file fail\n");
//		return 1;
//	}
//	fputs("I love xxxxxx", pf);
//	fseek(pf, 7, 0);//����λ��������ƫ��7��λ��
//	fputs("IT!", pf);//�ڴ�λ�������ļ���������
//	int size = ftell(pf);//�����ʱ�ļ�ָ���൱����ʼλ�õ�ƫ����
//	printf("%d\n", size);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int c; 
//	FILE* fp = fopen("test.txt", "r");
//	if (!fp) {
//		perror("File opening failed");
//		return 1;
//	}
//	//fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
//	while ((c = fgetc(fp)) != EOF) // ��׼C I/O��ȡ�ļ�ѭ��
//	{
//		putchar(c);
//	}
//		//�ж���ʲôԭ�������
//		if (ferror(fp))
//			puts("I/O error when reading");
//		else if (feof(fp))
//			puts("End of file reached successfully");
//	fclose(fp);
//}




//#include <stdio.h>
//#include <windows.h>
////VS2019 WIN10��������
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	fputs("abcdef", pf);//�Ƚ�����������������
//	printf("˯��10��-�Ѿ�д�����ˣ���test.txt�ļ��������ļ�û������\n");
//	Sleep(10000);
//	printf("ˢ�»�����\n");
//	fflush(pf);//ˢ�»�����ʱ���Ž����������������д���ļ������̣�
//	//ע��fflush �ڸ߰汾��VS�ϲ���ʹ����
//	printf("��˯��10��-��ʱ���ٴδ�test.txt�ļ����ļ���������\n");
//	Sleep(10000);
//	fclose(pf);
//	//ע��fclose�ڹر��ļ���ʱ��Ҳ��ˢ�»�����
//	pf = NULL;
//	return 0;
//}