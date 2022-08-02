#define _CRT_SECURE_NO_WARNINGS




//给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。要求返回这个链表的深度拷贝
//struct Node* copyRandomList(struct Node* head) {
//    struct Node* copy = NULL, * cur = head, * next = NULL;
//    //复制
//    while (cur)
//    {   //尾插在原节点后面
//        copy = (struct Node*)malloc(sizeof(struct Node));
//        next = cur->next;
//        copy->val = cur->val;
//        cur->next = copy;
//        copy->next = next;
//
//        //迭代
//        cur = next;
//    }
//
//    cur = head;
//    //复制random
//    while (cur)
//    {
//        copy = cur->next;
//        next = cur->next->next;
//
//        if (cur->random == NULL)
//        {
//            copy->random = NULL;
//        }
//        else
//        {
//            copy->random = cur->random->next;
//        }
//
//        //迭代往后走
//        cur = next;
//    }
//
//    //取复制后的链表，重新连接原链表
//    struct Node* copyhead = NULL, * tail = NULL;
//    cur = head;
//    while (cur)
//    {
//        copy = cur->next;
//        next = cur->next->next;
//
//        if (copyhead == NULL)
//        {
//            tail = copyhead = copy;
//        }
//        else
//        {
//            tail->next = copy;
//            tail = tail->next;
//        }
//
//        //连接原链表
//        cur->next = next;
//        cur = next;
//    }
//
//    return copyhead;
//}
//
//
