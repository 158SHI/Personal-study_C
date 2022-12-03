#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//void Fib(int f[20], int n)
//{
//	int i;
//	f[0] = 0; f[1] = 1;
//	for (i = 2; i <= n; i++)
//	{
//		f[i] = f[i - 1] + f[i - 2];
//	}
//}
//
//int main()
//{
//	int n = 5;
//	int arr[20] = { 0 };
//	Fib(arr, n);
//	return 0;
//}

/*
用函数编程将一组数据的最大数与最小数位置互换。主函数输入10个整数并输出互换后的数组。
*/

//void Exchange(int* p)
//{
//	int max = 0;
//	int min = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		if (p[i] > p[max])
//		{
//			max = i;
//		}
//		if (p[i] < p[min])
//		{
//			min = i;
//		}
//	}
//	int tmp = p[min];
//	p[min] = p[max];
//	p[max] = tmp;
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	Exchange(arr);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

/*
用函数编程计算n×n阶矩阵两条对角线上的各元素之和。主函数输入n×n阶矩阵并输出和。
*/

//int MatSum(int n)
//{
//	int i = 0, j = 0;
//	int tmp = 0;
//	int sum = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &tmp);
//			//if ((i == j) || (i + j == n - 1))
//			//{
//			//	sum += tmp;
//			//}
//			if (i == j)
//			{
//				sum += tmp;
//			}
//			if (i + j == n - 1)
//			{
//				sum += tmp;
//			}
//		}
//	}
//	return sum;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = MatSum(n);
//	printf("%d\n", ret);
//	return 0;
//}

//杨辉三角

//void YhTra(int n)
//{
//	int arr[31][31] = { 0 };
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			if (j == 0 || i == j)
//			{
//				arr[i][j] = 1;
//			}
//			else
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	YhTra(n);
//	return 0;
//}


//反转链表
typedef struct ListNode ListNode;
 struct ListNode 
 {
    int val;
    struct ListNode* next;   
};
//
//struct ListNode* reverseList(struct ListNode* head)
//{
//
//    ListNode* cur = head;
//    ListNode* pre = NULL;
//    while (cur->next != NULL)
//    {
//        ListNode* next = cur->next;
//        cur->next = pre;
//        pre = cur;
//        cur = next;
//    }
//    return cur;
//
//}
#include<stdbool.h>

//回文链表
//typedef struct ListNode ListNode;
//_Bool isPalindrome(struct ListNode* head)
//{
//    ListNode* cur = head;
//    int count = 0;
//    int arr[100] = { 0 };
//    while (cur->next != NULL)
//    {
//        arr[count] = cur->val;
//        count++;
//        cur = cur->next;
//    }
//
//    int left = 0;
//    int right = count;
//    while (left < right)
//    {
//        if (arr[left] != arr[right])
//        {
//            return false;
//        }
//        left++;
//        right--;
//    }
//
//    return true;
//}

 /*_Bool test(int* p)
 {
     int left = 0;
     int right = 3;
    while(left < right)
    {
        if (p[left] != p[right])
        {
            return false;
        }
        left++;
        right--;
    }
 }

int main()
{
    int arr[] = { 1,2,2,1 };
    _Bool ret = test(arr);
    return 0;
}*/

 //找次大值
 //无效
 //int Smax(int* p, int sz)
 //{
 //    if (sz == 1)
 //    {
 //        return -1;
 //    }

 //    int max = p[0];
 //    int smax = -1;

 //    int i = 0;
 //    int j = 1;
 //    while (i < sz || j < sz)
 //    {
 //        if ((p[j] > max) && (j < sz))
 //        {
 //            max = p[j];
 //        }
 //        if ((p[i] > smax) && (p[i] < max))
 //        {
 //            smax = p[i];
 //        }
 //        i++;
 //        j++;
 //    }
 //    if (max == smax)//不存在次小值
 //    {
 //        return -1;
 //    }
 //    else
 //    {
 //        return smax;
 //    }
 //}

 //int main()
 //{
 //    //int arr[] = { 10,6,7,9,11,5 };
 //    //int arr[] = { 1,1,1,1,1 };
 //    //int arr[] = { 1 };
 //    //int arr[] = { 1,1,1,1,1,11 };
 //    //int arr[] = { 8,3,4,4 };
 //    
 //    int arr[] = { 2,2,2,3,2,0,3,3,1,2,0,3,0,3,1,5,2,3,2,5,6,5,2,9 };
 //    int sz = sizeof(arr) / sizeof(arr[0]);
 //    int ret = Smax(arr, sz);
 //    printf("%d\n", ret);
 //    return 0;
 //}