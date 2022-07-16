#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//#include<stdlib.h>
//
//int* find_single(int* a, int sz)
//{
//	int* ret = (int*)malloc(sizeof(int) * 2);
//	if (ret == NULL)
//	{
//		perror("malloc");
//		return NULL;
//	}
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int flag = 1;
//		for (j = 0; j < sz; j++)//一个一个比较
//		{
//			if (i != j && a[i] == a[j])
//				flag = 0;
//		}
//		if (flag == 1)//不同的放进数组中
//			ret[k++] = a[i];
//	}
//	return ret;
//}
//
//int main()
//{
//	int a[] = { 1,2,3,4,5,6,1,2,3,4 };
//	int* ret = find_single(a, sizeof(a) / sizeof(a[0]));
//	if(ret!=NULL)
//	printf("%d %d\n", ret[0], ret[1]);
//	free(ret);
//
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
////模拟实现strncpy
//
//
//char* my_strncpy(char* des, const char* src, int num)
//{
//	assert(des && src);
//	char* ret = des;
//	while (num--)
//	{
//		if (*src != '\0')
//			*des++ = *src++;
//		else
//			*des++ = '\0';
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "abcdef xxxxxxxxxxxxx";
//	char arr2[30];
//	my_strncpy(arr2, arr1, strlen(arr1)+1);
//	printf("%s\n", arr2);
//	return 0;
//}
//
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
////模拟实现strncat
//char* my_strncat(char* des, const char* src, int num)
//{
//	assert(des && src);
//	char* ret = des;
//	while (*des != '\0')
//	{
//		des++;
//	}
//	while (num-- && *src!='\0')
//	{
//		*des++ = *src++;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "world!";
//	my_strncat(arr1, arr2, 3);
//	printf("%s", arr1);
//	return 0;
//}

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<math.h>
//模拟实现atoi
int my_atoi(char* str)
{
	assert(str);
	int a[20] = { -1 };
	int i = 0;
	int ret = 0;
	//把每一个字符转成整数
	while (*str != '\0' )
	{
		if (*str >= 48 && *str <= 57)
		{
			a[i++] = *str - 48;
			str++;
		}
		else
			break;
	}
	//第一个字符不为数字
	if (a[0] == -1)
		return 0;
	int k = 0;
	//变成整数
	while (i--)
	{
		ret += a[k++] * (int)pow(10, i);
	}
	return ret;
}
int main()
{
	int i = 0;
	char arr[10];
	scanf("%s", arr);
	i = my_atoi(arr);
	printf("%d", i);
	return 0;
}

