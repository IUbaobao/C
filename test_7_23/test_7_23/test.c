#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//int func(int x)
//{
//	int count = 0;
//	while (x)
//	{
//		count++;
//		x = x & (x - 1);//”Î‘ÀÀ„
//	} 
//		return count;
//}
//int main()
//{
//	printf("%d\n", func(-1));
//	return 0;
//}

#include<stdio.h>
#include<windows.h>
int main()
{
	int count = 0;
	//int x = -1;
	//while (x)
	//{
	//	count++;
	//	x = x >> 1;
	//	printf("%d", x);
	//	Sleep(200);
	//}
	int w = 1, x = 2, y = 3, z = 4;
	printf("%d", w < x ? w : y < z ? y : z);
	return 0;
}