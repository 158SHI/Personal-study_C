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

//��¼ѧ����Ϣ
typedef struct student
{
	char ID[ID_MAX];//ѧ��
	char name[STU_TEA_NAME_MAX];//����
	char sex[SEX_MAX];//�Ա�
	int age;//����
	char class[CLASS_MAX];//�༶
	char major[MAJOR_MAX];//רҵ
	
	//��¼�������Լ�¼��ѧ����ѡ��
	int topicNum;
}Stu;

//��¼������Ϣ
typedef struct topic
{
	int num;//������
	char name[TOC_NAME_MAX];//��������
	int numOfStu;//ѡ������
	char adviser[STU_TEA_NAME_MAX];//ָ����ʦ
	Stu* stuList;//ѡ��ѧ���б�
}Topic;

//���Ͽ�����Ϣ
typedef struct topic_management
{
	int capacity;
	int sz;
	Topic* topicList;//�����б�
}Mana;

//����ѧ����Ϣ
typedef struct stu_managment
{
	int capacity;
	int sz;
	Stu* stuList;//ѧ���б�
}Stu_list;

//�����û�
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