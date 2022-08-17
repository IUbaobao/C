#define _CRT_SECURE_NO_WARNINGS




//#include<stdio.h>
//typedef int BTDataType;
//
//typedef struct BinaryTreeNode
//{
//	BTDataType data;
//	struct BinaryTreeNode* left;
//	struct BinaryTreeNode* right;
//}BTNode;
//
//
//// 二叉树前序遍历
//void PreOrder(BTNode* root)
//{
//	if (root == NULL)
//		return;
//
//	printf("%d ", root->data);
//	PreOrder(root->left);
//	PreOrder(root->right);
//}
//
//
//// 二叉树中序遍历
//void InOrder(BTNode* root)
//{
//	if (root == NULL)
//		return;
//
//
//	PreOrder(root->left);
//	printf("%d ", root->data);
//	PreOrder(root->right);
//	
//}
//// 二叉树后序遍历
//void PostOrder(BTNode* root)
//{
//	if (root == NULL)
//		return;
//
//
//	PreOrder(root->left);
//	PreOrder(root->right);
//	printf("%d ", root->data);
//}
//
//int main()
//{
//
//	return 0;
//}







//二叉树层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
		return;
	//层序遍历需要队列，C语言要自行实现
	//Queue q;  定义一个队列
	//QueueInit(&q);队列初始化
	//QueuePush(&q, root);把数中第一个元素入队列
	while (!QueueEmpty(&q))//队列不为空则继续
	{

		BTNode cur = QueueFront(&q);//取队列元素，随带把取出来的元素中的左右子树依次入队列
		if (cur.left != NULL)
			QueuePush(&q, cur.left);
		if (cur.left != NULL)
			QueuePush(&q, cur.right);
		QueuePop(&q);
		if (&cur != NULL)
			printf("%c ", cur.data);
	}
}