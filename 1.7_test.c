#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

char firstUniqChar(char* s)
{
    //¹þÏ£±í
    int cnt[2][26] = { 0 };

    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        cnt[0][s[i] - 'a']++;
        cnt[1][s[i] - 'a'] = i;
    }

    int key = len;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[0][i] == 1)
        {
            key = cnt[1][i] < key ? cnt[1][i] : key;
        }
    }

    return key == len ? ' ' : s[key];
}

int main()
{
    char arr[20] = "leetcode";
    char ret = firstUniqChar(arr);
    return 0;
}