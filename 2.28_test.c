#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

double QuickPow(double x, int n)
{
    double res = 1.0;
    double base = x;
    while (n)
    {
        if(n % 2)
        {
            res *= base;
            n--;
        }
        base *= base;
        n /= 2;
    }
    return res;
}

int main()
{   
    //QuickPow(3, 10);
    int* a = NULL;
    int** b = &a;
    printf("%p\n", b);
	return 0;
}