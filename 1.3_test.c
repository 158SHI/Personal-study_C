#define _CRT_SECURE_NO_WARNINGS 1

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

bool IsSdn(int n)
{
    int tmp = n;
    int key = 0;
    while (tmp)
    {
        key = tmp % 10;
        if (key == 0 || n % key != 0)
        {
            return false;
        }
        tmp /= 10;
    }
    return true;
}

//int* selfDividingNumbers(int left, int right, int* returnSize)
//{
//    int i = 0;
//    int* retNums = (int*)malloc(sizeof(int) * 10000);
//    *returnSize = 0;
//    for (int i = left; i <= right; i++)
//    {
//        if (IsSdn(i))
//        {
//            retNums[(*returnSize)] = i;
//            (*returnSize)++;
//        }
//    }
//    return retNums;
//}

//int main()
//{
//    int retSize = 0;
//    int* retNums = selfDividingNumbers(1, 10000, &retSize);
//    for (int i = 0; i < retSize; i++)
//    {
//        printf("%d,", retNums[i]);
//    }
//    return 0;
//}

//int main()
//{
//    int retSize = 0;
//    int* retNums = selfDividingNumbers(1, 22, &retSize);
//    for (int i = 0; i < retSize; i++)
//    {
//        printf("%d,", retNums[i]);
//    }
//    return 0;
//}


//编写一个程序判断当前系统的存储模式

int CheckSys(void)
{
    int n = 1;
    //00 00 00 01 - 大端
    //01 00 00 00 - 小端
    return *(char*)&n;
}

//int main()
//{
//    if (CheckSys())
//    {
//        printf("小端\n");
//    }
//    else
//    {
//        printf("大端\n");
//    }
//    return 0;
//}


//整型在内存中的存储
//int main()
//{
//    char a = -1;
//    //10000000 00000000 00000000 00000001 - 原码
//    //11111111 11111111 11111111 11111110 - 反码
//    //11111111 11111111 11111111 11111111 - 补码
//    //11111111 - a
//    //11111111 11111111 11111111 11111111 - 整型提升后的补码
//    //-1 输出
//	signed char b = -1;
//    //char 在V.S.中默认是signed char
//	unsigned char c = -1;
//    //10000000 00000000 00000000 00000001 - 原码
//    //11111111 11111111 11111111 11111110 - 反码
//    //11111111 11111111 11111111 11111111 - 补码
//    //11111111 - c
//    //00000000 00000000 00000000 11111111 - 整型提升后的补码/原码
//    //255
//	printf("a=%d,b=%d,c=%d", a, b, c);//-1,-1,255
//	return 0;
//}

//int main()
//{
//	char a[1000];
//	int i;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//    // a[i] : -1 -2 -3 ... -128 127 126 ... 3 2 1 0 -1 -2
//	printf("%d", strlen(a));//255
//
//	return 0;
//}

//int main()
//{
//	int n = 9;
//	float* pFloat = (float*)&n;
//
//	printf("n的值为：%d\n", n);//9
//	printf("*pFloat的值为：%f\n", *pFloat);//0.000000
//    //00000000000000000000000000001001 - 9
//    //0 00000000 00000000000000000001001 - 在pFloat的角度下
//    //S   E             M
//    //S = 0
//    //E :00000000
//    //0.00000000000000000001001 * 2 ^ (-127)
//    //0.000000
//
//	*pFloat = 9.0;
//    //1001.0
//    //(-1)^0 * 1.001 * 2^3
//    //S = 0
//    //M = 1.001
//    //E = 3 + 127 = 130
//    //0 10000010 00100000000000000000000
//    //01000001 00010000 00000000 00000000
//	printf("num的值为：%d\n", n);//1,091,567,616
//	printf("*pFloat的值为：%f\n", *pFloat);//9.000000
//	return 0;
//}

//int main()
//{
//    unsigned char a = 200;
//    //00000000 00000000 00000000 11001000
//    //11001000 - a
//
//    unsigned char b = 100;
//    //00000000 00000000 00000000 01100100
//    //01100100 - b
//
//    //a + b
//    //00000000 00000000 00000000 11001000 - a
//    //00000000 00000000 00000000 01100100 - b
//    //00000000 00000000 00000001 00101100 - a + b
//
//    unsigned char c = 0;
//    //00101100 - c
//    //00000000 00000000 00000000 00101100 - 整型提升后的 c
//    c = a + b;
//    printf("%d %d", a + b, c);//300 44
//    return 0;
//}


//unsigned int a= 0x00 00 12 34;
//34 12 00 00  
//unsigned char b=*(unsigned char *)&a;// 34


/*
5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：

A选手说：B第二，我第三；
B选手说：我第二，E第四；
C选手说：我第一，D第二；
D选手说：C最后，我第三；
E选手说：我第四，A第一；

比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
*/

//int main()
//{
//    //枚举,直到条件符合
//    int A = 0, B = 0, C = 0, D = 0, E = 0;
//    for (int A = 1; A <= 5; A++)
//    {
//        for (int B = 1; B <= 5; B++)
//        {
//            for (int C = 1; C <= 5; C++)
//            {
//                for (int D = 1; D <= 5; D++)
//                {
//                    for (int E = 1; E <= 5; E++)
//                    {
//                        if ((B == 2) + (A == 3) == 1 &&
//                            (B == 2) + (E == 4) == 1 &&
//                            (C == 1) + (D == 2) == 1 &&
//                            (C == 5) + (D == 3) == 1 &&
//                            (E == 4) + (A == 1) == 1 &&
//                            (A * B * C * D * E) == 120) 
//                        //A * B * C * D * E) == 120 是为了保证5人各占一个名次
//                        {
//                            printf("A = %d\nB = %d\nC = %d\nD = %d\nE = %d\n", A, B, C, D, E);
//                            exit(-1);
//                        }
//                    }
//                }
//            }
//        }
//    }
//    return 0;
//}

/*
日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。

以下为4个嫌疑犯的供词:

A说：不是我。 // A == 0
B说：是C。 // C == 1
C说：是D。// D == 1
D说：C在说胡话。// D == 0

已知3个人说了真话，1个人说的是假话。

现在请根据这些信息，写一个程序来确定到底谁是凶手。
*/

//假设凶手是 1,非凶手为 0

//int main()
//{
//    for (int A = 0; A <= 1; A++)
//    {
//        for (int B = 0; B <= 1; B++)
//        {
//            for (int C = 0; C <= 1; C++)
//            {
//                for (int D = 0; D <= 1; D++)
//                {
//                    if ((A == 0) + (C == 1) + (D == 1) + (D == 0) == 3)
//                    {
//                        if (A == 1)
//                        {
//                            printf("凶手是A\n");
//                        }
//                        else if (B == 1)
//                        {
//                            printf("凶手是B\n");
//                        }
//                        else if (C == 1)
//                        {
//                            printf("凶手是C\n");
//                        }
//                        else
//                        {
//                            printf("凶手是D\n");
//                        }
//                        exit(-1);
//                    }
//                }
//            }
//        }
//    }
//    return 0;
//}

//杨辉三角
int main()
{
    int n = 0;
    printf("请输入行数:>");
    scanf("%d", &n);
    int arr[50][50] = { 0 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || i == j)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
            }
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}