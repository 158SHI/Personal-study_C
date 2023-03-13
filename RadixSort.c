#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"
#include <time.h>

void PrintArr(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

int GetMaxCount(int num)
{
	int count = 0;
	while (num) 
	{
		num /= 10;
		count++;
	}
	return count;
}

int GetDigit(int num, int aim)
{
	int res = 0;
	while (aim--)
	{
		res = num % 10;
		num /= 10;
	}
	return res;
}

ListNode** CreatListArr(void)
{
	ListNode** ListArr = (ListNode**)malloc(sizeof(ListNode*) * 10);
	assert(ListArr);
	for (int i = 0; i < 10; i++)
	{
		ListArr[i] = LTInit();
	}
	return ListArr;
}

int GetMax(int* arr, int sz)
{
	assert(arr);
	int res = arr[0];
	for (int i = 0; i < sz; i++) {
		res = arr[i] > res ? arr[i] : res;
	}
	return res;
}

//基数排序
void RadixSort(int* arr, int sz)
{
	assert(arr);
	int maxCount = GetMaxCount(GetMax(arr, sz));
	ListNode** ListArr = CreatListArr();
	//第1趟基数排序，并写入桶链表
	for (int i = 0; i < sz; i++)
	{
		int digit = GetDigit(arr[i], 1);
		ListPushBack(ListArr[digit], arr[i]);
	}

	//第2到第p趟基数排序
	for (int i = 2; i <= maxCount; i++)
	{
		for (int arrIndex = 0; arrIndex < 10; arrIndex++)
		{
			//逐个遍历桶链表
			ListNode* cur = ListArr[arrIndex]->next;
			while (cur != ListArr[arrIndex])
			{
				int element = cur->data;
				int digit = GetDigit(element, i);
				if (digit != arrIndex)
				{
					ListNode* nextNode = cur->next;
					ListErase(cur);
					ListPushBack(ListArr[digit], element);
					cur = nextNode;
				}
				else {
					cur = cur->next;
				}
			}
		}
	}

	//将有序数据写回数组
	int count = 0;
	for (int arrIndex = 0; arrIndex < 10; arrIndex++)
	{
		ListNode* cur = ListArr[arrIndex]->next;
		while (cur != ListArr[arrIndex])
		{
			arr[count++] = cur->data;
			cur = cur->next;
		}
	}
}

void GetRandom(int* arr, int sz)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < sz; i++)
	{
		arr[i] = (rand() % 1000);
	}
}

int main()
{
	int arr[500] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	GetRandom(arr, sz);
	RadixSort(arr, sz);
	PrintArr(arr, sz);
	return 0;
}