#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
/* 
	数组名表示首元素地址  
		但有两种情况是例外的
		1.sizeof(数组名)---数组名表示整个数组
		2.&数组名  --- 表示整个元素的地址
*/

/* 
	函数strlen计算字符串长度，只有在遇到'\0'才停止计算个数
	而且它的参数是一个字符指针
	strlen( const char *string )
*/

int main()
{
	//一维数组
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a)); // 16 数组名单独放在sizeof()里面，所以数组名表示整个数组的大小4*4

	printf("%d\n", sizeof(a + 0));// 4/8 数组名不是单独放在sizeof里面，所以数组名表示首元素地址，
									//首元素地址+1还是首元素地址，是地址在32位平台就4个字节，64位平台就8个字节

	printf("%d\n", sizeof(*a));	// 4  同样数组名不是单独放在sizeof里面，所以还是首元素地址，首元素地址解引用（*），
									//就是首元素，因为数组是int类型，所以为4

	printf("%d\n", sizeof(a + 1));// 4/8 跟sizeof(a+0)同样的道理，只不过这个指针指向的是数组第二个元素

	printf("%d\n", sizeof(a[1]));// 4  a[1]就是第二个元素，而且a[1]=*(a+1)

	printf("%d\n", sizeof(&a));	 // 4/8 &数组名，表示整个元素的地址，是地址就是4或8个字节
									//(千万不要因为它是整个元素地址就认为跟其他地址不一样)

	printf("%d\n", sizeof(*&a));	// 16 首先&数组名，就是整个数组的地址，而解引用（*）之后就是整个数组
									//注释：其实 * 与 & 相当于一个互逆运算，可以理解成两个抵消了变成sizeof(a)
										
	printf("%d\n", sizeof(&a + 1)); // 4/8 &数组名就是整个数组的地址，&a+1就是跳过整个数组后的地址，不管怎样都是地址

	printf("%d\n", sizeof(&a[0]));	// 4/8  a[0]为首元素，&a[0]就是首元素地址
	printf("%d\n", sizeof(&a[0] + 1));// 4/8  &a[0]为首元素地址，+1后就为第二个元素的地址
	
	
	
	//字符数组
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr)); // 6  数组名单独放在sizeof里面，数组名就表示整个数组，数组的大小就为1*6=6
	printf("%d\n", sizeof(arr + 0));// 4/8  数组名不是单独放在sizeof里面，所以它是首元素地址，+0也是首元素地址

	printf("%d\n", sizeof(*arr)); // 1 同样数组名不是单独放在sizeof里面，所以数组名表示首元素地址，解引用（*）后就为首元素
										//而数组是char类型的，所以为1字节
	printf("%d\n", sizeof(arr[1]));// 1  arr[1]就为第二个元素
	printf("%d\n", sizeof(&arr));	// 4/8 &数组名 表示整个数组的地址，是地址就是4或8个字节
	printf("%d\n", sizeof(&arr + 1));// 4/8  数组的地址+1，也是地址
	printf("%d\n", sizeof(&arr[0] + 1));// 4/8  &arr[0] 就是首元素地址，+1后就是第二个元素的地址，是地址就是4/8个字节
	printf("%d\n", strlen(arr));// 随机值 因为数组{'a','b'}类型于这样的初始化方式，它在结尾都没有'\0'，所以无法知道
									//	strlen在什么时候遇到'\0'停止计算
	printf("%d\n", strlen(arr + 0));//随机值 arr+0，为首元素地址，+0也为首元素地址，但是也是跟上面一样
	printf("%d\n", strlen(*arr));// err(错误)  strlen的参数是传一个字符指针，但是*arr为首元素，也就是'a'
									//a的ascll为97,你硬要传过去的话，那么strlen就认为它是一个地址，而97的地址
									//不是我们开辟的,对它进行访问的话，就是越界访问了程序错误
	printf("%d\n", strlen(arr[1]));//err(错误) arr[1]是第二个元素，也就是'b'，跟上面一样的错误
	printf("%d\n", strlen(&arr));	// 随机值 &arr 为整个数组的地址，但数组的地址其实数值上跟首元素的地址是一样的，
									//'\0'位置同样无法确定
	printf("%d\n", strlen(&arr + 1));// 随机值-6  &arr+1 越个一个数组后的地址，也是无法确定'\0'位置，但是它跟上面的
									//那个随机值有一定的联系, 那就是比它小6，随机值-6

	printf("%d\n", strlen(&arr[0] + 1));// 随机值-1  &arr[0]首元素地址，+1后就是第二个元素的地址，但是也不知道'\0'的位置


	char arr[] = "abcdef"; //这种初始化方式后面个默认有个'\0'，也就是说这个数组的内容为abcdef\0
	printf("%d\n", sizeof(arr)); //7  数组的内容为abcdef\0,数组名单独放在sizeof里面，所以表示整个数组的大小，也就是7*1
	printf("%d\n", sizeof(arr + 0));//4/8 数组名不是单独放在sizeof里面，所以这里的数组名表示首元素地址，+0也为首元素地址
									//是地址就为4或8个字节
	printf("%d\n", sizeof(*arr));// 1 同样，数组名不是单独放在sizeof里面，所以数组名表示首元素地址，解引用（*）后
									//就是首元素a，char类型为1个字节
	printf("%d\n", sizeof(arr[1]));// 1 arr[1]为第二个元素b,也等同于*(arr+1)
	printf("%d\n", sizeof(&arr));	// 4/8 &arr,表示整个数组的地址，是地址就为4或8个字节
	printf("%d\n", sizeof(&arr + 1));// 4/8 数组的地址+1，就是跳过一个数组后的地址，是地址就为4或8个字节
	printf("%d\n", sizeof(&arr[0] + 1));//4/8 &arr[0],首元素地址，+1后就为第二个元素的地址
	printf("%d\n", strlen(arr));//6  数组的内容为abcdef\0,arr表示首元素地址，从第一个元素开始算个数到\0停止
	printf("%d\n", strlen(arr + 0));// 6  arr表示首元素地址,+0也为首元素地址
	//printf("%d\n", strlen(*arr));	 // err(错误)  strlen的参数是传一个字符指针，但是*arr为首元素，也就是'a'
	//								//a的ascll为97,你硬要传过去的话，那么strlen就认为它是一个地址，而97的地址
	//								//不是我们开辟的,对它进行访问的话，就是越界访问了程序错误
	//printf("%d\n", strlen(arr[1]));//err 同上
	printf("%d\n", strlen(&arr));// 6 &arr 为整个数组的地址，但在数值上跟首元素地址一样，所以还从第一个元素开始算，遇\0停止
	printf("%d\n", strlen(&arr + 1));// 随机值 &arr 是整个数组的地址，+1后就是跳个整个数组的地址，而我们知道strlen是遇到
									// '\0'才停止计算的，而你把arr数组的内容跳过了，后面就不知道什么时候能遇到\0了
	printf("%d\n", strlen(&arr[0] + 1));//5 &arr[0]+1 是第二个元素的地址，也就是从第二个元素开始算，所以为6-1=5
	
	char* p = "abcdef";  /*很多以为这是把abcdef存在指针p中，其实这是错误的想法，
							它的本质是把首元素的地址存放在p中，这也就是把a的地址存放在p中
							*/
	printf("%d\n", sizeof(p));//4/8  p是一个char类型的指针，存放的是元素a的地址
	printf("%d\n", sizeof(p + 1));//4 p+1为b的地址，是地址就为4或8个字节
	printf("%d\n", sizeof(*p));// 1  p为a的地址，解引用（*）就是a，a是char类型
	printf("%d\n", sizeof(p[0]));// 1 p[0]就是首元素a
	printf("%d\n", sizeof(&p));// 4/8  p是char*类型的指针，而&p，就是p的地址，char**,二级指针，
								//本质还是指针，还是4或8个字节
	printf("%d\n", sizeof(&p + 1));// 4/8 &p是p的地址，&p+1就是p地址的后一个地址，还是地址就是4或8个字节
	printf("%d\n", sizeof(&p[0] + 1));// 4/8  p[0]是元素a，&a[0]就是首元素地址，+1就是等二个元素的地址（b的地址）

	printf("%d\n", strlen(p));// 6  p为首元素a的地址，从a开始往后算个数就是6个字符
								//（"abcdef"这样的初始化内存足够的情况下默认后面加\0）strlen遇\0停止计算
	printf("%d\n", strlen(p + 1));// 5 p为首元素地址，+1后为b的地址，往后数到\0后停止计算
	//printf("%d\n", strlen(*p));// // err(错误)  strlen的参数是传一个字符指针，但是*p为首元素，也就是'a'
	////								//a的ascll为97,你硬要传过去的话，那么strlen就认为它是一个地址，而97的地址
	////								//不是我们开辟的,对它进行访问的话，就是越界访问了程序错误
	//printf("%d\n", strlen(p[0]));// err 同上
	printf("%d\n", strlen(&p));// 随机值 p是char*类型的指针，&p就是取去p的地址，&p的类型就是char**二级指针，
								//你把它传给strlen，也就是传了p的地址，它跟a的地址没什么联系，&p指向的内容也不知道什么
								//地方会出现\0
	printf("%d\n", strlen(&p + 1));// 随机值，也是p的地址，+1后就是跳过p的地址的后一个地址，也是不知道\0的具体位置
									//它跟上面那个随机值没有任何关系，因为不知道它们之间是否存在\0
	printf("%d\n", strlen(&p[0] + 1));//5  p[0]为首元素a，&a[0]就是把a的地址取出来，+1就是b的地址，从b往后数就是5


	//二维数组
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48  数组名单独放在sizeof里面，所以数组名表示整个数组大小，3*4*4=48
	printf("%d\n", sizeof(a[0][0]));//4，a[0][0]表示首元素，因为是int类型，所以为4

	printf("%d\n", sizeof(a[0]));//16 a[0] 是首元素，对于二维数组来说 它的首元素为第一行的，a[0]其实相当于那到第一行
									// 的名称，相当于sizeof（第一行名称），表示整个数组的大小， 第一行有4个元素，所以4*4
								//  a[0]表示第一行，a[1]表示第二行....

	printf("%d\n", sizeof(a[0] + 1));//4/8  上面讲了，a[0]本质是第一行的名称，sizeof里面表示单独放数组名，所以表示该数组的
									//首元素地址，而第一行的首元素地址+1就是第一行第二个元素的地址

	printf("%d\n", sizeof(*(a[0] + 1)));//4  a[0]+1就是第一行第二个元素的地址，解引用就是该地址对应的元素值等同于a[0][1]

	printf("%d\n", sizeof(a + 1)); //4/8 数组名不是单独放在sizeof里面，所以a表示二维数组首元素地址，对于二维数组来说 
									//它的首元素为第一行的地址,+1就是第二行地址
									
	printf("%d\n", sizeof(*(a + 1)));// 16  a+1为第二行地址，它是单独放在sizeof里面，所以表示整个数组大小
										
	printf("%d\n", sizeof(&a[0] + 1));//4/8 a[0]是第一行，&a[0]就是把整个数组的地址取出来，+1就是跳过整个数组指向
										//下一个数组,也就是指向第二行，本质还是数组
										
	printf("%d\n", sizeof(*(&a[0] + 1)));// 16  &a[0]+1是第二行地址，解引用（*）后就拿到第二行数组的名称,sizeof()
										//里面单独放数组名，表示整个数组的大小

	printf("%d\n", sizeof(*a));//16  数组名不是单独放在sizeof里面，所以表示二维数组的首元素地址，二维数组的首元素地址
									//就是第一行地址，解引用（*）后相当于sizeof(第一行名称),数组名单独放里，
										//所以是整个第一行数组的大小
	printf("%d\n", sizeof(a[3]));	//16  a[3]相当于第四行地址，虽然这里没有第四行，但不影响它单独放在sizeof里面，所以表示
										//整个数组的大小，这个数组跟a[0],a[1]哪些是一样的道理，都是4个元素
	return 0;
}

//int main()
//{
//	//一维数组
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(a + 0));
//	printf("%d\n", sizeof(*a));
//	printf("%d\n", sizeof(a + 1));
//	printf("%d\n", sizeof(a[1]));
//	printf("%d\n", sizeof(&a));
//	printf("%d\n", sizeof(*&a));
//	printf("%d\n", sizeof(&a + 1));
//	printf("%d\n", sizeof(&a[0]));
//	printf("%d\n", sizeof(&a[0] + 1));
//	return 0;
//}






//int main()
//{
//	//字符数组
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%d\n", sizeof(arr));
//	printf("%d\n", sizeof(arr + 0));
//	printf("%d\n", sizeof(*arr));
//	printf("%d\n", sizeof(arr[1]));
//	printf("%d\n", sizeof(&arr));
//	printf("%d\n", sizeof(&arr + 1));
//	printf("%d\n", sizeof(&arr[0] + 1));
//	printf("%d\n", strlen(arr));
//	printf("%d\n", strlen(arr + 0));
//	//printf("%d\n", strlen(*arr));  //这两个注释掉，因为这是程序错误的写法
//	//printf("%d\n", strlen(arr[1]));//没有结果输出
//	printf("%d\n", strlen(&arr));
//	printf("%d\n", strlen(&arr + 1));
//	printf("%d\n", strlen(&arr[0] + 1));
//	return 0;
//}

int main()
{




	//char arr[] = "abcdef";
	//printf("%d\n", sizeof(arr));
	//printf("%d\n", sizeof(arr + 0));
	//printf("%d\n", sizeof(*arr));
	//printf("%d\n", sizeof(arr[1]));
	//printf("%d\n", sizeof(&arr));
	//printf("%d\n", sizeof(&arr + 1));
	//printf("%d\n", sizeof(&arr[0] + 1));
	//printf("%d\n", strlen(arr));
	//printf("%d\n", strlen(arr + 0));
	////printf("%d\n", strlen(*arr));
	////printf("%d\n", strlen(arr[1]));
	//printf("%d\n", strlen(&arr));
	//printf("%d\n", strlen(&arr + 1));
	//printf("%d\n", strlen(&arr[0] + 1));


	//char* p = "abcdef";
	//printf("%d\n", sizeof(p));
	//printf("%d\n", sizeof(p + 1));
	//printf("%d\n", sizeof(*p));
	//printf("%d\n", sizeof(p[0]));
	//printf("%d\n", sizeof(&p));
	//printf("%d\n", sizeof(&p + 1));
	//printf("%d\n", sizeof(&p[0] + 1));
	//printf("%d\n", strlen(p));
	//printf("%d\n", strlen(p + 1));
	////printf("%d\n", strlen(*p));
	////printf("%d\n", strlen(p[0]));
	//printf("%d\n", strlen(&p));
	//printf("%d\n", strlen(&p + 1));
	//printf("%d\n", strlen(&p[0] + 1));


//
//	//二维数组
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(a[0][0]));
//	printf("%d\n", sizeof(a[0]));
//	printf("%d\n", sizeof(a[0] + 1));
//	printf("%d\n", sizeof(*(a[0] + 1)));
//	printf("%d\n", sizeof(a + 1));
//	printf("%d\n", sizeof(*(a + 1)));
//	printf("%d\n", sizeof(&a[0] + 1));
//	printf("%d\n", sizeof(*(&a[0] + 1)));
//	printf("%d\n", sizeof(*a));
//	printf("%d\n", sizeof(a[3]));
//
//	return 0;
//}