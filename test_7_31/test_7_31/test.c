#define _CRT_SECURE_NO_WARNINGS


//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点
//struct ListNode* middleNode(struct ListNode* head) {
//    struct ListNode* slow = head, * fast = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}

//链表中倒数第k个结点
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//    // write code here
//    if (pListHead == NULL)
//        return NULL;
//    struct ListNode* fast = pListHead, * slow = pListHead;
//    while (k--)//先让fast走k步
//    {
//        if (fast == NULL)
//            return NULL;
//        fast = fast->next;
//    }
//    while (fast)
//    {
//        slow = slow->next;
//        fast = fast->next;
//    }
//    return slow;
//}

//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的

//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//
//    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));//哨兵位
//    newhead->next = NULL;
//    struct ListNode* cur1 = list1, * cur2 = list2, * tail = newhead;
//    while (cur1 && cur2)//取小尾插
//    {
//        if (cur1->val > cur2->val)
//        {
//            tail->next = cur2;
//            cur2 = cur2->next;
//        }
//        else
//        {
//            tail->next = cur1;
//            cur1 = cur1->next;
//        }
//        tail = tail->next;
//    }
//    if (cur1)//把剩下的连上
//    {
//        tail->next = cur1;
//    }
//    if (cur2)
//    {
//        tail->next = cur2;
//    }
//
//    tail = newhead->next;
//    free(newhead);
//    return tail;
//}

//链表分割
//现有一链表的头指针 ListNode* pHead，给一定值x，
//编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* partition(struct ListNode* pHead, int x) {
    // write code here
        //设置两个哨兵位,head1存比x大的，head2存比x小的进行尾插
    struct ListNode* head1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = pHead, * tail1 = head1, * tail2 = head2;
    while (cur)
    {
        if (cur->val < x)//取小的尾插到head2中
        {
            tail2->next = cur;
            tail2 = tail2->next;
        }
        else//取大的尾插到head1中
        {
            tail1->next = cur;
            tail1 = tail1->next;
        }
        cur = cur->next;
    }
    //将两部分连接，并将尾节点的next置空
    tail2->next = head1->next;
    tail1->next = NULL;
    cur = head2->next;
    free(head1);
    free(head2);

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

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = NULL;

    n1->val = 6;
    n2->val = 2;
    n3->val = 8;
    n4->val = 9;
    n5->val = 10;
    n6->val = 1;
    n7->val = 3;
    partition(n1, 9);
    return 0;
}