#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

/*
小乐乐与字符串
输入描述：
输入只包含大写字母的字符串s。(1 ≤ length ≤ 8000)
输出描述：
输出一个整数，为字符串s中子序列“CHN”的数量。
*/

//int main()
//{
//	char arr[8001] = { 0 };
//	scanf("%s", arr);
//	int c = 0;
//	int ch = 0;
//	long long chn = 0;
//	int i = 0;
//	while (arr[i])
//	{
//		if (arr[i] == 'C')
//		{
//			c++;
//		}
//		else if (arr[i] == 'H')
//		{
//			ch += c;
//		}
//		else if (arr[i] == 'N')
//		{
//			chn += ch;
//		}
//		i++;
//	}
//	printf("%d\n", chn);
//	return 0;
//}


/*
输入描述：
多组输入，每组输入包含一个正整数n (1 ≤ n ≤ 99999)

题目保证测试数据总数不超过500组，当输入n=0时程序结束。
输出描述：
对于每组测试用例，输出正整数n，后面紧跟“: ”，输出答案并换行，即比n大且是n的倍数的最小二段数。
*/

//_Bool Judge(long long num)
//{
//	long long n = num;
//	int cnt1 = 0;
//	int cnt2 = 0;
//	int tmp = -1;
//	int key = -1;
//
//	int time = 1;
//	int con = 1;
//
//	int count = 0;//计算位数
//	while (n)
//	{
//		tmp = n % 10;
//		if ((tmp == num % 10) && con)
//		{
//			cnt1++;
//		}
//		else if ((tmp != num % 10) && time)
//		{
//			key = tmp;
//			con--;
//			time--;
//		}
//
//		if (tmp == key)
//		{
//			cnt2++;
//		}
//
//		n /= 10;
//		count++;
//	}
//
//	if (count == cnt1+cnt2)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		long long k = 1;
//		long long num = 0;
//		while (true)
//		{
//			if (n == 0)
//			{
//				return 0;
//			}
//
//			num = k * n;
//			//判断二段数
//			if (num > 9)
//			{
//				_Bool ret = Judge(num);
//				if (ret)
//				{
//					break;
//				}
//			}
//			k++;
//		}
//		printf("%d:%lld\n", n, num);
//	}
//	return 0;
//}

//去重排序
//void RemoveDup(int* p, int* sz)
//{
//    for (int i = 0; i < *sz - 1; i++)
//    {
//        for (int j = i + 1; j < *sz; j++)
//        {
//            if (p[i] == p[j])
//            {
//                for (int k = j; k < *sz - 1; k++)
//                {
//                    p[k] = p[k + 1];
//                }
//                j--;
//                (*sz)--;
//            }
//        }
//    }
//}
//
//int cmp_int(const void* e1, const void* e2)
//{
//    return *((int*)e1) - *((int*)e2);
//}
//
//int main()
//{
//    int n = 0;
//    int arr[100] = { 0 };
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    RemoveDup(arr, &n);//去重
//
//    qsort(arr, n, sizeof(arr[0]), cmp_int);//排序
//
//    for (int i = 0; i < n; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

int Plus(const int *x)
{
	return ++x;
}

int main()
{
	int a = 10;
	int ret = Plus(&a);
	return 0;
}