#define _CRT_SECURE_NO_WARNINGS 1

//һ���ػ�����
#include<stdio.h>
#include<Windows.h>
#include<string.h>
int main(void)
{
	char input[20] = { 0 };
	system("shutdown -s -t 600");
again:
	system("cls");
	printf("��ĵ��Խ���һ���Ӻ�ػ������롰��������ȡ���ػ�\n");
	printf("������>:");
	scanf("%s", input);
	if (strcmp(input, "������") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}