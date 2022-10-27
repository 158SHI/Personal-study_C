#define _CRT_SECURE_NO_WARNINGS 1

//浅析摩尔投票算法

#include<stdio.h>


//引入


//void Bobble_sort(int arr[], int sz)
//{
//	for (int i = 0; i < sz-1; i++)
//	{
//		for (int j = 0; j < sz-1-i; j++)
//		{
//			if (arr[j]>arr[j+1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[50] = { 0 };
//	int sz = 0;
//	scanf("%d", &sz);
//	for (int i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	
//	//1.先排序，后判断
//	Bobble_sort(arr, sz);
//	int left = 0;
//	int right = sz - 1;
//	int mid = (left + right) / 2;
//	int count = 0;
//
//	for (int i = 0; i < sz; i++)
//	{
//		if (arr[i]==arr[mid])
//		{
//			count++;
//		}
//	}
//	if (count>(sz/2))
//	{
//		printf("该数字为：%d\n", arr[mid]);
//	}
//	else
//	{
//		printf("NO\n");
//	}
//	
//
//	/*
//	//2.计数器
//
//	int flag = 0;//假设不存在
//	for (int i = 0; i < sz-1; i++)
//	{
//		int key = arr[i];
//		int count = 1;
//		for (int j = i+1; j < sz; j++)
//		{
//			if (arr[j] == key)
//			{
//				count++;
//			}
//		}
//		if (count>(sz / 2))
//		{
//			printf("该数字为:%d\n", key);
//			flag = 1;
//			break;
//		}
//	}
//
//	if (flag==0)
//	{
//		printf("NO\n");
//	}*/
//
//	return 0;
//}

//摩尔投票算法求众数
void Moore(int arr[], int sz)
{
    int major;//第一次进入，第一个元素与第一个元素比较，cnt++
    int cnt = 0;
    for (int i = 0; i < sz; i++)
    {
        if (cnt == 0)//若cnt为0，则给major重新赋值
        {
            major = arr[i];
        }
        if (major == arr[i])//两数相等，无法抵消
        {
            cnt++;
        }
        else//两数不等，进行抵消
        {
            cnt--;
        }
    }
    if (cnt == 0)//数组中的数全部一一抵消，说明这样的数不存在
    {
        printf("NO\n");
    }
    else
    {
        printf("众数:%d\n",major);
    }
}

int main()
{
    int arr[] = { 1,2,1,3,1,1,2,1,5 };
    //int arr[] = { 1,1,2,2,3,3,4,4,4 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    Moore(arr, sz);
    return 0;
}