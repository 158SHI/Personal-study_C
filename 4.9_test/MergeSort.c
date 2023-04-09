#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//归并排序递归实现
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right) {
		return;
	}

	int mid = (left + right) / 2;
	//[left, mid] [mid + 1,right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	//若将 i 初始化为left，则tmp数组中的元素位置与 a 中的元素位置一一对应
	//最后拷贝数组时也要注意这一点
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2]) {
			tmp[i++] = a[begin1++];
		}
		else {
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1) {
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2) {
		tmp[i++] = a[begin2++];
	}

	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}

void TestMergeSort(void)
{
	int arr[] = { 1,3,5,2,4,6,-3,-1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, sz);
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	TestMergeSort();
	return 0;
}