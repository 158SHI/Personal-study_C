#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool canJump(int* nums, int numsSize)
{
    int maxJump = 0;//ĿǰΪֹ�ɵ������Զλ��
    for (int pos = 0; pos < numsSize; pos++)
    {
        int thisPosMaxJump = pos + nums[pos];//�ӵ�ǰλ�ÿ��Ե������Զλ��
        //�Ӵ�λ���ܵ����յ㣬ֱ�ӷ���true
        if (thisPosMaxJump == numsSize - 1) {
            return true;
        }
        //�޷������λ�ã�����false
        if (pos > maxJump) {
            return false;
        }
        //������Զλ��
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

