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
//	int age = 26;	//��ʼ��
//
//	age = 18;//��ֵ
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
//	a = a + 2;//�ȼ���a+=2��
//	b += 2;  //�ȼ���b=b+2��
//
//	printf("a=%d,b=%d\n", a, b);//���һ��
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//
//	int c = a++;	//a�ȸ�ֵ��c������c=0��Ȼ��a���Լ�1��a=1
//	int d = ++b;   //b���Լ�1������b=1���ٸ�ֵ��d������d=1
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
////��������Ľ����ʲô��

//
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	if (a == 1)		//�ж�����á�==��
//	{
//		printf("hehe\n");
//	}
//	if (a = 1) //err����д��
//	{
//		printf("����\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("����ǰa = %d b = %d\n", a, b);//
//	a = a ^ b;	// ��ʵ����a=10^20,�Ȳ�������
//	b = a ^ b;	//Ȼ������b=a^b=10^20^20,���Ծͱ��b=10^0=10
//
//	a = a ^ b;	//�������a= 10 ^ 20 ^ b = 10 ^ 20 ^ 10
//				//�ý����ɾ͵���10 ^ 10 ^ 20 = 0 ^ 20 = 20
//	printf("������a = %d b = %d\n", a, b);//�����������ͽ���������
//	
//
//	return 0;
//}

//
//#include<stdio.h>
//int main()
//{
//	int a = 110;
//	if (100 < a < 200)  //����д��
//	{
//		printf("haha\n");
//	}
//	if (a > 100 && a < 200)//��ȷд��
//	{
//		printf("hehe\n");
//	}
//	return 0;
//}
