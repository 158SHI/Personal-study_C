#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//ֱ��ѡ������

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void Print(int* parr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", parr[i]);
	}
	printf("\n");
}

void SelectSort(int* parr, int n)
{
	//˫ָ��
	int begin = 0;
	int end = n - 1;

	while (begin < end)
	{
		int min = begin;
		int max = begin;
		for (int i = begin; i <= end; i++)
		{
			if (parr[i] < parr[min])
			{
				min = i;
			}
			if (parr[i] > parr[max])
			{
				max = i;
			}
		}
		Swap(&parr[min], &parr[begin]);
		//����max��begin�������
		if (begin == max)
		{
			max = min;
		}
		Swap(&parr[max], &parr[end]);
		begin++;
		end--;
	}
}

void SelectSortTest(void)
{
	int arr[] = { 1,3,5,7,0,2,4,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, sz);
	Print(arr, sz);
}

void CreatHeap(int* parr, int n, int root)
{
	//�����
	int parent = root;
	int child = parent * 2 + 1;

	while (child < n)
	{
		//�ҳ��ϴ���ӽڵ�
		if ((child + 1 < n) && (parr[child + 1] > parr[child]))
		{
			child += 1;
		}

		if (parr[child] > parr[parent])
		{
			Swap(&parr[child], &parr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//������
void HeapSort(int* parr, int n)
{
	//����
	//���򽨴��
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		CreatHeap(parr, n, i);
	}
	
	int end = n - 1;
	while (end > 0)
	{
		Swap(&parr[end], &parr[0]);
		CreatHeap(parr, end, 0);
		end--;
	}
}

void HeapSortTest(void)
{
	int arr[] = { 1,3,5,7,0,2,4,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, sz);
	Print(arr, sz);
}

//ֱ��ð������
void BubbleSort(int* parr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		for (int j = 1; j < n - i; j++)
		{
			if (parr[j] < parr[j - 1])
			{
				Swap(&parr[j], &parr[j - 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

void BubbleSortTest()
{
	int arr[] = { 1,3,5,7,0,2,4,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz);
	Print(arr, sz);
}

//��������_�ڿӷ�
void QuickSort(int* parr, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	//һ������
	int begin = left;
	int end = right;

	int key = parr[begin];
	int pit = begin;

	while (begin < end)
	{
		//���������ߣ������������С��key����
		if (pit == begin)
		{
			while ((parr[end] >= key) && (begin < end))
			{
				end--;
			}
			parr[pit] = parr[end];
			pit = end;
		}
		//��������ұߣ�����������Ҵ���key����
		if (pit == end)
		{
			while ((parr[begin] <= key) && (begin < end))
			{
				begin++;
			}
			parr[pit] = parr[begin];
			pit = begin;
		}
	}
	//��key�������
	parr[pit] = key;

	//�ݹ��������Ҳ���
	QuickSort(parr, left, pit - 1);
	QuickSort(parr, pit + 1, right);
}

void QuickSortTest(void)
{
	int arr[] = { 1,3,5,7,0,2,4,6 };
	//int arr[] = { 6,5,3,7,8,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, sz - 1);
	Print(arr, sz);
}

int main()
{
	//SelectSortTest();
	//HeapSortTest();
	//BubbleSortTest();
	QuickSortTest();
	return 0;
}