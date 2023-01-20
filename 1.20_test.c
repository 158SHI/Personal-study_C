#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//int main()
//{
//	srand((unsigned int)time(NULL));
//	for (int i = 1; i <= 100; i++)
//	{
//		printf("%-3d ", rand() % 100 + 1);
//		if (i % 10 == 0)
//		{
//			printf("\n");
//		}
//	}
//	return 0;
//}

//int JudgeSys(void)
//{
//	int n = 1;
//	return *(char*)(&n);
//}

int JudgeSys(void)
{
	union U
	{
		int n;
		char c;
	}u;
	u.n = 1;
	return u.c;
}

//int main()
//{
//	if (JudgeSys())
//	{
//		printf("Ð¡¶Ë\n");
//	}
//	else
//	{
//		printf("´ó¶Ë\n");
//	}
//	return 0;
//}

//int Sum(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int (*p)(int, int) = &Sum;
//	return 0;
//}

