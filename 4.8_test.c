#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//struct TreeNode {
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;    
//};
//
//int TreeSize(struct TreeNode* root)
//{
//    if (root == NULL) {
//        return 0;
//    }
//
//    return TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//
//void PreOrder(struct TreeNode* root, struct TreeNode** nodeArr, int* pi)
//{
//    if (root == NULL) {
//        return;
//    }
//
//    nodeArr[(*pi)++] = root;
//    PreOrder(root->left, nodeArr, pi);
//    PreOrder(root->right, nodeArr, pi);
//}
//
//void flatten(struct TreeNode* root)
//{
//    int size = TreeSize(root);
//    struct TreeNode** nodeArr =
//        (struct TreeNode**)malloc(sizeof(struct TreeNode*) * size);
//    assert(nodeArr);
//    int i = 0;
//    PreOrder(root, nodeArr, &i);
//
//    for (i = 1; i < size; i++)
//    {
//        (nodeArr[i - 1])->left = NULL;
//        (nodeArr[i - 1])->right = nodeArr[i];
//    }
//    (nodeArr[i - 1])->left = NULL;
//    (nodeArr[i - 1])->right = NULL;
//
//    free(nodeArr);
//    return root;
//}
//
//int main()
//{
//    struct TreeNode* n1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    n1->left = NULL;
//    n1->right = NULL;
//    n1->val = 1;
//
//    struct TreeNode* n2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    n2->left = NULL;
//    n2->right = NULL;
//    n2->val = 2;
//
//    struct TreeNode* n3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    n3->left = NULL;
//    n3->right = NULL;
//    n3->val = 3;
//
//    struct TreeNode* n4 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    n4->left = NULL;
//    n4->right = NULL;
//    n4->val = 4;
//
//    struct TreeNode* n5 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    n5->left = NULL;
//    n5->right = NULL;
//    n5->val = 5;
//
//    struct TreeNode* n6 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    n6->left = NULL;
//    n6->right = NULL;
//    n6->val = 6;
//
//    n1->left = n2;
//    n1->right = n5;
//    n2->left = n3;
//    n2->right = n4;
//    n5->right = n6;
//
//    flatten(n1);
//
//    free(n1);
//    free(n2);
//    free(n3);
//    free(n4);
//    free(n5);
//    free(n6);
//
//    return 0;
//}

//÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int tmp = a[i];
		int end = i - 1;
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//œ£∂˚≈≈–Ú
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < n; i++)
		{
			int end = i - gap;
			int tmp = a[i];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//÷±Ω”—°‘Ò≈≈–Ú
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int left = begin + 1;
		int right = end - 1;
		int mini = left;
		int maxi = right;
		while (left <= end)
		{
			mini = a[left] < a[mini] ? left : mini;
			maxi = a[right] > a[maxi] ? right : maxi;
			left++;
			right--;
		}
		Swap(a + begin, a + mini);
		if (maxi == begin) {
			maxi = mini;
		}
		Swap(a + end, a + maxi);
		begin++;
		end--;
	}
}

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child]) {
			child++;
		}

		if (a[child] > a[parent])
		{
			Swap(a + parent, a + child);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

//∂—≈≈–Ú
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--) {
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(a + 0, a + end);
		AdjustDown(a, end, 0);
		end--;
	}
}

//√∞≈›≈≈–Ú
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 1; i < n - j; i++)
		{
			if (a[i] < a[i - 1]) {
				Swap(a + i, a + i - 1);
			}
		}
	}
}

int GetMidI(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right]) {
			return mid;
		}
		else if (a[right] > a[left]) {
			return left;
		}
		else {
			return right;
		}
	}
	else //a[left] <= a[mid]
	{
		if (a[mid] < a[right]) {
			return mid;
		}
		else if (a[right] < a[left]) {
			return left;
		}
		else {
			return right;
		}
	}
}

//int GetMidI(int* a, int left, int right)
//{
//	int mid = (left + right) / 2;
//	int max = a[left] > a[mid] ? left : mid;
//	max = a[max] > a[right] ? max : right;
//	int min = a[left] < a[right] ? left : right;
//	min = a[min] < a[mid] ? min : mid;
//	return left + right + mid - max - min;
//}

//ªÙ∂˚∞Ê±æ
int PartSort1(int* a, int left, int right)
{
	int midI = GetMidI(a, left, right);
	Swap(a + midI, a + left);

	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi]) {
			right--;
		}
		while (left < right && a[left] <= a[keyi]) {
			left++;
		}
		Swap(a + left, a + right);
	}
	Swap(a + left, a + keyi);
	keyi = left;

	return keyi;
}

//Õ⁄ø”∑®
int PartSort2(int* a, int left, int right)
{
	int midI = GetMidI(a, left, right);
	Swap(a + midI, a + left);

	int piti = left;
	int key = a[left];

	while (left < right)
	{
		while (left < right && a[right] >= key) {
			right--;
		}
		a[piti] = a[right];
		piti = right;

		while (left < right && a[left] <= key) {
			left++;
		}
		a[piti] = a[left];
		piti = left;
	}

	a[piti] = key;
	return piti;
}

//À´÷∏’Î∑®
int PartSort3(int* a, int left, int right)
{
	int midI = GetMidI(a, left, right);
	Swap(a + midI, a + left);

	int keyi = left;
	int cur = keyi;
	int prev = keyi;
	while (cur <= right)
	{
		if (a[cur] < a[keyi]) {
			prev++;
			Swap(a + prev, a + cur);
		}
		cur++;
	}
	Swap(a + keyi, a + prev);
	keyi = prev;

	return keyi;
}

//øÏÀŸ≈≈–Ú
void QuickSort(int* a, int left, int right)
{
	if (left >= right) {
		return;
	}

	int keyi = PartSort3(a, left, right);

	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}

void PrintArr(int* a, int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void TestInsertSort(void)
{
	int arr[] = { 1,3,-2,5,2,4,6,-1,-3,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, sz);
	PrintArr(arr, sz);
}

void TestShellSort(void)
{
	int arr[] = { 1,3,-2,5,2,4,6,-1,-3,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, sz);
	PrintArr(arr, sz);
}

void TestSelectSort(void)
{
	int arr[] = { 1,3,-2,5,2,4,6,-1,-3,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, sz);
	PrintArr(arr, sz);
}

void TestHeapSort(void)
{
	int arr[] = { 1,3,-2,5,2,4,6,-1,-3,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, sz);
	PrintArr(arr, sz);
}

void TestBubbleSort(void)
{
	int arr[] = { 1,3,-2,5,2,4,6,-1,-3,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz);
	PrintArr(arr, sz);
}

void TestQuickSort(void)
{
	int arr[] = { 1,3,-2,5,2,4,6,-1,-3,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, sz - 1);
	PrintArr(arr, sz);
}

int main()
{
	TestInsertSort();
	TestShellSort();
	TestSelectSort();
	TestHeapSort();
	TestBubbleSort();
	TestQuickSort();
	return 0;
}