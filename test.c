#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
    *returnSize = 2;
    int* retNums = (int*)malloc(sizeof(int) * 2);

    int key = 0;
    for (int i = 0; i < numsSize; i++)
    {
        key ^= nums[i];//key为两数异或运算的结果
    }
    int zeroEnd = 0;
    while (((key >> zeroEnd) & 1) == 0)
    {
        zeroEnd++;
    }
    int ret_ze = 0;
    int ret_nZe = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if ((nums[i] >> zeroEnd) & 1)//1
        {
            ret_nZe ^= nums[i];
        }
        else
        {
            ret_ze ^= nums[i];
        }
    }
    retNums[0] = ret_ze;
    retNums[1] = ret_nZe;
    return retNums;
}

void test1(void)
{
    int nums[] = { 1, 2, 5, 2 };
    int retSz = 0;
    singleNumbers(nums, 4, &retSz);

}

int main()
{
    test1();
    return 0;
}