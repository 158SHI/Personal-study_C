#define _CRT_SECURE_NO_WARNINGS 1

/*

Problem Description
���ڱ��ʽn^2+n+41����n�ڣ�x,y����Χ��ȡ����ֵʱ������x,y��(-39<=x<y<=50)���ж��ñ��ʽ��ֵ�Ƿ�Ϊ������

Input
���������ж��飬ÿ��ռһ�У�����������x��y��ɣ���x=0,y=0ʱ����ʾ������������в�������

Output
����ÿ��������Χ�ڵ�ȡֵ��������ʽ��ֵ��Ϊ�����������"OK",�����������Sorry��,ÿ�����ռһ�С�

Sample Input
0 1
0 0

Sample Output
OK

*/
#include<stdio.h>

int Judge(int num)
{
	int i;
	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			//��������
			return 0;
			break;
		}
	}
	if (i >= num)
	{
		//������
		return 1;
	}
}

int main()
{
	int x, y;
	int count = 0;
	while (scanf("%d %d", &x, &y) != EOF)
	{
		if (x == 0 && y == 0)
		{
			continue;
		}
		else
		{
			int counts = y - x + 1;
			count = 0;
			for (int n = x; n <= y; n++)
			{
				int num = n * n + n + 41;
				//�ж�num�Ƿ�Ϊ����
				//����������1��������������0
				int ret = Judge(num);
				if (ret == 1)
				{
					count++;
				}
			}
			if (count == counts)
			{
				printf("OK\n");
			}
			else
			{
				printf("Sorry\n");
			}
		}
	}
	return 0;
}