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
//	while (*str == ' ')//ȥ���ո�
//		str++;	
//	if (*str == '-')//�ж�����
//	{
//		flag = -1;
//		str++;
//	}
//	else if (*str == '+')
//	{
//		flag = 1;
//		str++;
//	}
//	while (*str >= '0' && *str <= '9')//�������
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
////дһ���꣬����ṹ����ĳ����������׵�ַ��ƫ�ƣ�������˵��
////���죺offsetof���ʵ��
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



//дһ���꣬���Խ�һ�������Ķ�����λ������λ��ż��λ������
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

//��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ� % 20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe % 20Are % 20Happy��
//#include<stdio.h>
//#include<string.h>
//
//void replaceSpace(char* str, int length) {
//    int space_num = 0;
//    char* cur = str;
//    while (*cur != '\0')
//    {
//        if (*cur == ' ')
//            space_num++;
//        cur++;
//    }
//    int end2 = length + space_num * 2 - 1;
//    int end1 = length - 1;
//    while (end1 != end2)
//    {
//        if (str[end1] != ' ')
//        {
//            str[end2--] = str[end1--];
//        }
//        else
//        {
//            end1--;
//            str[end2--] = '0';
//            str[end2--] = '2';
//            str[end2--] = '%';
//        }
//    }
//
//}
//
//int main()
//{
//    char arr[20] = "hello world!";
//    replaceSpace(arr, strlen(arr));
//    printf("%s", arr);
//    return 0;
//}

//
//���ӣ�https://www.nowcoder.com/questionTerminal/18ecd0ecf5ef4fe9ba3f17f8d00d2d66?pos=11&orderByHotValue=1
//��Դ��ţ����
//
//Fibonacci��������������ģ�
//F[0] = 0
//F[1] = 1
//for each i �� 2: F[i] = F[i - 1] + F[i - 2]
//��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci��������һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX - 1����X + 1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����
//
//�������� :
//����Ϊһ��������N(1 �� N �� 1, 000, 000)
//
//
//������� :
//    ���һ����С�Ĳ�����ΪFibonacci��"
//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int a = 0;
//    int b = 1;
//    int c = a + b;
//    int min = 99999999;
//    while (abs(n - c) <= min)
//    {
//        c = a + b;
//        if (abs(n - c) < min)
//            min = abs(n - c);
//        a = b;
//        b = c;
//    }
//    printf("%d\n", min);
//    return 0;
//}


#include<stdio.h>
#include<math.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int a = 0;
    int b = 1;
    int c = a + b;
    while (1)
    {
        if (n == b)
        {
            printf("0\n");
            break;
        }
        else if (n < b)
        {
            if (abs(n - a) > abs(n - b))
                printf("%d\n", abs(n - b));
            else
                printf("%d\n", abs(n - a));
            break;
        }
        else
        {
            a = b;
            b = c;
            c = a + b;
        }
    }
    return 0;
}