#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//#include<string.h>
//
//void Reverse(char* a, int left, int right)
//{
//	while (left < right)
//	{
//		char tem = a[left];
//		a[left] = a[right];
//		a[right] = tem;
//
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char arr[] = "I like beijing";
//	int sz = strlen(arr)-1;
//	//整个字符串逆置
//	Reverse(arr, 0,sz);
//
//	int i = 0;
//	int k = 0;
//	//然后逆置每一个单词
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] == ' ')
//		{
//			Reverse(arr, k, i-1);
//			k = i + 1;
//		}
//	}
//	printf("%s", arr);
//	return 0;
//}



//#include<stdio.h>
//
//void QuickSort(int* a, int L, int R)
//{
//	if (L >= R)
//		return;
//	int left = L;
//	int right = R;
//	int point = a[left];
//
//	while (left<right)
//	{
//		while (left < right && a[right] >= point)
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			a[left++] = a[right];
//		}
//
//		while (left < right && a[left] <= point)
//		{
//			left++;
//		}
//		if (left < right)
//		{
//			a[right--] = a[left];
//		}
//		
//	}
//	a[left] = point;
//
//	QuickSort(a, L, right - 1);
//	QuickSort(a, left + 1, R);
//
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	QuickSort(arr, 0, 9);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}





