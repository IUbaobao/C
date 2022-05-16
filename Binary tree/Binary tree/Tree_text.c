#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>

typedef char BTDatatype;
typedef struct BinaryTree
{
	struct BinaryTree* left;
	struct BinaryTree* right;
	BTDatatype data;
}BTNode;


int TreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
		return TreeSize(root->left) + TreeSize(root->right) + 1;
}


void Preatree(BTNode* root)
{
	if (NULL==root)
	{
		printf("NULL ");
		return;
	}

	
	Preatree(root->left);
	printf("%c ", root->data);
	Preatree(root->right);
	
}


int main()
{
	BTNode* a = (BTNode*)malloc(sizeof(BTNode));
	if (a == NULL)
		exit(-1);
	a->data = 'A';
	a->left = NULL;
	a->right = NULL;
	

	BTNode* b = (BTNode*)malloc(sizeof(BTNode));
	if (b == NULL)
		exit(-1);
	b->data = 'B';
	b->left = NULL;
	b->right = NULL;


	
	BTNode* c = (BTNode*)malloc(sizeof(BTNode));
	if (c == NULL)
		exit(-1);
	c->data = 'C';
	c->left = NULL;
	c->right = NULL;
	

	BTNode* d = (BTNode*)malloc(sizeof(BTNode));
	if (d == NULL)
		exit(-1);
	d->data = 'D';
	d->left = NULL;
	d->right = NULL;
	

	BTNode* g = (BTNode*)malloc(sizeof(BTNode));
	if (g == NULL)
		exit(-1);
	g->data = 'G';
	g->left = NULL;
	g->right = NULL;
	

	BTNode* f = (BTNode*)malloc(sizeof(BTNode));
	if (f == NULL)
		exit(-1);
	f->data = 'F';
	f->left = NULL;
	f->right = NULL;
	

	BTNode* t = (BTNode*)malloc(sizeof(BTNode));
	if (t == NULL)
		exit(-1);
	t->data = 'T';
	t->left = NULL;
	t->right = NULL;
	

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = f;
	d->left = g;
	c->right = t;

	//Preatree(a);
	printf("\n");
	int size = 0;
	size=TreeSize(a);
	printf("%d ",size);

	return 0;
}