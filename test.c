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
	struct Contact con;//����ͨѶ¼con
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>:");
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
		case MODIFY://������
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT://������
			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}


int main()
{
	test();
	return 0;
}