#define _CRT_SECURE_NO_WARNINGS

#include"Contact.h"

int main()
{
	system("color 6");//换字体颜色    60金黄，70白色

	Contact pc = { 0 };
	
	user user1 = { 0 };
	int pos1 = 0;  //接收用户登录后返回数组的对应下标
	UserInit(&user1);//初始化并加载用户账号
	ContactInit(&pc);//初始化通讯录
	
	
	pos1=UserLongsonSystem(&user1);//登录系统 ,登录成功就返回账号数组对应的下标，用户直接退出就返回-1

	if (pos1 == -1) //终止程序条件
	{
		return 0;
	}
	
	Sleep(300);//让程序停500ms
	

	 //通讯录管理系统逻辑实现
	 int input = 0;     //接收用户选择的功能
	 int pos = 0;		//接收查找联系人的下标
	 int flag = 0;		//用于控制退出的开关
	 int Q = 0;			//统计选择功能的次数
	 char FindObject[MAX_NAME] = { 0 };//接收用户搜索联系人的信息
	 int pos2 = 0;   //用于查找多个联系人的中间值
	 int n = 0; //接收查找联系人时的退出条件
	 do
	 {
		 if (Q != 0)		//这个是已经选择了某一功能之后的选项，可以提醒用户随时退出，或者转到起始界面
		 {
			 printf("\n\n请按1退出此界面，按0退出系统....................\n");

			 scanf("%d", &flag);
			 if (flag == 0)
			 {
				 input = 0;
				 qsort(pc.data, pc.size, sizeof(pc.data[0]), cmp_name);//按名字排序通讯录
				 ContactSave(&pc);		//用户选择退出，就先把通讯录的信息保存在文件中
				 UserSave(&user1);
				 ContactDestroy(&pc);
				 printf("\n退出成功\n");
				 break;
			 }
		 }
		 system("cls");
		 Print1(7);
		 printf("\t\t\t\t\t    欢迎%s来到通讯录管理系统\t\t\t\t\t\n", user1.val[pos1].userName);

		 menu();
		 Print1(3);

		 printf("\n\t\t\t\t\t请选择>:");
		 scanf("%d", &input);
		 switch (input)
		 {
		 case Print:  //打印全部联系人信息
			 system("cls");  //清屏
			 Print1(7);    //换行美观
			 qsort(pc.data, pc.size, sizeof(pc.data[0]), cmp_name);//按名字排序通讯录
			 ContactPrint(&pc);  
			 break;
		 case Add:   //增加联系人
			 system("cls");
			 ContactAdd(&pc);

			 break;
		 case Del:    //删除联系人
			 system("cls");
			 ContactPrint(&pc);
			 ContactDel(&pc);
			 break;
		 case Find:   //查找相关联系人
			 system("cls");
			 Print1(3);
			  n = 0;  //n作为是否找到联系人的开关
			 printf("\n\t\t\t\t\t\t\t\tPS:可以是名字,性别，电话号码，地址，年龄\n");
			 printf("\n\t\t\t\t\t请输入你要查找联系人的信息:");
			 scanf("%s", FindObject);   //接收相关信息
			 pos = ContactFind(&pc, FindObject, pos);   //进入查找，找到了返回对应下标，找不到返回-1
			  pos2 = pos;
			 while (1)						
			 {
				 if (pos2 != -1)      //不为-1，则打印该下标的元素
				 {
					 n++;//确保只打印一次标题
					 if (n == 1)
						 printf("\n%-20s %-10s %-8s %-18s %-30s\n", "姓名", "性别", "年龄", "电话号码", "地址");
					 printf("\n%-20s %-10s % -8s % -18s %-30s\n", pc.data[pos2].name,
						 pc.data[pos2].sex, pc.data[pos2].age, pc.data[pos2].tele, pc.data[pos2].addr);
					 //然后再把已经找到的元素的下一个的下标传过去进行查找，直到找完所有的相关元素就停止
					 pos2 = ContactFind(&pc, FindObject, pos2+1);  

				 }
				 else
				 {
					 if (n == 0)  //如果一开始n就为0，则说明一个也没有找到，也就不存在该联系人
						 printf("\t\t\t\t\t无此联系人\n");
					 break;
				 }
			 }
			 break;

		 case Revise:  //修改联系人信息
			 system("cls");
			 ContactPrint(&pc);   //修改前先打印联系人信息，以方便用户选择修改对象

			 ContactRevise(&pc);	//修改联系人信息函数实现
			 break;

		 case Save:  //用户也可以手动保存信息到文件
			 system("cls");
			 qsort(pc.data, pc.size, sizeof(pc.data[0]), cmp_name);//按名字排序通讯录
			 ContactSave(&pc);
			 UserSave(&user1);
			 printf("\t\t\t\t\t保存成功\n");
			 break;

		 case Exit:   //退出前先保存通讯录信息和账号信息到文件里，最后再销毁开辟的空间
			 system("cls");
			 ContactSave(&pc);
			 UserSave(&user1);
			 ContactDestroy(&pc);
			 printf("\t\t\t\t\t退出成功\n");

			 break;

		 case Reviseuser:     //
			 ReviseUser(&user1, pos1);
			 break;

		 default:   //选择错误提醒用户重新输入
			 system("cls");
			 printf("\t\t\t\t\t无此选项，请重新输入\n");
			 break;
		 }
		 Q++;

	 } while (input);

	return 0;
}