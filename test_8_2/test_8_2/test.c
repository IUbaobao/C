#define _CRT_SECURE_NO_WARNINGS




//����һ������Ϊ n ������ÿ���ڵ����һ���������ӵ����ָ�� random ����ָ�����ָ�������е��κνڵ��սڵ㡣
//����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣Ҫ�󷵻�����������ȿ���
//struct Node* copyRandomList(struct Node* head) {
//    struct Node* copy = NULL, * cur = head, * next = NULL;
//    //����
//    while (cur)
//    {   //β����ԭ�ڵ����
//        copy = (struct Node*)malloc(sizeof(struct Node));
//        next = cur->next;
//        copy->val = cur->val;
//        cur->next = copy;
//        copy->next = next;
//
//        //����
//        cur = next;
//    }
//
//    cur = head;
//    //����random
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
//        //����������
//        cur = next;
//    }
//
//    //ȡ���ƺ��������������ԭ����
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
//        //����ԭ����
//        cur->next = next;
//        cur = next;
//    }
//
//    return copyhead;
//}
//
//
