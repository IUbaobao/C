#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//int main()
//{
//    //union
//    //{
//    //    short k;
//    //    char i[2];
//    //}*s, a;
//    //s = &a;
//    //s->i[0] = 0x39;
//    //s->i[1] = 0x38;
//    //printf("%x\n",a.k);
//
//    enum ENUM_A
//    {
//        X1,
//        Y1,
//        Z1 = 255,
//        A1,
//        B1,
//    };
//    enum ENUM_A enumA = Y1;
//    enum ENUM_A enumB = B1;
//    printf("%d %d\n", enumA, enumB);
//
//        return 0;
//}

#include<stdio.h>
#include<string.h>
#include<assert.h>
//int my_strlen(const char* str)
//{
//	assert(str);
//	int count = 0;
//	while (*str++)
//	{
//		count++;
//	}
//	return count;
//}

//
//int my_strlen(const char* str)
//{
//	if (*str == '\0')
//		return 0;
//
//	return 1 + my_strlen(str + 1);
//}
//
//size_t my_strlen(const char* str)
//{
//	assert(str);
//	char* end = (char*)str;
//	while (*end!='\0')
//	{
//		end++;
//	};
//	return end - str;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//int my_strcmp(const char* src, const char* des)
//{
//	assert(src && des);
//	while (*src == *des)
//	{
//		if (*src == '\0')//����ͬʱ����\0�����ʾ�����ַ����������
//			return 0;
//		src++;
//		des++;
//	}
//	return *src - *des;//�������˵�������Ѿ���ʼ������ˣ����Ӧ���ַ��������
//}
//
//int main()
//{
//	char a[] = "abcdef";
//	char b[] = "abcdef";
//	if (strcmp(a, b) == 0)
//		printf("a==b\n");
//	else
//		printf("a!=b\n");
//
//	//char a[] = "abc";
//	//char b[] = "abf";
//	//int ret = my_strcmp(a, b);
//	//printf("%d", ret);
//	return 0;
//}





//char* my_strcpy( char* des ,const char* src)
//{
//	assert(des && src);
//	char* ret = des;//�ȱ���Ŀ���ַ����ʼλ��
//	while (*des++ = *src++)//���п���
//	{
//		;
//	}
//	return ret;
//}
//
//char* my_strcpy(char* des, const char* src)
//{
//	assert(des && src);
//	char* ret = des;//�ȱ���Ŀ���ַ����ʼλ��
//	while (*src!='\0')//���п���
//	{
//		*des = *src;
//		des++;
//		src++;
//	}
//	*des = '\0';//��\0����
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[20];
//	my_strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}


//char* my_strcat(char* des, const char* src)
//{
//	assert(des && src);
//	char* ret = des;//��¼Ŀ���ַ�������ʼλ��
//	char* end = des;//���ڼ�¼Ŀ���ַ�����β��ַ
//	while (*end)//�ҵ�β��ַ
//	{
//		end++;
//	}
//	while (*end++ = *src++)//��ʼ׷��(���������strcpy)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "world!";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	char* s1 = (char*)str1;
//	char* s2 = (char*)str2;
//	char* p1 = (char*)str1;//�����һ��Ѿ��ȽϹ����ַ�����һ��
//	while (*s1)//ȷ��s1û�е�β
//	{
//		while (*s1 == *s2 && *s1!='\0' && *s2!='\0')//�����������Ϊ����������������±Ƚ�
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')//���s2�Ѿ���β�ˣ���˵��ǰ��Ķ���s1��ȣ�֤��s1���ڸ��Ӵ�
//			return p1;
//		p1++;//�����str1�ĵڶ����ַ���ʼ�Ƚ�
//		s1 = p1;
//		s2 = (char*)str2;//s2�ع鵽��һ���ַ�
//	}
//	return NULL;
//}
//
//
//int main()
//{
//	char a[] = "hello world!";
//	char b[] = "ello";
//	char* ret = my_strstr(a, b);
//	if (ret != NULL)
//		printf("%s\n", ret);
//	else
//		printf("�����ڸ��Ӵ�\n");
//	
//	return 0;
//}

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
//	int* next = (int*)malloc(sizeof(int) * mlen);
//
//	assert(next);
//	Getnext(next, mstring, mlen);
//	int i = pos;
//	int j = 0;
//	while (i < slen && j < mlen)
//	{
//		if (j == -1 || sum[i] == mstring[j])
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
//	return -1;
//}
//

//
//int main()
//{
//
//	printf("%d ", KMP("abcdef", "cdef", 0));//2
//	printf("%d ", KMP("adddddbcdef", "cdef", 0));//7
//	printf("%d ", KMP("abcdef", "edef", 0));//-1
//
//
//	return 0;
//}
//
//void* my_memcpy(void* des, void* src, size_t num)
//{
//	assert(des && src);
//	void* ret = des;//��¼��Ŀ��ռ����ʼ��ַ
//	while (num--)
//	{
//		*((char*)des) = *((char*)src);
//		des = ((char*)des) + 1;
//		src = ((char*)src) + 1;
//	}
//	return ret;
//}
//int main()
//{
//	int a[20] = { 1,2,3,4,5,6 };
//
//	memmove(a, a, sizeof(a));
//	int i = 0;
//	for (i = 0; i < 12; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}


void* my_memmove(void* des, const void* src, int num)
{
	assert(des && src);
	void* ret = des;//��¼��Ŀ��ռ����ʼ��ַ
	if (des < src)//�����ͬһ���ռ�ģ���src�ĵ�ַ��des�����ǰ���󿽱�
	{
		while (num--)
		{
			*((char*)des) = *((char*)src);
			des = ((char*)des) + 1;
			src = ((char*)src) + 1;
		}
	}
	else//�����ͬһ���ռ�ģ���src�ĵ�ַ��desС����Ӻ���ǰ����
	{
		while (num--)
		{
			*((char*)des + num) = *((char*)src + num);
		}
	}
	return ret;
}


int main()
{
	char str[] = "memmove can be very useful......";
	my_memmove(str + 20, str + 15, 11);
	puts(str);
	return 0;
}