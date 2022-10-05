#define _CRT_SECURE_NO_WARNINGS 1

/*

�����Ӽ��˳����ӷ�

дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ�üӼ��˳������������

*/

//#include<stdio.h>
//
//int Sum(int a, int b)
//{
//	int carry, sum;
//	while (b)
//	{
//		sum = a ^ b;//��λ���
//		carry = (a & b) << 1;//��λ
//		a = sum;
//		b = carry;//���ظ�����
//	}
//	return a;
//}
//
////������ӣ��Ȱ�λ��ӣ��ٽ�λ
////�ڶ������У���λ�����������㣬��λ��������������������һλ
//int main()
//{
//	int a = 3, b = 5;
//	int ret = Sum(a, b);
//	printf("%d\n", ret);
//	return 0;
//}

//��������
//#include<stdio.h>
//
//void Sert_sorb(int arr[], int sz)
//{
	//for (int i = 1; i < sz; i++)
	//{
	//	int key = arr[i];//���Ҫ�������
	//	int j = i - 1;
	//	while (j>=0 && key<arr[j])//�����Ҫ���������ǰ��������бȽ�
	//	{
	//		arr[j + 1] = arr[j];
	//		j--;
	//	}
	//	arr[j+1] = key;//��������
	//}
//}
//
//int main()
//{
//	int arr[] = { 4,2,5,3,7,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Sert_sorb(arr,sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

/*

����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
���е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣

���磺{1, 2, 3, 4, 5, 6, 7} ������Ϊ��{1, 3, 5, 7, 2, 4, 6}��

*/

//#include<stdio.h>
//
//int Judge(int x)
//{
//	if (x % 2 == 0)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//	//ż������0
//	//��������1
//}
//
//void Resort(int arr[], int sz)//��������
//{
//	for (int i = 1; i < sz; i++)
//	{
//		int ret = Judge(arr[i]);//�ж�i����ż
//		if (ret == 0)//iΪż
//		{
//			continue;
//		}
//		else//iΪ��
//		{
//			int key = arr[i];
//			int j = i - 1;
//			while (j>=0 && Judge(arr[j]) == 0)
//			{
//				arr[j + 1] = arr[j];
//				j--;
//			}
//			arr[j + 1] = key;
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 2,5,4,7,3,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Resort(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

/*

��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1, 2, 3, 2, 2, 2, 5, 4, 2}
��������2�������г�������Σ��������鳤�ȵ�һ�룬������2
��������������0

*/

//1.��������ж�
//������������������ڣ���һ�����м���Ǹ���
//#include<stdio.h>
//
//void Resort(int arr[], int sz)
//{
//	for (int i = 1; i < sz; i++)
//	{
//		int key = arr[i];//���Ҫ�������
//		int j = i - 1;
//		while (j >= 0 && key < arr[j])//�����Ҫ���������ǰ��������бȽ�
//		{
//			arr[j + 1] = arr[j];
//			j--;
//		}
//		arr[j + 1] = key;//��������
//	}
//}
//
//int main()
//{
//	int arr[] = { 2,2,3,2,2,2,5,7 };//2
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Resort(arr,sz);//����
//	int left = 0, right = sz - 1;
//	int mid = left + (right - left) / 2;
//	int key = arr[mid];
//	int count = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		if (arr[i] == key)
//		{
//			count++;//����key���ֵĴ���
//		}
//	}
//	if (count > sz/2)//�ж�key�Ƿ��������
//	{
//		printf("%d\n", key);
//	}
//	else
//	{
//		printf("0\n");
//	}
//	return 0;
//}

//2.Ħ��ͶƱ�㷨��Boyer-Moore Algorithm��
#include<stdio.h>

int Moore(int arr[], int sz)
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
		return 0;
	}
	else//��������ʣ�����(major)�������еĳ��ִ���
	{
		int count = 0;
		for (int i = 0; i < sz; i++)
		{
			if (major == arr[i])
			{
				count++;
			}
		}
		return count > sz / 2 ? major : 0;
	}
}

int main()
{
	int arr[] = { 1,2,1,3,1,1,2,1,5 };
	//int arr[] = { 1,1,2,2,3,3,4,4,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = Moore(arr, sz);
	printf("%d\n", ret);
	return 0;
}