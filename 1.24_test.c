#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//void scan(int arr[10], int N)
//{
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	scan(arr, sz);
//	return 0;
//}

#include<stdbool.h>
#include<stdlib.h>

int main()
{
	//bool arr[10] = { 0 };
	//bool* arr2 = (bool*)malloc(sizeof(bool) * 5);
	//for (int i = 0; i < 5; i++)
	//{
	//	arr2[i] = true;
	//}
	bool** visited = (bool**)malloc(sizeof(bool*) * 3);
	for (int i = 0; i < 3; i++)
	{
		visited[i] = (bool*)calloc(3, sizeof(bool));
	}
	return 0;
}