#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h> 
//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));//1 6
//	return 0;
//}

//int main()
//{
//	int a[5] = { 5, 4, 3, 2, 1 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));//4 1
//	return 0;
//}

//
//���m��n�У�Ϊ����ת�ú�Ľ����ÿ����������һ���ո�
//���룺
//2 3
//1 2 3
//4 5 6
//
//�����
//1 4
//2 5
//3 6

//#include<stdio.h>
//
//int main()
//{
//    int n, m;
//    scanf("%d%d", &n, &m);
//    int max = n > m ? n : m;
//    int a[max][max];
//    int i = 0;
//    int j = 0;
//    //��ȡ����
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            scanf("%d", &a[i][j]);
//        }
//    }
//    int k1 = 0, k2 = 0;
//    int a1[max][max];
//    //��ʼ����
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            a1[k1++][k2] = a[i][j];
//        }
//        k1 = 0;
//        k2++;
//    }
//    //���
//    for (i = 0; i < m; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            printf("%d ", a1[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}


////�����Ǿ����ж�
//#include<stdio.h>
//
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    int a[n][n];
//    int i = 0, j = 0;
//    //��ȡ����
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            scanf("%d", &a[i][j]);
//        }
//    }
//
//    //�ж�
//    for (i = 0; i < n; i++)
//    {
//        for (j = i + 1; j < n; j++)
//        {
//            //�ж����Խ����µ�Ԫ���Ƿ�Ϊ0
//            if (a[j][i] != 0)
//            {
//                printf("NO\n");
//                return 0;
//            }
//        }
//    }
//    printf("YES\n");
//    return 0;
//}



//����һ���������У��ж��Ƿ����������У�����ָ�����е�������С����������ߴӴ�С����(��ͬԪ��Ҳ��Ϊ����)��
//���룺
//5
//1 6 9 22 30
//
//�����
//sorted
//#include<stdio.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int a[n];
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &a[i]);
//    }
//    int j = 2;
//    //Ԥ�ж������������ǽ���
//    if (a[0] > a[1])
//    {
//        //�ж��Ƿ�Ϊ����
//        for (i = 1; i < n - 1; i++)
//        {
//            if (a[i] < a[j])
//            {
//                printf("unsorted\n");
//                return 0;
//            }
//            j++;
//        }
//    }
//    else
//    {  //�ж��Ƿ�Ϊ����
//        for (i = 1; i < n - 1; i++)
//        {
//            if (a[i] > a[j])
//            {
//                printf("unsorted\n");
//                return 0;
//            }
//            j++;
//        }
//    }
//    printf("sorted\n");
//    return 0;
//