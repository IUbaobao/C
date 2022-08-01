#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>



//链表的回文结构
//1->2->2->1
//返回：true
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
//    struct ListNode* mid = middleNode(A);//找中间节点
//    struct ListNode* cur2 = reverseList(mid);//从中间节点开始逆置
//    struct ListNode* cur1 = A;
//    while (cur2)//依次比较
//    {
//        if (cur1->val != cur2->val)
//            return false;
//        cur2 = cur2->next;
//        cur1 = cur1->next;
//    }
//
//    return true;
//}



//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//
//    struct ListNode* cur1 = headA, * cur2 = headB;
//    int count1 = 1, count2 = 1;
//    //找尾
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
//    //尾节点不相等则不相交
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
//    //让长的先走差距步
//    while (k--)
//    {
//        longList = longList->next;
//    }
//    //相等地方即为入口
//    while (longList != shotList)
//    {
//        longList = longList->next;
//        shotList = shotList->next;
//    }
//    return longList;
//
//}

//给你一个链表的头节点 head ，判断链表中是否有环。
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
//	printf("%s\n", __DATE__);//文件被编译的日期
//	printf("%d\n", __LINE__);//输入当前行号
//	return 0;
//}


//#define MAX 10000
//#define CASE break; case //在写case语句的时候自动把 break写上
//#define reg register //为 register这个关键字，创建一个简短的名字

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
		printf("%d\n", arr[i]);//为了观察数组是否赋值成功。
#endif //__DEBUG__
	}
	return 0;
}