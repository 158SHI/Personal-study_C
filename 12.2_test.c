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

//������Ʊ�����ʱ��
//int maxProfit(int* prices, int pricesSize)
//{
//    int max = 0, minprice = 10001;
//    for (int i = 0; i < pricesSize; i++)
//    {
//        if (prices[i] < minprice)//��¼���Ʊ��
//        {
//            minprice = prices[i];
//        }
//        if (prices[i] - minprice > max)//��¼�������
//        {
//            max = prices[i] - minprice;
//        }
//
//    }
//    return max;
//}

//��һ


//ֻ����һ�ε�����

//������

//һά����Ķ�̬��

//ɾ�����������е��ظ���
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
    return ++j;//ע��j�ĳ�ʼֵ��0
}