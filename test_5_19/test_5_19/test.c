#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hello bit\n");
//    }
//    return 0;
//}


//
////ģ��ʵ�ֿ⺯��strlen
//#include<stdio.h>
//#include<assert.h>
//int my_strlen(const char* p)
//{
//	assert(p);
//	int count = 0;
//	while (*p != '\0')
//	{
//		count++;
//		p++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "hello xiaojin!";
//
//	int len=my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}
//
//
////ģ��ʵ�ֿ⺯��strcpy
//#include<stdio.h>
//#include<assert.h>
//
//char* my_strcpy(char* dest, const char* soure)
//{
//	assert(soure);
//	assert(dest);
//	char* tem = dest;
//	while (*dest++ = *soure++)
//	{
//		;
//	}
//	return tem;
//}
//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "XXXXXXXXXXXXXXX";
//
//	printf("%s\n", my_strcpy(arr2, arr1));
//	return 0;
//}

//
//��Ŀ��
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�

#include<stdio.h>

void AdjustArr(int* p, int len)
{
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		//�ҳ���߲�Ϊ������
		while (p[left] % 2 != 0 && left < right)
		{
			left++;
		}
		//�ҳ��ұ߲�Ϊż����
		while (p[right] % 2 == 0 && left < right)
		{
			right--;
		}
		//����
		if (p[left] % 2 == 0 && p[right] % 2 != 0 && left < right)
		{
			int tem = p[left];
			p[left] = p[right];
			p[right] = tem;
		}
	}
}
int main()
{
	int arr[] = { 1,2,5,3,4,8,6,7,9,10,3,2,134,435,324,67,345 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	AdjustArr(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}