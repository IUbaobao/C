#define _CRT_SECURE_NO_WARNINGS

//��������Ϸ
//#include<stdio.h>
//#include<time.h>//��ʼ�������Ҫ��ͷ�ļ�
//#include<stdlib.h>//���������Ҫ�õ�ͷ�ļ� 
////�˵�
//void menu()
//{
//	printf("*****************************************\n");
//	printf("***************0.�˳���Ϸ****************\n");
//	printf("***************1.��ʼ��Ϸ****************\n");
//	printf("*****************************************\n");
//
//}
////��Ϸʵ��
//void game()
//{
//	int put = rand() % 100 + 1;//�����ȡ1-100����
//	int b;
//	printf("���һ������>:");
//	while (1)
//	{
//		scanf("%d", &b); //�����û��������ֵ
//		 //��������Ƚϸ�����ʾ
//		if (b > put)
//			printf("�´���\n");
//		else if (b < put)
//			printf("��С��\n");
//		else//�¶Ծ��˳�ѭ��
//		{
//			printf("��ϲ�㣬�¶���\n");
//			break;
//		}
//}
//}
//int main()
//{
//	int  iput = 0;
//	srand((unsigned int)time(NULL)); //�������ʼ��
//	do
//	{
//		
//		menu();   //��ӡ�˵�
//		printf("��ѡ��>:");
//		scanf("%d", &iput);
//		switch(iput)
//		{
//			case 1:
//				game();
//				break;
//			case 0:
//				printf("�˳��ɹ�\n");
//				break;
//			default:
//				printf("�������������ѡ��\n");
//		}
//
//	} while (iput);
//	return 0;
//}




////��д������һ�� 1�� 100 �����������г��ֶ��ٸ�����9
//#include<stdio.h>
//
//int main()
//{
//	int i = 1;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 9 == 0 || (i>10&&(i / 10) % 9 == 0))
//		{
//			count++;
//		}
//	}
//	printf("%d\n ",count);
//	return 0;
//}


//����1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ���� + 1 / 99 - 1 / 100 ��ֵ����ӡ�����
//#include<stdio.h>
//
//int main()
//{
//	int i = 1;
//	double sum = 0.0;
//	int j = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += j*1.0 / i;
//		j = -j;
//	}
//	printf("%lf", sum);
//	return 0;
//}
//
//int main()
//{
//	int i = 1;
//	double sum = 0.0;
//	int j = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 1)
//		{
//			sum += 1.0 / i;
//		}
//		else
//			sum += -1 * 1.0 / i;
//	}
//	printf("%lf", sum);
//	return 0;
//}
//


//��10 �����������ֵ
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int max = arr[0];
//	for (i = 0; i < 10; i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d", max);
//	return 0;
//}
//



//// ����Ļ�����9 * 9�˷��ھ���
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%-d*%-d=%-d ",j,i ,i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//��д������һ���������������в��Ҿ����ĳ����
//Ҫ���ҵ��˾ʹ�ӡ�������ڵ��±꣬�Ҳ�����������Ҳ�����
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 5;
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0])-1;
//	while (left < right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("�ҵ��ˣ��±�Ϊ%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("�Ҳ���\n");
//	}
//	return 0;
//}