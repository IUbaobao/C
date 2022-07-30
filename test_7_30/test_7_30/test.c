#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
 struct ListNode {
    int val;
    struct ListNode* next;

};

 struct ListNode* removeElements(struct ListNode* head, int val) {
     if (head == NULL)
         return NULL;

     struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));//设置一个新的头结点
     newNode->next = head;
     struct ListNode* cur = newNode;
     while (cur->next)
     {
         if ((cur->next)->val == val)//删val元素
         {
             struct ListNode* del = cur->next;
             cur->next = del->next;
             free(del);
         }
         else
         {
             cur = cur->next;
         }
     }
     cur = newNode->next;
     free(newNode);
     return cur;
 }
int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));

    n1->val = 1;
    n1->next = n2;
    n2->val = 2;
    n2->next = n3;
    n3->val = 6;
    n3->next = n4;
    n4->val = 3;
    n4->next = n5;
    n5->val = 4;
    n5->next = n6;
    n6->val = 5;
    n6->next = n7;
    n7->val = 6;
    n7->next = NULL;

    removeElements(n1, 6);
    return 0;
}


//反转链表
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* prev = head, * cur = head->next;
    prev->next = NULL;//先把第一个结点逆置成NULL
    while (cur)//迭代逆置
    {
        struct ListNode* tem = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tem;
    }
    return prev;
}