#define _CRT_SECURE_NO_WARNINGS




//965. ��ֵ������
// ���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������
//ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��
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







//100. ��ͬ����
//�������ö������ĸ��ڵ� p �� q ����дһ���������������������Ƿ���ͬ��
//����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
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
//572. ��һ����������
//�������ö����� root �� subRoot ������ root ���Ƿ������ subRoot ������ͬ�ṹ�ͽڵ�ֵ��������������ڣ����� true �����򣬷��� false ��
//
//������ tree ��һ���������� tree ��ĳ���ڵ������ڵ�����к���ڵ㡣tree Ҳ���Կ����������һ��������
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