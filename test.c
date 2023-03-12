#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int func(int x, int y)
{
	int sum = 0;
	sum = x + y;
	return sum;
}

int main()
{
	int a = 10;
	int b = 20;
	int c = 0;

	c = func(a, b);

	printf("%d\n", c);

	return 0;
}