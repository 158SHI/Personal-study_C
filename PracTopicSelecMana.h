#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define ID_MAX 12
#define STU_TEA_NAME_MAX 15
#define SEX_MAX 8
#define CLASS_MAX 20
#define MAJOR_MAX 20

#define TOC_NAME_MAX 30

#define DEFAULT_CAP 20
#define EXP_SZ 20

//记录学生信息
typedef struct student
{
	char ID[ID_MAX];//学号
	char name[STU_TEA_NAME_MAX];//姓名
	char sex[SEX_MAX];//性别
	int age;//年龄
	char class[CLASS_MAX];//班级
	char major[MAJOR_MAX];//专业
	
	//记录课题编号以记录该学生的选题
	int topicNum;
}Stu;

//记录课题信息
typedef struct topic
{
	int num;//课题编号
	char name[TOC_NAME_MAX];//课题名称
	int numOfStu;//选报人数
	char adviser[STU_TEA_NAME_MAX];//指导老师
	Stu* stuList;//选报学生列表
}Topic;

//整合课题信息
typedef struct topic_management
{
	int capacity;
	int sz;
	Topic* topicList;//课题列表
}Mana;

//整合学生信息
typedef struct stu_managment
{
	int capacity;
	int sz;
	Stu* stuList;//学生列表
}Stu_list;

//定义用户
enum user
{
	STUDENT = 1,
	TEACHER
};

void menu(void);
void StudentTerminal(Mana* mana, Stu_list* s_l);
void TeacherTermibal(Mana* mana, Stu_list* s_l);
void InitList(Mana* mana, Stu_list* s_l);
void Destory(Mana* mana, Stu_list* s_l);
void PrintTopicOnce(Topic* topic);
void StuListPush(Stu_list* s_l, Stu* stu);
void ManaPush(Mana* mana, Topic* newtopic);
void CheckAllTopic(Mana* mana);
void StuInTopicPush(Stu* stuListInTopic, Stu* stu);
void LoadMessage(Mana* mana, Stu_list* s_l);
void SavaMessage(Mana* mana, Stu_list* s_l);