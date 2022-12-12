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
		//����end + 1�����ݲ��뵽[0, end]�У�ʹ[0, end + 1]����
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
		//�������
		//����������� 1
		gap = gap / 3 + 1;

		//��ÿ������ͬʱ��������
		for (int i = 0; i < n - gap; i++)
		{
			//��һ�����ݽ�������
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
	//�Ž���С�ѣ������򽨴��
	//�����������µ����㷨�����������Ŵӵ�һ����ΪҶ�ڵ�������й���

	//����
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		//��ʱ��һ��Ԫ������С��Ԫ��
		//����һ��Ԫ�������һ��Ԫ�ؽ�����ʹ��С��Ԫ��λ�������
		Swap(&a[0], &a[end]);
		//���½���
		AdjustDwon(a, end, 0);

		//��������и��룬����ҳ���ǰ����СԪ��
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

//���µ����㷨��С��
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1; // Ĭ�������ӽڵ�
	while (child < n)
	{
		// �ҽ�С���ӽڵ�
		if (/*���Һ���*/child + 1 < n && a[child + 1] < a[child])
		{
			child += 1;
		}

		//�����С�Ľڵ��ֵ�ȸ��ڵ�С�����븸�ڵ㽻��
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		//��������������������˵���Ѿ���С��
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

	//��˫ָ�� i �� j �����������ַ���
	for (int i = 0; i < len; i++)
	{
		int cnt[26];
		memset(cnt, 0, sizeof(cnt));

		//�ж�һ�� i �� j ���Ӵ�
		int maxFreq = 0;
		for (int j = i; j < len; j++)
		{
			//��¼����ĸ���ֵĴ���
			cnt[s[j] - 'a']++;

			//�жϸ���ĸ�ڸ��Ӵ����Ƿ���ִ�����࣬�Ը��¸��Ӵ��г��ֵ���ĸ������
			maxFreq = MAX(maxFreq, cnt[s[j] - 'a']);

			//�ҳ����Ӵ��г��ִ������ٵ���ĸ
			//ע��ÿ�ζ�Ҫ����min
			int minFreq = len;
			for (int k = 0; k < 26; k++)
			{
				if (cnt[k] > 0)
				{
					minFreq = MIN(minFreq, cnt[k]);
				}
			}

			//�ۼӸ����Ӵ���Ư����
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