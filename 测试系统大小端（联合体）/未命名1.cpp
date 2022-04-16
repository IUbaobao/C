

#include<stdio.h>
int check_sys()
{
	union
	{
		int i;
		char c;
	}u;
	u.i = 1;
	//返回1，小端
	//返回0，大端
	return u.c;
 }
int main()
{
	int ret = check_sys();
	if (ret == 1)
		printf("小端\n");
	else
		printf("大端\n");
	return 0;
}
