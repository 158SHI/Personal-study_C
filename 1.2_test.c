#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

int minimumLength(char* s)
{
    int n = strlen(s);
    int left = 0, right = n - 1;
    while (left < right && s[left] == s[right])
    {
        char c = s[left];
        while (left <= right && s[left] == c)
        {
            left++;
        }
        while (left <= right && s[right] == c)
        {
            right--;
        }
    }
    return right - left + 1;
}