#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<assert.h>
#include<string.h>


//模拟实现memmove
//void* my_memmove(void* des, const void* src, size_t num)
//{
//	assert(des && src);
//	void* ret = des;
//
//	if (des < src)
//	{
//		//从前往后
//		while (num--)
//		{
//			*(char*)des = *(char*)src;
//			//(char*)des = (char*)des + 1;
//			//(char*)src = (char*)src + 1;
//			((char*)des)++;
//
//		}
//	}
//	else
//	{
//		//从后往前
//		while (num--)
//		{
//			*((char*)des + num) = *((char*)src + num);
//		}
//	}
//	return  ret;
//}
void* my_memmove(void* des, void* src, size_t num)
{
    assert(des && src);
    void* ret = des;
    if (des < src)
    {
        //从前往后
        while (num--)
        {
            *((char*)des) = *((char*)src);
            (char*)des = (char*)des + 1;
            (char*)src = (char*)src + 1;
        }
    }
    else
    {
        //从后往前
        while (num--)
        {
            *((char*)des + num) = *((char*)src + num);
        }
    }
    return  ret;
}


int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int* ret = my_memmove(arr + 2, arr, 16);
    
	return 0;
}