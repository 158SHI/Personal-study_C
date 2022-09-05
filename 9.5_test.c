#define _CRT_SECURE_NO_WARNINGS 1

//一个关机程序
#include<stdio.h>
#include<Windows.h>
#include<string.h>
int main(void)
{
	char input[20] = { 0 };
	system("shutdown -s -t 600");
again:
	system("cls");
	printf("你的电脑将在一分钟后关机，输入“我是猪”以取消关机\n");
	printf("请输入>:");
	scanf("%s", input);
	if (strcmp(input, "我是猪") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}