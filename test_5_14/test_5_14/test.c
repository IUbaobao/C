#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//输入一个整数 n ，输出该数32位二进制表示中1的个数。其中负数用补码表示。
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
////输入两个整数，求两个整数二进制格式有多少个位不同
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
////喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。
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

//牛牛从键盘输入一个长度为 n 的数组，问你能否用这个数组组成一个链表，并顺序输出链表每个节点的值。
//输入描述：
//第一行输入一个正整数 n ，表示数组的长度
//输出描述：
//制作一个链表然后输出这个链表的值
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



//描述
//牛牛尝试把一个长度为 n 的数组转换成链表并把链表前两个节点交换位置和把链表最后两个节点交换位置。
//输入描述：
//第一行输入一个正整数 n 表示数组的长度
//第二行输入 n 个正整数，表示数组中各个元素的值
//输出描述：
//把数组转换成链表后输出交换位置后的链表
//示例1
//输入：
//4
//2 3 4 5
//复制
//输出：
//3 2 5 4
//复制
//示例2
//输入：
//3
//3 2 1
//复制
//输出：
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
// KMP算法
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
