#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��1
//void GetMemory(char* p)//p��str��һ����ʱ����������
//{
//	p = (char*)malloc(100);
//}//����ʱ��p���٣����ٵĿռ�δ��free�����޷��ҵ�������ڴ�й©
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");//str����NULL������
//	printf(str);
//}
//
////1.�������
////2.�ڴ�й©
//
//int main()
//{
//	Test();
//	return 0;
//}

//�޸�1
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(20);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//�޸�2
//char* GetMemory(char* p)
//{
//	p = (char*)malloc(20);
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//��2
//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}//��Ȼ�������ַ�����ĵ�ַ�����õ�ַ�Ŀռ䱻����
//
////char* GetMemory(void)
////{
////	char* p = "hello,world";//pָ��һ�������ַ����������ַ����洢�ھ�̬�������Բ��ᱻ����
////	return p;
////}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//��3
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);//str =(char*)malloc(100);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");//�������hello,���Ǵ����ڴ�й©
//	printf(str);
//}

//��4
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL)
//	{
//		strcpy(str, "world");//�Ƿ������ڴ棬strָ��Ŀռ��ѱ��ͷ�
//		printf(str);
//	}
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

/*
����
����n�����������У�Ҫ���������н���ȥ�ز�������νȥ�أ���ָ�����������ÿ���ظ����ֵ�������ֻ����������һ�γ��ֵ�λ�ã�ɾ������λ�á�
����������
����������У���һ�а���һ��������n��1 �� n �� 1000������ʾ�ڶ������������ֵĸ������ڶ��а���n����������Χ1~5000�����ÿո�ָ���

���������
���Ϊһ�У����������˳�����ȥ��֮������֣��ÿո�ָ���
*/

//��1
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int arr[1000] = { 0 };
//	int i = 0;
//	for ( i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	for ( i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = i+1; j < n-1; )
//		{
//			if (arr[j] == arr[i])
//			{
//				//ִ��ȥ�ز���
//				int key = j;
//				while (key<n-1)
//				{
//					arr[key] = arr[key + 1];
//					key++;
//				}
//				n--;
//			}
//			if (arr[j] != arr[i])
//			{
//				j++;
//			}
//		}
//	}
//
//	for ( i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//��2
//
//#include<stdbool.h>
//
//_Bool Judge(int* parr,int tmp,int count)
//{
//	_Bool flag = true;
//	for (int i = 0; i < count; i++)
//	{
//		if (parr[i] == tmp)
//		{
//			return false;
//		}
//	}
//	return flag;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int arr[1000] = { 0 };
//	int count = 0;
//	int tmp = 0;
//	int i = 0;
//	for ( i = 0; i < n; i++)
//	{
//		/*
//		����һ�������������в����ڸ�������������飻
//		�����ڸ������򲻷�������
//		*/
//		scanf("%d", &tmp);
//		_Bool ret = Judge(arr,tmp,count);
//		if (ret == true)//��������
//		{
//			arr[count++] = tmp;
//		}
//		else//����������
//		{
//			continue;
//		}
//	}
//
//	for ( i = 0; i < count; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

#include <stdio.h>

int main()
{
    int n = 0;
    int m = 0;
    int max = 0;
    int tmp = 0;
    int a = 0;
    int b = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) 
        {
            scanf("%d", &tmp);
            if (tmp > max) 
            {
                max = tmp;
                a = i;
                b = j;
            }
        }
    }
    printf("%d %d\n", a, b);
    return 0;
}