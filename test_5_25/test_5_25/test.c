#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	///*unsigned char a = 200;
//	//unsigned char b = 100;
//	//unsigned char c = 0;
//	//*/c = a + b;
//
//	unsigned int a = 0x1234; 
//	unsigned char b = *(unsigned char*)&a;
//
//	
//	//printf(" % d % d",a + b, c);
//	return 0;
////}
//#include<stdio.h>
//int main()
//{
//    char a[1000] = { 0 };
//    int i = 0;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", strlen(a));
//    return 0;
//}


//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//#include<stdio.h>
//
//int main()
//{
//	int a, b, c, d, e;
//	for (a = 1; a <= 5; a++)
//		for (b = 1; b <= 5; b++)
//			for (c = 1; c <= 5; c++)
//				for (d = 1; d <= 5; d++)
//					for (e = 1; e <= 5; e++)					//因为每位选手都说对了一半，所以可以用逻辑“||”或来表示
//						if ((b == 2 || a == 3) && (e == 4 || b == 2) && (c == 1 || d == 2) && (c == 5 || d == 3) && (e == 4 || a == 1) == 1)
//						{
//							if (a * b * c * d * e == 120)			//因为1*2*3*4*5=120，如果没有这个判断则会出现多种结果
//								printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
//						}
//
//
//	return 0;
//}


//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
//#include<stdio.h>
//int main()
//{
//	char killer;
//	for (killer = 'a'; killer < 'd'; killer++)
//	{
//		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
//		{
//			printf("killer=%c", killer);
//		}
//	}
//
//	return 0;
//}
//
//
//
//在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1
//……



