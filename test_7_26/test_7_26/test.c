#define _CRT_SECURE_NO_WARNINGS


//#include<stdio.h>
//
//int main()
//{
//
//	unsigned short x = 65530;
//	unsigned int y = x;
//	printf("%0x", y);
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int n = 1001;
//	int ans = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		ans ^= i % 3;
//	}
//	printf("%d", ans);
//	return 0;
//}

//����һ��������������������ַ�������ʽ�������
//���򲻿��Ǹ���������������ֺ���0����������ʽҲ����0��������Ϊ100�������Ϊ001
//
//
//���ݷ�Χ�� 0 \le n \le 2 ^ {30} - 1 \0��n��2
//30
//?1
//����������
//����һ��int����
//
//���������
//������������ַ�������ʽ�������
//
//ʾ��1
//���룺
//1516000
//����
//�����
//0006151

//#include<stdio.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    if (n == 0)
//        printf("%c\n", '0');
//    char arr[1000000];
//    int count = 0;
//    while (n)
//    {
//        arr[count++] = n % 10 + '0';
//        n /= 10;
//    }
//    printf("%s\n", arr);
//    return 0;
//}

//
//���ַ����е����е��ʽ��е��š�
//
//˵����
//
//1�����ɵ��ʵ��ַ�ֻ��26����д��СдӢ����ĸ��
//
//2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������
//
//3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո�������
//
//4��ÿ�������20����ĸ��
//
//���ݷ�Χ���ַ����������� 1 \le n \le 10000 \1��n��10000
//����������
//����һ�У���ʾ�������ŵľ���
//
//���������
//������ӵĵ��Ž��
//
//ʾ��1
//���룺
//I am a student
//�����
//student a am I
//#include<stdio.h>
//#include<string.h>
//void revese(char* a, int left, int right)
//{
//    while (left < right)
//    {
//        char tem = a[left];
//        a[left] = a[right];
//        a[right] = tem;
//        --right;
//        ++left;
//    }
//}
//
//int main()
//{
//    char arr[10001];
//    gets(arr);
//    int len = strlen(arr);
//    for (int i = 0; i < len; i++)
//    {
//        if ('A' <= arr[i] && arr[i] <= 'z')
//            continue;
//        else
//            arr[i] = ' ';  //�����ΪӢ���ַ����ַ�
//    }
//    revese(arr, 0, len - 1);//�Ȱ������ַ�������
//    int prev = 0;
//    for (int i = 0; i < len; i++)
//    {
//        if (arr[i] == ' ')
//        {
//            revese(arr, prev, i - 1);//�������������
//            prev = i + 1;
//        }
//    }
//    revese(arr, prev, len - 1); //�����һ����������
//    printf("%s\n", arr);
//    return 0;
//}



#include<stdio.h>

int main()
{
	//��д�ķ�ʽ��һ����ǰĿ¼�µ�test.txt�ļ�
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		printf("fopen fail\n");
		return 1;   //�ļ���ʧ���˳�����
	}
	//....���ļ�һϵ�в�����

	fclose(pf);//���ļ��ر�
	pf = NULL;
	return 0;
}