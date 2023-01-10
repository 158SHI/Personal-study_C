#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

char* my_strncpy(char* DestStr, const char* SourStr, size_t n)
{
	assert(DestStr && SourStr);
	char* ret = DestStr;
	while (n-- && (*DestStr++ = *SourStr++)){
		;
	}
	n = n == -1 ? n + 1 : n - 1;
	while (n--)
	{
		*DestStr++ = '\0';
	}
	return ret;
}

void test1(void)
{
	char Dest[20] = "helloworld";
	char Sour[20] = "world";
	printf("%s\n", my_strncpy(Dest, Sour, 7));
}

char* my_strncat(char* DestStr, const char* SourStr, size_t n)
{
	assert(DestStr && SourStr);
	char* ret = DestStr;
	while (*DestStr++){
		;
	}
	DestStr--;

	while (n-- && (*DestStr++ = *SourStr++)){
		;
	}
	n = n == -1 ? n + 1 : n - 1;
	while (n--)
	{
		*DestStr++ = '\0';
	}
	return ret;
}

void test2(void)
{
	char Dest[20] = "hello ";
	char Sour[20] = "world";
	printf("%s\n", my_strncat(Dest, Sour, 8));
}

int my_strncmp(const char* DestStr, const char* SourStr, size_t n)
{
	assert(DestStr && SourStr);
	while (n-- && *DestStr++ == *SourStr++)
	{
		if (*(DestStr - 1) == '\0' || n == 0)
		{
			return 0;
		}
	}
	return *(DestStr - 1) > *(SourStr - 1) ? 1 : -1;
}

void test3(void)
{
	char Dest[20] = "abcgd";
	char Sour[20] = "abcdg";
	printf("%d\n", my_strncmp(Dest, Sour, 3));
}

//int main()
//{
//	//char Dest[20] = "helloworld";
//	//char Sour[10] = "world";
//	//strncpy(Dest, Sour, 8);
//	//test1();
//	//test2();
//	test3();
//	return 0;
//}

int maxValue(int** grid, int gridSize, int* gridColSize)
{
	int row = gridSize;
	int col = *gridColSize;

	int maxRet = 0;

	int r = 1;
	int c = 1;
	while ((maxRet += (grid[r][c])) && ((r != row - 1) || (c != col - 1)))
	{
		
		if ((grid[r][c + 1] > grid[r + 1][c]) && (c + 1 < col) && (r + 1 < row))
		{
			c++;
		}
		else if ((grid[r][c + 1] < grid[r + 1][c]) && (c + 1 < col) && (r + 1 < row))
		{
			r++;
		}
		else if (r == row - 1)
		{
			c++;
		}
		else if (c == col - 1)
		{
			r++;
		}
		else {
			;
		}
	}
	return maxRet;
}

//int main()
//{
//	int* arr1 = (int*)malloc(sizeof(int) * 3);
//	int* arr2 = (int*)malloc(sizeof(int) * 3);
//	int* arr3 = (int*)malloc(sizeof(int) * 3);
//	int* arr[] = { arr1, arr2, arr3 };
//
//	int a = 3;
//	int* p = &a;
//	int ret = maxValue(arr, 3, p);
//	return 0;
//}

#include<string.h>
#include<assert.h>

void* my_memcpy(void* Dest, const void* Sour, size_t num)
{
	assert(Dest && Sour);
	void* ret = Dest;
	while (num--)
	{
		*(char*)Dest = *(char*)Sour;
		++(char*)Dest;
		++(char*)Sour;
	}
	return ret;
}

void test01(void)
{
	int Dest[] = { 1, 2, 3, 4, 5 };
	int Sour[] = { 6, 7, 8 };
	my_memcpy(Dest, Sour, 12);
}

void* my_memmove(void* Dest, const void* Sour, size_t nums)
{
	assert(Dest && Sour);
	void* ret = Dest;
	if (Sour < Dest)
	{
		while (nums--)
		{
			*((char*)Dest + nums) = *((char*)Sour + nums);
		}
	}
	else
	{
		while (nums--)
		{
			*(char*)Dest = *(char*)Sour;
			++(char*)Dest;
			++(char*)Sour;
		}
	}
	return ret;
}

void test02(void)
{
	int Dest[] = { 1, 2, 3, 4, 5 };
	int Sour[] = { 6, 7, 8 };
	my_memmove(Dest, Sour, 12);
	//my_memmove(Dest + 1, Dest, 12);
}

int main()
{
	//test01();
	test02();
	return 0;
}