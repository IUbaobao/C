#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>

int my_strcmp(const char* p1,const char* p2)
{
	assert(p1 && p2);
	while (*p1 == *p2)
	{
		if (*p1 == '\0')
			return 0;
		p1++;
		p2++;
	}
	return p1 - p2;
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";
	int ret = my_strcmp(arr1, arr2);
	if (ret == 0)
		printf("==\n");
	else if (ret > 0)
		printf(">\n");
	else
		printf("<\n");
	return 0;
}