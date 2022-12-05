#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int cmp_int(const void* e1, const void* e2)
{
    return ((*(int*)e1) - *((int*)e2));
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    qsort(nums1, nums1Size, sizeof(int), cmp_int);
    qsort(nums2, nums2Size, sizeof(int), cmp_int);

    int i = 0;
    int j = 0;
    (*returnSize) = 0;
    int* ret = (int*)malloc(1000 * sizeof(int));
    while ((i < nums1Size) && (j < nums2Size))
    {
        if (nums1[i] == nums2[j])
        {
            ret[(*returnSize)] = nums1[i];
            (*returnSize)++;
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
        
    }
    return ret;
}

//int main()
//{
//    int arr1[] = { 4,9,5 };
//    int sz1 = sizeof(arr1) / sizeof(arr1[0]);
//    int arr2[] = { 9,4,9,8,4 };
//    int sz2 = sizeof(arr2) / sizeof(arr2[0]);
//    int returnsize = 0;
//
//    intersect(arr1, sz1, arr2, sz2, &returnsize);
//    return 0;
//}

void Print(char** arr)
{
    printf("%s", arr[0]);
}

int main()
{
    char* arr[3] = { 0 };
    Print(arr);
    //printf("%s", arr[1]);
    return 0;
}