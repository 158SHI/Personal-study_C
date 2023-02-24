#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>
#include<string.h>

int main()
{
	char tmp0[37] = "■■■■■■■■■■■■■■■■■■";
	const char tmp1[] = "正在创建您的映射数据。\r\n请稍后：";

	for (int j = 0; j < 3; j++)
	{
		printf("%s", tmp1);
		for (int i = 0; i < 18; i++)
		{
			printf("%c", tmp0[i]);
			Sleep(35);
		}
		Sleep(35);
		system("cls");
	}
	return 0;
}
