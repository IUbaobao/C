#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//
//
//void AdjustArr(int* p, int len)
//{
//	int left = 0;
//	int right = len - 1;
//	while (left < right)
//	{
//		//�ҳ���߲�Ϊ������
//		while (p[left] % 2 != 0 && left < right)
//		{
//			left++;
//		}
//		//�ҳ��ұ߲�Ϊż����
//		while (p[right] % 2 == 0 && left < right)
//		{
//			right--;
//		}
//		//����
//		if (p[left] % 2 == 0 && p[right] % 2 != 0 && left < right)
//		{
//			int tem = p[left];
//			p[left] = p[right];
//			p[right] = tem;
//		}
//	}
//}
//int main()
//{
//	int arr[10] = {0};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	//����
//	AdjustArr(arr, sz);
//	
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//    char a[1000];
//    int i;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", strlen(a));
//    return 0;
//}
