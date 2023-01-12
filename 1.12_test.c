#define _CRT_SECURE_NO_WARNINGS 1

/*
实现一个通讯录；

通讯录可以用来存储1000个人的信息，每个人的信息包括：姓名、性别、年龄、电话、住址

提供方法：

添加联系人信息
删除指定联系人信息
查找指定联系人信息
修改指定联系人信息
显示所有联系人信息
清空所有联系人
以名字排序所有联系人
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
		printf("请选择你的操作:>");
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
			printf("退出通讯录_\n");
			break;
		default:
			system("cls");
			printf("选择非法，请重新选择_\n");
			break;
		}
	} while (input);
}

int main()
{
	TestContact();
	return 0;
}