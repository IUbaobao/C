#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
//int main()
//{
//	//以写的方式打开test.txt
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)//判断是否打开成功
//	{
//		perror("file fail\n");
//		return 1;
//	}
//	//往test.txt文件中写入数据
//	fputs("hello word!",pf);
//	fclose(pf);//关闭文件
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("file fail\n");
//		return 1;
//	}
//	fputs("I love xxxxxx", pf);
//	fseek(pf, 7, 0);//在零位置上往后偏移7个位置
//	fputs("IT!", pf);//在此位置上往文件输入数据
//	int size = ftell(pf);//计算此时文件指针相当于起始位置的偏移量
//	printf("%d\n", size);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int c; 
//	FILE* fp = fopen("test.txt", "r");
//	if (!fp) {
//		perror("File opening failed");
//		return 1;
//	}
//	//fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF
//	while ((c = fgetc(fp)) != EOF) // 标准C I/O读取文件循环
//	{
//		putchar(c);
//	}
//		//判断是什么原因结束的
//		if (ferror(fp))
//			puts("I/O error when reading");
//		else if (feof(fp))
//			puts("End of file reached successfully");
//	fclose(fp);
//}




//#include <stdio.h>
//#include <windows.h>
////VS2019 WIN10环境测试
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	fputs("abcdef", pf);//先将代码放在输出缓冲区
//	printf("睡眠10秒-已经写数据了，打开test.txt文件，发现文件没有内容\n");
//	Sleep(10000);
//	printf("刷新缓冲区\n");
//	fflush(pf);//刷新缓冲区时，才将输出缓冲区的数据写到文件（磁盘）
//	//注：fflush 在高版本的VS上不能使用了
//	printf("再睡眠10秒-此时，再次打开test.txt文件，文件有内容了\n");
//	Sleep(10000);
//	fclose(pf);
//	//注：fclose在关闭文件的时候，也会刷新缓冲区
//	pf = NULL;
//	return 0;
//}