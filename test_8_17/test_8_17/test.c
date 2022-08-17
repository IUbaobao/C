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
//// ������ǰ�����
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
//// �������������
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
//// �������������
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







//�������������
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
		return;
	//���������Ҫ���У�C����Ҫ����ʵ��
	//Queue q;  ����һ������
	//QueueInit(&q);���г�ʼ��
	//QueuePush(&q, root);�����е�һ��Ԫ�������
	while (!QueueEmpty(&q))//���в�Ϊ�������
	{

		BTNode cur = QueueFront(&q);//ȡ����Ԫ�أ������ȡ������Ԫ���е������������������
		if (cur.left != NULL)
			QueuePush(&q, cur.left);
		if (cur.left != NULL)
			QueuePush(&q, cur.right);
		QueuePop(&q);
		if (&cur != NULL)
			printf("%c ", cur.data);
	}
}