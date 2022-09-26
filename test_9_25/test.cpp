#define _CRT_SECURE_NO_WARNINGS



//
//���Ϊ0��n - 1��n����Χ��һȦ���ӱ��Ϊ0���˿�ʼ����1��������ȥ������m�����뿪����������µ�һ���ˣ�����Ƕ��٣�
//
//
//�������� :
//����һ����������n��m��3��n��10 ^ 6, 1��m��1003��n��10
//6
//, 1��m��100��
//
//
//������� :
//������һ�����������˵ı�š�
//ʾ��1
//����
//8 3
//���
//6

#include<stdio.h>
struct pre
{
    int num;
    struct pre* next;
};

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);
    struct pre arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].num = i;
        if (i < n - 1)
            arr[i].next = &arr[i + 1];
    }
    arr[n - 1].next = &arr[0];//�γɻ�
    struct pre* p = &arr[0];
    int i = 0;
    while (p->next != p)
    {
        i++;
        if (i % (m - 1) == 0)
        {
            p->next = p->next->next;
            i = 0;
        }
        p = p->next;
    }
    printf("%d\n", p->num);

    return 0;
}






//�Գƶ�����
//
//bool _isSymmetric(struct TreeNode*left,struct TreeNode*right)
//{
//    if(left==NULL && right==NULL)
//        return true;
//    if(left==NULL || right==NULL)
//        return false;
//    if(left->val!=right->val)
//        return false;
//     
//     return  _isSymmetric(left->left,right->right)
//     && _isSymmetric(left->right,right->left);  
//}
//
//bool isSymmetric(struct TreeNode* root){
//    
//    return _isSymmetric(root->left,root->right);
//}





////��ͬ����
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)
//        return true;
//    if (p == NULL || q == NULL)
//        return false;
//    return p->val == q->val
//        && isSameTree(p->left, q->left)
//        && isSameTree(p->right, q->right);
//}



//��ֵ������
//bool isUnivalTree(struct TreeNode* root) {
//    if (root == NULL)
//        return true;
//    if (root->left != NULL && root->val != root->left->val)
//        return false;
//    if (root->right != NULL && root->val != root->right->val)
//        return false;
//
//    return isUnivalTree(root->left)
//        && isUnivalTree(root->right);
//}



//
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)
//        return true;
//    if (p == NULL || q == NULL)
//        return false;
//
//    if (p->val != q->val)
//        return false;
//
//    return isSameTree(p->left, q->left)
//        && isSameTree(p->right, q->right);
//}
//
//
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
//    if (root == NULL)
//        return false;
//    if (isSameTree(root, subRoot))
//        return true;
//
//    return  isSubtree(root->left, subRoot)
//        || isSubtree(root->right, subRoot);
//}


//ƽ�������
//int TreeDepth(struct TreeNode* root)
//{
//    if (root == NULL)
//        return 0;
//    int ld = TreeDepth(root->left);
//    int rd = TreeDepth(root->right);
//
//    return ld > rd ? ld + 1 : rd + 1;
//}
//
//bool isBalanced(struct TreeNode* root) {
//    if (root == NULL)
//        return true;
//
//    int ld = TreeDepth(root->left);
//    int rd = TreeDepth(root->right);
//
//    return abs(ld - rd) < 2
//        && isBalanced(root->left)
//        && isBalanced(root->right);
//}




//ɾ�������������ظ���Ԫ�� - I
//struct ListNode* deleteDuplicates(struct ListNode* head) {
//    // write code here
//    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
//    if (newhead == NULL)
//    {
//        perror("malloc fail\n");
//        return head;
//    }
//    newhead->next = head;
//    struct ListNode* p = newhead;
//    while (p != NULL)
//    {
//        if (p->next != NULL && p->val == p->next->val)
//        {
//            p->next = p->next->next;
//        }
//        else {
//            p = p->next;
//        }
//    }
//
//    p = newhead->next;
//    free(newhead);
//    return p;
//}



//ɾ�������������ظ���Ԫ�� - II (��д��)
//struct ListNode* deleteDuplicates(struct ListNode* head) {
//    // write code here
//    if (head == NULL || head->next == NULL)
//        return head;
//    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
//    if (newhead == NULL)
//    {
//        perror("malloc fail\n");
//        return head;
//    }
//    struct ListNode* p = newhead;
//    struct ListNode* cur = head;
//    int pre = -1000000;
//    while (cur != NULL)
//    {
//        printf("prev:%d cur->val:%d\n", pre, cur->val);
//        if ((cur->val != pre && cur->next != NULL && cur->val != cur->next->val) || (cur->next == NULL && cur->val != pre))
//        {
//            p->next = cur;
//            p = p->next;
//            pre = cur->val;
//            cur = cur->next;
//        }
//        else {
//            pre = cur->val;
//            cur = cur->next;
//        }
//
//    }
//    p->next = NULL;
//    p = newhead->next;
//    free(newhead);
//    return p;
//}