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
    //复制节点尾插到原节点中
    while (cur)
    {
        next = cur->next;
        copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        cur->next = copy;
        copy->next = next;

        //迭代
        cur = next;
    }
    //复制randam
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
        //迭代
        cur = next;
    }

    //恢复原链表
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
        //迭代
        cur = next;
    }
    return copyhead;
}


