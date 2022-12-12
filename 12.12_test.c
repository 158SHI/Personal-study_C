#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void Print(int* parr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", parr[i]);
	}
	printf("\n");
}

void InsertSort(int* parr, int n)
{
	int end = 0;
	for (end = 0; end < n - 1; end++)
	{
		//将第end + 1个数据插入到[0, end]中，使[0, end + 1]有序
		int key = parr[end + 1];
		while (end >= 0)
		{
			if (key < parr[end])
			{
				parr[end + 1] = parr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		parr[end + 1] = key;
	}
}

void InsertTest(void)
{
	int arr[] = { 1,3,5,2,4,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, sz);
	Print(arr, sz);
}

void ShellSort(int* parr, int n)
{
	int gap = n;

	while (gap > 1)
	{
		//调整组距
		//组距最后必须是 1
		gap = gap / 3 + 1;

		//对每组数据同时进行排序
		for (int i = 0; i < n - gap; i++)
		{
			//对一组数据进行排序
			int end = i;
			int key = parr[end + gap];
			while (end >= 0)
			{
				if (key < parr[end])
				{
					parr[end + gap] = parr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			parr[end + gap] = key;
		}
	}
}

void ShellTest(void)
{
	int arr[] = { 1,3,5,2,4,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, sz);
	Print(arr, sz);
}

void Swap(int* p1, int* p2);
void AdjustDwon(int* a, int n, int root);

void HeapSort(int* a, int n)
{
	//排降序建小堆；排升序建大堆
	//若不满足向下调整算法的条件，则倒着从第一个不为叶节点的树进行构建

	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		//此时第一个元素是最小的元素
		//将第一个元素与最后一个元素交换，使最小的元素位于最后面
		Swap(&a[0], &a[end]);
		//重新建堆
		AdjustDwon(a, end, 0);

		//对数组进行隔离，逐个找出当前的最小元素
		end--;
	}
}

void HeapSortTest(int* a, int n)
{
	HeapSort(a, n);
	Print(a, n);
}

//int main()
//{
//	//InsertTest();
//	//ShellTest();
//	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//AdjustDwon(arr, sz, 0);
//	//Print(arr, sz);
//	//HeapSort(arr, sz);
//
//	HeapSortTest(arr, sz);
//	return 0;
//}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//向下调整算法建小堆
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1; // 默认是左子节点
	while (child < n)
	{
		// 找较小的子节点
		if (/*有右孩子*/child + 1 < n && a[child + 1] < a[child])
		{
			child += 1;
		}

		//如果较小的节点的值比父节点小，则与父节点交换
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		//若不满足上面条件，则说明已经是小堆
		else
		{
			break;
		}
	}
}


#include<string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int beautySum(char* s)
{
	int res = 0;
	int len = strlen(s);

	//用双指针 i 和 j 检索所有子字符串
	for (int i = 0; i < len; i++)
	{
		int cnt[26];
		memset(cnt, 0, sizeof(cnt));

		//判断一个 i 到 j 的子串
		int maxFreq = 0;
		for (int j = i; j < len; j++)
		{
			//记录该字母出现的次数
			cnt[s[j] - 'a']++;

			//判断该字母在该子串中是否出现次数最多，以更新该子串中出现的字母最大次数
			maxFreq = MAX(maxFreq, cnt[s[j] - 'a']);

			//找出该子串中出现次数最少的字母
			//注意每次都要重置min
			int minFreq = len;
			for (int k = 0; k < 26; k++)
			{
				if (cnt[k] > 0)
				{
					minFreq = MIN(minFreq, cnt[k]);
				}
			}

			//累加各个子串的漂亮数
			res += maxFreq - minFreq;
		}
	}
	return res;
}

int main()
{
	char arr[20] = "aabcb";
	printf("%d", beautySum(arr));
}