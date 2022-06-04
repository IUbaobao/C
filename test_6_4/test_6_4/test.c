#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//int main()
//{
//	int a = 0x00001234;
//	int b = 0x00001234;
//	int* pa = &a;
//	*pa = 1;
//
//	char* pb = (char*)&b;
//	*pb = 1;
//	*(pb + 1) = 0;
//	*(pb + 1) = 0;
//	*(pb + 1) = 0;
//
//
//	printf("a=%x,b=%x\n", a, b);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	const  char* p = "hello,My friend!";//是p里面存放了"hello,My friend!"吗？
//
//	printf("%s", p);
//
//	return 0;
//}

//
//#include <stdio.h>
//int main()
//{
//    char arr1[] = "hello,My friend!";
//    char arr2[] = "hello,My friend!";
//    const char* arr3 = "hello,My friend!";
//    const char* arr4 = "hello,My friend!";
//    if (arr1 == arr2)
//        printf("arr1 =arr2\n");
//    else
//        printf("arr1 != arr2 \n");
//
//    if (arr3 == arr4)
//        printf("arr3 = arr4 \n");
//    else
//        printf("arr3 != arr4 \n");
//
//    return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	int arr1[] = { a,b };	//整型数组
//
//	int* arr2[] = { &a,&b };//指针数组
//
//	printf("arr[0]=%p\n", arr2[0]);
//	printf("arr[1]=%p\n",arr2[1]);
//	return 0;
//}

//
//#include <stdio.h>
//int main()
//{
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//    int(*p)[10] = &arr;//把数组arr的地址赋值给数组指针变量p
//
//    //但是我们一般很少这样写代码 一个数组指针的比较笨的使用方法
//    int i = 0;
//    for (i; i < 10; i++)
//    {
//        printf("%d ", *((*p) + i)  );
//    }
//    printf("\n");
//    //上面的写法我们完全可以用一个整型指针来完成
//    int* parr = arr;
//    for (i = 0; i < 10; i++)
//    {
//        printf("%d ", *(parr + i));
//    }
//    return 0;
//}


//#include <stdio.h>
////以二维数组的形式接受地址
//void print_arr1(int arr[3][5], int row, int col)
//{
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < row; i++)
//    {
//        for (j = 0; j < col; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//
//    printf("\n");
//   }
//}
////以数组指针的形式接受地址
//void print_arr2(int(*arr)[5], int row, int col)
//{
//    int j = 0;
//    int i = 0;
//    for (i = 0; i < row; i++)
//    {
//        for (j = 0; j < col; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//}
//int main()
//{
//    int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
//    print_arr1(arr, 3, 5);
//    //数组名arr，表示首元素的地址
//    //但是二维数组的首元素是二维数组的第一行
//    //所以这里传递的arr，其实相当于第一行的地址，是一维数组的地址
//    //可以数组指针来接收
//    print_arr2(arr, 3, 5);
//    return 0;
//}


//
//
//#include <stdio.h>
//void test()
//{
//	printf("hehe\n");
//}
//int main()
//{
//	printf("%p\n", test);
//	printf("%p\n", &test);
//	return 0;
//}


//#include<stdio.h>
//
//int add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	void (*       signal(int, void(*)(int))             )(int);
//
//
//	int  add(int, int);
//
//
//
//	//add函数的地址如何存放
//	int (*pf1)(int, int) = &add;
//
//	int (*pf1[5])(int, int)
//	printf("%p ", pf1);
//	return 0;
//}
//
//
//#include<stdio.h>
//
//int add(int x, int y)
//{
//	return x + y;
//}
//int sum(int x, int y)
//{
//	return x - y;
//}
//int main()
//{
//	//先写函数指针
//	int (*pf)(int, int) = &add;
//
//	//再把函数指针copy过来，在变量名后加个[]
//	int (*pf1[5])(int, int) = { &add,&sum };
//
//	printf("pf=%p\npf1[0]=%p\npf1[1]=%p \n", pf, pf1[0], pf1[1]);
//
//	return 0;
//}

  

//描述
//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。
//输入描述：
//输入包括1行字符串，长度不超过100。
//输出描述：
//可能有多组测试数据，对于每组数据， 输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。 每个输出结果占一行。
//示例1
//输入：
//abc##de#g##f###
//复制
//输出：
//c b e g d f a

//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct TreeNode
//{
//    char val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//}TNode;
//
//TNode* ConstTree(char* a, int* i)
//{
//    if (a[*i] == '#')
//    {
//        ++(*i);
//        return NULL;
//    }
//    TNode* root = (TNode*)malloc(sizeof(TNode));
//    if (root == NULL)
//    {
//        printf("malloc fail\n");
//        exit(-1);
//    }
//    root->val = a[*i];
//    ++(*i);
//
//    root->left = ConstTree(a, i);
//    root->right = ConstTree(a, i);
//
//    return root;
//
//}
//
//void Inorder(TNode* root)
//{
//    if (root == NULL)
//        return;
//    Inorder(root->left);
//    printf("%c ", root->val);
//    Inorder(root->right);
//}
//int main()
//{
//    char arr[100];
//    while (scanf("%s", arr) != EOF)
//    {
//        int i = 0;
//        TNode* root = ConstTree(arr, &i);
//
//        Inorder(root);
//    }
//
//
//    return 0;
//}
//
//
//给定一个二叉树，找出其最大深度。
//
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//
//说明 : 叶子节点是指没有子节点的节点。
//
//示例：
//给定二叉树[3, 9, 20, null, null, 15, 7]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/maximum-depth-of-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//int maxDepth(struct TreeNode* root) {
//
//    if (root == NULL)
//        return 0;
//
//    int Tleft = maxDepth(root->left);
//    int Tright = maxDepth(root->right);
//
//    return Tleft > Tright ? Tleft + 1 : Tright + 1;
//
//}
//
//
// 给定一个二叉树，判断它是否是高度平衡的二叉树。

//bool isBalanced(struct TreeNode* root) {
//
//    if (root == NULL)
//        return true;
//
//    int  rootLeft = maxDepth(root->left);
//    int  rootright = maxDepth(root->right);
//
//
//    return  abs(rootLeft - rootright) < 2
//        && isBalanced(root->left)
//        && isBalanced(root->right);
//
//}
//


