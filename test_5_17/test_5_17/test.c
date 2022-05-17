#define _CRT_SECURE_NO_WARNINGS



//#include<stdio.h>
//int main()
//{
//	int a = -4;
//	a=a >> 1;
//	printf("%d ", a);
//	return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<string.h>
//
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
//
//
//}
//int KMP(char* sstring, char* mstring, int pos)
//{
//	assert(pos >= 0);
//	if (sstring == NULL || mstring == NULL)
//		return -1;
//
//	int slen = strlen(sstring);
//	int mlen = strlen(mstring);
//	int* next = (int*)malloc(sizeof(int) * mlen);
//	assert(next);
//
//	Getnext(next, mstring, mlen);
//
//	int j = 0;
//	int i = pos;
//	while (i < slen && j < mlen)
//	{
//		if (j == -1 || sstring[i] == mstring[j])
//		{
//			i++;
//			j++;
//		}
//		else
//			j = next[j];
//	}
//	if (j >= mlen)
//	{
//		return i - j;
//	}
//	return -1;
//
//}
//int main()
//{
//	printf("%d ", KMP("acgsfsfdghdfgsdfgf", "gsf", 0));//2
//}