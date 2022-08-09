#define _CRT_SECURE_NO_WARNINGS



#include"BTree.h"


BTNode* CreateTree()
{
	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
	assert(n1);
	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
	assert(n2);
	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
	assert(n3);
	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
	assert(n4);
	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
	assert(n5);
	BTNode* n6 = (BTNode*)malloc(sizeof(BTNode));
	assert(n6);
	BTNode* n7 = (BTNode*)malloc(sizeof(BTNode));
	assert(n7);

	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n5->data = 5;
	n6->data = 6;

	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	n2->right = NULL;
	n4->left = n5;
	n4->right = n6;
	n3->left = NULL;
	n3->right = NULL;
	n5->left = NULL;
	n5->right = NULL;
	n6->left = NULL;
	n6->right = NULL;


	return n1;
}


int main()
{
	BTNode* root = CreateTree();
	//BinaryTreePrevOrder(root);
	//BinaryTreeInOrder(root);
	//BinaryTreePostOrder(root);
	int size=BinaryTreeSize(root);
	printf("%d\n", size);
	int leaf = BinaryTreeLeafSize(root);
	printf("%d\n", leaf);
	int depth = BinaryTreeDepth(root);
	printf("%d\n", depth);

	BinaryTreeDestory(&root);
	return 0;
}
