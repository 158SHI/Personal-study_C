#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main()
//{
//	int i = 0;
//	int j = 0;
//
//	int n = 10;
//	int arr[20][20] = { 0 };
//
//	for ( i = 0; i < n; i++)
//	{
//		for ( j = 0; j <= i; j++)
//		{
//			if (i == j || j == 0)
//			{
//				arr[i][j] = 1;
//			}
//			else
//			{
//				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//			}
//			printf("%d ", arr[i][j]);
//
//		}
//		printf("\n");
//	}
//	return 0;
//}

//买卖股票的最佳时机
//int maxProfit(int* prices, int pricesSize)
//{
//    int max = 0, minprice = 10001;
//    for (int i = 0; i < pricesSize; i++)
//    {
//        if (prices[i] < minprice)//记录最低票价
//        {
//            minprice = prices[i];
//        }
//        if (prices[i] - minprice > max)//记录最高利润
//        {
//            max = prices[i] - minprice;
//        }
//
//    }
//    return max;
//}

//加一


//只出现一次的数字

//回文数

//一维数组的动态和

//删除有序数组中的重复项
int removeDuplicates(int* nums, int numsSize)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < numsSize; )
    {
        if (nums[i] == nums[j])
        {
            i++;
        }
        else
        {
            nums[++j] = nums[i++];
        }
    }
    return ++j;//注意j的初始值是0
}