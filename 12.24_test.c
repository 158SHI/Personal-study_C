#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>

int IsTheNumber(const int N)
{
    int jud[10] = { 0 };

    //判断完全平方数
    if ((int)sqrt(N) * (int)sqrt(N) != N)
    {
        return 0;
    }

    //判断数字
    int tmp = N;
    int n = 0;
    while (tmp)
    {
        n = tmp % 10;
        jud[n]++;
        tmp /= 10;
    }

    for (int k = 0; k < 10; k++)
    {
        if (jud[k] >= 2)
        {
            return 1;
        }
    }
    return 0;
}

//int main()
//{
//    int n1, n2, i, cnt;
//
//    scanf("%d %d", &n1, &n2);
//    cnt = 0;
//    for (i = n1; i <= n2; i++)
//    {
//        if (IsTheNumber(i))
//            cnt++;
//    }
//    printf("cnt = %d\n", cnt);
//
//    return 0;
//}

int main()
{
    int ret = IsTheNumber(2500);
    return 0;
}