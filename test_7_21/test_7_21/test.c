#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//#include<math.h>
//
//int my_atoi(char* str)
//{
//	assert(str);
//	int flag = 1;
//	int ret = 0;
//	while (*str == ' ')//去除空格
//		str++;	
//	if (*str == '-')//判断正负
//	{
//		flag = -1;
//		str++;
//	}
//	else if (*str == '+')
//	{
//		flag = 1;
//		str++;
//	}
//	while (*str >= '0' && *str <= '9')//变成整数
//	{
//		ret = 10 * ret+flag*(*str - '0');
//		str++;
//	}
//	return ret;
//}
//int main()
//{
//	int i = 0;
//	char arr[10];
//	scanf("%s", arr);
//	i = my_atoi(arr);
//	printf("%d", i);
//	return 0;
//}


//
////写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明
////考察：offsetof宏的实现
//#include<stdio.h>
//#include<stddef.h>
//
//#define my_offsetof(type,member) (size_t)&(((type*)0)->member)
//
////#define OFFSETOF(type,member)     (size_t)&(((type*)0)->member)
//
//struct s
//{
//	char a;
//	int b;
//	char c;
//};
//
//int main()
//{
//	struct s a = { 0 };
//	printf("%d\n", sizeof(struct  s));
//	printf("%d\n", my_offsetof(struct s, a));
//	printf("%d\n", my_offsetof(struct s, b));
//	printf("%d\n", my_offsetof(struct s, c));
//
//	return 0;
//}
//
//



//写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换。
//
//#include<stdio.h>
//
//#define SWAP_bit(n)   (((n&0x55555555)<<1)+((n&0xaaaaaaaa)>>1))
//
//int main()
//{
//	int a = 1;
//	printf("%d\n", SWAP_bit(a));
//	return 0;
//}

//请实现一个函数，将一个字符串中的每个空格替换成“ % 20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We % 20Are % 20Happy。
#include<stdio.h>
#include<string.h>

void replaceSpace(char* str, int length) {
    int space_num = 0;
    char* cur = str;
    while (*cur != '\0')
    {
        if (*cur == ' ')
            space_num++;
        cur++;
    }
    int end2 = length + space_num * 2 - 1;
    int end1 = length - 1;
    while (end1 != end2)
    {
        if (str[end1] != ' ')
        {
            str[end2--] = str[end1--];
        }
        else
        {
            end1--;
            str[end2--] = '0';
            str[end2--] = '2';
            str[end2--] = '%';
        }
    }

}

int main()
{
    char arr[20] = "hello world!";
    replaceSpace(arr, strlen(arr));
    printf("%s", arr);
    return 0;
}