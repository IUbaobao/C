#define _CRT_SECURE_NO_WARNINGS



//��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing. �����������Ϊ��beijing. like I
/*
    �ⷨ��1.�����Ƚ������ַ�����������
          2.Ȼ���ٰ�ÿһ�����ʽ�������
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
//    //��������
//    reverse(arr, arr, arr + len - 1);
//    //��������
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
//�������кϲ�
//#include<stdio.h>
//int main()
//{
//    int n, m;
//    scanf("%d %d", &n, &m);
//    int arr1[n];
//    int arr2[m];
//    int i = 0;
//    //��ȡ����
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
//    //���αȽϣ���С�ķ�β�嵽������
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
//    //��ʣ������û�бȽ������ֱ��β�嵽������
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

//С����ϲ�����֣�����ϲ��0��1�������ڵõ���һ���������ÿλ�������0��1�����ĳһλ���������Ͱ������1�������ż������ô�Ͱ������0������ش������õ������Ƕ��١�
//���룺
//222222
//
//�����
//0

//#include<stdio.h>
//int main()
//{
//    long int n = 0;
//    scanf("%ld", &n);
//    int arr[10] = { 0 };
//    int k = 0;
//    //�����齫ÿһλ����Ӧ�Ƿ�Ϊ��ż������
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
//    //Ȼ����������
//    while (left < right)
//    {
//        int tem = arr[left];
//        arr[left] = arr[right];
//        arr[right] = tem;
//        left++;
//        right--;
//    }
//    int flag = 0;
//    //�����һλΪ�������룬ֱ����1�����Ѿ������һλ����������������
//    for (i = 0; i < k; i++)
//    {
//        if (arr[i] != 0)
//        {
//            flag = 1;
//        }
//        //i+1==k�Ƿ�ֹȫ��������
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
//KiKi�ǳ�ϲ����������һ�ҵ�����������һ���·������˽⵽����������ǡ�˫11����11��11�գ�������·���7�ۣ���˫12�� ��12��12�գ�������·���8�ۣ�������Ż�ȯ���Զ����50Ԫ���Ż�ȯֻ����˫11��˫12ʹ�ã�����KiKi����������Ǯ����
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
//    //�����ַ�������
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


//����һ���ļ�����
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