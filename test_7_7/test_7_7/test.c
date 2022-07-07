#define _CRT_SECURE_NO_WARNINGS

//模拟实现strstr
//#include<stdio.h>
//#include<assert.h>
//
//char* my_strstr(const char* string, const char* src)
//{
//	assert(string && src);
//	char* s1 = (char* )string;
//	char* s2 = (char*)src;
//	char* p = (char*)string;
//	while (*p)
//	{
//		s1 = p;
//		s2 = (char*)src;
//		while ( *s2!='\0' && *s1 != '\0' && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//			return p;
//		p++;
//	}
//	return (NULL);
//}
//int main()
//{
//	char a[] = "huangdongming";
//	char b[] = "dongmingf";
//	char* ret = my_strstr(a, b);
//	printf("%s\n", ret);
//	return 0;
//}



//strerrno函数使用
//#include<stdio.h>
//#include<errno.h>
//#include<string.h>
//
//int main()
//{
//	FILE* pf = fopen("test.c1", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	return 0;
//	//FILE* pFile;
//	//pFile = fopen("unexist.ent", "r");
//	//if (pFile == NULL)
//	//	printf(" %s\n", strerror(errno));
//	////errno: Last error number
//	//return 0;
//}
