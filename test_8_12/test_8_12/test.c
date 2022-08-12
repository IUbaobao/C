#define _CRT_SECURE_NO_WARNINGS
//
//
//
//
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct BTNode
//{
//    struct BTNode* left;
//    struct BTNode* right;
//    char val;
//}node;
//
//node* BuildTree(char* a, int* i)
//{
//    if (a[*i] == '#')
//    {
//        (*i)++;
//        return NULL;
//    }
//    node* root = (node*)malloc(sizeof(node));
//    if (root == NULL)
//    {
//        printf("malloc file\n");
//        exit(-1);
//    }
//    root->val = a[*i];
//    (*i)++;
//    root->left = BuildTree(a, i);
//    root->right = BuildTree(a, i);
//    return root;
//}
//
//void InorderTree(node* root)
//{
//    if (root == NULL)
//        return;
//    InorderTree(root->left);
//    printf("%c ", root->val);
//    InorderTree(root->right);
//
//}
//int main()
//{
//
//    char a[101];
//    while (scanf("%s", a) != EOF)
//    {
//
//        int i = 0;
//        node* root = BuildTree(a, &i);
//
//        InorderTree(root);
//    }
//
//    return 0;
//}
//
//
//
////110. ƽ�������
//int isDepth(struct TreeNode* root)
//{
//    if (root == NULL)
//        return 0;
//
//    int ldepth = isDepth(root->left);
//    int rdepth = isDepth(root->right);
//    return  ldepth > rdepth ? ldepth + 1 : rdepth + 1;
//}
//
//
//bool isBalanced(struct TreeNode* root) {
//    if (root == NULL)
//        return true;
//
//    int ldepth = isDepth(root->left);
//    int rdepth = isDepth(root->right);
//
//    return abs(ldepth - rdepth) <= 1
//        && isBalanced(root->left)
//        && isBalanced(root->right);
//}
//
//
//
////965. ��ֵ������
//bool isUnivalTree(struct TreeNode* root) {
//    if (root == NULL)
//        return true;
//
//    if (root->left && root->left->val != root->val)
//        return false;
//    if (root->right && root->right->val != root->val)
//        return false;
//
//    return isUnivalTree(root->left)
//        && isUnivalTree(root->right);
//}
//
//
////104. ��������������
//
//int maxDepth(struct TreeNode* root) {
//    if (root == NULL)
//        return 0;
//
//    int leftDepth = maxDepth(root->left);
//    int rightDepth = maxDepth(root->right);
//
//    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
//}
//
//


//226. ��ת������
//struct TreeNode* invertTree(struct TreeNode* root) {
//    if (root == NULL)
//        return NULL;
//
//    struct TreeNode* tem = root->left;
//    root->left = root->right;
//    root->right = tem;
//    invertTree(root->left);
//    invertTree(root->right);
//
//    return root;
//}

//100. ��ͬ����

//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)
//        return true;
//
//    if (p == NULL || q == NULL)
//        return false;
//
//    return p->val == q->val
//        && isSameTree(p->left, q->left)
//        && isSameTree(p->right, q->right);
//}


//101. �Գƶ�����

//bool isSymmetric1(struct TreeNode* L, struct TreeNode* R)
//{
//    if (L == NULL && R == NULL)
//        return true;
//    if (L == NULL || R == NULL)
//        return false;
//
//    return L->val == R->val
//        && isSymmetric1(L->left, R->right)
//        && isSymmetric1(L->right, R->left);
//}
//bool isSymmetric(struct TreeNode* root) {
//
//    return  isSymmetric1(root->left, root->right);
//}

//572. ��һ����������


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
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
//    if (root == NULL)
//        return false;
//
//    if (isSameTree(root, subRoot))
//        return true;
//
//    return isSubtree(root->left, subRoot)
//        || isSubtree(root->right, subRoot);
//}
//
//110. ƽ�������
//
//int isDepth(struct TreeNode* root)
//{
//    if (root == NULL)
//        return 0;
//
//    int ldepth = isDepth(root->left);
//    int rdepth = isDepth(root->right);
//    return  ldepth > rdepth ? ldepth + 1 : rdepth + 1;
//}
//
//
//bool isBalanced(struct TreeNode* root) {
//    if (root == NULL)
//        return true;
//
//    int ldepth = isDepth(root->left);
//    int rdepth = isDepth(root->right);
//
//    return abs(ldepth - rdepth) <= 1
//        && isBalanced(root->left)
//        && isBalanced(root->right);
//}