#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//#include<stdlib.h>//malloc�����ͷ�ļ�
//int main()
//{
//	int arr[10];//��ջ������10��int���͵Ŀռ�
//	int* pa = (int*)malloc(sizeof(int) * 10);//���������10��int���͵Ŀռ�
//	if (pa == NULL)//�ж��Ƿ�����ʧ��
//	{
//		printf("malloc fail!\n");
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", pa[i]);
//	}
//	free(pa);//�ͷ��ڴ�
//	pa = NULL;
//	return 0;
//}

//
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	//���������10��int���͵Ŀռ�
//	int* pa = (int*)calloc(10, sizeof(int));
//	if (pa == NULL)//�ж��Ƿ�����ʧ��
//	{
//		printf("calloc fail!\n");
//		return 1;
//	}
//	//......
//	//�����ڴ治���ˣ���Ҫ����20��int���͵Ŀռ�
//	int* tem = (int*)realloc(pa, sizeof(int) * 30);
//	if (tem != NULL)//���ݳɹ����ܰѵ�ַ��pa
//	{
//		pa = tem;
//	}
//	free(pa);
//	pa = NULL;
//	free(NULL);
//	return  0;
//}
//

//���͵��ڴ�й©
//#include<stdio.h>
//#include<stdlib.h>
//void test()
//{
//	int* p = (int*)malloc(100);
//	if (NULL != p)
//	{
//		*p = 20;
//	}
//}
//int main()
//{
//	test();
//	while (1);
//}

//��������Test ��������ʲô���Ľ����
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}

//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//}

//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//
//int main()
//{
//	Test();
//	return 0;
//}



#include<stdio.h>

//struct S
//{
//	int i;
//	int a[0];
//};

//struct S
//{
//	int i;
//	int a[];
//};
//
//int main()
//{
//	printf("%d\n", sizeof(struct S));
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	printf("666");
//	return 0;
//}