#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

int main()
{
    int num = 0;
    scanf("%d", &num);
    char retStr[20] = { 0 };
    int numCount = 0;//记录数字
    int retCount = 0;//记录返回
    while (num)
    {
        if (numCount != 0 && numCount % 3 == 0)
        {
            retStr[retCount++] = ',';
        }
        retStr[retCount] = num % 10 + '0';
        num /= 10;
        numCount++;
        retCount++;
    }
    for (int i = retCount - 1; i >= 0; i--)
    {
        putchar(retStr[i]);
    }
    printf("\n");
    return 0;
}

//int main()
//{
//    char arrIn[101] = { 0 };
//    char arrDel[101] = { 0 };
//    char retStr[101] = { 0 };
//    int hash[26] = { 0 };
//    int retCount = 0;
//    gets(arrIn);
//    gets(arrDel);
//    for (int i = 0; i < strlen(arrDel); i++)
//    {
//        hash[arrDel[i] - 'a']++;
//    }
//    for (int i = 0; i < strlen(arrIn); i++)
//    {
//        bool flag = false;
//        if (hash[arrIn[i] - 'a'] == 0)
//        {
//            flag = true;
//        }
//        if (flag)
//        {
//            retStr[retCount++] = arrIn[i];
//        }
//    }
//    puts(retStr);
//    return 0;
//}

#include <stdio.h>
#include <string.h>

int main()
{
    char strIn[100] = { 0 };
    char strDel[100] = { 0 };
    gets(strIn);
    gets(strDel);
    int hash[128] = { 0 };
    for (int i = 0; i < strlen(strDel); i++)
    {
        hash[strDel[i]]++;
    }
    for (int i = 0; i < strlen(strIn); i++)
    {
        if (hash[strIn[i]] == 0)
        {
            putchar(strIn[i]);
        }
    }
    printf("\n");
    return 0;
}