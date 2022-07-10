#define _CRT_SECURE_NO_WARNINGS

/*左旋字符串*/
//#include<stdio.h>
//#include<assert.h>
//#include<string.h>
//void reverse(char* p,int left,int right)
//{
//	assert(p);
//	while (left < right)
//	{
//		char tmp = p[left];
//		p[left] = p[right];
//		p[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//void left_revolve(char* p, int k)
//{
//	int len = strlen(p);
//	k %= len;
//	reverse(p, 0, k - 1);
//	reverse(p, k, len - 1);
//	reverse(p, 0, len - 1);
//
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	int k = 0;
//	scanf("%d", &k);
//	left_revolve(arr1, k);
//
//	printf("%s\n", arr1);
//	return 0;
//}



/*判断一个字符串是否为另一个左旋得来的*/
#include<stdio.h>
#include<assert.h>
#include<string.h>

int is_left_revolve(char* p1, char* p2)
{
	assert(p1 && p2);
	int len1 = strlen(p1);
	int len2 = strlen(p2);
	if (len1 == len2)//字符串相等的情况下才能算
	{
		strncat(p1, p1, strlen(p1));//先把p1全部左旋的结果表示在它的子串中
		char* ret = strstr(p1, p2);//再通过字符串查找判断是否存在这样的子串
		if (ret == NULL)
			return 0;
		else
			return 1;
	}
	else
		return 0;
}

int main()
{
	char arr1[20] = "abcdef";
	char arr2[] = "cdefab";

	int ret=is_left_revolve(arr1, arr2);
	if (ret == 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}



