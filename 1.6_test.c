#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main()
//{
//	char arr[20] = { 0 };
//	int n = 5234;
//	sprintf(arr, "%d", n);
//	return 0;
//}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void Reserve(char* left, char* right)
{
    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

//int main()
//{
//    char arr[10001] = { 0 };
//    gets(arr);
//    int len = strlen(arr);
//    Reserve(arr, arr + len - 1);
//
//    char* begin = arr;
//    char* end = arr;
//
//    while (*end != '\0')
//    {
//        while (isalpha(*end))
//        {
//            end++;
//        }
//        Reserve(begin, end - 1);
//        begin = ++end;
//    }
//    //Êä³ö
//    for (int i = 0; i < len; i++)
//    {
//        if (!isalpha(arr[i]))
//        {
//            arr[i] = ' ';
//        }
//    }
//    char* output = strtok(arr, " ");
//    while (output != NULL)
//    {
//        printf("%s ", output);
//        output = strtok(NULL, " ");
//    }
//    return 0;
//}

//int main()
//{
//    char arr[100] = "  hello      world ";
//    char* tmp = strtok(arr, " ");
//    while (tmp != NULL)
//    {
//        printf("%s\n", tmp);
//        tmp = strtok(NULL, " ");
//    }
//    return 0;
//}

#include<stdbool.h>

int binarySearch(int* nums, int numsSize, int target, bool lower)
{
    int left = 0, right = numsSize - 1, ans = numsSize;
    while (left <= right) 
    {
        int mid = (left + right) / 2;
        if (nums[mid] > target || (lower && nums[mid] == target))
        {
            right = mid - 1;
            ans = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int search(int* nums, int numsSize, int target)
{
    int leftIdx = binarySearch(nums, numsSize, target, true);
    int rightIdx = binarySearch(nums, numsSize, target, false) - 1;
    int ret = 0;
    if (leftIdx <= rightIdx && rightIdx < numsSize && 
        nums[leftIdx] == target && nums[rightIdx] == target) 
    {
        ret = rightIdx - leftIdx + 1;
    }
    return ret;
}

int main()
{
    int arr[] = { 5,7,7,8,8,10 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    int ret = search(arr, sz, 8);
    printf("%d\n", ret);
    return 0;
}