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


//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ��������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
//#include<stdio.h>
//
//int main()
//{
//	int a, b, c, d, e;
//	for (a = 1; a <= 5; a++)
//		for (b = 1; b <= 5; b++)
//			for (c = 1; c <= 5; c++)
//				for (d = 1; d <= 5; d++)
//					for (e = 1; e <= 5; e++)					//��Ϊÿλѡ�ֶ�˵����һ�룬���Կ������߼���||��������ʾ
//						if ((b == 2 || a == 3) && (e == 4 || b == 2) && (c == 1 || d == 2) && (c == 5 || d == 3) && (e == 4 || a == 1) == 1)
//						{
//							if (a * b * c * d * e == 120)			//��Ϊ1*2*3*4*5=120�����û������ж������ֶ��ֽ��
//								printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
//						}
//
//
//	return 0;
//}


//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//����Ϊ4�����ɷ��Ĺ���:
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
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
//����Ļ�ϴ�ӡ������ǡ�
//1
//1 1
//1 2 1
//1 3 3 1
//����



