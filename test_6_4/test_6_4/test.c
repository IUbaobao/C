#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//int main()
//{
//	int a = 0x00001234;
//	int b = 0x00001234;
//	int* pa = &a;
//	*pa = 1;
//
//	char* pb = (char*)&b;
//	*pb = 1;
//	*(pb + 1) = 0;
//	*(pb + 1) = 0;
//	*(pb + 1) = 0;
//
//
//	printf("a=%x,b=%x\n", a, b);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	const  char* p = "hello,My friend!";//��p��������"hello,My friend!"��
//
//	printf("%s", p);
//
//	return 0;
//}

//
//#include <stdio.h>
//int main()
//{
//    char arr1[] = "hello,My friend!";
//    char arr2[] = "hello,My friend!";
//    const char* arr3 = "hello,My friend!";
//    const char* arr4 = "hello,My friend!";
//    if (arr1 == arr2)
//        printf("arr1 =arr2\n");
//    else
//        printf("arr1 != arr2 \n");
//
//    if (arr3 == arr4)
//        printf("arr3 = arr4 \n");
//    else
//        printf("arr3 != arr4 \n");
//
//    return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	int arr1[] = { a,b };	//��������
//
//	int* arr2[] = { &a,&b };//ָ������
//
//	printf("arr[0]=%p\n", arr2[0]);
//	printf("arr[1]=%p\n",arr2[1]);
//	return 0;
//}

//
//#include <stdio.h>
//int main()
//{
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//    int(*p)[10] = &arr;//������arr�ĵ�ַ��ֵ������ָ�����p
//
//    //��������һ���������д���� һ������ָ��ıȽϱ���ʹ�÷���
//    int i = 0;
//    for (i; i < 10; i++)
//    {
//        printf("%d ", *((*p) + i)  );
//    }
//    printf("\n");
//    //�����д��������ȫ������һ������ָ�������
//    int* parr = arr;
//    for (i = 0; i < 10; i++)
//    {
//        printf("%d ", *(parr + i));
//    }
//    return 0;
//}


//#include <stdio.h>
////�Զ�ά�������ʽ���ܵ�ַ
//void print_arr1(int arr[3][5], int row, int col)
//{
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < row; i++)
//    {
//        for (j = 0; j < col; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//
//    printf("\n");
//   }
//}
////������ָ�����ʽ���ܵ�ַ
//void print_arr2(int(*arr)[5], int row, int col)
//{
//    int j = 0;
//    int i = 0;
//    for (i = 0; i < row; i++)
//    {
//        for (j = 0; j < col; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//}
//int main()
//{
//    int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
//    print_arr1(arr, 3, 5);
//    //������arr����ʾ��Ԫ�صĵ�ַ
//    //���Ƕ�ά�������Ԫ���Ƕ�ά����ĵ�һ��
//    //�������ﴫ�ݵ�arr����ʵ�൱�ڵ�һ�еĵ�ַ����һά����ĵ�ַ
//    //��������ָ��������
//    print_arr2(arr, 3, 5);
//    return 0;
//}


//
//
//#include <stdio.h>
//void test()
//{
//	printf("hehe\n");
//}
//int main()
//{
//	printf("%p\n", test);
//	printf("%p\n", &test);
//	return 0;
//}


//#include<stdio.h>
//
//int add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	void (*       signal(int, void(*)(int))             )(int);
//
//
//	int  add(int, int);
//
//
//
//	//add�����ĵ�ַ��δ��
//	int (*pf1)(int, int) = &add;
//
//	int (*pf1[5])(int, int)
//	printf("%p ", pf1);
//	return 0;
//}
//
//
//#include<stdio.h>
//
//int add(int x, int y)
//{
//	return x + y;
//}
//int sum(int x, int y)
//{
//	return x - y;
//}
//int main()
//{
//	//��д����ָ��
//	int (*pf)(int, int) = &add;
//
//	//�ٰѺ���ָ��copy�������ڱ�������Ӹ�[]
//	int (*pf1[5])(int, int) = { &add,&sum };
//
//	printf("pf=%p\npf1[0]=%p\npf1[1]=%p \n", pf, pf1[0], pf1[1]);
//
//	return 0;
//}

  











