#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//
//
//void AdjustArr(int* p, int len)
//{
//	int left = 0;
//	int right = len - 1;
//	while (left < right)
//	{
//		//�ҳ���߲�Ϊ������
//		while (p[left] % 2 != 0 && left < right)
//		{
//			left++;
//		}
//		//�ҳ��ұ߲�Ϊż����
//		while (p[right] % 2 == 0 && left < right)
//		{
//			right--;
//		}
//		//����
//		if (p[left] % 2 == 0 && p[right] % 2 != 0 && left < right)
//		{
//			int tem = p[left];
//			p[left] = p[right];
//			p[right] = tem;
//		}
//	}
//}
//int main()
//{
//	int arr[10] = {0};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	//����
//	AdjustArr(arr, sz);
//	
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//    char a[1000];
//    int i;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", strlen(a));
//    return 0;
//}





//#include<stdio.h>
//int main()
//{
//	int a = 20;
//	int b = -10;
//	return 0;
//}


////�������������棿
//#include <stdio.h>
//int main()
//{
//    char a = -128;
//    printf("%u\n", a);
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    char a = -1;
//    signed char b = -1;
//    unsigned char c = -1;
//    printf("a=%d,b=%d,c=%d", a, b, c);
//    return 0;
//}

//����������ʲô��
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    char a[1000];
//    int i;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", strlen(a));
//    return 0;
//}
// 


//
////����������ʲô��
//#include<stdio.h>
//int main()
//{
//	int n = 9;
//	float* pFloat = (float*)&n;
//	printf("n��ֵΪ��%d\n", n);
//	printf("*pFloat��ֵΪ��%f\n", *pFloat);
//	*pFloat = 9.0;
//	printf("num��ֵΪ��%d\n", n);
//	printf("*pFloat��ֵΪ��%f\n", *pFloat);
//	return 0;
//}


///*����Ļ�ϴ�ӡ������ǡ�
//1
//1 1
//1 2 1
//1 3 3 1
//��*/��
//#include<stdio.h>
//#define ROW 100
//#define COL 100
//int main()
//{
//	int arr[ROW][COL] = {0};
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int j = 0;
//	//��ʼ��
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			if ( j == 0 || j == i)
//				arr[i][j] = 1;
//			else
//			arr[i][j] = 0;
//		}
//	}
//	//�������
//	for (i = 2; i < n; i++)
//	{
//		for (j = 1; j < n; j++)
//		{
//			if (j != 0 || j != i)
//			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//	//���
//	int k = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (k = 0; k < n-i-1; k++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < n; j++)
//		{
//			if (arr[i][j] != 0)
//			{
//			
//				printf("%d ", arr[i][j]);
//			}
//		}
//		printf("\n");
//	}
//
//	return 0;
//}



//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ��������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
#include<stdio.h>
//�������
int main()
{
	int a, b, c, d, e;
	for (a = 1; a <= 5; a++)
		for (b = 1; b <= 5; b++)
			for (c = 1; c <= 5; c++)
				for (d = 1; d <= 5; d++)
					for (e = 1; e <= 5; e++)					//��Ϊÿλѡ�ֶ�˵����һ�룬���Կ������߼���||��������ʾ
						if (((b != 2 && a == 3)|| (b == 2 && a != 3))
							&& ((b != 2 && e == 4)|| (b == 2 && e != 4))
							&& ((c != 1 && d == 2) || (c == 1 && d != 2))
							&& ((c != 5 && d == 3)  || (c == 5 && d != 3))
							&& ((e != 4 && a == 1)   || (e == 4 && a != 1)) == 1)
						{
							if (a * b * c * d * e == 120)			//��Ϊ1*2*3*4*5=120�����û������ж������ֶ��ֽ��
								printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
						}


	return 0;
}