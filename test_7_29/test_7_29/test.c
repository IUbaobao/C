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


    //������ǰn-k��
    Reverse(nums, 0, numsSize - k - 1);
    //���������k��
    Reverse(nums, numsSize - k, numsSize - 1);
    //����������
    Reverse(nums, 0, numsSize - 1);
}