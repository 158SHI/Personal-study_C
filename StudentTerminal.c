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
	printf("���������ѧ��>:");
	scanf("%s", Id);

	//������ѧ����Ϣ�б��в���ѧ����Ϣ
	for (int i = 0; i < s_l->sz; i++)
	{
		if (strcmp((s_l->stuList + i)->ID, Id) == 0)
		{
			//ֱ�ӵ�½
			return s_l->stuList + i;
		}
	}
	
	//�û������ڣ��Զ�ע��
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
	//ѧ����½
	Stu* stu = StuLogin(s_l);

}