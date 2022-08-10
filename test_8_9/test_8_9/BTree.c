#define _CRT_SECURE_NO_WARNINGS



#include"BTree.h"






// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%c ", root->data);
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



BTNode* BinaryTreeCreate(BTDataType* a,  int* pi)
{
	if (a[*pi] == '\0')
	{
		return NULL;
	}
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->data = a[*pi];
	(*pi)++;
	root->left = BinaryTreeCreate(a, pi);
	root->right = BinaryTreeCreate(a, pi);
	return root;
}


BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;

	BTNode* leftX = BinaryTreeFind(root->left,x);
	BTNode* rightX = BinaryTreeFind(root->right,x);

	return leftX == NULL ? rightX : leftX;
}



int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right,k-1);
}


void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
		return;

	Queue q;
	QueueInit(&q);
	QueuePush(&q, *root);
	while (!QueueEmpty(&q))
	{

		BTNode cur = QueueFront(&q);
		if(cur.left!=NULL)
		QueuePush(&q, *(cur.left));
		if(cur.left!=NULL)
		QueuePush(&q, *(cur.right));
		QueuePop(&q);
		if(&cur!=NULL)
		printf("%c ", cur.data);
	}
}










































