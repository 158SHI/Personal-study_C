#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//char* decodeMessage(char* key, char* message)
//{
//    char* rulesTable = (char*)calloc(26, sizeof(char));
//    char cur = 'a';
//    for (int i = 0; key[i] != '\0'; i++)
//    {
//        char c = key[i];
//        if (c != ' ' && rulesTable[c - 'a'] == 0)
//        {
//            rulesTable[c - 'a'] = cur++;
//        }
//    }
//    for (int i = 0; message[i] != '\0'; i++)
//    {
//        char c = message[i];
//        if (c != ' ')
//        {
//            message[i] = rulesTable[c - 'a'];
//        }
//    }
//    return message;
//}
//
//int main()
//{
//    char key[100] = "the quick brown fox jumps over the lazy dog";
//    char message[100] = "vkbs bs t suepuv";
//    printf("%s\n", decodeMessage(key, message));
//    return 0;
//}

#include<stdbool.h>

int lengthOfLongestSubstring(char* s)
{
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

	while (s[j] != '\0')
	{
		count = 0;
		memset(cnt, 0, sizeof(cnt));
		for (; j < len; j++)
		{
			cnt[s[j]]++;
			bool flag = false;
			for (int k = 0; k < 127; k++)
			{
				if (cnt[k] > 1)
				{
					flag = true;
					goto end;
				}
			}
			count++;
			MaxCount = count > MaxCount ? count : MaxCount;
			if (flag)
			{
			end:
				if(i != j)
				{
					cnt[s[i]]--;
					i++;
				}
			}
		}
	}

	return MaxCount;
}

int main()
{
	printf("%d\n",lengthOfLongestSubstring("pwwkew"));
	return 0;
}