#define _CRT_SECURE_NO_WARNINGS

//
//// �ڿӷ�
//int PartSort2(int* a, int left, int right)
//{
//	// ����ȡ��
//	int mid = GetMidIndex(a, left, right);
//	Swap(&a[left], &a[mid]);
//
//	int key = a[left];
//	int hole = left;
//	while (left<right)
//	{
//		//��С
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
//		//�Ҵ�
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


// ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	// ����ȡ��
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