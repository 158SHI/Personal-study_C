#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int a = -1;
//	int b = a >> 1;
//	return 0;
//}


int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    //哈希表
    int* cnt = (int*)calloc(numsSize, sizeof(int));
    int* retNums = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        cnt[nums[i] - 1]++;
    }
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (cnt[i] == 0)
        {
            retNums[(*returnSize)] = i + 1;
            (*returnSize)++;
        }
    }
    return retNums;
}

//int main()
//{
//    int arr[] = { 4,3,2,7,8,2,3,1 };
//    //int arr[] = { 1,1 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    int returnSize = 0;
//    findDisappearedNumbers(arr, sz, &returnSize);
//    return 0;
//}

//int Add(int x, int y)
//{
//    return x + y;
//}
//
//int main()
//{
//    int sum1 = Add(2, 3);
//    printf("%d", sum1);
//
//    int (*pAdd)(int, int) = Add;
//    int (**ppAdd)(int, int) = &pAdd;
//    int sum2 = pAdd(2, 3);
//    printf("%d", sum2);
//
//    return 0;
//}

//int main()
//{
//    int (*p1)(int, int) = Add;
//    int (*p2)(int, int) = &Add;
//    printf("%d\n", Add(2, 4));
//
//    printf("%d\n", (***Add)(2, 4));
//
//    printf("%d\n", (*p1)(2, 4));
//    printf("%d\n", p1(2, 4));
//    return 0;
//}

/*
有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。

要求：时间复杂度小于O(N);
*/

//二分查找
int* BinarySearch(int arr[4][4], int row, int col, int aim, int* retSize)
{
    int r = 0;
    int c = col - 1;
    *retSize = 2;
    int* retNums = malloc(sizeof(int) * 2);
    while (r >= 0 && r < row && c >= 0 && c < col)
    {
        if (aim < arr[r][c])
        {
            c--;
        }
        else if (aim > arr[r][c])
        {
            r++;
        }
        else
        {
            break;
        }
    }
    if (arr[r][c] == aim)
    {
        retNums[0] = r;
        retNums[1] = c;
    }
    else
    {
        retNums[0] = -1;
        retNums[1] = -1;
    }
    return retNums;
}

int main()
{
    int arr[4][4] = {
        1, 5, 7, 9,
        4, 6, 10, 15,
        8, 11, 12, 19,
        14, 16, 18, 21 };
    int n = 0;
    printf("请输入要查找的数字:");
    scanf("%d", &n);
    int count = 0;
    int* retNums = BinarySearch(arr, 4, 4, n, &count);
    if (retNums[0] == -1)
    {
        printf("无法找到该数字\n");
    }
    else
    {
        printf("该数字的下标为 %d %d\n", retNums[0], retNums[1]);
    }
    return 0;
}

/*
实现一个函数，可以左旋字符串中的k个字符。

例如：

ABCD左旋一个字符得到BCDA

ABCD左旋两个字符得到CDAB
*/

#include<string.h>

void Rotate(char* left, char* right)
{
    char tmp = 0;
    while (left < right)
    {
        tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

void Reserve(char* arr, int k)
{
    //先旋转前k个，再旋转后len - k个，最后整体旋转
    int len = strlen(arr);
    k %= len;//考虑 k >= len的情况
    Rotate(arr, arr + k - 1);
    Rotate(arr + k, arr + len - 1);
    Rotate(arr, arr + len - 1);
}

//int main()
//{
//    char arr[100] = { 0 };
//    int k = 0;
//    printf("请输入一个字符串:");
//    scanf("%s", arr);
//    printf("请输入旋转字符个数k:");
//    scanf("%d", &k);
//    Reserve(arr, k);
//    printf("%s\n", arr);
//    return 0;
//}


/*
写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。

例如：给定 s1 = AABCD 和 s2 = BCDAA ，返回1
给定 s1=abcd 和 s2=ACBD ，返回0.

AABCD左旋一个字符得到ABCDA  AABCDAABCD
AABCD左旋两个字符得到BCDAA
AABCD右旋一个字符得到DAABC
*/

int Judge(char* s1, char* s2)
{
    //先复制 s1,再在 s1 中寻找 s2 是否存在
    int len = strlen(s1);
    strncat(s1, s1, len);
    return strstr(s1, s2) == NULL ? 0 : 1;
}

//int main()
//{
//    char s1[200] = { 0 };
//    char s2[100] = { 0 };
//    printf("Input s1 = ");
//    gets(s1);
//    printf("Input s2 = ");
//    gets(s2);
//    int ret = Judge(s1, s2);
//    if (ret)
//    {
//        printf("Yes\n");
//    }
//    else
//    {
//        printf("No\n");
//    }
//    return 0;
//}