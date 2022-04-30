#define _CRT_SECURE_NO_WARNINGS

//小乐乐上课需要走n阶台阶，因为他腿比较长，所以每次可以选择走一阶或者走两阶，那么他一共有多少种走法？
//#include<stdio.h>
//int fun(int n)
//{
//    if (n <= 1)
//    {
//        return 1;
//    }
//    else
//        return fun(n - 1) + fun(n - 2);
//}
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int ret = fun(n);
//    printf("%d ", ret);
//    return 0;
//}

//
//有一个整数序列（可能有重复的整数），现删除指定的某一个整数，输出删除指定数字之后的序列，序列中未被删除数字的前后位置没有发生改变。
//数据范围：序列长度和序列中的值都满足 1 \le n \le 501≤n≤50
//输入描述：
//第一行输入一个整数(0≤N≤50)。
//第二行输入N个整数，输入用空格分隔的N个整数。
//第三行输入想要进行删除的一个整数。
//输出描述：
//输出为一行，删除指定数字之后的序列。
//示例1
//输入：
//6
//1 2 3 4 5 9
//4
//复制
//输出：
//1 2 3 5 9
//#include<stdio.h>
//int main()
//{
//    int size = 0;
//    int arr[50] = { 0 };
//    int input = 0;
//    int i = 0;
//    int j = 0;
//    scanf("%d", &size);
//    for (i = 0; i < size; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    scanf("%d", &input);
//    //删除
//    for (i = 0; i < size; i++)
//    {
//        if (input == arr[i])
//        {
//            for (j = i; j < size; j++)
//            {
//                arr[j] = arr[j + 1];
//            }
//            size--;
//            i--;
//        }
//    }
//    //打印
//    for (i = 0; i < size; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}
//
//输入n个成绩，换行输出n个成绩中最高分数和最低分数的差。
//输入描述：
//两行，第一行为n，表示n个成绩，不会大于10000。
//第二行为n个成绩（整数表示，范围0~100），以空格隔开。
//输出描述：
//一行，输出n个成绩中最高分数和最低分数的差。
//示例1
//输入：
//10
//98 100 99 97 95 99 98 97 96 100
//复制
//输出：
//5
//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    int i = 0;
//    int arr[10000] = { 0 };
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    int max = arr[0], min = arr[0];
//    //找出最大值和最小值
//    for (i = 1; i < n; i++)
//    {
//        if (arr[i] > max)
//        {
//            max = arr[i];
//        }
//        if (arr[i] < min)
//        {
//            min = arr[i];
//        }
//    }
//    printf("%d", (max - min));
//    return 0;
//}



//描述
//KiKi想完成字母大小写转换，有一个字符，判断它是否为大写字母，如果是，将它转换成小写字母；反之则转换为大写字母。
//输入描述：
//多组输入，每一行输入一个字母。
//输出描述：
//针对每组输入，输出单独占一行，输出字母的对应形式。
//示例1
//输入：
//a
//A
//Z
//输出：
//A
//a
//z

//#include<stdio.h>
//int main()
//{
//    char a;
//    while ((a = getchar()) != EOF)
//    {
//        if (a >= 'a' && a <= 'z')
//            printf("%c\n", a - 32);
//        if (a >= 'A' && a <= 'Z')
//            printf("%c\n", a + 32);
//    }
//
//}


//
//KiKi想判断输入的字符是不是字母，请帮他编程实现。
//
//输入描述：
//多组输入，每一行输入一个字符。
//输出描述：
//针对每组输入，输出单独占一行，判断输入字符是否为字母，输出内容详见输出样例。
//示例1
//输入：
//A
//6
//复制
//输出：
//A is an alphabet.
//6 is not an alphabet.
//#include<stdio.h>
//int main()
//{
//    char a;
//    while ((a = getchar()) != EOF)
//    {
//        if (a != '\n')
//        {
//            if (a >= 'A' && a <= 'z')
//                printf("%c is an alphabet.\n", a);
//            else
//                printf("%c is not an alphabet.\n", a);
//        }
//    }
//    return 0;
//}
//
//KiKi参加了语文、数学、外语的考试，请帮他判断三科中的最高分。从键盘任意输入三个整数表示的分数，编程判断其中的最高分。
//
//数据范围： 0 \le n \le 100 \0≤n≤100
//输入描述：
//输入一行包括三个整数表示的分数（0~100），用空格分隔。
//输出描述：
//输出为一行，即三个分数中的最高分
//示例1
//输入：
//94 98 99
//输出：
//99
//#include<stdio.h>
//int main()
//{
//    int arr[3] = { 0 };
//    int i = 0, max = 0;
//    for (i = 0; i < 3; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (i = 0; i < 3; i++)
//    {
//        if (arr[i] > max)
//            max = arr[i];
//    }
//    printf("%d", max);
//    return 0;
//}
//
//变种水仙花数 - Lily Number：把任意的数字，从中间拆分成两个数字，
// 比如1461 可以拆分成（1和461）, （14和61）, （146和1), 
// 如果所有拆分后的乘积之和等于自身，则是一个Lily Number。
//例如：
//655 = 6 * 55 + 65 * 5
//1461 = 1 * 461 + 14 * 61 + 146 * 1
//求出 5位数中的所有 Lily Number。
#include<stdio.h>
int main()
{
    int i = 0;
    for (i = 10000; i <= 99999; i++)
    {
        if (((i % 10) * (i / 10) + (i % 100) * (i / 100) + (i % 1000) * (i / 1000) + (i % 10000) * (i / 10000)) == i)
            printf("%d ", i);
    }
    return 0;
}