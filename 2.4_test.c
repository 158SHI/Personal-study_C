#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool canJump(int* nums, int numsSize)
{
    int maxJump = 0;//目前为止可到达的最远位置
    for (int pos = 0; pos < numsSize; pos++)
    {
        int thisPosMaxJump = pos + nums[pos];//从当前位置可以到达的最远位置
        //从此位置能到达终点，直接返回true
        if (thisPosMaxJump == numsSize - 1) {
            return true;
        }
        //无法到达此位置，返回false
        if (pos > maxJump) {
            return false;
        }
        //更新最远位置
        maxJump = maxJump > thisPosMaxJump ? maxJump : thisPosMaxJump;
    }
    return true;
}

int cmp_int(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}

int getMaximumConsecutive(int* coins, int coinsSize)
{
    int res = 1;
    qsort(coins, coinsSize, sizeof(int), cmp_int);
    for (int i = 0; i < coinsSize; i++)
    {
        if (coins[i] > res) {
            break;
        }
        res += coins[i];
    }
    return res;
}

