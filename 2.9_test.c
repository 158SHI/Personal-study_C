#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//offsetof宏的实现

#define OFFSETOF(type, member) (size_t)(&(((type*)0)->member))

struct stu
{
	int n1;
	char c;
	int n2;
};

//int main()
//{
//	printf("%zd\n", OFFSETOF(struct stu, n1));
//	printf("%zd\n", OFFSETOF(struct stu, c));
//	printf("%zd\n", OFFSETOF(struct stu, n2));
//	return 0;
//}

//写一个宏将一个整数的二进制序列的奇数位和偶数位互换

#define SWAP(n) (n = ((n & 0x55555555) << 1) | ((n & 0xaaaaaaaa) >> 1))

int main()
{
	int n = 10;
	SWAP(n);
	printf("%d\n", n);
	return 0;
}