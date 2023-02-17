#define _CRT_SECURE_NO_WARNINGS 1

#include"PracTopicSelecMana.h"

void test(void)
{
	int input = 0;
	Mana mana = { 0 };
	Stu_list s_l = { 0 };
	//初始化列表
	InitList(&mana, &s_l);

	menu();
	printf("请选择>:");
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case STUDENT:
			StudentTerminal(&mana, &s_l);
			break;
		case TEACHER:
			TeacherTermibal(&mana, &s_l);
			break;
		case 0:
			Destory(&mana, &s_l);
			printf("exit\n");
			break;
		default:
			printf("非法选项，请重新选择:>");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}