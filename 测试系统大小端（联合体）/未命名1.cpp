

#include<stdio.h>
int check_sys()
{
	union
	{
		int i;
		char c;
	}u;
	u.i = 1;
	//����1��С��
	//����0�����
	return u.c;
 }
int main()
{
	int ret = check_sys();
	if (ret == 1)
		printf("С��\n");
	else
		printf("���\n");
	return 0;
}
