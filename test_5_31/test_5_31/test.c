#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>


//文件操作测试
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//		if (pf == NULL)
//		{
//			exit(-1);
//		}
//		char arr[20];
//		scanf("%s", arr);
//		fputs(arr, pf);
//		char arr1[20];
//
//
//		fclose(pf);
//		pf = NULL;
//		pf = fopen("test.txt", "r");
//		if (pf == NULL)
//		{
//			exit(-1);
//		}
//		fgets(arr, 20, pf);
//		printf("%s", arr1);
//
//	return 0;
//}


//实现一个函数，可以左旋字符串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
////ABCD左旋两个字符得到CDAB
//#include<string.h>
//#include<assert.h>
//#include<stdlib.h>
//#include<stdio.h>
//void Adjust(char* arr, int len, int k)
//{
//	assert(len >= k);
//	int i = 0;
//	char* a = (char*)malloc(sizeof(char) * len);
//	//先把要左旋的字符存在一个临时数组
//	for (i = 0; i < k; i++)
//	{
//		a[i] = arr[i];
//	}
//	//把不用左旋的字符往前移
//	for (i = 0; i < len-k; i++)
//	{
//		arr[i] = arr[i + k];
//	}
//	int j = 0;
//	//把要左旋的字符放回
//	for (i; i < len; i++)
//	{
//		arr[i] = a[j];
//		j++;
//	}
//	free(a);
//	a = NULL;
//}
//
//int main()
//{
//	char arr1[] = "ABCD";
//	int k = 0;
//	int len = strlen(arr1);
//	scanf("%d", &k);
//	Adjust(arr1, len,k);
//	printf("%s", arr1);
//	return 0;
//}

#include<stdio.h>
#include<string.h>
#include<assert.h>
void Getnext(int* next, char* string, int len)
{
	assert(len >= 2);
	next[0] = -1;
	next[1] = 0;

	int i = 2;
	int k = 0;
	while (i < len)
	{
		if (k == -1 || string[i - 1] == string[k])
		{
			next[i] = k + 1;
			k++;
			i++;
		}
		else
			k = next[k];
	}
}

int KMP(char* sstring, char* mstring, int pos)
{
	assert(sstring);
	assert(mstring);
	int i = pos;
	int j = 0;

	int slen = strlen(sstring);
	int mlen = strlen(mstring);

	int* next = (int*)malloc(sizeof(int) * mlen);
	assert(next);
	Getnext(next, mstring, mlen);

	while (i < slen && j < mlen)
	{
		if (j == -1 || sstring[i] == mstring[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j >= mlen)
	{
		return i - j;
	}
	return -1;
}
int main()
{
	printf("%d ", KMP("acaffsdfsfss", "caff", 0));//1
	printf("%d ", KMP("acaffsdfsfss", "cfffaff", 0));//-1
	printf("%d ", KMP("acaffsdfsfss", "fss", 0));//9


	return 0;
}