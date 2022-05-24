#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE


#include <stdio.h>
#include<assert.h>
#include <conio.h>



//
//#define MAX_STR_LEN  6
//
//char passwd[MAX_STR_LEN] = { 0 };
//
//char* GetPasswd(void)
//{
//    char c;
//    int i = 0;
//    int len = MAX_STR_LEN - 1;
//
//    while ((c = getch()) != 13)
//    {
//        if (c == 13)
//        {
//            break;
//        }
//        passwd[i] = c;
//        putchar('*');
//        i++;
//        
//        if (i >= len)
//        {
//            break;
//        }
//    }
//
//    return passwd;
//}
//
//int main(void)
//{
//    char* dispstr = NULL;
//
//    dispstr = GetPasswd();
//    //printf("/nthe password is : %s/n", dispstr);
//
//    return 0;
////}
//
//void Getpassword(char* pass, int sz)
//{
//	assert(pass);
//	char c = 0;
//	int i = 0;
//	while ((c = getch()) != 13)
//	{
//
//		pass[i] = c;
//		i++;
//		putchar('*');
//		if (i > sz-2)
//		{
//			printf("\n密码过长\n");
//			break;
//		}
//	}
//	//pass[i] = '\0';
//}
//
//int main()
//{
//
//	char password[7] = { 0 };
//
//	 Getpassword(password,7);
//
//	printf("%s", password);
//}



//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：//
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//#include<stdio.h>
//int main()
//{
//	int a, b, c, d, e;
//	for (a = 1; a < 6; a++)
//		for(b=1;b<6;b++)
//			for(c=1;c<6;c++)
//				for(d=1;d<6;d++)
//					for (e = 1; e < 6; e++)
//					{
//						if ((b == 2 || a == 3) && (b == 2 || e == 4) && (c == 1 || d == 2) && (c == 5 || d == 3) && (e == 4 || a == 1) == 1)
//						{
//							if (a * b * c * d * e == 120)
//								printf("a=%d  b=%d  c=%d  d=%d  e=%d \n", a, b, c, d, e);
//						}
//					}
//	return 0;
//}


//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
////A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
#include<stdio.h>
int main()
{
	char killer = 0;

	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if (((killer != 'a') + (killer == 'd') + (killer != 'd') + (killer=='c')) == 3)
			printf("killer=%c", killer);
	}
	return 0;
}