#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
#include<string.h>
//int cmp_int(const void* e1, const void* e2)
//{
//	return (*(int*)e1) - (*(int*)e2);
//}
struct stu
{
	char name[20];
	int age;
};

int cmp_name(const void* e1, const void* e2)
{
	return (strcmp(((struct stu*)e2)->name, ((struct stu*)e1)->name));
}
int cmp_float(const void* e1, const void* e2)
{
	float sum = *(float*)e1 - *(float*)e2;
	if (sum > 0)
	{
		return 1;
	}
	else if (sum < 0)
	{
		return -1;
	}
	else
		return 0;
}

//int main()
//{
//	struct stu s1[3] = { {"�ƶ���",19},{"������",20},{"����",30} };
//	int arr[] = { 1,2,3,4,5,4,2,3,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	float arr2[] = { 1.0,6.0,7.0,4.0,2.0,9.0 };
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);  //��������
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	//qsort(s1, 3, sizeof(s1[0]), cmp_name);//����ṹ���е��ַ���
//   int  sz2 = sizeof(arr2) / sizeof(arr[0]);
//	qsort(arr2, sz2, sizeof(float), cmp_float);//���򸡵���
//	for (int i = 0; i < sz2; i++)
//	{
//		printf("%0.2f ", arr2[i]);
//	}
//	return 0;
//}

////��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ�
////���д�����������ľ����в���ĳ�������Ƿ���ڡ�
////Ҫ��ʱ�临�Ӷ�С��O(N)
//#include<stdio.h>
//int main()
//{
//	int arr[4][4] = { {1,5,7,9 },{4,6,10,15},{8,11,12,19},{14,16,18,21} };
//
//	int k = 0;
//	while (scanf("%d", &k)!=EOF)
//	{
//		
//		//��ȡ�������Ͻǵ������бȽ�
//		int i = 0;
//		int j = 3;
//		while (i < 4 && j >= 0)
//		{
//			//���k����������
//			if (k > arr[i][j])
//			{
//				i++;
//			}
//			//���kС����������
//			else if (k < arr[i][j])
//			{
//				j--;
//			}
//			else if (k == arr[i][j])
//			{
//				printf("�ҵ��ˣ�����Ϊ��%d��%d��\n ", i, j);
//				break;
//			}
//			//����Ѿ�Խ���򲻴��ڴ���
//			if (i >= 4 || j < 0)
//			{
//				printf("������\n");
//				break;
//			}
//		}
//	}
//
//	return 0;
//}


//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<string.h>
//int Check_adjust(char* s1,char*s2,int len1)
//{
//	
//	char  tem[100] = { 0 };//������ʱ��������ַ����ĳ�ʼ״̬
//	strcpy(tem, s1);
//	//k�����������ַ���������ÿ������֮����ַ�����s2�Ƚ�
//	for (int k = 1; k <= len1; k++)
//	{
//		//ÿ��ѭ���Ͱ�s1��س�̬
//		strcpy(s1, tem);
//		
//		//����������k���ַ�
//		int i = 0;
//		char* a = (char*)malloc(sizeof(char) * k);
//		//�Ȱ�Ҫ�������ַ�����һ����ʱ����
//		for (i = 0; i < k; i++)
//		{
//			a[i] = s1[i];
//		}
//		//�Ѳ����������ַ���ǰ��
//		for (i = 0; i < len1 - k; i++)
//		{
//			s1[i] = s1[i + k];
//		}
//		int j = 0;
//		//��Ҫ�������ַ��Ż�
//		for (i; i < len1; i++)
//		{
//			s1[i] = a[j];
//			j++;
//		}
//		free(a);
//		a = NULL;
//
//		//����֮���s2�Ƚ�
//		if (strcmp(s1, s2) == 0)
//		{
//			return 1;
//		}
//	}
//	//k��1�������ַ�������Ҳû������ͬ���򷵻�-1
//	return -1;
//	
//}
//
//int main()
//{
//	char s1[] = "AABCD";
//	char s2[] = "ABCDA";
//
//	int len1 = strlen(s1);
//	 int ret=Check_adjust(s1,s2, len1);
//	 printf("%d\n", ret);
//
//	return 0;
//}

//����ָ��
//void add()
//{
//	;
//}
//
//void(*pf)() = &add;
//
//int sum(int x, int y)
//{
//
//}
//
//int (*pf1)(int, int) = &sum;
//int (*pf1)(int, int) = sum;//Ҳ��



//ģ��qsort�Ĺ���ʵ��һ��ͨ�õ�ð������
#include<stdio.h>
//����
void Swap(char* buf1, char* buf2, int width)
{
	for (int i = 0; i < width; i++)
	{
		char tem = *buf1;
		*buf1 = *buf2;
		*buf2 = tem;
		buf1++;
		buf2++;
	}
	
}
//�Ƚ����ʹ�С
int cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}
//base�����׵�ַ��sz����Ԫ�س��ȣ�widthԪ��ռ���ٸ��ֽڣ�cmpԪ�رȽϵķ�ʽ�ĺ���
void Bubble_sort(void* base, int num, int width, int (*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < num - 1; i++)
	{
		int flag = 1;
		for (j = 0; j < num - i - 1; j++)
		{
			if (cmp((char*)base + j * width,(char*)base + (j + 1) * width)>0)
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
				flag = 0;
			}
		}
		if (flag == 1)
			return;
	}
}

int main()
{
	int arr[] = { 2,4,5,1,3,6,7,9,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//Bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	//for (int i = 0; i < sz; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
		struct stu s1[3] = { {"�ƶ���",19},{"������",20},{"����",30} };
	float arr2[] = { 1.0,6.0,7.0,4.0,2.0,9.0 };
	   int  sz2 = sizeof(arr2) / sizeof(arr[0]);
	Bubble_sort(arr2, sz2, sizeof(float), cmp_float);//���򸡵���
	Bubble_sort(s1, 3, sizeof(s1[0]), cmp_name);//����ṹ���е��ַ���

	//for (int i = 0; i < sz2; i++)
	//{
	//	printf("%0.2f ", arr2[i]);
	//}
	return 0;
}