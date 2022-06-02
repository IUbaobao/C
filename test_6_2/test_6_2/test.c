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
//	struct stu s1[3] = { {"黄东明",19},{"李子树",20},{"刘毅",30} };
//	int arr[] = { 1,2,3,4,5,4,2,3,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	float arr2[] = { 1.0,6.0,7.0,4.0,2.0,9.0 };
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);  //排序整型
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	//qsort(s1, 3, sizeof(s1[0]), cmp_name);//排序结构体中的字符串
//   int  sz2 = sizeof(arr2) / sizeof(arr[0]);
//	qsort(arr2, sz2, sizeof(float), cmp_float);//排序浮点型
//	for (int i = 0; i < sz2; i++)
//	{
//		printf("%0.2f ", arr2[i]);
//	}
//	return 0;
//}

////有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
////请编写程序在这样的矩阵中查找某个数字是否存在。
////要求：时间复杂度小于O(N)
//#include<stdio.h>
//int main()
//{
//	int arr[4][4] = { {1,5,7,9 },{4,6,10,15},{8,11,12,19},{14,16,18,21} };
//
//	int k = 0;
//	while (scanf("%d", &k)!=EOF)
//	{
//		
//		//先取矩阵右上角的数进行比较
//		int i = 0;
//		int j = 3;
//		while (i < 4 && j >= 0)
//		{
//			//如果k大，则往下找
//			if (k > arr[i][j])
//			{
//				i++;
//			}
//			//如果k小，则往左找
//			else if (k < arr[i][j])
//			{
//				j--;
//			}
//			else if (k == arr[i][j])
//			{
//				printf("找到了，坐标为（%d，%d）\n ", i, j);
//				break;
//			}
//			//如果已经越界则不存在此数
//			if (i >= 4 || j < 0)
//			{
//				printf("不存在\n");
//				break;
//			}
//		}
//	}
//
//	return 0;
//}


//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<string.h>
//int Check_adjust(char* s1,char*s2,int len1)
//{
//	
//	char  tem[100] = { 0 };//先用临时数组存着字符串的初始状态
//	strcpy(tem, s1);
//	//k控制左旋的字符个数，让每次左旋之后的字符串跟s2比较
//	for (int k = 1; k <= len1; k++)
//	{
//		//每次循环就把s1变回初态
//		strcpy(s1, tem);
//		
//		//下面是左旋k个字符
//		int i = 0;
//		char* a = (char*)malloc(sizeof(char) * k);
//		//先把要左旋的字符存在一个临时数组
//		for (i = 0; i < k; i++)
//		{
//			a[i] = s1[i];
//		}
//		//把不用左旋的字符往前移
//		for (i = 0; i < len1 - k; i++)
//		{
//			s1[i] = s1[i + k];
//		}
//		int j = 0;
//		//把要左旋的字符放回
//		for (i; i < len1; i++)
//		{
//			s1[i] = a[j];
//			j++;
//		}
//		free(a);
//		a = NULL;
//
//		//左旋之后跟s2比较
//		if (strcmp(s1, s2) == 0)
//		{
//			return 1;
//		}
//	}
//	//k从1左旋到字符串长度也没发现相同，则返回-1
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

//函数指针
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
//int (*pf1)(int, int) = sum;//也行



//模仿qsort的功能实现一个通用的冒泡排序
#include<stdio.h>
//交换
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
//比较整型大小
int cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}
//base数组首地址，sz数组元素长度，width元素占多少个字节，cmp元素比较的方式的函数
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
		struct stu s1[3] = { {"黄东明",19},{"李子树",20},{"刘毅",30} };
	float arr2[] = { 1.0,6.0,7.0,4.0,2.0,9.0 };
	   int  sz2 = sizeof(arr2) / sizeof(arr[0]);
	Bubble_sort(arr2, sz2, sizeof(float), cmp_float);//排序浮点型
	Bubble_sort(s1, 3, sizeof(s1[0]), cmp_name);//排序结构体中的字符串

	//for (int i = 0; i < sz2; i++)
	//{
	//	printf("%0.2f ", arr2[i]);
	//}
	return 0;
}