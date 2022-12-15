#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//int main()
//{
//	FILE* pf = fopen("test.log", "w");
//	if (pf == NULL)
//	{
//		perror("OpenFile:");
//		exit(-1);
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", i + 1);
//		fprintf(pf, "Date:%s Time:%s File:%s Function:%s Time:%d\n",
//			__DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__);
//	}
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	char s[20] = "hahaha";
//	int sum = 1231;
//	sprintf(s, "%d", sum);
//	printf("%s", s);
//	return 0;
//}

int getLucky(char* s, int k)
{
    int sum = 0;

    char* tmp = (char*)realloc(s, sizeof(char) * 100);
    if (tmp != NULL)
    {
        s = tmp;
    }

    while (k)
    {
        int len = strlen(s);

        sum = 0;

        for (int i = 0; i < len; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                int tmp = (s[i] - 'a' + 1) % 10 + (s[i] - 'a' + 1) / 10;
                sum += tmp;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                sum += s[i] - '0';
            }
        }

        sprintf(s, "%d", sum);

        k--;
    }
    return sum;
}

int main()
{
    char* s = (char*)malloc(sizeof(char) * 1);
    s = "s";
    getLucky(s, 2);
    //char c = 'l' - 'a' + '0';
    //char c = 'z' - 'a';
    //printf("%c", c);
    return 0;
}