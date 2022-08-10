#define _CRT_SECURE_NO_WARNINGS




//965. 单值二叉树
// 如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
//只有给定的树是单值二叉树时，才返回 true；否则返回 false。
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







//100. 相同的树
//给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
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
//572. 另一棵树的子树
//给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。
//
//二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。
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