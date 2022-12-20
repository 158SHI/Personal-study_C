#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

//int main()
//{
//	int input = 0;
//	do
//	{
//		printf("hehe");
//	} while (input);
//	return 0;
//}


void _reserve(int start, int end, char* s)
{
    while (start < end)
    {
        char tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        start++;
        end--;
    }
}

char* reverseWords(char* s)
{
    int start = 0;//��¼���ʵ���ʼλ��
    int end = 0;//��¼���ʵ�ĩβ

    while (s[end] != '\0')
    {
        //���ҵ��ʵ�ĩβ
        while (s[end] != ' ' && s[end] != '\0')
        {
            end++;
        }
        _reserve(start, end - 1, s);
        if (s[end] != '\0')
        {
            end++;
        }
        start = end;
    }
    return s;
}

int main()
{
    char arr[20] = "hello world";
    reverseWords(arr);
    return 0;
}