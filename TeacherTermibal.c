#define _CRT_SECURE_NO_WARNINGS 1

#include"PracTopicSelecMana.h"

static enum TeacherOption
{
	EXIT,
	PUBLISH_LESSON,
	DELETE_LESSON,
	CHECK_LESSON,
	CHECK_STU,
	SEARCH_STU
};

void TeacherOption(void)
{
	printf("+------------------------+\n");
	printf("+-------1.发布课题-------+\n");
	printf("+-------2.删除课题-------+\n");
	printf("+-----3.查看全部课题-----+\n");
	printf("+---4.查看选报学生信息---+\n");
	printf("+-----5.查找学生信息-----+\n");
	printf("+---------0.注销---------+\n");
	printf("+------------------------+\n");
}

void TeacherLoginSuccessfully(void)
{
	printf("登陆成功_\n");
}

void PublishLesson(Mana* mana)
{
	system("cls");
	Topic* newTopic = (Topic*)malloc(sizeof(Topic));
	printf("请输入课题名称>:");
	scanf("%s", newTopic->name);
	printf("请输入指导老师>:");
	scanf("%s", newTopic->adviser);
	newTopic->num = mana->sz + 1;
	newTopic->numOfStu = 0;
	ManaPush(mana, newTopic);
	printf("添加成功_\n");
}

void DeleteLesson(Mana* mana)
{
	int delNum = 0;
	printf("请选择要删除的课题的序号>:");
	scanf("%d", &delNum);
	
	if (delNum == mana->sz)
	{
		(mana->sz)--;
	}
	else
	{
		for (int i = delNum; i < mana->sz; i++)
		{
			(mana->topicList[i].num)--;
			mana->topicList[i - 1] = mana->topicList[i];
		}
		(mana->sz)--;
	}
}

void PrintStuOnce(Stu* stu)
{
	printf("%-10s\t%-5d\t%-5s\t%-12s\t%-15s\t%-20s\n",
		stu->name, stu->age, stu->sex, stu->ID, stu->major, stu->class);
}


void CheckLesson(Mana* mana)
{
	CheckAllTopic(mana);
	printf("输入课题序号以查看选报该课题的学生信息_\n输入0以退出该页面_\n");
	printf("请选择>:");
	int input = 0;
	do
	{
		scanf("%d", &input);
		if (input == 0 || (input > 0 && input <= mana->sz))
		{
			if (input == 0)
			{
				break;
			}
			else
			{
				Topic* aimTopic = mana->topicList + (input - 1);
				if (aimTopic->numOfStu == 0) {
					printf("该课题的选报人数为0_\n");
				}
				else {
					system("cls");
					printf("课题信息_:\n");
					printf("%-5s\t%-20s\t%-5s\t%-10s\n",
						"课题编号", "课题名称", "选报人数", "指导教师");
					printf("%-10d\t%-20s\t%-10d\t%-10s\n",
						aimTopic->num, aimTopic->name, aimTopic->numOfStu, aimTopic->adviser);
					printf("选报学生信息:_\n");
					printf("%-10s\t%-5s\t%-5s\t%-12s\t%-20s\t%-20s\n",
						"姓名", "年龄", "性别", "学号", "专业", "班级");
					for (int i = 0; i < aimTopic->numOfStu; i++)
					{
						PrintStuOnce(aimTopic->stuList + i);
					}
				}
			}
		}
		else
		{
			printf("输入非法，请重新输入>:\n");
		}
	} while (input);
}

void CheckStu(Stu_list* s_l)
{
	if (s_l->sz == 0)
	{
		printf("列表为空_\n");
	}
	else
	{
		bool flag = false;
		printf("%-10s\t%-5s\t%-5s\t%-12s\t%-20s\t%-20s\n",
			"姓名", "年龄", "性别", "学号", "专业", "班级");
		for (int i = 0; i < s_l->sz; i++)
		{
			if ((s_l->stuList + i)->topicNum != 0)
			{
				flag = true;
				PrintStuOnce(s_l->stuList + i);
			}
		}
		if (!flag)
		{
			printf("列表为空_\n");
		}
	}

}

void SearchStu(Stu_list* s_l)
{
	/*不想写啦
	* 焯
	*/


}

void TeacherTermibal(Mana* mana, Stu_list* s_l)
{
	TeacherLoginSuccessfully();
/*
	发布课题
	删除课题
	修改课题信息
	查看课题信息 包括课题本身信息和选报学生信息
	查看选报学生信息
	查找某已选报学生的信息
	修改查找出学生的选报信息
*/
	int input = 0;
	do
	{
		TeacherOption();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case PUBLISH_LESSON:
			PublishLesson(mana);
			break;
		case DELETE_LESSON:
			DeleteLesson(mana);
			break;
		case CHECK_LESSON:
			CheckLesson(mana);
			break;
		case CHECK_STU:
			CheckStu(s_l);
			break;
		case SEARCH_STU:
			SearchStu(s_l);
			break;
		case EXIT:
			system("cls");
			printf("退出登录_\n");
			break;
		default:
			printf("非法选项，请重新选择:>");
			break;
		}
	} while (input);
}