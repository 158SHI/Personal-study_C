#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//9*9�˷���
//int main()
//{
//    for (int i = 1; i <= 9; i++)
//    {
//        for (int j = 1; j <= i; j++)
//        {
//            printf("%d*%d=%-2d ", i, j, i * j);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//��10�������е����ֵ

//int main()
//{
//	int n;
//	int max = -9999;
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &n);
//		if (n>max)
//		{
//			max = n;
//		}
//	}
//	printf("���ֵΪ%d\n", max);
//	return 0;
//}

//�������
//int main()
//{
//	int flag = 1;
//	float ret = 0;
//	for (int i = 1; i <= 100; i++)
//	{
//		ret += flag * (1.0 / i);
//		flag = -flag;
//	}
//	printf("%f\n", ret);
//	return 0;
//}

//1��100�����г���9�ĸ���
//int main()
//{
//	//��λ��9
//	//ʮλ��9
//	int count = 0;
//	for (int i = 1; i <= 100; i++)
//	{
//		if (i/10 == 9)
//		{
//			count++;
//		}
//		if (i%10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

//���ֲ���
//int main()
//{
//	int arr[] = { -2,1,4,6,7,8,12,14 };
//	int n;
//	printf("������Ҫ���ҵ�����>:");
//	scanf("%d", &n);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	while (left<=right)
//	{
//		int mid = left + (right - left) / 2;//��ֹ���
//		if (arr[mid]>n)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < n)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("�ҵ��ˣ���Ԫ���±�Ϊ%d\n", mid);
//			break;
//		}
//	}
//	if (left>right)
//	{
//		printf("�޷��ҵ���Ԫ��\n");
//	}
//	return 0;
//}

//����ָ��

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int ret = Add(3, 5);
//	printf("%d\n", ret);
//
//	int(*p)(int, int) = &Add;//����ָ��
//
//	int ret2 = (*p)(10, 20);
//	printf("%d\n", ret2);
//	return 0;
//}


//����Ա����
//#include <stdio.h>
//int main()
//{
//    int mark;
//    int count = 0;
//    int sum = 0;
//    int max = 0;
//    int min = 101;
//    while (scanf("%d", &mark) != EOF)
//    {
//        if (mark > max)
//        {
//            max = mark;
//        }
//        if (mark < min)
//        {
//            min = mark;
//        }
//        sum += mark;
//        count++;
//
//        if (count == 7)
//        {
//            printf("%.2f", ((sum - max - min) / 5.0));
//            count = 0;
//            sum = 0;
//            max = 0;
//            min = 101;
//        }
//    }
//    return 0;
//}

//int main()
//{
//	int arr[] = { 2,12,4,2,3,21 };
//	for (int i = 0; i < 5; i++)
//	{
//		int key = arr[i];
//		int j = i - 1;
//	}
//	return 0;
//}


/*
* ɸѡ��������
* 
����
��ɸѡ����n���ڵ�������ɸѡ��������Ϊ����2~n֮������������������ڴ洢����������2֮��������ܱ�2����������0���ٽ�3֮��������ܱ�3����������0 ���Դ����ƣ�ֱ��nΪֹ�������в�Ϊ0 ������Ϊ������
����������
�������룬ÿ������һ����������������100����
���������
���ÿ�����������n��������У���һ�У����n֮�ڣ�����n�����������ÿո�ָ���

�ڶ��У����������2֮����0 �ĸ�����ÿ��������С�
ʾ��1
���룺
20

�����
2 3 5 7 11 13 17 19
11
*/


int main()
{
    int n;

    while (scanf("%d", &n) != EOF)
    {
        int count = 0;//������
        int arr[100] = { 0 };

        for (int i = 2; i < n; i++) //��2��n�����ִ�������arr��
        {
            arr[i - 2] = i;
        }

        for (int i = 0; i < n; i++) //�������ݲ���
        {
            int key;
            if (arr[i] == 0) //ѡ�������ұ�֤������Ϊ0
            {
                continue;
            }
            else
            {
                key = arr[i];
            }

            //������
            for (int j = i + 1; j < n; j++)
            {
                int key2;
                if (arr[j] == 0)//ʹkey2������0:�����ظ����ж� 0%key
                {
                    continue;
                }
                else
                {
                    key2 = arr[j];
                }

                if (key2 % key == 0)//�ܱ�����������ע���������Ϊ0
                { 
                    arr[j] = 0; //���丳ֵΪ0
                    count++;
                }
            }
        }
        //���������
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                printf("%d ", arr[i]);
            }
        }
        printf("\n%d\n", count + 1);
    }
   return 0;
}

//��1��+2��+...+10��
//2!=1!*2
//3!=2!*3

//�Ż��㷨
//int main()
//{
//    int sum = 0;
//    int ret = 1;
//    for (int i = 1; i <= 10; i++)
//    {
//        ret *= i;
//        sum += ret;
//    }
//    printf("%d\n", sum);
//    return 0;
//}