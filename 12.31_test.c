#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>

/*
输入一个整数m，若m不是素数，则输出所有因子（不包括 1 ）
*/
//int main()
//{
//	int m = 0;
//	bool flag = true;
//	scanf("%d", &m);
//	for (int i = 2; i < m; i++)
//	{
//		if (m % i == 0)
//		{
//			printf("%d ", i);
//			flag = false;
//		}
//	}
//	if (flag)
//	{
//		printf("No divisor! It is a prime number\n");
//	}
//	return 0;
//}


void output(int a)
{
    for (int i = 2; i <= a; i++)
    {
        if (a % i == 0)
        {
            a = a / i;

            if (a == 1)
            {
                printf("%d", i);
                exit(-1); 
            }

            printf("%d * ", i);
            return output(a);
        }
    }
}

//int main()
//{
//    output(20);
//    return 0;
//}

int dominantIndex(int* nums, int numsSize)
{
    int maxi = 0;
    //找数组中的最大值的下标
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[maxi] < nums[i])
        {
            maxi = i;
        }
    }
    double max_b = nums[maxi] / 2.0;
    for (int i = 0; i < numsSize; i++)
    {
        if (i == maxi)
        {
            continue;
        }
        if (max_b < nums[i])
        {
            return -1;
        }
    }
    return maxi;
}

int main()
{
    int arr[] = { 3,6,1,0 };
    printf("%d\n", dominantIndex(arr, 4));
    return 0;
}