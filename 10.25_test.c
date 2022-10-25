#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//9*9乘法表
//int main()
//{
//    for (int i = 1; i <= 9; i++)
//    {
//        for (int j = 1; j <= i; j++)
//        {
//            printf("%d*%d=%-2d ", i, j, i * j);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//求10个整数中的最大值

//int main()
//{
//	int n;
//	int max = -9999;
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &n);
//		if (n>max)
//		{
//			max = n;
//		}
//	}
//	printf("最大值为%d\n", max);
//	return 0;
//}

//分数求和
//int main()
//{
//	int flag = 1;
//	float ret = 0;
//	for (int i = 1; i <= 100; i++)
//	{
//		ret += flag * (1.0 / i);
//		flag = -flag;
//	}
//	printf("%f\n", ret);
//	return 0;
//}

//1到100整数中出现9的个数
//int main()
//{
//	//个位是9
//	//十位是9
//	int count = 0;
//	for (int i = 1; i <= 100; i++)
//	{
//		if (i/10 == 9)
//		{
//			count++;
//		}
//		if (i%10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

//二分查找
//int main()
//{
//	int arr[] = { -2,1,4,6,7,8,12,14 };
//	int n;
//	printf("请输入要查找的数字>:");
//	scanf("%d", &n);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	while (left<=right)
//	{
//		int mid = left + (right - left) / 2;//防止溢出
//		if (arr[mid]>n)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < n)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，该元素下标为%d\n", mid);
//			break;
//		}
//	}
//	if (left>right)
//	{
//		printf("无法找到该元素\n");
//	}
//	return 0;
//}

//函数指针

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int ret = Add(3, 5);
//	printf("%d\n", ret);
//
//	int(*p)(int, int) = &Add;//函数指针
//
//	int ret2 = (*p)(10, 20);
//	printf("%d\n", ret2);
//	return 0;
//}


//公务员面试
//#include <stdio.h>
//int main()
//{
//    int mark;
//    int count = 0;
//    int sum = 0;
//    int max = 0;
//    int min = 101;
//    while (scanf("%d", &mark) != EOF)
//    {
//        if (mark > max)
//        {
//            max = mark;
//        }
//        if (mark < min)
//        {
//            min = mark;
//        }
//        sum += mark;
//        count++;
//
//        if (count == 7)
//        {
//            printf("%.2f", ((sum - max - min) / 5.0));
//            count = 0;
//            sum = 0;
//            max = 0;
//            min = 101;
//        }
//    }
//    return 0;
//}

//int main()
//{
//	int arr[] = { 2,12,4,2,3,21 };
//	for (int i = 0; i < 5; i++)
//	{
//		int key = arr[i];
//		int j = i - 1;
//	}
//	return 0;
//}


/*
* 筛选法求素数
* 
描述
用筛选法求n以内的素数。筛选法求解过程为：将2~n之间的正整数放在数组内存储，将数组中2之后的所有能被2整除的数清0，再将3之后的所有能被3整除的数清0 ，以此类推，直到n为止。数组中不为0 的数即为素数。
输入描述：
多组输入，每行输入一个正整数（不大于100）。
输出描述：
针对每行输入的整数n，输出两行，第一行，输出n之内（包括n）的素数，用空格分隔，

第二行，输出数组中2之后被清0 的个数。每行输出后换行。
示例1
输入：
20

输出：
2 3 5 7 11 13 17 19
11
*/


int main()
{
    int n;

    while (scanf("%d", &n) != EOF)
    {
        int count = 0;//计数器
        int arr[100] = { 0 };

        for (int i = 2; i < n; i++) //将2到n的数字存入数组arr中
        {
            arr[i - 2] = i;
        }

        for (int i = 0; i < n; i++) //进行数据操作
        {
            int key;
            if (arr[i] == 0) //选定基数且保证基数不为0
            {
                continue;
            }
            else
            {
                key = arr[i];
            }

            //向后清除
            for (int j = i + 1; j < n; j++)
            {
                int key2;
                if (arr[j] == 0)//使key2不等于0:避免重复的判断 0%key
                {
                    continue;
                }
                else
                {
                    key2 = arr[j];
                }

                if (key2 % key == 0)//能被基数整除，注意基数不能为0
                { 
                    arr[j] = 0; //将其赋值为0
                    count++;
                }
            }
        }
        //按条件输出
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                printf("%d ", arr[i]);
            }
        }
        printf("\n%d\n", count + 1);
    }
   return 0;
}

//求1！+2！+...+10！
//2!=1!*2
//3!=2!*3

//优化算法
//int main()
//{
//    int sum = 0;
//    int ret = 1;
//    for (int i = 1; i <= 10; i++)
//    {
//        ret *= i;
//        sum += ret;
//    }
//    printf("%d\n", sum);
//    return 0;
//}