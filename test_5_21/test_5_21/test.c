#define _CRT_SECURE_NO_WARNINGS



//将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I
/*
    解法：1.可以先将整个字符串进行逆置
          2.然后再把每一个单词进行逆置
*/
//#include<stdio.h>
//void reverse(char* arr, char* left, char* right)
//{
//    while (left < right)
//    {
//        char tem = *left;
//        *left = *right;
//        *right = tem;
//        left++;
//        right--;
//    }
//}
//int main()
//{
//    char arr[101] = { 0 };
//    gets(arr);
//    int len = strlen(arr);
//    //整句逆置
//    reverse(arr, arr, arr + len - 1);
//    //单词逆置
//    char* start = arr;
//
//    while (*start)
//    {
//        char* end = start;
//        while (*end != ' ' && *end != '\0')
//        {
//            end++;
//        }
//        reverse(arr, start, end - 1);
//        if (*end != '\0')
//            end++;
//        start = end;
//    }
//
//
//
//    printf("%s", arr);
//    return 0;
//}

//
//有序序列合并
//#include<stdio.h>
//int main()
//{
//    int n, m;
//    scanf("%d %d", &n, &m);
//    int arr1[n];
//    int arr2[m];
//    int i = 0;
//    //获取数据
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr1[i]);
//    }
//    for (i = 0; i < m; i++)
//    {
//        scanf("%d", &arr2[i]);
//    }
//    int arr[n + m];
//    int j = 0;
//    int k = 0;
//    i = 0;
//    //依次比较，把小的放尾插到新数组
//    while (i < n && j < m)
//    {
//        if (arr1[i] > arr2[j])
//        {
//            arr[k] = arr2[j];
//            k++;
//            j++;
//        }
//        if (arr1[i] <= arr2[j])
//        {
//            arr[k] = arr1[i];
//            k++;
//            i++;
//        }
//    }
//    //把剩余其中没有比较完的数直接尾插到新数组
//    while (i < n)
//    {
//        arr[k++] = arr1[i++];
//    }
//    while (j < m)
//    {
//        arr[k++] = arr2[j++];
//    }
//    for (i = 0; i < k; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//小乐乐喜欢数字，尤其喜欢0和1。他现在得到了一个数，想把每位的数变成0或1。如果某一位是奇数，就把它变成1，如果是偶数，那么就把它变成0。请你回答他最后得到的数是多少。
//输入：
//222222
//
//输出：
//0

//#include<stdio.h>
//int main()
//{
//    long int n = 0;
//    scanf("%ld", &n);
//    int arr[10] = { 0 };
//    int k = 0;
//    //用数组将每一位数对应是否为奇偶存起来
//    while (n)
//    {
//        if ((n % 10) % 2 == 0)
//        {
//            arr[k++] = 0;
//        }
//        if ((n % 10) % 2 == 1)
//        {
//            arr[k++] = 1;
//        }
//        n = n / 10;
//    }
//    int i = 0;
//    int left = 0;
//    int right = k - 1;
//    //然后将数组逆置
//    while (left < right)
//    {
//        int tem = arr[left];
//        arr[left] = arr[right];
//        arr[right] = tem;
//        left++;
//        right--;
//    }
//    int flag = 0;
//    //如果第一位为零则不输入，直到有1或者已经是最后一位了再输出对数组的数
//    for (i = 0; i < k; i++)
//    {
//        if (arr[i] != 0)
//        {
//            flag = 1;
//        }
//        //i+1==k是防止全是零的情况
//        if (flag == 1 || i + 1 == k)
//        {
//            printf("%d", arr[i]);
//        }
//    }
//
//    return 0;
//}

//
//
//#include<stdio.h>
//
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        int i = 0;
//        int j = 0;
//        for (i = 1; i <= n; i++)
//        {
//            for (j = 0; j < 2 * (n - i); j++)
//            {
//                printf(" ");
//            }
//            for (j = 1; j <= i; j++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//
//KiKi非常喜欢网购，在一家店铺他看中了一件衣服，他了解到，如果今天是“双11”（11月11日）则这件衣服打7折，“双12” （12月12日）则这件衣服打8折，如果有优惠券可以额外减50元（优惠券只能在双11或双12使用），求KiKi最终所花的钱数。
//#include<stdio.h>
//int main()
//{
//    float m = 0;
//    int month = 0;
//    int day = 0;
//    int y = 0;
//    scanf("%f %d %d %d", &m, &month, &day, &y);
//    if (month == 11 && day == 11)
//    {
//        if (y == 1)
//        {
//            m = m * 0.7 - 50;
//        }
//        else
//        {
//            m = m * 0.7;
//        }
//    }
//    else if (month == 12 && day == 12)
//    {
//        if (y == 1)
//        {
//            m = m * 0.8 - 50;
//        }
//        else
//        {
//            m = m * 0.8;
//        }
//    }
//    else
//    {
//        if (y == 1)
//        {
//            m = m - 50;
//        }
//    }
//    if (m < 0.0)
//    {
//        m = 0.0;
//    }
//    printf("%0.2f", m);
//    return 0;
//}

//
//
//#include<stdio.h>
//#include<string.h>
//void reverse(char* arr, char* left, char* right)
//{
//    while (left < right)
//    {
//        char tem = *left;
//        *left = *right;
//        *right = tem;
//        right--;
//        left++;
//    }
//}
//int main()
//{
//    char arr[101] = { 0 };
//    gets(arr);
//    int len = strlen(arr);
//    //整个字符串逆置
//    reverse(arr, arr, arr + len - 1);
//
//    char* start = arr;
//    while (*start!='\0')
//    {
//        char* end = start;
//        while (*end != ' ' && *end!='\0')
//        {
//            end++;
//        }
//        reverse(arr, start, end - 1);
//        if (end != '\0')
//            end++;
//        start = end;
//    }
//    printf("%s", arr);
//    return 0;
//}


//测试一下文件操作
//#include <stdio.h>
//int main()
//{
//    double a[5] = { 1.,2.,3.,4.,5. };
//    FILE* pf = fopen("text.txt", "rb");
//    if (pf == NULL)
//    {
//        printf("file\n");
//    }
//    double b[5] = {0};
//    double c = 0;
//    int i = 0;
//    for ( i = 0; i < 5; i++)
//    {
//        fread(&c, sizeof (c), 1, pf);
//        b[i] = c;
//    }
//    for (i = 0; i < 5; i++)
//    {
//        printf("%lf ", b[i]);
//    }
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}