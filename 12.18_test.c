#define _CRT_SECURE_NO_WARNINGS 1

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

int Func(int* nums, int numsSize)
{
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (nums[mid] < 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    if (nums[left] >= 0)
    {
        return left;
    }
    else
    {
        return -1;
    }
}

int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
    int* ret = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    //寻找第一个非负数
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (nums[mid] < 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    //记录第一个非负数
    int neg = left;
    int key = nums[neg];

    //将各个元素平方
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] = nums[i] * nums[i];
    }

    //存在非负数
    if (key >= 0)
    {
        //双指针，择小放入返回数组
        int i = neg - 1;
        int j = neg;

        int k = 0;
        while ((i >= 0) && (j < numsSize))
        {
            if (nums[i] < nums[j])
            {
                ret[k] = nums[i];
                i--;
            }
            else
            {
                ret[k] = nums[j];
                j++;
            }
            k++;
        }

        //接入剩余元素
        if (i < 0)
        {
            while (j < numsSize)
            {
                ret[k] = nums[j];
                k++;
                j++;
            }
        }
        else if (j = numsSize)
        {
            while (i >= 0)
            {
                ret[k] = nums[i];
                k++;
                i--;
            }
        }
        return ret;
    }

    //不存在非负数
    else
    {
        //倒置数组
        int left = 0;
        int right = numsSize - 1;
        while (left < right)
        {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
        return nums;
    }

}

int main()
{
    //int arr[] = { 1,2,3,3,10 };
    //int arr[] = { -4,-3,-2,-1,0 };
    //int arr[] = { -5,-4,-3,-2 };
    int arr[] = { -10000,-9999,-7,-5,0,0,10000 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    //printf("%d\n", Func(arr, sz));

    int retsz = 0;
    sortedSquares(arr, sz, &retsz);
    return 0;
}