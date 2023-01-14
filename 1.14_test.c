#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct S
{
	char c;
	short arr[0];
}S;

//int main()
//{
//	S* ps = (S*)malloc(sizeof(S) + sizeof(short) * 10);
//	ps->c = 'a';
//	for (int i = 0; i < 10; i++)//柔性数组arr中第一个元素在存放时，会内存对齐
//	{
//		ps->arr[i] = i;
//	}
//	printf("%zd\n", sizeof((*ps)));
//	free(ps);
//	ps = NULL;
//	return 0;
//}

//int main()
//{
//	int a = 0x11223344;
//	printf("%x\n", a);
//	printf("%p\n", a);
//	return 0;
//}

#include<ctype.h>

//模拟实现atoi

int my_atoi(const char* string)
{
	int retNum = 0;
	int i = 0;
	//遇到'\0'时，'\0'ASCII值为0，判断为假，结束
	while (isdigit(string[i]))
	{
		char key = string[i++];
		retNum = retNum * 10 + (key - '0');
	}
	return retNum;
}

void test1(void)
{
	printf("%d\n", my_atoi("1234"));
	printf("%d\n", my_atoi("001234"));
	printf("%d\n", my_atoi("1203400"));
	printf("%d\n", my_atoi("abc1234"));
	printf("%d\n", my_atoi("123d4"));
	return 0;
}

void _reverse(char* left, char* right)
{
    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

char* reverseWords(char* s)
{
    int len = strlen(s);
    _reverse(s, s + len - 1);

    char* start = s;
    char* end = s;

    while (*end != '\0')
    {
        while (*end != ' ' && *end != '\0')
        {
            end++;
        }
        _reverse(start, end - 1);
        if (*end != '\0')
        {
            end++;
        }
        start = end;
    }

    return s;
}


void test2(void)
{
    char arr[20] = "hello world.";
    reverseWords(arr);
}

void test3(void)
{
    char arr1[20] = "hello";
    char arr2[10] = "world";
    strcat(arr1, " ");
    printf(strcat(arr1, arr2));
}

int main()
{
	//test1();
	//char a = '\0';
	//char b = '0';
	//printf("%d\n", isdigit(a));
	//printf("%d\n", isdigit(b));

	//test2();
    //test3();
    char arr[30] = "     hello  world!";
    //char arr2[20] = { 0 };
    //char* buf = NULL;
    //for (buf = strtok(arr, " "); buf != NULL; buf = strtok(NULL, " "))
    //{
    //    strcat(arr2, buf);
    //    strcat(arr2, " ");
    //}
    //printf(arr2);

    char retStr[30] = {0};

    char* buf = NULL;

    for (buf = strtok(arr, " "); buf != NULL; buf = strtok(NULL, " "))
    {
        strcat(retStr, buf);
        strcat(retStr, " ");
    }

    printf(retStr);
	return 0;
}