#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
  struct Node 
  {
      int val;
     struct Node *next;
      struct Node *random;
 };
 

struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head, * next = head, * copy = NULL;
    //���ƽڵ�β�嵽ԭ�ڵ���
    while (cur)
    {
        next = cur->next;
        copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        cur->next = copy;
        copy->next = next;

        //����
        cur = next;
    }
    //����randam
    cur = head;
    while (cur)
    {
        copy = cur->next;
        next = cur->next->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        //����
        cur = next;
    }

    //�ָ�ԭ����
    struct Node* copyhead = NULL, * tail = NULL;
    cur = head;
    while (cur)
    {
        copy = cur->next;
        next = cur->next->next;
        if (copyhead == NULL)
        {
            copyhead = tail = copy;
        }
        else
        {
            tail->next = copy;
            tail = tail->next;
        }
        cur->next = next;
        //����
        cur = next;
    }
    return copyhead;
}


