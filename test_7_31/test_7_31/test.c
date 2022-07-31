#define _CRT_SECURE_NO_WARNINGS


//����һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ����м���
//struct ListNode* middleNode(struct ListNode* head) {
//    struct ListNode* slow = head, * fast = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}

//�����е�����k�����
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//    // write code here
//    if (pListHead == NULL)
//        return NULL;
//    struct ListNode* fast = pListHead, * slow = pListHead;
//    while (k--)//����fast��k��
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

//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�

//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//
//    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));//�ڱ�λ
//    newhead->next = NULL;
//    struct ListNode* cur1 = list1, * cur2 = list2, * tail = newhead;
//    while (cur1 && cur2)//ȡСβ��
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
//    if (cur1)//��ʣ�µ�����
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

//����ָ�
//����һ�����ͷָ�� ListNode* pHead����һ��ֵx��
//��дһ�δ��뽫����С��x�Ľ������������֮ǰ���Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* partition(struct ListNode* pHead, int x) {
    // write code here
        //���������ڱ�λ,head1���x��ģ�head2���xС�Ľ���β��
    struct ListNode* head1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = pHead, * tail1 = head1, * tail2 = head2;
    while (cur)
    {
        if (cur->val < x)//ȡС��β�嵽head2��
        {
            tail2->next = cur;
            tail2 = tail2->next;
        }
        else//ȡ���β�嵽head1��
        {
            tail1->next = cur;
            tail1 = tail1->next;
        }
        cur = cur->next;
    }
    //�����������ӣ�����β�ڵ��next�ÿ�
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