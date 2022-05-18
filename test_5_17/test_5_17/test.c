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




//#include <stdio.h>
//int main()
//{
//	int num1 = 1;
//	int num2 = 2;
//	int a=num1& num2;
//	int b=num1 | num2;
//	int c=num1^ num2;
//
//	printf("a=%d  b=%d  c=%d", a, c, b);
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int age = 26;	//初始化
//
//	age = 18;//赋值
//
//	printf("age=%d",age);
//
//	return 0;
//}




//#include<stdio.h>
//int main()
//{
//	int a = 1;
//	int b = 1;
//
//	a = a + 2;//等价于a+=2；
//	b += 2;  //等价于b=b+2；
//
//	printf("a=%d,b=%d\n", a, b);//结果一样
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//
//	int c = a++;	//a先赋值给c，所以c=0，然后a再自加1，a=1
//	int d = ++b;   //b先自加1，所以b=1，再赋值给d，所以d=1
//
//	printf("a=%d,b=%d\n", a, b);
//	printf("c=%d,d=%d\n", c, d);
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int i = 0, a = 0, b = 2, c = 3, d = 4;
//    i = a++ && ++b && d++;
//    //i = a++||++b||d++;
//    printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c, d);
//    return 0;
//}
////程序输出的结果是什么？

//
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	if (a == 1)		//判断相等用“==”
//	{
//		printf("hehe\n");
//	}
//	if (a = 1) //err错误写法
//	{
//		printf("哈哈\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("交换前a = %d b = %d\n", a, b);//
//	a = a ^ b;	// 其实就是a=10^20,先不用算结果
//	b = a ^ b;	//然后现在b=a^b=10^20^20,所以就变成b=10^0=10
//
//	a = a ^ b;	//这里就是a= 10 ^ 20 ^ b = 10 ^ 20 ^ 10
//				//用交换律就等于10 ^ 10 ^ 20 = 0 ^ 20 = 20
//	printf("交换后a = %d b = %d\n", a, b);//这样两个数就交换过来了
//	
//
//	return 0;
//}

//
//#include<stdio.h>
//int main()
//{
//	int a = 110;
//	if (100 < a < 200)  //错误写法
//	{
//		printf("haha\n");
//	}
//	if (a > 100 && a < 200)//正确写法
//	{
//		printf("hehe\n");
//	}
//	return 0;
//}
