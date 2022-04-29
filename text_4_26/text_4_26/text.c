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



////将数组A中的内容和数组B中的内容进行交换。（数组一样大）
//#include<stdio.h>
////交换
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
//	printf("交换前arr1：%s\n", arr1);
//	printf("交换前arr2：%s\n", arr2);
//	swap_arr(arr1, arr2);
//	printf("\n交换后arr1：%s\n", arr1);
//	printf("交换后arr2：%s\n", arr2);
//	
//	return 0;
//}


///////将数组A中的内容和数组B中的内容进行交换。（数组一样大）
//#include<stdio.h>
//int main()
//{
//	int arr1[3] = { 0 };
//	int arr2[3] = { 0 };
//	int i = 0;
//	printf("请输入三个数\n");
//	for ( i = 0; i < 3; i++)
//	{
//		scanf("%d", &arr1[i]);
//	}
//	printf("请输入三个数\n");
//
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%d", &arr2[i]);
//	}
//	//交换数组
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
////创建一个整形数组，完成对数组的操作
////
////实现函数init() 初始化数组为全0
////实现print()  打印数组的每个元素
////实现reverse()  函数完成数组元素的逆置。
////要求：自己设计以上函数的参数，返回值。
//#include<stdio.h>
////初始化数组
//void init(int* p, int size)
//{
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		p[i] = 0;
//	}
//}
////打印数组
//void print(int* p, int size)
//{
//	int i = 0;
//	for (i = 0; i < size; i++)
//	{
//		printf("%d ", p[i]);
//	}
//}
////逆置数组
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
////编写一个函数 reverse_string(char* string)（递归实现）
////实现：将参数字符串中的字符反向排列，不是逆序打印。
////要求：不能使用C函数库中的字符串操作函数。
////比如 :
////char arr[] = "abcdef";
////逆序之后数组的内容变成：fedcba
//
//
//#include<stdio.h>
////计算字符串长度
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
////逆置字符串
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
////实现一个对整形数组的冒泡排序
//#include<stdio.h>
//void BBsort(int arr[], int size)
//{
//	int i = 0;
//	int j = 0;
//	int tem = 0;
//	//趟数
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