#define _CRT_SECURE_NO_WARNINGS


//珠玑妙算游戏
int* masterMind(char* solution, char* guess, int* returnSize) {

    int* a = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    a[0] = a[1] = 0;
    for (int i = 0; i < 4; i++)
    {
        if (solution[i] == guess[i])
        {
            a[0]++;
            //猜中的置成其他值
            solution[i] = '1';
            guess[i] = '0';
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (solution[i] == guess[j])
            {
                a[1]++;
                //伪猜中的也置成其他值
                solution[i] = '1';
                guess[j] = '0';
            }
        }
    }
    return a;
}


//两数之和
//输入：
//[3, 2, 4], 6
//复制
//返回值：
//[2, 3]
//复制
//说明：
//因为 2 + 4 = 6 ，而 2的下标为2 ， 4的下标为3 ，又因为 下标2 < 下标3 ，所以返回[2, 3]
int* twoSum(int* numbers, int numbersLen, int target, int* returnSize) {
    // write code here
    int* a = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i = 0; i < numbersLen; ++i)
    {
        if (numbers[i] > target)
            continue;
        for (int j = 0; j < numbersLen; ++j)
        {
            if (j != i && numbers[i] + numbers[j] == target)
            {
                if (i > j)
                {
                    a[0] = j + 1;
                    a[1] = i + 1;
                }
                else
                {
                    a[0] = i + 1;
                    a[1] = j + 1;
                }
            }
        }
    }
    return a;
}

//输入：
//abABCcDEF
//6
//
//输出：
//abABCc
#include<stdio.h>

int main()
{
    char arr[1001];
    scanf("%s", arr);
    int n;
    scanf("%d", &n);
    arr[n] = '\0';
    printf("%s\n", arr);
    return 0;
}