#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//int cmp_char(const void* e1, const void* e2)
//{
//	return *(char*)e1 - *(char*)e2;
//}
//
//int main()
//{
//	char s[10] = "haha";
//	char t[10] = "ahah";
//
//	int s_len = strlen(s);
//	qsort(s, s_len, sizeof(char), cmp_char);
//	return 0;
//}

int firstUniqChar(char* s)
{
    int len = strlen(s);
    int i = 0;
    int judge[26] = { 0 };

    for (i = 0; i <= len - 1; i++)
    {
        judge[s[i] - 'a']++;
    }

    for (i = 0; i <= len - 1; i++)
    {
        if (judge[s[i] - 'a'] == 1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char arr[100] = "leetcodeddadhoqhdoqdiqnqdonqou";
    firstUniqChar(arr);
    return 0;
}