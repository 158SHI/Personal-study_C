#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//��С������

//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	
//	int i = 1;
//	while (a * i % b != 0)
//	{
//		i++;
//	}
//	printf("%d\n", a * i);
//	return 0;
//}

#include<string.h>

//��������

//void Reverse(char* left, char* right)
//{
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char arr[100] = { 0 };
//	gets(arr);
//	int len = strlen(arr);
//	Reverse(arr, arr + len - 1);//���������ַ���
//
//	//���򵥴�
//	char* cur = arr;
//
//	while (*cur != '\0')
//	{
//		char* start = cur;
//		while ((*cur != ' ') && (*cur != '\0'))
//		{
//			cur++;
//		}
//		Reverse(start, cur - 1);
//		if (*cur != '\0')
//		{
//			cur++;
//		}
//	}
//
//	puts(arr);
//
//	return 0;
//}

//��ʧ�����飬Ҫ��ʱ�临�Ӷ�ΪO(N)
/*
1.�ͼ���
2.�������
*/



//��ת����
/*
1.�������һ��Ԫ�أ�����ǰ���Ԫ��
2.�ռ任ʱ�䣬���⿪��һ������
3.�Ƚ�ǰn-k��Ԫ�����ã������ú�k��Ԫ�أ����������������
*/

//int removeElement(int* nums, int numsSize, int val)
//{
//    int i = 0;
//    int j = 0;
//    int count = numsSize;
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[i] != val)
//        {
//            nums[j++] = nums[i];
//        }
//        else
//        {
//            count--;
//        }
//    }
//    return count;
//}
//
//int main()
//{
//    int arr[4] = { 3,2,2,3 };
//    removeElement(arr, 4, 3);
//    return 0;
//}

int searchInsert(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return left;
}

int main()
{
    int arr[] = { 1,2,4,5,6 };
    int ret = searchInsert(arr, 5, 3);
    return 0;
}