#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>



//����Ļ��Ľṹ
//1->2->2->1
//���أ�true
//struct ListNode* reverseList(struct ListNode* head) {
//
//    struct ListNode* n1 = NULL, * n2 = head;
//    while (n2)
//    {
//        struct ListNode* n3 = n2->next;
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//    }
//    return n1;
//}
//struct ListNode* middleNode(struct ListNode* head) {
//    struct ListNode* slow = head, * fast = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}
//bool chkPalindrome(ListNode* A) {
//    // write code here
//    struct ListNode* mid = middleNode(A);//���м�ڵ�
//    struct ListNode* cur2 = reverseList(mid);//���м�ڵ㿪ʼ����
//    struct ListNode* cur1 = A;
//    while (cur2)//���αȽ�
//    {
//        if (cur1->val != cur2->val)
//            return false;
//        cur2 = cur2->next;
//        cur1 = cur1->next;
//    }
//
//    return true;
//}



//���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣����������������ཻ�ڵ㣬���� null
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//
//    struct ListNode* cur1 = headA, * cur2 = headB;
//    int count1 = 1, count2 = 1;
//    //��β
//    while (cur1->next)
//    {
//        cur1 = cur1->next;
//        count1++;
//    }
//    while (cur2->next)
//    {
//        cur2 = cur2->next;
//        count2++;
//    }
//    //β�ڵ㲻������ཻ
//    if (cur1 != cur2)
//        return NULL;
//
//    struct ListNode* longList = headA, * shotList = headB;
//    if (count1 < count2)
//    {
//        longList = headB;
//        shotList = headA;
//    }
//    int k = abs(count1 - count2);
//    //�ó������߲�ಽ
//    while (k--)
//    {
//        longList = longList->next;
//    }
//    //��ȵط���Ϊ���
//    while (longList != shotList)
//    {
//        longList = longList->next;
//        shotList = shotList->next;
//    }
//    return longList;
//
//}

//����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���
//bool hasCycle(struct ListNode* head) {
//    struct ListNode* fast, * slow;
//    fast = slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (slow == fast)
//            return true;
//    }
//    return false;
//}



//
//#include<stdio.h>
//
//int main()
//{
//	printf("%s\n", __DATE__);//�ļ������������
//	printf("%d\n", __LINE__);//���뵱ǰ�к�
//	return 0;
//}


//#define MAX 10000
//#define CASE break; case //��дcase����ʱ���Զ��� breakд��
//#define reg register //Ϊ register����ؼ��֣�����һ����̵�����

//#define PRINT(FORMAT, VAL)\
//		printf("the value of " #VAL  "is " FORMAT "\n", VAL);
//#include<stdio.h>
//
//
//int main()
//{
//	int i = 10;
//
//	PRINT("%d", i + 6);
//	return 0;
//}



#include <stdio.h>
#define __DEBUG__
int main()
{
	int i = 0;
	int arr[10] = { 0 };
	for (i = 0; i < 10; i++)
	{
		arr[i] = i;
#ifdef __DEBUG__
		printf("%d\n", arr[i]);//Ϊ�˹۲������Ƿ�ֵ�ɹ���
#endif //__DEBUG__
	}
	return 0;
}