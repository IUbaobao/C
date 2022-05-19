#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hello bit\n");
//    }
//    return 0;
//}


//
////模拟实现库函数strlen
//#include<stdio.h>
//#include<assert.h>
//int my_strlen(const char* p)
//{
//	assert(p);
//	int count = 0;
//	while (*p != '\0')
//	{
//		count++;
//		p++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "hello xiaojin!";
//
//	int len=my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}
//
//
////模拟实现库函数strcpy
//#include<stdio.h>
//#include<assert.h>
//
//char* my_strcpy(char* dest, const char* soure)
//{
//	assert(soure);
//	assert(dest);
//	char* tem = dest;
//	while (*dest++ = *soure++)
//	{
//		;
//	}
//	return tem;
//}
//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "XXXXXXXXXXXXXXX";
//
//	printf("%s\n", my_strcpy(arr2, arr1));
//	return 0;
//}

//
//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。

#include<stdio.h>

void AdjustArr(int* p, int len)
{
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		//找出左边不为奇数的
		while (p[left] % 2 != 0 && left < right)
		{
			left++;
		}
		//找出右边不为偶数的
		while (p[right] % 2 == 0 && left < right)
		{
			right--;
		}
		//交换
		if (p[left] % 2 == 0 && p[right] % 2 != 0 && left < right)
		{
			int tem = p[left];
			p[left] = p[right];
			p[right] = tem;
		}
	}
}
int main()
{
	int arr[] = { 1,2,5,3,4,8,6,7,9,10,3,2,134,435,324,67,345 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	AdjustArr(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}