#define _CRT_SECURE_NO_WARNINGS



//实现一个函数，判断一个数是不是素数。
//利用上面实现的函数打印100到200之间的素数。
//#include<stdio.h>
//#include<math.h>
//int is_prime_num(int n)
//{
//	int i = 0;
//	for (i = 2; i < sqrt(n); i++)
//	{
//		//是素数返回1，不是返回-1
//		if (n % i == 0)
//		{
//			return -1;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime_num(i) == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}



////实现函数判断year是不是闰年。
//#include<stdio.h>
//int is_leap_year(int year)
//{
//	//是闰年返回1，不是返回-1
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//	{
//		return 1;
//	}
//	return -1;
//}
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	int ret = is_leap_year(i);
//	if (ret == 1)
//	{
//		printf("是闰年\n");
//	}
//	else
//	{
//		printf("不是闰年\n");
//	}
//	return 0;
//}



////字符的最短距离
//给你一个字符串 s 和一个字符 c ，且 c 是 s 中出现过的字符。
//返回一个整数数组 answer ，其中 answer.length == s.length 且 answer[i] 是 s 中从下标 i 到离它 最近 的字符 c 的 距离 。
//两个下标 i 和 j 之间的 距离 为 abs(i - j) ，其中 abs 是绝对值函数。
//输入：s = "aaab", c = "b"
//输出：[3, 2, 1, 0]
int* shortestToChar(char* s, char c, int* returnSize) {

    int len = strlen(s);
    int* arr = (int*)malloc(sizeof(int) * len);
    int i = 0;
    //先初始化为零
    for (i = 0; i < len; i++)
    {
        arr[i] = 0;
    }
    //距离控制变量
    int count = 0;
    //找到字符的控制变量
    int j = 0;
    //从左往右找字符
    for (i = 0; i < len; i++)
    {   //找到了把标识j变成1，count变零
        if (s[i] == c)
        {
            j = 1;
            count = 0;
        }
        //找了字符，从i开始置零，往后递增1，2,3....
        if (j == 1)
        {
            arr[i] = count++;
        }

    }
    j = 0;
    //从后往前找字符
    for (i = len - 1; i >= 0; i--)
    {
        //找到了，把控制开关j赋1，count从零开始
        if (s[i] == c)
        {
            j = 1;
            count = 0;
        }
        if (j == 1)
        {
            //如果本来里面存的数据距离比count大，则把小的count覆盖给它，如果本来位置是零，也没关系，因为也是赋零给它
            if (arr[i] >= count || arr[i] == 0)
            {
                arr[i] = count++;
            }
        }
    }

    *returnSize = len;
    return arr;
}