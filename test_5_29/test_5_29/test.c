#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

//KMP
//void GetNext(int* next, char* string, int len)
//{
//	assert(len >= 2);
//	next[0] = -1;
//	next[1] = 0;
//
//	int i = 2;
//	int k = 0;
//	while (i < len)
//	{
//		if (k == -1 || string[i - 1] == string[k])
//		{
//			next[i] = k + 1;
//			k++;
//			i++;
//		}
//		else
//		{
//			k = next[k];
//		}
//	}
//}
//
//
//
//int KMP(char* sstring, char* mstring, int pos)
//{
//	assert(mstring);
//	assert(sstring);
//	int mlen = strlen(mstring);
//	int slen = strlen(sstring);
//	int i = pos;
//	int j = 0;
//
//	int* next = (int*)malloc(sizeof(int) * mlen);
//	assert(next != NULL);
//
//	GetNext(next, mstring, mlen);
//
//	while (i < slen && j < mlen)
//	{
//		if (j == -1 || sstring[i] == mstring[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//	free(next);
//	if (j >= mlen)
//	{
//		return i - j;
//	}
//		return -1;
//}
//
//
//int main()
//{
//	printf("%d ", KMP("abcdefdsafasf", "fdsa", 0));//5
//	printf("%d ", KMP("abcdefdsafasf", "ffdfsa", 0));//-1
//	printf("%d ", KMP("abcdefdsafasf", "abcdef", 0));//0
//
//	return 0;
//}


//≤Â»Î≈≈–Ú
void InsertSort(int* a, int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int end = i;
		int tem = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tem)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end+1] = tem;
	}
}

//œ£∂˚≈≈–Ú
void ShellSort(int* a, int sz)
{
	int gap = sz;
	int i = 0;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		
		for (i = 0; i < sz - gap; i += gap)
		{
			int end = i;
			int tem = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tem)
				{
					a[end + gap] = a[end];
					end-= gap;
				}
				else
					break;
			}
			a[end + gap] = tem;
		}
	}
	
}
//øÏ≈≈
void QuickSort(int* a, int L, int R)
{
	if (L >= R)
		return;
	int left = L;
	int right = R;
	int point = a[left];
	while (left < right)
	{
		while (left<right && a[right]>=point)
		{
			right--;
		}
		if (left < right)
		{
			a[left++] = a[right];
		}
		while (left < right && a[left] <= point)
		{
			left++;
		}
		if (left < right)
		{
			a[right++] = a[left];
		}
	}
	a[left] = point;
	QuickSort(a, L, right - 1);
	QuickSort(a, left + 1, R);
}


int main()
{
	int arr[] = { 1,3,5,3,9,2,1,3,5,3,5,7,4,4,10 };

	int sz = sizeof(arr) / sizeof(arr[0]);
	//InsertSort(arr, sz);
	//ShellSort(arr, sz);
	QuickSort(arr, 0, sz - 1);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}