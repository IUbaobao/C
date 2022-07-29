#define _CRT_SECURE_NO_WARNINGS

void Reverse(int* a, int left, int right)
{
    while (left < right)
    {
        int tem = a[left];
        a[left] = a[right];
        a[right] = tem;
        left++;
        right--;
    }
}



void rotate(int* nums, int numsSize, int k) {

    k %= numsSize;


    //先逆置前n-k个
    Reverse(nums, 0, numsSize - k - 1);
    //再逆置最后k个
    Reverse(nums, numsSize - k, numsSize - 1);
    //整体再逆置
    Reverse(nums, 0, numsSize - 1);
}