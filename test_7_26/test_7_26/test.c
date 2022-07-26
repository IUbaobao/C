#define _CRT_SECURE_NO_WARNINGS


//#include<stdio.h>
//
//int main()
//{
//
//	unsigned short x = 65530;
//	unsigned int y = x;
//	printf("%0x", y);
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int n = 1001;
//	int ans = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		ans ^= i % 3;
//	}
//	printf("%d", ans);
//	return 0;
//}

//输入一个整数，将这个整数以字符串的形式逆序输出
//程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001
//
//
//数据范围： 0 \le n \le 2 ^ {30} - 1 \0≤n≤2
//30
//?1
//输入描述：
//输入一个int整数
//
//输出描述：
//将这个整数以字符串的形式逆序输出
//
//示例1
//输入：
//1516000
//复制
//输出：
//0006151

//#include<stdio.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    if (n == 0)
//        printf("%c\n", '0');
//    char arr[1000000];
//    int count = 0;
//    while (n)
//    {
//        arr[count++] = n % 10 + '0';
//        n /= 10;
//    }
//    printf("%s\n", arr);
//    return 0;
//}

//
//对字符串中的所有单词进行倒排。
//
//说明：
//
//1、构成单词的字符只有26个大写或小写英文字母；
//
//2、非构成单词的字符均视为单词间隔符；
//
//3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；
//
//4、每个单词最长20个字母；
//
//数据范围：字符串长度满足 1 \le n \le 10000 \1≤n≤10000
//输入描述：
//输入一行，表示用来倒排的句子
//
//输出描述：
//输出句子的倒排结果
//
//示例1
//输入：
//I am a student
//输出：
//student a am I
//#include<stdio.h>
//#include<string.h>
//void revese(char* a, int left, int right)
//{
//    while (left < right)
//    {
//        char tem = a[left];
//        a[left] = a[right];
//        a[right] = tem;
//        --right;
//        ++left;
//    }
//}
//
//int main()
//{
//    char arr[10001];
//    gets(arr);
//    int len = strlen(arr);
//    for (int i = 0; i < len; i++)
//    {
//        if ('A' <= arr[i] && arr[i] <= 'z')
//            continue;
//        else
//            arr[i] = ' ';  //清除不为英文字符的字符
//    }
//    revese(arr, 0, len - 1);//先把整个字符串逆置
//    int prev = 0;
//    for (int i = 0; i < len; i++)
//    {
//        if (arr[i] == ' ')
//        {
//            revese(arr, prev, i - 1);//再逐个单词逆置
//            prev = i + 1;
//        }
//    }
//    revese(arr, prev, len - 1); //把最后一个单词逆置
//    printf("%s\n", arr);
//    return 0;
//}



#include<stdio.h>

int main()
{
	//以写的方式打开一个当前目录下的test.txt文件
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		printf("fopen fail\n");
		return 1;   //文件打开失败退出程序
	}
	//....对文件一系列操作后

	fclose(pf);//将文件关闭
	pf = NULL;
	return 0;
}