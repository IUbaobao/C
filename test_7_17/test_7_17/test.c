#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//#include<stdlib.h>//malloc所需的头文件
//int main()
//{
//	int arr[10];//在栈区开辟10个int类型的空间
//	int* pa = (int*)malloc(sizeof(int) * 10);//向堆区申请10个int类型的空间
//	if (pa == NULL)//判断是否申请失败
//	{
//		printf("malloc fail!\n");
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", pa[i]);
//	}
//	free(pa);//释放内存
//	pa = NULL;
//	return 0;
//}

//
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	//向堆区申请10个int类型的空间
//	int* pa = (int*)calloc(10, sizeof(int));
//	if (pa == NULL)//判断是否申请失败
//	{
//		printf("calloc fail!\n");
//		return 1;
//	}
//	//......
//	//假设内存不够了，需要扩容20个int类型的空间
//	int* tem = (int*)realloc(pa, sizeof(int) * 30);
//	if (tem != NULL)//扩容成功才能把地址给pa
//	{
//		pa = tem;
//	}
//	free(pa);
//	pa = NULL;
//	free(NULL);
//	return  0;
//}
//

//典型的内存泄漏
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

//请问运行Test 函数会有什么样的结果？
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