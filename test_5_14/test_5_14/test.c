#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//����һ������ n ���������32λ�����Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
//int NumberOf1(int n) {
//    // write code here
//    int i = 0;
//    int p = 1;
//    int count = 0;
//    for (i = 0; i < 32; i++)
//    {
//        if ((n & p) == 1)
//        {
//            count++;
//        }
//        n >>= 1;
//    }
//    return count;
//}

//int NumberOf1(unsigned int n)
//{
//    int count = 0;
//    while (n)
//    {
//        if (n % 2 == 1)
//        {
//            count++;
//         }
//        n /= 2;
//    }
//    return count;
//}

//int NumberOf1(int n)
//{
//    int count = 0;
//    while (n)
//    {
//        n = n & (n - 1);
//        count++;
//    }
//    return count;
//}
//
//int main()
//{
//    int num = 0;
//    scanf("%d", &num);
////   int  ret = NumberOf1(num);
////   printf("%d ", ret);
////}
//
////�����������������������������Ƹ�ʽ�ж��ٸ�λ��ͬ
//int main()
//{
//    int m = 0;
//    int n = 0;
//    int p = 0;
//    int count = 0;
//    scanf("%d %d", &m, &n);
//    
//        p = m ^ n;
//        while (p)
//        {
//            p = p & (p - 1);
//            count++;
//
//        }
//        printf("%d", count);
//
//  
//    return 0;
//}

//
//
////����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֣���
//int main()
//{
//	int m = 20;
//	//scanf("%d", &m);
//	int k = m;
//	int s = 0;
//	int sum = m;
//	while (k!=1)
//	{
//		sum += k / 2;
//		s = k % 2;
//		k = k/ 2;
//		k = s + k;
//	}
//	printf("%d", sum);
//	return 0;
//}

//ţţ�Ӽ�������һ������Ϊ n �����飬�����ܷ�������������һ��������˳���������ÿ���ڵ��ֵ��
//����������
//��һ������һ�������� n ����ʾ����ĳ���
//���������
//����һ������Ȼ�������������ֵ
//

//
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct List
//{
//    int data;
//    struct List* next;
//}list;
//
//void ListDestroy(list** head)
//{
//    list* cur = *head;
//    while (cur != NULL)
//    {
//        list* next = cur->next;
//        free(cur);
//        cur = next;
//    }
//    *head = NULL;
//}
//
//
//list* BuyNode(int x)
//{
//    list* new = (list*)malloc(sizeof(list));
//    new->data = x;
//    new->next = NULL;
//    return new;
//}
//list* ListInit(int* arr, int n)
//{
//    list* phead = BuyNode(arr[0]);
//    list* tail = phead;
//
//    for (int i = 1; i < n; i++)
//    {
//        list* new = BuyNode(arr[i]);
//        while (tail->next != NULL)
//        {
//            tail = tail->next;
//        }
//        tail->next = new;
//    }
//    return phead;
//}
//int main()
//{
//    int n = 3;
//    scanf("%d", &n);
//    int arr[n];
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    list* head = ListInit(arr, n);
//    list* cur = head;
//
//    while (cur != NULL)
//    {
//        printf("%d ", cur->data);
//        cur = cur->next;
//    }
//    ListDestroy(&head);
//    return 0;
//}
//
//



//����
//ţţ���԰�һ������Ϊ n ������ת��������������ǰ�����ڵ㽻��λ�úͰ�������������ڵ㽻��λ�á�
//����������
//��һ������һ�������� n ��ʾ����ĳ���
//�ڶ������� n ������������ʾ�����и���Ԫ�ص�ֵ
//���������
//������ת����������������λ�ú������
//ʾ��1
//���룺
//4
//2 3 4 5
//����
//�����
//3 2 5 4
//����
//ʾ��2
//���룺
//3
//3 2 1
//����
//�����
//2 1 3

//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//typedef struct List
//{
//    int data;
//    struct List* next;
//}list;
//
//void ListDestroy(list** head)
//{
//    list* cur = *head;
//    while (cur != NULL)
//    {
//        list* next = cur->next;
//        free(cur);
//        cur = next;
//    }
//    *head = NULL;
//}
//
//
//list* BuyNode(int x)
//{
//    list* new = (list*)malloc(sizeof(list));
//    if (new == NULL)
//        exit(-1);
//    new->data = x;
//    new->next = NULL;
//    return new;
//}
//list* ListInit(int* arr, int n)
//{
//    list* phead = BuyNode(arr[0]);
//    list* tail = phead;
//
//    for (int i = 1; i < n; i++)
//    {
//        list* new = BuyNode(arr[i]);
//        while (tail->next != NULL)
//        {
//            tail = tail->next;
//        }
//        tail->next = new;
//    }
//    return phead;
//}
//
//list* Listchange(list* phead)
//{
//    assert(phead);
//    list* curPrev = phead;
//    list* cur = curPrev->next;
//    list* tailPrev = phead;
//    list* tailPrev2 = phead;
//    list* tail = phead;
//    while (tailPrev->next->next != NULL)
//    {
//        tailPrev = tailPrev->next;
//    }
//    tail = tailPrev->next;
//    while (tailPrev2->next != tailPrev)
//    {
//        tailPrev2 = tailPrev2->next;
//    }
//    curPrev->next = cur->next;
//    cur->next = curPrev;
//    phead = cur;
//    if (cur != tailPrev)
//        tailPrev->next = tail->next;
//         
//    else
//        tailPrev->next = tail;
//
//    if (cur != tailPrev)
//        tail->next = tailPrev;
//
//    else
//        tail->next = tailPrev2;
//    
//    if (tailPrev2 != cur)
//        tailPrev2->next = tail;
//
//    else
//        curPrev->next = tail;
//
//    if (curPrev == tailPrev2)
//        tailPrev2->next = NULL;
//
//
//    return phead;
//}
//
//int main()
//{
//    int n = 3;
//   // scanf("%d", &n);
//    int arr[3];
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    list* head = ListInit(arr, n);
//    head = Listchange(head);
//    list* cur = head;
//
//    while (cur != NULL)
//    {
//        printf("%d ", cur->data);
//        cur = cur->next;
//    }
//    ListDestroy(&head);
//    return 0;
//}
//
//
//
//
//
// 
// KMP�㷨
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<string.h>
//
//void Getnext(int* next, char* string, int len)
//{
//	assert(len >= 2);
//	next[0] = -1;
//	next[1] = 0;
//
//	int i = 2;
//	int k = 0;
//	while (i < len)
//	{
//		if (k == -1 || string[i - 1] == string[k])
//		{
//			next[i] = k + 1;
//			i++;
//			k++;
//		}
//		else
//		{
//			k=next[k];
//		}
//
//
//	}
//
//}
//int  KMP(char* sstring, char* mstring, int pos)
//{
//	assert(pos >= 0);
//
//	int slen = strlen(sstring);
//	int mlen = strlen(mstring);
//	int i = pos;
//	int j = 0;
//
//	int* next = (int*)malloc(sizeof(int) * mlen);
//	assert(next);
//	Getnext(next, mstring, mlen);
//	while (i < slen && j < mlen)
//	{
//		if (j == -1 || sstring[i] == mstring[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//	if (j >= mlen)
//	{
//		return i - j;
//	}
//	return -1;
//
//}
//int main()
//{
//	printf("%d ", KMP("abcdbacdf", "cdb", 0));//2
//	printf("%d ", KMP("abcdbacdf", "cdf", 0));//6
//	printf("%d ", KMP("abcdbacdf", "eio", 0));//-1
//
//	return 0;
//}
