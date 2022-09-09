#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Stack.h"
#include<string.h>

void PrintArray(int* a, int n);


//�������� 
void InsertSort(int* a, int n);
//ϣ������
void ShellSort(int* a, int n);
//ѡ������
void SelectSort(int* a, int n);
//������
void HeapSort(int* a, int n);
//ð������
void BubbleSort(int* a, int n);
//��������
void QuickSort(int* a, int left, int right);

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);

// ��������
void CountSort(int* a, int n);
