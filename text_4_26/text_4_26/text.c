#define _CRT_SECURE_NO_WARNINGS


//#include<stdio.h>
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int a[][1] = { 0 };
//	arr[1] = arr[3] * arr[2];
//	arr[0] = 3 * 4;
//	printf("%d ", arr[1]);
//	printf("\n%d ", arr[0]);
//	return 0;
//}



////������A�е����ݺ�����B�е����ݽ��н�����������һ����
//#include<stdio.h>
////����
//void swap_arr(char* arr1, char* arr2)
//{
//	while (*arr1 != '\0')
//	{
//		char tem = *arr1;
//		*arr1 = *arr2;
//		*arr2 = tem;
//		arr1++;
//		arr2++;
//	}
//}
//int main()
//{
//	
//	char arr1[] = "abcd";
//	char arr2[] = "fghi";
//	printf("����ǰarr1��%s\n", arr1);
//	printf("����ǰarr2��%s\n", arr2);
//	swap_arr(arr1, arr2);
//	printf("\n������arr1��%s\n", arr1);
//	printf("������arr2��%s\n", arr2);
//	
//	return 0;
//}


///////������A�е����ݺ�����B�е����ݽ��н�����������һ����
//#include<stdio.h>
//int main()
//{
//	int arr1[3] = { 0 };
//	int arr2[3] = { 0 };
//	int i = 0;
//	printf("������������\n");
//	for ( i = 0; i < 3; i++)
//	{
//		scanf("%d", &arr1[i]);
//	}
//	printf("������������\n");
//
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%d", &arr2[i]);
//	}
//	//��������
//	int tem = 0;
//	for (i = 0; i < 3; i++)
//	{
//		tem = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tem;
//	}
//	
//	return 0;
//}
//
//

//
////����һ���������飬��ɶ�����Ĳ���
////
////ʵ�ֺ���init() ��ʼ������Ϊȫ0
////ʵ��print()  ��ӡ�����ÿ��Ԫ��
////ʵ��reverse()  �����������Ԫ�ص����á�
////Ҫ���Լ�������Ϻ����Ĳ���������ֵ��
//#include<stdio.h>
////��ʼ������
//void init(int* p, int size)
//{
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		p[i] = 0;
//	}
//}
////��ӡ����
//void print(int* p, int size)
//{
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		printf("%d ", p[i]);
//	}
//}
////��������
//void reverse(int* p, int size)
//{
//	int i = 0;
//	int j = size - 1;
//	int tem = 0;
//	while (i < size / 2)
//	{
//		tem = p[i];
//		p[i] = p[j];
//		p[j] = tem;
//		j--;
//		i++;
//	}
//}
//
//int main()
//{
//	int arr[11] = { 1,2,3,4,5,6,7,8,9,10,11 };
//	//init(arr,10);
//	reverse(arr, 11);
//	print(arr, 11);
//	return 0;
//}


//
////��дһ������ reverse_string(char* string)���ݹ�ʵ�֣�
////ʵ�֣��������ַ����е��ַ��������У����������ӡ��
////Ҫ�󣺲���ʹ��C�������е��ַ�������������
////���� :
////char arr[] = "abcdef";
////����֮����������ݱ�ɣ�fedcba
//
//
//#include<stdio.h>
////�����ַ�������
//int my_strlen(char* p)
//{
//	int count = 0;
//	while (*p != '\0')
//	{
//		count++;
//		p++;
//	}
//	return count;
//}
////�����ַ���
//void reverse_string(char* p)
//{
//	int len = my_strlen(p);	
//	int tem = *(p + len - 1);
//	*(p + len - 1) = '\0';
//	if (my_strlen(p + 1) >= 2)
//	{
//		reverse_string(p + 1);
//	}
//	*(p + len - 1) = *p;
//	*p = tem;
//
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s", arr);
//	return 0;
//}
//
//
////ʵ��һ�������������ð������
//#include<stdio.h>
//void BBsort(int arr[], int size)
//{
//	int i = 0;
//	int j = 0;
//	int tem = 0;
//	//����
//	for (i = 0; i < size-1; i++)
//	{
//		for (j = 0; j < size - i - 1; j++)
//		{
//			if (arr[j] > arr[j+1])
//			{
//				tem = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tem;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 9,1,2,5,3,4,8,10,7,6 };
//	BBsort(arr, 10);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}