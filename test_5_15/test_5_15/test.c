#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
////≤Â»Î≈≈–Ú
//void InsertSort(int* arr, int n)
//{
//	int i = 0;
//	for (i = 0; i < n - 1; i++)
//	{
//		int end=i;
//		int tem = arr[end + 1];
//		while (end >= 0)
//		{
//			if (arr[end] > tem)
//			{
//				arr[end + 1] = arr[end];
//				end--;
//			}
//			else
//			{
//				break;
//			}
//		}
//		arr[end+1] = tem;
//	}
//
//}
////œ£∂˚≈≈–Ú
//void ShellSort(int* arr, int n)
//{
//	int i = 0;
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//
//		for (i = 0; i < n - gap; i++)
//		{
//			int end = i;
//			int tem = arr[end + gap];
//			while (end >= 0)
//			{
//				if (arr[end] > tem)
//				{
//					arr[end + gap] = arr[end];
//					end=end-gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			arr[end + gap] = tem;
//		}
//
//	}
//	
//}
//void Print(int* arr, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	/*int arr[] = { 5,3,2,1,0,6,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);*/
//	srand((unsigned int)time(NULL));
//	int n = 100000;
//	int* parr1 = (int*)malloc(sizeof(int) * n);
//	int* parr2 = (int*)malloc(sizeof(int) * n);
//
//	
//	for (int i = 0; i < n; i++)
//	{
//		parr1[i] = rand()%10000;
//		parr2[i] = rand()%10000;
//	}
//
//
//	int begin = clock();
//	InsertSort(parr1, n);
//	int end = clock();
//	printf("%d \n", end - begin);
//
//	int a = clock;
//	ShellSort(parr2, n);
//	int b = clock();
//	printf("%d \n", b - a);
//	//Print(parr1, n);
//	free(parr1);
//	free(parr2);
//	
//	return 0;
//}


//
////KMPÀ„∑®
//void Getnext(int* next, char* string, int len)
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
//
//}
//
//int KMP(char* sstring, char* mstring, int pos)
//{
//	assert(pos >= 0);
//	if (sstring == NULL || mstring == NULL)
//		return -1;
//
//	int slen = strlen(sstring);
//	int mlen = strlen(mstring);
//	int i = pos;
//	int j = 0;
//
//	int* next = (int*)malloc(sizeof(int) * mlen);
//	if (next == NULL)
//		exit(-1);
//	Getnext(next, mstring, mlen);
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
//	if (j >= mlen)
//		return i - j;
//
//	return -1;
//}
//
//int main()
//{
//	printf("%d ", KMP("abcdefdsafasf", "fdsa", 0));//5
//	printf("%d ", KMP("abcdefdsafasf", "ffdfsa", 0));//-1
//	printf("%d ", KMP("abcdefdsafasf", "abcdef", 0));//0
//
//
//	return 0;
//}

void InsertSort(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int end = i;
		int tem = arr[end + 1];

		while (end >= 0)
		{
			if (arr[end] > tem)
			{
				arr[end + 1] = arr[end];
				--end;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tem;
	}
	

}

void ShellSort(int* arr, int sz)
{
	int i = 0;
	int gap = sz;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		
		for (i = 0; i < sz - 1; i++)
		{
			int end = i;
			int tem = arr[end + 1];

			while (end >= 0)
			{
				if (arr[end] > tem)
				{
					arr[end + 1] = arr[end];
					--end;
				}
				else
				{
					break;
				}
			}
			arr[end + 1] = tem;
		}
	}
	


}

int main()
{
	int arr[] = { 3,5,2,6,1,7,2,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	//InsertSort(arr, sz);
	ShellSort(arr, sz);

	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}