#include<stdio.h>
#include<stdlib.h>

struct stu
{
	char six[20];
	char name[20];
	float gra[3];
	float Aver;
};
//读取文件数据
void readdata(struct stu stu1[], int size,const char arr[]);
//按平均分排序
void Aversort(struct stu stu1[], int size);
//比较平均分
int cmp(const void* e1, const void* e2);
//把数据写进文件
void writedata(struct stu stu1[], int size);
//打印数据
void print(struct stu stu1[], int size);
int main()
{
	struct stu stu1[5];
	readdata(stu1,5,"stud.dat");
	Aversort(stu1, 5);
	writedata(stu1, 5);
	readdata(stu1, 5,"stud_sore.dat");
	print(stu1, 5);
	return 0;
}



void readdata(struct stu stu1[], int size,const char arr[])
{
	FILE* pfread = fopen(arr,"rb");
	if (pfread == NULL)
	{
		printf("打开失败\n");
		exit;
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
void Aversort(struct stu stu1[], int size)
{
		//void qsort ( void * base, 	//base：参与排序的数组指针
		//				size_t num, 	//num：参与排序的元素个数；
		//				size_t size, 	//size：单个元素的大小；
		//				int (*comparator) (const void*, const void*) )
		//						( * comparator ) ( const void *, const void * )：比较函数指针；

	qsort(stu1, 5,sizeof(stu1[0]), cmp);
}
int cmp(const void* e1, const void* e2)
{
	if (((((struct stu*)e1)->Aver - ((struct stu*)e2)->Aver)) < 0)
		return 1;
	else if (((((struct stu*)e1)->Aver - ((struct stu*)e2)->Aver)) > 0)
		return -1;
	else
		return 0;
}
void writedata(struct stu stu1[], int size)
{
	FILE* pfwrite=fopen("stu_sort.dat", "wb");
	if (pfwrite == NULL)
	{
		printf("打开失败\n");
		exit;
	}
	
	int i=0;
	for (i = 0; i < size; i++)
	{
		fwrite(&stu1[i], sizeof(struct stu),1,pfwrite);
		
}
	
	fclose(pfwrite);
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
