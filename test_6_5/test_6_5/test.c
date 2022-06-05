#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
typedef struct BTree	//树的节点
{
	char val;
	struct BTree* left;
	struct BTree* right;
}BTNode;

void BTreeDestroy(BTNode* root)//后序销毁树
{
	if (root == NULL)
		return;
	BTreeDestroy(root->left);
	BTreeDestroy(root->right);

	free(root);
	root = NULL;
}


BTNode* Create_tree(char* a, int* i) //以前序方式构建树
{
	if (a[*i] == '#')
	{
		++(*i);
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		printf("malloc fail！\n");
		exit(-1);
	}
	root->val = a[*i];
	++(*i);
	root->left = Create_tree(a, i);
	root->right = Create_tree(a, i);

	return root;
}

void InorderBT(BTNode* root)
{
	if (root == NULL)
		return;

	InorderBT(root->left);
	printf("%c ", root->val);
	InorderBT(root->right);
}

int main()
{
	char a[100] = { 0 };
	
	scanf("%s", a);
	int i = 0;
	BTNode* root= Create_tree(a, &i);//构建树

	printf("中序遍历：");
	InorderBT(root);//中序遍历

	BTreeDestroy(root);//销毁树
	root = NULL;
	return 0;
}


//
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//typedef struct BTree	//树的节点
//{
//	char val;
//	struct BTree* left;
//	struct BTree* right;
//}BTNode;
//
//void BTreeDestroy(BTNode* root)//后序销毁树
//{
//	if (root == NULL)
//		return;
//	BTreeDestroy(root->left);
//	BTreeDestroy(root->right);
//
//	free(root);
//	root = NULL;
//}
//
//
//BTNode* Create_tree(char* a, int* i) //以前序方式构建树
//{
//	if (a[*i] == '#')
//	{
//		++(*i);
//		return NULL;
//	}
//
//	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
//	if (root == NULL)
//	{
//		printf("malloc fail！\n");
//		exit(-1);
//	}
//	root->val = a[*i];
//	++(*i);
//	root->left = Create_tree(a, i);
//	root->right = Create_tree(a, i);
//
//	return root;
//}
//int BTtee_size(BTNode* root)//求树节点个数
//{
//	if (root == NULL)
//		return 0;
//
//	return BTtee_size(root->left) + BTtee_size(root->right) + 1;
//}
//
//int maxDepth(BTNode* root)//求二叉树最大深度
//{
//	if (root == NULL)
//		return 0;
//	int leftDepth = maxDepth(root->left);
//	int rightDepth = maxDepth(root->right);
//
//	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;//要大的那个
//}
//
//int BTLeaf(BTNode* root)//求二叉树的叶子节点个数
//{
//	if (root == NULL)
//		return 0;
//
//
//	if (root->left == NULL && root->right == NULL)
//		return 1;
//
//	return 	BTLeaf(root->left)+BTLeaf(root->right);
//}
//
//
//bool isBalanced(BTNode* root)//判断它是否是高度平衡的二叉树
//{
//	if (root == NULL)//空树默认平衡
//		return true;
//	//分别求左右子树最大深度
//	int leftDepth = maxDepth(root->left);	
//	int rightDepth = maxDepth(root->right);
//
//	return abs(leftDepth - rightDepth) < 2//左右子树高度差不超过2（abs求绝对值）
//		&& isBalanced(root->left)			//分别递归判断每个节点的高度差是否不超过2
//		&& isBalanced(root->right);
//}
//int main()
//{
//	char a[100] = { 0 };
//
//	scanf("%s", a);
//	int i = 0;
//	BTNode* root = Create_tree(a, &i);//构建树
//
//	int size = BTtee_size(root);
//	printf("该树的节点个数为：%d\n", size);
//
//	int depth = maxDepth(root);
//	printf("该数的最大深度为：%d\n", depth);
//
//	int Leafnodes = BTLeaf(root);
//	printf("该树的叶子节点个数为：%d\n", Leafnodes);
//
//	printf("该二叉树是否为平衡树(0为假，1为真)：%d \n", isBalanced(root));
//	
//	BTreeDestroy(root);//销毁树
//	root = NULL;
//	return 0;
//}










//消失的数字
//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
//注意：本题相对书上原题稍作改动
//示例 1：
//输入：[3, 0, 1]
//输出：2
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/missing-number-lcci
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



int missingNumber(int* nums, int numsSize) {

	//方法一：先把0-n个数全部加起来，减去数组的总数
	// int i=0;
	// int sum=0;
	// for(i=0;i<numsSize+1;i++)
	// {
	//     sum+=i;
	// }
	// for(i=0;i<numsSize;i++)
	// {
	//     sum-=nums[i];
	// }
	// return sum;

	//方法二：先跟0-n之间的数异或，然后再跟数组里的数异或
	int i = 0;
	int n = 0;
	for (i = 0; i < numsSize + 1; i++)
	{
		n ^= i;
	}
	for (i = 0; i < numsSize; i++)
	{
		n ^= nums[i];
	}
	return n;
}



//给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
//
//示例 1:
//输入: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
//输出 : [5, 6, 7, 1, 2, 3, 4]
//解释 :
//	向右轮转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//	向右轮转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//	向右轮转 3 步 : [5, 6, 7, 1, 2, 3, 4]
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode.cn/problems/rotate-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

void Reverse(int* a, int left, int right)
{
	while (left < right)
	{
		int tem = a[left];
		a[left] = a[right];
		a[right] = tem;
		right--;
		left++;
	}
}

void rotate(int* nums, int numsSize, int k) {

	if (k > numsSize)
	{
		k %= numsSize;
	}

	//先逆置前n-k个
	Reverse(nums, 0, numsSize - k - 1);
	//再逆置最后k个
	Reverse(nums, numsSize - k, numsSize - 1);
	//整体再逆置
	Reverse(nums, 0, numsSize - 1);
}