#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int Sys(void)
{
	int x = 1;
	return *(char*)&x;
}

int main()
{
	int ret = Sys();
	return 0;
}