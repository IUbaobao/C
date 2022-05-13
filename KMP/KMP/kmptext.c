#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
//void Getnext(char* Pstring,int* next,int len)
//{
//	assert(len >= 2);
//	next[0] = -1;
//	next[1] = 0;
//	int i = 2;
//	int k = 0;
//	while (i < len)
//	{
//		if (k==-1 || Pstring[i - 1] == Pstring[k])
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
//int KMP(char* Mstring, char* Pstring, int pos)
//{
//	int mlen = strlen(Mstring);
//	int plen = strlen(Pstring);
//	int i = pos;
//	int j = 0;
//	int* next = (int*)malloc(sizeof(int) * plen);
//	Getnext(Pstring,next,plen);
//
//	while (i <= mlen && j <= plen)
//	{
//		if ( j==-1 ||Mstring[i] == Pstring[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//	if (j > plen)
//		return i - j;
//
//	return -1;
//}
//
//void Getnext(int* next, char* mstring, int len)
//{
//	assert(len >= 2);
//	next[0] = -1;
//	next[1] = 0;
//	int i = 2;
//	int k = 0;
//	while (i < len)
//	{
//		if (k == -1 || mstring[i - 1] == mstring[k])
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
//int KMP(char* sum, char* mstring, int pos)
//{
//	assert(sum);
//	assert(mstring);
//	int slen = strlen(sum);
//	int mlen = strlen(mstring);
//
//	int* next = (int*)malloc(sizeof(int)*mlen);
//
//	assert(next);
//	Getnext(next, mstring, mlen);
//	int i = pos;
//	int j = 0;
//	while (i <= slen && j <= mlen)
//	{
//		if (j==-1 || sum[i] == mstring[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//	if (j > mlen)
//	{
//		return i - j;
//	}
//	return -1;
//}








int main()
{

	printf("%d ", KMP("abcdef", "cdef", 0));//2
	printf("%d ", KMP("adddddbcdef", "cdef", 0));//7
	printf("%d ", KMP("abcdef", "edef", 0));//-1


	return 0;
}