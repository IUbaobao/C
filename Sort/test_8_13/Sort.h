#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Stack.h"

void PrintArray(int* a, int n);


//╡ЕхКеепР 
void InsertSort(int* a, int n);
//оё╤ШеепР
void ShellSort(int* a, int n);
//я║тЯеепР
void SelectSort(int* a, int n);
//╤яеепР
void HeapSort(int* a, int n);
//ц╟ещеепР
void BubbleSort(int* a, int n);
//©ЛкыеепР
void QuickSort(int* a, int left, int right);

// ©ЛкыеепР ╥г╣щ╧Ий╣ож
void QuickSortNonR(int* a, int left, int right);