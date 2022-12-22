#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void  Squeeze(char s[], char c)
{
	int i = 0;
	int j = 0;
	while (s[j] != '\0')
	{
		if (s[j] != c)
		{
			s[i++] = s[j++];
		}
		else
		{
			j++;
		}
	}
	s[i] = '\0';
}

//int main()
//{
//	char s[20] = "dafgbdd";
//	Squeeze(s, 'd');
//	puts(s);
//	return 0;
//}

#include <string.h>
#define N 80

void Inverse(char str[])
{
	int i = 0; 
	int j = strlen(str) - 1;
	while (i < j)
	{
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

//int main(void)
//{
//	char a[N];
//	gets(a);
//	Inverse(a);
//	printf("Inversed results:%s\n", a);
//	return 0;
//}

#include <stdio.h>

int CountWords(char str[])
{
	int cur = 0;
	int count = 0;
	while (str[cur] != '\0')
	{
		if (str[cur++] == ' ')
		{
			count++;
		}
	}
	return ++count;
}

//int main(void)
//{
//	char  str[20];
//	gets(str);
//	printf("Numbers of words = %d\n", CountWords(str));
//	return 0;
//}


int lengthOfLongestSubstring(char* s)
{
	//ø’∏ÒŒ Ã‚

	int len = strlen(s);
	if (len == 0)
	{
		return 0;
	}
	int i = 0;
	int j = 0;
	int MaxCount = 0;
	int count = 0;
	int cnt[127];

	while (i < len)
	{
		count = 0;
		memset(cnt, 0, sizeof(cnt));
		for (; j < len; j++)
		{
			cnt[s[j]]++;

			for (int k = 0; k < 127; k++)
			{
				if (cnt[k] > 1)
				{
					goto end;
				}
			}
			count++;
			MaxCount = count > MaxCount ? count : MaxCount;
		}
	end:
		i++;
		j = i;
	}

	return MaxCount;
}

int main()
{
	char arr[20] = " ";
	int ret = lengthOfLongestSubstring(arr);
	printf("%d", ret);
	return 0;
}