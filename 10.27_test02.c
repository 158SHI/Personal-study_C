#define _CRT_SECURE_NO_WARNINGS 1

//ǳ��Ħ��ͶƱ�㷨

#include<stdio.h>


//����


//void Bobble_sort(int arr[], int sz)
//{
//	for (int i = 0; i < sz-1; i++)
//	{
//		for (int j = 0; j < sz-1-i; j++)
//		{
//			if (arr[j]>arr[j+1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[50] = { 0 };
//	int sz = 0;
//	scanf("%d", &sz);
//	for (int i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	
//	//1.�����򣬺��ж�
//	Bobble_sort(arr, sz);
//	int left = 0;
//	int right = sz - 1;
//	int mid = (left + right) / 2;
//	int count = 0;
//
//	for (int i = 0; i < sz; i++)
//	{
//		if (arr[i]==arr[mid])
//		{
//			count++;
//		}
//	}
//	if (count>(sz/2))
//	{
//		printf("������Ϊ��%d\n", arr[mid]);
//	}
//	else
//	{
//		printf("NO\n");
//	}
//	
//
//	/*
//	//2.������
//
//	int flag = 0;//���費����
//	for (int i = 0; i < sz-1; i++)
//	{
//		int key = arr[i];
//		int count = 1;
//		for (int j = i+1; j < sz; j++)
//		{
//			if (arr[j] == key)
//			{
//				count++;
//			}
//		}
//		if (count>(sz / 2))
//		{
//			printf("������Ϊ:%d\n", key);
//			flag = 1;
//			break;
//		}
//	}
//
//	if (flag==0)
//	{
//		printf("NO\n");
//	}*/
//
//	return 0;
//}

//Ħ��ͶƱ�㷨������
void Moore(int arr[], int sz)
{
    int major;//��һ�ν��룬��һ��Ԫ�����һ��Ԫ�رȽϣ�cnt++
    int cnt = 0;
    for (int i = 0; i < sz; i++)
    {
        if (cnt == 0)//��cntΪ0�����major���¸�ֵ
        {
            major = arr[i];
        }
        if (major == arr[i])//������ȣ��޷�����
        {
            cnt++;
        }
        else//�������ȣ����е���
        {
            cnt--;
        }
    }
    if (cnt == 0)//�����е���ȫ��һһ������˵����������������
    {
        printf("NO\n");
    }
    else
    {
        printf("����:%d\n",major);
    }
}

int main()
{
    int arr[] = { 1,2,1,3,1,1,2,1,5 };
    //int arr[] = { 1,1,2,2,3,3,4,4,4 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    Moore(arr, sz);
    return 0;
}