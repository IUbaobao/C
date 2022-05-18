#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
////插入排序
//void InsertSort(int* array, int n)
//{
//    int i = 0;
//    for (i = 0; i < n - 1; i++)
//    {
//        int end = i;
//        int tem = array[end + 1];
//
//        while (end >= 0)
//        {
//            if (array[end] > tem)
//            {
//                array[end + 1] = array[end];
//                end--;
//            }
//            else
//                break;
//        }
//        array[end + 1] = tem;
//    }
//
//}
////希尔排序
//void ShellSort(int* array, int n)
//{
//    int i = 0;
//    int gap = n;
//    while (gap > 1)
//    {
//        gap = gap / 3 + 1;
//        for (i = 0; i < n - gap; i++)
//        {
//            int end = i;
//            int tem = array[end + gap];
//
//            while (end >= 0)
//            {
//                if (array[end] > tem)
//                {
//                    array[end + gap] = array[end];
//                    end -= gap;
//                }
//                else
//                    break;
//            }
//            array[end + gap] = tem;
//        }
//    }
//
//}
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int arr[n];
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    ShellSort(arr, n);
//    for (i = 0; i < n; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}
// 
// 链表求和
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
//    for (int i = 0; i < n; i++)
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
//    list* cur = head->next;
//    int sum = 0;
//    while (cur != NULL)
//    {
//        sum += cur->data;
//        cur = cur->next;
//    }
//    printf("%d", sum);
//    ListDestroy(&head);
//    return 0;
//}

//数组求和
//#include<stdio.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int arr[n];
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    int sum = 0;
//    for (i = 0; i < n; i++)
//    {
//        sum += arr[i];
//    }
//    printf("%d", sum);
//    return 0;
//}

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
void Getnext(int* next, char* string, int len)
{
	assert(len >= 2);
	next[0] = -1;
	next[1] = 0;

	int i = 2;
	int k = 0;

	while (i < len)
	{
		if (k == -1 || string[i - 1] == string[k])
		{
			next[i] = k + 1;
			k++;
			i++;
		}
		else
			k = next[k];
	}


}
int KMP(char* sstring, char* mstring, int pos)
{
	assert(sstring);
	assert(mstring);
	assert(pos >= 0);

	int i = pos;
	int j = 0;
	int slen = strlen(sstring);
	int mlen = strlen(mstring);

	int* next = (int*)malloc(sizeof(int) * mlen);
	assert(next);
	Getnext(next, mstring, mlen);

	while (j < mlen && i < slen)
	{
		if (j == -1 || sstring[i] == mstring[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j >= mlen)
		return i - j;
	return -1;
}

int main()
{
	printf("%d ", KMP("afssdafddfffdsfasdghgsdgdg", "ffds", 0));//10
	printf("%d ", KMP("afssdafddfffdsfasdhgsdgdg", "fsdffds", 0));//-1
	printf("%d ", KMP("afssdafddfffdsfasdghgsdgdg", "afss", 0));//0
	return 0;
}