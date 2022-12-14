#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

static void menu()
{
	printf("**------- CONTACT --------**\n");
	printf("**---1.Add-------2.Del----**\n");
	printf("**---3.Search---4.Modify--**\n");
	printf("**---5.Show------6.sort---**\n");
	printf("**---------0.exit---------**\n");
	printf("***----------------------***\n");
}

void test(void)
{
	struct Contact con;//创建通讯录con
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			DestoryContact(&con);//free开辟的动态内存空间
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}


int main()
{
	test();
	return 0;
}