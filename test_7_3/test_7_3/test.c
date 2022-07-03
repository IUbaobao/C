#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>

//模拟实现strlen
int my_strlen1(const char* p)
{
	assert(p);
	int count = 0;
	while (*p++ != '\0')
	{
		count++;
	}
	return count;
}

int my_strlen2(const char* p)
{
	assert(p);

	if (*p == '\0')
		return 0;

	return 1 + my_strlen2(p + 1);
}

int my_strlen3( char* p)
{
	assert(p);

	char* end = p;
	while (*end++)
	{
		;
	}
	return end - p-1;
}



//模拟实现strcpy

char* my_strcpy(char* des, const char* src)
{
	assert(des && src);
	char* ret = des;
	while (*des++ = *src++)
	{
		;
	}
	return ret;
}


//模拟实现strcat
char* my_strcat(char* des, const char* src)
{
	assert(des && src);
	char* ret = des;
	while (*++des)
	{
		;
	}
	while (*des++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char a[] = "abcdef";
	char b[20];
	char c[20] = "hello ";
	int len = my_strlen3(a);
	printf("%d \n", len);
	my_strcpy(b, a);
	printf("%s\n", b);
	my_strcat(c, "world");
	printf("%s\n", c);
	return 0;
}