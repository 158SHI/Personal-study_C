#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void getNext(int* next, char* p)
{
	next[0] = -1;
	int k = -1;
	for (int i = 1; i < strlen(p); )
	{
		if (k == -1 || p[i - 1] == p[k]){
			next[i] = k + 1;
			k++;
			i++;
		}
		else{
			k = next[k];
		}
	}
}

char* Kmp(const char* str, const char* sub)
{
	int i = 0;
	int j = 0;
	int strLen = strlen(str);
	int subLen = strlen(sub);
	int* next = (int*)malloc(sizeof(int) * subLen);
	if (next == NULL)
	{
		perror("Kmp::malloc");
		return NULL;
	}
	getNext(next, sub);
	while (i < strLen && j < subLen)
	{
		if (j == -1 || str[i] == sub[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	free(next);
	next = NULL;
	if (j >= subLen)
	{
		return str + i - j;
	}
	else
	{
		return NULL;
	}
}

void test1(void)
{
	//char str[20] = "abcdddeffgmn";
	//char sub[20] = "deffg";
	char str[20] = "a";
	char sub[20] = "a";	
	printf(Kmp(str, sub));
}

int main()
{
	test1();
	return 0;
}