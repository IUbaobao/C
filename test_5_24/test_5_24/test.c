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
//			printf("\n�������\n");
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



//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������//
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
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


//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//����Ϊ4�����ɷ��Ĺ���:
////A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
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