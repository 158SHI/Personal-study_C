#define _CRT_SECURE_NO_WARNINGS 1

#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<assert.h>

//int main()
//{
//	char arr1[] = "1580405516@qq.com";
//	char arr2[] = "@.";
//	for (char* ret = strtok(arr1, arr2); ret != NULL; ret = strtok(NULL, arr2))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}

//int main()
//{
//	char arr[] = "I AM A Student.";
//	int i = 0;
//	while (arr[i])
//	{
//		if (isupper(arr[i]))
//		{
//			arr[i] = tolower(arr[i]);
//		}
//		i++;
//	}
//	printf("%s\n", arr);
//	return 0;
//}

//ʵ��memcpy

//void* my_memcpy(void* Des, void* Sour, size_t num)
//{
//	assert(Des && Sour);
//	void* ret = Des;
//	while (num--)
//	{
//		*(char*)Des = *(char*)Sour;
//		++(char*)Des;
//		++(char*)Sour;
//	}
//	return ret;
//}

//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7 };
//	int arr2[] = { 6,6,6 };
//	//memcpy(arr1, arr2, sizeof(arr2));
//	my_memcpy(arr1, arr2, sizeof(arr2));
//	return 0;
//}

//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7 };//��1,2,3,4,5������3,4,5,6,7��λ���ϣ��ص�������
//	//int arr2[10] = { 0 };
//	//my_memcpy(arr2, arr1, sizeof(arr1));
//	my_memcpy(arr1 + 2, arr1, 20);
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%d ", arr1[i]);//��������⣬ĳЩ���ݱ����ǵ�
//	}
//	return 0;
//}

//memmove ���Դ����ڴ��ص��Ŀ���
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7 };
//	memmove(arr + 2, arr, 20);
//
//	return 0;
//}

//void* my_memmove(void* Dest, void* Src, size_t num)
//{
//	assert(Dest != NULL);
//	assert(Src != NULL);
//	void* ret = Dest;
//	if ((char*)Dest< (char*)Src)
//	{
//		//˳�򿽱�
//		while (num--)
//		{
//			*(char*)Dest = *(char*)Src;
//			++(char*)Dest;
//			++(char*)Src;
//		}
//	}
//	else
//	{
//		//���򿽱�
//		while (num--)
//		{
//			char* Src2 = (char*)Src+num;
//			char* Dest2 = (char*)Dest+num;
//			*(char*)Dest2 = *(char*)Src2;
//			--(char*)Dest2;
//			--(char*)Src2;
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7 };
//	my_memmove(arr + 2, arr, 20);
//	return 0;
//}

//��ŵ��

//void swap(char x, char y)
//{
//	printf("%c->%c\n", x, y);
//}
//
//void Hanoi(int n,char a,char b,char c)
//{
//	if (n<=1)
//	{
//		swap(a, c);
//	}
//	else
//	{
//		Hanoi(n - 1, a, c, b);
//		swap(a, c);
//		Hanoi(n - 1, a, b, c);
//	}
//}
//
//int main()
//{
//	int n;
//	printf("���������:>");
//	scanf("%d", &n);
//	Hanoi(n, 'A', 'B', 'C');
//	return 0;
//}

//������̨��

//int frog(int n)
//{
//	if (n==1)
//	{
//		return 1;
//	}
//	else if (n == 2)
//	{
//		return 2;
//	}
//	else
//	{
//		return frog(n - 1) + frog(n - 2);
//	}
//}

int frog(int n)
{
	int a = 0;
	int b = 1;
	int c = 0;
	if (n==1)
	{
		return 1;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
}

int main()
{
	int n;
	printf("������̨����>:");
	scanf("%d", &n);
	int ret = frog(n);
	printf("����%d������\n", ret);
	return 0;
}