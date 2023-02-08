#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

static int cmp_str(const void* e1, const void* e2)
{
    return strcmp(*(char**)e1, *(char**)e2);
}

char** removeSubfolders(char** folder, int folderSize, int* returnSize)
{
    qsort(folder, folderSize, sizeof(char*), cmp_str);
    char** ans = (char**)malloc(sizeof(char*) * folderSize);
    int pos = 0;
    ans[pos++] = folder[0];
    for (int i = 1; i < folderSize; i++)
    {
        int preLength = strlen(ans[pos - 1]);
        if ((preLength >= strlen(folder[i])) ||
            (strncmp(ans[pos - 1], folder[i], preLength) != 0) ||
            (folder[i][preLength] != '/'))
        {
            ans[pos++] = folder[i];
        }
    }
    *returnSize = pos;
    return ans;
}

#define PRINT(param, n) printf("the value of "#n" is "param"\n", n);

int main()
{
    PRINT("%d", 5);
    PRINT("%d", 7);
    PRINT("%f", 7.0);
    PRINT("%f", 2.3);
    return 0;
}