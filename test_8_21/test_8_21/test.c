#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>

void Swap(int* e1, int* e2)
{
	int tem = *e1;
	*e1 = *e2;
	*e2 = tem;
}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{

		int end = i;
		int tem = a[end + 1];
		while (end >= 0)
		{
			if (tem < a[end])
				a[end + 1] = a[end--];
			else
				break;
		}
		a[end + 1] = tem;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i+=gap)
		{

			int end = i;
			int tem = a[end + gap];
			while (end >= 0)
			{
				if (tem < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}	
				else
					break;
			}
			a[end + gap] = tem;
		}
	}
}

int main()
{
	int a[] = { 2,4,1,6,3,6,2,7,3,5,8,23 };
	int n = sizeof(a) / sizeof(a[0]);
	ShellSort(a, n);
	for(int i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}