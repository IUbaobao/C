#define _CRT_SECURE_NO_WARNINGS

//
//// 挖坑法
//int PartSort2(int* a, int left, int right)
//{
//	// 三数取中
//	int mid = GetMidIndex(a, left, right);
//	Swap(&a[left], &a[mid]);
//
//	int key = a[left];
//	int hole = left;
//	while (left<right)
//	{
//		//找小
//		while (left < right && a[right] >= key)
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			a[hole] = a[right];
//			hole = right;
//		}
//		
//		//找大
//		while (left < right && a[left] < key)
//		{
//			left++;
//		}
//		if (left < right)
//		{
//			a[hole] = a[left];
//			hole = left;
//		}
//
//	}
//	a[hole] = key;
//}


// 前后指针法
int PartSort3(int* a, int left, int right)
{
	// 三数取中
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);
	int key = left;
	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (a[cur] < key)
		{
			Swap(&a[++prev], &a[cur]);
		}

		cur++;
	}
	Swap(&a[key], &a[prev]);
	
	return prev;
}