#define _CRT_SECURE_NO_WARNINGS



#include"BTree.h"






// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%d ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);

}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreePrevOrder(root->left);
	printf("%d ", root->data);
	BinaryTreePrevOrder(root->right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreePrevOrder(root->left);

	BinaryTreePrevOrder(root->right);
	printf("%d ", root->data);

}




int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}



int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);

}


void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
		return;

	BinaryTreeDestory(&(*root)->left);
	BinaryTreeDestory(&(*root)->right);
	free(*root);
	*root = NULL;
}



int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftdepth = BinaryTreeSize(root->left);
	int rightdepth = BinaryTreeSize(root->right);

	return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
}