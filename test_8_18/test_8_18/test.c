#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>

//int main()
//{
//	char arr[] = "hello world";
//	printf(arr);
//	return 0;
//

//typedef union
//{
//	int a;
//	struct
//	{
//		short b;
//		short c;
//	};
//}X;
//int main()
//{
//	X x;
//	x.a = 0x20150810;
//	printf("%x,%x\n", x.b, x.c);
//	return 0;
//}

int main()
{
	unsigned char i = 7;
	int j = 0;
	for (; i > 0; i -= 3)
	{
		++j;
	}
	printf("%d\n", j);
	return 0;
}