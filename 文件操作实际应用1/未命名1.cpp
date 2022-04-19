
#include<stdio.h>
#include<stdlib.h>

struct stu
{
	char six[20];
	char name[20];
	float gra[3];
	float Aver;
};
//获取键盘数据
void scan(struct stu stu1[], int size);
//打印数据
void print(struct stu stu1[], int size);
//求平均分
void cmpEm(struct stu stu1[], int size);
//把数据写进文件
void writedata(struct stu stu1[], int size);
//读取文件数据
void readdata(struct stu stu1[], int size);


int main()
{
	struct stu stu1[5] = {0};
	//scan(stu1, 5);
	//writedata(stu1, 5);
	readdata(stu1, 5);
	print(stu1, 5);
}


void scan(struct stu stu1[], int size)
{
	for (int i = 0; i < 5; i++)
	{
		printf("请输入学号，姓名，三门课程成绩\n第%d个学生   ", i + 1);
		scanf("%s %s%f%f%f", &stu1[i].six, &stu1[i].name, &stu1[i].gra[0],
			&stu1[i].gra[1], &stu1[i].gra[2]);
	}

}

void print(struct stu stu1[], int size)
{
	int i = 0;
	printf("%-20s%-20s%-28s%-6s\n", "学号", "姓名", "成绩", "平均分");
	for (i = 0; i < 5; i++)
	{
		printf("%-20s%-20s%-6.2f%-6.2f%-16.2f%-6.2f\n", stu1[i].six, stu1[i].name, stu1[i].gra[0],
			stu1[i].gra[1], stu1[i].gra[2], stu1[i].Aver);
	}

}

void  cmpEm( struct stu stu1[], int size)
{
	float tem = 0;
	for (int i = 0; i < size; i++)
	{
		stu1[i].Aver = (stu1[i].gra[0] + stu1[i].gra[1] + stu1[i].gra[2]) / 3;
	}

}

void writedata(struct stu stu1[], int size)
{
	FILE* pfwrite=fopen("stud.dat", "wb");
	if (pfwrite == NULL)
	{
		printf("打开失败\n");
		return;
	}
 cmpEm(stu1, size);
	struct stu tem = {0};
	int i=0;
	for (i = 0; i < size; i++)
	{
		fwrite(&stu1[i], sizeof(struct stu),1,pfwrite);
		
}
	
	fclose(pfwrite);
}

void readdata(struct stu stu1[], int size)
{
	FILE* pfread = fopen("stud.dat", "rb");
	if (pfread == NULL)
	{
		printf("打开失败\n");
		return;
	}
	struct stu tem = { 0 };
	int i = 0;
	while (fread(&tem, sizeof(struct stu), 1, pfread))
	{
		stu1[i] = tem;
		i++;
	}
	
	fclose(pfread);
}


