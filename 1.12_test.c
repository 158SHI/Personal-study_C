#define _CRT_SECURE_NO_WARNINGS 1

/*
ʵ��һ��ͨѶ¼��

ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ�������������Ա����䡢�绰��סַ

�ṩ������

�����ϵ����Ϣ
ɾ��ָ����ϵ����Ϣ
����ָ����ϵ����Ϣ
�޸�ָ����ϵ����Ϣ
��ʾ������ϵ����Ϣ
���������ϵ��
����������������ϵ��
*/

#include"Contact.h"

void TestContact(void)
{
	int input = 0;
	Contact Con;
	ContactInit(&Con);
	do
	{
		menu();
		printf("��ѡ����Ĳ���:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			ContactAdd(&Con);
			break;
		case DELET:
			ContactDelet(&Con);
			break;
		case SEARCH:
			ContactSearch(&Con);
			break;
		case MODIFY:
			ContactModify(&Con);
			break;
		case SHOW:
			ContactShow(&Con);
			break;
		case CLEAR:
			ContactClear(&Con);
			break;
		case SORT:
			ContactSort(&Con);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼_\n");
			break;
		default:
			system("cls");
			printf("ѡ��Ƿ���������ѡ��_\n");
			break;
		}
	} while (input);
}

int main()
{
	TestContact();
	return 0;
}