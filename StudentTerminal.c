#define _CRT_SECURE_NO_WARNINGS 1

#include"PracTopicSelecMana.h"

static void StuOption(void)
{


}

static void NewStuLogin(Stu* newStu)
{
	

}

Stu* StuLogin(Stu_list* s_l)
{
	char Id[ID_MAX] = { 0 };
	printf("请输入你的学号>:");
	scanf("%s", Id);

	//在已有学生信息列表中查找学号信息
	for (int i = 0; i < s_l->sz; i++)
	{
		if (strcmp((s_l->stuList + i)->ID, Id) == 0)
		{
			//直接登陆
			return s_l->stuList + i;
		}
	}
	
	//用户不存在，自动注册
	Stu* newStu = (Stu*)malloc(sizeof(Stu));
	if (newStu == NULL) {
		perror("StuLogin::newStu_malloc");
		exit(-1);
	}
	strcpy(newStu->ID, Id);
	NewStuLogin(newStu);
	return newStu;
}

void StudentTerminal(Mana* mana, Stu_list* s_l)
{
	//学生登陆
	Stu* stu = StuLogin(s_l);

}