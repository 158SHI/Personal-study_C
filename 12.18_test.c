#define _CRT_SECURE_NO_WARNINGS 1

#include<stdbool.h>
#include<stdio.h>

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
    return left;
}

int main()
{
    int arr[] = { 1,2,3,3,10 };
    //int arr[] = { -5,-4,-3,-2 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", Func(arr, sz));
    return 0;
}