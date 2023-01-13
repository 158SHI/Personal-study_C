#define _CRT_SECURE_NO_WARNINGS 1

//enum RGB
//{
//	RED,
//	YELLOW,
//	BLUE
//};
//
//int main()
//{
//	int red = RED;
//	return 0;
//}

#include<stdio.h>

char* GetMemory(void)
{
	char p[] = "hello world";
	return p;
}
void Test(void)
{
	char* str = NULL;
	str = GetMemory();
	printf(str);
}

//int main()
//{
//	Test();
//	return 0;
//}

#include<stdlib.h>

/*
一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。

编写一个函数找出这两个只出现一次的数字。
*/

int* FindNums(int* nums, int numSize)
{
	int xor = 0;
	for (int i = 0; i < numSize; i++)
	{
		xor ^= nums[i];
	}
	int flag = 0;
	while (!((xor >> flag) & 1))
	{
		flag++;
	}
	int* retNums = (int*)calloc(2, sizeof(int));
	if (retNums == NULL){
		return NULL;
	}
	for (int i = 0; i < numSize; i++)
	{
		if ((nums[i] >> flag) & 1){
			retNums[0] ^= nums[i];
		}
		else{
			retNums[1] ^= nums[i];
		}
	}
	return retNums;
}

//int main()
//{
//	int arr[] = { 3, 2, 5, 7, 1, 2, 1, 7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* retNums = FindNums(arr, sz);
//	printf("%d %d", retNums[0], retNums[1]);
//	free(retNums);
//	retNums = NULL;
//	return 0;
//}

#include<string.h>
#include<assert.h>

char* my_strncpy(char* DestStr, const char* SourStr, size_t n)
{
	assert(DestStr && SourStr);
	char* ret = DestStr;
	while (n-- && (*DestStr++ = *SourStr++)) {
		;
	}
	n = n == -1 ? n + 1 : n;
	while (n--)
	{
		*DestStr++ = '\0';
	}
	return ret;
}

void test1(void)
{
	char Dest[20] = "hello world";
	char Sour[20] = "world";
	my_strncpy(Dest, Sour, 4);

	printf(Dest);
}

char* my_strncat(char* DestStr, const char* SourStr, size_t n)
{
	assert(DestStr && SourStr);
	char* ret = DestStr;
	while (*DestStr++) {
		;
	}
	DestStr--;

	while (n-- && (*DestStr++ = *SourStr++)) {
		;
	}
	n = n == -1 ? n + 1 : n;
	while (n--)
	{
		*DestStr++ = '\0';
	}
	return ret;
}

void test2(void)
{
	char Dest[20] = "hello world";
	char Sour[20] = "world";
	my_strncat(Dest, Sour, 6);
	printf(Dest);
}

void test3(void)
{
	int a = -1;
	int b = 0x11223344;
	
	printf("%x\n", b);
	//printf("%d\n", a);


	printf("%x\n", a);
	printf("%d\n", a);
}

//int main()
//{
//	//test1();
//	//test2();
//	test3();
//	return 0;
//}

//int main()
//{
//	union
//	{
//		short k;
//		char i[2];
//	}*s, a;
//	s = &a;
//	s->i[0] = 0x39;
//	s->i[1] = 0x38;
//	printf("%x\n", a.k);
//	return 0;
//}

int main()
{
	int a = 4;
	int b = 5;
	int c = a < b ? (a, a = a + 1) : (b, b = b + 1);
	return 0;
}